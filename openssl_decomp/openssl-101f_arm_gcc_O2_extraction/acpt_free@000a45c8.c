
undefined4 acpt_free(int param_1)

{
  void *ptr;
  
  if (param_1 == 0) {
    return 0;
  }
  ptr = *(void **)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x10) == 0) {
    return 1;
  }
  if (*(int *)((int)ptr + 8) != -1) {
    shutdown(*(int *)((int)ptr + 8),2);
    close(*(int *)((int)ptr + 8));
    *(undefined4 *)((int)ptr + 8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  if (*(void **)((int)ptr + 4) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)ptr + 4));
  }
  if (*(void **)((int)ptr + 0x10) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)ptr + 0x10));
  }
  if (*(BIO **)((int)ptr + 0x1c) != (BIO *)0x0) {
    BIO_free(*(BIO **)((int)ptr + 0x1c));
  }
  CRYPTO_free(ptr);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}

