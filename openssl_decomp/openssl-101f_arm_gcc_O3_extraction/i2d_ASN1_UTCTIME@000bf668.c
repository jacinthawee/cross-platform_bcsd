
int i2d_ASN1_UTCTIME(ASN1_UTCTIME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_ASN1_UTCTIME_it_000bf670);
  return iVar1;
}
