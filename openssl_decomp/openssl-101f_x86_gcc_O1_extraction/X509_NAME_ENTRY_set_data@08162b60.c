
int X509_NAME_ENTRY_set_data(X509_NAME_ENTRY *ne,int type,uchar *bytes,int len)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  
  if ((ne != (X509_NAME_ENTRY *)0x0) && ((bytes != (uchar *)0x0 || (len == 0)))) {
    if ((0 < type) && ((type & 0x1000U) != 0)) {
      iVar1 = OBJ_obj2nid(ne->object);
      pAVar2 = ASN1_STRING_set_by_NID(&ne->value,bytes,len,type,iVar1);
      return (uint)(pAVar2 != (ASN1_STRING *)0x0);
    }
    if (len < 0) {
      len = strlen((char *)bytes);
    }
    iVar1 = ASN1_STRING_set(ne->value,bytes,len);
    if (iVar1 != 0) {
      if (type == -1) {
        return 1;
      }
      if (type == -2) {
        pAVar2 = ne->value;
        iVar1 = ASN1_PRINTABLE_type(bytes,len);
        pAVar2->type = iVar1;
        return 1;
      }
      ne->value->type = type;
      return 1;
    }
  }
  return 0;
}

