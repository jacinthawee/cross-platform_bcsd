
CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  code *pcVar8;
  
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar2 != 0x17) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  piVar7 = *(int **)(cms + 4);
  if (piVar7 == (int *)0x0) {
    return (CMS_RecipientInfo *)0x0;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_RecipientInfo_it_006a93bc);
  if (puVar3 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x65,0x41,"cms_env.c",0xda);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar4 = (undefined4 *)
           (*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_KeyTransRecipientInfo_it_006a93c0);
  puVar3[1] = puVar4;
  puVar1 = PTR_X509_check_purpose_006a771c;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar3 = 0;
    (*(code *)puVar1)(recip,0xffffffff,0xffffffff);
    iVar2 = (*(code *)PTR_X509_get_pubkey_006a6f08)(recip);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x65,0x71,"cms_env.c",0xae);
      goto LAB_005bbb24;
    }
    (*(code *)PTR_CRYPTO_add_lock_006a805c)(&recip->references,1,3,"cms_env.c",0xb1);
    puVar4[5] = iVar2;
    puVar4[4] = recip;
    if ((int)(flags << 0xf) < 0) {
      iVar5 = *piVar7;
      *puVar4 = 2;
      if (iVar5 < 2) {
        *piVar7 = 2;
        uVar6 = 1;
      }
      else {
        uVar6 = 1;
      }
    }
    else {
      uVar6 = 0;
      *puVar4 = 0;
    }
    iVar5 = cms_set1_SignerIdentifier(puVar4[1],recip,uVar6);
    if (iVar5 == 0) goto LAB_005bbb24;
    if ((*(int *)(iVar2 + 0xc) != 0) &&
       (pcVar8 = *(code **)(*(int *)(iVar2 + 0xc) + 0x58), pcVar8 != (code *)0x0)) {
      iVar2 = (*pcVar8)(iVar2,7,0,puVar3);
      if (iVar2 == -2) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x65,0x7d,"cms_env.c",0xcb);
        goto LAB_005bbb24;
      }
      if (iVar2 < 1) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x65,0x6f,"cms_env.c",0xcf);
        goto LAB_005bbb24;
      }
    }
    iVar2 = (*(code *)PTR_sk_push_006a6fa8)(piVar7[2],puVar3);
    if (iVar2 != 0) {
      return (CMS_RecipientInfo *)puVar3;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x65,0x41,"cms_env.c",0xda);
LAB_005bbb24:
  (*(code *)PTR_ASN1_item_free_006a8658)(puVar3,PTR_CMS_RecipientInfo_it_006a93bc);
  return (CMS_RecipientInfo *)0x0;
}

