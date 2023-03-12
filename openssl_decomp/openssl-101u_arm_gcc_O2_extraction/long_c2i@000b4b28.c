
undefined4
long_c2i(uint *param_1,byte *param_2,uint param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  int line;
  uint uVar4;
  uint uVar5;
  
  if (4 < (int)param_3) {
    line = 0xa3;
    goto LAB_000b4b8c;
  }
  uVar5 = param_3;
  if (param_3 != 0) {
    uVar5 = (uint)*param_2;
    if ((int)(uVar5 << 0x18) < 0) {
      if (0 < (int)param_3) {
        uVar5 = ~uVar5 & 0xff;
        if ((1 < (int)param_3) && (uVar5 = (uint)(byte)~param_2[1] | uVar5 << 8, 2 < (int)param_3))
        {
          uVar4 = param_3;
          if (3 < (int)param_3) {
            uVar4 = (uint)param_2[3];
          }
          if (3 < (int)param_3) {
            uVar4 = ~uVar4;
          }
          uVar5 = (uint)(byte)~param_2[2] | uVar5 << 8;
          if (3 < (int)param_3) {
            uVar4 = uVar4 & 0xff;
          }
          if (3 < (int)param_3) {
            uVar5 = uVar4 | uVar5 << 8;
          }
        }
        bVar3 = true;
        goto LAB_000b4b6a;
      }
      uVar5 = 0;
LAB_000b4b6c:
      uVar5 = ~uVar5;
    }
    else if ((int)param_3 < 1) {
      uVar5 = 0;
    }
    else {
      if (1 < (int)param_3) {
        uVar1 = CONCAT11(*param_2,param_2[1]);
        uVar5 = (uint)uVar1;
        if (2 < (int)param_3) {
          uVar2 = CONCAT21(uVar1,param_2[2]);
          uVar5 = (uint)uVar2;
          if (3 < (int)param_3) {
            uVar5 = CONCAT31(uVar2,param_2[3]);
          }
        }
      }
      bVar3 = false;
LAB_000b4b6a:
      if (bVar3) goto LAB_000b4b6c;
    }
  }
  if (*(uint *)(param_6 + 0x14) != uVar5) {
    *param_1 = uVar5;
    return 1;
  }
  line = 0xb9;
LAB_000b4b8c:
  ERR_put_error(0xd,0xa6,0x80,"x_long.c",line);
  return 0;
}

