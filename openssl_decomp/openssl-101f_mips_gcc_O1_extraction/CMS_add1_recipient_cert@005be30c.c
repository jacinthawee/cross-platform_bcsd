
CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  code *pcVar8;
  
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar2 != 0x17) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar2 = *(int *)(cms + 4);
  if (iVar2 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_RecipientInfo_it_006aa4c8);
  if (puVar3 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x65,0x41,"cms_env.c",0xe3);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar4 = (undefined4 *)
           (*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_KeyTransRecipientInfo_it_006aa4cc);
  puVar3[1] = puVar4;
  puVar1 = PTR_X509_check_purpose_006a87e8;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar3 = 0;
    (*(code *)puVar1)(recip,0xffffffff,0xffffffff);
    iVar5 = (*(code *)PTR_X509_get_pubkey_006a8008)(recip);
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x65,0x71,"cms_env.c",0xb2);
      goto LAB_005be4bc;
    }
    (*(code *)PTR_CRYPTO_add_lock_006a9080)(&recip->references,1,3,"cms_env.c",0xb5);
    uVar6 = 2;
    if ((flags & 0x10000) == 0) {
      uVar6 = 0;
    }
    puVar4[5] = iVar5;
    puVar4[4] = recip;
    *puVar4 = uVar6;
    iVar7 = cms_set1_SignerIdentifier(puVar4[1],recip,(flags & 0x10000) != 0);
    if (iVar7 == 0) goto LAB_005be4bc;
    if ((*(int *)(iVar5 + 0xc) != 0) &&
       (pcVar8 = *(code **)(*(int *)(iVar5 + 0xc) + 0x58), pcVar8 != (code *)0x0)) {
      iVar5 = (*pcVar8)(iVar5,7,0,puVar3);
      if (iVar5 == -2) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x65,0x7d,"cms_env.c",0xd2);
        goto LAB_005be4bc;
      }
      if (iVar5 < 1) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x65,0x6f,"cms_env.c",0xd8);
        goto LAB_005be4bc;
      }
    }
    iVar2 = (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)(iVar2 + 8),puVar3);
    if (iVar2 != 0) {
      return (CMS_RecipientInfo *)puVar3;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x65,0x41,"cms_env.c",0xe3);
LAB_005be4bc:
  (*(code *)PTR_ASN1_item_free_006a977c)(puVar3,PTR_CMS_RecipientInfo_it_006aa4c8);
  return (CMS_RecipientInfo *)0x0;
}

