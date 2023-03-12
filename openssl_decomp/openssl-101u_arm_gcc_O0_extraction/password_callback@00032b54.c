
UI * password_callback(char *param_1,UI *param_2,int param_3,char **param_4)

{
  UI *pUVar1;
  UI *ui_method;
  uint uVar2;
  int iVar3;
  UI *pUVar4;
  char *pcVar5;
  
  if (param_4 != (char **)0x0) {
    pcVar5 = *param_4;
    param_4 = (char **)param_4[1];
    if (pcVar5 != (char *)0x0) {
      pUVar1 = (UI *)strlen(pcVar5);
      if ((int)param_2 <= (int)pUVar1) {
        pUVar1 = param_2;
      }
      memcpy(param_1,pcVar5,(size_t)pUVar1);
      return pUVar1;
    }
  }
  ui_method = UI_new_method(::ui_method);
  pUVar1 = ui_method;
  if (ui_method != (UI *)0x0) {
    pUVar1 = (UI *)UI_construct_prompt(ui_method,"pass phrase",(char *)param_4);
    if (pUVar1 == (UI *)0x0) {
      BIO_printf(bio_err,"Out of memory\n");
      UI_free(ui_method);
    }
    else {
      UI_ctrl(ui_method,1,1,(void *)0x0,(f *)0x0);
      uVar2 = UI_add_input_string(ui_method,(char *)pUVar1,2,param_1,4,(int)(param_2 + -1));
      pcVar5 = (char *)(~uVar2 >> 0x1f);
      if (param_3 == 0) {
        pcVar5 = (char *)0x0;
      }
      if (pcVar5 != (char *)0x0) {
        pcVar5 = (char *)CRYPTO_malloc((int)param_2,"apps.c",0x249);
        if (pcVar5 == (char *)0x0) {
          BIO_printf(bio_err,"Out of memory\n");
          UI_free(ui_method);
          CRYPTO_free(pUVar1);
          return (UI *)0x0;
        }
        uVar2 = UI_add_verify_string
                          (ui_method,(char *)pUVar1,2,pcVar5,4,(int)(param_2 + -1),param_1);
      }
      if (-1 < (int)uVar2) {
        do {
          uVar2 = UI_process(ui_method);
          if (-1 < (int)uVar2) break;
          iVar3 = UI_ctrl(ui_method,2,0,(void *)0x0,(f *)0x0);
        } while (iVar3 != 0);
      }
      if (pcVar5 != (char *)0x0) {
        OPENSSL_cleanse(pcVar5,(size_t)param_2);
        CRYPTO_free(pcVar5);
      }
      if ((int)uVar2 < 0) {
        if (uVar2 == 0xffffffff) {
          pUVar4 = (UI *)0x0;
          BIO_printf(bio_err,"User interface error\n");
          ERR_print_errors(bio_err);
          OPENSSL_cleanse(param_1,(size_t)param_2);
        }
        else if (uVar2 == 0xfffffffe) {
          pUVar4 = (UI *)0x0;
          BIO_printf(bio_err,"aborted!\n");
          OPENSSL_cleanse(param_1,(size_t)param_2);
        }
        else {
          pUVar4 = (UI *)0x0;
        }
      }
      else {
        pUVar4 = (UI *)strlen(param_1);
      }
      UI_free(ui_method);
      CRYPTO_free(pUVar1);
      pUVar1 = pUVar4;
    }
  }
  return pUVar1;
}

