
int EC_GROUP_check(EC_GROUP *group,BN_CTX *ctx)

{
  BIGNUM *order;
  int iVar1;
  EC_POINT *r;
  BN_CTX *c;
  int local_20;
  
  c = (BN_CTX *)0x0;
  if ((ctx == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), c = ctx, ctx == (BN_CTX *)0x0)) {
    ERR_put_error(0x10,0xaa,0x41,"ec_check.c",0x47);
    return 0;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  if (order == (BIGNUM *)0x0) {
LAB_0810439a:
    r = (EC_POINT *)0x0;
    BN_CTX_end(ctx);
    local_20 = 0;
    if (c == (BN_CTX *)0x0) {
      return 0;
    }
  }
  else {
    iVar1 = EC_GROUP_check_discriminant(group,ctx);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0xaa,0x76,"ec_check.c",0x51);
      goto LAB_0810439a;
    }
    if (*(EC_POINT **)(group + 4) == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xaa,0x71,"ec_check.c",0x58);
      goto LAB_0810439a;
    }
    iVar1 = EC_POINT_is_on_curve(group,*(EC_POINT **)(group + 4),ctx);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0xaa,0x6b,"ec_check.c",0x5d);
      goto LAB_0810439a;
    }
    r = EC_POINT_new(group);
    if (r == (EC_POINT *)0x0) goto LAB_0810439a;
    iVar1 = EC_GROUP_get_order(group,order,ctx);
    local_20 = 0;
    if (iVar1 != 0) {
      if (order->top == 0) {
        ERR_put_error(0x10,0xaa,0x80,"ec_check.c",0x66);
      }
      else {
        iVar1 = EC_POINT_mul(group,r,order,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
        if (iVar1 != 0) {
          iVar1 = EC_POINT_is_at_infinity(group,r);
          local_20 = 1;
          if (iVar1 == 0) {
            ERR_put_error(0x10,0xaa,0x7a,"ec_check.c",0x6d);
            local_20 = 0;
          }
        }
      }
    }
    BN_CTX_end(ctx);
    if (c == (BN_CTX *)0x0) goto LAB_081043c4;
  }
  BN_CTX_free(c);
  if (r == (EC_POINT *)0x0) {
    return local_20;
  }
LAB_081043c4:
  EC_POINT_free(r);
  return local_20;
}

