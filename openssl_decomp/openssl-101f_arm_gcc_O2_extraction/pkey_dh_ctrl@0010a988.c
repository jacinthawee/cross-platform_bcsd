
undefined4 pkey_dh_ctrl(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0x1001) {
    if (param_3 < 0x100) {
      return 0xfffffffe;
    }
    **(int **)(param_1 + 0x14) = param_3;
    return 1;
  }
  if (param_2 == 0x1002) {
    (*(int **)(param_1 + 0x14))[1] = param_3;
    return 1;
  }
  if (param_2 == 2) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

