
undefined4 BN_GF2m_mod_sqrt_arr(BIGNUM *param_1,undefined4 param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  int iVar1;
  undefined4 uVar2;
  
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
    return 1;
  }
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_set_bit(a,*param_3 + -1);
    if (iVar1 != 0) {
      uVar2 = BN_GF2m_mod_exp_arr(param_1,param_2,a,param_3,param_4);
      goto LAB_081e1ba3;
    }
  }
  uVar2 = 0;
LAB_081e1ba3:
  BN_CTX_end(param_4);
  return uVar2;
}

