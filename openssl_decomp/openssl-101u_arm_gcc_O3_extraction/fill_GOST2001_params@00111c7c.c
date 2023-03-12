
EC_POINT * fill_GOST2001_params(EC_KEY *param_1,int param_2)

{
  BN_CTX *ctx;
  EC_GROUP *group;
  int iVar1;
  int *piVar2;
  EC_POINT *p;
  EC_POINT *pEVar3;
  BIGNUM *local_38;
  BIGNUM *local_34;
  BIGNUM *local_30;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24 [2];
  
  local_38 = (BIGNUM *)0x0;
  local_34 = (BIGNUM *)0x0;
  local_30 = (BIGNUM *)0x0;
  local_2c = (BIGNUM *)0x0;
  local_28 = (BIGNUM *)0x0;
  local_24[0] = (BIGNUM *)0x0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x65,0x41,"gost2001.c",0x2d);
  }
  else {
    BN_CTX_start(ctx);
    local_38 = BN_CTX_get(ctx);
    local_30 = BN_CTX_get(ctx);
    local_2c = BN_CTX_get(ctx);
    local_28 = BN_CTX_get(ctx);
    local_24[0] = BN_CTX_get(ctx);
    local_34 = BN_CTX_get(ctx);
    if (((local_30 == (BIGNUM *)0x0 || local_38 == (BIGNUM *)0x0) ||
        (local_28 == (BIGNUM *)0x0 || local_2c == (BIGNUM *)0x0)) ||
       (local_34 == (BIGNUM *)0x0 || local_24[0] == (BIGNUM *)0x0)) {
      ERR_GOST_error(0x65,0x41,"gost2001.c",0x39);
    }
    else {
      piVar2 = &R3410_2001_paramset;
      iVar1 = R3410_2001_paramset;
      while (iVar1 != 0) {
        if (iVar1 == param_2) {
          iVar1 = BN_hex2bn(&local_38,(char *)piVar2[3]);
          if (((iVar1 == 0) || (iVar1 = BN_hex2bn(&local_30,(char *)piVar2[1]), iVar1 == 0)) ||
             (iVar1 = BN_hex2bn(&local_2c,(char *)piVar2[2]), iVar1 == 0)) {
            ERR_GOST_error(0x65,0x44,"gost2001.c",0x47);
            goto joined_r0x00111cfc;
          }
          group = EC_GROUP_new_curve_GFp(local_38,local_30,local_2c,ctx);
          if (group == (EC_GROUP *)0x0) {
            ERR_GOST_error(0x65,0x41,"gost2001.c",0x4d);
            goto joined_r0x00111cfc;
          }
          p = EC_POINT_new(group);
          if (p == (EC_POINT *)0x0) {
            ERR_GOST_error(0x65,0x41,"gost2001.c",0x53);
          }
          else {
            iVar1 = BN_hex2bn(&local_28,(char *)piVar2[5]);
            if (((iVar1 == 0) || (iVar1 = BN_hex2bn(local_24,(char *)piVar2[6]), iVar1 == 0)) ||
               ((iVar1 = EC_POINT_set_affine_coordinates_GFp(group,p,local_28,local_24[0],ctx),
                iVar1 == 0 || (iVar1 = BN_hex2bn(&local_34,(char *)piVar2[4]), iVar1 == 0)))) {
              pEVar3 = (EC_POINT *)0x0;
              ERR_GOST_error(0x65,0x44,"gost2001.c",0x5b);
            }
            else {
              iVar1 = EC_GROUP_set_generator(group,p,local_34,(BIGNUM *)0x0);
              if (iVar1 == 0) {
                pEVar3 = (EC_POINT *)0x0;
                ERR_GOST_error(0x65,0x44,"gost2001.c",0x66);
              }
              else {
                EC_GROUP_set_curve_name(group,*piVar2);
                pEVar3 = (EC_POINT *)EC_KEY_set_group(param_1,group);
                if (pEVar3 == (EC_POINT *)0x0) {
                  ERR_GOST_error(0x65,0x44,"gost2001.c",0x6b);
                }
                else {
                  pEVar3 = (EC_POINT *)0x1;
                }
              }
            }
            EC_POINT_free(p);
            p = pEVar3;
          }
          EC_GROUP_free(group);
          goto LAB_00111d50;
        }
        piVar2 = piVar2 + 7;
        iVar1 = *piVar2;
      }
      ERR_GOST_error(0x65,0x82,"gost2001.c",0x40);
    }
joined_r0x00111cfc:
    if (ctx != (BN_CTX *)0x0) {
      p = (EC_POINT *)0x0;
LAB_00111d50:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      return p;
    }
  }
  return (EC_POINT *)0x0;
}

