
PKCS7_DIGEST * d2i_PKCS7_DIGEST(PKCS7_DIGEST **a,uchar **in,long len)

{
  PKCS7_DIGEST *pPVar1;
  
  pPVar1 = (PKCS7_DIGEST *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_PKCS7_DIGEST_it_000d9a98);
  return pPVar1;
}

