
ASN1_OBJECT * CMS_get0_eContentType(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  ASN1_OBJECT *pAVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_0818c048:
    ppAVar2 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_0818c048;
      if (iVar1 != 0x17) {
LAB_0818bffc:
        ERR_put_error(0x2e,0x82,0x98,"cms_lib.c",0x111);
        return (ASN1_OBJECT *)0x0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        ppAVar2 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0x14);
        goto LAB_0818c038;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_0818bffc;
        ppAVar2 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 4);
        goto LAB_0818c038;
      }
    }
    ppAVar2 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0xc);
  }
LAB_0818c038:
  if (ppAVar2 == (ASN1_OBJECT **)0x0) {
    pAVar3 = (ASN1_OBJECT *)0x0;
  }
  else {
    pAVar3 = *ppAVar2;
  }
  return pAVar3;
}

