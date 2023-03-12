
int BN_lshift1(BIGNUM *r,BIGNUM *a)

{
  BIGNUM *pBVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  ulong *puVar6;
  ulong *puVar7;
  ulong *puVar8;
  
  if (r == a) {
    if ((r->dmax <= r->top) && (pBVar1 = bn_expand2(r,r->top + 1), pBVar1 == (BIGNUM *)0x0)) {
      return 0;
    }
  }
  else {
    iVar2 = a->top;
    r->neg = a->neg;
    if (r->dmax <= iVar2) {
      pBVar1 = bn_expand2(r,iVar2 + 1);
      if (pBVar1 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar2 = a->top;
    }
    r->top = iVar2;
  }
  if (0 < a->top) {
    uVar4 = 0;
    uVar5 = uVar4;
    puVar6 = r->d;
    puVar8 = a->d;
    do {
      uVar3 = *puVar8;
      uVar4 = uVar4 + 1;
      puVar7 = puVar6 + 1;
      *puVar6 = uVar5 | uVar3 << 1;
      uVar5 = -((int)uVar3 >> 0x1f);
      puVar6 = puVar7;
      puVar8 = puVar8 + 1;
    } while ((int)uVar4 < a->top);
    if (uVar5 != 0) {
      *puVar7 = 1;
      r->top = r->top + 1;
      return 1;
    }
  }
  return 1;
}

