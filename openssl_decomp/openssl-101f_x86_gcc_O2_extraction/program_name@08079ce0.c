
void program_name(char *param_1,char *param_2,size_t param_3)

{
  char *pcVar1;
  
  pcVar1 = strrchr(param_1,0x2f);
  if (pcVar1 != (char *)0x0) {
    param_1 = pcVar1 + 1;
  }
  BUF_strlcpy(param_2,param_1,param_3);
  return;
}

