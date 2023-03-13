
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_txt(X509_NAME_ENTRY **ne,char *field,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_NAME_ENTRY *ne_00;
  
  o = OBJ_txt2obj(field,0);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x83,0x77,"x509name.c",0x127);
    ERR_add_error_data(2,"name=",field);
    return (X509_NAME_ENTRY *)0x0;
  }
  if ((ne == (X509_NAME_ENTRY **)0x0) || (ne_00 = *ne, ne_00 == (X509_NAME_ENTRY *)0x0)) {
    ne_00 = X509_NAME_ENTRY_new();
    if (ne_00 == (X509_NAME_ENTRY *)0x0) goto LAB_08161209;
    ASN1_OBJECT_free(ne_00->object);
    pAVar1 = OBJ_dup(o);
    ne_00->object = pAVar1;
    if ((pAVar1 == (ASN1_OBJECT *)0x0) ||
       (iVar2 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar2 == 0)) {
      if (ne != (X509_NAME_ENTRY **)0x0) goto LAB_081611f9;
      goto LAB_081611fd;
    }
    if (ne == (X509_NAME_ENTRY **)0x0) goto LAB_0816120b;
  }
  else {
    ASN1_OBJECT_free(ne_00->object);
    pAVar1 = OBJ_dup(o);
    ne_00->object = pAVar1;
    if ((pAVar1 == (ASN1_OBJECT *)0x0) ||
       (iVar2 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar2 == 0)) {
LAB_081611f9:
      if (ne_00 != *ne) {
LAB_081611fd:
        X509_NAME_ENTRY_free(ne_00);
      }
LAB_08161209:
      ne_00 = (X509_NAME_ENTRY *)0x0;
      goto LAB_0816120b;
    }
  }
  if (*ne == (X509_NAME_ENTRY *)0x0) {
    *ne = ne_00;
  }
LAB_0816120b:
  ASN1_OBJECT_free(o);
  return ne_00;
}

