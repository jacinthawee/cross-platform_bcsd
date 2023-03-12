
void pkey_hmac_cleanup(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(iVar2 + 0x14);
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 != 0) {
    if (*(int *)(iVar2 + 4) != 0) {
      (*(code *)PTR_OPENSSL_cleanse_006a8174)();
      iVar1 = *(int *)(iVar2 + 0xc);
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x005e2e40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
  return;
}

