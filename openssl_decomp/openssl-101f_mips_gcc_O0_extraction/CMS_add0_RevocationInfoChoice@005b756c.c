
CMS_RevocationInfoChoice * CMS_add0_RevocationInfoChoice(CMS_ContentInfo *cms)

{
  int iVar1;
  CMS_RevocationInfoChoice *pCVar2;
  int *piVar3;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar1 == 0x16) {
    piVar3 = (int *)(*(int *)(cms + 4) + 0x10);
  }
  else {
    if (iVar1 != 0x17) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x84,0x98,"cms_lib.c",0x201);
      return (CMS_RevocationInfoChoice *)0x0;
    }
    piVar3 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (piVar3 == (int *)0x0) {
    return (CMS_RevocationInfoChoice *)0x0;
  }
  if (*piVar3 == 0) {
    iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
    *piVar3 = iVar1;
    if (iVar1 == 0) {
      return (CMS_RevocationInfoChoice *)0x0;
    }
  }
  pCVar2 = (CMS_RevocationInfoChoice *)
           (*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_RevocationInfoChoice_it_006aa3fc);
  if (pCVar2 == (CMS_RevocationInfoChoice *)0x0) {
    return (CMS_RevocationInfoChoice *)0x0;
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(*piVar3,pCVar2);
  if (iVar1 == 0) {
    (*(code *)PTR_ASN1_item_free_006a977c)(pCVar2,PTR_CMS_RevocationInfoChoice_it_006aa3fc);
    return (CMS_RevocationInfoChoice *)0x0;
  }
  return pCVar2;
}
