
void cleanup(EVP_PKEY_CTX *ctx)

{
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    return;
  }
  if (*(int *)ctx != 1) {
    if (*(int *)ctx != 2) {
                    /* WARNING: Could not recover jumptable at 0x00580404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(ctx);
      return;
    }
    (*(code *)PTR_X509_CRL_free_006a7060)(*(undefined4 *)(ctx + 4));
                    /* WARNING: Could not recover jumptable at 0x00580454. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(ctx);
    return;
  }
  (*(code *)PTR_X509_free_006a6e90)(*(undefined4 *)(ctx + 4));
                    /* WARNING: Could not recover jumptable at 0x0058042c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(ctx);
  return;
}

