
SXNET * d2i_SXNET(SXNET **a,uchar **in,long len)

{
  SXNET *pSVar1;
  
  pSVar1 = (SXNET *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_SXNET_it_000d294c);
  return pSVar1;
}

