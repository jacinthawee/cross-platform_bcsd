
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_REVOKED * X509_REVOKED_new(void)

{
  X509_REVOKED *pXVar1;
  
  pXVar1 = (X509_REVOKED *)ASN1_item_new((ASN1_ITEM *)X509_REVOKED_it);
  return pXVar1;
}

