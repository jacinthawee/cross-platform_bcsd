
void PKCS7_DIGEST_free(PKCS7_DIGEST *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_PKCS7_DIGEST_it_000dbcf8);
  return;
}

