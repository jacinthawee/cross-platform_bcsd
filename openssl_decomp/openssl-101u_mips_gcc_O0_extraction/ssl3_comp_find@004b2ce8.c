
int * ssl3_comp_find(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    return (int *)0x0;
  }
  if ((param_1 != 0) && (iVar1 = (*(code *)PTR_sk_num_006a6e2c)(), 0 < iVar1)) {
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      piVar2 = (int *)(*(code *)PTR_sk_value_006a6e24)(param_1,iVar3);
      if (param_2 == *piVar2) {
        return piVar2;
      }
      iVar3 = iVar4;
    } while (iVar1 != iVar4);
  }
  return (int *)0x0;
}

