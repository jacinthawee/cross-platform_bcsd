
int ec_GFp_simple_make_affine(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BN_CTX *ctx;
  
  if ((*(int *)(param_2 + 0x40) == 0) &&
     (iVar4 = EC_POINT_is_at_infinity(param_1,param_2), iVar4 == 0)) {
    if (param_3 == (BN_CTX *)0x0) {
      ctx = BN_CTX_new();
      if (ctx == (BN_CTX *)0x0) {
        return 0;
      }
      BN_CTX_start(ctx);
      pBVar1 = BN_CTX_get(ctx);
      pBVar2 = BN_CTX_get(ctx);
      if (((pBVar2 == (BIGNUM *)0x0) ||
          (iVar3 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,pBVar1,pBVar2,ctx),
          iVar3 == 0)) ||
         (iVar3 = EC_POINT_set_affine_coordinates_GFp(param_1,param_2,pBVar1,pBVar2,ctx), iVar3 == 0
         )) {
        iVar4 = 0;
        BN_CTX_end(ctx);
        goto LAB_081e988d;
      }
      param_3 = ctx;
      if (*(int *)(param_2 + 0x40) != 0) {
        iVar4 = 1;
        BN_CTX_end(ctx);
        goto LAB_081e988d;
      }
    }
    else {
      BN_CTX_start(param_3);
      pBVar1 = BN_CTX_get(param_3);
      pBVar2 = BN_CTX_get(param_3);
      if (((pBVar2 == (BIGNUM *)0x0) ||
          (iVar3 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,pBVar1,pBVar2,param_3),
          iVar3 == 0)) ||
         (iVar3 = EC_POINT_set_affine_coordinates_GFp(param_1,param_2,pBVar1,pBVar2,param_3),
         iVar3 == 0)) {
        BN_CTX_end(param_3);
        return 0;
      }
      if (*(int *)(param_2 + 0x40) != 0) {
        BN_CTX_end(param_3);
        goto LAB_081e97c6;
      }
      ctx = (BN_CTX *)0x0;
    }
    ERR_put_error(0x10,0x66,0x44,"ecp_smpl.c",0x4d4);
    BN_CTX_end(param_3);
    if (ctx != (BN_CTX *)0x0) {
      iVar4 = 0;
LAB_081e988d:
      BN_CTX_free(ctx);
      return iVar4;
    }
  }
  else {
LAB_081e97c6:
    iVar4 = 1;
  }
  return iVar4;
}

