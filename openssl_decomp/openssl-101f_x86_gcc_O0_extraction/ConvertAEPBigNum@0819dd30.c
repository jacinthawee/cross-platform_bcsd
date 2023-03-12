
undefined4 ConvertAEPBigNum(BIGNUM *param_1,uint param_2,int param_3)

{
  ulong *puVar1;
  int iVar2;
  
  iVar2 = param_2 * 8 + 0x1f;
  if (iVar2 < 0) {
    iVar2 = param_2 * 8 + 0x3e;
  }
  if (param_1->dmax < iVar2 >> 5) {
    bn_expand2(param_1,iVar2 >> 5);
  }
  param_1->top = param_2 >> 2;
  if (param_2 >> 2 != 0) {
    puVar1 = param_1->d;
    iVar2 = 0;
    do {
      puVar1[iVar2] = *(ulong *)(param_3 + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (param_1->top != iVar2 && iVar2 <= param_1->top);
  }
  return 0;
}

