
void TS_X509_ALGOR_print_bio(BIO *param_1,ASN1_OBJECT **param_2)

{
  int n;
  char *pcVar1;
  
  n = OBJ_obj2nid(*param_2);
  pcVar1 = "UNKNOWN";
  if (n != 0) {
    pcVar1 = OBJ_nid2ln(n);
  }
  BIO_printf(param_1,"Hash Algorithm: %s\n",pcVar1);
  return;
}

