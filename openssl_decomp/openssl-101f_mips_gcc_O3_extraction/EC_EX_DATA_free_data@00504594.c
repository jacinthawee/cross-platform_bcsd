
void EC_EX_DATA_free_data(int **param_1,int param_2,code *param_3,int param_4)

{
  int **ppiVar1;
  int **ppiVar2;
  int iVar3;
  
  if (param_1 != (int **)0x0) {
    ppiVar2 = (int **)*param_1;
    while (ppiVar1 = ppiVar2, ppiVar1 != (int **)0x0) {
      if (((ppiVar1[2] == (int *)param_2) && (ppiVar1[3] == (int *)param_3)) &&
         (ppiVar1[4] == (int *)param_4)) {
        iVar3 = (int)*ppiVar1;
        (*param_3)(ppiVar1[1]);
        (*(code *)PTR_CRYPTO_free_006a7f88)(*param_1);
        *param_1 = (int *)iVar3;
        return;
      }
      param_1 = ppiVar1;
      ppiVar2 = (int **)*ppiVar1;
    }
  }
  return;
}

