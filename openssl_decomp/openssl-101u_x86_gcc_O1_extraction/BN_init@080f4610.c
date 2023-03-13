
void BN_init(BIGNUM *param_1)

{
  param_1->d = (ulong *)0x0;
  param_1->top = 0;
  param_1->dmax = 0;
  param_1->neg = 0;
  param_1->flags = 0;
  return;
}

