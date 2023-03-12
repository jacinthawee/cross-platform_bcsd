
int BN_lshift1(BIGNUM *r,BIGNUM *a)

{
  ulong *puVar1;
  uint uVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  
  if (r == a) {
    if ((r->dmax <= r->top) && (pBVar4 = bn_expand2(r,r->top + 1), pBVar4 == (BIGNUM *)0x0)) {
      return 0;
    }
  }
  else {
    r->neg = a->neg;
    iVar5 = a->top;
    if (r->dmax <= iVar5) {
      pBVar4 = bn_expand2(r,iVar5 + 1);
      if (pBVar4 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar5 = a->top;
    }
    r->top = iVar5;
  }
  iVar5 = 0;
  puVar1 = a->d;
  puVar6 = r->d;
  uVar3 = 0;
  if (0 < a->top) {
    do {
      uVar2 = puVar1[iVar5];
      puVar7 = puVar6 + 1;
      iVar5 = iVar5 + 1;
      *puVar6 = uVar3 | uVar2 * 2;
      uVar3 = uVar2 >> 0x1f;
      puVar6 = puVar7;
    } while (a->top != iVar5 && iVar5 <= a->top);
    if ((int)uVar2 < 0) {
      *puVar7 = 1;
      r->top = r->top + 1;
    }
  }
  return 1;
}

