import os
import json
import openai
import pickle
import pandas as pd
import re
import time
import datetime
import tiktoken
import csv
from tenacity import retry, stop_after_attempt, wait_random_exponential

openai.api_key = # put your own api key

@retry(wait=wait_random_exponential(min=20, max=60), stop=stop_after_attempt(6))
def completion_with_backoff(**kwargs):
    return openai.ChatCompletion.create(**kwargs)

def count_tokens(filename, model):
    encoding = tiktoken.encoding_for_model(model)
    with open(filename, 'r') as f:
        code = f.read()
    input_ids = encoding.encode(code)
    num_tokens = len(input_ids)
    return num_tokens

def break_up_file_to_chunks(filename, model, chunk_size=2000, overlap=100):
    encoding = tiktoken.encoding_for_model(model)
    with open(filename, 'r') as f:
        code = f.read()
    tokens = encoding.encode(code)
    num_tokens = len(tokens)
                             
    chunks = []
    for i in range(0, num_tokens, chunk_size - overlap):
        chunk = tokens[i:i+chunk_size]
        chunks.append(chunk)
    
    return chunks

f = open("data/partial_test_fn_100.txt", "r")
test_fns = f.read()
data = []
with open("data/decomp_test.json") as inf:
    for line in inf:
        info = json.loads(line.strip())
        if info["func"] in test_fns:
            data.append(info)
print("Loading data done")
# print(data)
# print(len(data))

summarised_files = []
with open('data/summaries.csv') as f:
    reader = csv.DictReader(f, delimiter=',')
    for row in reader:
        summarised_files.append(row['file_name'])
# headers = ['sw', 'op', 'arch', 'func', 'file_name', 'response']
# with open('data/summaries.csv', 'w') as f:
#     writer = csv.DictWriter(f, fieldnames=headers)
#     writer.writeheader()
#     f.close()
    
# id_q = 0
id_q = len(summarised_files)
model = "gpt-3.5-turbo"
for q in data:
    if q['file_name'] in summarised_files:
        continue
    print(f"Summarizing Function {id_q+1}/{len(data)}")
    filename = q['file_name']
    prompt_response = []
    encoding = tiktoken.encoding_for_model(model)
    # first break up the decompiled function into chunks so won't exceed token limit
    chunks = break_up_file_to_chunks(filename, model)
    # for each chunk, get a summary of what the function chunk is doing
    for i, chunk in enumerate(chunks):
        prompt_request = encoding.decode(chunks[i]) + "\n\"\"\"\nHere's what the above decompiled function is doing:\n"
        msg = [{'role': 'user', 'content': prompt_request}]
        response = completion_with_backoff(
            model=model,
            messages=msg,
            temperature=0.5,
            max_tokens=200
        )
        # response = openai.ChatCompletion.create(
        #     model=model,
        #     messages=msg,
        #     temperature=0.5,
        #     max_tokens=200
        # )
        prompt_response.append(response["choices"][0]["message"]['content'].strip())
    # consolidate all chunk summaries to get one summary for that function
    prompt_request = "Consolidate these function summaries: \n" + str(prompt_response)
    msg = [{'role': 'user', 'content': prompt_request}]
    response = completion_with_backoff(
        model=model,
        messages=msg,
        temperature=0.5,
        max_tokens=500
    )
    # response = openai.ChatCompletion.create(
    #         model=model,
    #         messages=msg,
    #         temperature=0.5,
    #         max_tokens=500
    #     )
    q['response'] = response["choices"][0]["message"]['content'].strip()
    with open('data/summaries.csv', 'a') as f:
        writer = csv.DictWriter(f, fieldnames=list(q.keys()))
        writer.writerow(q)
        f.close()
    if id_q % 10 == 0:
        time.sleep(60)
    id_q += 1