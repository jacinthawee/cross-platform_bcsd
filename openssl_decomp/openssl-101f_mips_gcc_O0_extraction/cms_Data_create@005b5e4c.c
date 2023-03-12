
undefined4 * cms_Data_create(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_ContentInfo_it_006aa3dc);
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x15);
  puVar1 = PTR_OBJ_obj2nid_006a822c;
  *puVar2 = uVar3;
  iVar4 = (*(code *)puVar1)(uVar3);
  if (iVar4 == 0x19) {
LAB_005b5f70:
    piVar5 = (int *)(*(int *)(puVar2[1] + 8) + 4);
joined_r0x005b5f44:
    if (piVar5 == (int *)0x0) {
      return puVar2;
    }
  }
  else {
    if (0x19 < iVar4) {
      if (iVar4 == 0xcd) {
        iVar4 = *(int *)(puVar2[1] + 0x14);
      }
      else {
        if (iVar4 != 0x312) {
          if (iVar4 == 0x1a) {
            piVar5 = (int *)(*(int *)(puVar2[1] + 4) + 8);
            goto joined_r0x005b5f44;
          }
          goto LAB_005b5ed4;
        }
        iVar4 = *(int *)(puVar2[1] + 0xc);
      }
      piVar5 = (int *)(iVar4 + 4);
      goto joined_r0x005b5f44;
    }
    if (iVar4 == 0x16) goto LAB_005b5f70;
    if (iVar4 == 0x17) {
      piVar5 = (int *)(*(int *)(puVar2[1] + 0xc) + 8);
      goto joined_r0x005b5f44;
    }
    piVar5 = puVar2 + 1;
    if (iVar4 == 0x15) {
      iVar4 = *piVar5;
      goto LAB_005b5eec;
    }
LAB_005b5ed4:
    piVar5 = (int *)puVar2[1] + 1;
    if (*(int *)puVar2[1] != 4) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x81,0x98,"cms_lib.c",0xee);
      return puVar2;
    }
  }
  iVar4 = *piVar5;
LAB_005b5eec:
  if (iVar4 == 0) {
    iVar4 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
    *piVar5 = iVar4;
    if (iVar4 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x93,0x41,"cms_lib.c",0x154);
      return puVar2;
    }
  }
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 0x20;
  return puVar2;
}

