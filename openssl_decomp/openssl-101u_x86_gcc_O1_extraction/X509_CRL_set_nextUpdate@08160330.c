
int X509_CRL_set_nextUpdate(X509_CRL *x,ASN1_TIME *tm)

{
  if (x != (X509_CRL *)0x0) {
    if (x->crl->nextUpdate != tm) {
      tm = ASN1_STRING_dup(tm);
      if (tm != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(x->crl->nextUpdate);
        x->crl->nextUpdate = tm;
      }
    }
    return (uint)(tm != (ASN1_STRING *)0x0);
  }
  return 0;
}

