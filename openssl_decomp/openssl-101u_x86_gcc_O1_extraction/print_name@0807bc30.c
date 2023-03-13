
void print_name(BIO *param_1,char *param_2,X509_NAME *param_3,uint param_4)

{
  int indent;
  char *buf;
  
  if (param_2 != (char *)0x0) {
    BIO_puts(param_1,param_2);
  }
  if ((param_4 & 0xf0000) == 0x40000) {
    BIO_puts(param_1,"\n");
    indent = 4;
  }
  else {
    indent = 0;
    if (param_4 == 0) {
      buf = X509_NAME_oneline(param_3,(char *)0x0,0);
      BIO_puts(param_1,buf);
      BIO_puts(param_1,"\n");
      CRYPTO_free(buf);
      return;
    }
  }
  X509_NAME_print_ex(param_1,param_3,indent,param_4);
  BIO_puts(param_1,"\n");
  return;
}

