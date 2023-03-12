
int i2d_PKCS7_ENCRYPT(PKCS7_ENCRYPT *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_PKCS7_ENCRYPT_it_000d9a74);
  return iVar1;
}

