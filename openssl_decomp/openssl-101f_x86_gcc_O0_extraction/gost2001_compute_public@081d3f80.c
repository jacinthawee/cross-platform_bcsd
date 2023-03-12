
undefined4 gost2001_compute_public(EC_KEY *param_1)

{
  EC_GROUP *group;
  BN_CTX *ctx;
  BIGNUM *n;
  EC_POINT *r;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  group = EC_KEY_get0_group(param_1);
  if (group == (EC_GROUP *)0x0) {
    ERR_GOST_error(0x68,0x72,"gost2001.c",0x11e);
    return 0;
  }
  ctx = BN_CTX_new();
  BN_CTX_start(ctx);
  n = EC_KEY_get0_private_key(param_1);
  if (n == (BIGNUM *)0x0) {
    uVar2 = 0;
    r = (EC_POINT *)0x0;
    ERR_GOST_error(0x68,0x10,"gost2001.c",0x125);
  }
  else {
    r = EC_POINT_new(group);
    iVar1 = EC_POINT_mul(group,r,n,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
    if (iVar1 == 0) {
      uVar3 = 300;
    }
    else {
      uVar2 = 0x100;
      iVar1 = EC_KEY_set_public_key(param_1,r);
      if (iVar1 != 0) goto LAB_081d3ffe;
      uVar3 = 0x131;
    }
    uVar2 = 0;
    ERR_GOST_error(0x68,0x10,"gost2001.c",uVar3);
  }
LAB_081d3ffe:
  BN_CTX_end(ctx);
  EC_POINT_free(r);
  BN_CTX_free(ctx);
  return uVar2;
}

