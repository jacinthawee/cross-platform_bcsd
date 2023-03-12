
int i2d_NETSCAPE_X509(NETSCAPE_X509 *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)NETSCAPE_X509_it);
  return iVar1;
}

