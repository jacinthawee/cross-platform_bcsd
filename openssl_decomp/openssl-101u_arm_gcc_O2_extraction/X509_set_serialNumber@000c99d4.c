
int X509_set_serialNumber(X509 *x,ASN1_INTEGER *serial)

{
  ASN1_INTEGER *pAVar1;
  
  if (x != (X509 *)0x0) {
    pAVar1 = x->cert_info->serialNumber;
    if ((pAVar1 != serial) && (pAVar1 = ASN1_STRING_dup(serial), pAVar1 != (ASN1_STRING *)0x0)) {
      ASN1_STRING_free(x->cert_info->serialNumber);
      x->cert_info->serialNumber = pAVar1;
    }
    if (pAVar1 != (ASN1_INTEGER *)0x0) {
      pAVar1 = (ASN1_INTEGER *)0x1;
    }
    return (int)pAVar1;
  }
  return 0;
}

