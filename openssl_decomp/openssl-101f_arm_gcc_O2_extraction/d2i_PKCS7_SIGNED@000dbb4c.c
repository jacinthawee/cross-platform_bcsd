
PKCS7_SIGNED * d2i_PKCS7_SIGNED(PKCS7_SIGNED **a,uchar **in,long len)

{
  PKCS7_SIGNED *pPVar1;
  
  pPVar1 = (PKCS7_SIGNED *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_PKCS7_SIGNED_it_000dbb54);
  return pPVar1;
}

