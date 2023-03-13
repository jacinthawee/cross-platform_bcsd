
uint ssl3_cbc_remove_padding(undefined4 param_1,uint *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2[1];
  uVar2 = 0;
  if (param_4 + 1U <= uVar1) {
    uVar3 = (uint)*(byte *)((param_2[3] - 1) + uVar1);
    uVar2 = param_4 + 1U + uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = ~((int)((uVar1 - uVar2 ^ uVar2 | uVar2 ^ uVar1) ^ uVar1 |
                   (param_3 - uVar3 ^ uVar3 | uVar3 ^ param_3) ^ param_3) >> 0x1f);
    uVar3 = uVar3 & uVar2;
    *param_2 = *param_2 | uVar3 << 8;
    param_2[1] = uVar1 - uVar3;
    uVar2 = ~(uVar2 & 0xfffffffe);
  }
  return uVar2;
}

