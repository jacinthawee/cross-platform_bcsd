
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * EVP_get_pw_prompt(void)

{
  undefined1 *puVar1;
  
  puVar1 = prompt_string;
  if (prompt_string[0] == '\0') {
    puVar1 = (char *)0x0;
  }
  return puVar1;
}

