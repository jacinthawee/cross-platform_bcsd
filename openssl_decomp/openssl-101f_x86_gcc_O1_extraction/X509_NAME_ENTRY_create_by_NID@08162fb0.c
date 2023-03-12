
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_NID(X509_NAME_ENTRY **ne,int nid,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_NAME_ENTRY *ne_00;
  
  o = OBJ_nid2obj(nid);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x72,0x6d,"x509name.c",0x12f);
    return (X509_NAME_ENTRY *)0x0;
  }
  if ((ne == (X509_NAME_ENTRY **)0x0) || (ne_00 = *ne, ne_00 == (X509_NAME_ENTRY *)0x0)) {
    ne_00 = X509_NAME_ENTRY_new();
    if (ne_00 == (X509_NAME_ENTRY *)0x0) goto LAB_08163006;
    ASN1_OBJECT_free(ne_00->object);
    pAVar1 = OBJ_dup(o);
    ne_00->object = pAVar1;
    if ((pAVar1 == (ASN1_OBJECT *)0x0) ||
       (iVar2 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar2 == 0)) {
      if (ne != (X509_NAME_ENTRY **)0x0) goto LAB_08162ff6;
      goto LAB_08162ffa;
    }
    if (ne == (X509_NAME_ENTRY **)0x0) goto LAB_08163008;
  }
  else {
    ASN1_OBJECT_free(ne_00->object);
    pAVar1 = OBJ_dup(o);
    ne_00->object = pAVar1;
    if ((pAVar1 == (ASN1_OBJECT *)0x0) ||
       (iVar2 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar2 == 0)) {
LAB_08162ff6:
      if (ne_00 != *ne) {
LAB_08162ffa:
        X509_NAME_ENTRY_free(ne_00);
      }
LAB_08163006:
      ne_00 = (X509_NAME_ENTRY *)0x0;
      goto LAB_08163008;
    }
  }
  if (*ne == (X509_NAME_ENTRY *)0x0) {
    *ne = ne_00;
  }
LAB_08163008:
  ASN1_OBJECT_free(o);
  return ne_00;
}

