
bool ec_GFp_simple_point_get_affine_coordinates
               (int *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *n;
  int iVar1;
  BIGNUM *pBVar2;
  BN_CTX *pBVar3;
  bool bVar4;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24;
  
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar1 != 0) {
    ERR_put_error(0x10,0xa7,0x6a,"ecp_smpl.c",0x21a);
    return false;
  }
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    if (param_5 == (BN_CTX *)0x0) {
      return false;
    }
    BN_CTX_start(param_5);
    pBVar2 = BN_CTX_get(param_5);
    local_2c = BN_CTX_get(param_5);
    local_28 = BN_CTX_get(param_5);
    local_24 = BN_CTX_get(param_5);
    pBVar3 = param_5;
    if (local_24 == (BIGNUM *)0x0) {
      bVar4 = false;
      BN_CTX_end(param_5);
      goto LAB_081e7a86;
    }
  }
  else {
    BN_CTX_start(param_5);
    pBVar2 = BN_CTX_get(param_5);
    local_2c = BN_CTX_get(param_5);
    local_28 = BN_CTX_get(param_5);
    local_24 = BN_CTX_get(param_5);
    if (local_24 == (BIGNUM *)0x0) {
      BN_CTX_end(param_5);
      return false;
    }
    pBVar3 = (BN_CTX *)0x0;
  }
  if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
    pBVar2 = (BIGNUM *)(param_2 + 0x2c);
LAB_081e79aa:
    if (((pBVar2->top != 1) || (*pBVar2->d != 1)) || (pBVar2->neg != 0)) {
      n = (BIGNUM *)(param_1 + 0x12);
      pBVar2 = BN_mod_inverse(local_2c,pBVar2,n,param_5);
      if (pBVar2 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0xa7,3,"ecp_smpl.c",0x255);
      }
      else {
        if (*(int *)(*param_1 + 0x90) == 0) {
          iVar1 = (**(code **)(*param_1 + 0x88))(param_1,local_28,local_2c,param_5);
        }
        else {
          iVar1 = BN_mod_sqr(local_28,local_2c,n,param_5);
        }
        if ((iVar1 != 0) &&
           ((param_3 == (BIGNUM *)0x0 ||
            (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_2 + 4,local_28,param_5),
            iVar1 != 0)))) {
          if (param_4 == (BIGNUM *)0x0) goto LAB_081e7c88;
          if (*(int *)(*param_1 + 0x90) == 0) {
            iVar1 = (**(code **)(*param_1 + 0x84))(param_1,local_24,local_28,local_2c,param_5);
          }
          else {
            iVar1 = BN_mod_mul(local_24,local_28,local_2c,n,param_5);
          }
          if (iVar1 != 0) {
            iVar1 = (**(code **)(*param_1 + 0x84))(param_1,param_4,param_2 + 0x18,local_24,param_5);
            bVar4 = iVar1 != 0;
            goto LAB_081e7a72;
          }
        }
      }
      goto LAB_081e7a70;
    }
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      if ((param_3 != (BIGNUM *)0x0) &&
         (pBVar2 = BN_copy(param_3,(BIGNUM *)(param_2 + 4)), pBVar2 == (BIGNUM *)0x0))
      goto LAB_081e7a70;
      if (param_4 == (BIGNUM *)0x0) goto LAB_081e7c88;
      pBVar2 = BN_copy(param_4,(BIGNUM *)(param_2 + 0x18));
LAB_081e7b40:
      bVar4 = pBVar2 != (BIGNUM *)0x0;
    }
    else {
      if ((param_3 != (BIGNUM *)0x0) &&
         (iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_2 + 4,param_5), iVar1 == 0))
      goto LAB_081e7a70;
      if (param_4 != (BIGNUM *)0x0) {
        pBVar2 = (BIGNUM *)(**(code **)(*param_1 + 0x94))(param_1,param_4,param_2 + 0x18,param_5);
        goto LAB_081e7b40;
      }
LAB_081e7c88:
      bVar4 = true;
    }
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x94))(param_1,pBVar2,param_2 + 0x2c,param_5);
    if (iVar1 != 0) goto LAB_081e79aa;
LAB_081e7a70:
    bVar4 = false;
  }
LAB_081e7a72:
  BN_CTX_end(param_5);
  param_5 = pBVar3;
  if (pBVar3 == (BN_CTX *)0x0) {
    return bVar4;
  }
LAB_081e7a86:
  BN_CTX_free(param_5);
  return bVar4;
}

