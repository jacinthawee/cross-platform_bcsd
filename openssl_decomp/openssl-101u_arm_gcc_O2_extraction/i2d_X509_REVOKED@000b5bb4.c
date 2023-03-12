
int i2d_X509_REVOKED(X509_REVOKED *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_X509_REVOKED_it_000b5bbc);
  return iVar1;
}

