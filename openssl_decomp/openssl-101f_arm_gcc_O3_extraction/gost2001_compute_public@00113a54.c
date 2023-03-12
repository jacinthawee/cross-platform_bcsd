
BIGNUM * gost2001_compute_public(EC_KEY *param_1)

{
  EC_GROUP *group;
  BN_CTX *ctx;
  BIGNUM *n;
  BIGNUM *r;
  
  group = EC_KEY_get0_group(param_1);
  if (group != (EC_GROUP *)0x0) {
    ctx = BN_CTX_new();
    BN_CTX_start(ctx);
    n = EC_KEY_get0_private_key(param_1);
    if (n == (BIGNUM *)0x0) {
      ERR_GOST_error(0x68,0x10,"gost2001.c",0x125);
      r = n;
    }
    else {
      r = (BIGNUM *)EC_POINT_new(group);
      n = (BIGNUM *)EC_POINT_mul(group,(EC_POINT *)r,n,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
      if (n == (BIGNUM *)0x0) {
        ERR_GOST_error(0x68,0x10,"gost2001.c",300);
      }
      else {
        n = (BIGNUM *)EC_KEY_set_public_key(param_1,(EC_POINT *)r);
        if (n == (BIGNUM *)0x0) {
          ERR_GOST_error(0x68,0x10,"gost2001.c",0x131);
        }
        else {
          n = (BIGNUM *)0x100;
        }
      }
    }
    BN_CTX_end(ctx);
    EC_POINT_free((EC_POINT *)r);
    BN_CTX_free(ctx);
    return n;
  }
  ERR_GOST_error(0x68,0x72,"gost2001.c",0x11e);
  return (BIGNUM *)0x0;
}

