
X509_REQ * d2i_X509_REQ(X509_REQ **a,uchar **in,long len)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_X509_REQ_it_000b7450);
  return pXVar1;
}

