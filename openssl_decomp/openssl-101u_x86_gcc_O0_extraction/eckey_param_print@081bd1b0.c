
undefined4 eckey_param_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *group;
  BN_CTX *c;
  int iVar1;
  BIGNUM *order;
  int iVar2;
  undefined4 uVar3;
  
  if (*(EC_KEY **)(param_2 + 0x14) == (EC_KEY *)0x0) {
LAB_081bd270:
    c = (BN_CTX *)0x0;
    iVar2 = 0x43;
  }
  else {
    group = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x14));
    if (group == (EC_GROUP *)0x0) goto LAB_081bd270;
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      iVar2 = 0x41;
    }
    else {
      iVar2 = 0x20;
      iVar1 = BIO_indent(param_1,param_3,0x80);
      if (iVar1 != 0) {
        order = BN_new();
        if (order != (BIGNUM *)0x0) {
          iVar2 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
          if (iVar2 == 0) {
LAB_081bd22e:
            uVar3 = 0;
            ERR_put_error(0x10,0xdd,0x20,"ec_ameth.c",0x1e5);
          }
          else {
            iVar2 = BN_num_bits(order);
            iVar2 = BIO_printf(param_1,"%s: (%d bit)\n","ECDSA-Parameters",iVar2);
            if (iVar2 < 1) goto LAB_081bd22e;
            iVar2 = ECPKParameters_print(param_1,group,param_3);
            if (iVar2 == 0) goto LAB_081bd22e;
            uVar3 = 1;
          }
          BN_free(order);
          goto LAB_081bd25a;
        }
      }
    }
  }
  uVar3 = 0;
  ERR_put_error(0x10,0xdd,iVar2,"ec_ameth.c",0x1e5);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
LAB_081bd25a:
  BN_CTX_free(c);
  return uVar3;
}

