
int i2d_PKCS7_RECIP_INFO(PKCS7_RECIP_INFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_PKCS7_RECIP_INFO_it_000dbc20);
  return iVar1;
}

