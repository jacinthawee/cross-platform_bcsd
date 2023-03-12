
int X509V3_extensions_print
              (BIO *out,char *title,stack_st_X509_EXTENSION *exts,ulong flag,int indent)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  int iVar3;
  
  iVar1 = sk_num(&exts->stack);
  if (iVar1 < 1) {
    return 1;
  }
  iVar1 = indent;
  if (title != (char *)0x0) {
    iVar1 = indent + 4;
    BIO_printf(out,"%*s%s:\n",indent,"",title);
  }
  iVar3 = 0;
  do {
    iVar2 = sk_num(&exts->stack);
    if (iVar2 <= iVar3) {
      return 1;
    }
    ex = (X509_EXTENSION *)sk_value(&exts->stack,iVar3);
    if ((iVar1 != 0) && (iVar2 = BIO_printf(out,"%*s",iVar1,""), iVar2 < 1)) {
      return 0;
    }
    a = X509_EXTENSION_get_object(ex);
    i2a_ASN1_OBJECT(out,a);
    X509_EXTENSION_get_critical(ex);
    iVar2 = BIO_printf(out,": %s\n");
    if (iVar2 < 1) {
      return 0;
    }
    iVar2 = X509V3_EXT_print(out,ex,flag,iVar1 + 4);
    if (iVar2 == 0) {
      BIO_printf(out,"%*s",iVar1 + 4,"");
      ASN1_STRING_print(out,ex->value);
    }
    iVar2 = BIO_write(out,"\n",1);
    iVar3 = iVar3 + 1;
  } while (0 < iVar2);
  return 0;
}

