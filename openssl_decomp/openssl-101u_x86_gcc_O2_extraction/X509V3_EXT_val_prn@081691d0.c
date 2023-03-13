
void X509V3_EXT_val_prn(BIO *out,stack_st_CONF_VALUE *val,int indent,int ml)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  char *buf;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  if (val != (stack_st_CONF_VALUE *)0x0) {
    if ((ml == 0) || (iVar1 = sk_num(&val->stack), iVar1 == 0)) {
      puVar5 = &DAT_081eca46;
      pcVar4 = (char *)indent;
      BIO_printf(out,"%*s",indent,&DAT_081eca46);
      iVar1 = sk_num(&val->stack);
      if (iVar1 == 0) {
        BIO_puts(out,"<EMPTY>\n");
      }
      if (ml == 0) {
        for (; iVar1 = sk_num(&val->stack), ml < iVar1; ml = ml + 1) {
          if (0 < ml) {
            BIO_printf(out,", ",pcVar4,puVar5);
          }
          pvVar3 = sk_value(&val->stack,ml);
          buf = *(char **)((int)pvVar3 + 4);
          if (buf == (char *)0x0) {
            BIO_puts(out,*(char **)((int)pvVar3 + 8));
          }
          else {
            puVar6 = *(undefined1 **)((int)pvVar3 + 8);
            if (puVar6 == (undefined1 *)0x0) {
              BIO_puts(out,buf);
            }
            else {
              BIO_printf(out,"%s:%s",buf,puVar6);
              pcVar4 = buf;
              puVar5 = puVar6;
            }
          }
        }
        return;
      }
    }
    for (iVar1 = 0; iVar2 = sk_num(&val->stack), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      BIO_printf(out,"%*s",indent,&DAT_081eca46);
      pvVar3 = sk_value(&val->stack,iVar1);
      pcVar4 = *(char **)((int)pvVar3 + 4);
      if (pcVar4 == (char *)0x0) {
        BIO_puts(out,*(char **)((int)pvVar3 + 8));
      }
      else if (*(int *)((int)pvVar3 + 8) == 0) {
        BIO_puts(out,pcVar4);
      }
      else {
        BIO_printf(out,"%s:%s",pcVar4,*(int *)((int)pvVar3 + 8));
      }
      BIO_puts(out,"\n");
    }
  }
  return;
}

