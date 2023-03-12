
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * EVP_get_pw_prompt(void)

{
  if (prompt_string[0] != '\0') {
    return prompt_string;
  }
  return (char *)0x0;
}

