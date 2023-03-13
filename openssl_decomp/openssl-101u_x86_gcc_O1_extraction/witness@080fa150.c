
undefined4 __regparm3
witness(BIGNUM *param_1_00,BIGNUM *param_2_00,BIGNUM *param_3_00,BIGNUM *param_1,int param_2,
       BN_CTX *param_3,BN_MONT_CTX *param_4)

{
  int iVar1;
  
  iVar1 = BN_mod_exp_mont(param_1_00,param_1_00,param_1,param_2_00,param_3,param_4);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (((param_1_00->top == 1) && (*param_1_00->d == 1)) && (param_1_00->neg == 0)) {
    return 0;
  }
  do {
    iVar1 = BN_cmp(param_1_00,param_3_00);
    if (iVar1 == 0) {
      return 0;
    }
    param_2 = param_2 + -1;
    if (param_2 == 0) {
      return 1;
    }
    iVar1 = BN_mod_mul(param_1_00,param_1_00,param_1_00,param_2_00,param_3);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
  } while (((param_1_00->top != 1) || (*param_1_00->d != 1)) || (param_1_00->neg != 0));
  return 1;
}

