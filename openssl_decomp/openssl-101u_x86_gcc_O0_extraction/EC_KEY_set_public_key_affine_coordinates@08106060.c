
int EC_KEY_set_public_key_affine_coordinates(EC_KEY *key,BIGNUM *x,BIGNUM *y)

{
  BN_CTX *c;
  EC_POINT *p;
  BIGNUM *x_00;
  BIGNUM *y_00;
  EC_METHOD *meth;
  int iVar1;
  EC_POINT *pEVar2;
  uint uVar3;
  
  if ((((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (x == (BIGNUM *)0x0)) ||
     (y == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,0xe5,0x43,"ec_key.c",0x178);
    return 0;
  }
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  p = EC_POINT_new(*(EC_GROUP **)(key + 4));
  if (p == (EC_POINT *)0x0) {
    BN_CTX_free(c);
    return 0;
  }
  x_00 = BN_CTX_get(c);
  y_00 = BN_CTX_get(c);
  meth = EC_GROUP_method_of(*(EC_GROUP **)(key + 4));
  iVar1 = EC_METHOD_get_field_type(meth);
  if (iVar1 == 0x197) {
    uVar3 = 0;
    iVar1 = EC_POINT_set_affine_coordinates_GF2m(*(undefined4 *)(key + 4),p,x,y,c);
    if (iVar1 == 0) goto LAB_08106119;
    iVar1 = EC_POINT_get_affine_coordinates_GF2m(*(undefined4 *)(key + 4),p,x_00,y_00,c);
  }
  else {
    iVar1 = EC_POINT_set_affine_coordinates_GFp(*(EC_GROUP **)(key + 4),p,x,y,c);
    if (iVar1 == 0) {
      uVar3 = 0;
      goto LAB_08106119;
    }
    iVar1 = EC_POINT_get_affine_coordinates_GFp(*(EC_GROUP **)(key + 4),p,x_00,y_00,c);
  }
  uVar3 = 0;
  if (iVar1 != 0) {
    iVar1 = BN_cmp(x,x_00);
    if ((iVar1 == 0) && (iVar1 = BN_cmp(y,y_00), iVar1 == 0)) {
      if (*(EC_POINT **)(key + 8) != (EC_POINT *)0x0) {
        EC_POINT_free(*(EC_POINT **)(key + 8));
      }
      uVar3 = 0;
      pEVar2 = EC_POINT_dup(p,*(EC_GROUP **)(key + 4));
      *(EC_POINT **)(key + 8) = pEVar2;
      if (pEVar2 != (EC_POINT *)0x0) {
        iVar1 = EC_KEY_check_key(key);
        uVar3 = (uint)(iVar1 != 0);
      }
    }
    else {
      uVar3 = 0;
      ERR_put_error(0x10,0xe5,0x92,"ec_key.c",0x1a4);
    }
  }
LAB_08106119:
  BN_CTX_free(c);
  EC_POINT_free(p);
  return uVar3;
}

