
/* WARNING: Type propagation algorithm not settling */

undefined ec_GF2m_simple_dbl(int *param_1,EC_POINT *param_2,BIGNUM *param_3,BN_CTX *param_4)

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
  if ((iVar1 != 0) ||
     (uVar2 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,(EC_POINT *)param_3), uVar2 != 0)) {
    iVar1 = EC_POINT_copy(param_2,(EC_POINT *)param_3);
    return iVar1 != 0;
  }
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    if (param_4 == (BN_CTX *)0x0) {
      return 0;
    }
    BN_CTX_start(param_4);
    local_40 = BN_CTX_get(param_4);
    local_38 = BN_CTX_get(param_4);
    local_3c = BN_CTX_get(param_4);
    local_30 = BN_CTX_get(param_4);
    local_24 = BN_CTX_get(param_4);
    local_20 = BN_CTX_get(param_4);
    local_28 = BN_CTX_get(param_4);
    local_2c = BN_CTX_get(param_4);
    pBVar4 = param_4;
    if (local_2c == (BIGNUM *)0x0) {
      uVar5 = 0;
      BN_CTX_end(param_4);
      goto LAB_081bc736;
    }
  }
  else {
    BN_CTX_start(param_4);
    local_40 = BN_CTX_get(param_4);
    local_38 = BN_CTX_get(param_4);
    local_3c = BN_CTX_get(param_4);
    local_30 = BN_CTX_get(param_4);
    local_24 = BN_CTX_get(param_4);
    local_20 = BN_CTX_get(param_4);
    local_28 = BN_CTX_get(param_4);
    local_2c = BN_CTX_get(param_4);
    if (local_2c == (BIGNUM *)0x0) {
      BN_CTX_end(param_4);
      return 0;
    }
    pBVar4 = (BN_CTX *)0x0;
  }
  if (*(int *)((int)(param_3 + 3) + 4) == 0) {
    iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_3,local_40,local_38,param_4);
    if (iVar1 == 0) goto LAB_081bc720;
LAB_081bc4f9:
    if (*(int *)((int)(param_3 + 3) + 4) != 0) {
      pBVar3 = BN_copy(local_3c,(BIGNUM *)&param_3->top);
      if (pBVar3 != (BIGNUM *)0x0) {
        param_3 = (BIGNUM *)((int)(param_3 + 1) + 4);
        pBVar3 = BN_copy(local_30,param_3);
        if (pBVar3 != (BIGNUM *)0x0) goto LAB_081bc53a;
      }
      goto LAB_081bc720;
    }
    iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_3,local_3c,local_30,param_4);
    if (iVar1 == 0) goto LAB_081bc720;
LAB_081bc53a:
    iVar1 = BN_ucmp(local_40,local_3c);
    if (iVar1 != 0) {
      iVar1 = BN_GF2m_add(local_2c,local_40,local_3c);
      if (((((iVar1 != 0) && (iVar1 = BN_GF2m_add(local_28,local_38,local_30), iVar1 != 0)) &&
           (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,local_28,local_28,local_2c,param_4),
           iVar1 != 0)) &&
          ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,local_24,local_28,param_4), iVar1 != 0 &&
           (iVar1 = BN_GF2m_add(local_24,local_24,param_1 + 0x1d,iVar1), iVar1 != 0)))) &&
         (iVar1 = BN_GF2m_add(local_24,local_24,local_28,iVar1), iVar1 != 0)) {
LAB_081bc60d:
        iVar1 = BN_GF2m_add(local_24,local_24,local_2c,iVar1);
        if ((iVar1 != 0) && (iVar1 = BN_GF2m_add(local_20,local_3c,local_24,iVar1), iVar1 != 0)) {
          uVar6 = (**(code **)(*param_1 + 0x84))(param_1,local_20,local_20,local_28,param_4);
          if (((int)uVar6 != 0) &&
             ((iVar1 = BN_GF2m_add(local_20,local_20,local_24,(int)((ulonglong)uVar6 >> 0x20)),
              iVar1 != 0 && (iVar1 = BN_GF2m_add(local_20,local_20,local_30,iVar1), iVar1 != 0)))) {
            iVar1 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,local_24,local_20,param_4);
            uVar5 = iVar1 != 0;
            goto LAB_081bc722;
          }
        }
      }
      goto LAB_081bc720;
    }
    iVar1 = BN_ucmp(local_38,local_30);
    if ((iVar1 == 0) && (local_3c->top != 0)) {
      iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,local_28,local_30,local_3c,param_4);
      if ((iVar1 != 0) &&
         (((iVar1 = BN_GF2m_add(local_28,local_28,local_3c), iVar1 != 0 &&
           (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,local_24,local_28,param_4), iVar1 != 0))
          && (iVar1 = BN_GF2m_add(local_24,local_24,local_28,param_3), iVar1 != 0)))) {
        local_2c = (BIGNUM *)(param_1 + 0x1d);
        iVar1 = extraout_ECX;
        goto LAB_081bc60d;
      }
      goto LAB_081bc720;
    }
    iVar1 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
    uVar5 = iVar1 != 0;
  }
  else {
    pBVar3 = BN_copy(local_40,(BIGNUM *)&param_3->top);
    if ((pBVar3 != (BIGNUM *)0x0) &&
       (pBVar3 = BN_copy(local_38,(BIGNUM *)((int)(param_3 + 1) + 4)), pBVar3 != (BIGNUM *)0x0))
    goto LAB_081bc4f9;
LAB_081bc720:
    uVar5 = 0;
  }
LAB_081bc722:
  BN_CTX_end(param_4);
  param_4 = pBVar4;
  if (pBVar4 == (BN_CTX *)0x0) {
    return uVar5;
  }
LAB_081bc736:
  BN_CTX_free(param_4);
  return uVar5;
}

