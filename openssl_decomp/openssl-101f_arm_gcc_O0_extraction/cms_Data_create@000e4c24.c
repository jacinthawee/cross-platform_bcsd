
ASN1_OBJECT ** cms_Data_create(void)

{
  ASN1_OBJECT **ppAVar1;
  ASN1_OBJECT *o;
  int iVar2;
  ASN1_OCTET_STRING *pAVar3;
  char ***pppcVar4;
  
  ppAVar1 = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)CMS_ContentInfo_it);
  if (ppAVar1 == (ASN1_OBJECT **)0x0) {
    return (ASN1_OBJECT **)0x0;
  }
  o = OBJ_nid2obj(0x15);
  *ppAVar1 = o;
  iVar2 = OBJ_obj2nid(o);
  if (iVar2 == 0x19) {
LAB_000e4ca0:
    pppcVar4 = (char ***)(ppAVar1[1]->nid + 4);
  }
  else if (iVar2 < 0x1a) {
    if (iVar2 == 0x16) goto LAB_000e4ca0;
    if (iVar2 != 0x17) {
      if (iVar2 == 0x15) {
        pppcVar4 = (char ***)(ppAVar1 + 1);
        goto LAB_000e4c64;
      }
LAB_000e4c5a:
      if (ppAVar1[1]->sn != (char *)0x4) {
        ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xee);
        return ppAVar1;
      }
      pppcVar4 = &ppAVar1[1]->ln;
      goto LAB_000e4c64;
    }
    pppcVar4 = (char ***)(ppAVar1[1]->length + 8);
  }
  else if (iVar2 == 0xcd) {
    pppcVar4 = (char ***)(ppAVar1[1]->flags + 4);
  }
  else if (iVar2 == 0x312) {
    pppcVar4 = (char ***)(ppAVar1[1]->length + 4);
  }
  else {
    if (iVar2 != 0x1a) goto LAB_000e4c5a;
    pppcVar4 = (char ***)(ppAVar1[1]->ln + 2);
  }
  if (pppcVar4 == (char ***)0x0) {
    return ppAVar1;
  }
LAB_000e4c64:
  pAVar3 = (ASN1_OCTET_STRING *)*pppcVar4;
  if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
    pAVar3 = ASN1_OCTET_STRING_new();
    *pppcVar4 = (char **)pAVar3;
    if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
      ERR_put_error(0x2e,0x93,0x41,"cms_lib.c",0x154);
      return ppAVar1;
    }
  }
  pAVar3->flags = pAVar3->flags | 0x20;
  return ppAVar1;
}

