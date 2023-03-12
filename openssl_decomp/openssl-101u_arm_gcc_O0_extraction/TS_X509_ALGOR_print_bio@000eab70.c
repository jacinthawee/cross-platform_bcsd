
void TS_X509_ALGOR_print_bio(BIO *param_1,ASN1_OBJECT **param_2)

{
  int n;
  
  n = OBJ_obj2nid(*param_2);
  if (n != 0) {
    OBJ_nid2ln(n);
  }
  BIO_vprintf(param_1,"Hash Algorithm: %s\n",&stack0xfffffff8);
  return;
}

