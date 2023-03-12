
int X509_NAME_ENTRY_set_object(X509_NAME_ENTRY *ne,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  
  if ((ne != (X509_NAME_ENTRY *)0x0) && (obj != (ASN1_OBJECT *)0x0)) {
    ASN1_OBJECT_free(ne->object);
    pAVar1 = OBJ_dup(obj);
    ne->object = pAVar1;
    return (uint)(pAVar1 != (ASN1_OBJECT *)0x0);
  }
  ERR_put_error(0xb,0x73,0x43,"x509name.c",0x155);
  return 0;
}

