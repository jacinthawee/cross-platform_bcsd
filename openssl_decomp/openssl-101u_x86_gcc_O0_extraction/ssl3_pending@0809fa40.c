
undefined4 ssl3_pending(int param_1)

{
  if (*(int *)(param_1 + 0x38) == 0xf1) {
    return 0;
  }
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x10c) != 0x17) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x110);
}

