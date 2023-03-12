
int SSL_use_RSAPrivateKey(SSL *ssl,RSA *rsa)

{
  int iVar1;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar2;
  
  if (rsa == (RSA *)0x0) {
    ERR_put_error(0x14,0xcc,0x43,"ssl_rsa.c",0x9f);
    return 0;
  }
  iVar1 = ssl_cert_inst(&ssl->cert);
  if (iVar1 != 0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xcc,6,"ssl_rsa.c",0xa9);
    }
    else {
      RSA_up_ref(rsa);
      EVP_PKEY_assign(pkey,6,rsa);
      pEVar2 = (EVP_PKEY *)ssl_set_pkey(ssl->cert,pkey);
      EVP_PKEY_free(pkey);
      pkey = pEVar2;
    }
    return (int)pkey;
  }
  ERR_put_error(0x14,0xcc,0x41,"ssl_rsa.c",0xa4);
  return 0;
}

