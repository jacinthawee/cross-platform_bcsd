
__off_t fd_ctrl(int param_1,int param_2,__off_t param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  __off_t _Var2;
  
  if (param_2 < 0xd) {
    if (param_2 < 0xb) {
      if (param_2 == 3) {
LAB_08117857:
        _Var2 = lseek(*(int *)(param_1 + 0x1c),0,1);
        return _Var2;
      }
      if (3 < param_2) {
        if (param_2 == 8) {
          return *(__off_t *)(param_1 + 0x10);
        }
        if (param_2 != 9) {
          return 0;
        }
        *(__off_t *)(param_1 + 0x10) = param_3;
        return 1;
      }
      param_3 = 0;
      if (param_2 != 1) {
        return 0;
      }
LAB_081177ef:
      _Var2 = lseek(*(int *)(param_1 + 0x1c),param_3,0);
      return _Var2;
    }
  }
  else {
    if (param_2 == 0x69) {
      if (*(int *)(param_1 + 0xc) == 0) {
        return -1;
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x1c);
      }
      return *(__off_t *)(param_1 + 0x1c);
    }
    if (0x69 < param_2) {
      if (param_2 != 0x80) {
        if (param_2 != 0x85) {
          return 0;
        }
        goto LAB_08117857;
      }
      goto LAB_081177ef;
    }
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
    *(__off_t *)(param_1 + 0x10) = param_3;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
  }
  return 1;
}

