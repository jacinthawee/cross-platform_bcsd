
int X509_REVOKED_set_revocationDate(X509_REVOKED *r,ASN1_TIME *tm)

{
  ASN1_TIME *pAVar1;
  
  if (r != (X509_REVOKED *)0x0) {
    pAVar1 = r->revocationDate;
    if ((pAVar1 != tm) && (pAVar1 = ASN1_STRING_dup(tm), pAVar1 != (ASN1_STRING *)0x0)) {
      ASN1_STRING_free(r->revocationDate);
      r->revocationDate = pAVar1;
    }
    if (pAVar1 != (ASN1_TIME *)0x0) {
      pAVar1 = (ASN1_TIME *)0x1;
    }
    return (int)pAVar1;
  }
  return 0;
}

