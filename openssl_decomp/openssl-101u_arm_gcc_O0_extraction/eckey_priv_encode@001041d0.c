
uchar * eckey_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  EC_GROUP *group;
  int iVar1;
  ASN1_OBJECT *a;
  char *pcVar2;
  uint flags;
  int num;
  uchar *penc;
  int iVar3;
  ASN1_OBJECT *aobj;
  EC_KEY *key;
  uchar *local_2c [2];
  
  key = *(EC_KEY **)(param_2 + 0x14);
  if ((key == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(key), group == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdf,0x7c,"ec_ameth.c",0x4a);
  }
  else {
    iVar1 = EC_GROUP_get_asn1_flag(group);
    if ((iVar1 != 0) && (iVar1 = EC_GROUP_get_curve_name(group), iVar1 != 0)) {
      a = OBJ_nid2obj(iVar1);
      iVar1 = 6;
LAB_0010421c:
      flags = EC_KEY_get_enc_flags(key);
      EC_KEY_set_enc_flags(key,flags | 1);
      num = i2d_ECPrivateKey(key,(uchar **)0x0);
      if (num == 0) {
        EC_KEY_set_enc_flags(key,flags);
        ERR_put_error(0x10,0xd6,0x10,"ec_ameth.c",0x143);
        return (uchar *)0x0;
      }
      penc = (uchar *)CRYPTO_malloc(num,"ec_ameth.c",0x146);
      if (penc == (uchar *)0x0) {
        EC_KEY_set_enc_flags(key,flags);
        ERR_put_error(0x10,0xd6,0x41,"ec_ameth.c",0x149);
      }
      else {
        local_2c[0] = penc;
        iVar3 = i2d_ECPrivateKey(key,local_2c);
        if (iVar3 == 0) {
          EC_KEY_set_enc_flags(key,flags);
          CRYPTO_free(penc);
          ERR_put_error(0x10,0xd6,0x10,"ec_ameth.c",0x150);
          return (uchar *)0x0;
        }
        EC_KEY_set_enc_flags(key,flags);
        aobj = OBJ_nid2obj(0x198);
        penc = (uchar *)PKCS8_pkey_set0(param_1,aobj,0,iVar1,a,penc,num);
        if (penc != (uchar *)0x0) {
          penc = (uchar *)0x1;
        }
      }
      return penc;
    }
    a = (ASN1_OBJECT *)ASN1_STRING_new();
    if (a != (ASN1_OBJECT *)0x0) {
      pcVar2 = (char *)i2d_ECParameters(key,(uchar **)&a->nid);
      a->sn = pcVar2;
      if (0 < (int)pcVar2) {
        iVar1 = 0x10;
        goto LAB_0010421c;
      }
      ASN1_STRING_free((ASN1_STRING *)a);
      ERR_put_error(0x10,0xdf,0x10,"ec_ameth.c",0x5c);
    }
  }
  ERR_put_error(0x10,0xd6,0x8e,"ec_ameth.c",0x133);
  return (uchar *)0x0;
}

