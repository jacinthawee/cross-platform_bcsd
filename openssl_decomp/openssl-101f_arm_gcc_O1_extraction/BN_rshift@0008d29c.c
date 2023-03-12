
int BN_rshift(BIGNUM *r,BIGNUM *a,int n)

{
  int iVar1;
  int iVar2;
  ulong *puVar3;
  BIGNUM *pBVar4;
  uint uVar5;
  uint uVar6;
  ulong *puVar7;
  int iVar8;
  uint uVar9;
  ulong *puVar10;
  char in_CY;
  
  uVar6 = n + 0x1fU & n >> 0x20;
  if (in_CY == '\0') {
    uVar6 = n;
  }
  iVar8 = (int)uVar6 >> 5;
  if ((iVar8 < a->top) && (a->top != 0)) {
    iVar1 = BN_num_bits(a);
    iVar2 = (iVar1 - n) + 0x1f;
    iVar1 = (iVar1 - n) + 0x3e;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
    iVar1 = iVar1 >> 5;
    if (r == a) {
      if (n == 0) {
        return 1;
      }
    }
    else {
      r->neg = a->neg;
      if ((r->dmax < iVar1) && (pBVar4 = bn_expand2(r,iVar1), pBVar4 == (BIGNUM *)0x0)) {
        return 0;
      }
    }
    puVar10 = a->d;
    iVar2 = a->top;
    r->top = iVar1;
    iVar2 = iVar2 - iVar8;
    puVar3 = r->d;
    uVar6 = n % 0x20;
    puVar7 = puVar10 + iVar8;
    if (uVar6 == 0) {
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar7;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    else {
      iVar1 = iVar2 + -1;
      uVar5 = puVar10[iVar8];
      if (iVar1 != 0) {
        puVar10 = puVar3;
        do {
          puVar7 = puVar7 + 1;
          uVar9 = uVar5 >> (uVar6 & 0xff);
          uVar5 = *puVar7;
          iVar1 = iVar1 + -1;
          *puVar10 = uVar5 << (0x20 - uVar6 & 0xff) | uVar9;
          puVar10 = puVar10 + 1;
        } while (iVar1 != 0);
        puVar3 = puVar3 + iVar2 + 0x3fffffff;
      }
      uVar5 = uVar5 >> (uVar6 & 0xff);
      if (uVar5 != 0) {
        *puVar3 = uVar5;
      }
    }
    return 1;
  }
  BN_set_word(r,0);
  return 1;
}

