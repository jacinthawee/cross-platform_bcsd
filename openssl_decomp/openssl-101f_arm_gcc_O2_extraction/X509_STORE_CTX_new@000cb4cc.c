
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_STORE_CTX * X509_STORE_CTX_new(void)

{
  X509_STORE_CTX *__s;
  
  __s = (X509_STORE_CTX *)CRYPTO_malloc(0x88,"x509_vfy.c",0x7c7);
  if (__s == (X509_STORE_CTX *)0x0) {
    ERR_put_error(0xb,0x8e,0x41,"x509_vfy.c",0x7ca);
  }
  else {
    memset(__s,0,0x88);
  }
  return __s;
}

