
uint ocsp_helper(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    return 1;
  }
  uVar1 = *(uint *)(param_2 + 0x28);
  uVar2 = uVar1 & 2;
  if ((uVar2 != 0) && ((*(uint *)(param_2 + 0x2c) & 4) == 0)) {
    return 0;
  }
  if ((int)(uVar1 << 0x1f) < 0) {
    uVar2 = (uVar1 << 0x1b) >> 0x1f;
  }
  else if ((uVar1 & 0x60) == 0x60) {
    uVar2 = 3;
  }
  else if (uVar2 == 0) {
    if ((int)(uVar1 << 0x1c) < 0) {
      if ((*(uint *)(param_2 + 0x34) & 7) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 5;
      }
    }
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

