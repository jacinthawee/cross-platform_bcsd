
undefined4 eckey_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  EC_GROUP *group;
  int iVar1;
  ASN1_OBJECT *a;
  char *pcVar2;
  int iVar3;
  uchar *penc;
  ASN1_OBJECT *aobj;
  EC_KEY *key;
  uchar *local_1c;
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if ((key == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(key), group == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdf,0x7c,"ec_ameth.c",0x4a);
  }
  else {
    iVar1 = EC_GROUP_get_asn1_flag(group);
    if ((iVar1 != 0) && (iVar1 = EC_GROUP_get_curve_name(group), iVar1 != 0)) {
      a = OBJ_nid2obj(iVar1);
      iVar1 = 6;
LAB_0010613c:
      iVar3 = i2o_ECPublicKey(key,(uchar **)0x0);
      if ((iVar3 < 1) ||
         (penc = (uchar *)CRYPTO_malloc(iVar3,"ec_ameth.c",0x77), penc == (uchar *)0x0)) {
        penc = (uchar *)0x0;
      }
      else {
        local_1c = penc;
        iVar3 = i2o_ECPublicKey(key,&local_1c);
        if (0 < iVar3) {
          aobj = OBJ_nid2obj(0x198);
          iVar3 = X509_PUBKEY_set0_param(param_1,aobj,iVar1,a,penc,iVar3);
          if (iVar3 != 0) {
            return 1;
          }
        }
      }
      if (iVar1 == 6) {
        ASN1_OBJECT_free(a);
      }
      else {
        ASN1_STRING_free((ASN1_STRING *)a);
      }
      if (penc == (uchar *)0x0) {
        return 0;
      }
      CRYPTO_free(penc);
      return 0;
    }
    a = (ASN1_OBJECT *)ASN1_STRING_new();
    if (a != (ASN1_OBJECT *)0x0) {
      pcVar2 = (char *)i2d_ECParameters(key,(uchar **)&a->nid);
      a->sn = pcVar2;
      if (0 < (int)pcVar2) {
        iVar1 = 0x10;
        goto LAB_0010613c;
      }
      ASN1_STRING_free((ASN1_STRING *)a);
      ERR_put_error(0x10,0xdf,0x10,"ec_ameth.c",0x5e);
    }
  }
  ERR_put_error(0x10,0xd8,0x10,"ec_ameth.c",0x71);
  return 0;
}

