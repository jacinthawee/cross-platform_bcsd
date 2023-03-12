
void * TS_VERIFY_CTX_new(void)

{
  void *__s;
  
  __s = CRYPTO_malloc(0x28,"ts_verify_ctx.c",0x42);
  if (__s != (void *)0x0) {
    memset(__s,0,0x28);
    return __s;
  }
  ERR_put_error(0x2f,0x90,0x41,"ts_verify_ctx.c",0x46);
  return (void *)0x0;
}

