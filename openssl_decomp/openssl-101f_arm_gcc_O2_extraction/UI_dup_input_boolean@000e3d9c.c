
int UI_dup_input_boolean
              (UI *ui,char *prompt,char *action_desc,char *ok_chars,char *cancel_chars,int flags,
              char *result_buf)

{
  int iVar1;
  
  if ((prompt != (char *)0x0) && (prompt = BUF_strdup(prompt), prompt == (char *)0x0)) {
    ERR_put_error(0x28,0x6e,0x41,"ui_lib.c",0x13e);
    return -1;
  }
  if ((action_desc != (char *)0x0) &&
     (action_desc = BUF_strdup(action_desc), action_desc == (char *)0x0)) {
    ERR_put_error(0x28,0x6e,0x41,"ui_lib.c",0x148);
    ok_chars = action_desc;
    goto LAB_000e3e20;
  }
  if (ok_chars == (char *)0x0) {
LAB_000e3dda:
    if ((cancel_chars == (char *)0x0) ||
       (cancel_chars = BUF_strdup(cancel_chars), cancel_chars != (char *)0x0)) {
      iVar1 = general_allocate_boolean_constprop_4
                        (ui,prompt,action_desc,ok_chars,cancel_chars,1,flags,result_buf);
      return iVar1;
    }
    iVar1 = 0x15c;
  }
  else {
    ok_chars = BUF_strdup(ok_chars);
    iVar1 = 0x152;
    if (ok_chars != (char *)0x0) goto LAB_000e3dda;
  }
  ERR_put_error(0x28,0x6e,0x41,"ui_lib.c",iVar1);
LAB_000e3e20:
  if (prompt != (char *)0x0) {
    CRYPTO_free(prompt);
  }
  if (action_desc != (char *)0x0) {
    CRYPTO_free(action_desc);
  }
  if (ok_chars != (char *)0x0) {
    CRYPTO_free(ok_chars);
  }
  return -1;
}

