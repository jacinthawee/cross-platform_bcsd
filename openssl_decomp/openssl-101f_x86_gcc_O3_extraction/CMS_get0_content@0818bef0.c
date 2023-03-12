
ASN1_OCTET_STRING ** CMS_get0_content(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_OCTET_STRING **ppAVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_0818bf48:
    ppAVar2 = (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 8) + 4);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_0818bf48;
      if (iVar1 == 0x17) {
        return (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 0xc) + 8);
      }
      if (iVar1 == 0x15) {
        return (ASN1_OCTET_STRING **)(cms + 4);
      }
    }
    else {
      if (iVar1 == 0xcd) {
        return (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 0x14) + 4);
      }
      if (iVar1 == 0x312) {
        return (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 0xc) + 4);
      }
      if (iVar1 == 0x1a) {
        return (ASN1_OCTET_STRING **)(*(int *)(*(int *)(cms + 4) + 4) + 8);
      }
    }
    if (**(int **)(cms + 4) == 4) {
      return (ASN1_OCTET_STRING **)(*(int **)(cms + 4) + 1);
    }
    ERR_put_error(0x2e,0x81,0x98,"cms_lib.c",0xee);
    ppAVar2 = (ASN1_OCTET_STRING **)0x0;
  }
  return ppAVar2;
}

