
int i2d_ASN1_UTF8STRING(ASN1_UTF8STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_ASN1_UTF8STRING_it_000bce8c);
  return iVar1;
}

