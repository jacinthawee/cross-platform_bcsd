
int i2d_X509_NAME(X509_NAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_X509_NAME_it_000b7dec);
  return iVar1;
}

