
BIGNUM * BN_dup(BIGNUM *a)

{
  BIGNUM *pBVar1;
  ulong *puVar2;
  uint uVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong *puVar10;
  ulong *puVar11;
  uint uVar12;
  
  if (a == (BIGNUM *)0x0) {
    return (BIGNUM *)0x0;
  }
  pBVar1 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"bn_lib.c",0x110);
  if (pBVar1 == (BIGNUM *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x71,0x41,"bn_lib.c",0x111);
    return (BIGNUM *)0x0;
  }
  pBVar1->top = 0;
  pBVar1->neg = 0;
  pBVar1->dmax = 0;
  pBVar1->d = (ulong *)0x0;
  pBVar1->flags = 1;
  if (a == pBVar1) {
    return pBVar1;
  }
  uVar12 = a->top;
  puVar11 = (ulong *)0x0;
  if (0 < (int)uVar12) {
    puVar11 = (ulong *)bn_expand_internal(pBVar1,uVar12);
    if (puVar11 == (ulong *)0x0) {
      if (pBVar1->d != (ulong *)0x0) {
        uVar12 = pBVar1->flags;
        if ((uVar12 & 2) != 0) goto LAB_004f326c;
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      uVar12 = pBVar1->flags;
LAB_004f326c:
      if ((uVar12 & 1) == 0) {
        pBVar1->d = (ulong *)0x0;
        pBVar1->flags = uVar12 | 0x8000;
        return (BIGNUM *)0x0;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(pBVar1);
      return (BIGNUM *)0x0;
    }
    if (pBVar1->d != (ulong *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    pBVar1->dmax = uVar12;
    pBVar1->d = puVar11;
    uVar12 = a->top;
  }
  iVar5 = (int)uVar12 >> 2;
  puVar10 = a->d;
  puVar2 = puVar10;
  puVar4 = puVar11;
  iVar6 = iVar5;
  if (0 < iVar5) {
    do {
      uVar9 = puVar2[1];
      uVar8 = puVar2[2];
      iVar6 = iVar6 + -1;
      uVar7 = puVar2[3];
      *puVar4 = *puVar2;
      puVar4[1] = uVar9;
      puVar4[2] = uVar8;
      puVar4[3] = uVar7;
      puVar2 = puVar2 + 4;
      puVar4 = puVar4 + 4;
    } while (iVar6 != 0);
    uVar12 = a->top;
    puVar11 = puVar11 + iVar5 * 4;
    puVar10 = puVar10 + iVar5 * 4;
  }
  uVar3 = uVar12 & 3;
  if (uVar3 == 2) {
LAB_004f323c:
    puVar11[1] = puVar10[1];
  }
  else {
    if (uVar3 == 3) {
      puVar11[2] = puVar10[2];
      goto LAB_004f323c;
    }
    if (uVar3 != 1) goto LAB_004f3208;
  }
  *puVar11 = *puVar10;
  uVar12 = a->top;
LAB_004f3208:
  iVar6 = a->neg;
  pBVar1->top = uVar12;
  pBVar1->neg = iVar6;
  return pBVar1;
}

