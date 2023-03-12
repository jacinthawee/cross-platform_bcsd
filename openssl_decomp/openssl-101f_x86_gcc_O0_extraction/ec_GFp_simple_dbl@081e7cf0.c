
bool ec_GFp_simple_dbl(int *param_1,int param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  BIGNUM *m;
  code *pcVar1;
  code *pcVar2;
  BIGNUM *a;
  int iVar3;
  BIGNUM *r;
  BIGNUM *pBVar4;
  BN_CTX *pBVar5;
  bool bVar6;
  BIGNUM *local_38;
  BIGNUM *local_34;
  BIGNUM *local_2c;
  EC_POINT *local_24;
  EC_POINT *local_20;
  
  iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
  if (iVar3 != 0) {
    BN_set_word((BIGNUM *)(param_2 + 0x2c),0);
    *(undefined4 *)(param_2 + 0x40) = 0;
    return true;
  }
  pcVar1 = *(code **)(*param_1 + 0x84);
  pcVar2 = *(code **)(*param_1 + 0x88);
  m = (BIGNUM *)(param_1 + 0x12);
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    if (param_4 == (BN_CTX *)0x0) {
      return false;
    }
    BN_CTX_start(param_4);
    local_38 = BN_CTX_get(param_4);
    local_34 = BN_CTX_get(param_4);
    local_2c = BN_CTX_get(param_4);
    r = BN_CTX_get(param_4);
    pBVar5 = param_4;
    if (r == (BIGNUM *)0x0) {
      bVar6 = false;
      BN_CTX_end(param_4);
      goto LAB_081e7dcc;
    }
  }
  else {
    BN_CTX_start(param_4);
    local_38 = BN_CTX_get(param_4);
    local_34 = BN_CTX_get(param_4);
    local_2c = BN_CTX_get(param_4);
    r = BN_CTX_get(param_4);
    if (r == (BIGNUM *)0x0) {
      BN_CTX_end(param_4);
      return false;
    }
    pBVar5 = (BN_CTX *)0x0;
  }
  if (*(int *)(param_3 + 0x40) == 0) {
    if (param_1[0x27] == 0) {
      iVar3 = (*pcVar2)(param_1,local_38,param_3 + 4,param_4);
      if (((iVar3 != 0) && (iVar3 = BN_mod_lshift1_quick(local_34,local_38,m), iVar3 != 0)) &&
         ((iVar3 = BN_mod_add_quick(local_38,local_38,local_34,m), iVar3 != 0 &&
          ((iVar3 = (*pcVar2)(param_1,local_34,param_3 + 0x2c,param_4), iVar3 != 0 &&
           (iVar3 = (*pcVar2)(param_1,local_34,local_34,param_4), iVar3 != 0)))))) {
        iVar3 = (*pcVar1)(param_1,local_34,local_34,param_1 + 0x1d,param_4);
        pBVar4 = local_38;
        a = local_34;
joined_r0x081e7e8e:
        if ((iVar3 != 0) && (iVar3 = BN_mod_add_quick(local_34,a,pBVar4,m), iVar3 != 0))
        goto LAB_081e7eb2;
      }
    }
    else {
      iVar3 = (*pcVar2)(param_1,local_34,param_3 + 0x2c,param_4);
      if (iVar3 != 0) {
        iVar3 = BN_mod_add_quick(local_38,(BIGNUM *)(param_3 + 4),local_34,m);
        if (((iVar3 != 0) &&
            (iVar3 = BN_mod_sub_quick(local_2c,(BIGNUM *)(param_3 + 4),local_34,m), iVar3 != 0)) &&
           (iVar3 = (*pcVar1)(param_1,local_34,local_38,local_2c,param_4), iVar3 != 0)) {
          iVar3 = BN_mod_lshift1_quick(local_38,local_34,m);
          pBVar4 = local_34;
          a = local_38;
          goto joined_r0x081e7e8e;
        }
      }
    }
LAB_081e7db6:
    bVar6 = false;
  }
  else {
    iVar3 = (*pcVar2)(param_1,local_38,param_3 + 4,param_4);
    if ((((iVar3 == 0) || (iVar3 = BN_mod_lshift1_quick(local_34,local_38,m), iVar3 == 0)) ||
        (iVar3 = BN_mod_add_quick(local_38,local_38,local_34,m), iVar3 == 0)) ||
       (iVar3 = BN_mod_add_quick(local_34,local_38,(BIGNUM *)(param_1 + 0x1d),m), iVar3 == 0))
    goto LAB_081e7db6;
LAB_081e7eb2:
    local_24 = param_3 + 4;
    if (*(int *)(param_3 + 0x40) == 0) {
      iVar3 = (*pcVar1)(param_1,local_38,param_3 + 0x18,param_3 + 0x2c,param_4);
      if (iVar3 != 0) goto LAB_081e7ee4;
      goto LAB_081e7db6;
    }
    pBVar4 = BN_copy(local_38,(BIGNUM *)(param_3 + 0x18));
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_081e7db6;
LAB_081e7ee4:
    local_20 = param_3 + 0x18;
    iVar3 = BN_mod_lshift1_quick((BIGNUM *)(param_2 + 0x2c),local_38,m);
    if (iVar3 == 0) goto LAB_081e7db6;
    *(undefined4 *)(param_2 + 0x40) = 0;
    iVar3 = (*pcVar2)(param_1,r,local_20,param_4);
    if (((iVar3 == 0) || (iVar3 = (*pcVar1)(param_1,local_2c,local_24,r,param_4), iVar3 == 0)) ||
       ((iVar3 = BN_mod_lshift_quick(local_2c,local_2c,2,m), iVar3 == 0 ||
        (iVar3 = BN_mod_lshift1_quick(local_38,local_2c,m), iVar3 == 0)))) goto LAB_081e7db6;
    pBVar4 = (BIGNUM *)(param_2 + 4);
    iVar3 = (*pcVar2)(param_1,pBVar4,local_34,param_4);
    if (((((iVar3 == 0) || (iVar3 = BN_mod_sub_quick(pBVar4,pBVar4,local_38,m), iVar3 == 0)) ||
         (iVar3 = (*pcVar2)(param_1,local_38,r,param_4), iVar3 == 0)) ||
        ((iVar3 = BN_mod_lshift_quick(r,local_38,3,m), iVar3 == 0 ||
         (iVar3 = BN_mod_sub_quick(local_38,local_2c,pBVar4,m), iVar3 == 0)))) ||
       (iVar3 = (*pcVar1)(param_1,local_38,local_34,local_38,param_4), iVar3 == 0))
    goto LAB_081e7db6;
    iVar3 = BN_mod_sub_quick((BIGNUM *)(param_2 + 0x18),local_38,r,m);
    bVar6 = iVar3 != 0;
  }
  BN_CTX_end(param_4);
  param_4 = pBVar5;
  if (pBVar5 == (BN_CTX *)0x0) {
    return bVar6;
  }
LAB_081e7dcc:
  BN_CTX_free(param_4);
  return bVar6;
}

