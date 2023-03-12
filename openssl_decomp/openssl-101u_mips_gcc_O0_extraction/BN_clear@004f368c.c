
void BN_clear(BIGNUM *a)

{
  undefined4 in_a2;
  undefined4 in_a3;
  
  if (a->d != (ulong *)0x0) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(a->d,a->dmax << 2,in_a2,in_a3,&_gp);
  }
  a->top = 0;
  a->neg = 0;
  return;
}

