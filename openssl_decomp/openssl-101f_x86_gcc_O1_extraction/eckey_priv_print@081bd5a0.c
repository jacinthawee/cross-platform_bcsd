
undefined4 eckey_priv_print(BIO *param_1,int param_2,int param_3)

{
  EC_KEY *key;
  EC_GROUP *group;
  BN_CTX *c;
  EC_POINT *pEVar1;
  point_conversion_form_t form;
  BIGNUM *a;
  int iVar2;
  BIGNUM *a_00;
  uchar *buf;
  BIGNUM *order;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if (key == (EC_KEY *)0x0) {
LAB_081bd6e0:
    c = (BN_CTX *)0x0;
    iVar4 = 0x43;
LAB_081bd6e7:
    uVar5 = 0;
    buf = (uchar *)0x0;
    ERR_put_error(0x10,0xdd,iVar4,"ec_ameth.c",0x1fe);
LAB_081bd708:
    if (c == (BN_CTX *)0x0) goto LAB_081bd718;
  }
  else {
    group = EC_KEY_get0_group(key);
    if (group == (EC_GROUP *)0x0) goto LAB_081bd6e0;
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar4 = 0x41;
      goto LAB_081bd6e7;
    }
    pEVar1 = EC_KEY_get0_public_key(key);
    form = EC_KEY_get_conv_form(key);
    a = EC_POINT_point2bn(group,pEVar1,form,(BIGNUM *)0x0,c);
    if (a == (BIGNUM *)0x0) {
      iVar4 = 0x10;
      goto LAB_081bd6e7;
    }
    iVar2 = BN_num_bits(a);
    iVar4 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar4 = iVar2 + 7;
    }
    uVar3 = iVar4 >> 3;
    a_00 = EC_KEY_get0_private_key(key);
    if (a_00 != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(a_00);
      iVar4 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar4 = iVar2 + 0xe;
      }
      if (uVar3 < (uint)(iVar4 >> 3)) {
        uVar3 = iVar4 >> 3;
      }
    }
    buf = (uchar *)CRYPTO_malloc(uVar3 + 10,"ec_ameth.c",0x1dd);
    if (buf == (uchar *)0x0) {
      order = (BIGNUM *)0x0;
      iVar4 = 0x41;
LAB_081bd69d:
      uVar5 = 0;
      ERR_put_error(0x10,0xdd,iVar4,"ec_ameth.c",0x1fe);
    }
    else {
      order = (BIGNUM *)0x0;
      iVar4 = 0x20;
      iVar2 = BIO_indent(param_1,param_3,0x80);
      if (iVar2 == 0) goto LAB_081bd69d;
      order = BN_new();
      if (order == (BIGNUM *)0x0) goto LAB_081bd69d;
      iVar2 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
      if (iVar2 == 0) goto LAB_081bd69d;
      iVar2 = BN_num_bits(order);
      iVar2 = BIO_printf(param_1,"%s: (%d bit)\n","Private-Key",iVar2);
      if (iVar2 < 1) goto LAB_081bd69d;
      if (a_00 != (BIGNUM *)0x0) {
        iVar2 = ASN1_bn_print(param_1,"priv:",a_00,buf,param_3);
        if (iVar2 == 0) goto LAB_081bd69d;
      }
      iVar4 = ASN1_bn_print(param_1,"pub: ",a,buf,param_3);
      if (iVar4 == 0) {
LAB_081bd82c:
        iVar4 = 0x20;
        goto LAB_081bd69d;
      }
      iVar4 = ECPKParameters_print(param_1,group,param_3);
      if (iVar4 == 0) goto LAB_081bd82c;
      uVar5 = 1;
    }
    BN_free(a);
    if (order != (BIGNUM *)0x0) {
      BN_free(order);
      goto LAB_081bd708;
    }
  }
  BN_CTX_free(c);
LAB_081bd718:
  if (buf != (uchar *)0x0) {
    CRYPTO_free(buf);
  }
  return uVar5;
}

