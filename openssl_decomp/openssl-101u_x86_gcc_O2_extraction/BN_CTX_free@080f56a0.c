
void BN_CTX_free(BN_CTX *c)

{
  BIGNUM *pBVar1;
  BIGNUM *a;
  
  if (c != (BN_CTX *)0x0) {
    if (*(int *)(c + 0x1c) != 0) {
      CRYPTO_free(*(void **)(c + 0x14));
    }
    a = *(BIGNUM **)c;
    while (a != (BIGNUM *)0x0) {
      pBVar1 = a + 0x10;
      do {
        if (a->d != (ulong *)0x0) {
          BN_clear_free(a);
        }
        a = a + 1;
      } while (a != pBVar1);
      *(undefined4 *)(c + 4) = *(undefined4 *)((int)*(void **)c + 0x144);
      CRYPTO_free(*(void **)c);
      a = *(BIGNUM **)(c + 4);
      *(BIGNUM **)c = a;
    }
    CRYPTO_free(c);
    return;
  }
  return;
}

