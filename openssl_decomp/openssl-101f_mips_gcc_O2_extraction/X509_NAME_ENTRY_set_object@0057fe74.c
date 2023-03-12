
int X509_NAME_ENTRY_set_object(X509_NAME_ENTRY *ne,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  
  if ((ne != (X509_NAME_ENTRY *)0x0) && (obj != (ASN1_OBJECT *)0x0)) {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(ne->object);
    pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
    ne->object = pAVar1;
    return (uint)(pAVar1 != (ASN1_OBJECT *)0x0);
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x73,0x43,"x509name.c",0x155);
  return 0;
}

