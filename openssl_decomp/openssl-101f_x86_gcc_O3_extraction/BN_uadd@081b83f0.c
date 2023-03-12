
int BN_uadd(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  ulong uVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  int num;
  ulong *puVar6;
  int iVar7;
  
  iVar7 = a->top;
  iVar2 = b->top;
  pBVar4 = a;
  num = iVar2;
  if (iVar7 < iVar2) {
    pBVar4 = b;
    b = a;
    num = iVar7;
    iVar7 = iVar2;
  }
  if ((r->dmax <= iVar7) && (pBVar3 = bn_expand2(r,iVar7 + 1), pBVar3 == (BIGNUM *)0x0)) {
    return 0;
  }
  puVar6 = pBVar4->d;
  r->top = iVar7;
  iVar7 = iVar7 - num;
  puVar5 = r->d + num;
  uVar1 = bn_add_words(r->d,puVar6,b->d,num);
  puVar6 = puVar6 + num;
  if (uVar1 != 0) {
    if (iVar7 == 0) {
LAB_081b848a:
      *puVar5 = 1;
      r->top = r->top + 1;
      goto LAB_081b8494;
    }
    uVar1 = *puVar6 + 1;
    *puVar5 = uVar1;
    while( true ) {
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      iVar7 = iVar7 + -1;
      if (uVar1 != 0) break;
      if (iVar7 == 0) goto LAB_081b848a;
      uVar1 = *puVar6 + 1;
      *puVar5 = uVar1;
    }
  }
  if ((puVar6 != puVar5) && (iVar7 != 0)) {
    iVar2 = 0;
    do {
      puVar5[iVar2] = puVar6[iVar2];
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar7);
  }
LAB_081b8494:
  r->neg = 0;
  return 1;
}

