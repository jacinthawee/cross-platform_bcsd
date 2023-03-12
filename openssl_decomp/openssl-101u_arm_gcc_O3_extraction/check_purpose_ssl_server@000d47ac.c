
uint check_purpose_ssl_server(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_2 + 0x28);
  if (((uVar2 & 4) == 0) || (uVar1 = *(uint *)(param_2 + 0x30) & 0x11, uVar1 != 0)) {
    if (param_3 == 0) {
      if (((uVar2 & 8) != 0) && ((*(uint *)(param_2 + 0x34) & 0x40) == 0)) {
        return 0;
      }
      if (-1 < (int)(uVar2 << 0x1e)) {
        return 1;
      }
      return (uint)((*(uint *)(param_2 + 0x2c) & 0xa0) != 0);
    }
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
          if ((*(uint *)(param_2 + 0x34) & 4) == 0) {
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
  return uVar1;
}

