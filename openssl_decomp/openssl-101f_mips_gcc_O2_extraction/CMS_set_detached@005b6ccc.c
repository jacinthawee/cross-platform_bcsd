
int CMS_set_detached(CMS_ContentInfo *cms,int detached)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar1 == 0x19) {
LAB_005b6d9c:
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 8) + 4);
  }
  else if (iVar1 < 0x1a) {
    if (iVar1 == 0x16) goto LAB_005b6d9c;
    if (iVar1 != 0x17) {
      if (iVar1 == 0x15) {
        piVar2 = (int *)(cms + 4);
        goto LAB_005b6d44;
      }
LAB_005b6d30:
      piVar2 = *(int **)(cms + 4) + 1;
      if (**(int **)(cms + 4) != 4) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x81,0x98,"cms_lib.c",0xee);
        return 0;
      }
      goto LAB_005b6d44;
    }
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
  }
  else if (iVar1 == 0xcd) {
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 0x14) + 4);
  }
  else if (iVar1 == 0x312) {
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 4);
  }
  else {
    if (iVar1 != 0x1a) goto LAB_005b6d30;
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 8);
  }
  if (piVar2 == (int *)0x0) {
    return 0;
  }
LAB_005b6d44:
  if (detached != 0) {
    if (*piVar2 != 0) {
      (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)();
      *piVar2 = 0;
      return 1;
    }
    return 1;
  }
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
    *piVar2 = iVar1;
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x93,0x41,"cms_lib.c",0x154);
      return 0;
    }
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x20;
  return 1;
}

