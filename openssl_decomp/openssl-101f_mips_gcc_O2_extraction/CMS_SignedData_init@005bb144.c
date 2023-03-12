
int CMS_SignedData_init(CMS_ContentInfo *cms)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if (*(int *)(cms + 4) == 0) {
    puVar3 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_SignedData_it_006aa48c);
    *(undefined4 **)(cms + 4) = puVar3;
    puVar1 = PTR_OBJ_nid2obj_006a8240;
    if (puVar3 == (undefined4 *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x95,0x41,"cms_sd.c",0x54);
      return 0;
    }
    puVar5 = (undefined4 *)puVar3[2];
    *puVar3 = 1;
    uVar4 = (*(code *)puVar1)(0x15);
    *puVar5 = uVar4;
    puVar1 = PTR_ASN1_OBJECT_free_006a8104;
    uVar4 = *(undefined4 *)cms;
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
    (*(code *)puVar1)(uVar4);
    uVar4 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x16);
    iVar2 = *(int *)(cms + 4);
    *(undefined4 *)cms = uVar4;
  }
  else {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
    if (iVar2 != 0x16) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
      return 0;
    }
    iVar2 = *(int *)(cms + 4);
  }
  return (uint)(iVar2 != 0);
}

