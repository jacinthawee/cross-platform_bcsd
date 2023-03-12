
undefined4 callb(int param_1,X509_STORE_CTX *param_2)

{
  BIO *pBVar1;
  int n;
  X509 *a;
  X509_NAME *pXVar2;
  int iVar3;
  char *pcVar4;
  
  n = X509_STORE_CTX_get_error(param_2);
  if (n != 0x12) {
    if (param_1 != 0) {
      BIO_printf(bio_err,"error with certificate to be certified - should be self signed\n");
      return 0;
    }
    a = X509_STORE_CTX_get_current_cert(param_2);
    pBVar1 = bio_err;
    pXVar2 = X509_get_subject_name(a);
    print_name(pBVar1,0,pXVar2,0);
    pBVar1 = bio_err;
    iVar3 = X509_STORE_CTX_get_error_depth(param_2);
    pcVar4 = X509_verify_cert_error_string(n);
    BIO_printf(pBVar1,"error with certificate - error %d at depth %d\n%s\n",n,iVar3,pcVar4);
  }
  return 1;
}

