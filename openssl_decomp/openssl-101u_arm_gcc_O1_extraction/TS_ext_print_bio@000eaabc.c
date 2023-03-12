
undefined4 TS_ext_print_bio(BIO *param_1,stack_st_X509_EXTENSION *param_2)

{
  int iVar1;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  int iVar2;
  int loc;
  
  BIO_printf(param_1,"Extensions:\n");
  iVar1 = X509v3_get_ext_count(param_2);
  if (0 < iVar1) {
    loc = 0;
    do {
      ex = X509v3_get_ext(param_2,loc);
      loc = loc + 1;
      a = X509_EXTENSION_get_object(ex);
      i2a_ASN1_OBJECT(param_1,a);
      X509_EXTENSION_get_critical(ex);
      BIO_printf(param_1,": %s\n");
      iVar2 = X509V3_EXT_print(param_1,ex,0,4);
      if (iVar2 == 0) {
        BIO_printf(param_1,"%4s","");
        ASN1_STRING_print(param_1,ex->value);
      }
      BIO_write(param_1,"\n",1);
    } while (loc != iVar1);
  }
  return 1;
}

