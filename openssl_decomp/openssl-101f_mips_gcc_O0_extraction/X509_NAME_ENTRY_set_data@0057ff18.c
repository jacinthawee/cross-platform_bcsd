
int X509_NAME_ENTRY_set_data(X509_NAME_ENTRY *ne,int type,uchar *bytes,int len)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  
  if (ne == (X509_NAME_ENTRY *)0x0) {
    return 0;
  }
  if (bytes == (uchar *)0x0) {
    if (len != 0) {
      return 0;
    }
    if ((0 < type) && ((type & 0x1000U) != 0)) goto LAB_0058003c;
  }
  else {
    if ((0 < type) && ((type & 0x1000U) != 0)) {
LAB_0058003c:
      iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ne->object);
      pAVar2 = ASN1_STRING_set_by_NID(&ne->value,bytes,len,type,iVar1);
      return (uint)(pAVar2 != (ASN1_STRING *)0x0);
    }
    if (len < 0) {
      len = (*(code *)PTR_strlen_006aab30)(bytes);
      iVar1 = ASN1_STRING_set(ne->value,bytes,len);
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_0057ff88;
    }
  }
  iVar1 = ASN1_STRING_set(ne->value,bytes,len);
  if (iVar1 == 0) {
    return 0;
  }
LAB_0057ff88:
  if (type != -1) {
    if (type == -2) {
      pAVar2 = ne->value;
      iVar1 = (*(code *)PTR_ASN1_PRINTABLE_type_006a8234)(bytes,len);
      pAVar2->type = iVar1;
    }
    else {
      ne->value->type = type;
    }
  }
  return 1;
}

