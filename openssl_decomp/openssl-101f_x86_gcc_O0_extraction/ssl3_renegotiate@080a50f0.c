
undefined4 ssl3_renegotiate(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
    if ((**(byte **)(param_1 + 0x58) & 1) == 0) {
      *(undefined4 *)(*(byte **)(param_1 + 0x58) + 0x194) = 1;
      return 1;
    }
  }
  return uVar1;
}

