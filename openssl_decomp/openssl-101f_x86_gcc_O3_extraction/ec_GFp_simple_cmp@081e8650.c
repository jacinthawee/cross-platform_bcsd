
uint ec_GFp_simple_cmp(int *param_1,EC_POINT *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  BIGNUM *pBVar4;
  uint uVar5;
  BN_CTX *pBVar6;
  BIGNUM *local_38;
  BIGNUM *local_34;
  BIGNUM *local_30;
  BIGNUM *local_28;
  BIGNUM *local_24;
  
  iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar3 != 0) {
    iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
    return (uint)(iVar3 == 0);
  }
  iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
  if (iVar3 != 0) {
    return 1;
  }
  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(param_3 + 0x40) != 0)) {
    iVar3 = BN_cmp((BIGNUM *)(param_2 + 4),(BIGNUM *)(param_3 + 4));
    if (iVar3 != 0) {
      return 1;
    }
    iVar3 = BN_cmp((BIGNUM *)(param_2 + 0x18),(BIGNUM *)(param_3 + 0x18));
    return (uint)(iVar3 != 0);
  }
  pcVar1 = *(code **)(*param_1 + 0x84);
  pcVar2 = *(code **)(*param_1 + 0x88);
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    if (param_4 == (BN_CTX *)0x0) {
      return 0xffffffff;
    }
    BN_CTX_start(param_4);
    local_28 = BN_CTX_get(param_4);
    local_24 = BN_CTX_get(param_4);
    local_30 = BN_CTX_get(param_4);
    pBVar4 = BN_CTX_get(param_4);
    pBVar6 = param_4;
    if (pBVar4 == (BIGNUM *)0x0) {
      uVar5 = 0xffffffff;
      BN_CTX_end(param_4);
      goto LAB_081e8857;
    }
  }
  else {
    BN_CTX_start(param_4);
    local_28 = BN_CTX_get(param_4);
    local_24 = BN_CTX_get(param_4);
    local_30 = BN_CTX_get(param_4);
    pBVar4 = BN_CTX_get(param_4);
    if (pBVar4 == (BIGNUM *)0x0) {
      BN_CTX_end(param_4);
      return 0xffffffff;
    }
    pBVar6 = (BN_CTX *)0x0;
  }
  local_38 = (BIGNUM *)(param_2 + 4);
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar3 = (*pcVar2)(param_1,pBVar4,param_3 + 0x2c,param_4);
    if ((iVar3 != 0) && (iVar3 = (*pcVar1)(param_1,local_28,local_38,pBVar4,param_4), iVar3 != 0)) {
      local_38 = local_28;
      goto LAB_081e8713;
    }
LAB_081e8840:
    uVar5 = 0xffffffff;
  }
  else {
LAB_081e8713:
    local_34 = (BIGNUM *)(param_3 + 4);
    if (*(int *)(param_2 + 0x40) == 0) {
      iVar3 = (*pcVar2)(param_1,local_30,param_2 + 0x2c,param_4);
      if ((iVar3 == 0) ||
         (iVar3 = (*pcVar1)(param_1,local_24,local_34,local_30,param_4), iVar3 == 0))
      goto LAB_081e8840;
      local_34 = local_24;
    }
    uVar5 = 1;
    iVar3 = BN_cmp(local_38,local_34);
    if (iVar3 == 0) {
      if (*(int *)(param_3 + 0x40) == 0) {
        iVar3 = (*pcVar1)(param_1,pBVar4,pBVar4,param_3 + 0x2c,param_4);
        if ((iVar3 == 0) ||
           (iVar3 = (*pcVar1)(param_1,local_28,param_2 + 0x18,pBVar4,param_4), iVar3 == 0))
        goto LAB_081e8840;
      }
      else {
        local_38 = (BIGNUM *)(param_2 + 0x18);
      }
      if (*(int *)(param_2 + 0x40) == 0) {
        iVar3 = (*pcVar1)(param_1,local_30,local_30,param_2 + 0x2c,param_4);
        if ((iVar3 == 0) ||
           (iVar3 = (*pcVar1)(param_1,local_24,param_3 + 0x18,local_30,param_4), iVar3 == 0))
        goto LAB_081e8840;
      }
      else {
        local_34 = (BIGNUM *)(param_3 + 0x18);
      }
      iVar3 = BN_cmp(local_38,local_34);
      uVar5 = (uint)(iVar3 != 0);
    }
  }
  BN_CTX_end(param_4);
  param_4 = pBVar6;
  if (pBVar6 == (BN_CTX *)0x0) {
    return uVar5;
  }
LAB_081e8857:
  BN_CTX_free(param_4);
  return uVar5;
}

