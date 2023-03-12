
int EC_GROUP_check(EC_GROUP *group,BN_CTX *ctx)

{
  BIGNUM *order;
  EC_POINT *point;
  EC_POINT *pEVar1;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((ctx == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), c = ctx, ctx == (BN_CTX *)0x0)) {
    ERR_put_error(0x10,0xaa,0x41,"ec_check.c",0x47);
    return 0;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  if (order != (BIGNUM *)0x0) {
    point = (EC_POINT *)EC_GROUP_check_discriminant(group,ctx);
    if (point == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xaa,0x76,"ec_check.c",0x51);
      pEVar1 = point;
      goto LAB_00092916;
    }
    point = *(EC_POINT **)(group + 4);
    if (point == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xaa,0x71,"ec_check.c",0x58);
      pEVar1 = point;
      goto LAB_00092916;
    }
    point = (EC_POINT *)EC_POINT_is_on_curve(group,point,ctx);
    if (point == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xaa,0x6b,"ec_check.c",0x5d);
      pEVar1 = point;
      goto LAB_00092916;
    }
    point = EC_POINT_new(group);
    if (point != (EC_POINT *)0x0) {
      pEVar1 = (EC_POINT *)EC_GROUP_get_order(group,order,ctx);
      if (pEVar1 != (EC_POINT *)0x0) {
        pEVar1 = (EC_POINT *)order->top;
        if (pEVar1 == (EC_POINT *)0x0) {
          ERR_put_error(0x10,0xaa,0x80,"ec_check.c",0x66);
        }
        else {
          pEVar1 = (EC_POINT *)EC_POINT_mul(group,point,order,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
          if (pEVar1 != (EC_POINT *)0x0) {
            pEVar1 = (EC_POINT *)EC_POINT_is_at_infinity(group,point);
            if (pEVar1 == (EC_POINT *)0x0) {
              ERR_put_error(0x10,0xaa,0x7a,"ec_check.c",0x6d);
            }
            else {
              pEVar1 = (EC_POINT *)0x1;
            }
          }
        }
      }
      goto LAB_00092916;
    }
  }
  point = (EC_POINT *)0x0;
  pEVar1 = (EC_POINT *)0x0;
LAB_00092916:
  BN_CTX_end(ctx);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  if (point != (EC_POINT *)0x0) {
    EC_POINT_free(point);
  }
  return (int)pEVar1;
}

