
BIGNUM * BN_dup(BIGNUM *a)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  BIGNUM *ptr;
  int iVar4;
  uint uVar5;
  ulong *puVar6;
  ulong *puVar7;
  uint uVar8;
  int iVar9;
  ulong *local_2c;
  ulong *local_28;
  
  if (a == (BIGNUM *)0x0) {
    return (BIGNUM *)0x0;
  }
  ptr = (BIGNUM *)CRYPTO_malloc(0x14,"bn_lib.c",0x11b);
  if (ptr == (BIGNUM *)0x0) {
    ERR_put_error(3,0x71,0x41,"bn_lib.c",0x11d);
    return (BIGNUM *)0x0;
  }
  ptr->flags = 1;
  ptr->top = 0;
  ptr->neg = 0;
  ptr->dmax = 0;
  ptr->d = (ulong *)0x0;
  if (a == ptr) {
    return ptr;
  }
  uVar8 = a->top;
  if ((int)uVar8 < 1) {
    local_2c = (ulong *)0x0;
  }
  else {
    local_2c = (ulong *)bn_expand_internal();
    puVar6 = ptr->d;
    if (local_2c == (ulong *)0x0) {
      uVar8 = ptr->flags;
      if ((puVar6 != (ulong *)0x0) && ((uVar8 & 2) == 0)) {
        CRYPTO_free(puVar6);
        uVar8 = ptr->flags;
      }
      if ((uVar8 & 1) == 0) {
        ptr->d = (ulong *)0x0;
        ptr->flags = uVar8 | 0x8000;
        return (BIGNUM *)0x0;
      }
      CRYPTO_free(ptr);
      return (BIGNUM *)0x0;
    }
    if (puVar6 != (ulong *)0x0) {
      CRYPTO_free(puVar6);
    }
    ptr->dmax = uVar8;
    ptr->d = local_2c;
    uVar8 = a->top;
  }
  local_28 = a->d;
  iVar4 = (int)uVar8 >> 2;
  puVar6 = local_2c;
  puVar7 = local_28;
  iVar9 = iVar4;
  if (0 < iVar4) {
    do {
      uVar1 = puVar7[2];
      uVar2 = puVar7[3];
      uVar3 = *puVar7;
      puVar6[1] = puVar7[1];
      puVar6[2] = uVar1;
      *puVar6 = uVar3;
      puVar6[3] = uVar2;
      iVar9 = iVar9 + -1;
      puVar6 = puVar6 + 4;
      puVar7 = puVar7 + 4;
    } while (iVar9 != 0);
    local_2c = local_2c + iVar4 * 4;
    local_28 = local_28 + iVar4 * 4;
    uVar8 = a->top;
  }
  uVar5 = uVar8 & 3;
  if (uVar5 == 2) {
LAB_080f6a4d:
    local_2c[1] = local_28[1];
  }
  else {
    if (uVar5 == 3) {
      local_2c[2] = local_28[2];
      goto LAB_080f6a4d;
    }
    if (uVar5 != 1) goto LAB_080f6a1f;
  }
  *local_2c = *local_28;
  uVar8 = a->top;
LAB_080f6a1f:
  ptr->top = uVar8;
  ptr->neg = a->neg;
  return ptr;
}

