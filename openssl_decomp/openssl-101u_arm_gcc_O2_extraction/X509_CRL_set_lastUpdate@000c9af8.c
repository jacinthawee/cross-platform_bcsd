
int X509_CRL_set_lastUpdate(X509_CRL *x,ASN1_TIME *tm)

{
  ASN1_TIME *pAVar1;
  
  if (x != (X509_CRL *)0x0) {
    pAVar1 = x->crl->lastUpdate;
    if ((pAVar1 != tm) && (pAVar1 = ASN1_STRING_dup(tm), pAVar1 != (ASN1_STRING *)0x0)) {
      ASN1_STRING_free(x->crl->lastUpdate);
      x->crl->lastUpdate = pAVar1;
    }
    if (pAVar1 != (ASN1_TIME *)0x0) {
      pAVar1 = (ASN1_TIME *)0x1;
    }
    return (int)pAVar1;
  }
  return 0;
}

