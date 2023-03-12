
undefined4 conn_free(int param_1)

{
  int __fd;
  int *ptr;
  
  if (param_1 == 0) {
    return 0;
  }
  ptr = *(int **)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x10) == 0) {
    return 1;
  }
  __fd = *(int *)(param_1 + 0x1c);
  if (__fd == -1) {
    if (ptr == (int *)0x0) goto LAB_0009efc4;
  }
  else {
    if (*ptr == 6) {
      shutdown(__fd,2);
      __fd = *(int *)(param_1 + 0x1c);
    }
    close(__fd);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  if ((void *)ptr[1] != (void *)0x0) {
    CRYPTO_free((void *)ptr[1]);
  }
  if ((void *)ptr[2] != (void *)0x0) {
    CRYPTO_free((void *)ptr[2]);
  }
  CRYPTO_free(ptr);
LAB_0009efc4:
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}

