
CMS_RecipientInfo *
CMS_add0_recipient_key
          (CMS_ContentInfo *cms,int nid,uchar *key,size_t keylen,uchar *id,size_t idlen,
          ASN1_GENERALIZEDTIME *date,ASN1_OBJECT *otherTypeId,ASN1_TYPE *otherType)

{
  int iVar1;
  undefined4 *val;
  undefined4 *puVar2;
  ASN1_VALUE *pAVar3;
  ASN1_STRING *str;
  ASN1_OBJECT *aobj;
  int iVar4;
  ASN1_OBJECT **ppAVar5;
  X509_ALGOR *alg;
  int iVar6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar1 = *(int *)(cms + 4);
  if (iVar1 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  if (nid == 0) {
    if (keylen == 0x18) {
      nid = 0x315;
    }
    else if (keylen == 0x20) {
      nid = 0x316;
    }
    else {
      if (keylen != 0x10) {
        iVar1 = 0x1e0;
        goto LAB_000e66d0;
      }
      nid = 0x314;
    }
  }
  else {
    if ((2 < nid - 0x314U) || (*(size_t *)(&CSWTCH_8 + (nid - 0x314U) * 4) == 0)) {
      ERR_put_error(0x2e,100,0x99,"cms_env.c",0x1ea);
      return (CMS_RecipientInfo *)0x0;
    }
    if (keylen != *(size_t *)(&CSWTCH_8 + (nid - 0x314U) * 4)) {
      iVar1 = 0x1ef;
LAB_000e66d0:
      ERR_put_error(0x2e,100,0x76,"cms_env.c",iVar1);
      return (CMS_RecipientInfo *)0x0;
    }
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x2e,100,0x41,"cms_env.c",0x220);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar2 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_KEKRecipientInfo_it);
  val[1] = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *val = 2;
    if (otherTypeId != (ASN1_OBJECT *)0x0) {
      iVar6 = puVar2[1];
      pAVar3 = ASN1_item_new((ASN1_ITEM *)CMS_OtherKeyAttribute_it);
      iVar4 = puVar2[1];
      *(ASN1_VALUE **)(iVar6 + 8) = pAVar3;
      if (*(int *)(iVar4 + 8) == 0) goto LAB_000e677e;
    }
    iVar1 = sk_push(*(_STACK **)(iVar1 + 8),val);
    if (iVar1 != 0) {
      str = *(ASN1_STRING **)puVar2[1];
      puVar2[4] = key;
      *puVar2 = 4;
      puVar2[5] = keylen;
      ASN1_STRING_set0(str,id,idlen);
      ppAVar5 = *(ASN1_OBJECT ***)(puVar2[1] + 8);
      *(ASN1_GENERALIZEDTIME **)(puVar2[1] + 4) = date;
      if (ppAVar5 != (ASN1_OBJECT **)0x0) {
        *ppAVar5 = otherTypeId;
        ppAVar5[1] = (ASN1_OBJECT *)otherType;
      }
      alg = (X509_ALGOR *)puVar2[2];
      aobj = OBJ_nid2obj(nid);
      X509_ALGOR_set0(alg,aobj,-1,(void *)0x0);
      return (CMS_RecipientInfo *)val;
    }
  }
LAB_000e677e:
  ERR_put_error(0x2e,100,0x41,"cms_env.c",0x220);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

