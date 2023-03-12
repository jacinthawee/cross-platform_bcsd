
/* WARNING: Type propagation algorithm not settling */

undefined ec_GF2m_simple_add(int *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4,
                            BN_CTX *param_5)

{
  int iVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  int extraout_ECX;
  BN_CTX *pBVar4;
  undefined uVar5;
  undefined8 uVar6;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  BIGNUM *local_38;
  BIGNUM *local_30;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24;
  BIGNUM *local_20;
  
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,(EC_POINT *)param_3);
  pBVar3 = param_4;
  if ((iVar1 != 0) ||
     (uVar2 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,(EC_POINT *)param_4), pBVar3 = param_3,
     uVar2 != 0)) {
    iVar1 = EC_POINT_copy(param_2,(EC_POINT *)pBVar3);
    return iVar1 != 0;
  }
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    if (param_5 == (BN_CTX *)0x0) {
      return 0;
    }
    BN_CTX_start(param_5);
    local_40 = BN_CTX_get(param_5);
    local_38 = BN_CTX_get(param_5);
    local_3c = BN_CTX_get(param_5);
    local_30 = BN_CTX_get(param_5);
    local_24 = BN_CTX_get(param_5);
    local_20 = BN_CTX_get(param_5);
    local_28 = BN_CTX_get(param_5);
    local_2c = BN_CTX_get(param_5);
    pBVar4 = param_5;
    if (local_2c == (BIGNUM *)0x0) {
      uVar5 = 0;
      BN_CTX_end(param_5);
      goto LAB_081bc1ae;
    }
  }
  else {
    BN_CTX_start(param_5);
    local_40 = BN_CTX_get(param_5);
    local_38 = BN_CTX_get(param_5);
    local_3c = BN_CTX_get(param_5);
    local_30 = BN_CTX_get(param_5);
    local_24 = BN_CTX_get(param_5);
    local_20 = BN_CTX_get(param_5);
    local_28 = BN_CTX_get(param_5);
    local_2c = BN_CTX_get(param_5);
    if (local_2c == (BIGNUM *)0x0) {
      BN_CTX_end(param_5);
      return 0;
    }
    pBVar4 = (BN_CTX *)0x0;
  }
  if (*(int *)((int)(param_3 + 3) + 4) == 0) {
    iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_3,local_40,local_38,param_5);
    if (iVar1 == 0) goto LAB_081bc198;
LAB_081bbf8f:
    if (*(int *)((int)(param_4 + 3) + 4) != 0) {
      pBVar3 = BN_copy(local_3c,(BIGNUM *)&param_4->top);
      if ((pBVar3 != (BIGNUM *)0x0) &&
         (pBVar3 = BN_copy(local_30,(BIGNUM *)((int)(param_4 + 1) + 4)), pBVar3 != (BIGNUM *)0x0))
      goto LAB_081bbfdc;
      goto LAB_081bc198;
    }
    iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_4,local_3c,local_30,param_5);
    if (iVar1 == 0) goto LAB_081bc198;
LAB_081bbfdc:
    iVar1 = BN_ucmp(local_40,local_3c);
    if (iVar1 != 0) {
      iVar1 = BN_GF2m_add(local_2c,local_40,local_3c);
      if (((((iVar1 != 0) && (iVar1 = BN_GF2m_add(local_28,local_38,local_30), iVar1 != 0)) &&
           (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,local_28,local_28,local_2c,param_5),
           iVar1 != 0)) &&
          ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,local_24,local_28,param_5), iVar1 != 0 &&
           (iVar1 = BN_GF2m_add(local_24,local_24,param_1 + 0x1d,iVar1), iVar1 != 0)))) &&
         (iVar1 = BN_GF2m_add(local_24,local_24,local_28,iVar1), iVar1 != 0)) {
LAB_081bc0af:
        iVar1 = BN_GF2m_add(local_24,local_24,local_2c,iVar1);
        if ((iVar1 != 0) && (iVar1 = BN_GF2m_add(local_20,local_3c,local_24,iVar1), iVar1 != 0)) {
          uVar6 = (**(code **)(*param_1 + 0x84))(param_1,local_20,local_20,local_28,param_5);
          if (((int)uVar6 != 0) &&
             ((iVar1 = BN_GF2m_add(local_20,local_20,local_24,(int)((ulonglong)uVar6 >> 0x20)),
              iVar1 != 0 && (iVar1 = BN_GF2m_add(local_20,local_20,local_30,iVar1), iVar1 != 0)))) {
            iVar1 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,local_24,local_20,param_5);
            uVar5 = iVar1 != 0;
            goto LAB_081bc19a;
          }
        }
      }
      goto LAB_081bc198;
    }
    iVar1 = BN_ucmp(local_38,local_30);
    if ((iVar1 == 0) && (local_3c->top != 0)) {
      iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,local_28,local_30,local_3c,param_5);
      if ((iVar1 != 0) &&
         (((iVar1 = BN_GF2m_add(local_28,local_28,local_3c), iVar1 != 0 &&
           (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,local_24,local_28,param_5), iVar1 != 0))
          && (iVar1 = BN_GF2m_add(local_24,local_24,local_28,param_3), iVar1 != 0)))) {
        local_2c = (BIGNUM *)(param_1 + 0x1d);
        iVar1 = extraout_ECX;
        goto LAB_081bc0af;
      }
      goto LAB_081bc198;
    }
    iVar1 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
    uVar5 = iVar1 != 0;
  }
  else {
    pBVar3 = BN_copy(local_40,(BIGNUM *)&param_3->top);
    if (pBVar3 != (BIGNUM *)0x0) {
      param_3 = (BIGNUM *)((int)(param_3 + 1) + 4);
      pBVar3 = BN_copy(local_38,param_3);
      if (pBVar3 != (BIGNUM *)0x0) goto LAB_081bbf8f;
    }
LAB_081bc198:
    uVar5 = 0;
  }
LAB_081bc19a:
  BN_CTX_end(param_5);
  param_5 = pBVar4;
  if (pBVar4 == (BN_CTX *)0x0) {
    return uVar5;
  }
LAB_081bc1ae:
  BN_CTX_free(param_5);
  return uVar5;
}

