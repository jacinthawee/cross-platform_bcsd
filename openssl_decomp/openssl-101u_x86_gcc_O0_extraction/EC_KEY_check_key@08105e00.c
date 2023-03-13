
int EC_KEY_check_key(EC_KEY *key)

{
  EC_GROUP *group;
  int iVar1;
  BN_CTX *c;
  EC_POINT *r;
  int iVar2;
  int line;
  
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
  iVar1 = EC_POINT_is_on_curve(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),c);
  if (iVar1 < 1) {
    line = 0x13e;
    iVar1 = 0x6b;
  }
  else {
    group = *(EC_GROUP **)(key + 4);
    if (*(int *)(group + 0xc) == 0) {
      line = 0x144;
      iVar1 = 0x7a;
    }
    else {
      iVar1 = EC_POINT_mul(group,r,(BIGNUM *)0x0,*(EC_POINT **)(key + 8),(BIGNUM *)(group + 8),c);
      if (iVar1 == 0) {
        line = 0x148;
        iVar1 = 0x10;
      }
      else {
        iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),r);
        if (iVar1 == 0) {
          line = 0x14c;
          iVar1 = 0x82;
        }
        else {
          iVar2 = 1;
          if (*(BIGNUM **)(key + 0xc) == (BIGNUM *)0x0) goto LAB_08105eaf;
          iVar1 = BN_cmp(*(BIGNUM **)(key + 0xc),(BIGNUM *)(group + 8));
          if (iVar1 < 0) {
            iVar1 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,*(BIGNUM **)(key + 0xc),(EC_POINT *)0x0,
                                 (BIGNUM *)0x0,c);
            if (iVar1 == 0) {
              line = 0x15a;
              iVar1 = 0x10;
            }
            else {
              iVar1 = EC_POINT_cmp(*(EC_GROUP **)(key + 4),r,*(EC_POINT **)(key + 8),c);
              if (iVar1 == 0) goto LAB_08105eaf;
              line = 0x15e;
              iVar1 = 0x7b;
            }
          }
          else {
            line = 0x155;
            iVar1 = 0x82;
          }
        }
      }
    }
  }
  iVar2 = 0;
  ERR_put_error(0x10,0xb1,iVar1,"ec_key.c",line);
LAB_08105eaf:
  BN_CTX_free(c);
  EC_POINT_free(r);
  return iVar2;
}

