
undefined4 sock_free(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      return 1;
    }
    (*(code *)PTR_shutdown_006a995c)(*(undefined4 *)(param_1 + 0x1c),2);
    (*(code *)PTR_close_006a994c)(*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 1;
}
