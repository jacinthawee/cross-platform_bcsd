
undefined4 eckey_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  EC_KEY *key;
  EC_GROUP *group;
  int iVar1;
  ASN1_OBJECT *a;
  char *pcVar2;
  ASN1_OBJECT *aobj;
  uchar *penc;
  undefined4 uVar3;
  int in_GS_OFFSET;
  int local_30;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  key = *(EC_KEY **)(param_2 + 0x14);
  if ((key == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(key), group == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdf,0x7c,"ec_ameth.c",0x4a);
  }
  else {
    iVar1 = EC_GROUP_get_asn1_flag(group);
    if ((iVar1 != 0) && (iVar1 = EC_GROUP_get_curve_name(group), iVar1 != 0)) {
      a = OBJ_nid2obj(iVar1);
      iVar1 = i2o_ECPublicKey(key,(uchar **)0x0);
      if (iVar1 < 1) {
        penc = (uchar *)0x0;
      }
      else {
        penc = (uchar *)CRYPTO_malloc(iVar1,"ec_ameth.c",0x77);
        if ((penc != (uchar *)0x0) &&
           (local_24 = penc, iVar1 = i2o_ECPublicKey(key,&local_24), 0 < iVar1)) {
          local_30 = 6;
LAB_081be3b4:
          aobj = OBJ_nid2obj(0x198);
          uVar3 = 1;
          iVar1 = X509_PUBKEY_set0_param(param_1,aobj,local_30,a,penc,iVar1);
          if (iVar1 != 0) goto LAB_081be29f;
          if (local_30 != 6) goto LAB_081be281;
        }
      }
      ASN1_OBJECT_free(a);
LAB_081be28d:
      uVar3 = 0;
      if (penc != (uchar *)0x0) {
        CRYPTO_free(penc);
      }
      goto LAB_081be29f;
    }
    a = (ASN1_OBJECT *)ASN1_STRING_new();
    if (a != (ASN1_OBJECT *)0x0) {
      pcVar2 = (char *)i2d_ECParameters(key,(uchar **)&a->nid);
      a->sn = pcVar2;
      if (0 < (int)pcVar2) {
        penc = (uchar *)0x0;
        iVar1 = i2o_ECPublicKey(key,(uchar **)0x0);
        if (((0 < iVar1) &&
            (penc = (uchar *)CRYPTO_malloc(iVar1,"ec_ameth.c",0x77), penc != (uchar *)0x0)) &&
           (local_24 = penc, iVar1 = i2o_ECPublicKey(key,&local_24), 0 < iVar1)) {
          local_30 = 0x10;
          goto LAB_081be3b4;
        }
LAB_081be281:
        ASN1_STRING_free((ASN1_STRING *)a);
        goto LAB_081be28d;
      }
      ASN1_STRING_free((ASN1_STRING *)a);
      ERR_put_error(0x10,0xdf,0x10,"ec_ameth.c",0x5e);
    }
  }
  uVar3 = 0;
  ERR_put_error(0x10,0xd8,0x10,"ec_ameth.c",0x71);
LAB_081be29f:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

