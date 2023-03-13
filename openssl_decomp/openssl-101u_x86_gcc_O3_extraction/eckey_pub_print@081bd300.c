
undefined4 eckey_pub_print(BIO *param_1,int param_2,int param_3)

{
  EC_KEY *key;
  EC_GROUP *group;
  BN_CTX *c;
  EC_POINT *pEVar1;
  point_conversion_form_t form;
  BIGNUM *a;
  int iVar2;
  uchar *buf;
  int iVar3;
  BIGNUM *order;
  undefined4 uVar4;
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if (key == (EC_KEY *)0x0) {
LAB_081bd430:
    c = (BN_CTX *)0x0;
    iVar3 = 0x43;
LAB_081bd437:
    ERR_put_error(0x10,0xdd,iVar3,"ec_ameth.c",0x1e5);
LAB_081bd454:
    uVar4 = 0;
    buf = (uchar *)0x0;
LAB_081bd458:
    if (c == (BN_CTX *)0x0) goto LAB_081bd468;
  }
  else {
    group = EC_KEY_get0_group(key);
    if (group == (EC_GROUP *)0x0) goto LAB_081bd430;
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar3 = 0x41;
      goto LAB_081bd437;
    }
    pEVar1 = EC_KEY_get0_public_key(key);
    if (pEVar1 == (EC_POINT *)0x0) {
      buf = (uchar *)CRYPTO_malloc(10,"ec_ameth.c",0x1c5);
      a = (BIGNUM *)0x0;
      if (buf != (uchar *)0x0) {
LAB_081bd3b2:
        order = (BIGNUM *)0x0;
        iVar3 = BIO_indent(param_1,param_3,0x80);
        if (iVar3 == 0) {
LAB_081bd3dc:
          uVar4 = 0;
          ERR_put_error(0x10,0xdd,0x20,"ec_ameth.c",0x1e5);
          if (a != (BIGNUM *)0x0) goto LAB_081bd408;
          goto LAB_081bd414;
        }
        order = BN_new();
        if (order == (BIGNUM *)0x0) goto LAB_081bd3dc;
        iVar3 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
        if (iVar3 == 0) goto LAB_081bd3dc;
        iVar3 = BN_num_bits(order);
        iVar3 = BIO_printf(param_1,"%s: (%d bit)\n","Public-Key",iVar3);
        if (iVar3 < 1) goto LAB_081bd3dc;
        if (a != (BIGNUM *)0x0) {
          iVar3 = ASN1_bn_print(param_1,"pub: ",a,buf,param_3);
          if (iVar3 != 0) {
            uVar4 = 1;
            iVar3 = ECPKParameters_print(param_1,group,param_3);
            if (iVar3 != 0) goto LAB_081bd408;
          }
          uVar4 = 0;
          ERR_put_error(0x10,0xdd,0x20,"ec_ameth.c",0x1e5);
          goto LAB_081bd408;
        }
        iVar3 = ECPKParameters_print(param_1,group,param_3);
        if (iVar3 == 0) {
          uVar4 = 0;
          ERR_put_error(0x10,0xdd,0x20,"ec_ameth.c",0x1e5);
        }
        else {
          uVar4 = 1;
        }
        goto LAB_081bd418;
      }
      ERR_put_error(0x10,0xdd,0x41,"ec_ameth.c",0x1e5);
      goto LAB_081bd454;
    }
    form = EC_KEY_get_conv_form(key);
    a = EC_POINT_point2bn(group,pEVar1,form,(BIGNUM *)0x0,c);
    if (a == (BIGNUM *)0x0) {
      iVar3 = 0x10;
      goto LAB_081bd437;
    }
    iVar2 = BN_num_bits(a);
    iVar3 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar3 = iVar2 + 0xe;
    }
    buf = (uchar *)CRYPTO_malloc((iVar3 >> 3) + 10,"ec_ameth.c",0x1c5);
    if (buf != (uchar *)0x0) goto LAB_081bd3b2;
    uVar4 = 0;
    order = (BIGNUM *)0x0;
    ERR_put_error(0x10,0xdd,0x41,"ec_ameth.c",0x1e5);
LAB_081bd408:
    BN_free(a);
LAB_081bd414:
    if (order != (BIGNUM *)0x0) {
LAB_081bd418:
      BN_free(order);
      goto LAB_081bd458;
    }
  }
  BN_CTX_free(c);
LAB_081bd468:
  if (buf != (uchar *)0x0) {
    CRYPTO_free(buf);
  }
  return uVar4;
}

