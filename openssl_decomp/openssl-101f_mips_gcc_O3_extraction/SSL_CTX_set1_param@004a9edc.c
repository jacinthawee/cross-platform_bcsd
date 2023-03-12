
int SSL_CTX_set1_param(SSL_CTX *ctx,X509_VERIFY_PARAM *vpm)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a9ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_set1_006a9438)(ctx->param);
  return iVar1;
}

