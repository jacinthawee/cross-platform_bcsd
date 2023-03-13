
char ** SRP_VBASE_get_by_user(_STACK **param_1,char *param_2)

{
  char **ppcVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (_STACK **)0x0) {
    iVar3 = 0;
    while( true ) {
      iVar2 = sk_num(*param_1);
      if (iVar2 <= iVar3) break;
      ppcVar1 = (char **)sk_value(*param_1,iVar3);
      iVar2 = strcmp(*ppcVar1,param_2);
      if (iVar2 == 0) {
        return ppcVar1;
      }
      iVar3 = iVar3 + 1;
    }
  }
  return (char **)0x0;
}

