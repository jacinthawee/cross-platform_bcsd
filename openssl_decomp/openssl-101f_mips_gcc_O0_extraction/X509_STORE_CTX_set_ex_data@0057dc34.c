
int X509_STORE_CTX_set_ex_data(X509_STORE_CTX *ctx,int idx,void *data)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0057dc40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a9480)(&ctx->ex_data);
  return iVar1;
}

