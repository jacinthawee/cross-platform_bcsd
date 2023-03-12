
int EC_KEY_generate_key(EC_KEY *key)

{
  BIGNUM *order;
  BIGNUM *ctx;
  int iVar1;
  BIGNUM *rnd;
  EC_POINT *r;
  
  if ((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) {
    ERR_put_error(0x10,0xb3,0x43,"ec_key.c",0xfb);
    return 0;
  }
  order = BN_new();
  if (order == (BIGNUM *)0x0) {
    return 0;
  }
  ctx = (BIGNUM *)BN_CTX_new();
  rnd = ctx;
  if ((ctx != (BIGNUM *)0x0) &&
     (((rnd = *(BIGNUM **)(key + 0xc), rnd != (BIGNUM *)0x0 ||
       (rnd = BN_new(), rnd != (BIGNUM *)0x0)) &&
      (iVar1 = EC_GROUP_get_order(*(EC_GROUP **)(key + 4),order,(BN_CTX *)ctx), iVar1 != 0)))) {
    do {
      iVar1 = BN_rand_range(rnd,order);
      if (iVar1 == 0) goto LAB_000949e8;
    } while (rnd->top == 0);
    r = *(EC_POINT **)(key + 8);
    if ((r != (EC_POINT *)0x0) || (r = EC_POINT_new(*(EC_GROUP **)(key + 4)), r != (EC_POINT *)0x0))
    {
      iVar1 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,(BN_CTX *)ctx
                          );
      if (iVar1 != 0) {
        iVar1 = 1;
        *(BIGNUM **)(key + 0xc) = rnd;
        *(EC_POINT **)(key + 8) = r;
      }
      BN_free(order);
      if (*(int *)(key + 8) == 0) {
        EC_POINT_free(r);
      }
      goto LAB_000949f2;
    }
  }
LAB_000949e8:
  iVar1 = 0;
  BN_free(order);
LAB_000949f2:
  if ((rnd != (BIGNUM *)0x0) && (*(int *)(key + 0xc) == 0)) {
    BN_free(rnd);
  }
  if (ctx != (BIGNUM *)0x0) {
    BN_CTX_free((BN_CTX *)ctx);
  }
  return iVar1;
}

