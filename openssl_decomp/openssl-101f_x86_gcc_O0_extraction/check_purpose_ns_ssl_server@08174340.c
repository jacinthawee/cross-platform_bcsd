
uint check_purpose_ns_ssl_server(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_2 + 0x28);
  if (((uVar1 & 4) == 0) || (uVar2 = 0, (*(byte *)(param_2 + 0x30) & 0x11) != 0)) {
    if (param_3 == 0) {
      if ((((uVar1 & 8) == 0) || (uVar2 = 0, (*(byte *)(param_2 + 0x34) & 0x40) != 0)) &&
         (uVar2 = 1, (uVar1 & 2) != 0)) {
        uVar2 = 0;
        if ((*(uint *)(param_2 + 0x2c) & 0xa0) != 0) {
          uVar2 = *(uint *)(param_2 + 0x2c) >> 5 & 1;
        }
      }
    }
    else {
      uVar3 = uVar1 & 2;
      if ((uVar3 == 0) || (uVar2 = 0, (*(byte *)(param_2 + 0x2c) & 4) != 0)) {
        if ((uVar1 & 1) != 0) {
          return (uint)((uVar1 & 0x10) != 0);
        }
        uVar2 = 3;
        if (((((uVar1 & 0x60) != 0x60) && (uVar2 = 4, uVar3 == 0)) && (uVar2 = 0, (uVar1 & 8) != 0))
           && (uVar2 = uVar3, (*(uint *)(param_2 + 0x34) & 7) != 0)) {
          uVar2 = (int)(*(uint *)(param_2 + 0x34) << 0x1d) >> 0x1f & 5;
        }
      }
    }
  }
  return uVar2;
}

