
OCSP_ONEREQ * d2i_OCSP_ONEREQ(OCSP_ONEREQ **a,uchar **in,long len)

{
  OCSP_ONEREQ *pOVar1;
  
  pOVar1 = (OCSP_ONEREQ *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_OCSP_ONEREQ_it_000e120c);
  return pOVar1;
}

