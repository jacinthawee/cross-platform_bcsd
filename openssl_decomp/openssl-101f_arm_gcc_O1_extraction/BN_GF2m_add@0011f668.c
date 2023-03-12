
undefined4 BN_GF2m_add(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  ulong *puVar1;
  BIGNUM *pBVar2;
  int iVar3;
  ulong *puVar4;
  ulong *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BIGNUM *pBVar9;
  
  iVar6 = param_2->top;
  iVar3 = param_3->top;
  iVar8 = iVar6;
  pBVar2 = param_3;
  iVar7 = iVar3;
  if (iVar6 < iVar3) {
    iVar8 = iVar3;
    pBVar2 = param_1;
    iVar7 = iVar6;
  }
  pBVar9 = param_2;
  if (iVar3 <= iVar6) {
    pBVar9 = pBVar2;
    param_3 = param_2;
  }
  if (param_1->dmax < iVar8) {
    pBVar2 = bn_expand2(param_1,iVar8);
    if (pBVar2 == (BIGNUM *)0x0) {
      return 0;
    }
    iVar7 = pBVar9->top;
  }
  if (iVar7 < 1) {
    iVar7 = 0;
  }
  else {
    puVar1 = param_1->d;
    iVar8 = 0;
    puVar4 = param_3->d;
    iVar7 = 0;
    puVar5 = pBVar9->d;
    do {
      iVar7 = iVar7 + 1;
      *(uint *)((int)puVar1 + iVar8) =
           *(uint *)((int)puVar4 + iVar8) ^ *(uint *)((int)puVar5 + iVar8);
      iVar8 = iVar8 + 4;
    } while (iVar7 < pBVar9->top);
  }
  iVar8 = param_3->top;
  if (iVar7 < iVar8) {
    puVar1 = param_3->d;
    iVar3 = iVar7 * 4;
    puVar4 = param_1->d;
    iVar6 = 0;
    do {
      iVar7 = iVar7 + 1;
      *(undefined4 *)((int)puVar4 + iVar6 + iVar3) = *(undefined4 *)((int)puVar1 + iVar6 + iVar3);
      iVar6 = iVar6 + 4;
      iVar8 = param_3->top;
    } while (iVar7 < iVar8);
  }
  param_1->top = iVar8;
  if (iVar8 < 1) {
    return 1;
  }
  puVar1 = param_1->d + iVar8 + 0x3fffffff;
  do {
    if (*puVar1 != 0) break;
    iVar8 = iVar8 + -1;
    puVar1 = puVar1 + -1;
  } while (iVar8 != 0);
  param_1->top = iVar8;
  return 1;
}

