
undefined4 dgram_new(int param_1)

{
  void *__s;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  __s = CRYPTO_malloc(0x38,"bss_dgram.c",0xdd);
  if (__s != (void *)0x0) {
    memset(__s,0,0x38);
    *(void **)(param_1 + 0x20) = __s;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}

