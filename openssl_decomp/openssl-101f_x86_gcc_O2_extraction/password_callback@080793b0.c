
size_t password_callback(char *param_1,size_t param_2,int param_3,char **param_4)

{
  size_t sVar1;
  UI *ui_method;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *extraout_EDX;
  char *extraout_EDX_00;
  char *pcVar5;
  char *extraout_EDX_01;
  char *object_name;
  char *local_20;
  
  if (param_4 == (char **)0x0) {
    object_name = (char *)0x0;
  }
  else {
    pcVar2 = *param_4;
    object_name = param_4[1];
    if (pcVar2 != (char *)0x0) {
      sVar1 = strlen(pcVar2);
      if ((int)sVar1 <= (int)param_2) {
        param_2 = sVar1;
      }
      memcpy(param_1,pcVar2,param_2);
      return param_2;
    }
  }
  ui_method = UI_new_method(::ui_method);
  if (ui_method == (UI *)0x0) {
    return 0;
  }
  pcVar2 = UI_construct_prompt(ui_method,"pass phrase",object_name);
  UI_ctrl(ui_method,1,1,(void *)0x0,(f *)0x0);
  iVar3 = UI_add_input_string(ui_method,pcVar2,2,param_1,4,0x1fff);
  if ((iVar3 < 0) || (param_3 == 0)) {
    local_20 = (char *)0x0;
    pcVar5 = extraout_EDX;
  }
  else {
    local_20 = (char *)CRYPTO_malloc(param_2,"apps.c",0x250);
    object_name = param_1;
    iVar3 = UI_add_verify_string(ui_method,pcVar2,2,local_20,4,0x1fff,param_1);
    pcVar5 = extraout_EDX_01;
  }
  if (-1 < iVar3) {
    do {
      iVar3 = UI_process(ui_method);
      if (-1 < iVar3) {
        if (local_20 != (char *)0x0) {
          OPENSSL_cleanse(local_20,param_2);
          CRYPTO_free(local_20);
        }
        sVar1 = strlen(param_1);
        goto LAB_080794d2;
      }
      iVar4 = UI_ctrl(ui_method,2,0,(void *)0x0,(f *)0x0);
      pcVar5 = extraout_EDX_00;
    } while (iVar4 != 0);
  }
  if (local_20 != (char *)0x0) {
    OPENSSL_cleanse(local_20,param_2);
    CRYPTO_free(local_20);
    object_name = pcVar5;
  }
  if (iVar3 == -1) {
    BIO_printf(bio_err,"User interface error\n",object_name);
    ERR_print_errors(bio_err);
  }
  else {
    if (iVar3 != -2) {
      sVar1 = 0;
      goto LAB_080794d2;
    }
    BIO_printf(bio_err,"aborted!\n",object_name);
  }
  sVar1 = 0;
  OPENSSL_cleanse(param_1,param_2);
LAB_080794d2:
  UI_free(ui_method);
  CRYPTO_free(pcVar2);
  return sVar1;
}

