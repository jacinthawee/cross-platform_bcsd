
int SSL_CTX_use_RSAPrivateKey_ASN1(SSL_CTX *ctx,uchar *d,long len)

{
  RSA *r;
  EVP_PKEY *pkey;
  int iVar1;
  EVP_PKEY *pEVar2;
  uchar *local_1c [2];
  
  local_1c[0] = d;
  r = d2i_RSAPrivateKey((RSA **)0x0,local_1c,len);
  if (r != (RSA *)0x0) {
    pkey = (EVP_PKEY *)ssl_cert_inst(&ctx->cert);
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xb1,0x41,"ssl_rsa.c",0x200);
    }
    else {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xb1,6,"ssl_rsa.c",0x204);
      }
      else {
        RSA_up_ref(r);
        iVar1 = EVP_PKEY_assign(pkey,6,r);
        if (iVar1 < 1) {
          pkey = (EVP_PKEY *)0x0;
          RSA_free(r);
        }
        else {
          pEVar2 = (EVP_PKEY *)ssl_set_pkey(ctx->cert,pkey);
          EVP_PKEY_free(pkey);
          pkey = pEVar2;
        }
      }
    }
    RSA_free(r);
    return (int)pkey;
  }
  ERR_put_error(0x14,0xb2,0xd,"ssl_rsa.c",0x246);
  return 0;
}
