
char * pem_check_suffix(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  char *__s1;
  
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_2);
  pcVar3 = (char *)0x0;
  if ((int)(sVar2 + 1) < (int)sVar1) {
    __s1 = param_1 + (sVar1 - sVar2);
    pcVar3 = (char *)strcmp(__s1,param_2);
    if (pcVar3 != (char *)0x0) {
      return (char *)0x0;
    }
    if (__s1[-1] == ' ') {
      return __s1 + (-1 - (int)param_1);
    }
  }
  return pcVar3;
}

