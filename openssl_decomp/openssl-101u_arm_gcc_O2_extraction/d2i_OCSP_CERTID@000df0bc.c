
OCSP_CERTID * d2i_OCSP_CERTID(OCSP_CERTID **a,uchar **in,long len)

{
  OCSP_CERTID *pOVar1;
  
  pOVar1 = (OCSP_CERTID *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_OCSP_CERTID_it_000df0c4);
  return pOVar1;
}
