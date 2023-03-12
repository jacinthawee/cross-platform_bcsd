
int EC_KEY_check_key(EC_KEY *key)

{
  int iVar1;
  BN_CTX *c;
  EC_POINT *r;
  undefined4 uVar2;
  EC_GROUP *group;
  undefined4 uVar3;
  
  if (((key == (EC_KEY *)0x0) || (*(EC_GROUP **)(key + 4) == (EC_GROUP *)0x0)) ||
     (*(EC_POINT **)(key + 8) == (EC_POINT *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xb1,0x43,"ec_key.c",0x139);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8));
  if (iVar1 != 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xb1,0x6a,"ec_key.c",0x13f);
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
    uVar3 = 0x6b;
    uVar2 = 0x14b;
  }
  else {
    group = *(EC_GROUP **)(key + 4);
    if (*(int *)(group + 0xc) == 0) {
      uVar3 = 0x7a;
      uVar2 = 0x152;
    }
    else {
      iVar1 = EC_POINT_mul(group,r,(BIGNUM *)0x0,*(EC_POINT **)(key + 8),(BIGNUM *)(group + 8),c);
      if (iVar1 == 0) {
        uVar3 = 0x10;
        uVar2 = 0x157;
      }
      else {
        iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),r);
        if (iVar1 == 0) {
          uVar3 = 0x82;
          uVar2 = 0x15c;
        }
        else {
          if (*(BIGNUM **)(key + 0xc) == (BIGNUM *)0x0) {
LAB_0050bca4:
            iVar1 = 1;
            goto LAB_0050bb0c;
          }
          iVar1 = BN_cmp(*(BIGNUM **)(key + 0xc),(BIGNUM *)(group + 8));
          if (iVar1 < 0) {
            iVar1 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,*(BIGNUM **)(key + 0xc),(EC_POINT *)0x0,
                                 (BIGNUM *)0x0,c);
            if (iVar1 == 0) {
              uVar3 = 0x10;
              uVar2 = 0x16c;
            }
            else {
              iVar1 = EC_POINT_cmp(*(EC_GROUP **)(key + 4),r,*(EC_POINT **)(key + 8),c);
              if (iVar1 == 0) goto LAB_0050bca4;
              uVar3 = 0x7b;
              uVar2 = 0x172;
            }
          }
          else {
            uVar3 = 0x82;
            uVar2 = 0x166;
          }
        }
      }
    }
  }
  iVar1 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xb1,uVar3,"ec_key.c",uVar2);
LAB_0050bb0c:
  BN_CTX_free(c);
  EC_POINT_free(r);
  return iVar1;
}

