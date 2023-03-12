
int SSL_CTX_use_RSAPrivateKey(SSL_CTX *ctx,RSA *rsa)

{
  int iVar1;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar2;
  
  if (rsa == (RSA *)0x0) {
    ERR_put_error(0x14,0xb1,0x43,"ssl_rsa.c",0x1fc);
    return 0;
  }
  iVar1 = ssl_cert_inst(&ctx->cert);
  if (iVar1 != 0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xb1,6,"ssl_rsa.c",0x204);
    }
    else {
      RSA_up_ref(rsa);
      iVar1 = EVP_PKEY_assign(pkey,6,rsa);
      if (iVar1 < 1) {
        pkey = (EVP_PKEY *)0x0;
        RSA_free(rsa);
      }
      else {
        pEVar2 = (EVP_PKEY *)ssl_set_pkey(ctx->cert,pkey);
        EVP_PKEY_free(pkey);
        pkey = pEVar2;
      }
    }
    return (int)pkey;
  }
  ERR_put_error(0x14,0xb1,0x41,"ssl_rsa.c",0x200);
  return 0;
}

