
BIGNUM * BN_GF2m_mod_solve_quad_arr(BIGNUM *param_1,undefined4 param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *b;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *local_2c;
  
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
    return (BIGNUM *)0x1;
  }
  BN_CTX_start(param_4);
  b = BN_CTX_get(param_4);
  a = BN_CTX_get(param_4);
  a_00 = BN_CTX_get(param_4);
  if ((a_00 != (BIGNUM *)0x0) && (iVar1 = BN_GF2m_mod_arr(b,param_2,param_3), iVar1 != 0)) {
    if (b->top == 0) {
      local_2c = (BIGNUM *)0x1;
      BN_set_word(param_1,0);
      goto LAB_00120746;
    }
    if (*param_3 << 0x1f < 0) {
      pBVar2 = BN_copy(a,b);
      if (pBVar2 != (BIGNUM *)0x0) {
        if (2 < *param_3) {
          iVar1 = 1;
          do {
            iVar3 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4);
            iVar1 = iVar1 + 1;
            if (((iVar3 == 0) || (iVar3 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4), iVar3 == 0)) ||
               (iVar3 = BN_GF2m_add(a,a,b), iVar3 == 0)) goto LAB_00120744;
          } while (iVar1 <= (*param_3 + -1) / 2);
        }
LAB_00120822:
        iVar1 = BN_GF2m_mod_sqr_arr(a_00,a,param_3,param_4);
        if ((iVar1 != 0) && (iVar1 = BN_GF2m_add(a_00,a,a_00), iVar1 != 0)) {
          iVar1 = BN_ucmp(a_00,b);
          if (iVar1 == 0) {
            local_2c = BN_copy(param_1,a);
            if (local_2c != (BIGNUM *)0x0) {
              local_2c = (BIGNUM *)0x1;
            }
          }
          else {
            local_2c = (BIGNUM *)0x0;
            ERR_put_error(3,0x87,0x74,"bn_gf2m.c",0x3f5);
          }
          goto LAB_00120746;
        }
      }
    }
    else {
      pBVar2 = BN_CTX_get(param_4);
      pBVar4 = BN_CTX_get(param_4);
      pBVar5 = BN_CTX_get(param_4);
      if (pBVar5 != (BIGNUM *)0x0) {
        iVar1 = *param_3;
        local_2c = (BIGNUM *)0x32;
        do {
          iVar1 = BN_rand(pBVar2,iVar1,0,0);
          if ((iVar1 == 0) || (iVar1 = BN_GF2m_mod_arr(pBVar2,pBVar2,param_3), iVar1 == 0))
          goto LAB_00120744;
          BN_set_word(a,0);
          pBVar6 = BN_copy(a_00,pBVar2);
          if (pBVar6 == (BIGNUM *)0x0) goto LAB_00120744;
          iVar1 = *param_3;
          if (1 < iVar1) {
            iVar3 = 1;
            do {
              iVar1 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4);
              iVar3 = iVar3 + 1;
              if ((((iVar1 == 0) ||
                   (iVar1 = BN_GF2m_mod_sqr_arr(pBVar4,a_00,param_3,param_4), iVar1 == 0)) ||
                  (iVar1 = BN_GF2m_mod_mul_arr(pBVar5,pBVar4,b,param_3,param_4), iVar1 == 0)) ||
                 ((iVar1 = BN_GF2m_add(a,a,pBVar5), iVar1 == 0 ||
                  (iVar1 = BN_GF2m_add(a_00,pBVar4,pBVar2), iVar1 == 0)))) goto LAB_00120744;
              iVar1 = *param_3;
            } while (iVar3 < iVar1);
          }
          if (a_00->top != 0) goto LAB_00120822;
          local_2c = (BIGNUM *)((int)&local_2c[-1].flags + 3);
        } while (local_2c != (BIGNUM *)0x0);
        ERR_put_error(3,0x87,0x71,"bn_gf2m.c",0x3ec);
        goto LAB_00120746;
      }
    }
  }
LAB_00120744:
  local_2c = (BIGNUM *)0x0;
LAB_00120746:
  BN_CTX_end(param_4);
  return local_2c;
}

