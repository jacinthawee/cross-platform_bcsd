
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_OBJ(X509_NAME_ENTRY **ne,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_NAME_ENTRY *ne_00;
  
  if (((ne != (X509_NAME_ENTRY **)0x0) && (ne_00 = *ne, ne_00 != (X509_NAME_ENTRY *)0x0)) ||
     (ne_00 = (X509_NAME_ENTRY *)(*(code *)PTR_X509_NAME_ENTRY_new_006aa054)(),
     ne_00 != (X509_NAME_ENTRY *)0x0)) {
    if (obj == (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x73,0x43,"x509name.c",0x155);
    }
    else {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)(ne_00->object);
      pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
      ne_00->object = pAVar1;
      if ((pAVar1 != (ASN1_OBJECT *)0x0) &&
         (iVar2 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar2 != 0)) {
        if ((ne != (X509_NAME_ENTRY **)0x0) && (*ne == (X509_NAME_ENTRY *)0x0)) {
          *ne = ne_00;
          return ne_00;
        }
        return ne_00;
      }
    }
    if ((ne != (X509_NAME_ENTRY **)0x0) && (ne_00 == *ne)) {
      return (X509_NAME_ENTRY *)0x0;
    }
    (*(code *)PTR_X509_NAME_ENTRY_free_006a8250)(ne_00);
  }
  return (X509_NAME_ENTRY *)0x0;
}

