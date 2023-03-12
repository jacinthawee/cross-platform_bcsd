
undefined4 x509_name_ex_new(int **param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"x_name.c",0x8f);
  if (piVar1 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xab,0x41,"x_name.c",0x9d);
    return 0;
  }
  iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
  *piVar1 = iVar2;
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_BUF_MEM_new_006a749c)();
    piVar1[2] = iVar2;
    if (iVar2 != 0) {
      piVar1[3] = 0;
      piVar1[4] = 0;
      piVar1[1] = 1;
      *param_1 = piVar1;
      return 1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xab,0x41,"x_name.c",0x9d);
  if (*piVar1 != 0) {
    (*(code *)PTR_sk_free_006a6e80)();
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
  return 0;
}

