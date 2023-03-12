
int i2d_PKCS7_SIGNED(PKCS7_SIGNED *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_PKCS7_SIGNED_it_000dbb60);
  return iVar1;
}

