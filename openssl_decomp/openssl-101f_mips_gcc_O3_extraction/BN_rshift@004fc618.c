
int BN_rshift(BIGNUM *r,BIGNUM *a,int n)

{
  int iVar1;
  uint *puVar2;
  BIGNUM *pBVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  
  iVar10 = n + 0x1f;
  if (-1 < n) {
    iVar10 = n;
  }
  iVar10 = iVar10 >> 5;
  if ((a->top <= iVar10) || (a->top == 0)) {
    BN_set_word(r,0);
    return 1;
  }
  iVar1 = BN_num_bits(a);
  iVar5 = (iVar1 - n) + 0x1f;
  if (iVar5 < 0) {
    iVar5 = (iVar1 - n) + 0x3e;
  }
  iVar5 = iVar5 >> 5;
  if (a == r) {
    if (n == 0) {
      return 1;
    }
  }
  else {
    r->neg = a->neg;
    if ((r->dmax < iVar5) && (pBVar3 = bn_expand2(r,iVar5), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
  }
  uVar7 = n & 0x8000001f;
  if ((int)uVar7 < 0) {
    uVar7 = (uVar7 - 1 | 0xffffffe0) + 1;
  }
  iVar1 = a->top;
  puVar4 = r->d;
  puVar2 = a->d + iVar10;
  r->top = iVar5;
  iVar1 = iVar1 - iVar10;
  if (uVar7 == 0) {
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar2;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  else {
    iVar10 = iVar1 + -1;
    uVar6 = *puVar2;
    if (iVar10 != 0) {
      puVar8 = puVar4;
      do {
        puVar2 = puVar2 + 1;
        uVar9 = uVar6 >> (uVar7 & 0x1f);
        uVar6 = *puVar2;
        iVar10 = iVar10 + -1;
        *puVar8 = uVar6 << (0x20 - uVar7 & 0x1f) | uVar9;
        puVar8 = puVar8 + 1;
      } while (iVar10 != 0);
      puVar4 = puVar4 + iVar1 + -1;
    }
    uVar6 = uVar6 >> (uVar7 & 0x1f);
    if (uVar6 != 0) {
      *puVar4 = uVar6;
      return 1;
    }
  }
  return 1;
}

