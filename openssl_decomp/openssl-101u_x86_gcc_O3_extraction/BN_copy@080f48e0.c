
BIGNUM * BN_copy(BIGNUM *a,BIGNUM *b)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  int iVar7;
  ulong *puVar8;
  uint uVar9;
  ulong *puVar10;
  ulong *local_28;
  
  if (a == b) {
    return a;
  }
  uVar9 = b->top;
  if (a->dmax < (int)uVar9) {
    local_28 = (ulong *)bn_expand_internal();
    if (local_28 == (ulong *)0x0) {
      return (BIGNUM *)0x0;
    }
    if (a->d != (ulong *)0x0) {
      CRYPTO_free(a->d);
    }
    a->dmax = uVar9;
    a->d = local_28;
    uVar9 = b->top;
  }
  else {
    local_28 = a->d;
  }
  puVar10 = b->d;
  iVar4 = (int)uVar9 >> 2;
  puVar5 = local_28;
  iVar7 = iVar4;
  puVar8 = puVar10;
  if (0 < iVar4) {
    do {
      uVar1 = puVar8[2];
      uVar2 = puVar8[3];
      uVar3 = *puVar8;
      puVar5[1] = puVar8[1];
      puVar5[2] = uVar1;
      *puVar5 = uVar3;
      puVar5[3] = uVar2;
      iVar7 = iVar7 + -1;
      puVar5 = puVar5 + 4;
      puVar8 = puVar8 + 4;
    } while (iVar7 != 0);
    local_28 = local_28 + iVar4 * 4;
    puVar10 = puVar10 + iVar4 * 4;
    uVar9 = b->top;
  }
  uVar6 = uVar9 & 3;
  if (uVar6 == 2) {
LAB_080f49ea:
    local_28[1] = puVar10[1];
  }
  else {
    if (uVar6 == 3) {
      local_28[2] = puVar10[2];
      goto LAB_080f49ea;
    }
    if (uVar6 != 1) goto LAB_080f49ba;
  }
  *local_28 = *puVar10;
  uVar9 = b->top;
LAB_080f49ba:
  a->top = uVar9;
  a->neg = b->neg;
  return a;
}

