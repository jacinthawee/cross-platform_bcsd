
int CMS_is_detached(CMS_ContentInfo *cms)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_0818a848:
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 8) + 4);
  }
  else if (iVar1 < 0x1a) {
    if (iVar1 == 0x16) goto LAB_0818a848;
    if (iVar1 != 0x17) {
      if (iVar1 != 0x15) {
LAB_0818a81c:
        cms = *(CMS_ContentInfo **)(cms + 4);
        if (*(int *)cms != 4) {
          ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xea);
          return -1;
        }
      }
      piVar2 = (int *)((int)cms + 4);
      goto LAB_0818a855;
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
    if (iVar1 != 0x1a) goto LAB_0818a81c;
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 8);
  }
  if (piVar2 == (int *)0x0) {
    return -1;
  }
LAB_0818a855:
  return (uint)(*piVar2 == 0);
}

