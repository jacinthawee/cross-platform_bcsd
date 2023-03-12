
BIGNUM * BN_GF2m_mod_exp_arr(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,undefined4 param_4,
                            BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3->top == 0) {
    pBVar1 = (BIGNUM *)BN_set_word(param_1,1);
    return pBVar1;
  }
  if ((param_3->top == 1) && (*param_3->d == 1)) {
    pBVar1 = BN_copy(param_1,param_2);
    if (pBVar1 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)0x1;
    }
  }
  else {
    BN_CTX_start(param_5);
    pBVar1 = BN_CTX_get(param_5);
    if ((pBVar1 == (BIGNUM *)0x0) || (iVar2 = BN_GF2m_mod_arr(pBVar1,param_2,param_4), iVar2 == 0))
    {
LAB_001203be:
      pBVar1 = (BIGNUM *)0x0;
    }
    else {
      iVar3 = BN_num_bits(param_3);
      iVar2 = iVar3 + -2;
      if (-1 < iVar3 + -2) {
        do {
          iVar3 = BN_GF2m_mod_sqr_arr(pBVar1,pBVar1,param_4,param_5);
          iVar4 = iVar2 + -1;
          if ((iVar3 == 0) ||
             ((iVar2 = BN_is_bit_set(param_3,iVar2), iVar2 != 0 &&
              (iVar2 = BN_GF2m_mod_mul_arr(pBVar1,pBVar1,param_2,param_4,param_5), iVar2 == 0))))
          goto LAB_001203be;
          iVar2 = iVar4;
        } while (iVar4 != -1);
      }
      pBVar1 = BN_copy(param_1,pBVar1);
      if (pBVar1 != (BIGNUM *)0x0) {
        pBVar1 = (BIGNUM *)0x1;
      }
    }
    BN_CTX_end(param_5);
  }
  return pBVar1;
}

