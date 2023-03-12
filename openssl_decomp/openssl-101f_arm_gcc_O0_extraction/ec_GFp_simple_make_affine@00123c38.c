
BN_CTX * ec_GFp_simple_make_affine(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  BIGNUM *x;
  BIGNUM *y;
  int iVar1;
  BN_CTX *pBVar2;
  BN_CTX *c;
  
  if ((*(int *)(param_2 + 0x40) == 0) &&
     (pBVar2 = (BN_CTX *)EC_POINT_is_at_infinity(param_1,param_2), pBVar2 == (BN_CTX *)0x0)) {
    c = pBVar2;
    if ((param_3 != (BN_CTX *)0x0) ||
       (param_3 = BN_CTX_new(), c = param_3, param_3 != (BN_CTX *)0x0)) {
      BN_CTX_start(param_3);
      x = BN_CTX_get(param_3);
      y = BN_CTX_get(param_3);
      if ((y == (BIGNUM *)0x0) ||
         ((iVar1 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,x,y,param_3), iVar1 == 0 ||
          (iVar1 = EC_POINT_set_affine_coordinates_GFp(param_1,param_2,x,y,param_3), iVar1 == 0))))
      {
        pBVar2 = (BN_CTX *)0x0;
      }
      else {
        pBVar2 = *(BN_CTX **)(param_2 + 0x40);
        if (pBVar2 == (BN_CTX *)0x0) {
          ERR_put_error(0x10,0x66,0x44,"ecp_smpl.c",0x48f);
        }
        else {
          pBVar2 = (BN_CTX *)0x1;
        }
      }
      BN_CTX_end(param_3);
      if (c != (BN_CTX *)0x0) {
        BN_CTX_free(c);
        return pBVar2;
      }
    }
  }
  else {
    pBVar2 = (BN_CTX *)0x1;
  }
  return pBVar2;
}

