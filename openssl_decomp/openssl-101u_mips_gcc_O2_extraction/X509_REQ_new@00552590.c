
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_REQ * X509_REQ_new(void)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)ASN1_item_new((ASN1_ITEM *)X509_REQ_it);
  return pXVar1;
}

