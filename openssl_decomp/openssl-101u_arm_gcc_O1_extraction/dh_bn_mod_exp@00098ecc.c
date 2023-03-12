
int dh_bn_mod_exp(int param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,
                 BN_CTX *param_6,BN_MONT_CTX *param_7)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *r;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  BIGNUM **ppBVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  BN_MONT_CTX *pBStack_c0;
  int iStack_bc;
  int iStack_b8;
  uint uStack_b4;
  BIGNUM *apBStack_a8 [37];
  
  pBStack_c0 = param_7;
  if ((param_3->top == 1) && (*(int *)(param_1 + 0x1c) << 0x1e < 0)) {
    iVar1 = BN_mod_exp_mont_word(param_2,*param_3->d,param_4,param_5,param_6,param_7);
    return iVar1;
  }
  if ((param_4->flags & 4U) != 0) {
    iVar1 = BN_mod_exp_mont_consttime(param_2,param_3,param_4,param_5,param_6,param_7);
    return iVar1;
  }
  if ((param_5->top < 1) || (-1 < (int)(*param_5->d << 0x1f))) {
    ERR_put_error(3,0x6d,0x66,"bn_exp.c",0x19b);
    return 0;
  }
  iStack_bc = BN_num_bits(param_4);
  if (iStack_bc == 0) {
    if (((param_5->top == 1) && (*param_5->d == 1)) && (param_5->neg == 0)) {
      BN_set_word(param_2,0);
      return 1;
    }
    iVar1 = BN_set_word(param_2,1);
    return iVar1;
  }
  BN_CTX_start(param_6);
  pBVar2 = BN_CTX_get(param_6);
  r = BN_CTX_get(param_6);
  pBVar3 = BN_CTX_get(param_6);
  apBStack_a8[0] = pBVar3;
  if ((r == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0) || (pBVar3 == (BIGNUM *)0x0)) {
LAB_00087008:
    iVar1 = 0;
    goto LAB_0008700a;
  }
  if (param_7 == (BN_MONT_CTX *)0x0) {
    pBStack_c0 = BN_MONT_CTX_new();
    if (pBStack_c0 == (BN_MONT_CTX *)0x0) goto LAB_00087008;
    iVar1 = BN_MONT_CTX_set(pBStack_c0,param_5,param_6);
    if (iVar1 != 0) goto LAB_00086fb6;
  }
  else {
LAB_00086fb6:
    if (((param_3->neg == 0) && (iVar1 = BN_ucmp(param_3,param_5), iVar1 < 0)) ||
       (iVar1 = BN_nnmod(pBVar3,param_3,param_5,param_6), param_3 = pBVar3, iVar1 != 0)) {
      if (param_3->top == 0) {
        iVar1 = 1;
        BN_set_word(param_2,0);
      }
      else {
        iVar1 = BN_mod_mul_montgomery(pBVar3,param_3,&pBStack_c0->RR,pBStack_c0,param_6);
        if (iVar1 == 0) goto LAB_00087068;
        if (iStack_bc < 0x2a0) {
          if (0xef < iStack_bc) {
            iStack_b8 = 0x10;
            uStack_b4 = 5;
            goto LAB_0008701a;
          }
          if (0x4f < iStack_bc) {
            iStack_b8 = 8;
            uStack_b4 = 4;
            goto LAB_0008701a;
          }
          if (0x17 < iStack_bc) {
            iStack_b8 = 4;
            uStack_b4 = 3;
            goto LAB_0008701a;
          }
          uStack_b4 = 1;
        }
        else {
          iStack_b8 = 0x20;
          uStack_b4 = 6;
LAB_0008701a:
          iVar1 = BN_mod_mul_montgomery(pBVar2,pBVar3,pBVar3,pBStack_c0,param_6);
          if (iVar1 == 0) goto LAB_00087068;
          iVar1 = 1;
          ppBVar6 = apBStack_a8;
          do {
            iVar1 = iVar1 + 1;
            pBVar3 = BN_CTX_get(param_6);
            ppBVar6[1] = pBVar3;
            if ((pBVar3 == (BIGNUM *)0x0) ||
               (iVar4 = BN_mod_mul_montgomery(pBVar3,*ppBVar6,pBVar2,pBStack_c0,param_6), iVar4 == 0
               )) goto LAB_00087068;
            ppBVar6 = ppBVar6 + 1;
          } while (iVar1 < iStack_b8);
        }
        pBVar2 = BN_value_one();
        iVar1 = BN_mod_mul_montgomery(r,pBVar2,&pBStack_c0->RR,pBStack_c0,param_6);
        if (iVar1 == 0) goto LAB_00087068;
        iStack_bc = iStack_bc + -1;
        iStack_b8 = 1;
        while( true ) {
          while (iVar1 = BN_is_bit_set(param_4,iStack_bc), iVar1 == 0) {
            if ((iStack_b8 == 0) &&
               (iVar1 = BN_mod_mul_montgomery(r,r,r,pBStack_c0,param_6), iVar1 == 0))
            goto LAB_00087068;
            if (iStack_bc == 0) goto LAB_000871ce;
            iStack_bc = iStack_bc + -1;
          }
          if (uStack_b4 == 1) {
            uVar5 = 0;
            uVar9 = uStack_b4;
          }
          else {
            uVar9 = 1;
            if (iStack_bc + -1 < 0) {
              uVar5 = 0;
            }
            else {
              uVar8 = 1;
              uVar5 = 0;
              iVar1 = iStack_bc + -1;
              iVar4 = iStack_bc + -2;
              do {
                iVar1 = BN_is_bit_set(param_4,iVar1);
                if (iVar1 != 0) {
                  uVar9 = uVar9 << (uVar8 - uVar5 & 0xff) | 1;
                  uVar5 = uVar8;
                }
                uVar8 = uVar8 + 1;
                iVar7 = iVar4 + -1;
              } while ((iVar4 != iStack_bc - uStack_b4) &&
                      (iVar1 = iVar4, iVar4 = iVar7, iVar7 != -2));
            }
          }
          if (iStack_b8 == 0) {
            do {
              iStack_b8 = iStack_b8 + 1;
              iVar1 = BN_mod_mul_montgomery(r,r,r,pBStack_c0,param_6);
              if (iVar1 == 0) goto LAB_00087068;
            } while (iStack_b8 <= (int)uVar5);
          }
          iVar1 = BN_mod_mul_montgomery(r,r,apBStack_a8[(int)uVar9 >> 1],pBStack_c0,param_6);
          if (iVar1 == 0) goto LAB_00087068;
          iStack_bc = iStack_bc + ~uVar5;
          if (iStack_bc < 0) break;
          iStack_b8 = 0;
        }
LAB_000871ce:
        iVar1 = BN_from_montgomery(param_2,r,pBStack_c0,param_6);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
      }
    }
    else {
LAB_00087068:
      iVar1 = 0;
    }
    if (param_7 != (BN_MONT_CTX *)0x0) goto LAB_0008700a;
  }
  BN_MONT_CTX_free(pBStack_c0);
LAB_0008700a:
  BN_CTX_end(param_6);
  return iVar1;
}

