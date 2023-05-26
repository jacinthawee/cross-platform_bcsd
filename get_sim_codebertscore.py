import code_bert_score
from code_bert_score import BERTScorer
import pickle
from nltk.translate import bleu_score
from nltk.translate.bleu_score import sentence_bleu
import re
import csv
import pandas as pd
from sklearn import metrics
import os, os.path

def tokenize_for_bleu_eval(code):
    code = re.sub(r'([^A-Za-z0-9_])', r' \1 ', code)
    tokens = [t for t in code.split(' ') if t]
    return tokens

def print_results(predictions, refs, pred_results):
    for i in range(len(refs)):
        print(f'Example {i}:')
        print(f'Reference: {refs[i]}')
        print(f'Prediction: {predictions[i]}')
        print(f'Prediction precision: {pred_results[0][i]:.3f}, recall: {pred_results[1][i]:.3f}, f1: {pred_results[2][i]:.3f}, f3: {pred_results[3][i]:.3f}')
        ref_tokens = tokenize_for_bleu_eval(refs[i])
        pred_tokens = tokenize_for_bleu_eval(predictions[i])
        print(f'BLEU score: {sentence_bleu([ref_tokens], pred_tokens):.3f}')
        print()

if __name__ == '__main__':
    
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
    
    scorer = BERTScorer(lang='c')
    
    mrr_list = [] 
    prec_1_list = []
    prec_5_list = []
    prec_10_list = []
    rec_1_list = []
    rec_5_list = []
    rec_10_list = []

    tot_data = len(data)
    
    for i in range(1864):
        filename = 'data/15052023_queries_cbs/query'+str(i)+'.csv'
        df = pd.read_csv(filename)
        # then calculate rank acc to relevancy grade = 1 of highest cos sim
        same_fxn = df.loc[df['ground_truth']==1]
        rank = same_fxn.iloc[0].name + 1 # index starts with 0, rank starts with 1
        rr = 1/rank # calc reciprocal rank
        mrr_list.append(rr)
        
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
    print('Resuming from Query', len(mrr_list))
    # print(mrr_list)
    
    for idx in range(len(mrr_list), tot_data):
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

            with open(data_dict['file_name1'], 'r') as f:
                code = f.read()
            predictions = [code]
            
            with open(data_dict['file_name2'], 'r') as f:
                code = f.read()
            refs = [code]
            
            P, R, F1 = scorer.score(predictions, refs)
            f1 = F1[0].item()
            # pred_results = code_bert_score.score(cands=predictions, refs=refs, no_punc=True, lang='c')
            # f1 = pred_results[2][0]
            
            data_dict['f1'] = f1
            all_data.append(data_dict)

        # order all entries acc to highest cos sim first 
        df = pd.DataFrame(all_data)
        df = df.sort_values(by='f1', axis=0, ascending=False)
        df.reset_index(drop=True, inplace=True)
        df.to_csv('data/15052023_queries_cbs/query'+str(idx)+'.csv')
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

    headers = list(gemini_data[0].keys())
    headers.append('f1')
    with open('data/auc_gemini_cbs.csv', 'w') as f:
        writer = csv.DictWriter(f, fieldnames=headers)
        writer.writeheader()
        f.close()

    for entry in gemini_data:
        
        file1 = entry['g0_filename']
        file2 = entry['g1_filename']
        
        with open(file1, 'r') as f:
            code = f.read()
        predictions = [code]
        with open(file2, 'r') as f:
            code = f.read()
        refs = [code]
        
        P, R, F1 = scorer.score(predictions, refs)
        f1 = F1[0].item()
        # pred_results = code_bert_score.score(cands=predictions, refs=refs, no_punc=True, lang='c')
        # f1 = pred_results[2][0]

        entry['f1'] = f1

        with open('data/auc_gemini_cbs.csv', 'a') as f:
            writer = csv.DictWriter(f, fieldnames=list(entry.keys()))
            writer.writerow(entry)
            f.close()

    df = pd.read_csv('data/auc_gemini_cbs.csv')
    y = df['ground_truth'].tolist()
    pred = df['f1'].tolist()
    fpr, tpr, thresholds = metrics.roc_curve(y, pred)
    print('AUC (Gemini data):', metrics.auc(fpr, tpr))
