
BIGNUM * SRP_Calc_B(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4)

{
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar1;
  BIGNUM *local_20;
  
  if ((((param_1 == (BIGNUM *)0x0) || (param_2 == (BIGNUM *)0x0)) || (param_3 == (BIGNUM *)0x0)) ||
     ((param_4 == (BIGNUM *)0x0 || (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)))) {
    return (BIGNUM *)0x0;
  }
  r = BN_new();
  if ((r == (BIGNUM *)0x0) || (r_00 = BN_new(), r_00 == (BIGNUM *)0x0)) {
    local_20 = (BIGNUM *)0x0;
    r_01 = (BIGNUM *)0x0;
    r_00 = (BIGNUM *)0x0;
  }
  else {
    r_01 = BN_new();
    local_20 = (BIGNUM *)0x0;
    if (r_01 != (BIGNUM *)0x0) {
      iVar1 = BN_mod_exp(r_00,param_3,param_1,param_2,ctx);
      if ((iVar1 == 0) || (local_20 = (BIGNUM *)srp_Calc_k(), local_20 == (BIGNUM *)0x0)) {
        local_20 = (BIGNUM *)0x0;
      }
      else {
        iVar1 = BN_mod_mul(r,param_4,local_20,param_2,ctx);
        if ((iVar1 != 0) && (iVar1 = BN_mod_add(r_01,r_00,r,param_2,ctx), iVar1 != 0))
        goto LAB_08198f74;
      }
      BN_free(r_01);
      r_01 = (BIGNUM *)0x0;
    }
  }
LAB_08198f74:
  BN_CTX_free(ctx);
  BN_clear_free(r);
  BN_clear_free(r_00);
  BN_free(local_20);
  return r_01;
}

