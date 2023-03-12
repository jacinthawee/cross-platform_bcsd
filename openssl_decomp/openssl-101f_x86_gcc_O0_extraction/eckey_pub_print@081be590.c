
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
  undefined4 local_24;
  int local_20;
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if (key == (EC_KEY *)0x0) {
LAB_081be6a0:
    c = (BN_CTX *)0x0;
    iVar3 = 0x43;
LAB_081be6a7:
    buf = (uchar *)0x0;
    ERR_put_error(0x10,0xdd,iVar3,"ec_ameth.c",0x1fe);
    local_24 = 0;
LAB_081be6ce:
    if (c == (BN_CTX *)0x0) goto LAB_081be6de;
  }
  else {
    group = EC_KEY_get0_group(key);
    if (group == (EC_GROUP *)0x0) goto LAB_081be6a0;
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar3 = 0x41;
      goto LAB_081be6a7;
    }
    pEVar1 = EC_KEY_get0_public_key(key);
    form = EC_KEY_get_conv_form(key);
    a = EC_POINT_point2bn(group,pEVar1,form,(BIGNUM *)0x0,c);
    if (a == (BIGNUM *)0x0) {
      iVar3 = 0x10;
      goto LAB_081be6a7;
    }
    iVar2 = BN_num_bits(a);
    iVar3 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar3 = iVar2 + 0xe;
    }
    buf = (uchar *)CRYPTO_malloc((iVar3 >> 3) + 10,"ec_ameth.c",0x1dd);
    if (buf == (uchar *)0x0) {
      order = (BIGNUM *)0x0;
      local_20 = 0x41;
LAB_081be65b:
      ERR_put_error(0x10,0xdd,local_20,"ec_ameth.c",0x1fe);
      local_24 = 0;
    }
    else {
      order = (BIGNUM *)0x0;
      iVar3 = BIO_indent(param_1,param_3,0x80);
      local_20 = 0x20;
      if (iVar3 == 0) goto LAB_081be65b;
      local_20 = 0x20;
      order = BN_new();
      if (order == (BIGNUM *)0x0) goto LAB_081be65b;
      iVar3 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
      local_20 = 0x20;
      if (iVar3 == 0) goto LAB_081be65b;
      iVar3 = BN_num_bits(order);
      iVar3 = BIO_printf(param_1,"%s: (%d bit)\n","Public-Key",iVar3);
      local_20 = 0x20;
      if (iVar3 < 1) goto LAB_081be65b;
      iVar3 = ASN1_bn_print(param_1,"pub: ",a,buf,param_3);
      if (iVar3 == 0) {
LAB_081be7dc:
        local_20 = 0x20;
        goto LAB_081be65b;
      }
      iVar3 = ECPKParameters_print(param_1,group,param_3);
      if (iVar3 == 0) goto LAB_081be7dc;
      local_24 = 1;
    }
    BN_free(a);
    if (order != (BIGNUM *)0x0) {
      BN_free(order);
      goto LAB_081be6ce;
    }
  }
  BN_CTX_free(c);
LAB_081be6de:
  if (buf != (uchar *)0x0) {
    CRYPTO_free(buf);
  }
  return local_24;
}

