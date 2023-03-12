
X509_EXTENSION *
X509_EXTENSION_create_by_NID(X509_EXTENSION **ex,int nid,int crit,ASN1_OCTET_STRING *data)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_BOOLEAN AVar3;
  uchar *data_00;
  int iVar4;
  X509_EXTENSION *a;
  
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(nid);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6c,0x6d,"x509_v3.c",0xc0);
  }
  else {
    if (((ex == (X509_EXTENSION **)0x0) || (a = *ex, a == (X509_EXTENSION *)0x0)) &&
       (a = X509_EXTENSION_new(), a == (X509_EXTENSION *)0x0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6d,0x41,"x509_v3.c",0xd1);
    }
    else {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)(a->object);
      pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
      AVar3 = -1;
      iVar4 = data->length;
      if (crit != 0) {
        AVar3 = 0xff;
      }
      data_00 = data->data;
      a->object = pAVar2;
      a->critical = AVar3;
      iVar4 = ASN1_STRING_set(a->value,data_00,iVar4);
      if (iVar4 != 0) {
        if ((ex != (X509_EXTENSION **)0x0) && (*ex == (X509_EXTENSION *)0x0)) {
          *ex = a;
        }
        return a;
      }
      if ((ex == (X509_EXTENSION **)0x0) || (a != *ex)) {
        X509_EXTENSION_free(a);
      }
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
  }
  return (X509_EXTENSION *)0x0;
}

