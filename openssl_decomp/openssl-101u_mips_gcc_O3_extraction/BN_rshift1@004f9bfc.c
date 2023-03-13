
int BN_rshift1(BIGNUM *r,BIGNUM *a)

{
  uint *puVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  ulong *puVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  int words;
  int iVar9;
  
  iVar9 = a->top;
  if (iVar9 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  puVar8 = a->d;
  words = iVar9 - (uint)(puVar8[iVar9 + -1] == 1);
  if (a != r) {
    if ((r->dmax < words) && (pBVar3 = bn_expand2(r,words), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
    r->neg = a->neg;
  }
  uVar7 = puVar8[iVar9 + -1];
  uVar6 = 0x80000000;
  puVar2 = r->d;
  uVar4 = uVar7 >> 1;
  if ((uVar7 & 1) == 0) {
    uVar6 = 0;
  }
  if (uVar4 != 0) {
    puVar2[iVar9 + -1] = uVar4;
  }
  if (1 < iVar9) {
    puVar5 = puVar8 + iVar9;
    puVar2 = puVar2 + iVar9;
    do {
      puVar1 = puVar5 + -2;
      puVar5 = puVar5 + -1;
      uVar4 = *puVar1 >> 1 | uVar6;
      uVar6 = 0x80000000;
      if ((*puVar1 & 1) == 0) {
        uVar6 = 0;
      }
      puVar2[-2] = uVar4;
      puVar2 = puVar2 + -1;
    } while (puVar8 + 1 != puVar5);
  }
  r->top = words;
  return 1;
}

