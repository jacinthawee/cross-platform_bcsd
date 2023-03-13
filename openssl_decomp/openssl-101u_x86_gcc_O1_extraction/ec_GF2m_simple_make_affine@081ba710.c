
bool ec_GF2m_simple_make_affine(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *b;
  BN_CTX *ctx;
  bool bVar3;
  
  if ((*(int *)(param_2 + 0x40) == 0) &&
     (iVar1 = EC_POINT_is_at_infinity(param_1,param_2), iVar1 == 0)) {
    if (param_3 == (BN_CTX *)0x0) {
      ctx = BN_CTX_new();
      if (ctx == (BN_CTX *)0x0) {
        return false;
      }
      BN_CTX_start(ctx);
      pBVar2 = BN_CTX_get(ctx);
      b = BN_CTX_get(ctx);
      param_3 = ctx;
      if (b == (BIGNUM *)0x0) {
        bVar3 = false;
        BN_CTX_end(ctx);
        goto LAB_081ba7c2;
      }
    }
    else {
      ctx = (BN_CTX *)0x0;
      BN_CTX_start(param_3);
      pBVar2 = BN_CTX_get(param_3);
      b = BN_CTX_get(param_3);
      if (b == (BIGNUM *)0x0) {
        BN_CTX_end(param_3);
        return false;
      }
    }
    iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,pBVar2,b,param_3);
    if (((iVar1 == 0) || (pBVar2 = BN_copy((BIGNUM *)(param_2 + 4),pBVar2), pBVar2 == (BIGNUM *)0x0)
        ) || (pBVar2 = BN_copy((BIGNUM *)(param_2 + 0x18),b), pBVar2 == (BIGNUM *)0x0)) {
      bVar3 = false;
    }
    else {
      iVar1 = BN_set_word((BIGNUM *)(param_2 + 0x2c),1);
      bVar3 = iVar1 != 0;
    }
    BN_CTX_end(param_3);
    if (ctx != (BN_CTX *)0x0) {
LAB_081ba7c2:
      BN_CTX_free(ctx);
      return bVar3;
    }
  }
  else {
    bVar3 = true;
  }
  return bVar3;
}

