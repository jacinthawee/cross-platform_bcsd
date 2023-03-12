
undefined4 eckey_priv_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *group;
  BN_CTX *c;
  EC_POINT *pEVar1;
  point_conversion_form_t form;
  BIGNUM *a;
  int iVar2;
  BIGNUM *a_00;
  BIGNUM *buf;
  BIGNUM *order;
  int iVar3;
  EC_KEY *key;
  undefined4 uVar4;
  uint uVar5;
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if ((key == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(key), group == (EC_GROUP *)0x0)) {
    c = (BN_CTX *)0x0;
    iVar3 = 0x43;
  }
  else {
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar3 = 0x41;
    }
    else {
      pEVar1 = EC_KEY_get0_public_key(key);
      form = EC_KEY_get_conv_form(key);
      a = EC_POINT_point2bn(group,pEVar1,form,(BIGNUM *)0x0,c);
      if (a != (BIGNUM *)0x0) {
        iVar2 = BN_num_bits(a);
        iVar3 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar3 = iVar2 + 7;
        }
        a_00 = EC_KEY_get0_private_key(key);
        uVar5 = iVar3 >> 3;
        if (a_00 != (BIGNUM *)0x0) {
          iVar2 = BN_num_bits(a_00);
          iVar3 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar3 = iVar2 + 0xe;
          }
          if (uVar5 < (uint)(iVar3 >> 3)) {
            uVar5 = iVar3 >> 3;
          }
        }
        buf = (BIGNUM *)CRYPTO_malloc(uVar5 + 10,"ec_ameth.c",0x1dd);
        if (buf == (BIGNUM *)0x0) {
          iVar3 = 0x41;
          order = buf;
LAB_00105a66:
          uVar4 = 0;
          ERR_put_error(0x10,0xdd,iVar3,"ec_ameth.c",0x1fe);
        }
        else {
          order = (BIGNUM *)BIO_indent(param_1,param_3,0x80);
          iVar3 = 0x20;
          if (order == (BIGNUM *)0x0) goto LAB_00105a66;
          order = BN_new();
          if ((order == (BIGNUM *)0x0) ||
             (iVar3 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0), iVar3 == 0)) {
LAB_00105ad8:
            iVar3 = 0x20;
            goto LAB_00105a66;
          }
          iVar3 = BN_num_bits(order);
          iVar3 = BIO_printf(param_1,"%s: (%d bit)\n","Private-Key",iVar3);
          if (iVar3 < 1) goto LAB_00105ad8;
          if (a_00 != (BIGNUM *)0x0) {
            iVar3 = ASN1_bn_print(param_1,"priv:",a_00,(uchar *)buf,param_3);
            if (iVar3 == 0) goto LAB_00105ad8;
          }
          iVar3 = ASN1_bn_print(param_1,"pub: ",a,(uchar *)buf,param_3);
          if ((iVar3 == 0) || (iVar3 = ECPKParameters_print(param_1,group,param_3), iVar3 == 0))
          goto LAB_00105ad8;
          uVar4 = 1;
        }
        BN_free(a);
        if (order != (BIGNUM *)0x0) {
          BN_free(order);
        }
        goto LAB_00105a8c;
      }
      iVar3 = 0x10;
    }
  }
  uVar4 = 0;
  ERR_put_error(0x10,0xdd,iVar3,"ec_ameth.c",0x1fe);
  buf = (BIGNUM *)0x0;
LAB_00105a8c:
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  if (buf != (BIGNUM *)0x0) {
    CRYPTO_free(buf);
  }
  return uVar4;
}

