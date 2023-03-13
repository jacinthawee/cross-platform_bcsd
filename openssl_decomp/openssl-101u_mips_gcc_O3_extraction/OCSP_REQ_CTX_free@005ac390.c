
void OCSP_REQ_CTX_free(OCSP_REQ_CTX *rctx)

{
  if (*(int *)(rctx + 0x10) != 0) {
    (*(code *)PTR_BIO_free_006a6e70)();
  }
  if (*(int *)(rctx + 4) != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
                    /* WARNING: Could not recover jumptable at 0x005ac3ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(rctx);
  return;
}

