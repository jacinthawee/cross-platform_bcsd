
CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *val;
  undefined4 *puVar4;
  EVP_PKEY *pEVar5;
  undefined4 uVar6;
  
  iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar3 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  piVar1 = *(int **)(cms + 4);
  if (piVar1 == (int *)0x0) {
    return (CMS_RecipientInfo *)0x0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xda);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar4 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_KeyTransRecipientInfo_it);
  val[1] = puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    *val = 0;
    X509_check_purpose(recip,-1,-1);
    pEVar5 = X509_get_pubkey(recip);
    if (pEVar5 == (EVP_PKEY *)0x0) {
      ERR_put_error(0x2e,0x65,0x71,"cms_env.c",0xae);
      goto LAB_0818fe7b;
    }
    CRYPTO_add_lock(&recip->references,1,3,"cms_env.c",0xb1);
    puVar4[5] = pEVar5;
    puVar4[4] = recip;
    if ((flags & 0x10000) == 0) {
      *puVar4 = 0;
      uVar6 = 0;
    }
    else {
      iVar3 = *piVar1;
      *puVar4 = 2;
      uVar6 = 1;
      if (iVar3 < 2) {
        *piVar1 = 2;
      }
    }
    iVar3 = cms_set1_SignerIdentifier(puVar4[1],recip,uVar6);
    if (iVar3 == 0) goto LAB_0818fe7b;
    if ((pEVar5->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar2 = *(code **)(pEVar5->ameth + 0x58), pcVar2 != (code *)0x0)) {
      iVar3 = (*pcVar2)(pEVar5,7,0,val);
      if (iVar3 == -2) {
        ERR_put_error(0x2e,0x65,0x7d,"cms_env.c",0xcb);
        goto LAB_0818fe7b;
      }
      if (iVar3 < 1) {
        ERR_put_error(0x2e,0x65,0x6f,"cms_env.c",0xcf);
        goto LAB_0818fe7b;
      }
    }
    iVar3 = sk_push((_STACK *)piVar1[2],val);
    if (iVar3 != 0) {
      return (CMS_RecipientInfo *)val;
    }
  }
  ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0xda);
LAB_0818fe7b:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

