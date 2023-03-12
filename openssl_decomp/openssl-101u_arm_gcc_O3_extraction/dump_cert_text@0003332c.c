
undefined4 dump_cert_text(BIO *param_1,X509 *param_2)

{
  X509_NAME *pXVar1;
  char *pcVar2;
  
  pXVar1 = X509_get_subject_name(param_2);
  pcVar2 = X509_NAME_oneline(pXVar1,(char *)0x0,0);
  BIO_puts(param_1,"subject=");
  BIO_puts(param_1,pcVar2);
  CRYPTO_free(pcVar2);
  pXVar1 = X509_get_issuer_name(param_2);
  pcVar2 = X509_NAME_oneline(pXVar1,(char *)0x0,0);
  BIO_puts(param_1,"\nissuer=");
  BIO_puts(param_1,pcVar2);
  BIO_puts(param_1,"\n");
  CRYPTO_free(pcVar2);
  return 0;
}

