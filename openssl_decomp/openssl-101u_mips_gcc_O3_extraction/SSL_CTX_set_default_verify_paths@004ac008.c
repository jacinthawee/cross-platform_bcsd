
int SSL_CTX_set_default_verify_paths(SSL_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004ac014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_STORE_set_default_paths_006a7298)(ctx->cert_store);
  return iVar1;
}

