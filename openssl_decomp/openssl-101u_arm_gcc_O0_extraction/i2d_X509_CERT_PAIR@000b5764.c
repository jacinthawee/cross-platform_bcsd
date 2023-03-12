
int i2d_X509_CERT_PAIR(X509_CERT_PAIR *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_X509_CERT_PAIR_it_000b576c);
  return iVar1;
}

