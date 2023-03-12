
int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *str,uchar *data,int len)

{
  int iVar1;
  
  iVar1 = ASN1_STRING_set(str,data,len);
  return iVar1;
}

