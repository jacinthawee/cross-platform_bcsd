
int i2d_RSAPrivateKey(RSA *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_RSAPrivateKey_it_0009875c);
  return iVar1;
}

