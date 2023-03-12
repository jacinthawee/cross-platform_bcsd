
int i2d_X509_EXTENSIONS(X509_EXTENSIONS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_X509_EXTENSIONS_it_000c09c8);
  return iVar1;
}

