
int i2d_PKCS12_BAGS(PKCS12_BAGS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_PKCS12_BAGS_it_000dd38c);
  return iVar1;
}

