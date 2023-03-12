
int CMS_is_detached(CMS_ContentInfo *cms)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar1 == 0x19) {
LAB_005b6c14:
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 8) + 4);
  }
  else if (iVar1 < 0x1a) {
    if (iVar1 == 0x16) goto LAB_005b6c14;
    if (iVar1 != 0x17) {
      if (iVar1 == 0x15) {
        piVar2 = (int *)(cms + 4);
        goto LAB_005b6bdc;
      }
LAB_005b6bc8:
      piVar2 = *(int **)(cms + 4) + 1;
      if (**(int **)(cms + 4) != 4) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x81,0x98,"cms_lib.c",0xee);
        return -1;
      }
      goto LAB_005b6bdc;
    }
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
  }
  else {
    if (iVar1 == 0xcd) {
      iVar1 = *(int *)(*(int *)(cms + 4) + 0x14);
    }
    else {
      if (iVar1 != 0x312) {
        if (iVar1 == 0x1a) {
          piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 8);
          goto joined_r0x005b6c20;
        }
        goto LAB_005b6bc8;
      }
      iVar1 = *(int *)(*(int *)(cms + 4) + 0xc);
    }
    piVar2 = (int *)(iVar1 + 4);
  }
joined_r0x005b6c20:
  if (piVar2 == (int *)0x0) {
    return -1;
  }
LAB_005b6bdc:
  return (uint)(*piVar2 == 0);
}

