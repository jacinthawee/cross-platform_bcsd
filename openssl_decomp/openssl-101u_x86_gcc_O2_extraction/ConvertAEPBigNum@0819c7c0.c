
undefined4 ConvertAEPBigNum(BIGNUM *param_1,uint param_2,int param_3)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2 * 8;
  if (iVar3 < 0x7fffffe1) {
    iVar2 = iVar3 + 0x1f;
    if (iVar3 + 0x1f < 0) {
      iVar2 = iVar3 + 0x3e;
    }
    if (param_1->dmax < iVar2 >> 5) {
      bn_expand2(param_1,iVar2 >> 5);
    }
  }
  param_1->top = param_2 >> 2;
  if (param_2 >> 2 != 0) {
    puVar1 = param_1->d;
    iVar3 = 0;
    do {
      puVar1[iVar3] = *(ulong *)(param_3 + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (param_1->top != iVar3 && iVar3 <= param_1->top);
  }
  return 0;
}

