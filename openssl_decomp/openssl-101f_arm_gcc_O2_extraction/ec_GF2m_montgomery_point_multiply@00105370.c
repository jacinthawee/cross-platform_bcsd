
int ec_GF2m_montgomery_point_multiply
              (int *param_1,EC_POINT *param_2,int *param_3,EC_POINT *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *a_02;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  BIGNUM *b;
  int local_3c;
  int local_38;
  
  if (param_2 == param_4) {
    ERR_put_error(0x10,0xd0,0x70,"ec2_mult.c",0xe2);
    return 0;
  }
  if ((((param_3 == (int *)0x0) || (param_3[1] == 0)) || (param_4 == (EC_POINT *)0x0)) ||
     (iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_4), iVar1 != 0)) {
    iVar1 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
    return iVar1;
  }
  if (*(int *)(param_4 + 0x40) == 0) {
    return 0;
  }
  BN_CTX_start(param_5);
  pBVar2 = BN_CTX_get(param_5);
  a = BN_CTX_get(param_5);
  if (a != (BIGNUM *)0x0) {
    b = (BIGNUM *)(param_4 + 4);
    iVar1 = BN_GF2m_mod_arr(pBVar2,b,param_1 + 0x17);
    if ((iVar1 != 0) && (iVar1 = BN_set_word(a,1), iVar1 != 0)) {
      a_00 = (BIGNUM *)(param_2 + 0x18);
      iVar1 = (**(code **)(*param_1 + 0x88))(param_1,a_00,pBVar2,param_5);
      if (iVar1 != 0) {
        a_01 = (BIGNUM *)(param_2 + 4);
        iVar1 = (**(code **)(*param_1 + 0x88))(param_1,a_01,a_00,param_5);
        if ((iVar1 != 0) && (iVar1 = BN_GF2m_add(a_01,a_01,param_1 + 0x22), iVar1 != 0)) {
          local_3c = param_3[1] + -1;
          uVar5 = *(uint *)(*param_3 + local_3c * 4);
          if ((int)uVar5 < 0) {
            uVar7 = 0x40000000;
          }
          else {
            uVar6 = 0x80000000;
            do {
              uVar7 = uVar6;
              uVar6 = uVar7 >> 1;
            } while ((uVar5 & uVar6) == 0);
            uVar7 = uVar7 >> 2;
            if (uVar7 == 0) {
              uVar7 = 0x80000000;
              local_3c = param_3[1] + -2;
            }
          }
          local_38 = local_3c << 2;
          for (; -1 < local_3c; local_3c = local_3c + -1) {
            uVar5 = *(uint *)(*param_3 + local_38);
            do {
              if ((uVar7 & uVar5) == 0) {
                iVar1 = gf2m_Madd(param_1,b,a_01,a_00,pBVar2,a,param_5);
                pBVar3 = a;
                pBVar4 = pBVar2;
              }
              else {
                iVar1 = gf2m_Madd(param_1,b,pBVar2,a,a_01,a_00,param_5);
                pBVar3 = a_00;
                pBVar4 = a_01;
              }
              if ((iVar1 == 0) || (iVar1 = gf2m_Mdouble(param_1,pBVar4,pBVar3,param_5), iVar1 == 0))
              goto LAB_001053d6;
              uVar7 = uVar7 >> 1;
            } while (uVar7 != 0);
            uVar7 = 0x80000000;
            local_38 = local_38 + -4;
          }
          param_4 = param_4 + 0x18;
          if (a->top == 0) {
            BN_set_word(a_01,0);
            BN_set_word(a_00,0);
            iVar1 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
            if (iVar1 != 0) goto LAB_00105564;
          }
          else {
            if (*(int *)(param_2 + 0x1c) == 0) {
              pBVar2 = BN_copy(a_01,b);
              if ((pBVar2 == (BIGNUM *)0x0) || (iVar1 = BN_GF2m_add(a_00,b,param_4), iVar1 == 0))
              goto LAB_001053d6;
            }
            else {
              BN_CTX_start(param_5);
              pBVar3 = BN_CTX_get(param_5);
              pBVar4 = BN_CTX_get(param_5);
              a_02 = BN_CTX_get(param_5);
              if (((((((a_02 == (BIGNUM *)0x0) || (iVar1 = BN_set_word(a_02,1), iVar1 == 0)) ||
                     (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,a,a_00,param_5),
                     iVar1 == 0)) ||
                    (((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a,a,b,param_5), iVar1 == 0 ||
                      (iVar1 = BN_GF2m_add(a,a,pBVar2), iVar1 == 0)) ||
                     ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_00,a_00,b,param_5),
                      iVar1 == 0 ||
                      ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar2,a_00,pBVar2,param_5),
                       iVar1 == 0 || (iVar1 = BN_GF2m_add(a_00,a_00,a_01), iVar1 == 0)))))))) ||
                   ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_00,a_00,a,param_5), iVar1 == 0
                    || (((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar4,b,param_5),
                         iVar1 == 0 || (iVar1 = BN_GF2m_add(pBVar4,pBVar4,param_4), iVar1 == 0)) ||
                        (iVar1 = (**(code **)(*param_1 + 0x84))
                                           (param_1,pBVar4,pBVar4,pBVar3,param_5), iVar1 == 0))))))
                  || (((iVar1 = BN_GF2m_add(pBVar4,pBVar4,a_00), iVar1 == 0 ||
                       (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,pBVar3,b,param_5),
                       iVar1 == 0)) ||
                      (((iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar3,a_02,pBVar3,param_5),
                        iVar1 == 0 ||
                        ((iVar1 = (**(code **)(*param_1 + 0x84))
                                            (param_1,pBVar4,pBVar3,pBVar4,param_5), iVar1 == 0 ||
                         (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_01,pBVar2,pBVar3,param_5)
                         , iVar1 == 0)))) || (iVar1 = BN_GF2m_add(a_00,a_01,b), iVar1 == 0)))))) ||
                 ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_00,a_00,pBVar4,param_5),
                  iVar1 == 0 || (iVar1 = BN_GF2m_add(a_00,a_00,param_4), iVar1 == 0)))) {
                iVar1 = 0;
                BN_CTX_end(param_5);
                goto LAB_001053d8;
              }
              BN_CTX_end(param_5);
            }
            iVar1 = BN_set_word((BIGNUM *)(param_2 + 0x2c),1);
            if (iVar1 != 0) {
              *(undefined4 *)(param_2 + 0x40) = 1;
LAB_00105564:
              BN_set_negative(a_01,0);
              iVar1 = 1;
              BN_set_negative(a_00,0);
              goto LAB_001053d8;
            }
          }
        }
      }
    }
  }
LAB_001053d6:
  iVar1 = 0;
LAB_001053d8:
  BN_CTX_end(param_5);
  return iVar1;
}

