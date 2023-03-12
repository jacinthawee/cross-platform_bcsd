
int EC_KEY_set_public_key_affine_coordinates(EC_KEY *key,BIGNUM *x,BIGNUM *y)

{
  BN_CTX *c;
  EC_POINT *p;
  BIGNUM *b;
  BIGNUM *b_00;
  EC_METHOD *meth;
  int iVar1;
  EC_POINT *pEVar2;
  undefined4 uVar3;
  uint uVar4;
  code *pcVar5;
  
  if ((((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (x == (BIGNUM *)0x0)) ||
     (y == (BIGNUM *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xe5,0x43,"ec_key.c",0x178);
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
  b = BN_CTX_get(c);
  b_00 = BN_CTX_get(c);
  meth = EC_GROUP_method_of(*(EC_GROUP **)(key + 4));
  iVar1 = EC_METHOD_get_field_type(meth);
  if (iVar1 == 0x197) {
    iVar1 = EC_POINT_set_affine_coordinates_GF2m(*(undefined4 *)(key + 4),p,x,y,c);
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(key + 4);
      pcVar5 = (code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694;
      goto LAB_00509cf8;
    }
  }
  else {
    iVar1 = EC_POINT_set_affine_coordinates_GFp(*(EC_GROUP **)(key + 4),p,x,y,c);
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(key + 4);
      pcVar5 = (code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698;
LAB_00509cf8:
      iVar1 = (*pcVar5)(uVar3,p,b,b_00,c);
      if (iVar1 != 0) {
        iVar1 = BN_cmp(x,b);
        if (iVar1 == 0) {
          iVar1 = BN_cmp(y,b_00);
          if (iVar1 == 0) {
            if (*(EC_POINT **)(key + 8) != (EC_POINT *)0x0) {
              EC_POINT_free(*(EC_POINT **)(key + 8));
            }
            pEVar2 = EC_POINT_dup(p,*(EC_GROUP **)(key + 4));
            *(EC_POINT **)(key + 8) = pEVar2;
            if (pEVar2 != (EC_POINT *)0x0) {
              iVar1 = EC_KEY_check_key(key);
              uVar4 = (uint)(iVar1 != 0);
              goto LAB_00509bbc;
            }
            goto LAB_00509bb8;
          }
        }
        uVar4 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xe5,0x92,"ec_key.c",0x1a4);
        goto LAB_00509bbc;
      }
    }
  }
LAB_00509bb8:
  uVar4 = 0;
LAB_00509bbc:
  BN_CTX_free(c);
  EC_POINT_free(p);
  return uVar4;
}

