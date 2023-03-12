
undefined4 acpt_new(int param_1)

{
  undefined4 *__s;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  __s = (undefined4 *)CRYPTO_malloc(0x20,"bss_acpt.c",0x92);
  if (__s != (undefined4 *)0x0) {
    memset(__s,0,0x20);
    __s[2] = 0xffffffff;
    __s[6] = 0;
    *(undefined4 **)(param_1 + 0x20) = __s;
    *__s = 1;
    *(undefined4 *)(param_1 + 0x10) = 1;
    return 1;
  }
  return 0;
}

