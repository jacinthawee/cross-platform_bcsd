
int * ssl_cert_new(void)

{
  int *__s;
  EVP_MD *pEVar1;
  
  __s = (int *)CRYPTO_malloc(0x94,"ssl_cert.c",0xb6);
  if (__s == (int *)0x0) {
    ERR_put_error(0x14,0xa2,0x41,"ssl_cert.c",0xb9);
  }
  else {
    memset(__s,0,0x94);
    *__s = (int)(__s + 0xc);
    __s[0x24] = 1;
    pEVar1 = EVP_sha1();
    __s[0x14] = (int)pEVar1;
    pEVar1 = EVP_sha1();
    __s[0x11] = (int)pEVar1;
    pEVar1 = EVP_sha1();
    __s[0xe] = (int)pEVar1;
    pEVar1 = EVP_sha1();
    __s[0x1d] = (int)pEVar1;
  }
  return __s;
}

