
int SSL_use_RSAPrivateKey_ASN1(SSL *ssl,uchar *d,long len)

{
  RSA *r;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar1;
  uchar *local_1c [2];
  
  local_1c[0] = d;
  r = d2i_RSAPrivateKey((RSA **)0x0,local_1c,len);
  if (r != (RSA *)0x0) {
    pkey = (EVP_PKEY *)ssl_cert_inst(&ssl->cert);
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xcc,0x41,"ssl_rsa.c",0xa4);
    }
    else {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xcc,6,"ssl_rsa.c",0xa9);
      }
      else {
        RSA_up_ref(r);
        EVP_PKEY_assign(pkey,6,r);
        pEVar1 = (EVP_PKEY *)ssl_set_pkey(ssl->cert,pkey);
        EVP_PKEY_free(pkey);
        pkey = pEVar1;
      }
    }
    RSA_free(r);
    return (int)pkey;
  }
  ERR_put_error(0x14,0xcd,0xd,"ssl_rsa.c",0x11d);
  return 0;
}

