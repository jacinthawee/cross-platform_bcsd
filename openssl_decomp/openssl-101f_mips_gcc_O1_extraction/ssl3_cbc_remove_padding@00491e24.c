
uint ssl3_cbc_remove_padding(undefined4 param_1,uint *param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2[1];
  if (param_4 + 1U <= uVar2) {
    uVar1 = (uint)*(byte *)(param_2[3] + uVar2 + -1);
    uVar3 = uVar1 + 1;
    uVar1 = (int)~(param_3 - uVar3 | (uVar2 - uVar1) - (param_4 + 1U)) >> 0x1f;
    uVar3 = uVar3 & uVar1;
    param_2[1] = uVar2 - uVar3;
    *param_2 = *param_2 | uVar3 << 8;
    return uVar1 & 1 | ~uVar1;
  }
  return 0;
}

