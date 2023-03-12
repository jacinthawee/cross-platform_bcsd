
CMS_RecipientInfo *
CMS_add0_recipient_key
          (CMS_ContentInfo *cms,int nid,uchar *key,size_t keylen,uchar *id,size_t idlen,
          ASN1_GENERALIZEDTIME *date,ASN1_OBJECT *otherTypeId,ASN1_TYPE *otherType)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  ASN1_OBJECT **ppAVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar2 != 0x17) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar2 = *(int *)(cms + 4);
  if (iVar2 == 0) {
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
        uVar8 = 0x76;
        uVar3 = 0x1e0;
        goto LAB_005bbf8c;
      }
      nid = 0x314;
    }
  }
  else {
    if ((2 < nid - 0x314U) || (*(size_t *)(CSWTCH_8 + (nid - 0x314U) * 4) == 0)) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,100,0x99,"cms_env.c",0x1ea);
      return (CMS_RecipientInfo *)0x0;
    }
    if (keylen != *(size_t *)(CSWTCH_8 + (nid - 0x314U) * 4)) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,100,0x76,"cms_env.c",0x1ef);
      return (CMS_RecipientInfo *)0x0;
    }
  }
  puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_RecipientInfo_it_006a93bc);
  if (puVar4 == (undefined4 *)0x0) {
    uVar8 = 0x41;
    uVar3 = 0x220;
LAB_005bbf8c:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,100,uVar8,"cms_env.c",uVar3);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar5 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_KEKRecipientInfo_it_006a93d0)
  ;
  puVar4[1] = puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    *puVar4 = 2;
    if (otherTypeId != (ASN1_OBJECT *)0x0) {
      iVar9 = puVar5[1];
      uVar3 = (*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_OtherKeyAttribute_it_006a93d4);
      iVar7 = puVar5[1];
      *(undefined4 *)(iVar9 + 8) = uVar3;
      if (*(int *)(iVar7 + 8) == 0) goto LAB_005bc0dc;
    }
    iVar2 = (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)(iVar2 + 8),puVar4);
    puVar1 = PTR_ASN1_STRING_set0_006a9144;
    if (iVar2 != 0) {
      uVar3 = *(undefined4 *)puVar5[1];
      *puVar5 = 4;
      puVar5[4] = key;
      puVar5[5] = keylen;
      (*(code *)puVar1)(uVar3,id,idlen);
      iVar2 = puVar5[1];
      *(ASN1_GENERALIZEDTIME **)(iVar2 + 4) = date;
      ppAVar6 = *(ASN1_OBJECT ***)(iVar2 + 8);
      if (ppAVar6 != (ASN1_OBJECT **)0x0) {
        *ppAVar6 = otherTypeId;
        ppAVar6[1] = (ASN1_OBJECT *)otherType;
      }
      uVar8 = puVar5[2];
      uVar3 = (*(code *)PTR_OBJ_nid2obj_006a7140)(nid);
      (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(uVar8,uVar3,0xffffffff,0);
      return (CMS_RecipientInfo *)puVar4;
    }
  }
LAB_005bc0dc:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,100,0x41,"cms_env.c",0x220);
  (*(code *)PTR_ASN1_item_free_006a8658)(puVar4,PTR_CMS_RecipientInfo_it_006a93bc);
  return (CMS_RecipientInfo *)0x0;
}

