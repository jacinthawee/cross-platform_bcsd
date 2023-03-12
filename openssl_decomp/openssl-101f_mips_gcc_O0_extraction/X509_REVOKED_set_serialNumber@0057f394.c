
int X509_REVOKED_set_serialNumber(X509_REVOKED *x,ASN1_INTEGER *serial)

{
  if (x != (X509_REVOKED *)0x0) {
    if ((x->serialNumber != serial) &&
       (serial = ASN1_STRING_dup(serial), serial != (ASN1_STRING *)0x0)) {
      ASN1_STRING_free(x->serialNumber);
      x->serialNumber = serial;
    }
    return (uint)(serial != (ASN1_STRING *)0x0);
  }
  return 0;
}

