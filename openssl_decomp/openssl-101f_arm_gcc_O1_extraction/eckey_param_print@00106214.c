
undefined4 eckey_param_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *group;
  BN_CTX *c;
  int iVar1;
  BIGNUM *order;
  undefined4 uVar2;
  
  if ((*(EC_KEY **)(param_2 + 0x14) == (EC_KEY *)0x0) ||
     (group = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x14)), group == (EC_GROUP *)0x0)) {
    c = (BN_CTX *)0x0;
    iVar1 = 0x43;
  }
  else {
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar1 = 0x41;
    }
    else {
      iVar1 = BIO_indent(param_1,param_3,0x80);
      if ((iVar1 != 0) && (order = BN_new(), order != (BIGNUM *)0x0)) {
        iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
        if (iVar1 == 0) {
LAB_00106284:
          uVar2 = 0;
          ERR_put_error(0x10,0xdd,0x20,"ec_ameth.c",0x1fe);
        }
        else {
          iVar1 = BN_num_bits(order);
          iVar1 = BIO_printf(param_1,"%s: (%d bit)\n","ECDSA-Parameters",iVar1);
          if ((iVar1 < 1) || (iVar1 = ECPKParameters_print(param_1,group,param_3), iVar1 == 0))
          goto LAB_00106284;
          uVar2 = 1;
        }
        BN_free(order);
        goto LAB_001062a4;
      }
      iVar1 = 0x20;
    }
  }
  ERR_put_error(0x10,0xdd,iVar1,"ec_ameth.c",0x1fe);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  uVar2 = 0;
LAB_001062a4:
  BN_CTX_free(c);
  return uVar2;
}

