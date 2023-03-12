
UI * password_callback(char *param_1,UI *param_2,int param_3,char **param_4)

{
  UI *pUVar1;
  UI *ui_method;
  uint uVar2;
  int iVar3;
  char *result_buf;
  char *pcVar4;
  
  if (param_4 != (char **)0x0) {
    pcVar4 = *param_4;
    param_4 = (char **)param_4[1];
    if (pcVar4 != (char *)0x0) {
      pUVar1 = (UI *)strlen(pcVar4);
      if ((int)param_2 <= (int)pUVar1) {
        pUVar1 = param_2;
      }
      memcpy(param_1,pcVar4,(size_t)pUVar1);
      return pUVar1;
    }
  }
  ui_method = UI_new_method(::ui_method);
  pUVar1 = ui_method;
  if (ui_method != (UI *)0x0) {
    pcVar4 = UI_construct_prompt(ui_method,"pass phrase",(char *)param_4);
    UI_ctrl(ui_method,1,1,(void *)0x0,(f *)0x0);
    uVar2 = UI_add_input_string(ui_method,pcVar4,2,param_1,4,0x1fff);
    result_buf = (char *)(~uVar2 >> 0x1f);
    if (param_3 == 0) {
      result_buf = (char *)0x0;
    }
    if (result_buf != (char *)0x0) {
      result_buf = (char *)CRYPTO_malloc((int)param_2,"apps.c",0x250);
      uVar2 = UI_add_verify_string(ui_method,pcVar4,2,result_buf,4,0x1fff,param_1);
    }
    if (-1 < (int)uVar2) {
      do {
        uVar2 = UI_process(ui_method);
        if (-1 < (int)uVar2) break;
        iVar3 = UI_ctrl(ui_method,2,0,(void *)0x0,(f *)0x0);
      } while (iVar3 != 0);
    }
    if (result_buf != (char *)0x0) {
      OPENSSL_cleanse(result_buf,(size_t)param_2);
      CRYPTO_free(result_buf);
    }
    if ((int)uVar2 < 0) {
      if (uVar2 == 0xffffffff) {
        pUVar1 = (UI *)0x0;
        BIO_printf(bio_err,"User interface error\n");
        ERR_print_errors(bio_err);
        OPENSSL_cleanse(param_1,(size_t)param_2);
      }
      else if (uVar2 == 0xfffffffe) {
        pUVar1 = (UI *)0x0;
        BIO_printf(bio_err,"aborted!\n");
        OPENSSL_cleanse(param_1,(size_t)param_2);
      }
      else {
        pUVar1 = (UI *)0x0;
      }
    }
    else {
      pUVar1 = (UI *)strlen(param_1);
    }
    UI_free(ui_method);
    CRYPTO_free(pcVar4);
  }
  return pUVar1;
}

