
undefined4 ConvertAEPBigNum(BIGNUM *param_1,uint param_2,ulong *param_3)

{
  int iVar1;
  ulong *puVar2;
  int iVar3;
  
  iVar3 = param_2 * 8;
  if (iVar3 < 0x7fffffe1) {
    iVar1 = iVar3 + 0x3e;
    if (-1 < iVar3 + 0x1f) {
      iVar1 = iVar3 + 0x1f;
    }
    if (param_1->dmax < iVar1 >> 5) {
      bn_expand2(param_1,iVar1 >> 5);
    }
  }
  param_1->top = param_2 >> 2;
  if (param_2 >> 2 != 0) {
    iVar3 = 0;
    puVar2 = param_1->d + -1;
    do {
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
    } while (iVar3 < param_1->top);
  }
  return 0;
}

