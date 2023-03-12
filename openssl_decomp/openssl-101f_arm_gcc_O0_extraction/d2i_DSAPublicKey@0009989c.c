
DSA * d2i_DSAPublicKey(DSA **a,uchar **pp,long length)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,(ASN1_ITEM *)PTR_DSAPublicKey_it_000998a4
                               );
  return pDVar1;
}

