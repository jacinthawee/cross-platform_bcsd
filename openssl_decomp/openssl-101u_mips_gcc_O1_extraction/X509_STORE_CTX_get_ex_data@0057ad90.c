
void * X509_STORE_CTX_get_ex_data(X509_STORE_CTX *ctx,int idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0057ad9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a8364)(&ctx->ex_data);
  return pvVar1;
}

