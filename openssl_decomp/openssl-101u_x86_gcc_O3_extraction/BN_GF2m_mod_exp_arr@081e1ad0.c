
uint BN_GF2m_mod_exp_arr(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,int *param_4,
                        BN_CTX *param_5)

{
  ulong *puVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  BIGNUM *pBVar6;
  uint uVar7;
  
  if (param_3->top == 0) {
    uVar7 = BN_set_word(param_1,1);
    return uVar7;
  }
  if ((param_3->top == 1) && (*param_3->d == 1)) {
    pBVar3 = BN_copy(param_1,param_2);
    return (uint)(pBVar3 != (BIGNUM *)0x0);
  }
  BN_CTX_start(param_5);
  pBVar3 = BN_CTX_get(param_5);
  if (pBVar3 == (BIGNUM *)0x0) {
LAB_081e1b86:
    uVar7 = 0;
  }
  else {
    if (*param_4 == 0) {
      BN_set_word(pBVar3,0);
    }
    else {
      if (param_2 != pBVar3) {
        iVar5 = param_2->top;
        if (pBVar3->dmax < iVar5) {
          pBVar6 = bn_expand2(pBVar3,iVar5);
          if (pBVar6 == (BIGNUM *)0x0) goto LAB_081e1b86;
          iVar5 = param_2->top;
        }
        if (0 < iVar5) {
          puVar1 = pBVar3->d;
          iVar4 = 0;
          puVar2 = param_2->d;
          do {
            puVar1[iVar4] = puVar2[iVar4];
            iVar5 = param_2->top;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar5);
        }
        pBVar3->top = iVar5;
      }
      iVar5 = BN_GF2m_mod_arr_part_0();
      if (iVar5 == 0) goto LAB_081e1b86;
    }
    iVar5 = BN_num_bits(param_3);
    iVar5 = iVar5 + -2;
    if (-1 < iVar5) {
      do {
        iVar4 = BN_GF2m_mod_sqr_arr(pBVar3,pBVar3,param_4,param_5);
        if ((iVar4 == 0) ||
           ((iVar4 = BN_is_bit_set(param_3,iVar5), iVar4 != 0 &&
            (iVar4 = BN_GF2m_mod_mul_arr(pBVar3,pBVar3,param_2,param_4,param_5), iVar4 == 0))))
        goto LAB_081e1b86;
        iVar5 = iVar5 + -1;
      } while (iVar5 != -1);
    }
    pBVar3 = BN_copy(param_1,pBVar3);
    uVar7 = (uint)(pBVar3 != (BIGNUM *)0x0);
  }
  BN_CTX_end(param_5);
  return uVar7;
}

