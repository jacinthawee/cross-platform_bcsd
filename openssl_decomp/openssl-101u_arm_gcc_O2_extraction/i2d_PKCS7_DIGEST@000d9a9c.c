
int i2d_PKCS7_DIGEST(PKCS7_DIGEST *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_PKCS7_DIGEST_it_000d9aa4);
  return iVar1;
}

