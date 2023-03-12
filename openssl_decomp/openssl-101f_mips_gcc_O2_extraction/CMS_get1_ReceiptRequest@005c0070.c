
undefined4 CMS_get1_ReceiptRequest(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0xd4);
  iVar2 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)(param_1,uVar1,0xfffffffd,0x10);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ASN1_item_unpack_006aa2f0)(iVar2,PTR_CMS_ReceiptRequest_it_006aa4f8);
    if (iVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else if (param_2 == (int *)0x0) {
      (*(code *)PTR_ASN1_item_free_006a977c)(iVar2,PTR_CMS_ReceiptRequest_it_006aa4f8);
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

