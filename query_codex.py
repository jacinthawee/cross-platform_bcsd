import os
import json
import openai
import pickle
import pandas as pd
import re
import time
import datetime

openai.api_key = "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"

f = open("partial_test_fn_100.txt", "r")
test_fns = f.read()
data = []
with open("decomp_test.json") as inf:
    for line in inf:
        info = json.loads(line.strip())
        if info["func"] in test_fns:
            data.append(info)

# print(data)
# print(len(data))

mrr_list = []
prec_1_list = []
prec_5_list = []
prec_10_list = []
rec_1_list = []
rec_5_list = []
rec_10_list = []
id = 0
query_id = 0
for query in data:
    res = []
    for ot in data:
        if query == ot:
            continue
        res_dict = {}
        res_dict["query"] = query["func"]
        res_dict["other"] = ot["func"]
        if query["func"] == ot["func"]:
            res_dict["ground_truth"] = 1
        else:
            res_dict["ground_truth"] = 0
        # Prepare decompiled A and B functions to be compared
        txtA = open(query["file_name"], "r")
        decA = txtA.read()
        txtB = open(ot["file_name"], "r")
        decB = txtB.read()
        prompt_text = "\n\"\"\"\nHere's what the above decompiled function is doing:\n1."
        # need to add prompt at the end of the function 
        decA_prompt = decA + prompt_text
        decB_prompt = decB + prompt_text

        # Get the code explanations for A and B 
        respA = openai.Completion.create(
            engine="code-davinci-002",
            prompt=decA_prompt,
            temperature=0,
            max_tokens=300,
            top_p=1.0,
            frequency_penalty=0.0,
            presence_penalty=0.0,
            stop=["\"\"\""]
        )

        respB = openai.Completion.create(
            engine="code-davinci-002",
            prompt=decB_prompt,
            temperature=0,
            max_tokens=300,
            top_p=1.0,
            frequency_penalty=0.0,
            presence_penalty=0.0,
            stop=["\"\"\""]
        )

        # Query if A and B are the same function
        expA = "Function A: \n" + respA['choices'][0].text
        expB = "Function B: \n" + respB['choices'][0].text
        prompt_text = "\n\"\"\"\nWhat is the percentage similarity between Function A and Function B? Output a number only\n"
        query_cdx = expA + expB + prompt_text
        response = openai.Completion.create(
            engine="text-davinci-003",
            prompt=query_cdx,
            temperature=0,
            max_tokens=10,
            top_p=1.0,
            frequency_penalty=0.0,
            presence_penalty=0.0,
            stop=["\"\"\""]
        )

        pc_similarity = re.findall('(\d+|\d+[.,]\d{1,2})(?=\s*%)', response["choices"][0].text)[0]
        res_dict["pc_similarity"] = pc_similarity
        if int(pc_similarity) > 50:
            res_dict["is_similar"] = 1
        else:
            res_dict["is_similar"] = 0
        res_dict["q_arch"] = query["arch"]
        res_dict["o_arch"] = ot["arch"]
        res_dict["q_opt"] = query["op"]
        res_dict["o_opt"] = ot["op"]
        res_dict["q_sw"] = query["sw"]
        res_dict["o_sw"] = ot["sw"]
        res.append(res_dict)

        id += 1
        if id % 20 == 0:
            print("Query ", id, " @ ", datetime.datetime.now())
            time.sleep(120)

        if res_dict["is_similar"] != res_dict["ground_truth"]:
            file = open("data/20032023_queries/unsuccessful/test_"+id+".txt", "w")
            file.write(decA_prompt + respA["choices"][0].text + "\n")
            file.write(decB_prompt + respB["choices"][0].text + "\n")
            file.write(response["choices"][0].text)
            file.close()
    df = pd.DataFrame(res)
    df = df.sort_values(by="pc_similarity", axis=0, ascending=False)
    df.reset_index(drop=True, inplace=True)
    df.to_csv('data/20032023_queries/query'+str(query_id)+".csv")
    same_fxn = df.loc[df["ground_truth"] == 1]
    rank = same_fxn.iloc[0].name + 1
    rr = 1/rank
    mrr_list.append(rr)
    top1_relevant = (df.head(1)["ground_truth"]==1).sum()
    top5_relevant = (df.head(5)["ground_truth"]==1).sum()
    top10_relevant = (df.head(10)["ground_truth"]==1).sum()
    tot_relevant = (df["ground_truth"]==1).sum()

    prec1 = top1_relevant/1
    prec5 = top5_relevant/5
    prec10 = top10_relevant/10
    rec1 = top1_relevant/tot_relevant
    rec5 = top5_relevant/tot_relevant
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

# # Prepare decompiled A and B functions to be compared
# txtA = open("fxna.c", "r")
# decA = txtA.read()
# txtB = open("fxnb.c", "r")
# decB = txtB.read()
# prompt_text = "\n\"\"\"\nHere's what the above decompiled function is doing:\n1."
# # need to add prompt at the end of the function 
# decA_prompt = decA + prompt_text
# decB_prompt = decB + prompt_text

# openai.api_key = "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"
# # openai.api_key = "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"
# # print(openai.Model.list())

# # Get the code explanations for A and B 
# respA = openai.Completion.create(
#     engine="code-davinci-002",
#     prompt=decA_prompt,
#     temperature=0,
#     max_tokens=200,
#     top_p=1.0,
#     frequency_penalty=0.0,
#     presence_penalty=0.0,
#     stop=["\"\"\""]
# )

# respB = openai.Completion.create(
#     engine="code-davinci-002",
#     prompt=decB_prompt,
#     temperature=0,
#     max_tokens=200,
#     top_p=1.0,
#     frequency_penalty=0.0,
#     presence_penalty=0.0,
#     stop=["\"\"\""]
# )

# # Query if A and B are the same function
# expA = "Function A: \n" + respA['choices'][0].text
# expB = "Function B: \n" + respB['choices'][0].text
# prompt_text = "\n\"\"\"\nWhat is the percentage similarity between Function A and Function B? Output a number only\n"
# query = expA + expB + prompt_text
# response = openai.Completion.create(
#     engine="text-davinci-003",
#     prompt=query,
#     temperature=0,
#     max_tokens=20,
#     top_p=1.0,
#     frequency_penalty=0.0,
#     presence_penalty=0.0,
#     stop=["\"\"\""]
# )

# file = open("test.txt", "w")
# # file.write(decA_prompt + respA["choices"][0].text + "\n")
# # file.write(decB_prompt + respB["choices"][0].text + "\n")
# pc_similarity = re.findall('(\d+|\d+[.,]\d{1,2})(?=\s*%)', response["choices"][0].text)[0]
# file.write(pc_similarity)
# # file.write(response["choices"][0].text)
# file.close()
# # print(response)
