
uint ec_GF2m_simple_is_on_curve(int *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  BN_CTX *c;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  EC_POINT *pEVar6;
  code *pcVar7;
  
  c = (BN_CTX *)EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (c != (BN_CTX *)0x0) {
    return 1;
  }
  pcVar7 = *(code **)(*param_1 + 0x84);
  pcVar4 = *(code **)(*param_1 + 0x88);
  if ((*(int *)(param_2 + 0x40) == 0) ||
     ((param_3 == (BN_CTX *)0x0 && (param_3 = BN_CTX_new(), c = param_3, param_3 == (BN_CTX *)0x0)))
     ) {
    return 0xffffffff;
  }
  BN_CTX_start(param_3);
  pBVar1 = BN_CTX_get(param_3);
  pBVar2 = BN_CTX_get(param_3);
  if (pBVar2 != (BIGNUM *)0x0) {
    pEVar6 = param_2 + 4;
    iVar3 = BN_GF2m_add(pBVar2,pEVar6,param_1 + 0x1d);
    if ((iVar3 != 0) && (iVar3 = (*pcVar7)(param_1,pBVar2,pBVar2,pEVar6,param_3), iVar3 != 0)) {
      iVar3 = BN_GF2m_add(pBVar2,pBVar2,param_2 + 0x18);
      if (((iVar3 != 0) &&
          (((iVar3 = (*pcVar7)(param_1,pBVar2,pBVar2,pEVar6,param_3), iVar3 != 0 &&
            (iVar3 = BN_GF2m_add(pBVar2,pBVar2,param_1 + 0x22), iVar3 != 0)) &&
           (iVar3 = (*pcVar4)(param_1,pBVar1,param_2 + 0x18,param_3), iVar3 != 0)))) &&
         (iVar3 = BN_GF2m_add(pBVar2,pBVar2,pBVar1), iVar3 != 0)) {
        uVar5 = count_leading_zeroes(pBVar2->top);
        uVar5 = uVar5 >> 5;
        goto LAB_00104bda;
      }
    }
  }
  uVar5 = 0xffffffff;
LAB_00104bda:
  BN_CTX_end(param_3);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return uVar5;
}

