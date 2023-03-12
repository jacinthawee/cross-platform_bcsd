
undefined4 eckey_pub_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *group;
  BIGNUM *c;
  BIGNUM *a;
  point_conversion_form_t form;
  int iVar1;
  int iVar2;
  BIGNUM *buf;
  BIGNUM *order;
  EC_KEY *key;
  undefined4 uVar3;
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if ((key == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(key), group == (EC_GROUP *)0x0)) {
    c = (BIGNUM *)0x0;
    iVar2 = 0x43;
    order = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    buf = (BIGNUM *)0x0;
  }
  else {
    c = (BIGNUM *)BN_CTX_new();
    if (c == (BIGNUM *)0x0) {
      iVar2 = 0x41;
      buf = c;
      a = c;
      order = c;
    }
    else {
      a = (BIGNUM *)EC_KEY_get0_public_key(key);
      if (a == (BIGNUM *)0x0) {
        iVar2 = 10;
      }
      else {
        form = EC_KEY_get_conv_form(key);
        a = EC_POINT_point2bn(group,(EC_POINT *)a,form,(BIGNUM *)0x0,(BN_CTX *)c);
        if (a == (BIGNUM *)0x0) {
          iVar2 = 0x10;
          buf = a;
          order = a;
          goto LAB_00104612;
        }
        iVar1 = BN_num_bits(a);
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        iVar2 = (iVar2 >> 3) + 10;
      }
      buf = (BIGNUM *)CRYPTO_malloc(iVar2,"ec_ameth.c",0x1c5);
      if (buf == (BIGNUM *)0x0) {
        iVar2 = 0x41;
        order = buf;
      }
      else {
        order = (BIGNUM *)BIO_indent(param_1,param_3,0x80);
        iVar2 = 0x20;
        if (order != (BIGNUM *)0x0) {
          order = BN_new();
          if ((order != (BIGNUM *)0x0) &&
             (iVar2 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0), iVar2 != 0)) {
            iVar2 = BN_num_bits(order);
            iVar2 = BIO_printf(param_1,"%s: (%d bit)\n","Public-Key",iVar2);
            if ((0 < iVar2) &&
               ((a == (BIGNUM *)0x0 ||
                (iVar2 = ASN1_bn_print(param_1,"pub: ",a,(uchar *)buf,param_3), iVar2 != 0)))) {
              uVar3 = 1;
              iVar2 = ECPKParameters_print(param_1,group,param_3);
              if (iVar2 != 0) goto LAB_0010462a;
            }
          }
          iVar2 = 0x20;
        }
      }
    }
  }
LAB_00104612:
  uVar3 = 0;
  ERR_put_error(0x10,0xdd,iVar2,"ec_ameth.c",0x1e5);
LAB_0010462a:
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (c != (BIGNUM *)0x0) {
    BN_CTX_free((BN_CTX *)c);
  }
  if (buf != (BIGNUM *)0x0) {
    CRYPTO_free(buf);
  }
  return uVar3;
}

