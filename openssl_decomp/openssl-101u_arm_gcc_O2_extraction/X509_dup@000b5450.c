
X509 * X509_dup(X509 *x509)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)ASN1_item_dup((ASN1_ITEM *)PTR_X509_it_000b5458,x509);
  return pXVar1;
}

