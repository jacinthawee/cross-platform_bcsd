
int BN_rshift(BIGNUM *r,BIGNUM *a,int n)

{
  int iVar1;
  int iVar2;
  ulong *puVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  uint uVar6;
  ulong *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  if (n < 0) {
    ERR_put_error(3,0x92,0x77,"bn_shift.c",0xb7);
    return 0;
  }
  iVar9 = n >> 5;
  if ((iVar9 < a->top) && (a->top != 0)) {
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
    puVar5 = a->d;
    uVar8 = n & 0x1f;
    puVar3 = r->d;
    puVar7 = puVar5 + iVar9;
    iVar2 = a->top - iVar9;
    r->top = iVar1;
    if (uVar8 == 0) {
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar7;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    else {
      iVar1 = iVar2 + -1;
      uVar6 = puVar5[iVar9];
      if (iVar1 != 0) {
        puVar5 = puVar3;
        do {
          puVar7 = puVar7 + 1;
          uVar10 = uVar6 >> uVar8;
          uVar6 = *puVar7;
          iVar1 = iVar1 + -1;
          *puVar5 = uVar6 << (0x20 - uVar8 & 0xff) | uVar10;
          puVar5 = puVar5 + 1;
        } while (iVar1 != 0);
        puVar3 = puVar3 + iVar2 + 0x3fffffff;
      }
      if (uVar6 >> uVar8 != 0) {
        *puVar3 = uVar6 >> uVar8;
      }
    }
    return 1;
  }
  BN_set_word(r,0);
  return 1;
}

