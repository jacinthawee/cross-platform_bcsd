
void ASN1_OBJECT_free(ASN1_OBJECT *a)

{
  uint uVar1;
  
  if (a != (ASN1_OBJECT *)0x0) {
    uVar1 = a->flags;
    if ((uVar1 & 4) != 0) {
      if (a->sn != (char *)0x0) {
        CRYPTO_free(a->sn);
      }
      if (a->ln != (char **)0x0) {
        CRYPTO_free(a->ln);
      }
      uVar1 = a->flags;
      a->ln = (char **)0x0;
      a->sn = (char *)0x0;
    }
    if ((uVar1 & 8) != 0) {
      if (a->data != (uchar *)0x0) {
        CRYPTO_free(a->data);
        uVar1 = a->flags;
      }
      a->data = (uchar *)0x0;
      a->length = 0;
    }
    if ((uVar1 & 1) != 0) {
      CRYPTO_free(a);
      return;
    }
  }
  return;
}

