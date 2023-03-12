
X509_EXTENSION *
X509_EXTENSION_create_by_NID(X509_EXTENSION **ex,int nid,int crit,ASN1_OCTET_STRING *data)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  uchar *data_00;
  int iVar2;
  ASN1_BOOLEAN AVar3;
  X509_EXTENSION *a;
  
  o = OBJ_nid2obj(nid);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x6c,0x6d,"x509_v3.c",0xc2);
    return (X509_EXTENSION *)0x0;
  }
  if (((ex == (X509_EXTENSION **)0x0) || (a = *ex, a == (X509_EXTENSION *)0x0)) &&
     (a = X509_EXTENSION_new(), a == (X509_EXTENSION *)0x0)) {
    ERR_put_error(0xb,0x6d,0x41,"x509_v3.c",0xd4);
  }
  else {
    ASN1_OBJECT_free(a->object);
    pAVar1 = OBJ_dup(o);
    data_00 = data->data;
    if (crit == 0) {
      AVar3 = -1;
    }
    else {
      AVar3 = 0xff;
    }
    iVar2 = data->length;
    a->critical = AVar3;
    a->object = pAVar1;
    iVar2 = ASN1_STRING_set(a->value,data_00,iVar2);
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
    if ((ex == (X509_EXTENSION **)0x0) || (a != *ex)) {
      X509_EXTENSION_free(a);
    }
  }
  ASN1_OBJECT_free(o);
  return (X509_EXTENSION *)0x0;
}

