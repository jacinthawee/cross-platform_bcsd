
undefined4 * cms_Data_create(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_ContentInfo_it_006a92d0);
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  uVar3 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
  puVar1 = PTR_OBJ_obj2nid_006a712c;
  *puVar2 = uVar3;
  iVar4 = (*(code *)puVar1)(uVar3);
  if (iVar4 == 0x19) {
LAB_005b3600:
    piVar5 = (int *)(*(int *)(puVar2[1] + 8) + 4);
joined_r0x005b35d4:
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
            goto joined_r0x005b35d4;
          }
          goto LAB_005b3564;
        }
        iVar4 = *(int *)(puVar2[1] + 0xc);
      }
      piVar5 = (int *)(iVar4 + 4);
      goto joined_r0x005b35d4;
    }
    if (iVar4 == 0x16) goto LAB_005b3600;
    if (iVar4 == 0x17) {
      piVar5 = (int *)(*(int *)(puVar2[1] + 0xc) + 8);
      goto joined_r0x005b35d4;
    }
    piVar5 = puVar2 + 1;
    if (iVar4 == 0x15) {
      iVar4 = *piVar5;
      goto LAB_005b357c;
    }
LAB_005b3564:
    piVar5 = (int *)puVar2[1] + 1;
    if (*(int *)puVar2[1] != 4) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x81,0x98,"cms_lib.c",0xea);
      return puVar2;
    }
  }
  iVar4 = *piVar5;
LAB_005b357c:
  if (iVar4 == 0) {
    iVar4 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a8668)();
    *piVar5 = iVar4;
    if (iVar4 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x93,0x41,"cms_lib.c",0x14c);
      return puVar2;
    }
  }
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 0x20;
  return puVar2;
}

