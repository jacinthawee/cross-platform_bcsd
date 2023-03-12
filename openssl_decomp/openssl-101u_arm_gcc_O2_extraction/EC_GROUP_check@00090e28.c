
int EC_GROUP_check(EC_GROUP *group,BN_CTX *ctx)

{
  BIGNUM *order;
  EC_POINT *point;
  int iVar1;
  EC_POINT *pEVar2;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((ctx == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), c = ctx, ctx == (BN_CTX *)0x0)) {
    ERR_put_error(0x10,0xaa,0x41,"ec_check.c",0x45);
    return 0;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  if (order != (BIGNUM *)0x0) {
    point = (EC_POINT *)EC_GROUP_check_discriminant(group,ctx);
    if (point == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xaa,0x76,"ec_check.c",0x4f);
      pEVar2 = point;
      goto LAB_00090eba;
    }
    point = *(EC_POINT **)(group + 4);
    if (point == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xaa,0x71,"ec_check.c",0x55);
      pEVar2 = point;
      goto LAB_00090eba;
    }
    iVar1 = EC_POINT_is_on_curve(group,point,ctx);
    if (iVar1 < 1) {
      point = (EC_POINT *)0x0;
      ERR_put_error(0x10,0xaa,0x6b,"ec_check.c",0x59);
      pEVar2 = (EC_POINT *)0x0;
      goto LAB_00090eba;
    }
    point = EC_POINT_new(group);
    if (point != (EC_POINT *)0x0) {
      pEVar2 = (EC_POINT *)EC_GROUP_get_order(group,order,ctx);
      if (pEVar2 != (EC_POINT *)0x0) {
        pEVar2 = (EC_POINT *)order->top;
        if (pEVar2 == (EC_POINT *)0x0) {
          ERR_put_error(0x10,0xaa,0x80,"ec_check.c",99);
        }
        else {
          pEVar2 = (EC_POINT *)EC_POINT_mul(group,point,order,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
          if (pEVar2 != (EC_POINT *)0x0) {
            pEVar2 = (EC_POINT *)EC_POINT_is_at_infinity(group,point);
            if (pEVar2 == (EC_POINT *)0x0) {
              ERR_put_error(0x10,0xaa,0x7a,"ec_check.c",0x6a);
            }
            else {
              pEVar2 = (EC_POINT *)0x1;
            }
          }
        }
      }
      goto LAB_00090eba;
    }
  }
  point = (EC_POINT *)0x0;
  pEVar2 = (EC_POINT *)0x0;
LAB_00090eba:
  BN_CTX_end(ctx);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  if (point != (EC_POINT *)0x0) {
    EC_POINT_free(point);
  }
  return (int)pEVar2;
}

