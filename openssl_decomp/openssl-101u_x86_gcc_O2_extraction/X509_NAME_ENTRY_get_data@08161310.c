
ASN1_STRING * X509_NAME_ENTRY_get_data(X509_NAME_ENTRY *ne)

{
  if (ne != (X509_NAME_ENTRY *)0x0) {
    return ne->value;
  }
  return (ASN1_STRING *)0x0;
}

