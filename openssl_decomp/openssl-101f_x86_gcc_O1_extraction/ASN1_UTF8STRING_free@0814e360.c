
void ASN1_UTF8STRING_free(ASN1_UTF8STRING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_UTF8STRING_it);
  return;
}

