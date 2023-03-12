
int SSL_CTX_use_PrivateKey_ASN1(int pk,SSL_CTX *ctx,uchar *d,long len)

{
  EVP_PKEY *pkey;
  int iVar1;
  uchar *local_14;
  
  local_14 = d;
  pkey = d2i_PrivateKey(pk,(EVP_PKEY **)0x0,&local_14,len);
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xae,0x41,"ssl_rsa.c",0x272);
    }
    else {
      iVar1 = ssl_set_pkey(ctx->cert,pkey);
    }
    EVP_PKEY_free(pkey);
    return iVar1;
  }
  ERR_put_error(0x14,0xaf,0xd,"ssl_rsa.c",0x2b2);
  return 0;
}

