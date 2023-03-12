
void OCSP_REQ_CTX_free(OCSP_REQ_CTX *rctx)

{
  if (*(int *)(rctx + 0x10) != 0) {
    (*(code *)PTR_BIO_free_006a7f70)();
  }
  if (*(int *)(rctx + 4) != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
                    /* WARNING: Could not recover jumptable at 0x005aeebc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(rctx);
  return;
}

