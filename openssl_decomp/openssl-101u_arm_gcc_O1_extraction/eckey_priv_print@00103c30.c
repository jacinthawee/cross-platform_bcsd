
undefined4 eckey_priv_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *group;
  BIGNUM *c;
  BIGNUM *a;
  point_conversion_form_t form;
  int iVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  BIGNUM *order;
  int iVar3;
  EC_KEY *key;
  undefined4 uVar4;
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if ((key == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(key), group == (EC_GROUP *)0x0)) {
    c = (BIGNUM *)0x0;
    iVar3 = 0x43;
    order = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    pBVar2 = (BIGNUM *)0x0;
  }
  else {
    c = (BIGNUM *)BN_CTX_new();
    if (c == (BIGNUM *)0x0) {
      iVar3 = 0x41;
      pBVar2 = c;
      a = c;
      order = c;
    }
    else {
      a = (BIGNUM *)EC_KEY_get0_public_key(key);
      pBVar2 = a;
      if (a != (BIGNUM *)0x0) {
        form = EC_KEY_get_conv_form(key);
        a = EC_POINT_point2bn(group,(EC_POINT *)a,form,(BIGNUM *)0x0,(BN_CTX *)c);
        if (a == (BIGNUM *)0x0) {
          iVar3 = 0x10;
          pBVar2 = a;
          order = a;
          goto LAB_00103cfa;
        }
        iVar1 = BN_num_bits(a);
        iVar3 = iVar1 + 0xe;
        if (-1 < iVar1 + 7) {
          iVar3 = iVar1 + 7;
        }
        pBVar2 = (BIGNUM *)(iVar3 >> 3);
      }
      a_00 = EC_KEY_get0_private_key(key);
      if (a_00 != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(a_00);
        iVar3 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar3 = iVar1 + 0xe;
        }
        if (pBVar2 < (BIGNUM *)(iVar3 >> 3)) {
          pBVar2 = (BIGNUM *)(iVar3 >> 3);
        }
      }
      pBVar2 = (BIGNUM *)CRYPTO_malloc((int)((int)&pBVar2->dmax + 2),"ec_ameth.c",0x1c5);
      if (pBVar2 == (BIGNUM *)0x0) {
        iVar3 = 0x41;
        order = pBVar2;
      }
      else {
        order = (BIGNUM *)BIO_indent(param_1,param_3,0x80);
        iVar3 = 0x20;
        if (order != (BIGNUM *)0x0) {
          order = BN_new();
          if ((order != (BIGNUM *)0x0) &&
             (iVar3 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0), iVar3 != 0)) {
            iVar3 = BN_num_bits(order);
            iVar3 = BIO_printf(param_1,"%s: (%d bit)\n","Private-Key",iVar3);
            if (((0 < iVar3) &&
                ((a_00 == (BIGNUM *)0x0 ||
                 (iVar3 = ASN1_bn_print(param_1,"priv:",a_00,(uchar *)pBVar2,param_3), iVar3 != 0)))
                ) && ((a == (BIGNUM *)0x0 ||
                      (iVar3 = ASN1_bn_print(param_1,"pub: ",a,(uchar *)pBVar2,param_3), iVar3 != 0)
                      ))) {
              uVar4 = 1;
              iVar3 = ECPKParameters_print(param_1,group,param_3);
              if (iVar3 != 0) goto LAB_00103d12;
            }
          }
          iVar3 = 0x20;
        }
      }
    }
  }
LAB_00103cfa:
  uVar4 = 0;
  ERR_put_error(0x10,0xdd,iVar3,"ec_ameth.c",0x1e5);
LAB_00103d12:
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (c != (BIGNUM *)0x0) {
    BN_CTX_free((BN_CTX *)c);
  }
  if (pBVar2 != (BIGNUM *)0x0) {
    CRYPTO_free(pBVar2);
  }
  return uVar4;
}

