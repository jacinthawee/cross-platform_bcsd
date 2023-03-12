
int BN_rshift1(BIGNUM *r,BIGNUM *a)

{
  int iVar1;
  int iVar2;
  BIGNUM *pBVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ulong *puVar9;
  int words;
  int iVar10;
  
  iVar7 = a->top;
  if (iVar7 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  puVar9 = a->d;
  iVar10 = iVar7 + 0x3fffffff;
  words = iVar7;
  if (puVar9[iVar10] == 1) {
    words = iVar7 + -1;
  }
  if (a != r) {
    if ((r->dmax < words) && (pBVar3 = bn_expand2(r,words), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
    r->neg = a->neg;
  }
  puVar4 = r->d;
  if ((puVar9[iVar10] & 1) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0x80000000;
  }
  uVar5 = puVar9[iVar10] >> 1;
  if (uVar5 != 0) {
    puVar4[iVar10] = uVar5;
  }
  if (1 < iVar7) {
    iVar8 = iVar10 * 4 + 4;
    iVar10 = 0;
    do {
      iVar1 = iVar10 + iVar8;
      iVar2 = iVar10 + iVar8;
      iVar10 = iVar10 + -4;
      uVar5 = *(uint *)((int)puVar9 + iVar1 + -8);
      *(uint *)((int)puVar4 + iVar2 + -8) = uVar6 | uVar5 >> 1;
      if ((uVar5 & 1) == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = 0x80000000;
      }
    } while (iVar10 != iVar7 * -4 + 4);
  }
  r->top = words;
  return 1;
}

