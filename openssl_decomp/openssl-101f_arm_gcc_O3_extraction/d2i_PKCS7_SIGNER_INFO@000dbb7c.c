
PKCS7_SIGNER_INFO * d2i_PKCS7_SIGNER_INFO(PKCS7_SIGNER_INFO **a,uchar **in,long len)

{
  PKCS7_SIGNER_INFO *pPVar1;
  
  pPVar1 = (PKCS7_SIGNER_INFO *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_PKCS7_SIGNER_INFO_it_000dbb84);
  return pPVar1;
}

