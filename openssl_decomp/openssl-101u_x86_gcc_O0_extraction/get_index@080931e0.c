
int __regparm3 get_index(int param_1,char *param_2,char param_3)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  
  if (param_2 == (char *)0x0) {
    return -1;
  }
  iVar3 = 0;
  if (param_3 == 'I') {
    for (; iVar1 = sk_num(*(_STACK **)(*(int *)(param_1 + 4) + 4)), iVar3 < iVar1; iVar3 = iVar3 + 1
        ) {
      ppcVar2 = (char **)sk_value(*(_STACK **)(*(int *)(param_1 + 4) + 4),iVar3);
      if ((**ppcVar2 == 'I') && (iVar1 = strcmp(param_2,ppcVar2[3]), iVar1 == 0)) {
        return iVar3;
      }
    }
  }
  else {
    for (; iVar1 = sk_num(*(_STACK **)(*(int *)(param_1 + 4) + 4)), iVar3 < iVar1; iVar3 = iVar3 + 1
        ) {
      ppcVar2 = (char **)sk_value(*(_STACK **)(*(int *)(param_1 + 4) + 4),iVar3);
      if ((**ppcVar2 != 'I') && (iVar1 = strcmp(param_2,ppcVar2[3]), iVar1 == 0)) {
        return iVar3;
      }
    }
  }
  return -1;
}

