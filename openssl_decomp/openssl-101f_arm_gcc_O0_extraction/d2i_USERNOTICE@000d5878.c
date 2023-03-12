
USERNOTICE * d2i_USERNOTICE(USERNOTICE **a,uchar **in,long len)

{
  USERNOTICE *pUVar1;
  
  pUVar1 = (USERNOTICE *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_USERNOTICE_it_000d5880);
  return pUVar1;
}

