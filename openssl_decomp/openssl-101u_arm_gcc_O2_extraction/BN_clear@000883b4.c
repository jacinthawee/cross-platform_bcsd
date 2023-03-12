
void BN_clear(BIGNUM *a)

{
  if (a->d != (ulong *)0x0) {
    OPENSSL_cleanse(a->d,a->dmax << 2);
  }
  a->top = 0;
  a->neg = 0;
  return;
}

