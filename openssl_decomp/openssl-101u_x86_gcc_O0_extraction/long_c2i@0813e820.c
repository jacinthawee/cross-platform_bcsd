
undefined4
long_c2i(uint *param_1,byte *param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  ushort uVar1;
  uint3 uVar2;
  uint uVar3;
  int line;
  
  if (param_3 < 5) {
    uVar3 = 0;
    if (param_3 != 0) {
      if ((char)*param_2 < '\0') {
        uVar3 = 0xffffffff;
        if (0 < param_3) {
          uVar3 = (uint)(byte)~*param_2;
          if (param_3 != 1) {
            uVar1 = CONCAT11(~*param_2,~param_2[1]);
            uVar3 = (uint)uVar1;
            if (param_3 != 2) {
              uVar2 = CONCAT21(uVar1,~param_2[2]);
              uVar3 = (uint)uVar2;
              if (param_3 == 4) {
                uVar3 = CONCAT31(uVar2,~param_2[3]);
              }
            }
          }
          uVar3 = ~uVar3;
        }
      }
      else if (0 < param_3) {
        uVar3 = (uint)*param_2;
        if (param_3 != 1) {
          uVar1 = CONCAT11(*param_2,param_2[1]);
          uVar3 = (uint)uVar1;
          if (param_3 != 2) {
            uVar2 = CONCAT21(uVar1,param_2[2]);
            uVar3 = (uint)uVar2;
            if (param_3 == 4) {
              uVar3 = CONCAT31(uVar2,param_2[3]);
            }
          }
        }
      }
    }
    if (*(uint *)(param_6 + 0x14) != uVar3) {
      *param_1 = uVar3;
      return 1;
    }
    line = 0xb9;
  }
  else {
    line = 0xa3;
  }
  ERR_put_error(0xd,0xa6,0x80,"x_long.c",line);
  return 0;
}

