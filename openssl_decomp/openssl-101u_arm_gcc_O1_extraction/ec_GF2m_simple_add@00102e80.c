
int ec_GF2m_simple_add(int *param_1,EC_POINT *param_2,EC_POINT *param_3,EC_POINT *param_4,
                      BN_CTX *param_5)

{
  int iVar1;
  BN_CTX *c;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = EC_POINT_copy(param_2,param_4);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  c = (BN_CTX *)EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_4);
  if (c != (BN_CTX *)0x0) {
    iVar1 = EC_POINT_copy(param_2,param_3);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  pBVar2 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  pBVar4 = BN_CTX_get(param_5);
  pBVar5 = BN_CTX_get(param_5);
  if (pBVar5 != (BIGNUM *)0x0) {
    if (*(int *)(param_3 + 0x40) == 0) {
      pBVar6 = (BIGNUM *)EC_POINT_get_affine_coordinates_GF2m(param_1,param_3,a,a_00,param_5);
    }
    else {
      pBVar6 = BN_copy(a,(BIGNUM *)(param_3 + 4));
      if (pBVar6 == (BIGNUM *)0x0) goto LAB_0010307c;
      pBVar6 = BN_copy(a_00,(BIGNUM *)(param_3 + 0x18));
    }
    if (pBVar6 != (BIGNUM *)0x0) {
      if (*(int *)(param_4 + 0x40) == 0) {
        pBVar6 = (BIGNUM *)EC_POINT_get_affine_coordinates_GF2m(param_1,param_4,a_01,a_02,param_5);
      }
      else {
        pBVar6 = BN_copy(a_01,(BIGNUM *)(param_4 + 4));
        if (pBVar6 == (BIGNUM *)0x0) goto LAB_0010307c;
        pBVar6 = BN_copy(a_02,(BIGNUM *)(param_4 + 0x18));
      }
      if (pBVar6 != (BIGNUM *)0x0) {
        iVar1 = BN_ucmp(a,a_01);
        if (iVar1 == 0) {
          iVar1 = BN_ucmp(a_00,a_02);
          if ((iVar1 != 0) || (a_01->top == 0)) {
            iVar1 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
            if (iVar1 != 0) {
              iVar1 = 1;
            }
            goto LAB_0010307e;
          }
          iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar4,a_02,a_01,param_5);
          if ((((iVar1 != 0) && (iVar1 = BN_GF2m_add(pBVar4,pBVar4,a_01), iVar1 != 0)) &&
              (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,pBVar4,param_5), iVar1 != 0))
             && (iVar1 = BN_GF2m_add(pBVar2,pBVar2,pBVar4), iVar1 != 0)) {
            iVar1 = BN_GF2m_add(pBVar2,pBVar2,param_1 + 0x1d);
            goto joined_r0x0010307a;
          }
        }
        else {
          iVar1 = BN_GF2m_add(pBVar5,a,a_01);
          if ((((iVar1 != 0) && (iVar1 = BN_GF2m_add(pBVar4,a_00,a_02), iVar1 != 0)) &&
              ((iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar4,pBVar4,pBVar5,param_5),
               iVar1 != 0 &&
               ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,pBVar4,param_5), iVar1 != 0
                && (iVar1 = BN_GF2m_add(pBVar2,pBVar2,param_1 + 0x1d), iVar1 != 0)))))) &&
             (iVar1 = BN_GF2m_add(pBVar2,pBVar2,pBVar4), iVar1 != 0)) {
            iVar1 = BN_GF2m_add(pBVar2,pBVar2,pBVar5);
joined_r0x0010307a:
            if ((((iVar1 != 0) && (iVar1 = BN_GF2m_add(pBVar3,a_01,pBVar2), iVar1 != 0)) &&
                (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,pBVar3,pBVar4,param_5),
                iVar1 != 0)) &&
               ((iVar1 = BN_GF2m_add(pBVar3,pBVar3,pBVar2), iVar1 != 0 &&
                (iVar1 = BN_GF2m_add(pBVar3,pBVar3,a_02), iVar1 != 0)))) {
              iVar1 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,pBVar2,pBVar3,param_5);
              if (iVar1 != 0) {
                iVar1 = 1;
              }
              goto LAB_0010307e;
            }
          }
        }
      }
    }
  }
LAB_0010307c:
  iVar1 = 0;
LAB_0010307e:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
    return iVar1;
  }
  return iVar1;
}

