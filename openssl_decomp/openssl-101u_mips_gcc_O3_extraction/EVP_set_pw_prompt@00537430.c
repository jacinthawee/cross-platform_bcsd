
void EVP_set_pw_prompt(char *prompt)

{
  undefined4 in_a3;
  
  if (prompt != (char *)0x0) {
    (*(code *)PTR_strncpy_006a99e0)(prompt_string,prompt,0x4f,in_a3,&_gp);
    prompt_string[79] = 0;
    return;
  }
  prompt_string[0] = 0;
  return;
}

