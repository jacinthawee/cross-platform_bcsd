
GENERAL_NAMES * d2i_GENERAL_NAMES(GENERAL_NAMES **a,uchar **in,long len)

{
  GENERAL_NAMES *pGVar1;
  
  pGVar1 = (GENERAL_NAMES *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)GENERAL_NAMES_it);
  return pGVar1;
}

