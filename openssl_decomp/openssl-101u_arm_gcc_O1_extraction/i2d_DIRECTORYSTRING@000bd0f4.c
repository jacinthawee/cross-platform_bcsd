
int i2d_DIRECTORYSTRING(ASN1_STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_DIRECTORYSTRING_it_000bd0fc);
  return iVar1;
}
