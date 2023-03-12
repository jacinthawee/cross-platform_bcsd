
int EC_KEY_check_key(EC_KEY *key)

{
  int iVar1;
  BN_CTX *c;
  EC_POINT *r;
  int iVar2;
  EC_GROUP *group;
  
  if (((key == (EC_KEY *)0x0) || (*(EC_GROUP **)(key + 4) == (EC_GROUP *)0x0)) ||
     (*(EC_POINT **)(key + 8) == (EC_POINT *)0x0)) {
    ERR_put_error(0x10,0xb1,0x43,"ec_key.c",0x12e);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8));
  if (iVar1 != 0) {
    ERR_put_error(0x10,0xb1,0x6a,"ec_key.c",0x133);
    return 0;
  }
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  r = EC_POINT_new(*(EC_GROUP **)(key + 4));
  if (r == (EC_POINT *)0x0) {
    BN_CTX_free(c);
    return 0;
  }
  iVar2 = EC_POINT_is_on_curve(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),c);
  if (iVar2 < 1) {
    ERR_put_error(0x10,0xb1,0x6b,"ec_key.c",0x13e);
    goto LAB_00093172;
  }
  group = *(EC_GROUP **)(key + 4);
  iVar1 = *(int *)(group + 0xc);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xb1,0x7a,"ec_key.c",0x144);
    goto LAB_00093172;
  }
  iVar1 = EC_POINT_mul(group,r,(BIGNUM *)0x0,*(EC_POINT **)(key + 8),(BIGNUM *)(group + 8),c);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xb1,0x10,"ec_key.c",0x148);
    goto LAB_00093172;
  }
  iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),r);
  iVar2 = 0x14c;
  if (iVar1 == 0) {
LAB_000931f0:
    ERR_put_error(0x10,0xb1,0x82,"ec_key.c",iVar2);
    iVar1 = 0;
  }
  else {
    if (*(BIGNUM **)(key + 0xc) != (BIGNUM *)0x0) {
      iVar1 = BN_cmp(*(BIGNUM **)(key + 0xc),(BIGNUM *)(group + 8));
      if (-1 < iVar1) {
        iVar2 = 0x155;
        goto LAB_000931f0;
      }
      iVar1 = 0;
      iVar2 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,*(BIGNUM **)(key + 0xc),(EC_POINT *)0x0,
                           (BIGNUM *)0x0,c);
      if (iVar2 == 0) {
        ERR_put_error(0x10,0xb1,0x10,"ec_key.c",0x15a);
        iVar1 = iVar2;
        goto LAB_00093172;
      }
      iVar2 = EC_POINT_cmp(*(EC_GROUP **)(key + 4),r,*(EC_POINT **)(key + 8),c);
      if (iVar2 != 0) {
        ERR_put_error(0x10,0xb1,0x7b,"ec_key.c",0x15e);
        goto LAB_00093172;
      }
    }
    iVar1 = 1;
  }
LAB_00093172:
  BN_CTX_free(c);
  EC_POINT_free(r);
  return iVar1;
}

