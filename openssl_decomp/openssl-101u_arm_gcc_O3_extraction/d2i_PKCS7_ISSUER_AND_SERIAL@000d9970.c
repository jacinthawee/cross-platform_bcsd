
PKCS7_ISSUER_AND_SERIAL *
d2i_PKCS7_ISSUER_AND_SERIAL(PKCS7_ISSUER_AND_SERIAL **a,uchar **in,long len)

{
  PKCS7_ISSUER_AND_SERIAL *pPVar1;
  
  pPVar1 = (PKCS7_ISSUER_AND_SERIAL *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,
                         (ASN1_ITEM *)PTR_PKCS7_ISSUER_AND_SERIAL_it_000d9978);
  return pPVar1;
}

