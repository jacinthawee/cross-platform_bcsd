
uint ec_GF2m_simple_is_on_curve(int *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  BIGNUM *pBVar4;
  EC_POINT *pEVar5;
  BN_CTX *pBVar6;
  uint uVar7;
  BIGNUM *local_28;
  
  iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar3 != 0) {
    return 1;
  }
  pcVar1 = *(code **)(*param_1 + 0x84);
  pcVar2 = *(code **)(*param_1 + 0x88);
  if (*(int *)(param_2 + 0x40) == 0) {
    return 0xffffffff;
  }
  if (param_3 == (BN_CTX *)0x0) {
    param_3 = BN_CTX_new();
    if (param_3 == (BN_CTX *)0x0) {
      return 0xffffffff;
    }
    BN_CTX_start(param_3);
    local_28 = BN_CTX_get(param_3);
    pBVar4 = BN_CTX_get(param_3);
    pBVar6 = param_3;
    if (pBVar4 == (BIGNUM *)0x0) {
      uVar7 = 0xffffffff;
      BN_CTX_end(param_3);
      goto LAB_081ba961;
    }
  }
  else {
    BN_CTX_start(param_3);
    local_28 = BN_CTX_get(param_3);
    pBVar4 = BN_CTX_get(param_3);
    pBVar6 = (BN_CTX *)0x0;
    if (pBVar4 == (BIGNUM *)0x0) {
      BN_CTX_end(param_3);
      return 0xffffffff;
    }
  }
  pEVar5 = param_2 + 4;
  iVar3 = BN_GF2m_add(pBVar4,pEVar5,param_1 + 0x1d);
  if ((iVar3 == 0) || (iVar3 = (*pcVar1)(param_1,pBVar4,pBVar4,pEVar5,param_3), iVar3 == 0)) {
LAB_081ba948:
    uVar7 = 0xffffffff;
  }
  else {
    iVar3 = BN_GF2m_add(pBVar4,pBVar4,param_2 + 0x18);
    if (((iVar3 == 0) ||
        (((iVar3 = (*pcVar1)(param_1,pBVar4,pBVar4,pEVar5,param_3), iVar3 == 0 ||
          (iVar3 = BN_GF2m_add(pBVar4,pBVar4,param_1 + 0x22), iVar3 == 0)) ||
         (iVar3 = (*pcVar2)(param_1,local_28,param_2 + 0x18,param_3), iVar3 == 0)))) ||
       (iVar3 = BN_GF2m_add(pBVar4,pBVar4,local_28,iVar3), iVar3 == 0)) goto LAB_081ba948;
    uVar7 = (uint)(pBVar4->top == 0);
  }
  BN_CTX_end(param_3);
  param_3 = pBVar6;
  if (pBVar6 == (BN_CTX *)0x0) {
    return uVar7;
  }
LAB_081ba961:
  BN_CTX_free(param_3);
  return uVar7;
}

