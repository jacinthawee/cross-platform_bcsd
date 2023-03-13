
ASN1_OBJECT ** cms_DigestedData_create(undefined4 param_1)

{
  ASN1_OBJECT **ppAVar1;
  ASN1_OBJECT **a;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT *pAVar3;
  
  a = (ASN1_OBJECT **)CMS_ContentInfo_new();
  if (a == (ASN1_OBJECT **)0x0) {
    a = (ASN1_OBJECT **)0x0;
  }
  else {
    pAVar2 = (ASN1_OBJECT *)ASN1_item_new((ASN1_ITEM *)CMS_DigestedData_it);
    if (pAVar2 == (ASN1_OBJECT *)0x0) {
      CMS_ContentInfo_free((CMS_ContentInfo *)a);
      return (ASN1_OBJECT **)0x0;
    }
    pAVar3 = OBJ_nid2obj(0x19);
    a[1] = pAVar2;
    ppAVar1 = (ASN1_OBJECT **)pAVar2->nid;
    *a = pAVar3;
    pAVar2->sn = (char *)0x0;
    pAVar3 = OBJ_nid2obj(0x15);
    *ppAVar1 = pAVar3;
    cms_DigestAlgorithm_set(pAVar2->ln,param_1);
  }
  return a;
}

