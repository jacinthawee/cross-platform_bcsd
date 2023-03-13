
int CMS_SignedData_init(CMS_ContentInfo *cms)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  undefined4 *puVar3;
  ASN1_OBJECT *pAVar4;
  
  if (*(int *)(cms + 4) == 0) {
    puVar3 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_SignedData_it);
    *(undefined4 **)(cms + 4) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      ERR_put_error(0x2e,0x95,0x41,"cms_sd.c",0x52);
      return 0;
    }
    ppAVar1 = (ASN1_OBJECT **)puVar3[2];
    *puVar3 = 1;
    pAVar4 = OBJ_nid2obj(0x15);
    *ppAVar1 = pAVar4;
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
    ASN1_OBJECT_free(*(ASN1_OBJECT **)cms);
    pAVar4 = OBJ_nid2obj(0x16);
    *(ASN1_OBJECT **)cms = pAVar4;
    iVar2 = *(int *)(cms + 4);
  }
  else {
    iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar2 != 0x16) {
      ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
      return 0;
    }
    iVar2 = *(int *)(cms + 4);
  }
  return (uint)(iVar2 != 0);
}

