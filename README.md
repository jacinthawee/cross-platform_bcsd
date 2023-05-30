# cross-platform_bcsd
This repo contains data and code for 3 approaches used to perform binary code similarity detection. Refer to README.pdf for detailed descriptions and instructions.

The approaches are:
1. Gemini
  - Implemented from https://github.com/xiaojunxu/dnn-binary-code-similarity 
  - Graph-based method using block-level attributes from CFGs of binary functions to train 2 graph embedding networks in a Siamese NN to determine if the 2 binary functions are similar or not

2. gpt-3.5-turbo/SBERT
  - First obtain code explanations of psuedo C binary functions using gpt-3.5-turbo
  - Then using the code explanations, get embeddings using SBERT. Use embeddings to calculate cosine similarity between the 2 binary functions

3. CodeBERTScore
  - Directly input pair of pseudo C binary functions into CodeBERTScore and obtain metrics, of interest to us is F1 score as measure of similarity

On a reduced test dataset, the performance of all 3 approaches are as follows:
<img width="472" alt="image" src="https://github.com/jacinthawee/cross-platform_bcsd/assets/78328036/3a9e4392-9129-4a08-ba0e-14696095712c">
