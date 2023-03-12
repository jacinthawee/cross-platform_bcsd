
int X509_set_notAfter(X509 *x,ASN1_TIME *tm)

{
  X509_VAL *pXVar1;
  uint uVar2;
  
  if (x != (X509 *)0x0) {
    pXVar1 = x->cert_info->validity;
    if (pXVar1 == (X509_VAL *)0x0) {
      uVar2 = 0;
    }
    else {
      if ((pXVar1->notAfter != tm) && (tm = ASN1_STRING_dup(tm), tm != (ASN1_STRING *)0x0)) {
        ASN1_STRING_free(x->cert_info->validity->notAfter);
        x->cert_info->validity->notAfter = tm;
      }
      uVar2 = (uint)(tm != (ASN1_STRING *)0x0);
    }
    return uVar2;
  }
  return 0;
}

