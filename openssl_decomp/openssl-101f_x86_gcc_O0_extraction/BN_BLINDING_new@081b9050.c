
BN_BLINDING * BN_BLINDING_new(BIGNUM *A,BIGNUM *Ai,BIGNUM *mod)

{
  BIGNUM **ptr;
  BIGNUM *pBVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  ptr = (BIGNUM **)CRYPTO_malloc(0x2c,"bn_blind.c",0x8f);
  if (ptr == (BIGNUM **)0x0) {
    ERR_put_error(3,0x66,0x41,"bn_blind.c",0x91);
    return (BN_BLINDING *)0x0;
  }
  *ptr = (BIGNUM *)0x0;
  ptr[10] = (BIGNUM *)0x0;
  puVar3 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
  for (uVar2 = (uint)((int)ptr + (0x2c - (int)(undefined4 *)((uint)(ptr + 1) & 0xfffffffc))) >> 2;
      uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  if (A != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(A);
    *ptr = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_081b9122;
  }
  if (Ai == (BIGNUM *)0x0) {
LAB_081b90cb:
    pBVar1 = BN_dup(mod);
    ptr[3] = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) {
      if ((*(byte *)&mod->flags & 4) != 0) {
        pBVar1->flags = pBVar1->flags | 4;
      }
      ptr[7] = (BIGNUM *)0xffffffff;
      CRYPTO_THREADID_current((CRYPTO_THREADID *)(ptr + 5));
      return (BN_BLINDING *)ptr;
    }
  }
  else {
    pBVar1 = BN_dup(Ai);
    ptr[1] = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) goto LAB_081b90cb;
  }
  if (*ptr != (BIGNUM *)0x0) {
    BN_free(*ptr);
  }
LAB_081b9122:
  if (ptr[1] != (BIGNUM *)0x0) {
    BN_free(ptr[1]);
  }
  if (ptr[2] != (BIGNUM *)0x0) {
    BN_free(ptr[2]);
  }
  if (ptr[3] != (BIGNUM *)0x0) {
    BN_free(ptr[3]);
  }
  CRYPTO_free(ptr);
  return (BN_BLINDING *)0x0;
}

