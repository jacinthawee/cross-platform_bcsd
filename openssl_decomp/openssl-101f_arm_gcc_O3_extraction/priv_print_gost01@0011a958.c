
undefined4 priv_print_gost01(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  BN_CTX *ctx;
  BIGNUM *y;
  EC_KEY *pEVar3;
  EC_POINT *p;
  EC_GROUP *pEVar4;
  int iVar5;
  char *pcVar6;
  BIGNUM *pBVar7;
  
  iVar1 = BIO_indent(param_1,param_3,0x80);
  if (iVar1 == 0) {
    return 0;
  }
  BIO_printf(param_1,"Private key: ");
  iVar1 = EVP_PKEY_base_id(param_2);
  if (iVar1 == 0x32b) {
    pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_2);
    if (pEVar3 != (EC_KEY *)0x0) {
      pBVar7 = EC_KEY_get0_private_key(pEVar3);
      goto joined_r0x0011ab16;
    }
  }
  else if ((iVar1 == 0x32c) && (pvVar2 = EVP_PKEY_get0(param_2), pvVar2 != (void *)0x0)) {
    pBVar7 = *(BIGNUM **)((int)pvVar2 + 0x1c);
joined_r0x0011ab16:
    if (pBVar7 != (BIGNUM *)0x0) {
      BN_print(param_1,pBVar7);
      goto LAB_0011a9b8;
    }
  }
  BIO_printf(param_1,"<undefined)");
LAB_0011a9b8:
  BIO_printf(param_1,"\n");
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
    return 0;
  }
  BN_CTX_start(ctx);
  pBVar7 = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_2);
  p = EC_KEY_get0_public_key(pEVar3);
  pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_2);
  pEVar4 = EC_KEY_get0_group(pEVar3);
  iVar1 = EC_POINT_get_affine_coordinates_GFp(pEVar4,p,pBVar7,y,ctx);
  if (iVar1 == 0) {
    ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
    BN_CTX_free(ctx);
    return 0;
  }
  iVar1 = BIO_indent(param_1,param_3,0x80);
  if (iVar1 != 0) {
    BIO_printf(param_1,"Public key:\n");
    iVar1 = BIO_indent(param_1,param_3 + 3,0x80);
    if (iVar1 != 0) {
      BIO_printf(param_1,"X:");
      BN_print(param_1,pBVar7);
      BIO_printf(param_1,"\n");
      BIO_indent(param_1,param_3 + 3,0x80);
      BIO_printf(param_1,"Y:");
      BN_print(param_1,y);
      BIO_printf(param_1,"\n");
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_2);
      pEVar4 = EC_KEY_get0_group(pEVar3);
      iVar1 = EC_GROUP_get_curve_name(pEVar4);
      iVar5 = BIO_indent(param_1,param_3,0x80);
      if (iVar5 != 0) {
        pcVar6 = OBJ_nid2ln(iVar1);
        BIO_printf(param_1,"Parameter set: %s\n",pcVar6);
        return 1;
      }
    }
  }
  return 0;
}
