
int i2d_PKCS12_MAC_DATA(PKCS12_MAC_DATA *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_PKCS12_MAC_DATA_it_000dd35c);
  return iVar1;
}

