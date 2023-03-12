
void ssl2_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar1 + 0x30) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (*(int *)(iVar1 + 0x34) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar1,0x120);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  return;
}

