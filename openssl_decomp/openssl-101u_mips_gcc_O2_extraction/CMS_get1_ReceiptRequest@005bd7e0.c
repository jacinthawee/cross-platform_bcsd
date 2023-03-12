
undefined4 CMS_get1_ReceiptRequest(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0xd4);
  iVar2 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)(param_1,uVar1,0xfffffffd,0x10);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ASN1_item_unpack_006a91d8)(iVar2,PTR_CMS_ReceiptRequest_it_006a93ec);
    if (iVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else if (param_2 == (int *)0x0) {
      (*(code *)PTR_ASN1_item_free_006a8658)(iVar2,PTR_CMS_ReceiptRequest_it_006a93ec);
      uVar1 = 1;
    }
    else {
      *param_2 = iVar2;
      uVar1 = 1;
    }
    return uVar1;
  }
  return 0;
}

