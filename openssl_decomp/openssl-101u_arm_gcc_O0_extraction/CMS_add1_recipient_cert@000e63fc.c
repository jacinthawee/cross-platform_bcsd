
CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  int iVar1;
  undefined4 *val;
  undefined4 *puVar2;
  EVP_PKEY *pEVar3;
  uint uVar4;
  code *pcVar5;
  int *piVar6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  piVar6 = *(int **)(cms + 4);
  if (piVar6 == (int *)0x0) {
    return (CMS_RecipientInfo *)0x0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xda);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar2 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_KeyTransRecipientInfo_it);
  val[1] = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *val = 0;
    X509_check_purpose(recip,-1,-1);
    pEVar3 = X509_get_pubkey(recip);
    if (pEVar3 == (EVP_PKEY *)0x0) {
      ERR_put_error(0x2e,0x65,0x71,"cms_env.c",0xae);
      goto LAB_000e64d8;
    }
    CRYPTO_add_lock(&recip->references,1,3,"cms_env.c",0xb1);
    uVar4 = flags & 0x10000;
    puVar2[5] = pEVar3;
    puVar2[4] = recip;
    if (uVar4 == 0) {
      *puVar2 = 0;
    }
    else {
      iVar1 = *piVar6;
      *puVar2 = 2;
      uVar4 = 1;
      if (iVar1 < 2) {
        *piVar6 = 2;
      }
    }
    iVar1 = cms_set1_SignerIdentifier(puVar2[1],recip,uVar4);
    if (iVar1 == 0) goto LAB_000e64d8;
    if ((pEVar3->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar5 = *(code **)(pEVar3->ameth + 0x58), pcVar5 != (code *)0x0)) {
      iVar1 = (*pcVar5)(pEVar3,7,0,val);
      if (iVar1 == -2) {
        ERR_put_error(0x2e,0x65,0x7d,"cms_env.c",0xcb);
        goto LAB_000e64d8;
      }
      if (iVar1 < 1) {
        ERR_put_error(0x2e,0x65,0x6f,"cms_env.c",0xcf);
        goto LAB_000e64d8;
      }
    }
    iVar1 = sk_push((_STACK *)piVar6[2],val);
    if (iVar1 != 0) {
      return (CMS_RecipientInfo *)val;
    }
  }
  ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xda);
LAB_000e64d8:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

