
undefined4 cms_encode_Receipt(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined *puVar7;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0xd4);
  iVar3 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)(param_1,uVar2,0xfffffffd,0x10);
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)
             (*(code *)PTR_ASN1_item_unpack_006a91d8)(iVar3,PTR_CMS_ReceiptRequest_it_006a93ec);
    if (puVar4 != (undefined4 *)0x0) {
      uVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x32);
      iVar5 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)(param_1,uVar2,0xfffffffd,6);
      if (iVar5 == 0) {
        iVar3 = 0xad;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa1,0xad,s_cms_ess_c_006721bc,0x179);
        uVar2 = 0;
      }
      else {
        local_1c = *puVar4;
        local_18 = *(undefined4 *)(param_1 + 0x14);
        iVar3 = 0;
        local_24 = 1;
        local_20 = iVar5;
        uVar2 = (*(code *)PTR_ASN1_item_pack_006a8df4)(&local_24,PTR_CMS_Receipt_it_006a93f0);
      }
      puVar7 = PTR_CMS_ReceiptRequest_it_006a93ec;
      (*(code *)PTR_ASN1_item_free_006a8658)(puVar4);
      goto LAB_005be2d8;
    }
  }
  iVar3 = 0xa8;
  puVar7 = (undefined *)0xa1;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa1,0xa8,s_cms_ess_c_006721bc,0x16f);
  uVar2 = 0;
LAB_005be2d8:
  if (local_14 == *(int **)puVar1) {
    return uVar2;
  }
  piVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*piVar6 == 3) {
    iVar5 = piVar6[1];
    *(undefined **)(iVar5 + 0x10) = puVar7;
    if ((puVar7 != (undefined *)0x0) && (iVar3 < 0)) {
      iVar3 = (*(code *)PTR_strlen_006a9a24)(puVar7);
    }
    *(int *)(iVar5 + 0x14) = iVar3;
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa8,0xb1,"cms_pwri.c",0x47);
  return 0;
}

