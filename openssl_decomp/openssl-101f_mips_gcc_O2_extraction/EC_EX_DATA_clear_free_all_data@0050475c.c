
void EC_EX_DATA_clear_free_all_data(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    while (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
      (*(code *)piVar1[4])(piVar1[1]);
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar1);
      piVar1 = (int *)iVar2;
    }
    *param_1 = 0;
  }
  return;
}

