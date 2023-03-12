
int * ssl_cert_inst(int **param_1)

{
  int **__s;
  EVP_MD *pEVar1;
  
  if (param_1 == (int **)0x0) {
    ERR_put_error(0x14,0xde,0x43,"ssl_cert.c",0x1a2);
    __s = param_1;
  }
  else {
    __s = (int **)(int *)0x1;
    if (*param_1 == (int *)0x0) {
      __s = (int **)CRYPTO_malloc(0x94,"ssl_cert.c",0xb6);
      if (__s == (int **)0x0) {
        ERR_put_error(0x14,0xa2,0x41,"ssl_cert.c",0xb9);
        *param_1 = (int *)0x0;
        ERR_put_error(0x14,0xde,0x41,"ssl_cert.c",0x1a9);
      }
      else {
        memset(__s,0,0x94);
        __s[0x24] = (int *)0x1;
        *__s = (int *)(__s + 0xc);
        pEVar1 = EVP_sha1();
        __s[0x14] = &pEVar1->type;
        pEVar1 = EVP_sha1();
        __s[0x11] = &pEVar1->type;
        pEVar1 = EVP_sha1();
        __s[0xe] = &pEVar1->type;
        pEVar1 = EVP_sha1();
        __s[0x1d] = &pEVar1->type;
        *param_1 = (int *)__s;
        __s = (int **)(int *)0x1;
      }
    }
  }
  return (int *)__s;
}

