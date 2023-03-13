
int X509_set_notAfter(X509 *x,ASN1_TIME *tm)

{
  X509_VAL *pXVar1;
  
  if ((x != (X509 *)0x0) && (pXVar1 = x->cert_info->validity, pXVar1 != (X509_VAL *)0x0)) {
    if (pXVar1->notAfter != tm) {
      tm = ASN1_STRING_dup(tm);
      if (tm != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(x->cert_info->validity->notAfter);
        x->cert_info->validity->notAfter = tm;
      }
    }
    return (uint)(tm != (ASN1_STRING *)0x0);
  }
  return 0;
}

