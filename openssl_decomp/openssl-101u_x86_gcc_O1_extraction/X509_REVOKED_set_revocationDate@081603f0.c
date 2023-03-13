
int X509_REVOKED_set_revocationDate(X509_REVOKED *r,ASN1_TIME *tm)

{
  if (r != (X509_REVOKED *)0x0) {
    if (r->revocationDate != tm) {
      tm = ASN1_STRING_dup(tm);
      if (tm != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(r->revocationDate);
        r->revocationDate = tm;
      }
    }
    return (uint)(tm != (ASN1_STRING *)0x0);
  }
  return 0;
}

