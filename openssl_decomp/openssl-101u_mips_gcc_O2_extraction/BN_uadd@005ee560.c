
int BN_uadd(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  undefined *puVar1;
  ulong uVar2;
  BIGNUM *pBVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = a->top;
  iVar7 = b->top;
  pBVar3 = b;
  iVar8 = iVar7;
  if (iVar9 < iVar7) {
    pBVar3 = a;
    a = b;
    iVar8 = iVar9;
    iVar9 = iVar7;
  }
  if ((r->dmax <= iVar9) && (iVar7 = (*(code *)PTR_bn_expand2_006a8524)(r,iVar9 + 1), iVar7 == 0)) {
    return 0;
  }
  puVar1 = PTR_bn_add_words_006a8584;
  puVar5 = a->d;
  puVar6 = r->d;
  iVar7 = iVar9 - iVar8;
  puVar4 = pBVar3->d;
  r->top = iVar9;
  iVar9 = (*(code *)puVar1)(puVar6,puVar5,puVar4,iVar8);
  puVar6 = puVar6 + iVar8;
  puVar5 = puVar5 + iVar8;
  if (iVar9 != 0) {
    if (iVar7 == 0) {
LAB_005ee648:
      *puVar6 = 1;
      r->top = r->top + 1;
      goto LAB_005ee660;
    }
    uVar2 = *puVar5 + 1;
    *puVar6 = uVar2;
    while( true ) {
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + -1;
      if (uVar2 != 0) break;
      if (iVar7 == 0) goto LAB_005ee648;
      uVar2 = *puVar5 + 1;
      *puVar6 = uVar2;
    }
  }
  if ((iVar7 != 0) && (iVar7 = iVar7 + -1, puVar5 != puVar6)) {
    do {
      iVar7 = iVar7 + -1;
      *puVar6 = *puVar5;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar7 != -1);
  }
LAB_005ee660:
  r->neg = 0;
  return 1;
}

