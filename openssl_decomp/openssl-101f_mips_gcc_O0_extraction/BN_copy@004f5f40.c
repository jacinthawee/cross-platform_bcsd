
BIGNUM * BN_copy(BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  
  if (a == b) {
    return a;
  }
  uVar11 = b->top;
  if (a->dmax < (int)uVar11) {
    puVar1 = (ulong *)bn_expand_internal(a,uVar11);
    if (puVar1 == (ulong *)0x0) {
      return (BIGNUM *)0x0;
    }
    if (a->d != (ulong *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    a->dmax = uVar11;
    a->d = puVar1;
    uVar11 = b->top;
  }
  else {
    puVar1 = a->d;
  }
  iVar2 = (int)uVar11 >> 2;
  puVar5 = b->d;
  puVar4 = puVar1;
  puVar6 = puVar5;
  iVar7 = iVar2;
  if (0 < iVar2) {
    do {
      uVar10 = puVar6[1];
      uVar9 = puVar6[2];
      iVar7 = iVar7 + -1;
      uVar8 = puVar6[3];
      *puVar4 = *puVar6;
      puVar4[1] = uVar10;
      puVar4[2] = uVar9;
      puVar4[3] = uVar8;
      puVar4 = puVar4 + 4;
      puVar6 = puVar6 + 4;
    } while (iVar7 != 0);
    uVar11 = b->top;
    puVar1 = puVar1 + iVar2 * 4;
    puVar5 = puVar5 + iVar2 * 4;
  }
  uVar3 = uVar11 & 3;
  if (uVar3 == 2) {
LAB_004f606c:
    puVar1[1] = puVar5[1];
  }
  else {
    if (uVar3 == 3) {
      puVar1[2] = puVar5[2];
      goto LAB_004f606c;
    }
    if (uVar3 != 1) goto LAB_004f6038;
  }
  *puVar1 = *puVar5;
  uVar11 = b->top;
LAB_004f6038:
  iVar7 = b->neg;
  a->top = uVar11;
  a->neg = iVar7;
  return a;
}

