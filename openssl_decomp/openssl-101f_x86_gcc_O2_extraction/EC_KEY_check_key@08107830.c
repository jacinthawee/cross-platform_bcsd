
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
    ERR_put_error(0x10,0xb1,0x43,"ec_key.c",0x139);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8));
  if (iVar1 != 0) {
    ERR_put_error(0x10,0xb1,0x6a,"ec_key.c",0x13f);
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
  if (iVar1 == 0) {
    line = 0x14b;
    iVar1 = 0x6b;
  }
  else {
    group = *(EC_GROUP **)(key + 4);
    if (*(int *)(group + 0xc) == 0) {
      line = 0x152;
      iVar1 = 0x7a;
    }
    else {
      iVar1 = EC_POINT_mul(group,r,(BIGNUM *)0x0,*(EC_POINT **)(key + 8),(BIGNUM *)(group + 8),c);
      if (iVar1 == 0) {
        line = 0x157;
        iVar1 = 0x10;
      }
      else {
        iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),r);
        if (iVar1 == 0) {
          line = 0x15c;
          iVar1 = 0x82;
        }
        else {
          iVar2 = 1;
          if (*(BIGNUM **)(key + 0xc) == (BIGNUM *)0x0) goto LAB_081078df;
          iVar1 = BN_cmp(*(BIGNUM **)(key + 0xc),(BIGNUM *)(group + 8));
          if (iVar1 < 0) {
            iVar1 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,*(BIGNUM **)(key + 0xc),(EC_POINT *)0x0,
                                 (BIGNUM *)0x0,c);
            if (iVar1 == 0) {
              line = 0x16c;
              iVar1 = 0x10;
            }
            else {
              iVar1 = EC_POINT_cmp(*(EC_GROUP **)(key + 4),r,*(EC_POINT **)(key + 8),c);
              if (iVar1 == 0) goto LAB_081078df;
              line = 0x172;
              iVar1 = 0x7b;
            }
          }
          else {
            line = 0x166;
            iVar1 = 0x82;
          }
        }
      }
    }
  }
  iVar2 = 0;
  ERR_put_error(0x10,0xb1,iVar1,"ec_key.c",line);
LAB_081078df:
  BN_CTX_free(c);
  EC_POINT_free(r);
  return iVar2;
}

