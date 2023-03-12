
RSA * d2i_RSAPublicKey(RSA **a,uchar **in,long len)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_RSAPublicKey_it_00098768);
  return pRVar1;
}

