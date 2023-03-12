
X509_EXTENSION *
X509_EXTENSION_create_by_OBJ(X509_EXTENSION **ex,ASN1_OBJECT *obj,int crit,ASN1_OCTET_STRING *data)

{
  ASN1_OBJECT *pAVar1;
  ASN1_BOOLEAN AVar2;
  uchar *data_00;
  int iVar3;
  X509_EXTENSION *a;
  
  if ((ex == (X509_EXTENSION **)0x0) || (a = *ex, a == (X509_EXTENSION *)0x0)) {
    a = X509_EXTENSION_new();
    if (a == (X509_EXTENSION *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6d,0x41,"x509_v3.c",0xd1);
      return (X509_EXTENSION *)0x0;
    }
    if (obj == (ASN1_OBJECT *)0x0) goto LAB_005811f0;
  }
  else if (obj == (ASN1_OBJECT *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(a->object);
  pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
  AVar2 = -1;
  iVar3 = data->length;
  if (crit != 0) {
    AVar2 = 0xff;
  }
  data_00 = data->data;
  a->object = pAVar1;
  a->critical = AVar2;
  iVar3 = ASN1_STRING_set(a->value,data_00,iVar3);
  if (iVar3 != 0) {
    if ((ex != (X509_EXTENSION **)0x0) && (*ex == (X509_EXTENSION *)0x0)) {
      *ex = a;
      return a;
    }
    return a;
  }
LAB_005811f0:
  if ((ex != (X509_EXTENSION **)0x0) && (*ex == a)) {
    return (X509_EXTENSION *)0x0;
  }
  X509_EXTENSION_free(a);
  return (X509_EXTENSION *)0x0;
}

