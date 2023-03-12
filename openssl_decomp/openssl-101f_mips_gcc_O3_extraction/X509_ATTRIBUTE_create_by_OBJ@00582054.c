
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_OBJ(X509_ATTRIBUTE **attr,ASN1_OBJECT *obj,int atrtype,void *data,int len)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *attr_00;
  
  if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 = *attr, attr_00 == (X509_ATTRIBUTE *)0x0)) {
    attr_00 = (X509_ATTRIBUTE *)(*(code *)PTR_X509_ATTRIBUTE_new_006a9fe0)();
    if (attr_00 == (X509_ATTRIBUTE *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x89,0x41,"x509_att.c",0xed);
      return (X509_ATTRIBUTE *)0x0;
    }
    if (obj != (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)(attr_00->object);
      pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
      attr_00->object = pAVar1;
      iVar2 = X509_ATTRIBUTE_set1_data(attr_00,atrtype,data,len);
      if (iVar2 != 0) {
        if (attr == (X509_ATTRIBUTE **)0x0) {
          return attr_00;
        }
        goto LAB_00582184;
      }
    }
    if (attr == (X509_ATTRIBUTE **)0x0) goto LAB_005820e8;
  }
  else {
    if (obj == (ASN1_OBJECT *)0x0) {
      return (X509_ATTRIBUTE *)0x0;
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(attr_00->object);
    pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,atrtype,data,len);
    if (iVar2 != 0) {
LAB_00582184:
      if (*attr == (X509_ATTRIBUTE *)0x0) {
        *attr = attr_00;
        return attr_00;
      }
      return attr_00;
    }
  }
  if (*attr == attr_00) {
    return (X509_ATTRIBUTE *)0x0;
  }
LAB_005820e8:
  (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(attr_00);
  return (X509_ATTRIBUTE *)0x0;
}

