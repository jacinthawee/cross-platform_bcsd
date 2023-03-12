
void ASN1_STRING_set0(ASN1_STRING *str,void *data,int len)

{
  if (str->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  str->data = (uchar *)data;
  str->length = len;
  return;
}

