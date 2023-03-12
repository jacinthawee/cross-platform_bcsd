
undefined4 TS_ext_print_bio(BIO *param_1,stack_st_X509_EXTENSION *param_2)

{
  int iVar1;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  int iVar2;
  char *pcVar3;
  int loc;
  
  BIO_printf(param_1,"Extensions:\n");
  iVar1 = X509v3_get_ext_count(param_2);
  if (0 < iVar1) {
    loc = 0;
    do {
      ex = X509v3_get_ext(param_2,loc);
      a = X509_EXTENSION_get_object(ex);
      i2a_ASN1_OBJECT(param_1,a);
      iVar2 = X509_EXTENSION_get_critical(ex);
      pcVar3 = "";
      if (iVar2 != 0) {
        pcVar3 = "critical";
      }
      BIO_printf(param_1,": %s\n",pcVar3);
      iVar2 = X509V3_EXT_print(param_1,ex,0,4);
      if (iVar2 == 0) {
        BIO_printf(param_1,"%4s",&DAT_081ec74a);
        ASN1_STRING_print(param_1,ex->value);
      }
      loc = loc + 1;
      BIO_write(param_1,&DAT_081f11d3,1);
    } while (iVar1 != loc);
  }
  return 1;
}

