
int X509_set_notBefore(X509 *x,ASN1_TIME *tm)

{
  X509_VAL *pXVar1;
  ASN1_TIME *pAVar2;
  
  if (x == (X509 *)0x0) {
    return 0;
  }
  pXVar1 = x->cert_info->validity;
  if (pXVar1 != (X509_VAL *)0x0) {
    pAVar2 = pXVar1->notBefore;
    if ((pAVar2 != tm) && (pAVar2 = ASN1_STRING_dup(tm), pAVar2 != (ASN1_STRING *)0x0)) {
      ASN1_STRING_free(x->cert_info->validity->notBefore);
      x->cert_info->validity->notBefore = pAVar2;
    }
    if (pAVar2 != (ASN1_TIME *)0x0) {
      pAVar2 = (ASN1_TIME *)0x1;
    }
    return (int)pAVar2;
  }
  return 0;
}

