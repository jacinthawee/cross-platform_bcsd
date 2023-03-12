
int get_index(int param_1,int param_2,int param_3)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return -1;
  }
  iVar3 = 0;
  if (param_3 == 0x49) {
    while (iVar1 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(param_1 + 4) + 4)),
          iVar3 < iVar1) {
      ppcVar2 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                   (*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar3);
      if (**ppcVar2 == 'I') {
        iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,ppcVar2[3]);
        if (iVar1 == 0) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
      }
      else {
        iVar3 = iVar3 + 1;
      }
    }
  }
  else {
    for (; iVar1 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(param_1 + 4) + 4)),
        iVar3 < iVar1; iVar3 = iVar3 + 1) {
      ppcVar2 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                   (*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar3);
      if ((**ppcVar2 != 'I') &&
         (iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,ppcVar2[3]), iVar1 == 0)) {
        return iVar3;
      }
    }
  }
  return -1;
}

