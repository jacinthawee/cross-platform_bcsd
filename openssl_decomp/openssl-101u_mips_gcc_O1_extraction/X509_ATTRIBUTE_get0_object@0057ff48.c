
ASN1_OBJECT * X509_ATTRIBUTE_get0_object(X509_ATTRIBUTE *attr)

{
  if (attr != (X509_ATTRIBUTE *)0x0) {
    return attr->object;
  }
  return (ASN1_OBJECT *)0x0;
}

