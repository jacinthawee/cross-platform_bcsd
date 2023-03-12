
void EVP_set_pw_prompt(char *prompt)

{
  if (prompt != (char *)0x0) {
    strncpy(&prompt_string,prompt,0x4f);
    DAT_0019881b = 0;
    return;
  }
  prompt_string = 0;
  return;
}

