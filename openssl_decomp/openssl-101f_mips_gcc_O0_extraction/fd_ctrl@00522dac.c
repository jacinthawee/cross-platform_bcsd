
undefined4 fd_ctrl(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 0xd) {
    if (param_2 < 0xb) {
      if (param_2 == 3) goto LAB_00522f14;
      if (param_2 < 4) {
        param_3 = 0;
        if (param_2 != 1) {
          return 0;
        }
        uVar1 = *(undefined4 *)(param_1 + 0x1c);
        goto LAB_00522e40;
      }
      if (param_2 == 8) {
        return *(undefined4 *)(param_1 + 0x10);
      }
      if (param_2 != 9) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x10) = param_3;
    }
    uVar1 = 1;
  }
  else {
    if (param_2 != 0x69) {
      if (param_2 < 0x6a) {
        if (param_2 != 0x68) {
          return 0;
        }
        if ((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
          if (*(int *)(param_1 + 0xc) == 0) {
            *(undefined4 *)(param_1 + 0xc) = 0;
            *(undefined4 *)(param_1 + 0x14) = 0;
          }
          else {
            (*(code *)PTR_close_006aaa5c)(*(undefined4 *)(param_1 + 0x1c));
            *(undefined4 *)(param_1 + 0xc) = 0;
            *(undefined4 *)(param_1 + 0x14) = 0;
          }
        }
        uVar1 = *param_4;
        *(undefined4 *)(param_1 + 0x10) = param_3;
        *(undefined4 *)(param_1 + 0xc) = 1;
        *(undefined4 *)(param_1 + 0x1c) = uVar1;
        return 1;
      }
      if (param_2 == 0x80) {
        uVar1 = *(undefined4 *)(param_1 + 0x1c);
LAB_00522e40:
                    /* WARNING: Could not recover jumptable at 0x00522e58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)PTR_lseek_006aabdc)(uVar1,param_3,0);
        return uVar1;
      }
      if (param_2 != 0x85) {
        return 0;
      }
LAB_00522f14:
                    /* WARNING: Could not recover jumptable at 0x00522f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)PTR_lseek_006aabdc)(*(undefined4 *)(param_1 + 0x1c),0,1);
      return uVar1;
    }
    uVar1 = 0xffffffff;
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x1c);
      }
      return *(undefined4 *)(param_1 + 0x1c);
    }
  }
  return uVar1;
}

