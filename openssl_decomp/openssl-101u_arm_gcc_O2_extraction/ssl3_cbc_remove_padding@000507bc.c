
undefined4 ssl3_cbc_remove_padding(undefined4 param_1,uint *param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2[1];
  if (uVar3 < param_4 + 1U) {
    return 0;
  }
  uVar1 = (uint)*(byte *)(param_2[3] + uVar3 + -1);
  uVar4 = uVar1 + 1;
  uVar1 = param_4 + 1U + uVar1;
  uVar1 = ~((int)(param_3 ^ (param_3 - uVar4 ^ uVar4 | uVar4 ^ param_3)) >> 0x1f) &
          ~((int)((uVar3 - uVar1 ^ uVar1 | uVar1 ^ uVar3) ^ uVar3) >> 0x1f);
  uVar4 = uVar4 & uVar1;
  if (uVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 1;
  }
  param_2[1] = uVar3 - uVar4;
  *param_2 = *param_2 | uVar4 << 8;
  return uVar2;
}

