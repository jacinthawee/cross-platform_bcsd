
BIGNUM * SRP_Calc_client_key(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                            BIGNUM *param_5,BIGNUM *param_6)

{
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar1;
  BIGNUM *local_24;
  BIGNUM *local_20;
  
  if ((((param_6 != (BIGNUM *)0x0) && (param_2 != (BIGNUM *)0x0)) && (param_1 != (BIGNUM *)0x0)) &&
     (((param_3 != (BIGNUM *)0x0 && (param_4 != (BIGNUM *)0x0)) && (param_5 != (BIGNUM *)0x0)))) {
    ctx = BN_CTX_new();
    if (ctx != (BN_CTX *)0x0) {
      r = BN_new();
      if ((r == (BIGNUM *)0x0) || (r_00 = BN_new(), r_00 == (BIGNUM *)0x0)) {
        local_20 = (BIGNUM *)0x0;
        local_24 = (BIGNUM *)0x0;
        r_01 = (BIGNUM *)0x0;
        r_00 = (BIGNUM *)0x0;
      }
      else {
        r_01 = BN_new();
        if (r_01 == (BIGNUM *)0x0) {
          local_20 = (BIGNUM *)0x0;
          local_24 = (BIGNUM *)0x0;
        }
        else {
          local_20 = BN_new();
          local_24 = (BIGNUM *)0x0;
          if (((((local_20 != (BIGNUM *)0x0) &&
                (iVar1 = BN_mod_exp(r,param_3,param_4,param_1,ctx), iVar1 != 0)) &&
               (local_24 = (BIGNUM *)srp_Calc_k(), local_24 != (BIGNUM *)0x0)) &&
              ((iVar1 = BN_mod_mul(r_00,r,local_24,param_1,ctx), iVar1 != 0 &&
               (iVar1 = BN_mod_sub(r,param_2,r_00,param_1,ctx), iVar1 != 0)))) &&
             ((iVar1 = BN_mod_mul(r_01,param_6,param_4,param_1,ctx), iVar1 != 0 &&
              (iVar1 = BN_mod_add(r_00,param_5,r_01,param_1,ctx), iVar1 != 0)))) {
            BN_mod_exp(local_20,r,r_00,param_1,ctx);
          }
        }
      }
      BN_CTX_free(ctx);
      BN_clear_free(r);
      BN_clear_free(r_00);
      BN_clear_free(r_01);
      BN_free(local_24);
      return local_20;
    }
    return (BIGNUM *)0x0;
  }
  return (BIGNUM *)0x0;
}

