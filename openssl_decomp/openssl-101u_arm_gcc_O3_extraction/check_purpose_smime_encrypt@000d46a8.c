
uint check_purpose_smime_encrypt(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_2 + 0x28);
  if (((uVar2 & 4) == 0) || (uVar1 = *(uint *)(param_2 + 0x30) & 4, uVar1 != 0)) {
    if (param_3 == 0) {
      if (((int)(uVar2 << 0x1c) < 0) && ((*(uint *)(param_2 + 0x34) & 0x20) == 0)) {
        if (-1 < (int)(*(uint *)(param_2 + 0x34) << 0x18)) {
          return 0;
        }
        uVar1 = 2;
      }
      else {
        uVar1 = 1;
      }
      if ((int)(uVar2 << 0x1e) < 0) {
        if ((*(uint *)(param_2 + 0x2c) & 0x20) == 0) {
          uVar1 = 0;
        }
        return uVar1;
      }
    }
    else {
      uVar3 = uVar2 & 2;
      if ((uVar3 == 0) || (uVar1 = *(uint *)(param_2 + 0x2c) & 4, uVar1 != 0)) {
        if ((int)(uVar2 << 0x1f) < 0) {
          uVar1 = (uVar2 << 0x1b) >> 0x1f;
        }
        else if ((uVar2 & 0x60) == 0x60) {
          uVar1 = 3;
        }
        else if (uVar3 == 0) {
          uVar1 = uVar3;
          if (((int)(uVar2 << 0x1c) < 0) && ((*(uint *)(param_2 + 0x34) & 7) != 0)) {
            if ((*(uint *)(param_2 + 0x34) & 2) == 0) {
              uVar1 = 0;
            }
            else {
              uVar1 = 5;
            }
          }
        }
        else {
          uVar1 = 4;
        }
      }
    }
  }
  return uVar1;
}

