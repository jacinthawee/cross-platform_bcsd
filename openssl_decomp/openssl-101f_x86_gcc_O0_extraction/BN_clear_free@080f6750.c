
void BN_clear_free(BIGNUM *a)

{
  uint uVar1;
  
  if (a != (BIGNUM *)0x0) {
    if (a->d == (ulong *)0x0) {
      uVar1 = a->flags;
    }
    else {
      OPENSSL_cleanse(a->d,a->dmax << 2);
      uVar1 = a->flags;
      if ((uVar1 & 2) == 0) {
        CRYPTO_free(a->d);
        uVar1 = a->flags;
      }
    }
    OPENSSL_cleanse(a,0x14);
    if ((uVar1 & 1) != 0) {
      CRYPTO_free(a);
      return;
    }
  }
  return;
}

