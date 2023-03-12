
int X509_NAME_ENTRY_set_data(X509_NAME_ENTRY *ne,int type,uchar *bytes,int len)

{
  int iVar1;
  uint uVar2;
  ASN1_STRING *pAVar3;
  
  if (ne != (X509_NAME_ENTRY *)0x0) {
    uVar2 = count_leading_zeroes(bytes);
    uVar2 = uVar2 >> 5;
    if (len == 0) {
      uVar2 = 0;
    }
    if (uVar2 == 0) {
      if ((0 < type) && (type << 0x13 < 0)) {
        iVar1 = OBJ_obj2nid(ne->object);
        pAVar3 = ASN1_STRING_set_by_NID(&ne->value,bytes,len,type,iVar1);
        if (pAVar3 == (ASN1_STRING *)0x0) {
          return 0;
        }
        return 1;
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
          pAVar3 = ne->value;
          iVar1 = ASN1_PRINTABLE_type(bytes,len);
          pAVar3->type = iVar1;
          return 1;
        }
        ne->value->type = type;
        return 1;
      }
    }
  }
  return 0;
}

