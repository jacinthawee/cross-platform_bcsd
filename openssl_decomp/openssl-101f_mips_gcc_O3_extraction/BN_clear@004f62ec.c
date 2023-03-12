
void BN_clear(BIGNUM *a)

{
  undefined4 in_a3;
  
  if (a->d != (ulong *)0x0) {
    (*(code *)PTR_memset_006aab00)(a->d,0,a->dmax << 2,in_a3,&_gp);
  }
  a->top = 0;
  a->neg = 0;
  return;
}

