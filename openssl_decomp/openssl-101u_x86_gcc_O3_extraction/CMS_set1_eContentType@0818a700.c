
int CMS_set1_eContentType(CMS_ContentInfo *cms,ASN1_OBJECT *oid)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT **ppAVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_0818a7b8:
    ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_0818a7b8;
      if (iVar1 != 0x17) {
LAB_0818a73e:
        ERR_put_error(0x2e,0x82,0x98,"cms_lib.c",0x10c);
        return 0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0x14);
        goto LAB_0818a780;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_0818a73e;
        ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 4);
        goto LAB_0818a780;
      }
    }
    ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0xc);
  }
LAB_0818a780:
  if (ppAVar3 == (ASN1_OBJECT **)0x0) {
    return 0;
  }
  if (oid != (ASN1_OBJECT *)0x0) {
    pAVar2 = OBJ_dup(oid);
    if (pAVar2 == (ASN1_OBJECT *)0x0) {
      return 0;
    }
    ASN1_OBJECT_free(*ppAVar3);
    *ppAVar3 = pAVar2;
  }
  return 1;
}
