
undefined4 fd_free(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      if (*(int *)(param_1 + 0xc) != 0) {
        close(*(int *)(param_1 + 0x1c));
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    return 1;
  }
  return 0;
}
