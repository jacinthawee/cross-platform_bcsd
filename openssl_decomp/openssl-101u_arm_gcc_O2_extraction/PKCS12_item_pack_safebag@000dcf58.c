
PKCS12_SAFEBAG * PKCS12_item_pack_safebag(void *obj,ASN1_ITEM *it,int nid1,int nid2)

{
  PKCS12_SAFEBAG *a;
  ASN1_OBJECT *pAVar1;
  ASN1_STRING *pAVar2;
  PKCS12_SAFEBAG *pPVar3;
  int line;
  
  a = (PKCS12_SAFEBAG *)PKCS12_BAGS_new();
  if (a == (PKCS12_SAFEBAG *)0x0) {
    ERR_put_error(0x23,0x75,0x41,"p12_add.c",0x48);
  }
  else {
    pAVar1 = OBJ_nid2obj(nid1);
    a->type = pAVar1;
    pAVar2 = ASN1_item_pack(obj,it,(ASN1_OCTET_STRING **)&(a->value).bag);
    line = 0x4d;
    if (pAVar2 != (ASN1_STRING *)0x0) {
      pPVar3 = PKCS12_SAFEBAG_new();
      if (pPVar3 != (PKCS12_SAFEBAG *)0x0) {
        (pPVar3->value).shkeybag = (X509_SIG *)a;
        pAVar1 = OBJ_nid2obj(nid2);
        pPVar3->type = pAVar1;
        return pPVar3;
      }
      line = 0x51;
    }
    ERR_put_error(0x23,0x75,0x41,"p12_add.c",line);
    PKCS12_BAGS_free((PKCS12_BAGS *)a);
    a = (PKCS12_SAFEBAG *)0x0;
  }
  return a;
}
