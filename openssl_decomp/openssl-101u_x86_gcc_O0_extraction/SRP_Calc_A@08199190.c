
BIGNUM * SRP_Calc_A(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  BN_CTX *ctx;
  BIGNUM *r;
  int iVar1;
  BIGNUM *pBVar2;
  
  if (((param_2 != (BIGNUM *)0x0 && param_3 != (BIGNUM *)0x0) && (param_1 != (BIGNUM *)0x0)) &&
     (ctx = BN_CTX_new(), ctx != (BN_CTX *)0x0)) {
    r = BN_new();
    pBVar2 = r;
    if ((r != (BIGNUM *)0x0) && (iVar1 = BN_mod_exp(r,param_3,param_1,param_2,ctx), iVar1 == 0)) {
      pBVar2 = (BIGNUM *)0x0;
      BN_free(r);
    }
    BN_CTX_free(ctx);
    return pBVar2;
  }
  return (BIGNUM *)0x0;
}

