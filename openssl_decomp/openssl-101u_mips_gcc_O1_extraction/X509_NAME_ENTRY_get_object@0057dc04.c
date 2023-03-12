
ASN1_OBJECT * X509_NAME_ENTRY_get_object(X509_NAME_ENTRY *ne)

{
  if (ne != (X509_NAME_ENTRY *)0x0) {
    return ne->object;
  }
  return (ASN1_OBJECT *)0x0;
}

