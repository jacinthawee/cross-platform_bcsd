
OTHERNAME * d2i_OTHERNAME(OTHERNAME **a,uchar **in,long len)

{
  OTHERNAME *pOVar1;
  
  pOVar1 = (OTHERNAME *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_OTHERNAME_it_000d2a3c);
  return pOVar1;
}

