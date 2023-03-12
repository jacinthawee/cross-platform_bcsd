
ASN1_OBJECT * CMS_get0_eContentType(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT **ppAVar3;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar1 == 0x19) {
LAB_005b69f0:
    ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_005b69f0;
      if (iVar1 != 0x17) {
LAB_005b6984:
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x82,0x98,"cms_lib.c",0x111);
        return (ASN1_OBJECT *)0x0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0x14);
        goto LAB_005b69d4;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_005b6984;
        ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 4);
        goto LAB_005b69d4;
      }
    }
    ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0xc);
  }
LAB_005b69d4:
  if (ppAVar3 == (ASN1_OBJECT **)0x0) {
    pAVar2 = (ASN1_OBJECT *)0x0;
  }
  else {
    pAVar2 = *ppAVar3;
  }
  return pAVar2;
}

