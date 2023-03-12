
int BN_lshift1(BIGNUM *r,BIGNUM *a)

{
  BIGNUM *pBVar1;
  uint *puVar2;
  uint *puVar3;
  ulong *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (r == a) {
    if ((r->dmax <= r->top) && (pBVar1 = bn_expand2(r,r->top + 1), pBVar1 == (BIGNUM *)0x0)) {
      return 0;
    }
  }
  else {
    iVar5 = a->top;
    r->neg = a->neg;
    if (r->dmax <= iVar5) {
      pBVar1 = bn_expand2(r,iVar5 + 1);
      if (pBVar1 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar5 = a->top;
    }
    r->top = iVar5;
  }
  if (0 < a->top) {
    iVar5 = 0;
    uVar7 = 0;
    puVar2 = r->d;
    puVar4 = a->d;
    do {
      uVar6 = *puVar4;
      puVar3 = puVar2 + 1;
      iVar5 = iVar5 + 1;
      *puVar2 = uVar6 << 1 | uVar7;
      uVar7 = uVar6 >> 0x1f;
      puVar2 = puVar3;
      puVar4 = puVar4 + 1;
    } while (iVar5 < a->top);
    if ((int)uVar6 < 0) {
      *puVar3 = 1;
      r->top = r->top + 1;
      return 1;
    }
  }
  return 1;
}

