
undefined4 ndef_prefix_free(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  
  if (param_4 != (int *)0x0) {
    iVar1 = *param_4;
    if (*(int *)(iVar1 + 0x14) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *param_2 = 0;
    *param_3 = 0;
    return 1;
  }
  return 0;
}

