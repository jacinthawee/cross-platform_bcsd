
int i2d_PKCS7_ENVELOPE(PKCS7_ENVELOPE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_PKCS7_ENVELOPE_it_000d99b4);
  return iVar1;
}

