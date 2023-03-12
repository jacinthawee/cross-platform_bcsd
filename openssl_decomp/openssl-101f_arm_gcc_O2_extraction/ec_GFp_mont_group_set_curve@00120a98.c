
BN_MONT_CTX *
ec_GFp_mont_group_set_curve
          (int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,BN_MONT_CTX *param_5)

{
  BN_MONT_CTX *mont;
  BN_MONT_CTX *pBVar1;
  BN_MONT_CTX *r;
  BIGNUM *a;
  BN_MONT_CTX *c;
  
  if (*(BN_MONT_CTX **)(param_1 + 0xa0) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(BIGNUM **)(param_1 + 0xa4) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  c = (BN_MONT_CTX *)0x0;
  if ((param_5 != (BN_MONT_CTX *)0x0) ||
     (pBVar1 = (BN_MONT_CTX *)BN_CTX_new(), param_5 = pBVar1, c = pBVar1,
     pBVar1 != (BN_MONT_CTX *)0x0)) {
    mont = BN_MONT_CTX_new();
    pBVar1 = mont;
    if (mont != (BN_MONT_CTX *)0x0) {
      pBVar1 = (BN_MONT_CTX *)BN_MONT_CTX_set(mont,param_2,(BN_CTX *)param_5);
      if (pBVar1 == (BN_MONT_CTX *)0x0) {
        ERR_put_error(0x10,0xbd,3,"ecp_mont.c",0xe9);
      }
      else {
        r = (BN_MONT_CTX *)BN_new();
        pBVar1 = r;
        if (r != (BN_MONT_CTX *)0x0) {
          a = BN_value_one();
          pBVar1 = (BN_MONT_CTX *)
                   BN_mod_mul_montgomery((BIGNUM *)r,a,&mont->RR,mont,(BN_CTX *)param_5);
          if (pBVar1 != (BN_MONT_CTX *)0x0) {
            *(BN_MONT_CTX **)(param_1 + 0xa0) = mont;
            *(BN_MONT_CTX **)(param_1 + 0xa4) = r;
            pBVar1 = (BN_MONT_CTX *)
                     ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
            mont = (BN_MONT_CTX *)0x0;
            if (pBVar1 == (BN_MONT_CTX *)0x0) {
              BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
              *(undefined4 *)(param_1 + 0xa0) = 0;
              BN_free(*(BIGNUM **)(param_1 + 0xa4));
              *(undefined4 *)(param_1 + 0xa4) = 0;
              mont = pBVar1;
            }
          }
        }
      }
    }
    if (c != (BN_MONT_CTX *)0x0) {
      BN_CTX_free((BN_CTX *)c);
    }
    if (mont != (BN_MONT_CTX *)0x0) {
      BN_MONT_CTX_free(mont);
      return pBVar1;
    }
  }
  return pBVar1;
}

