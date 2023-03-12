
undefined4 fill_GOST2001_params(EC_KEY *param_1,int param_2)

{
  BN_CTX *ctx;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  EC_GROUP *group;
  EC_POINT *p;
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
  BN_CTX_start(ctx);
  local_38 = BN_CTX_get(ctx);
  local_30 = BN_CTX_get(ctx);
  local_2c = BN_CTX_get(ctx);
  local_28 = BN_CTX_get(ctx);
  local_24[0] = BN_CTX_get(ctx);
  local_34 = BN_CTX_get(ctx);
  piVar1 = &R3410_2001_paramset;
  iVar2 = R3410_2001_paramset;
  do {
    if (iVar2 == 0) {
      uVar3 = 0;
      ERR_GOST_error(0x65,0x82,"gost2001.c",0x35);
      p = (EC_POINT *)0x0;
      group = (EC_GROUP *)0x0;
LAB_001135ec:
      EC_POINT_free(p);
      EC_GROUP_free(group);
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      return uVar3;
    }
    if (iVar2 == param_2) {
      BN_hex2bn(&local_38,(char *)piVar1[3]);
      uVar3 = 1;
      BN_hex2bn(&local_30,(char *)piVar1[1]);
      BN_hex2bn(&local_2c,(char *)piVar1[2]);
      group = EC_GROUP_new_curve_GFp(local_38,local_30,local_2c,ctx);
      p = EC_POINT_new(group);
      BN_hex2bn(&local_28,(char *)piVar1[5]);
      BN_hex2bn(local_24,(char *)piVar1[6]);
      EC_POINT_set_affine_coordinates_GFp(group,p,local_28,local_24[0],ctx);
      BN_hex2bn(&local_34,(char *)piVar1[4]);
      EC_GROUP_set_generator(group,p,local_34,(BIGNUM *)0x0);
      EC_GROUP_set_curve_name(group,*piVar1);
      EC_KEY_set_group(param_1,group);
      goto LAB_001135ec;
    }
    piVar1 = piVar1 + 7;
    iVar2 = *piVar1;
  } while( true );
}

