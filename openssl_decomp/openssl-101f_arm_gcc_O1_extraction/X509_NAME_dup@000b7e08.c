
X509_NAME * X509_NAME_dup(X509_NAME *xn)

{
  X509_NAME *pXVar1;
  
  pXVar1 = (X509_NAME *)ASN1_item_dup((ASN1_ITEM *)PTR_X509_NAME_it_000b7e10,xn);
  return pXVar1;
}

