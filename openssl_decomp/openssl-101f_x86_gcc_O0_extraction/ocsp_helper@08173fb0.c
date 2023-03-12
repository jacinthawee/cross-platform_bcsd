
uint ocsp_helper(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1;
  if (param_3 != 0) {
    uVar1 = *(uint *)(param_2 + 0x28);
    if (((uVar1 & 2) == 0) || (uVar2 = 0, (*(byte *)(param_2 + 0x2c) & 4) != 0)) {
      if ((uVar1 & 1) == 0) {
        uVar2 = 3;
        if ((((uVar1 & 0x60) != 0x60) && (uVar2 = 4, (uVar1 & 2) == 0)) &&
           (uVar2 = 0, (uVar1 & 8) != 0)) {
          return ~-(uint)((*(uint *)(param_2 + 0x34) & 7) == 0) & 5;
        }
      }
      else {
        uVar2 = uVar1 >> 4 & 1;
      }
    }
  }
  return uVar2;
}

