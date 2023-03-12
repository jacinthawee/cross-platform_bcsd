
int ASN1_BIT_STRING_set(ASN1_BIT_STRING *a,uchar *d,int length)

{
  int iVar1;
  
  iVar1 = ASN1_STRING_set(a,d,length);
  return iVar1;
}

