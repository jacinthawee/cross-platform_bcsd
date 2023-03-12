
void ocsp_nonce_free(ASN1_STRING *a)

{
  if (a == (ASN1_STRING *)0x0) {
    return;
  }
  if ((a->data != (uchar *)0x0) && ((*(byte *)&a->flags & 0x10) == 0)) {
    CRYPTO_free(a->data);
    CRYPTO_free(a);
    return;
  }
  CRYPTO_free(a);
  return;
}
