
int X509_EXTENSION_set_object(X509_EXTENSION *ex,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  
  if ((ex != (X509_EXTENSION *)0x0) && (obj != (ASN1_OBJECT *)0x0)) {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(ex->object);
    pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
    ex->object = pAVar1;
    return 1;
  }
  return 0;
}

