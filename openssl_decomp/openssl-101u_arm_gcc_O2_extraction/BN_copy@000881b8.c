
BIGNUM * BN_copy(BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  
  if (a == b) {
    return a;
  }
  uVar6 = b->top;
  if (a->dmax < (int)uVar6) {
    puVar11 = (ulong *)bn_expand_internal(a,uVar6);
    if (puVar11 == (ulong *)0x0) {
      return (BIGNUM *)0x0;
    }
    if (a->d != (ulong *)0x0) {
      CRYPTO_free(a->d);
    }
    uVar5 = b->top;
    a->d = puVar11;
    a->dmax = uVar6;
  }
  else {
    puVar11 = a->d;
    uVar5 = uVar6;
  }
  iVar3 = (int)uVar5 >> 2;
  puVar1 = b->d;
  puVar2 = puVar1;
  puVar4 = puVar11;
  iVar7 = iVar3;
  if (0 < iVar3) {
    do {
      uVar10 = puVar2[1];
      iVar7 = iVar7 + -1;
      uVar9 = puVar2[2];
      uVar8 = puVar2[3];
      *puVar4 = *puVar2;
      puVar4[1] = uVar10;
      puVar4[2] = uVar9;
      puVar4[3] = uVar8;
      puVar2 = puVar2 + 4;
      puVar4 = puVar4 + 4;
    } while (iVar7 != 0);
    uVar5 = b->top;
    puVar11 = puVar11 + iVar3 * 4;
    puVar1 = puVar1 + iVar3 * 4;
  }
  uVar6 = uVar5 & 3;
  if (uVar6 == 2) {
LAB_0008823c:
    puVar11[1] = puVar1[1];
  }
  else {
    if (uVar6 == 3) {
      puVar11[2] = puVar1[2];
      goto LAB_0008823c;
    }
    if (uVar6 != 1) goto LAB_00088224;
  }
  *puVar11 = *puVar1;
  uVar5 = b->top;
LAB_00088224:
  iVar3 = b->neg;
  a->top = uVar5;
  a->neg = iVar3;
  return a;
}

