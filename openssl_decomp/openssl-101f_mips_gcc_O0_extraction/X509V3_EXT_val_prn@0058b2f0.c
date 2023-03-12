
void X509V3_EXT_val_prn(BIO *out,stack_st_CONF_VALUE *val,int indent,int ml)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (val != (stack_st_CONF_VALUE *)0x0) {
    if ((ml == 0) || (iVar1 = (*(code *)PTR_sk_num_006a7f2c)(val), iVar1 == 0)) {
      (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066df84,indent,"");
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(val);
      if (iVar1 == 0) {
        (*(code *)PTR_BIO_puts_006a8058)(out,"<EMPTY>\n");
      }
      if (ml == 0) {
        iVar1 = (*(code *)PTR_sk_num_006a7f2c)(val);
        if (iVar1 < 1) {
          return;
        }
        do {
          if (0 < ml) {
            (*(code *)PTR_BIO_printf_006a7f38)(out,", ");
          }
          iVar1 = (*(code *)PTR_sk_value_006a7f24)(val,ml);
          iVar2 = *(int *)(iVar1 + 4);
          if (iVar2 == 0) {
            (*(code *)PTR_BIO_puts_006a8058)(out,*(undefined4 *)(iVar1 + 8),0);
          }
          else if (*(int *)(iVar1 + 8) == 0) {
            (*(code *)PTR_BIO_puts_006a8058)(out,iVar2,iVar2,0);
          }
          else {
            (*(code *)PTR_BIO_printf_006a7f38)(out,"%s:%s");
          }
          ml = ml + 1;
          iVar1 = (*(code *)PTR_sk_num_006a7f2c)(val);
        } while (ml < iVar1);
        return;
      }
    }
    for (iVar1 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(val), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066df84,indent,"");
      iVar2 = (*(code *)PTR_sk_value_006a7f24)(val,iVar1);
      iVar3 = *(int *)(iVar2 + 4);
      if (iVar3 == 0) {
        (*(code *)PTR_BIO_puts_006a8058)(out,*(undefined4 *)(iVar2 + 8));
      }
      else if (*(int *)(iVar2 + 8) == 0) {
        (*(code *)PTR_BIO_puts_006a8058)(out,iVar3);
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(out,"%s:%s",iVar3);
      }
      (*(code *)PTR_BIO_puts_006a8058)(out,"\n");
    }
  }
  return;
}

