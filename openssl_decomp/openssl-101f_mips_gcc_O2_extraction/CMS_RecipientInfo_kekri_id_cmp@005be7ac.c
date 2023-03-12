
int CMS_RecipientInfo_kekri_id_cmp(CMS_RecipientInfo *ri,uchar *id,size_t idlen)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  undefined4 local_30;
  undefined4 uStack_2c;
  int iStack_24;
  int iStack_20;
  size_t local_1c;
  undefined4 local_18;
  uchar *local_14;
  undefined4 local_10;
  undefined4 *local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar9 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  local_c = puVar9;
  if (*(int *)ri == 2) {
    local_10 = 0;
    local_18 = 4;
    iVar7 = **(int **)(*(int *)(ri + 4) + 4);
    local_1c = idlen;
    local_14 = id;
    iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(&local_1c);
    pcVar10 = (char *)puVar9;
  }
  else {
    idlen = 0x7b;
    pcVar10 = "cms_env.c";
    local_30 = 0x1c0;
    iVar7 = 0x8a;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e);
    iVar2 = -2;
  }
  if (local_c == *(undefined4 **)puVar1) {
    return iVar2;
  }
  puVar9 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar9);
  if (iVar2 != 0x17) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return 0;
  }
  iVar2 = puVar9[1];
  if (iVar2 == 0) {
    return 0;
  }
  if (iVar7 == 0) {
    if (pcVar10 == &DAT_00000018) {
      iVar7 = 0x315;
    }
    else if (pcVar10 == &DAT_00000020) {
      iVar7 = 0x316;
    }
    else {
      if (pcVar10 != &SUB_00000010) {
        uVar8 = 0x76;
        uVar3 = 0x1ff;
        goto LAB_005be8fc;
      }
      iVar7 = 0x314;
    }
  }
  else {
    if ((2 < iVar7 - 0x314U) ||
       (*(undefined4 **)(CSWTCH_8 + (iVar7 - 0x314U) * 4) == (undefined4 *)0x0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,100,0x99,"cms_env.c",0x20c);
      return 0;
    }
    if ((undefined4 *)pcVar10 != *(undefined4 **)(CSWTCH_8 + (iVar7 - 0x314U) * 4)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,100,0x76,"cms_env.c",0x213);
      return 0;
    }
  }
  puVar9 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_RecipientInfo_it_006aa4c8);
  if (puVar9 == (undefined4 *)0x0) {
    uVar8 = 0x41;
    uVar3 = 0x247;
LAB_005be8fc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,100,uVar8,"cms_env.c",uVar3);
    return 0;
  }
  puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_KEKRecipientInfo_it_006aa4dc)
  ;
  puVar9[1] = puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar9 = 2;
    if (iStack_24 != 0) {
      iVar11 = puVar4[1];
      uVar3 = (*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_OtherKeyAttribute_it_006aa4e0);
      iVar6 = puVar4[1];
      *(undefined4 *)(iVar11 + 8) = uVar3;
      if (*(int *)(iVar6 + 8) == 0) goto LAB_005bea4c;
    }
    iVar2 = (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)(iVar2 + 8),puVar9);
    puVar1 = PTR_ASN1_STRING_set0_006aa260;
    if (iVar2 != 0) {
      uVar3 = *(undefined4 *)puVar4[1];
      *puVar4 = 4;
      puVar4[4] = idlen;
      puVar4[5] = pcVar10;
      (*(code *)puVar1)(uVar3,local_30,uStack_2c);
      iVar2 = puVar4[1];
      *(undefined **)(iVar2 + 4) = &_gp;
      piVar5 = *(int **)(iVar2 + 8);
      if (piVar5 != (int *)0x0) {
        *piVar5 = iStack_24;
        piVar5[1] = iStack_20;
      }
      uVar8 = puVar4[2];
      uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar7);
      (*(code *)PTR_X509_ALGOR_set0_006a9e04)(uVar8,uVar3,0xffffffff,0);
      return (int)puVar9;
    }
  }
LAB_005bea4c:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,100,0x41,"cms_env.c",0x247);
  (*(code *)PTR_ASN1_item_free_006a977c)(puVar9,PTR_CMS_RecipientInfo_it_006aa4c8);
  return 0;
}

