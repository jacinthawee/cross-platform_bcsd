
BIGNUM * bn_expand2(BIGNUM *a,int words)

{
  ulong *puVar1;
  
  if (words <= a->dmax) {
    return a;
  }
  puVar1 = (ulong *)bn_expand_internal();
  if (puVar1 == (ulong *)0x0) {
    a = (BIGNUM *)0x0;
  }
  else {
    if (a->d != (ulong *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    a->d = puVar1;
    a->dmax = words;
  }
  return a;
}

