
void SSL_CTX_set_cert_store(SSL_CTX *param_1,X509_STORE *param_2)

{
  if (param_1->cert_store != (x509_store_st *)0x0) {
    (*(code *)PTR_X509_STORE_free_006a8384)();
  }
  param_1->cert_store = param_2;
  return;
}

