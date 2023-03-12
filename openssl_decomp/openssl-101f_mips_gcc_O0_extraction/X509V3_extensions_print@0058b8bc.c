
int X509V3_extensions_print
              (BIO *out,char *title,stack_st_X509_EXTENSION *exts,ulong flag,int indent)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *ex;
  ASN1_OBJECT *pAVar3;
  
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(exts);
  if (0 < iVar1) {
    if (title != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)(out,"%*s%s:\n",indent,"",title);
      indent = indent + 4;
    }
    for (iVar1 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(exts), iVar1 < iVar2; iVar1 = iVar1 + 1)
    {
      ex = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a7f24)(exts,iVar1);
      if ((indent != 0) &&
         (iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066df84,indent,""), iVar2 < 1)) {
        return 0;
      }
      pAVar3 = X509_EXTENSION_get_object(ex);
      (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(out,pAVar3);
      iVar2 = X509_EXTENSION_get_critical(ex);
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(out,": %s\n","");
      }
      else {
        iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(out,": %s\n","critical");
      }
      if (iVar2 < 1) {
        return 0;
      }
      iVar2 = X509V3_EXT_print(out,ex,flag,indent + 4);
      if (iVar2 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066df84,indent + 4,"");
        (*(code *)PTR_ASN1_STRING_print_006a9e74)(out,ex->value);
      }
      iVar2 = (*(code *)PTR_BIO_write_006a7f14)(out,"\n",1);
      if (iVar2 < 1) {
        return 0;
      }
    }
  }
  return 1;
}

