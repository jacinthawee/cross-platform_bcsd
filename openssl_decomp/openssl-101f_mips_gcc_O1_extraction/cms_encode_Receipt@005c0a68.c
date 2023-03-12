
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0xd4);
  iVar3 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)(param_1,uVar2,0xfffffffd,0x10);
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)
             (*(code *)PTR_ASN1_item_unpack_006aa2f0)(iVar3,PTR_CMS_ReceiptRequest_it_006aa4f8);
    if (puVar4 != (undefined4 *)0x0) {
      uVar2 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x32);
      iVar5 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)(param_1,uVar2,0xfffffffd,6);
      if (iVar5 == 0) {
        iVar3 = 0xad;
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa1,0xad,s_cms_ess_c_00672acc,0x191);
        uVar2 = 0;
      }
      else {
        local_1c = *puVar4;
        local_18 = *(undefined4 *)(param_1 + 0x14);
        iVar3 = 0;
        local_24 = 1;
        local_20 = iVar5;
        uVar2 = (*(code *)PTR_ASN1_item_pack_006a9f14)(&local_24,PTR_CMS_Receipt_it_006aa4fc);
      }
      puVar7 = PTR_CMS_ReceiptRequest_it_006aa4f8;
      (*(code *)PTR_ASN1_item_free_006a977c)(puVar4);
      goto LAB_005c0b68;
    }
  }
  iVar3 = 0xa8;
  puVar7 = (undefined *)0xa1;
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa1,0xa8,s_cms_ess_c_00672acc,0x186);
  uVar2 = 0;
LAB_005c0b68:
  if (local_14 == *(int **)puVar1) {
    return uVar2;
  }
  piVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*piVar6 == 3) {
    iVar5 = piVar6[1];
    *(undefined **)(iVar5 + 0x10) = puVar7;
    if ((puVar7 != (undefined *)0x0) && (iVar3 < 0)) {
      iVar3 = (*(code *)PTR_strlen_006aab30)(puVar7);
    }
    *(int *)(iVar5 + 0x14) = iVar3;
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa8,0xb1,"cms_pwri.c",0x47);
  return 0;
}

