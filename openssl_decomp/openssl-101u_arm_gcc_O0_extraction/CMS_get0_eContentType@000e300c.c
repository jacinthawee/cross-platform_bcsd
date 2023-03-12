
ASN1_OBJECT * CMS_get0_eContentType(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_000e3062:
    pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_000e3062;
      if (iVar1 != 0x17) {
LAB_000e302e:
        ERR_put_error(0x2e,0x82,0x98,"cms_lib.c",0x10c);
        return (ASN1_OBJECT *)0x0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 0x14);
        goto LAB_000e3058;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_000e302e;
        pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 4);
        goto LAB_000e3058;
      }
    }
    pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 0xc);
  }
LAB_000e3058:
  if (pAVar2 != (ASN1_OBJECT *)0x0) {
    pAVar2 = (ASN1_OBJECT *)pAVar2->sn;
  }
  return pAVar2;
}

