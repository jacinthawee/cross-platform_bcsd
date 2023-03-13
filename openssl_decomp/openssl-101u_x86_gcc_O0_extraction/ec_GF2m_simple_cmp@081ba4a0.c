
uint ec_GF2m_simple_cmp(EC_GROUP *param_1,EC_POINT *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *b;
  uint uVar2;
  BN_CTX *ctx;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_20;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
    return (uint)(iVar1 == 0);
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(param_3 + 0x40) != 0)) {
    iVar1 = BN_cmp((BIGNUM *)(param_2 + 4),(BIGNUM *)(param_3 + 4));
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = BN_cmp((BIGNUM *)(param_2 + 0x18),(BIGNUM *)(param_3 + 0x18));
    return (uint)(iVar1 != 0);
  }
  if (param_4 == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    if (ctx == (BN_CTX *)0x0) {
      return 0xffffffff;
    }
    BN_CTX_start(ctx);
    local_2c = BN_CTX_get(ctx);
    local_28 = BN_CTX_get(ctx);
    local_20 = BN_CTX_get(ctx);
    b = BN_CTX_get(ctx);
    param_4 = ctx;
    if (b == (BIGNUM *)0x0) {
      uVar2 = 0xffffffff;
      BN_CTX_end(ctx);
      goto LAB_081ba573;
    }
  }
  else {
    ctx = (BN_CTX *)0x0;
    BN_CTX_start(param_4);
    local_2c = BN_CTX_get(param_4);
    local_28 = BN_CTX_get(param_4);
    local_20 = BN_CTX_get(param_4);
    b = BN_CTX_get(param_4);
    if (b == (BIGNUM *)0x0) {
      BN_CTX_end(param_4);
      return 0xffffffff;
    }
  }
  iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,local_2c,local_28,param_4);
  if ((iVar1 == 0) ||
     (iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_3,local_20,b,param_4), iVar1 == 0))
  {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 1;
    iVar1 = BN_cmp(local_2c,local_20);
    if (iVar1 == 0) {
      iVar1 = BN_cmp(local_28,b);
      uVar2 = (uint)(iVar1 != 0);
    }
  }
  BN_CTX_end(param_4);
  if (ctx == (BN_CTX *)0x0) {
    return uVar2;
  }
LAB_081ba573:
  BN_CTX_free(ctx);
  return uVar2;
}

