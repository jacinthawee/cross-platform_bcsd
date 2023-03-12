
undefined4 dgram_free(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      if (*(int *)(param_1 + 0xc) != 0) {
        shutdown(*(int *)(param_1 + 0x1c),2);
        close(*(int *)(param_1 + 0x1c));
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    if (*(void **)(param_1 + 0x20) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x20));
    }
    return 1;
  }
  return 0;
}

