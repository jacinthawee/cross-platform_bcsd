
int CMS_set1_eContentType(CMS_ContentInfo *cms,ASN1_OBJECT *oid)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar1 == 0x19) {
LAB_005b41ac:
    piVar2 = *(int **)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_005b41ac;
      if (iVar1 != 0x17) {
LAB_005b410c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x82,0x98,"cms_lib.c",0x10c);
        return 0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        piVar2 = *(int **)(*(int *)(cms + 4) + 0x14);
        goto LAB_005b4160;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_005b410c;
        piVar2 = *(int **)(*(int *)(cms + 4) + 4);
        goto LAB_005b4160;
      }
    }
    piVar2 = *(int **)(*(int *)(cms + 4) + 0xc);
  }
LAB_005b4160:
  if (piVar2 != (int *)0x0) {
    if (oid == (ASN1_OBJECT *)0x0) {
      return 1;
    }
    iVar1 = (*(code *)PTR_OBJ_dup_006a8494)(oid);
    if (iVar1 != 0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a7004)(*piVar2);
      *piVar2 = iVar1;
      return 1;
    }
  }
  return 0;
}

