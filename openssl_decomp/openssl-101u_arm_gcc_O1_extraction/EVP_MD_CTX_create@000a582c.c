
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD_CTX * EVP_MD_CTX_create(void)

{
  EVP_MD_CTX *__s;
  
  __s = (EVP_MD_CTX *)CRYPTO_malloc(0x18,"digest.c",0x83);
  if (__s != (EVP_MD_CTX *)0x0) {
    memset(__s,0,0x18);
  }
  return __s;
}

