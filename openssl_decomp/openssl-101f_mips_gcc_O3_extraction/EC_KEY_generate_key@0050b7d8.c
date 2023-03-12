
int EC_KEY_generate_key(EC_KEY *key)

{
  BIGNUM *order;
  BN_CTX *ctx;
  int iVar1;
  BIGNUM *rnd;
  uint uVar2;
  EC_POINT *r;
  
  if ((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xb3,0x43,"ec_key.c",0xfb);
    return 0;
  }
  order = BN_new();
  if (order == (BIGNUM *)0x0) {
    return 0;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    rnd = (BIGNUM *)0x0;
LAB_0050b86c:
    uVar2 = 0;
    BN_free(order);
    if (rnd == (BIGNUM *)0x0) goto LAB_0050b88c;
  }
  else {
    rnd = *(BIGNUM **)(key + 0xc);
    if (((rnd == (BIGNUM *)0x0) && (rnd = BN_new(), rnd == (BIGNUM *)0x0)) ||
       (iVar1 = EC_GROUP_get_order(*(EC_GROUP **)(key + 4),order,ctx), iVar1 == 0))
    goto LAB_0050b86c;
    do {
      iVar1 = BN_rand_range(rnd,order);
      if (iVar1 == 0) goto LAB_0050b86c;
    } while (rnd->top == 0);
    r = *(EC_POINT **)(key + 8);
    if ((r == (EC_POINT *)0x0) && (r = EC_POINT_new(*(EC_GROUP **)(key + 4)), r == (EC_POINT *)0x0))
    goto LAB_0050b86c;
    iVar1 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
    if (iVar1 != 0) {
      *(BIGNUM **)(key + 0xc) = rnd;
      *(EC_POINT **)(key + 8) = r;
      BN_free(order);
    }
    else {
      BN_free(order);
    }
    uVar2 = (uint)(iVar1 != 0);
    if (*(int *)(key + 8) == 0) {
      EC_POINT_free(r);
    }
  }
  if (*(int *)(key + 0xc) == 0) {
    BN_free(rnd);
  }
LAB_0050b88c:
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  return uVar2;
}

