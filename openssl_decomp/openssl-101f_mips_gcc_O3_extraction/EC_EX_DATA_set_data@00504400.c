
undefined4 EC_EX_DATA_set_data(int **param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  int **ppiVar2;
  
  if (param_1 != (int **)0x0) {
    for (piVar1 = *param_1; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if ((((int *)piVar1[2] == param_3) && ((int *)piVar1[3] == param_4)) &&
         ((int *)piVar1[4] == param_5)) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd3,0x6c,"ec_lib.c",0x231);
        return 0;
      }
    }
    if (param_2 == (int *)0x0) {
      return 1;
    }
    ppiVar2 = (int **)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"ec_lib.c",0x23a);
    if (ppiVar2 != (int **)0x0) {
      ppiVar2[1] = param_2;
      ppiVar2[2] = param_3;
      ppiVar2[3] = param_4;
      ppiVar2[4] = param_5;
      *ppiVar2 = *param_1;
      *param_1 = (int *)ppiVar2;
      return 1;
    }
  }
  return 0;
}

