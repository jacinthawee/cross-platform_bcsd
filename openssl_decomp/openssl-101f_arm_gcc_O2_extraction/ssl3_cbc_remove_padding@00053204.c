
undefined4 ssl3_cbc_remove_padding(undefined4 param_1,uint *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_2[1];
  if (uVar2 < param_4 + 1U) {
    uVar1 = 0;
  }
  else {
    uVar3 = (uint)*(byte *)(param_2[3] + uVar2 + -1);
    uVar4 = uVar3 + 1;
    uVar3 = ~((uVar2 - uVar3) - (param_4 + 1U)) & ~(param_3 - uVar4);
    uVar4 = (int)uVar3 >> 0x1f & uVar4;
    if ((int)uVar3 < 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0xffffffff;
    }
    param_2[1] = uVar2 - uVar4;
    *param_2 = *param_2 | uVar4 << 8;
  }
  return uVar1;
}

