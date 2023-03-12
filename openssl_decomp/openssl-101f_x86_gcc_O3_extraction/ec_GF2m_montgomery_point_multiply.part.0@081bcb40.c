
undefined4 __regparm3
ec_GF2m_montgomery_point_multiply_part_0
          (int *param_1_00,EC_POINT *param_2_00,int *param_3,int param_1,BN_CTX *param_2)

{
  BIGNUM *b;
  uint uVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  int iVar3;
  BIGNUM *a_00;
  BIGNUM *a_01;
  uint uVar4;
  uint uVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *a_02;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_24;
  int local_20;
  
  BN_CTX_start(param_2);
  pBVar2 = BN_CTX_get(param_2);
  a = BN_CTX_get(param_2);
  if (a != (BIGNUM *)0x0) {
    b = (BIGNUM *)(param_1 + 4);
    iVar3 = BN_GF2m_mod_arr(pBVar2,b,param_1_00 + 0x17);
    if ((iVar3 != 0) && (iVar3 = BN_set_word(a,1), iVar3 != 0)) {
      a_00 = (BIGNUM *)(param_2_00 + 0x18);
      iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,a_00,pBVar2,param_2);
      if (iVar3 != 0) {
        a_01 = (BIGNUM *)(param_2_00 + 4);
        iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,a_01,a_00,param_2);
        if ((iVar3 != 0) && (iVar3 = BN_GF2m_add(a_01,a_01,param_1_00 + 0x22), iVar3 != 0)) {
          iVar3 = *param_3;
          local_24 = param_3[1] + -1;
          uVar1 = *(uint *)(iVar3 + local_24 * 4);
          if ((int)uVar1 < 0) {
            uVar5 = 0x40000000;
          }
          else {
            uVar4 = 0x80000000;
            do {
              uVar5 = uVar4;
              uVar4 = uVar5 >> 1;
            } while ((uVar1 & uVar4) == 0);
            uVar5 = uVar5 >> 2;
            if (uVar5 == 0) {
              uVar5 = 0x80000000;
              local_24 = param_3[1] + -2;
            }
          }
          if (-1 < local_24) {
            local_20 = local_24 << 2;
            while( true ) {
              uVar1 = *(uint *)(iVar3 + local_20);
              do {
                if ((uVar1 & uVar5) == 0) {
                  iVar3 = gf2m_Madd(a_00,pBVar2,a,param_2);
                }
                else {
                  iVar3 = gf2m_Madd(a,a_01,a_00,param_2);
                }
                if ((iVar3 == 0) || (iVar3 = gf2m_Mdouble(param_2), iVar3 == 0)) goto LAB_081bcb97;
                uVar5 = uVar5 >> 1;
              } while (uVar5 != 0);
              local_24 = local_24 + -1;
              local_20 = local_20 + -4;
              if (local_24 == -1) break;
              uVar5 = 0x80000000;
              iVar3 = *param_3;
            }
          }
          param_1 = param_1 + 0x18;
          if (a->top == 0) {
            BN_set_word(a_01,0);
            BN_set_word(a_00,0);
            iVar3 = EC_POINT_set_to_infinity((EC_GROUP *)param_1_00,param_2_00);
            if (iVar3 != 0) {
LAB_081bcdb6:
              uVar8 = 1;
              BN_set_negative(a_01,0);
              BN_set_negative(a_00,0);
              goto LAB_081bcb99;
            }
          }
          else if (*(int *)(param_2_00 + 0x1c) == 0) {
            pBVar2 = BN_copy(a_01,b);
            if ((pBVar2 != (BIGNUM *)0x0) &&
               (iVar3 = BN_GF2m_add(a_00,b,param_1,extraout_ECX), iVar3 != 0)) {
LAB_081bcd91:
              iVar3 = BN_set_word((BIGNUM *)(param_2_00 + 0x2c),1);
              if (iVar3 != 0) {
                *(undefined4 *)(param_2_00 + 0x40) = 1;
                goto LAB_081bcdb6;
              }
            }
          }
          else {
            BN_CTX_start(param_2);
            pBVar6 = BN_CTX_get(param_2);
            pBVar7 = BN_CTX_get(param_2);
            a_02 = BN_CTX_get(param_2);
            if (a_02 != (BIGNUM *)0x0) {
              uVar9 = 1;
              uVar8 = extraout_EDX;
              uVar10 = extraout_EDX;
              iVar3 = BN_set_word(a_02,1);
              if (((((((iVar3 != 0) &&
                      (iVar3 = (**(code **)(*param_1_00 + 0x84))
                                         (param_1_00,pBVar6,a,a_00,param_2,uVar9,uVar8,uVar10),
                      iVar3 != 0)) &&
                     (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a,a,b,param_2),
                     iVar3 != 0)) &&
                    ((iVar3 = BN_GF2m_add(a,a,pBVar2,iVar3), iVar3 != 0 &&
                     (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_00,a_00,b,param_2),
                     iVar3 != 0)))) &&
                   (((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                        (param_1_00,pBVar2,a_00,pBVar2,param_2), iVar3 != 0 &&
                     ((iVar3 = BN_GF2m_add(a_00,a_00,a_01,iVar3), iVar3 != 0 &&
                      (iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_00,a_00,a,param_2),
                      iVar3 != 0)))) &&
                    (iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar7,b,param_2),
                    iVar3 != 0)))) &&
                  ((((iVar3 = BN_GF2m_add(pBVar7,pBVar7,param_1,iVar3), iVar3 != 0 &&
                     (iVar3 = (**(code **)(*param_1_00 + 0x84))
                                        (param_1_00,pBVar7,pBVar7,pBVar6,param_2), iVar3 != 0)) &&
                    (iVar3 = BN_GF2m_add(pBVar7,pBVar7,a_00,iVar3), iVar3 != 0)) &&
                   (((iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,pBVar6,pBVar6,b,param_2),
                     iVar3 != 0 &&
                     (iVar3 = (**(code **)(*param_1_00 + 0x8c))
                                        (param_1_00,pBVar6,a_02,pBVar6,param_2), iVar3 != 0)) &&
                    ((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                        (param_1_00,pBVar7,pBVar6,pBVar7,param_2), iVar3 != 0 &&
                     ((iVar3 = (**(code **)(*param_1_00 + 0x84))
                                         (param_1_00,a_01,pBVar2,pBVar6,param_2), iVar3 != 0 &&
                      (iVar3 = BN_GF2m_add(a_00,a_01,b,iVar3), iVar3 != 0)))))))))) &&
                 ((iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,a_00,a_00,pBVar7,param_2),
                  iVar3 != 0 && (iVar3 = BN_GF2m_add(a_00,a_00,param_1,param_1_00), iVar3 != 0)))) {
                BN_CTX_end(param_2);
                goto LAB_081bcd91;
              }
            }
            BN_CTX_end(param_2);
          }
        }
      }
    }
  }
LAB_081bcb97:
  uVar8 = 0;
LAB_081bcb99:
  BN_CTX_end(param_2);
  return uVar8;
}

