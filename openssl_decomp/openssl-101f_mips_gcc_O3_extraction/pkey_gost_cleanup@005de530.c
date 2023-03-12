
void pkey_gost_cleanup(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)();
  if (*(int *)(iVar1 + 8) != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
                    /* WARNING: Could not recover jumptable at 0x005de584. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
  return;
}

