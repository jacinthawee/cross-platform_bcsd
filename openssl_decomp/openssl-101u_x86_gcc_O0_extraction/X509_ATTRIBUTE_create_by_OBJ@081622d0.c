
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_OBJ(X509_ATTRIBUTE **attr,ASN1_OBJECT *obj,int atrtype,void *data,int len)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *attr_00;
  
  if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 = *attr, attr_00 == (X509_ATTRIBUTE *)0x0)) {
    attr_00 = X509_ATTRIBUTE_new();
    if (attr_00 == (X509_ATTRIBUTE *)0x0) {
      ERR_put_error(0xb,0x89,0x41,"x509_att.c",0xf7);
      return (X509_ATTRIBUTE *)0x0;
    }
    if (obj != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(attr_00->object);
      pAVar1 = OBJ_dup(obj);
      attr_00->object = pAVar1;
      iVar2 = X509_ATTRIBUTE_set1_data(attr_00,atrtype,data,len);
      if (iVar2 != 0) {
        if (attr == (X509_ATTRIBUTE **)0x0) {
          return attr_00;
        }
        goto LAB_08162390;
      }
    }
    if (attr == (X509_ATTRIBUTE **)0x0) goto LAB_08162325;
  }
  else {
    if (obj == (ASN1_OBJECT *)0x0) {
      return (X509_ATTRIBUTE *)0x0;
    }
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(obj);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,atrtype,data,len);
    if (iVar2 != 0) {
LAB_08162390:
      if (*attr != (X509_ATTRIBUTE *)0x0) {
        return attr_00;
      }
      *attr = attr_00;
      return attr_00;
    }
  }
  if (*attr == attr_00) {
    return (X509_ATTRIBUTE *)0x0;
  }
LAB_08162325:
  X509_ATTRIBUTE_free(attr_00);
  return (X509_ATTRIBUTE *)0x0;
}

