
PKCS12_SAFEBAG * PKCS12_item_pack_safebag(void *obj,ASN1_ITEM *it,int nid1,int nid2)

{
  ASN1_STRING *pAVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *pAVar3;
  int line;
  
  pAVar1 = (ASN1_STRING *)PKCS12_BAGS_new();
  if (pAVar1 == (ASN1_STRING *)0x0) {
    ERR_put_error(0x23,0x75,0x41,"p12_add.c",0x47);
  }
  else {
    pAVar2 = OBJ_nid2obj(nid1);
    pAVar1->length = (int)pAVar2;
    pAVar3 = ASN1_item_pack(obj,it,&((_union_988 *)&pAVar1->type)->x509cert);
    line = 0x4c;
    if (pAVar3 != (ASN1_STRING *)0x0) {
      pAVar3 = (ASN1_STRING *)PKCS12_SAFEBAG_new();
      if (pAVar3 != (ASN1_STRING *)0x0) {
        pAVar3->type = (int)pAVar1;
        pAVar2 = OBJ_nid2obj(nid2);
        pAVar3->length = (int)pAVar2;
        return (PKCS12_SAFEBAG *)pAVar3;
      }
      line = 0x50;
    }
    ERR_put_error(0x23,0x75,0x41,"p12_add.c",line);
    pAVar1 = pAVar3;
  }
  return (PKCS12_SAFEBAG *)pAVar1;
}

