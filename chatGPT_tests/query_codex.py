import os
import openai

# Prepare decompiled A and B functions to be compared
txtA = open("openssl-101f_mips_gcc_o0_x509_add1_trust_obj.txt", "r")
decA = txtA.read()
txtB = open("openssl-101f_arm_gcc_o0_x509_add1_trust_obj.txt", "r")
decB = txtB.read()
prompt_text = "\n\"\"\"\nHere's what the above decompiled function is doing:\n1."
# need to add prompt at the end of the function 
decA_prompt = decA + prompt_text
decB_prompt = decB + prompt_text

openai.api_key = "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"
# print(openai.Model.list())

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
prompt_text = "\n\"\"\"\nWhat is the percentage similarity between Function A and Function B? Explain why.\n"
query = expA + expB + prompt_text
response = openai.Completion.create(
    engine="text-davinci-003",
    prompt=query,
    temperature=0,
    max_tokens=300,
    top_p=1.0,
    frequency_penalty=0.0,
    presence_penalty=0.0,
    stop=["\"\"\""]
)
print(response)
