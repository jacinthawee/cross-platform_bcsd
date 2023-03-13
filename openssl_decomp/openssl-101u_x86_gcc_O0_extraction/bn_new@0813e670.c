
bool bn_new(BIGNUM **param_1)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_new();
  *param_1 = pBVar1;
  return pBVar1 != (BIGNUM *)0x0;
}

