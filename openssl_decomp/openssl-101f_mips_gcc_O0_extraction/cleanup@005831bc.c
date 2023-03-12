
void cleanup(EVP_PKEY_CTX *ctx)

{
  if (*(int *)ctx == 1) {
    (*(code *)PTR_X509_free_006a7f90)(*(undefined4 *)(ctx + 4));
  }
  else if (*(int *)ctx == 2) {
    (*(code *)PTR_X509_CRL_free_006a8160)(*(undefined4 *)(ctx + 4));
                    /* WARNING: Could not recover jumptable at 0x00583224. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(ctx);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00583200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(ctx);
  return;
}

