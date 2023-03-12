
int SSL_CTX_get_verify_depth(SSL_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004aab7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_get_depth_006a9448)(ctx->param);
  return iVar1;
}

