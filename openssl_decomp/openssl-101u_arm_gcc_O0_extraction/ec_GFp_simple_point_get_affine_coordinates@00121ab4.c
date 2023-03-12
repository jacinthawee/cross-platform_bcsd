
BIGNUM * ec_GFp_simple_point_get_affine_coordinates
                   (int *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BN_CTX *c;
  BIGNUM *pBVar1;
  BIGNUM *ret;
  BIGNUM *r;
  BIGNUM *r_00;
  int iVar2;
  BIGNUM *n;
  
  c = (BN_CTX *)EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (c != (BN_CTX *)0x0) {
    ERR_put_error(0x10,0xa7,0x6a,"ecp_smpl.c",0x224);
    return (BIGNUM *)0x0;
  }
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return (BIGNUM *)0x0;
  }
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  ret = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  if (r_00 != (BIGNUM *)0x0) {
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      pBVar1 = (BIGNUM *)(param_2 + 0x2c);
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x94))(param_1,pBVar1,param_2 + 0x2c,param_5);
      if (iVar2 == 0) goto LAB_00121b9a;
    }
    if (((pBVar1->top == 1) && (*pBVar1->d == 1)) && (pBVar1->neg == 0)) {
      if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
        if ((param_3 != (BIGNUM *)0x0) &&
           (pBVar1 = BN_copy(param_3,(BIGNUM *)(param_2 + 4)), pBVar1 == (BIGNUM *)0x0))
        goto LAB_00121b9a;
        if (param_4 != (BIGNUM *)0x0) {
          pBVar1 = BN_copy(param_4,(BIGNUM *)(param_2 + 0x18));
          if (pBVar1 != (BIGNUM *)0x0) {
            pBVar1 = (BIGNUM *)0x1;
          }
          goto LAB_00121b9c;
        }
      }
      else {
        if ((param_3 != (BIGNUM *)0x0) &&
           (iVar2 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_2 + 4,param_5), iVar2 == 0)
           ) goto LAB_00121b9a;
        if (param_4 != (BIGNUM *)0x0) {
          pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x94))(param_1,param_4,param_2 + 0x18,param_5);
          if (pBVar1 != (BIGNUM *)0x0) {
            pBVar1 = (BIGNUM *)0x1;
          }
          goto LAB_00121b9c;
        }
      }
LAB_00121c96:
      pBVar1 = (BIGNUM *)0x1;
      goto LAB_00121b9c;
    }
    n = (BIGNUM *)(param_1 + 0x12);
    pBVar1 = BN_mod_inverse(ret,pBVar1,n,param_5);
    if (pBVar1 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0xa7,3,"ecp_smpl.c",599);
      goto LAB_00121b9c;
    }
    if (*(int *)(*param_1 + 0x90) == 0) {
      iVar2 = (**(code **)(*param_1 + 0x88))(param_1,r,ret,param_5);
    }
    else {
      iVar2 = BN_mod_sqr(r,ret,n,param_5);
    }
    if ((iVar2 != 0) &&
       ((param_3 == (BIGNUM *)0x0 ||
        (iVar2 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_2 + 4,r,param_5), iVar2 != 0))
       )) {
      if (param_4 == (BIGNUM *)0x0) goto LAB_00121c96;
      if (*(int *)(*param_1 + 0x90) == 0) {
        iVar2 = (**(code **)(*param_1 + 0x84))(param_1,r_00,r,ret);
      }
      else {
        iVar2 = BN_mod_mul(r_00,r,ret,n,param_5);
      }
      if (iVar2 != 0) {
        pBVar1 = (BIGNUM *)
                 (**(code **)(*param_1 + 0x84))(param_1,param_4,param_2 + 0x18,r_00,param_5);
        if (pBVar1 != (BIGNUM *)0x0) {
          pBVar1 = (BIGNUM *)0x1;
        }
        goto LAB_00121b9c;
      }
    }
  }
LAB_00121b9a:
  pBVar1 = (BIGNUM *)0x0;
LAB_00121b9c:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
    return pBVar1;
  }
  return pBVar1;
}

