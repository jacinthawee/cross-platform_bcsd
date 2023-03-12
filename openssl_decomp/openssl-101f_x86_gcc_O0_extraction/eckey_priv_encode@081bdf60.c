
bool eckey_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  EC_KEY *key;
  EC_GROUP *group;
  int iVar1;
  ASN1_OBJECT *a;
  char *pcVar2;
  uint flags;
  uchar *penc;
  int iVar3;
  ASN1_OBJECT *aobj;
  int in_GS_OFFSET;
  bool bVar4;
  int local_30;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  key = *(EC_KEY **)(param_2 + 0x14);
  if (key == (EC_KEY *)0x0) {
LAB_081be0c0:
    ERR_put_error(0x10,0xdf,0x7c,"ec_ameth.c",0x4a);
LAB_081be0db:
    iVar3 = 0x144;
    iVar1 = 0x8e;
  }
  else {
    group = EC_KEY_get0_group(key);
    if (group == (EC_GROUP *)0x0) goto LAB_081be0c0;
    iVar1 = EC_GROUP_get_asn1_flag(group);
    if (iVar1 == 0) {
LAB_081bdfc4:
      a = (ASN1_OBJECT *)ASN1_STRING_new();
      if (a != (ASN1_OBJECT *)0x0) {
        pcVar2 = (char *)i2d_ECParameters(key,(uchar **)&a->nid);
        a->sn = pcVar2;
        local_30 = 0x10;
        if (0 < (int)pcVar2) goto LAB_081bdff5;
        ASN1_STRING_free((ASN1_STRING *)a);
        ERR_put_error(0x10,0xdf,0x10,"ec_ameth.c",0x5e);
      }
      goto LAB_081be0db;
    }
    iVar1 = EC_GROUP_get_curve_name(group);
    if (iVar1 == 0) goto LAB_081bdfc4;
    a = OBJ_nid2obj(iVar1);
    local_30 = 6;
LAB_081bdff5:
    flags = EC_KEY_get_enc_flags(key);
    EC_KEY_set_enc_flags(key,flags | 1);
    iVar1 = i2d_ECPrivateKey(key,(uchar **)0x0);
    if (iVar1 == 0) {
      EC_KEY_set_enc_flags(key,flags);
      iVar3 = 0x153;
      iVar1 = 0x10;
    }
    else {
      penc = (uchar *)CRYPTO_malloc(iVar1,"ec_ameth.c",0x156);
      if (penc != (uchar *)0x0) {
        local_24 = penc;
        iVar3 = i2d_ECPrivateKey(key,&local_24);
        if (iVar3 == 0) {
          EC_KEY_set_enc_flags(key,flags);
          CRYPTO_free(penc);
          ERR_put_error(0x10,0xd6,0x10,"ec_ameth.c",0x162);
        }
        EC_KEY_set_enc_flags(key,flags);
        aobj = OBJ_nid2obj(0x198);
        iVar1 = PKCS8_pkey_set0(param_1,aobj,0,local_30,a,penc,iVar1);
        bVar4 = iVar1 != 0;
        goto LAB_081be0a2;
      }
      EC_KEY_set_enc_flags(key,flags);
      iVar3 = 0x15a;
      iVar1 = 0x41;
    }
  }
  ERR_put_error(0x10,0xd6,iVar1,"ec_ameth.c",iVar3);
  bVar4 = false;
LAB_081be0a2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

