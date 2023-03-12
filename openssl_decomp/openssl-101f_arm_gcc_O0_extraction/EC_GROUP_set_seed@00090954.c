
size_t EC_GROUP_set_seed(EC_GROUP *param_1,uchar *param_2,size_t len)

{
  void *__dest;
  
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (param_2 == (uchar *)0x0 || len == 0) {
    return 1;
  }
  __dest = CRYPTO_malloc(len,"ec_lib.c",0x182);
  *(void **)(param_1 + 0x3c) = __dest;
  if (__dest != (void *)0x0) {
    memcpy(__dest,param_2,len);
    *(size_t *)(param_1 + 0x40) = len;
    return len;
  }
  return 0;
}

