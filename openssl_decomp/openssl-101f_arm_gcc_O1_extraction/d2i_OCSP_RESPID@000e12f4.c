
OCSP_RESPID * d2i_OCSP_RESPID(OCSP_RESPID **a,uchar **in,long len)

{
  OCSP_RESPID *pOVar1;
  
  pOVar1 = (OCSP_RESPID *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_OCSP_RESPID_it_000e12fc);
  return pOVar1;
}
