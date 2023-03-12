
char * conf_value_LHASH_COMP(char **param_1,char **param_2)

{
  char *pcVar1;
  
  if ((*param_1 == *param_2) || (pcVar1 = (char *)strcmp(*param_1,*param_2), pcVar1 == (char *)0x0))
  {
    if (param_1[1] == (char *)0x0) {
      pcVar1 = param_2[1];
      if (pcVar1 != (char *)0x0) {
        pcVar1 = (char *)0xffffffff;
      }
      return pcVar1;
    }
    if (param_2[1] != (char *)0x0) {
      pcVar1 = (char *)strcmp(param_1[1],param_2[1]);
      return pcVar1;
    }
    pcVar1 = (char *)0x1;
  }
  return pcVar1;
}

