
bool BN_GF2m_mod_solve_quad_arr(BIGNUM *param_1,BIGNUM *param_2,int *param_3,BN_CTX *param_4)

{
  ulong *puVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar4;
  int iVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  bool bVar10;
  int local_2c;
  int local_20;
  
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
    return true;
  }
  BN_CTX_start(param_4);
  pBVar3 = BN_CTX_get(param_4);
  a = BN_CTX_get(param_4);
  a_00 = BN_CTX_get(param_4);
  if (a_00 != (BIGNUM *)0x0) {
    if (*param_3 == 0) {
      BN_set_word(pBVar3,0);
    }
    else {
      if (param_2 != pBVar3) {
        iVar5 = param_2->top;
        if (pBVar3->dmax < iVar5) {
          pBVar6 = bn_expand2(pBVar3,iVar5);
          if (pBVar6 == (BIGNUM *)0x0) goto LAB_081e2156;
          iVar5 = param_2->top;
        }
        if (0 < iVar5) {
          puVar1 = pBVar3->d;
          puVar2 = param_2->d;
          iVar4 = 0;
          do {
            puVar1[iVar4] = puVar2[iVar4];
            iVar5 = param_2->top;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar5);
        }
        pBVar3->top = iVar5;
      }
      iVar5 = BN_GF2m_mod_arr_part_0();
      if (iVar5 == 0) goto LAB_081e2156;
    }
    if (pBVar3->top == 0) {
      bVar10 = true;
      BN_set_word(param_1,0);
      goto LAB_081e2158;
    }
    if ((*(byte *)param_3 & 1) == 0) {
      pBVar6 = BN_CTX_get(param_4);
      pBVar7 = BN_CTX_get(param_4);
      pBVar8 = BN_CTX_get(param_4);
      if (pBVar8 != (BIGNUM *)0x0) {
        iVar5 = *param_3;
        local_20 = 0x32;
        do {
          iVar5 = BN_rand(pBVar6,iVar5,0,0);
          if (iVar5 == 0) goto LAB_081e2156;
          if (*param_3 == 0) {
            BN_set_word(pBVar6,0);
          }
          else {
            iVar5 = BN_GF2m_mod_arr_part_0();
            if (iVar5 == 0) goto LAB_081e2156;
          }
          BN_set_word(a,0);
          pBVar9 = BN_copy(a_00,pBVar6);
          if (pBVar9 == (BIGNUM *)0x0) goto LAB_081e2156;
          iVar5 = *param_3;
          if (1 < iVar5) {
            local_2c = 1;
            do {
              iVar5 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4);
              if ((((iVar5 == 0) ||
                   (iVar5 = BN_GF2m_mod_sqr_arr(pBVar7,a_00,param_3,param_4), iVar5 == 0)) ||
                  (iVar5 = BN_GF2m_mod_mul_arr(pBVar8,pBVar7,pBVar3,param_3,param_4), iVar5 == 0))
                 || ((iVar5 = BN_GF2m_add(a,a,pBVar8), iVar5 == 0 ||
                     (iVar5 = BN_GF2m_add(a_00,pBVar7,pBVar6), iVar5 == 0)))) goto LAB_081e2156;
              local_2c = local_2c + 1;
              iVar5 = *param_3;
            } while (local_2c < iVar5);
          }
          if (a_00->top != 0) goto LAB_081e23c6;
          local_20 = local_20 + -1;
        } while (local_20 != 0);
        iVar4 = 0x4a6;
        iVar5 = 0x71;
LAB_081e241d:
        ERR_put_error(3,0x87,iVar5,"bn_gf2m.c",iVar4);
      }
    }
    else {
      pBVar6 = BN_copy(a,pBVar3);
      if (pBVar6 != (BIGNUM *)0x0) {
        if (2 < *param_3) {
          iVar5 = 1;
          do {
            iVar4 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4);
            if (((iVar4 == 0) || (iVar4 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4), iVar4 == 0)) ||
               (iVar4 = BN_GF2m_add(a,a,pBVar3), iVar4 == 0)) goto LAB_081e2156;
            iVar5 = iVar5 + 1;
          } while (iVar5 <= (*param_3 + -1) / 2);
        }
LAB_081e23c6:
        iVar5 = BN_GF2m_mod_sqr_arr(a_00,a,param_3,param_4);
        if ((iVar5 != 0) && (iVar5 = BN_GF2m_add(a_00,a,a_00), iVar5 != 0)) {
          iVar5 = BN_ucmp(a_00,pBVar3);
          if (iVar5 == 0) {
            pBVar3 = BN_copy(param_1,a);
            bVar10 = pBVar3 != (BIGNUM *)0x0;
            goto LAB_081e2158;
          }
          iVar4 = 0x4b0;
          iVar5 = 0x74;
          goto LAB_081e241d;
        }
      }
    }
  }
LAB_081e2156:
  bVar10 = false;
LAB_081e2158:
  BN_CTX_end(param_4);
  return bVar10;
}

