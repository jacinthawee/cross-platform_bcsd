
undefined4 aes_gcm_cleanup(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar1 + 0x100,0x178);
  if (*(int *)(iVar1 + 0x278) != param_1 + 0x20) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  return 1;
}

