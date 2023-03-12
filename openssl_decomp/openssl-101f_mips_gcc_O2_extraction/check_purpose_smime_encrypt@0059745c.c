
uint check_purpose_smime_encrypt(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0x28);
  if (((uVar2 & 4) == 0) || ((*(uint *)(param_2 + 0x30) & 4) != 0)) {
    if (param_3 == 0) {
      if (((uVar2 & 8) == 0) || ((*(uint *)(param_2 + 0x34) & 0x20) != 0)) {
        uVar1 = 1;
        if ((uVar2 & 2) == 0) {
          return uVar1;
        }
      }
      else {
        if ((*(uint *)(param_2 + 0x34) & 0x80) == 0) {
          return 0;
        }
        uVar1 = 2;
        if ((uVar2 & 2) == 0) {
          return 2;
        }
      }
      if ((*(uint *)(param_2 + 0x2c) & 0x20) == 0) {
        uVar1 = 0;
      }
      return uVar1;
    }
    if (((uVar2 & 2) == 0) || ((*(uint *)(param_2 + 0x2c) & 4) != 0)) {
      if ((uVar2 & 1) != 0) {
        return (uVar2 << 0x1b) >> 0x1f;
      }
      if ((uVar2 & 0x60) == 0x60) {
        return 3;
      }
      if ((uVar2 & 2) != 0) {
        return 4;
      }
      if ((uVar2 & 8) != 0) {
        uVar2 = 5;
        if ((*(uint *)(param_2 + 0x34) & 7) != 0) {
          if ((*(uint *)(param_2 + 0x34) & 2) == 0) {
            uVar2 = 0;
          }
          return uVar2;
        }
      }
    }
  }
  return 0;
}

