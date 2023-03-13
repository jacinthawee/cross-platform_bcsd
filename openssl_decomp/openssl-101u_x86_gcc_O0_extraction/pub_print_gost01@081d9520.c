
undefined4 pub_print_gost01(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  BN_CTX *ctx;
  BIGNUM *x;
  BIGNUM *y;
  EC_KEY *pEVar1;
  EC_POINT *p;
  EC_GROUP *pEVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
    return 0;
  }
  BN_CTX_start(ctx);
  x = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  pEVar1 = (EC_KEY *)EVP_PKEY_get0(param_2);
  p = EC_KEY_get0_public_key(pEVar1);
  pEVar1 = (EC_KEY *)EVP_PKEY_get0(param_2);
  pEVar2 = EC_KEY_get0_group(pEVar1);
  iVar3 = EC_POINT_get_affine_coordinates_GFp(pEVar2,p,x,y,ctx);
  if (iVar3 != 0) {
    iVar3 = BIO_indent(param_1,param_3,0x80);
    if (iVar3 != 0) {
      BIO_printf(param_1,"Public key:\n");
      iVar3 = BIO_indent(param_1,param_3 + 3,0x80);
      if (iVar3 != 0) {
        BIO_printf(param_1,"X:");
        BN_print(param_1,x);
        BIO_printf(param_1,"\n");
        BIO_indent(param_1,param_3 + 3,0x80);
        BIO_printf(param_1,"Y:");
        BN_print(param_1,y);
        BIO_printf(param_1,"\n");
        BN_CTX_end(ctx);
        BN_CTX_free(ctx);
        pEVar1 = (EC_KEY *)EVP_PKEY_get0(param_2);
        pEVar2 = EC_KEY_get0_group(pEVar1);
        iVar3 = EC_GROUP_get_curve_name(pEVar2);
        iVar4 = BIO_indent(param_1,param_3,0x80);
        if (iVar4 != 0) {
          pcVar5 = OBJ_nid2ln(iVar3);
          BIO_printf(param_1,"Parameter set: %s\n",pcVar5);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
  BN_CTX_free(ctx);
  return 0;
}

