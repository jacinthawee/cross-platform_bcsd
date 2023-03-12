
X509_NAME * d2i_X509_NAME(X509_NAME **a,uchar **in,long len)

{
  X509_NAME *pXVar1;
  
  pXVar1 = (X509_NAME *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_X509_NAME_it_000b7de0);
  return pXVar1;
}

