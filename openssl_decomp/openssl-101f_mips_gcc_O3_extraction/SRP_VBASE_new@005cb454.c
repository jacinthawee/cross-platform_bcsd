
int * SRP_VBASE_new(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"srp_vfy.c",0xf6);
  if (piVar1 != (int *)0x0) {
    iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
    *piVar1 = iVar2;
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
      piVar1[1] = iVar2;
      if (iVar2 != 0) {
        piVar1[3] = 0;
        piVar1[4] = 0;
        piVar1[2] = 0;
        if (param_1 == 0) {
          return piVar1;
        }
        iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(param_1);
        piVar1[2] = iVar2;
        if (iVar2 == 0) {
          (*(code *)PTR_sk_free_006a7f80)(*piVar1);
          (*(code *)PTR_sk_free_006a7f80)(piVar1[1]);
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar1);
          return (int *)0x0;
        }
        return piVar1;
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar1);
  }
  return (int *)0x0;
}

