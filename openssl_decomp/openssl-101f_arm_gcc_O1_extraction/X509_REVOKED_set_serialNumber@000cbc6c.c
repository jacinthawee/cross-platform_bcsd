
int X509_REVOKED_set_serialNumber(X509_REVOKED *x,ASN1_INTEGER *serial)

{
  ASN1_INTEGER *pAVar1;
  
  if (x != (X509_REVOKED *)0x0) {
    pAVar1 = x->serialNumber;
    if ((pAVar1 != serial) && (pAVar1 = ASN1_STRING_dup(serial), pAVar1 != (ASN1_STRING *)0x0)) {
      ASN1_STRING_free(x->serialNumber);
      x->serialNumber = pAVar1;
    }
    if (pAVar1 != (ASN1_INTEGER *)0x0) {
      pAVar1 = (ASN1_INTEGER *)0x1;
    }
    return (int)pAVar1;
  }
  return 0;
}

