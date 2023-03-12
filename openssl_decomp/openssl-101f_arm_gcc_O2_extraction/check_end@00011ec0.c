
int check_end(char *param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  
  sVar2 = strlen(param_2);
  sVar3 = strlen(param_1);
  if ((int)sVar2 <= (int)sVar3) {
    iVar1 = strcmp(param_1 + (sVar3 - sVar2),param_2);
    return iVar1;
  }
  return 1;
}

