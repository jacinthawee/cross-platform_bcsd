
void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx)

{
  code *pcVar1;
  
  if (ctx != (EVP_PKEY_CTX *)0x0) {
    if ((*(int *)ctx != 0) && (pcVar1 = *(code **)(*(int *)ctx + 0x10), pcVar1 != (code *)0x0)) {
      (*pcVar1)();
    }
    if (*(EVP_PKEY **)(ctx + 8) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(ctx + 8));
    }
    if (*(EVP_PKEY **)(ctx + 0xc) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(ctx + 0xc));
    }
    if (*(int *)(ctx + 4) != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
                    /* WARNING: Could not recover jumptable at 0x00548764. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(ctx);
    return;
  }
  return;
}

