
int CMS_set_detached(CMS_ContentInfo *cms,int detached)

{
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  ASN1_OCTET_STRING **ppAVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_000e5212:
    ppAVar3 = (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 8) + 4);
  }
  else if (iVar1 < 0x1a) {
    if (iVar1 == 0x16) goto LAB_000e5212;
    if (iVar1 != 0x17) {
      if (iVar1 != 0x15) {
LAB_000e51e4:
        cms = *(CMS_ContentInfo **)(cms + 4);
        if (*(int *)cms != 4) {
          ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xee);
          return 0;
        }
      }
      ppAVar3 = (ASN1_OCTET_STRING **)((int)cms + 4);
      goto LAB_000e51ee;
    }
    ppAVar3 = (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
  }
  else {
    if (iVar1 == 0xcd) {
      iVar1 = *(int *)(*(int *)(cms + 4) + 0x14);
    }
    else {
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_000e51e4;
        ppAVar3 = (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 4) + 8);
        goto joined_r0x000e521a;
      }
      iVar1 = *(int *)(*(int *)(cms + 4) + 0xc);
    }
    ppAVar3 = (ASN1_OCTET_STRING **)(iVar1 + 4);
  }
joined_r0x000e521a:
  if (ppAVar3 == (ASN1_OCTET_STRING **)0x0) {
    return 0;
  }
LAB_000e51ee:
  if (detached == 0) {
    pAVar2 = *ppAVar3;
    if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
      pAVar2 = ASN1_OCTET_STRING_new();
      *ppAVar3 = pAVar2;
      if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
        ERR_put_error(0x2e,0x93,0x41,"cms_lib.c",0x154);
        return 0;
      }
    }
    pAVar2->flags = pAVar2->flags | 0x20;
    return 1;
  }
  if (*ppAVar3 != (ASN1_OCTET_STRING *)0x0) {
    ASN1_OCTET_STRING_free(*ppAVar3);
    *ppAVar3 = (ASN1_OCTET_STRING *)0x0;
    return 1;
  }
  return 1;
}

