
undefined4 fd_ctrl(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 < 0xd) {
    if (10 < param_2) {
      return 1;
    }
    if (param_2 == 3) {
LAB_0009dfec:
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
      param_3 = 0;
      uVar2 = 1;
      goto LAB_00011a0c;
    }
    if (3 < param_2) {
      if (param_2 == 8) {
        return *(undefined4 *)(param_1 + 0x10);
      }
      if (param_2 != 9) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x10) = param_3;
      return 1;
    }
    if (param_2 != 1) {
      return 0;
    }
    param_3 = 0;
  }
  else {
    if (param_2 == 0x69) {
      if (*(int *)(param_1 + 0xc) == 0) {
        return 0xffffffff;
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x1c);
      }
      return *(undefined4 *)(param_1 + 0x1c);
    }
    if (param_2 < 0x6a) {
      if (param_2 != 0x68) {
        return 0;
      }
      if ((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
        if (*(int *)(param_1 + 0xc) != 0) {
          close(*(int *)(param_1 + 0x1c));
        }
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      uVar1 = *param_4;
      *(undefined4 *)(param_1 + 0x10) = param_3;
      *(undefined4 *)(param_1 + 0xc) = 1;
      *(undefined4 *)(param_1 + 0x1c) = uVar1;
      return 1;
    }
    if (param_2 != 0x80) {
      if (param_2 != 0x85) {
        return 0;
      }
      goto LAB_0009dfec;
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  uVar2 = 0;
LAB_00011a0c:
  uVar1 = (*(code *)PTR_lseek_00189064)(uVar1,param_3,uVar2);
  return uVar1;
}

