
undefined4 sock_ctrl(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 0xd) {
    if (10 < param_2) {
      return 1;
    }
    if (param_2 == 8) {
      return *(undefined4 *)(param_1 + 0x10);
    }
    if (param_2 != 9) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x10) = param_3;
    uVar1 = 1;
  }
  else {
    if (param_2 == 0x68) {
      if ((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
        if (*(int *)(param_1 + 0xc) != 0) {
          shutdown(*(int *)(param_1 + 0x1c),2);
          close(*(int *)(param_1 + 0x1c));
        }
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      uVar1 = *param_4;
      *(undefined4 *)(param_1 + 0xc) = 1;
      *(undefined4 *)(param_1 + 0x1c) = uVar1;
      *(undefined4 *)(param_1 + 0x10) = param_3;
      return 1;
    }
    if (param_2 != 0x69) {
      return 0;
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x1c);
      }
      return *(undefined4 *)(param_1 + 0x1c);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

