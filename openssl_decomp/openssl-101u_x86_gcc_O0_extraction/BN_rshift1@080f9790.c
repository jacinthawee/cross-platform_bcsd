
int BN_rshift1(BIGNUM *r,BIGNUM *a)

{
  int iVar1;
  ulong *puVar2;
  uint uVar3;
  ulong *puVar4;
  uint uVar5;
  BIGNUM *pBVar6;
  int iVar7;
  int words;
  
  iVar7 = a->top;
  if (iVar7 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  puVar2 = a->d;
  iVar1 = iVar7 + 0x3fffffff;
  words = iVar7 - (uint)(puVar2[iVar1] == 1);
  if (a != r) {
    if ((r->dmax < words) && (pBVar6 = bn_expand2(r,words), pBVar6 == (BIGNUM *)0x0)) {
      return 0;
    }
    r->neg = a->neg;
  }
  uVar3 = puVar2[iVar1];
  iVar7 = iVar7 + -1;
  puVar4 = r->d;
  if (uVar3 >> 1 != 0) {
    puVar4[iVar1] = uVar3 >> 1;
  }
  if (0 < iVar7) {
    do {
      uVar5 = uVar3 & 1;
      iVar7 = iVar7 + -1;
      uVar3 = puVar2[iVar7];
      puVar4[iVar7] = -uVar5 & 0x80000000 | uVar3 >> 1;
    } while (iVar7 != 0);
  }
  r->top = words;
  return 1;
}

