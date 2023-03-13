
int ec_GFp_mont_group_set_curve
              (int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,BN_CTX *param_5)

{
  BN_MONT_CTX *mont;
  int iVar1;
  BIGNUM *r;
  BIGNUM *a;
  BN_CTX *c;
  
  if (*(BN_MONT_CTX **)(param_1 + 0xa0) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(BIGNUM **)(param_1 + 0xa4) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  if (param_5 == (BN_CTX *)0x0) {
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      return 0;
    }
    mont = BN_MONT_CTX_new();
    iVar1 = 0;
    param_5 = c;
    if (mont == (BN_MONT_CTX *)0x0) goto LAB_081e28e4;
  }
  else {
    mont = BN_MONT_CTX_new();
    c = (BN_CTX *)0x0;
    if (mont == (BN_MONT_CTX *)0x0) {
      return 0;
    }
  }
  iVar1 = BN_MONT_CTX_set(mont,param_2,param_5);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xbd,3,"ecp_mont.c",0xde);
  }
  else {
    r = BN_new();
    if (r != (BIGNUM *)0x0) {
      a = BN_value_one();
      iVar1 = BN_mod_mul_montgomery(r,a,&mont->RR,mont,param_5);
      if (iVar1 != 0) {
        *(BN_MONT_CTX **)(param_1 + 0xa0) = mont;
        *(BIGNUM **)(param_1 + 0xa4) = r;
        iVar1 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
        if (iVar1 == 0) {
          BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
          *(undefined4 *)(param_1 + 0xa0) = 0;
          BN_free(*(BIGNUM **)(param_1 + 0xa4));
          *(undefined4 *)(param_1 + 0xa4) = 0;
        }
        if (c == (BN_CTX *)0x0) {
          return iVar1;
        }
LAB_081e28e4:
        BN_CTX_free(c);
        return iVar1;
      }
    }
  }
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  BN_MONT_CTX_free(mont);
  return 0;
}

