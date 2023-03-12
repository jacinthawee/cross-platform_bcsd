
uint ec_GFp_simple_cmp(int *param_1,EC_POINT *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  code *pcVar7;
  BN_CTX *c;
  code *pcVar8;
  BIGNUM *b;
  BIGNUM *a;
  
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
    uVar6 = count_leading_zeroes(iVar1);
    return uVar6 >> 5;
  }
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(param_3 + 0x40) != 0)) {
    iVar1 = BN_cmp((BIGNUM *)(param_2 + 4),(BIGNUM *)(param_3 + 4));
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = BN_cmp((BIGNUM *)(param_2 + 0x18),(BIGNUM *)(param_3 + 0x18));
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  pcVar7 = *(code **)(*param_1 + 0x84);
  pcVar8 = *(code **)(*param_1 + 0x88);
  c = (BN_CTX *)0x0;
  if ((param_4 == (BN_CTX *)0x0) && (param_4 = BN_CTX_new(), c = param_4, param_4 == (BN_CTX *)0x0))
  {
    return 0xffffffff;
  }
  BN_CTX_start(param_4);
  pBVar2 = BN_CTX_get(param_4);
  pBVar3 = BN_CTX_get(param_4);
  pBVar4 = BN_CTX_get(param_4);
  pBVar5 = BN_CTX_get(param_4);
  if (pBVar5 == (BIGNUM *)0x0) {
LAB_001235bc:
    uVar6 = 0xffffffff;
  }
  else {
    if (*(int *)(param_3 + 0x40) == 0) {
      iVar1 = (*pcVar8)(param_1,pBVar5,param_3 + 0x2c,param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar2,param_2 + 4,pBVar5,param_4), a = pBVar2, iVar1 == 0))
      goto LAB_001235bc;
    }
    else {
      a = (BIGNUM *)(param_2 + 4);
    }
    if (*(int *)(param_2 + 0x40) == 0) {
      iVar1 = (*pcVar8)(param_1,pBVar4,param_2 + 0x2c,param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar3,param_3 + 4,pBVar4,param_4), b = pBVar3, iVar1 == 0))
      goto LAB_001235bc;
    }
    else {
      b = (BIGNUM *)(param_3 + 4);
    }
    iVar1 = BN_cmp(a,b);
    if (iVar1 != 0) {
      uVar6 = 1;
      goto LAB_001235c0;
    }
    if (*(int *)(param_3 + 0x40) == 0) {
      iVar1 = (*pcVar7)(param_1,pBVar5,pBVar5,param_3 + 0x2c,param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar2,param_2 + 0x18,pBVar5,param_4), iVar1 == 0))
      goto LAB_001235bc;
    }
    else {
      a = (BIGNUM *)(param_2 + 0x18);
    }
    if (*(int *)(param_2 + 0x40) == 0) {
      iVar1 = (*pcVar7)(param_1,pBVar4,pBVar4,param_2 + 0x2c,param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar3,param_3 + 0x18,pBVar4,param_4), iVar1 == 0))
      goto LAB_001235bc;
    }
    else {
      b = (BIGNUM *)(param_3 + 0x18);
    }
    uVar6 = BN_cmp(a,b);
    if (uVar6 != 0) {
      uVar6 = 1;
    }
  }
LAB_001235c0:
  BN_CTX_end(param_4);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
    return uVar6;
  }
  return uVar6;
}

