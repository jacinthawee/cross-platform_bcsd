
int i2d_X509_CRL(X509_CRL *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_X509_CRL_it_000b5c1c);
  return iVar1;
}

