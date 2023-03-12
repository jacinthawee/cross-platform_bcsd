
undefined4 ndef_suffix_free(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  
  if (param_4 != (int *)0x0) {
    iVar2 = *param_4;
    if (*(int *)(iVar2 + 0x14) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar1 = PTR_CRYPTO_free_006a6e88;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *param_2 = 0;
    *param_3 = 0;
    (*(code *)puVar1)(*param_4);
    *param_4 = 0;
    return 1;
  }
  return 0;
}

