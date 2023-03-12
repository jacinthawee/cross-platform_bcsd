
int BN_set_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  
  if (a->dmax < 1) {
    puVar1 = (ulong *)bn_expand_internal(a,1);
    if (puVar1 == (ulong *)0x0) {
      return 0;
    }
    if (a->d != (ulong *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    a->d = puVar1;
    a->dmax = 1;
  }
  a->neg = 0;
  *a->d = w;
  a->top = (uint)(w != 0);
  return 1;
}

