
undefined4 * cms_DigestedData_create(undefined4 param_1)

{
  undefined4 *a;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  a = (undefined4 *)CMS_ContentInfo_new();
  if (a == (undefined4 *)0x0) {
    a = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_DigestedData_it_006a93b0);
    if (puVar1 == (undefined4 *)0x0) {
      CMS_ContentInfo_free((CMS_ContentInfo *)a);
      return (undefined4 *)0x0;
    }
    uVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x19);
    a[1] = puVar1;
    *a = uVar2;
    *puVar1 = 0;
    puVar4 = (undefined4 *)puVar1[2];
    uVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
    uVar3 = puVar1[1];
    *puVar4 = uVar2;
    cms_DigestAlgorithm_set(uVar3,param_1);
  }
  return a;
}

