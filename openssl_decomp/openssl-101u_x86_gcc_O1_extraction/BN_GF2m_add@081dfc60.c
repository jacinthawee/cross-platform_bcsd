
undefined4 BN_GF2m_add(BIGNUM *param_1,int *param_2,int *param_3)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = param_2[1];
  iVar3 = param_3[1];
  iVar2 = iVar3;
  piVar6 = param_3;
  if (iVar3 <= iVar5) {
    iVar2 = iVar5;
    iVar5 = iVar3;
    piVar6 = param_2;
    param_2 = param_3;
  }
  if (param_1->dmax < iVar2) {
    pBVar4 = bn_expand2(param_1,iVar2);
    if (pBVar4 == (BIGNUM *)0x0) {
      return 0;
    }
    iVar5 = param_2[1];
  }
  if (iVar5 < 1) {
    iVar3 = 0;
  }
  else {
    iVar5 = *piVar6;
    iVar2 = *param_2;
    puVar1 = param_1->d;
    iVar3 = 0;
    do {
      puVar1[iVar3] = *(uint *)(iVar5 + iVar3 * 4) ^ *(uint *)(iVar2 + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (param_2[1] != iVar3 && iVar3 <= param_2[1]);
  }
  iVar5 = piVar6[1];
  if (iVar3 < iVar5) {
    iVar2 = *piVar6;
    puVar1 = param_1->d;
    do {
      puVar1[iVar3] = *(ulong *)(iVar2 + iVar3 * 4);
      iVar5 = piVar6[1];
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar5);
  }
  param_1->top = iVar5;
  if (iVar5 < 1) {
    return 1;
  }
  do {
    if (param_1->d[iVar5 + -1] != 0) break;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  param_1->top = iVar5;
  return 1;
}

