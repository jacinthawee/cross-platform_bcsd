
int * SRP_VBASE_new(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"srp_vfy.c",0x10e);
  if (piVar1 != (int *)0x0) {
    iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *piVar1 = iVar2;
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
      piVar1[1] = iVar2;
      if (iVar2 != 0) {
        piVar1[3] = 0;
        piVar1[4] = 0;
        piVar1[2] = 0;
        if (param_1 == 0) {
          return piVar1;
        }
        iVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_1);
        piVar1[2] = iVar2;
        if (iVar2 == 0) {
          (*(code *)PTR_sk_free_006a6e80)(*piVar1);
          (*(code *)PTR_sk_free_006a6e80)(piVar1[1]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
          return (int *)0x0;
        }
        return piVar1;
      }
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
  }
  return (int *)0x0;
}

