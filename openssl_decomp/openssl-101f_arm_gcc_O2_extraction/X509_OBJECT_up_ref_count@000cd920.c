
void X509_OBJECT_up_ref_count(X509_OBJECT *a)

{
  if (a->type != 1) {
    if (a->type == 2) {
      CRYPTO_add_lock(&((a->data).x509)->valid,1,6,"x509_lu.c",0x198);
    }
    return;
  }
  CRYPTO_add_lock(&((a->data).x509)->references,1,3,"x509_lu.c",0x195);
  return;
}
