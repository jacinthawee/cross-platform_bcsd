
void * TS_RESP_CTX_new(void)

{
  void *__s;
  
  __s = CRYPTO_malloc(0x50,"ts_rsp_sign.c",0xac);
  if (__s == (void *)0x0) {
    ERR_put_error(0x2f,0x7f,0x41,"ts_rsp_sign.c",0xad);
  }
  else {
    memset(__s,0,0x50);
    *(undefined4 *)((int)__s + 0x2c) = 0xe90ed;
    *(undefined4 *)((int)__s + 0x34) = 0xe9135;
    *(undefined4 *)((int)__s + 0x3c) = 0xe8c11;
  }
  return __s;
}

