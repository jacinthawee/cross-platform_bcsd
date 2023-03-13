
CMS_ContentInfo * CMS_EnvelopedData_create(EVP_CIPHER *cipher)

{
  ASN1_OBJECT **ppAVar1;
  ASN1_OBJECT **a;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  
  a = (ASN1_OBJECT **)CMS_ContentInfo_new();
  if (a == (ASN1_OBJECT **)0x0) goto LAB_0818fc9c;
  if (a[1] == (ASN1_OBJECT *)0x0) {
    pAVar3 = (ASN1_OBJECT *)ASN1_item_new((ASN1_ITEM *)CMS_EnvelopedData_it);
    a[1] = pAVar3;
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      ppAVar1 = (ASN1_OBJECT **)pAVar3->length;
      pAVar3->sn = (char *)0x0;
      pAVar3 = OBJ_nid2obj(0x15);
      *ppAVar1 = pAVar3;
      ASN1_OBJECT_free(*a);
      pAVar3 = OBJ_nid2obj(0x17);
      *a = pAVar3;
      pAVar3 = a[1];
      goto LAB_0818fc54;
    }
    ERR_put_error(0x2e,0x7e,0x41,"cms_env.c",0x5a);
  }
  else {
    iVar2 = OBJ_obj2nid(*a);
    if (iVar2 == 0x17) {
      pAVar3 = a[1];
LAB_0818fc54:
      if (pAVar3 != (ASN1_OBJECT *)0x0) {
        iVar2 = cms_EncryptedContent_init(pAVar3->length,cipher,0,0);
        if (iVar2 != 0) {
          return (CMS_ContentInfo *)a;
        }
      }
    }
    else {
      ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    }
  }
  CMS_ContentInfo_free((CMS_ContentInfo *)a);
LAB_0818fc9c:
  ERR_put_error(0x2e,0x7c,0x41,"cms_env.c",0x86);
  return (CMS_ContentInfo *)0x0;
}

