
int i2d_AUTHORITY_INFO_ACCESS(AUTHORITY_INFO_ACCESS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_AUTHORITY_INFO_ACCESS_it_000d7638);
  return iVar1;
}
