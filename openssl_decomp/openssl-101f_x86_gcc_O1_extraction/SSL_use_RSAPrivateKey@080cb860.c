
int SSL_use_RSAPrivateKey(SSL *ssl,RSA *rsa)

{
  int iVar1;
  EVP_PKEY *pkey;
  int line;
  
  if (rsa == (RSA *)0x0) {
    line = 0x9f;
    iVar1 = 0x43;
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xcc,0x41,"ssl_rsa.c",0xa4);
      return 0;
    }
    pkey = EVP_PKEY_new();
    if (pkey != (EVP_PKEY *)0x0) {
      RSA_up_ref(rsa);
      EVP_PKEY_assign(pkey,6,rsa);
      iVar1 = ssl_set_pkey();
      EVP_PKEY_free(pkey);
      return iVar1;
    }
    line = 0xa9;
    iVar1 = 6;
  }
  ERR_put_error(0x14,0xcc,iVar1,"ssl_rsa.c",line);
  return 0;
}

