
uint check_purpose_ns_ssl_server(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x28);
  if (((uVar1 & 4) == 0) || ((*(uint *)(param_2 + 0x30) & 0x11) != 0)) {
    if (param_3 == 0) {
      if (((uVar1 & 8) == 0) || ((*(uint *)(param_2 + 0x34) & 0x40) != 0)) {
        if ((uVar1 & 2) == 0) {
          return 1;
        }
        if ((*(uint *)(param_2 + 0x2c) & 0xa0) != 0) {
          return (*(uint *)(param_2 + 0x2c) << 0x1a) >> 0x1f;
        }
      }
    }
    else if (((uVar1 & 2) == 0) || ((*(uint *)(param_2 + 0x2c) & 4) != 0)) {
      if ((uVar1 & 1) != 0) {
        return (uVar1 << 0x1b) >> 0x1f;
      }
      if ((uVar1 & 0x60) == 0x60) {
        return 3;
      }
      if ((uVar1 & 2) != 0) {
        return 4;
      }
      if ((uVar1 & 8) != 0) {
        uVar1 = 5;
        if ((*(uint *)(param_2 + 0x34) & 7) != 0) {
          if ((*(uint *)(param_2 + 0x34) & 4) == 0) {
            uVar1 = 0;
          }
          return uVar1;
        }
      }
    }
  }
  return 0;
}

