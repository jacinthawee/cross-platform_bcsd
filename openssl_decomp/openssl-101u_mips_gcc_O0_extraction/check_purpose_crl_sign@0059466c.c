
uint check_purpose_crl_sign(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_2 + 0x28);
  if (param_3 == 0) {
    if ((uVar1 & 2) != 0) {
      return (uint)(*(int *)(param_2 + 0x2c) << 0x1e) >> 0x1f;
    }
    return 1;
  }
  if (((uVar1 & 2) == 0) || ((*(uint *)(param_2 + 0x2c) & 4) != 0)) {
    if ((uVar1 & 1) != 0) {
      return (uVar1 << 0x1b) >> 0x1f;
    }
    if ((uVar1 & 0x60) == 0x60) {
      return 3;
    }
    if ((uVar1 & 2) != 0) {
      return 4;
    }
    uVar2 = 5;
    if ((uVar1 & 8) != 0) {
      if ((*(uint *)(param_2 + 0x34) & 7) == 0) {
        uVar2 = 0;
      }
      return uVar2;
    }
  }
  return 0;
}

