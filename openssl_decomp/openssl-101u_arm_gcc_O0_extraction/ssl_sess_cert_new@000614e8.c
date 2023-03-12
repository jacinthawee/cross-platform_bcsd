
void * ssl_sess_cert_new(void)

{
  void *__s;
  
  __s = CRYPTO_malloc(0x7c,"ssl_cert.c",0x18b);
  if (__s == (void *)0x0) {
    ERR_put_error(0x14,0xe1,0x41,"ssl_cert.c",0x18d);
  }
  else {
    memset(__s,0,0x7c);
    *(int *)((int)__s + 8) = (int)__s + 0xc;
    *(undefined4 *)((int)__s + 0x78) = 1;
  }
  return __s;
}

