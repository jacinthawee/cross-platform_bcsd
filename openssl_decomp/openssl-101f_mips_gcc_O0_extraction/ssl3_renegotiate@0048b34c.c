
undefined4 ssl3_renegotiate(int param_1)

{
  if (*(int *)(param_1 + 0x20) == 0) {
    return 1;
  }
  if ((**(uint **)(param_1 + 0x58) & 1) == 0) {
    (*(uint **)(param_1 + 0x58))[0x65] = 1;
    return 1;
  }
  return 0;
}

