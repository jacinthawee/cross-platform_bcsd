
int EVP_read_pw_string_min(char *buf,int minlen,int maxlen,char *prompt,int verify)

{
  UI *ui;
  int iVar1;
  int in_GS_OFFSET;
  char local_2020 [8192];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((prompt == (char *)0x0) && (prompt_string[0] != '\0')) {
    prompt = prompt_string;
  }
  ui = UI_new();
  iVar1 = 0x1fff;
  if (maxlen < 0x2000) {
    iVar1 = maxlen;
  }
  UI_add_input_string(ui,prompt,0,buf,minlen,iVar1);
  if (verify != 0) {
    UI_add_verify_string(ui,prompt,0,local_2020,minlen,iVar1,buf);
  }
  iVar1 = UI_process(ui);
  UI_free(ui);
  OPENSSL_cleanse(local_2020,0x2000);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

