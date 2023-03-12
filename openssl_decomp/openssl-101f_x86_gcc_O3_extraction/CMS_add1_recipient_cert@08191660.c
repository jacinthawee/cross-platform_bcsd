
CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  code *pcVar1;
  int iVar2;
  undefined4 *val;
  uint *puVar3;
  EVP_PKEY *pEVar4;
  int iVar5;
  
  iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar2 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar2 = *(int *)(cms + 4);
  if (iVar2 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xe3);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar3 = (uint *)ASN1_item_new((ASN1_ITEM *)CMS_KeyTransRecipientInfo_it);
  val[1] = puVar3;
  if (puVar3 != (uint *)0x0) {
    *val = 0;
    X509_check_purpose(recip,-1,-1);
    pEVar4 = X509_get_pubkey(recip);
    if (pEVar4 == (EVP_PKEY *)0x0) {
      ERR_put_error(0x2e,0x65,0x71,"cms_env.c",0xb2);
      goto LAB_081917b0;
    }
    CRYPTO_add_lock(&recip->references,1,3,"cms_env.c",0xb5);
    puVar3[5] = (uint)pEVar4;
    puVar3[4] = (uint)recip;
    *puVar3 = ~-(uint)((flags & 0x10000) == 0) & 2;
    iVar5 = cms_set1_SignerIdentifier(puVar3[1],recip,(flags & 0x10000) != 0);
    if (iVar5 == 0) goto LAB_081917b0;
    if ((pEVar4->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar1 = *(code **)(pEVar4->ameth + 0x58), pcVar1 != (code *)0x0)) {
      iVar5 = (*pcVar1)(pEVar4,7,0,val);
      if (iVar5 == -2) {
        ERR_put_error(0x2e,0x65,0x7d,"cms_env.c",0xd2);
        goto LAB_081917b0;
      }
      if (iVar5 < 1) {
        ERR_put_error(0x2e,0x65,0x6f,"cms_env.c",0xd8);
        goto LAB_081917b0;
      }
    }
    iVar2 = sk_push(*(_STACK **)(iVar2 + 8),val);
    if (iVar2 != 0) {
      return (CMS_RecipientInfo *)val;
    }
  }
  ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xe3);
LAB_081917b0:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

