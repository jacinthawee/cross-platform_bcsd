
int CMS_is_detached(CMS_ContentInfo *cms)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_000e516c:
    piVar3 = (int *)(*(int *)(*(int *)(cms + 4) + 8) + 4);
  }
  else if (iVar1 < 0x1a) {
    if (iVar1 == 0x16) goto LAB_000e516c;
    if (iVar1 != 0x17) {
      if (iVar1 != 0x15) {
LAB_000e5152:
        cms = *(CMS_ContentInfo **)(cms + 4);
        if (*(int *)cms != 4) {
          ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xee);
          return -1;
        }
      }
      piVar3 = (int *)((int)cms + 4);
      goto LAB_000e5178;
    }
    piVar3 = (int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
  }
  else if (iVar1 == 0xcd) {
    piVar3 = (int *)(*(int *)(*(int *)(cms + 4) + 0x14) + 4);
  }
  else if (iVar1 == 0x312) {
    piVar3 = (int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 4);
  }
  else {
    if (iVar1 != 0x1a) goto LAB_000e5152;
    piVar3 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 8);
  }
  if (piVar3 == (int *)0x0) {
    return -1;
  }
LAB_000e5178:
  uVar2 = count_leading_zeroes(*piVar3);
  return uVar2 >> 5;
}

