
undefined4 ssl_new(int param_1)

{
  void *__s;
  
  __s = CRYPTO_malloc(0x18,"bio_ssl.c",0x6c);
  if (__s != (void *)0x0) {
    memset(__s,0,0x18);
    *(void **)(param_1 + 0x20) = __s;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  ERR_put_error(0x20,0x76,0x41,"bio_ssl.c",0x6f);
  return 0;
}

