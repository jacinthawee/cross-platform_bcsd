
int UI_dup_input_boolean
              (UI *ui,char *prompt,char *action_desc,char *ok_chars,char *cancel_chars,int flags,
              char *result_buf)

{
  char *ptr;
  char *ptr_00;
  char *ptr_01;
  char *pcVar1;
  int iVar2;
  
  if (prompt == (char *)0x0) {
    ptr = (char *)0x0;
    if (action_desc == (char *)0x0) goto LAB_081886ba;
LAB_08188635:
    ptr_00 = BUF_strdup(action_desc);
    if (ptr_00 != (char *)0x0) {
      if (ok_chars != (char *)0x0) goto LAB_0818864f;
LAB_081886c0:
      ptr_01 = (char *)0x0;
      goto LAB_08188665;
    }
    ptr_01 = (char *)0x0;
    ERR_put_error(0x28,0x6e,0x41,"ui_lib.c",0x13c);
    if (ptr == (char *)0x0) {
      return -1;
    }
  }
  else {
    ptr = BUF_strdup(prompt);
    if (ptr == (char *)0x0) {
      ERR_put_error(0x28,0x6e,0x41,"ui_lib.c",0x134);
      return -1;
    }
    if (action_desc != (char *)0x0) goto LAB_08188635;
LAB_081886ba:
    ptr_00 = (char *)0x0;
    if (ok_chars == (char *)0x0) goto LAB_081886c0;
LAB_0818864f:
    ptr_01 = BUF_strdup(ok_chars);
    if (ptr_01 == (char *)0x0) {
      iVar2 = 0x144;
    }
    else {
LAB_08188665:
      if ((cancel_chars == (char *)0x0) ||
         (pcVar1 = BUF_strdup(cancel_chars), pcVar1 != (char *)0x0)) {
        iVar2 = general_allocate_boolean_constprop_5();
        return iVar2;
      }
      iVar2 = 0x14c;
    }
    ERR_put_error(0x28,0x6e,0x41,"ui_lib.c",iVar2);
    if (ptr == (char *)0x0) goto LAB_081886fb;
  }
  CRYPTO_free(ptr);
LAB_081886fb:
  if (ptr_00 != (char *)0x0) {
    CRYPTO_free(ptr_00);
  }
  if (ptr_01 != (char *)0x0) {
    CRYPTO_free(ptr_01);
  }
  return -1;
}

