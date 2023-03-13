
int X509_STORE_CTX_set_trust(X509_STORE_CTX *ctx,int trust)

{
  int iVar1;
  
  if (trust == 0) {
    return 1;
  }
  iVar1 = X509_TRUST_get_by_id(trust);
  if (iVar1 == -1) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x86,0x78,"x509_vfy.c",0x82e);
    iVar1 = 0;
  }
  else {
    if (ctx->param->trust == 0) {
      ctx->param->trust = trust;
    }
    iVar1 = 1;
  }
  return iVar1;
}

