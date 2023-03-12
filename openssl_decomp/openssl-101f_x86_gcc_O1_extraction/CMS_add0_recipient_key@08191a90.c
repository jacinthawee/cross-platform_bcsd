
CMS_RecipientInfo *
CMS_add0_recipient_key
          (CMS_ContentInfo *cms,int nid,uchar *key,size_t keylen,uchar *id,size_t idlen,
          ASN1_GENERALIZEDTIME *date,ASN1_OBJECT *otherTypeId,ASN1_TYPE *otherType)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  undefined4 *val;
  undefined4 *puVar4;
  ASN1_VALUE *pAVar5;
  ASN1_OBJECT *aobj;
  
  iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar3 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar3 = *(int *)(cms + 4);
  if (iVar3 == 0) {
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
        iVar3 = 0x1ff;
        goto LAB_08191bfd;
      }
      nid = 0x314;
    }
  }
  else {
    if ((2 < nid - 0x314U) || (*(size_t *)(CSWTCH_8 + (nid - 0x314U) * 4) == 0)) {
      ERR_put_error(0x2e,100,0x99,"cms_env.c",0x20c);
      return (CMS_RecipientInfo *)0x0;
    }
    if (keylen != *(size_t *)(CSWTCH_8 + (nid - 0x314U) * 4)) {
      iVar3 = 0x213;
LAB_08191bfd:
      ERR_put_error(0x2e,100,0x76,"cms_env.c",iVar3);
      return (CMS_RecipientInfo *)0x0;
    }
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x2e,100,0x41,"cms_env.c",0x247);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar4 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_KEKRecipientInfo_it);
  val[1] = puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    *val = 2;
    if (otherTypeId != (ASN1_OBJECT *)0x0) {
      iVar1 = puVar4[1];
      pAVar5 = ASN1_item_new((ASN1_ITEM *)CMS_OtherKeyAttribute_it);
      *(ASN1_VALUE **)(iVar1 + 8) = pAVar5;
      if (*(int *)(puVar4[1] + 8) == 0) goto LAB_08191b75;
    }
    iVar3 = sk_push(*(_STACK **)(iVar3 + 8),val);
    if (iVar3 != 0) {
      *puVar4 = 4;
      puVar4[4] = key;
      puVar4[5] = keylen;
      ASN1_STRING_set0(*(ASN1_STRING **)puVar4[1],id,idlen);
      iVar3 = puVar4[1];
      *(ASN1_GENERALIZEDTIME **)(iVar3 + 4) = date;
      ppAVar2 = *(ASN1_OBJECT ***)(iVar3 + 8);
      if (ppAVar2 != (ASN1_OBJECT **)0x0) {
        *ppAVar2 = otherTypeId;
        ppAVar2[1] = (ASN1_OBJECT *)otherType;
      }
      aobj = OBJ_nid2obj(nid);
      X509_ALGOR_set0((X509_ALGOR *)puVar4[2],aobj,-1,(void *)0x0);
      return (CMS_RecipientInfo *)val;
    }
  }
LAB_08191b75:
  ERR_put_error(0x2e,100,0x41,"cms_env.c",0x247);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

