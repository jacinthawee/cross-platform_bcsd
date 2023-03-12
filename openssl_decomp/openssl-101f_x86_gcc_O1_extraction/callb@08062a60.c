
undefined4 callb(int param_1,X509_STORE_CTX *param_2)

{
  int n;
  X509 *a;
  X509_NAME *pXVar1;
  char *pcVar2;
  int iVar3;
  
  n = X509_STORE_CTX_get_error(param_2);
  if (n == 0x12) {
    return 1;
  }
  if (param_1 == 0) {
    a = X509_STORE_CTX_get_current_cert(param_2);
    pXVar1 = X509_get_subject_name(a);
    print_name(bio_err,0,pXVar1,0);
    pcVar2 = X509_verify_cert_error_string(n);
    iVar3 = X509_STORE_CTX_get_error_depth(param_2);
    BIO_printf(bio_err,"error with certificate - error %d at depth %d\n%s\n",n,iVar3,pcVar2);
    return 1;
  }
  BIO_printf(bio_err,"error with certificate to be certified - should be self signed\n");
  return 0;
}

