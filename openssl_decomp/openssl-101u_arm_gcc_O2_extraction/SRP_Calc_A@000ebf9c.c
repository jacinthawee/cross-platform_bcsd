
BIGNUM * SRP_Calc_A(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *pBVar1;
  
  if (((param_2 != (BIGNUM *)0x0 && param_1 != (BIGNUM *)0x0) && (param_3 != (BIGNUM *)0x0)) &&
     (ctx = BN_CTX_new(), ctx != (BN_CTX *)0x0)) {
    r = BN_new();
    if ((r != (BIGNUM *)0x0) &&
       (pBVar1 = (BIGNUM *)BN_mod_exp(r,param_3,param_1,param_2,ctx), pBVar1 == (BIGNUM *)0x0)) {
      BN_free(r);
      r = pBVar1;
    }
    BN_CTX_free(ctx);
    return r;
  }
  return (BIGNUM *)0x0;
}

