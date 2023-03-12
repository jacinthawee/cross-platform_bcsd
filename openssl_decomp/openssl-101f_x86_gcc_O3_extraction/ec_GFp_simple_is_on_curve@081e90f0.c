
uint ec_GFp_simple_is_on_curve(int *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  BIGNUM *m;
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  BIGNUM *r;
  BIGNUM *pBVar4;
  uint uVar5;
  BN_CTX *pBVar6;
  BIGNUM *local_30;
  BIGNUM *local_28;
  EC_POINT *local_24;
  
  iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar3 != 0) {
    return 1;
  }
  pcVar1 = *(code **)(*param_1 + 0x84);
  pcVar2 = *(code **)(*param_1 + 0x88);
  if (param_3 == (BN_CTX *)0x0) {
    param_3 = BN_CTX_new();
    if (param_3 == (BN_CTX *)0x0) {
      return 0xffffffff;
    }
    BN_CTX_start(param_3);
    r = BN_CTX_get(param_3);
    local_30 = BN_CTX_get(param_3);
    local_28 = BN_CTX_get(param_3);
    pBVar4 = BN_CTX_get(param_3);
    if ((pBVar4 == (BIGNUM *)0x0) ||
       (iVar3 = (*pcVar2)(param_1,r,param_2 + 4,param_3), pBVar6 = param_3, iVar3 == 0)) {
      uVar5 = 0xffffffff;
      BN_CTX_end(param_3);
      goto LAB_081e91e8;
    }
  }
  else {
    BN_CTX_start(param_3);
    r = BN_CTX_get(param_3);
    local_30 = BN_CTX_get(param_3);
    local_28 = BN_CTX_get(param_3);
    pBVar4 = BN_CTX_get(param_3);
    if ((pBVar4 == (BIGNUM *)0x0) || (iVar3 = (*pcVar2)(param_1,r,param_2 + 4,param_3), iVar3 == 0))
    {
      BN_CTX_end(param_3);
      return 0xffffffff;
    }
    pBVar6 = (BN_CTX *)0x0;
  }
  local_24 = param_2 + 4;
  m = (BIGNUM *)(param_1 + 0x12);
  if (*(int *)(param_2 + 0x40) == 0) {
    iVar3 = (*pcVar2)(param_1,local_30,param_2 + 0x2c,param_3);
    if (((iVar3 != 0) && (iVar3 = (*pcVar2)(param_1,local_28,local_30,param_3), iVar3 != 0)) &&
       (iVar3 = (*pcVar1)(param_1,pBVar4,local_28,local_30,param_3), iVar3 != 0)) {
      if (param_1[0x27] == 0) {
        iVar3 = (*pcVar1)(param_1,local_30,local_28,param_1 + 0x1d,param_3);
        if ((iVar3 != 0) && (iVar3 = BN_mod_add_quick(r,r,local_30,m), iVar3 != 0)) {
          iVar3 = (*pcVar1)(param_1,r,r,local_24,param_3);
          goto joined_r0x081e947a;
        }
      }
      else {
        iVar3 = BN_mod_lshift1_quick(local_30,local_28,m);
        if (((iVar3 != 0) && (iVar3 = BN_mod_add_quick(local_30,local_30,local_28,m), iVar3 != 0))
           && (iVar3 = BN_mod_sub_quick(r,r,local_30,m), iVar3 != 0)) {
          iVar3 = (*pcVar1)(param_1,r,r,local_24,param_3);
joined_r0x081e947a:
          if ((iVar3 != 0) &&
             (iVar3 = (*pcVar1)(param_1,local_30,param_1 + 0x22,pBVar4,param_3), pBVar4 = local_30,
             iVar3 != 0)) goto LAB_081e931c;
        }
      }
    }
LAB_081e91cf:
    uVar5 = 0xffffffff;
  }
  else {
    iVar3 = BN_mod_add_quick(r,r,(BIGNUM *)(param_1 + 0x1d),m);
    if ((iVar3 == 0) || (iVar3 = (*pcVar1)(param_1,r,r,local_24,param_3), iVar3 == 0))
    goto LAB_081e91cf;
    pBVar4 = (BIGNUM *)(param_1 + 0x22);
LAB_081e931c:
    iVar3 = BN_mod_add_quick(r,r,pBVar4,m);
    if ((iVar3 == 0) || (iVar3 = (*pcVar2)(param_1,local_30,param_2 + 0x18,param_3), iVar3 == 0))
    goto LAB_081e91cf;
    iVar3 = BN_ucmp(local_30,r);
    uVar5 = (uint)(iVar3 == 0);
  }
  BN_CTX_end(param_3);
  param_3 = pBVar6;
  if (pBVar6 == (BN_CTX *)0x0) {
    return uVar5;
  }
LAB_081e91e8:
  BN_CTX_free(param_3);
  return uVar5;
}

