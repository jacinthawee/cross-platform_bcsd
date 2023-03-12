
X509_EXTENSION *
X509_EXTENSION_create_by_OBJ(X509_EXTENSION **ex,ASN1_OBJECT *obj,int crit,ASN1_OCTET_STRING *data)

{
  X509_EXTENSION *a;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  
  if ((ex == (X509_EXTENSION **)0x0) || (a = *ex, a == (X509_EXTENSION *)0x0)) {
    a = X509_EXTENSION_new();
    if (a == (X509_EXTENSION *)0x0) {
      ERR_put_error(0xb,0x6d,0x41,"x509_v3.c",0xd1);
      return (X509_EXTENSION *)0x0;
    }
    if (obj == (ASN1_OBJECT *)0x0) goto LAB_08163730;
  }
  else if (obj == (ASN1_OBJECT *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  ASN1_OBJECT_free(a->object);
  pAVar1 = OBJ_dup(obj);
  a->object = pAVar1;
  a->critical = CONCAT31((int3)(-(uint)(crit == 0) >> 8),0xff);
  iVar2 = ASN1_STRING_set(a->value,data->data,data->length);
  if (iVar2 != 0) {
    if (ex == (X509_EXTENSION **)0x0) {
      return a;
    }
    if (*ex != (X509_EXTENSION *)0x0) {
      return a;
    }
    *ex = a;
    return a;
  }
LAB_08163730:
  if ((ex != (X509_EXTENSION **)0x0) && (*ex == a)) {
    return (X509_EXTENSION *)0x0;
  }
  X509_EXTENSION_free(a);
  return (X509_EXTENSION *)0x0;
}

