
BIGNUM * BN_dup(BIGNUM *a)

{
  BIGNUM *ptr;
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  ulong *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  bool bVar12;
  
  if (a == (BIGNUM *)0x0) {
    return (BIGNUM *)0x0;
  }
  ptr = (BIGNUM *)CRYPTO_malloc(0x14,"bn_lib.c",0x110);
  if (ptr == (BIGNUM *)0x0) {
    ERR_put_error(3,0x71,0x41,"bn_lib.c",0x111);
    return (BIGNUM *)0x0;
  }
  ptr->top = 0;
  ptr->flags = 1;
  ptr->neg = 0;
  ptr->dmax = 0;
  ptr->d = (ulong *)0x0;
  if (a == ptr) {
    return ptr;
  }
  uVar7 = a->top;
  if ((int)uVar7 < 1) {
    puVar11 = (ulong *)0x0;
  }
  else {
    puVar11 = (ulong *)bn_expand_internal(ptr,uVar7);
    puVar2 = ptr->d;
    if (puVar11 == (ulong *)0x0) {
      if (puVar2 != (ulong *)0x0) {
        uVar7 = ptr->flags;
        if ((int)(uVar7 << 0x1e) < 0) goto LAB_00088172;
        CRYPTO_free(puVar2);
      }
      uVar7 = ptr->flags;
LAB_00088172:
      bVar12 = (uVar7 & 1) == 0;
      if (bVar12) {
        ptr->d = (ulong *)0x0;
        uVar7 = uVar7 | 0x8000;
      }
      if (!bVar12) {
        CRYPTO_free(ptr);
        return (BIGNUM *)0x0;
      }
      ptr->flags = uVar7;
      return (BIGNUM *)0x0;
    }
    if (puVar2 != (ulong *)0x0) {
      CRYPTO_free(puVar2);
    }
    ptr->d = puVar11;
    ptr->dmax = uVar7;
    uVar7 = a->top;
  }
  iVar6 = (int)uVar7 >> 2;
  puVar1 = a->d;
  iVar3 = iVar6;
  puVar2 = puVar11;
  puVar4 = puVar1;
  if (0 < iVar6) {
    do {
      iVar3 = iVar3 + -1;
      uVar10 = puVar4[1];
      uVar9 = puVar4[2];
      uVar8 = puVar4[3];
      *puVar2 = *puVar4;
      puVar2[1] = uVar10;
      puVar2[2] = uVar9;
      puVar2[3] = uVar8;
      puVar2 = puVar2 + 4;
      puVar4 = puVar4 + 4;
    } while (iVar3 != 0);
    uVar7 = a->top;
    puVar11 = puVar11 + iVar6 * 4;
    puVar1 = puVar1 + iVar6 * 4;
  }
  uVar5 = uVar7 & 3;
  if (uVar5 == 2) {
LAB_00088132:
    puVar11[1] = puVar1[1];
  }
  else {
    if (uVar5 == 3) {
      puVar11[2] = puVar1[2];
      goto LAB_00088132;
    }
    if (uVar5 != 1) goto LAB_00088118;
  }
  *puVar11 = *puVar1;
  uVar7 = a->top;
LAB_00088118:
  iVar6 = a->neg;
  ptr->top = uVar7;
  ptr->neg = iVar6;
  return ptr;
}

