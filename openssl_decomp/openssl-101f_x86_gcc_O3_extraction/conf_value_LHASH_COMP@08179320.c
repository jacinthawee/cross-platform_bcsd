
int conf_value_LHASH_COMP(char **param_1,char **param_2)

{
  int iVar1;
  
  if ((*param_1 != *param_2) && (iVar1 = strcmp(*param_1,*param_2), iVar1 != 0)) {
    return iVar1;
  }
  if (param_1[1] == (char *)0x0) {
    return -(uint)(param_2[1] != (char *)0x0);
  }
  if (param_2[1] == (char *)0x0) {
    return 1;
  }
  iVar1 = strcmp(param_1[1],param_2[1]);
  return iVar1;
}

