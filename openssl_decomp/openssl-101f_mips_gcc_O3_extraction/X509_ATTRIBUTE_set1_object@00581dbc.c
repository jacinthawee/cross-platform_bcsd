
int X509_ATTRIBUTE_set1_object(X509_ATTRIBUTE *attr,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  
  if ((attr != (X509_ATTRIBUTE *)0x0) && (obj != (ASN1_OBJECT *)0x0)) {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(attr->object);
    pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
    attr->object = pAVar1;
    return 1;
  }
  return 0;
}

