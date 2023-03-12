
int ec_GF2m_montgomery_point_multiply
              (int *param_1,EC_POINT *param_2,int *param_3,EC_POINT *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *a_01;
  uint uVar6;
  BIGNUM *b;
  uint uVar7;
  uint local_4c;
  int local_44;
  int local_3c;
  
  if (param_2 == param_4) {
    ERR_put_error(0x10,0xd0,0x70,"ec2_mult.c",0x112);
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
    iVar1 = param_1[0x13];
    a_00 = (BIGNUM *)(param_2 + 4);
    a_01 = (BIGNUM *)(param_2 + 0x18);
    if (pBVar2->dmax < iVar1) {
      bn_expand2(pBVar2,iVar1);
      iVar1 = param_1[0x13];
    }
    if (a->dmax < iVar1) {
      bn_expand2(a,iVar1);
      iVar1 = param_1[0x13];
    }
    if (*(int *)(param_2 + 0xc) < iVar1) {
      bn_expand2(a_00,iVar1);
      iVar1 = param_1[0x13];
    }
    if (*(int *)(param_2 + 0x20) < iVar1) {
      bn_expand2(a_01,iVar1);
    }
    b = (BIGNUM *)(param_4 + 4);
    iVar1 = BN_GF2m_mod_arr(pBVar2,b,param_1 + 0x17);
    if (((iVar1 != 0) && (iVar1 = BN_set_word(a,1), iVar1 != 0)) &&
       ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,a_01,pBVar2,param_5), iVar1 != 0 &&
        (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,a_00,a_01,param_5), iVar1 != 0)))) {
      iVar1 = BN_GF2m_add(a_00,a_00,param_1 + 0x22);
      if (iVar1 != 0) {
        local_44 = param_3[1] + -1;
        uVar6 = *(uint *)(*param_3 + local_44 * 4);
        if ((int)uVar6 < 0) {
          local_4c = 0x40000000;
        }
        else {
          uVar7 = 0x80000000;
          do {
            local_4c = uVar7;
            uVar7 = local_4c >> 1;
          } while ((uVar6 & uVar7) == 0);
          local_4c = local_4c >> 2;
          if (local_4c == 0) {
            local_44 = param_3[1] + -2;
            local_4c = 0x80000000;
          }
        }
        local_3c = local_44 << 2;
        for (; -1 < local_44; local_44 = local_44 + -1) {
          uVar6 = *(uint *)(*param_3 + local_3c);
          do {
            uVar7 = local_4c & uVar6;
            BN_consttime_swap(uVar7,pBVar2,a_00,param_1[0x13]);
            BN_consttime_swap(uVar7,a,a_01,param_1[0x13]);
            BN_CTX_start(param_5);
            pBVar3 = BN_CTX_get(param_5);
            pBVar4 = BN_CTX_get(param_5);
            if (((pBVar4 == (BIGNUM *)0x0) || (pBVar5 = BN_copy(pBVar3,b), pBVar5 == (BIGNUM *)0x0))
               || (((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_00,a_00,a,param_5), iVar1 == 0
                    || (((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,pBVar2,param_5),
                         iVar1 == 0 ||
                         (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar4,a_00,a_01,param_5),
                         iVar1 == 0)) || (iVar1 = BN_GF2m_add(a_01,a_01,a_00), iVar1 == 0)))) ||
                   (((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,a_01,a_01,param_5), iVar1 == 0
                     || (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_00,a_01,pBVar3,param_5),
                        iVar1 == 0)) || (iVar1 = BN_GF2m_add(a_00,a_00,pBVar4), iVar1 == 0))))))
            goto LAB_001035ac;
            BN_CTX_end(param_5);
            BN_CTX_start(param_5);
            pBVar3 = BN_CTX_get(param_5);
            if (((pBVar3 == (BIGNUM *)0x0) ||
                (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,pBVar2,param_5), iVar1 == 0))
               || (((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar3,a,param_5), iVar1 == 0 ||
                    (((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a,pBVar2,pBVar3,param_5),
                      iVar1 == 0 ||
                      (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,pBVar2,param_5),
                      iVar1 == 0)) ||
                     (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar3,pBVar3,param_5),
                     iVar1 == 0)))) ||
                   ((iVar1 = (**(code **)(*param_1 + 0x84))
                                       (param_1,pBVar3,param_1 + 0x22,pBVar3,param_5), iVar1 == 0 ||
                    (iVar1 = BN_GF2m_add(pBVar2,pBVar2,pBVar3), iVar1 == 0)))))) goto LAB_001035ac;
            BN_CTX_end(param_5);
            BN_consttime_swap(uVar7,pBVar2,a_00,param_1[0x13]);
            BN_consttime_swap(uVar7,a,a_01,param_1[0x13]);
            local_4c = local_4c >> 1;
          } while (local_4c != 0);
          local_4c = 0x80000000;
          local_3c = local_3c + -4;
        }
        param_4 = param_4 + 0x18;
        if (a->top == 0) {
          BN_set_word(a_00,0);
          BN_set_word(a_01,0);
          iVar1 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
          if (iVar1 != 0) goto LAB_0010379e;
        }
        else {
          if (*(int *)(param_2 + 0x1c) == 0) {
            pBVar2 = BN_copy(a_00,b);
            if ((pBVar2 == (BIGNUM *)0x0) || (iVar1 = BN_GF2m_add(a_01,b,param_4), iVar1 == 0))
            goto LAB_00103488;
          }
          else {
            BN_CTX_start(param_5);
            pBVar3 = BN_CTX_get(param_5);
            pBVar4 = BN_CTX_get(param_5);
            pBVar5 = BN_CTX_get(param_5);
            if ((((((pBVar5 == (BIGNUM *)0x0) || (iVar1 = BN_set_word(pBVar5,1), iVar1 == 0)) ||
                  ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,a,a_01,param_5),
                   iVar1 == 0 ||
                   (((((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a,a,b,param_5), iVar1 == 0 ||
                       (iVar1 = BN_GF2m_add(a,a,pBVar2), iVar1 == 0)) ||
                      (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,b,param_5),
                      iVar1 == 0)) ||
                     ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar2,a_01,pBVar2,param_5),
                      iVar1 == 0 || (iVar1 = BN_GF2m_add(a_01,a_01,a_00), iVar1 == 0)))) ||
                    (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,a,param_5), iVar1 == 0
                    )))))) ||
                 ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar4,b,param_5), iVar1 == 0 ||
                  (iVar1 = BN_GF2m_add(pBVar4,pBVar4,param_4), iVar1 == 0)))) ||
                (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar4,pBVar4,pBVar3,param_5),
                iVar1 == 0)) ||
               ((((iVar1 = BN_GF2m_add(pBVar4,pBVar4,a_01), iVar1 == 0 ||
                  (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,pBVar3,b,param_5),
                  iVar1 == 0)) ||
                 (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar3,pBVar5,pBVar3,param_5),
                 iVar1 == 0)) ||
                (((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar4,pBVar3,pBVar4,param_5),
                  iVar1 == 0 ||
                  (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_00,pBVar2,pBVar3,param_5),
                  iVar1 == 0)) ||
                 ((iVar1 = BN_GF2m_add(a_01,a_00,b), iVar1 == 0 ||
                  ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,pBVar4,param_5),
                   iVar1 == 0 || (iVar1 = BN_GF2m_add(a_01,a_01,param_4), iVar1 == 0)))))))))) {
LAB_001035ac:
              iVar1 = 0;
              BN_CTX_end(param_5);
              goto LAB_0010348a;
            }
            BN_CTX_end(param_5);
          }
          iVar1 = BN_set_word((BIGNUM *)(param_2 + 0x2c),1);
          if (iVar1 != 0) {
            *(undefined4 *)(param_2 + 0x40) = 1;
LAB_0010379e:
            BN_set_negative(a_00,0);
            iVar1 = 1;
            BN_set_negative(a_01,0);
            goto LAB_0010348a;
          }
        }
      }
    }
  }
LAB_00103488:
  iVar1 = 0;
LAB_0010348a:
  BN_CTX_end(param_5);
  return iVar1;
}

