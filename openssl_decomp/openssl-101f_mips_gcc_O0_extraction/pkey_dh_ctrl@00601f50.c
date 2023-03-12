
undefined4 pkey_dh_ctrl(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0x1001) {
    if (0xff < param_3) {
      **(int **)(param_1 + 0x14) = param_3;
      return 1;
    }
    return 0xfffffffe;
  }
  if (param_2 != 0x1002) {
    uVar1 = 0xfffffffe;
    if (param_2 == 2) {
      uVar1 = 1;
    }
    return uVar1;
  }
  (*(int **)(param_1 + 0x14))[1] = param_3;
  return 1;
}

