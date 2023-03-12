
ASN1_OBJECT * X509_EXTENSION_get_object(X509_EXTENSION *ex)

{
  if (ex != (X509_EXTENSION *)0x0) {
    return ex->object;
  }
  return (ASN1_OBJECT *)0x0;
}

