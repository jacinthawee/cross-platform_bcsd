
CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  int iVar1;
  undefined4 *val;
  uint *puVar2;
  EVP_PKEY *pEVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar1 = *(int *)(cms + 4);
  if (iVar1 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xe3);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar2 = (uint *)ASN1_item_new((ASN1_ITEM *)CMS_KeyTransRecipientInfo_it);
  val[1] = puVar2;
  if (puVar2 != (uint *)0x0) {
    *val = 0;
    X509_check_purpose(recip,-1,-1);
    pEVar3 = X509_get_pubkey(recip);
    if (pEVar3 == (EVP_PKEY *)0x0) {
      ERR_put_error(0x2e,0x65,0x71,"cms_env.c",0xb2);
      goto LAB_000e84c8;
    }
    CRYPTO_add_lock(&recip->references,1,3,"cms_env.c",0xb5);
    uVar5 = flags & 0x10000;
    puVar2[5] = (uint)pEVar3;
    if (uVar5 != 0) {
      uVar5 = 2;
    }
    puVar2[4] = (uint)recip;
    *puVar2 = uVar5;
    iVar4 = cms_set1_SignerIdentifier(puVar2[1],recip);
    if (iVar4 == 0) goto LAB_000e84c8;
    if ((pEVar3->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar6 = *(code **)(pEVar3->ameth + 0x58), pcVar6 != (code *)0x0)) {
      iVar4 = (*pcVar6)(pEVar3,7,0,val);
      if (iVar4 == -2) {
        ERR_put_error(0x2e,0x65,0x7d,"cms_env.c",0xd2);
        goto LAB_000e84c8;
      }
      if (iVar4 < 1) {
        ERR_put_error(0x2e,0x65,0x6f,"cms_env.c",0xd8);
        goto LAB_000e84c8;
      }
    }
    iVar1 = sk_push(*(_STACK **)(iVar1 + 8),val);
    if (iVar1 != 0) {
      return (CMS_RecipientInfo *)val;
    }
  }
  ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xe3);
LAB_000e84c8:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

