
X509 * X509_dup(X509 *x509)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)ASN1_item_dup((ASN1_ITEM *)X509_it,x509);
  return pXVar1;
}

