
int X509V3_extensions_print
              (BIO *out,char *title,stack_st_X509_EXTENSION *exts,ulong flag,int indent)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  char *pcVar3;
  
  iVar1 = sk_num(&exts->stack);
  if (0 < iVar1) {
    if (title != (char *)0x0) {
      BIO_printf(out,"%*s%s:\n",indent,&DAT_081eca46,title);
      indent = indent + 4;
    }
    for (iVar1 = 0; iVar2 = sk_num(&exts->stack), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      ex = (X509_EXTENSION *)sk_value(&exts->stack,iVar1);
      if ((indent != 0) && (iVar2 = BIO_printf(out,"%*s",indent,&DAT_081eca46), iVar2 < 1)) {
        return 0;
      }
      a = X509_EXTENSION_get_object(ex);
      i2a_ASN1_OBJECT(out,a);
      iVar2 = X509_EXTENSION_get_critical(ex);
      pcVar3 = "";
      if (iVar2 != 0) {
        pcVar3 = "critical";
      }
      iVar2 = BIO_printf(out,": %s\n",pcVar3);
      if (iVar2 < 1) {
        return 0;
      }
      iVar2 = X509V3_EXT_print(out,ex,flag,indent + 4);
      if (iVar2 == 0) {
        BIO_printf(out,"%*s",indent + 4,&DAT_081eca46);
        ASN1_STRING_print(out,ex->value);
      }
      iVar2 = BIO_write(out,&DAT_081f15cb,1);
      if (iVar2 < 1) {
        return 0;
      }
    }
  }
  return 1;
}

