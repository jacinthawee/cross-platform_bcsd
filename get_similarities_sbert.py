import csv
import pandas as pd
from sentence_transformers import SentenceTransformer, util
from sklearn import metrics

model = SentenceTransformer("all-mpnet-base-v2")

original = []
with open('data/summaries.csv') as f:
    reader = csv.DictReader(f, delimiter=',')
    for row in reader:
        original.append(row)
        
actual = []
with open('data/ssl_data.csv') as f:
    reader = csv.DictReader(f, delimiter=',')
    for row in reader:
        actual.append(row)

actual_files = [i['file_name'] for i in actual]
data = []
for entry in original:
    if entry['file_name'] in actual_files:
        data.append(entry)
print(len(data), 'files')

# embeddings = []
for entry in data:
    sentence = entry['response']
    embedding = model.encode(sentence)
    entry['embedding'] = embedding
    # embeddings.append(embedding)

mrr_list = [] 
prec_1_list = []
prec_5_list = []
prec_10_list = []
rec_1_list = []
rec_5_list = []
rec_10_list = []

tot_data = len(data)
for idx in range(tot_data):
    all_data = []
    for cur_idx in range(tot_data):
        if idx == cur_idx:
            continue
        data_dict = {}
        data_dict['sw1'] = data[idx]['sw']
        data_dict['op1'] = data[idx]['op']
        data_dict['arch1'] = data[idx]['arch']
        data_dict['func1'] = data[idx]['func']
        data_dict['file_name1'] = data[idx]['file_name']
        data_dict['response1'] = data[idx]['response']
        
        data_dict['sw2'] = data[cur_idx]['sw']
        data_dict['op2'] = data[cur_idx]['op']
        data_dict['arch2'] = data[cur_idx]['arch']
        data_dict['func2'] = data[cur_idx]['func']
        data_dict['file_name2'] = data[cur_idx]['file_name']
        data_dict['response2'] = data[cur_idx]['response']
        
        if data_dict['func1'] == data_dict['func2']:
            data_dict['ground_truth'] = 1
        else:
            data_dict['ground_truth'] = 0
        
        # embed1 = embeddings[idx]
        # embed2 = embeddings[cur_idx]
        embed1 = data[idx]['embedding']
        embed2 = data[cur_idx]['embedding']
        cos = util.cos_sim(embed1, embed2)
        data_dict['cos_sim'] = cos[0][0].item()
        all_data.append(data_dict)

    # order all entries acc to highest cos sim first 
    df = pd.DataFrame(all_data)
    df = df.sort_values(by='cos_sim', axis=0, ascending=False)
    df.reset_index(drop=True, inplace=True)
    df.to_csv('data/15052023_queries/query'+str(idx)+'.csv')
    # then calculate rank acc to relevancy grade = 1 of highest cos sim
    same_fxn = df.loc[df['ground_truth']==1]
    rank = same_fxn.iloc[0].name + 1 # index starts with 0, rank starts with 1
    rr = 1/rank # calc reciprocal rank
    mrr_list.append(rr)
    print("Query ", idx)
    print(mrr_list)
    # find for each k the top k precision and recall
    # precision@k = # relevant items in top k / k
    # recall@k = # relevant items in top k / # of all possible relevant items
    top5_relevant = (df.head(5)["ground_truth"]==1).sum()
    top10_relevant = (df.head(10)["ground_truth"]==1).sum()
    top1_relevant = (df.head(1)["ground_truth"]==1).sum()
    tot_relevant = (df["ground_truth"]==1).sum()

    prec1 = top1_relevant/1
    rec1 = top1_relevant/tot_relevant
    prec5 = top5_relevant/5
    rec5 = top5_relevant/tot_relevant
    prec10 = top10_relevant/10
    rec10 = top10_relevant/tot_relevant

    prec_1_list.append(prec1)
    prec_5_list.append(prec5)
    prec_10_list.append(prec10)
    rec_1_list.append(rec1)
    rec_5_list.append(rec5)
    rec_10_list.append(rec10)

mrr = sum(mrr_list)/len(mrr_list)
print("Test MRR is: ", mrr)
precision_top1 = sum(prec_1_list)/len(prec_1_list)
print("precision@1: ", precision_top1)
precision_top5 = sum(prec_5_list)/len(prec_5_list)
print("precision@5: ", precision_top5)
precision_top10 = sum(prec_10_list)/len(prec_10_list)
print("precision@10: ", precision_top10)
recall_top1 = sum(rec_1_list)/len(rec_1_list)
print("recall@1: ", recall_top1)
recall_top5 = sum(rec_5_list)/len(rec_5_list)
print("recall@5: ", recall_top5)
recall_top10 = sum(rec_10_list)/len(rec_10_list)
print("recall@10: ", recall_top10)

# get auc for comparison against gemini
gemini_data = []
with open('data/for_llm.csv') as f:
    reader = csv.DictReader(f, delimiter=',')
    for row in reader:
        gemini_data.append(row)

response_dict = {}
for i in data:
    response_dict[i['file_name']] = i['response']
for entry in gemini_data:
    entry['g0_response'] = response_dict[entry['g0_filename']]
    entry['g1_response'] = response_dict[entry['g1_filename']]

headers = list(gemini_data[0].keys())
headers.append('cos_sim')
with open('data/auc_gemini_sbert.csv', 'w') as f:
    writer = csv.DictWriter(f, fieldnames=headers)
    writer.writeheader()
    f.close()
    
for entry in gemini_data:
    sentence1 = entry['g0_response']
    embedding1 = model.encode(sentence1)
    
    sentence2 = entry['g1_response']
    embedding2 = model.encode(sentence2)
    
    cos = util.cos_sim(embedding1, embedding2)
    entry['cos_sim'] = cos[0][0].item()
    
    with open('data/auc_gemini_sbert.csv', 'a') as f:
        writer = csv.DictWriter(f, fieldnames=list(entry.keys()))
        writer.writerow(entry)
        f.close()
    
df = pd.read_csv('data/auc_gemini_sbert.csv')
y = df['ground_truth'].tolist()
pred = df['cos_sim'].tolist()
fpr, tpr, thresholds = metrics.roc_curve(y, pred)
print('AUC (Gemini data):', metrics.auc(fpr, tpr))