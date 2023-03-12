
int X509_set_serialNumber(X509 *x,ASN1_INTEGER *serial)

{
  if (x != (X509 *)0x0) {
    if (x->cert_info->serialNumber != serial) {
      serial = ASN1_STRING_dup(serial);
      if (serial != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(x->cert_info->serialNumber);
        x->cert_info->serialNumber = serial;
      }
    }
    return (uint)(serial != (ASN1_STRING *)0x0);
  }
  return 0;
}

