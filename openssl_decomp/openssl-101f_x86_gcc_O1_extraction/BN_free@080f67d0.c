
void BN_free(BIGNUM *a)

{
  uint uVar1;
  
  if (a != (BIGNUM *)0x0) {
    uVar1 = a->flags;
    if ((a->d != (ulong *)0x0) && ((uVar1 & 2) == 0)) {
      CRYPTO_free(a->d);
      uVar1 = a->flags;
    }
    if ((uVar1 & 1) != 0) {
      CRYPTO_free(a);
      return;
    }
    a->d = (ulong *)0x0;
    a->flags = uVar1 | 0x8000;
  }
  return;
}

