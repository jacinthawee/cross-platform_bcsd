
OCSP_CRLID * d2i_OCSP_CRLID(OCSP_CRLID **a,uchar **in,long len)

{
  OCSP_CRLID *pOVar1;
  
  pOVar1 = (OCSP_CRLID *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_OCSP_CRLID_it_000e141c);
  return pOVar1;
}

