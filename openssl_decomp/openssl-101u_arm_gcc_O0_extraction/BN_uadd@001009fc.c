
int BN_uadd(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  int num;
  ulong uVar1;
  BIGNUM *pBVar2;
  ulong *puVar3;
  int iVar4;
  BIGNUM *pBVar5;
  ulong *puVar6;
  int iVar7;
  int iVar8;
  ulong *rp;
  ulong *ap;
  
  iVar7 = b->top;
  iVar4 = a->top;
  iVar8 = iVar7;
  num = iVar4;
  if (iVar7 <= iVar4) {
    iVar8 = iVar4;
    num = iVar7;
  }
  pBVar5 = b;
  if (iVar4 < iVar7) {
    pBVar5 = a;
    a = b;
  }
  if ((r->dmax <= iVar8) && (pBVar2 = bn_expand2(r,iVar8 + 1), pBVar2 == (BIGNUM *)0x0)) {
    return 0;
  }
  ap = a->d;
  rp = r->d;
  iVar4 = iVar8 - num;
  puVar3 = pBVar5->d;
  r->top = iVar8;
  puVar6 = ap + num;
  uVar1 = bn_add_words(rp,ap,puVar3,num);
  puVar3 = rp + num;
  if (uVar1 != 0) {
    if (iVar4 == 0) {
LAB_00100aa0:
      *puVar3 = 1;
      r->top = r->top + 1;
      goto LAB_00100a88;
    }
    uVar1 = ap[num] + 1;
    rp[num] = uVar1;
    while( true ) {
      puVar3 = puVar3 + 1;
      puVar6 = puVar6 + 1;
      iVar4 = iVar4 + -1;
      if (uVar1 != 0) break;
      if (iVar4 == 0) goto LAB_00100aa0;
      uVar1 = *puVar6 + 1;
      *puVar3 = uVar1;
    }
  }
  if (puVar3 != puVar6 && iVar4 != 0) {
    iVar4 = iVar4 + -1;
    do {
      iVar4 = iVar4 + -1;
      *puVar3 = *puVar6;
      puVar3 = puVar3 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar4 != -1);
  }
LAB_00100a88:
  r->neg = 0;
  return 1;
}

