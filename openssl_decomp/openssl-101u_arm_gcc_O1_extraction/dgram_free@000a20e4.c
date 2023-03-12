
undefined4 dgram_free(int param_1)

{
  void *ptr;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    ptr = *(void **)(param_1 + 0x20);
  }
  else {
    if (*(int *)(param_1 + 0xc) != 0) {
      shutdown(*(int *)(param_1 + 0x1c),2);
      close(*(int *)(param_1 + 0x1c));
    }
    ptr = *(void **)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (ptr != (void *)0x0) {
    CRYPTO_free(ptr);
    return 1;
  }
  return 1;
}

