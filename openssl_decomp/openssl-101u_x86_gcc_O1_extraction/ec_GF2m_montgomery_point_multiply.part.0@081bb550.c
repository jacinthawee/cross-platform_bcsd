
undefined4 __regparm3
ec_GF2m_montgomery_point_multiply_part_0
          (int *param_1_00,EC_POINT *param_2_00,int *param_3,int param_1,BN_CTX *param_2)

{
  BIGNUM *a;
  BIGNUM *a_00;
  uint uVar1;
  BIGNUM *pBVar2;
  BIGNUM *a_01;
  BIGNUM *b;
  int iVar3;
  uint uVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint local_38;
  int local_2c;
  int local_24;
  
  BN_CTX_start(param_2);
  pBVar2 = BN_CTX_get(param_2);
  a_01 = BN_CTX_get(param_2);
  if (a_01 != (BIGNUM *)0x0) {
    a = (BIGNUM *)(param_2_00 + 4);
    iVar3 = param_1_00[0x13];
    a_00 = (BIGNUM *)(param_2_00 + 0x18);
    if (pBVar2->dmax < iVar3) {
      bn_expand2(pBVar2,iVar3);
      iVar3 = param_1_00[0x13];
    }
    if (a_01->dmax < iVar3) {
      bn_expand2(a_01,iVar3);
      iVar3 = param_1_00[0x13];
    }
    if (*(int *)(param_2_00 + 0xc) < iVar3) {
      bn_expand2(a,iVar3);
      iVar3 = param_1_00[0x13];
    }
    if (*(int *)(param_2_00 + 0x20) < iVar3) {
      bn_expand2(a_00,iVar3);
    }
    b = (BIGNUM *)(param_1 + 4);
    iVar3 = BN_GF2m_mod_arr(pBVar2,b,param_1_00 + 0x17);
    if ((((iVar3 != 0) && (iVar3 = BN_set_word(a_01,1), iVar3 != 0)) &&
        (iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,a_00,pBVar2,param_2), iVar3 != 0)) &&
       (iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,a,a_00,param_2), iVar3 != 0)) {
      iVar3 = BN_GF2m_add(param_2_00 + 4,param_2_00 + 4,param_1_00 + 0x22);
      if (iVar3 != 0) {
        local_2c = param_3[1] + -1;
        iVar3 = *param_3;
        uVar1 = *(uint *)(iVar3 + local_2c * 4);
        if ((int)uVar1 < 0) {
          local_38 = 0x40000000;
        }
        else {
          uVar4 = 0x80000000;
          do {
            local_38 = uVar4;
            uVar4 = local_38 >> 1;
          } while ((uVar1 & uVar4) == 0);
          local_38 = local_38 >> 2;
          if (local_38 == 0) {
            local_38 = 0x80000000;
            local_2c = param_3[1] + -2;
          }
        }
        if (-1 < local_2c) {
          local_24 = local_2c << 2;
          while( true ) {
            uVar1 = *(uint *)(iVar3 + local_24);
            do {
              uVar4 = uVar1 & local_38;
              BN_consttime_swap(uVar4,pBVar2,a,param_1_00[0x13]);
              BN_consttime_swap(uVar4,a_01,a_00,param_1_00[0x13]);
              BN_CTX_start(param_2);
              pBVar5 = BN_CTX_get(param_2);
              pBVar6 = BN_CTX_get(param_2);
              if (((((pBVar6 == (BIGNUM *)0x0) ||
                    (pBVar7 = BN_copy(pBVar5,b), pBVar7 == (BIGNUM *)0x0)) ||
                   ((iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a,a,a_01,param_2),
                    iVar3 == 0 ||
                    ((iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_00,a_00,pBVar2,param_2)
                     , iVar3 == 0 ||
                     (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,pBVar6,a,a_00,param_2),
                     iVar3 == 0)))))) || (iVar3 = BN_GF2m_add(a_00,a_00,a), iVar3 == 0)) ||
                 (((iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,a_00,a_00,param_2),
                   iVar3 == 0 ||
                   (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a,a_00,pBVar5,param_2),
                   iVar3 == 0)) || (iVar3 = BN_GF2m_add(a,a,pBVar6,iVar3), iVar3 == 0))))
              goto LAB_081bb768;
              BN_CTX_end(param_2);
              BN_CTX_start(param_2);
              pBVar5 = BN_CTX_get(param_2);
              if ((((pBVar5 == (BIGNUM *)0x0) ||
                   (iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar2,pBVar2,param_2),
                   iVar3 == 0)) ||
                  ((iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar5,a_01,param_2),
                   iVar3 == 0 ||
                   ((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                       (param_1_00,a_01,pBVar2,pBVar5,param_2), iVar3 == 0 ||
                    (iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar2,pBVar2,param_2),
                    iVar3 == 0)))))) ||
                 ((iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar5,pBVar5,param_2),
                  iVar3 == 0 ||
                  ((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                      (param_1_00,pBVar5,param_1_00 + 0x22,pBVar5,param_2),
                   iVar3 == 0 || (iVar3 = BN_GF2m_add(pBVar2,pBVar2,pBVar5,iVar3), iVar3 == 0))))))
              goto LAB_081bb768;
              BN_CTX_end(param_2);
              BN_consttime_swap(uVar4,pBVar2,a,param_1_00[0x13]);
              BN_consttime_swap(uVar4,a_01,a_00,param_1_00[0x13]);
              local_38 = local_38 >> 1;
            } while (local_38 != 0);
            local_2c = local_2c + -1;
            local_24 = local_24 + -4;
            if (local_2c == -1) break;
            local_38 = 0x80000000;
            iVar3 = *param_3;
          }
        }
        param_1 = param_1 + 0x18;
        if (a_01->top == 0) {
          BN_set_word(a,0);
          BN_set_word(a_00,0);
          iVar3 = EC_POINT_set_to_infinity((EC_GROUP *)param_1_00,param_2_00);
          if (iVar3 != 0) {
LAB_081bba64:
            uVar8 = 1;
            BN_set_negative(a,0);
            BN_set_negative(a_00,0);
            goto LAB_081bb5e6;
          }
        }
        else {
          if (*(int *)(param_2_00 + 0x1c) != 0) {
            BN_CTX_start(param_2);
            pBVar5 = BN_CTX_get(param_2);
            pBVar6 = BN_CTX_get(param_2);
            pBVar7 = BN_CTX_get(param_2);
            if (pBVar7 != (BIGNUM *)0x0) {
              uVar9 = 1;
              uVar8 = extraout_EDX;
              uVar10 = extraout_EDX;
              iVar3 = BN_set_word(pBVar7,1);
              if ((((((iVar3 != 0) &&
                     (iVar3 = (**(code **)(*param_1_00 + 0x84))
                                        (param_1_00,pBVar5,a_01,a_00,param_2,uVar9,uVar8,uVar10),
                     iVar3 != 0)) &&
                    (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_01,a_01,b,param_2),
                    iVar3 != 0)) &&
                   (((iVar3 = BN_GF2m_add(a_01,a_01,pBVar2,iVar3), iVar3 != 0 &&
                     (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_00,a_00,b,param_2),
                     iVar3 != 0)) &&
                    ((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                        (param_1_00,pBVar2,a_00,pBVar2,param_2), iVar3 != 0 &&
                     ((iVar3 = BN_GF2m_add(a_00,a_00,a,iVar3), iVar3 != 0 &&
                      (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_00,a_00,a_01,param_2),
                      iVar3 != 0)))))))) &&
                  ((iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar6,b,param_2),
                   iVar3 != 0 &&
                   (((((iVar3 = BN_GF2m_add(pBVar6,pBVar6,param_1,iVar3), iVar3 != 0 &&
                       (iVar3 = (**(code **)(*param_1_00 + 0x84))
                                          (param_1_00,pBVar6,pBVar6,pBVar5,param_2), iVar3 != 0)) &&
                      (iVar3 = BN_GF2m_add(pBVar6,pBVar6,a_00,iVar3), iVar3 != 0)) &&
                     ((iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,pBVar5,pBVar5,b,param_2)
                      , iVar3 != 0 &&
                      (iVar3 = (**(code **)(*param_1_00 + 0x8c))
                                         (param_1_00,pBVar5,pBVar7,pBVar5,param_2), iVar3 != 0))))
                    && ((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                           (param_1_00,pBVar6,pBVar5,pBVar6,param_2), iVar3 != 0 &&
                        ((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                            (param_1_00,a,pBVar2,pBVar5,param_2), iVar3 != 0 &&
                         (iVar3 = BN_GF2m_add(a_00,a,b,iVar3), iVar3 != 0)))))))))) &&
                 ((iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_00,a_00,pBVar6,param_2),
                  iVar3 != 0 && (iVar3 = BN_GF2m_add(a_00,a_00,param_1,param_1_00), iVar3 != 0)))) {
                BN_CTX_end(param_2);
                goto LAB_081bba45;
              }
            }
LAB_081bb768:
            uVar8 = 0;
            BN_CTX_end(param_2);
            goto LAB_081bb5e6;
          }
          pBVar2 = BN_copy(a,b);
          if ((pBVar2 != (BIGNUM *)0x0) &&
             (iVar3 = BN_GF2m_add(a_00,b,param_1,extraout_ECX), iVar3 != 0)) {
LAB_081bba45:
            iVar3 = BN_set_word((BIGNUM *)(param_2_00 + 0x2c),1);
            if (iVar3 != 0) {
              *(undefined4 *)(param_2_00 + 0x40) = 1;
              goto LAB_081bba64;
            }
          }
        }
      }
    }
  }
  uVar8 = 0;
LAB_081bb5e6:
  BN_CTX_end(param_2);
  return uVar8;
}

