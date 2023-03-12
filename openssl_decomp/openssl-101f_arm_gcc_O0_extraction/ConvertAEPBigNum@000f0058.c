
undefined4 ConvertAEPBigNum(BIGNUM *param_1,uint param_2,ulong *param_3)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2 * 8 + 0x1f;
  iVar3 = param_2 * 8 + 0x3e;
  if (-1 < iVar2) {
    iVar3 = iVar2;
  }
  if (param_1->dmax < iVar3 >> 5) {
    bn_expand2(param_1,iVar3 >> 5);
  }
  param_1->top = param_2 >> 2;
  if (param_2 >> 2 != 0) {
    iVar3 = 0;
    puVar1 = param_1->d + -1;
    do {
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
      *puVar1 = *param_3;
      param_3 = param_3 + 1;
    } while (iVar3 < param_1->top);
  }
  return 0;
}

