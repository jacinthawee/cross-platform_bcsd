
int hwcrhk_get_pass(char *param_1,size_t *param_2,char *param_3,UI_METHOD **param_4,code **param_5)

{
  UI_METHOD *method;
  UI *ui_method;
  char *prompt;
  int iVar1;
  size_t sVar2;
  UI_METHOD *pUVar3;
  UI_METHOD *pUVar4;
  code *pcVar5;
  UI_METHOD *user_data;
  bool bVar6;
  
  if ((param_1 != (char *)0x0) && (*param_1 == '\0')) {
    param_1 = (char *)0x0;
  }
  if (param_5 == (code **)0x0) {
    pUVar3 = (UI_METHOD *)0x0;
    pUVar4 = (UI_METHOD *)0x0;
    pcVar5 = (code *)0x0;
    if (param_4 != (UI_METHOD **)0x0) goto LAB_081a2fee;
LAB_081a30f6:
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x66,0x6c,"e_chil.c",0x4bd);
    iVar1 = -1;
  }
  else {
    pUVar3 = (UI_METHOD *)param_5[1];
    pcVar5 = *param_5;
    pUVar4 = (UI_METHOD *)param_5[2];
    if (param_4 == (UI_METHOD **)0x0) {
      bVar6 = pcVar5 == (code *)0x0;
      method = pUVar3;
      user_data = pUVar4;
LAB_081a313b:
      if ((method == (UI_METHOD *)0x0) && (bVar6)) goto LAB_081a30f6;
      if (method != (UI_METHOD *)0x0) goto LAB_081a3000;
      sVar2 = (*pcVar5)(param_3,*param_2,0,user_data);
      *param_2 = sVar2;
    }
    else {
LAB_081a2fee:
      method = *param_4;
      user_data = param_4[1];
      if (method == (UI_METHOD *)0x0) {
        bVar6 = pcVar5 == (code *)0x0;
        method = pUVar3;
        if (user_data == (UI_METHOD *)0x0) {
          user_data = pUVar4;
        }
        goto LAB_081a313b;
      }
      if (user_data == (UI_METHOD *)0x0) {
        user_data = pUVar4;
      }
LAB_081a3000:
      ui_method = UI_new_method(method);
      if (ui_method == (UI *)0x0) {
        sVar2 = *param_2;
      }
      else {
        prompt = UI_construct_prompt(ui_method,"pass phrase",param_1);
        iVar1 = UI_add_input_string(ui_method,prompt,2,param_3,0,*param_2 - 1);
        UI_add_user_data(ui_method,user_data);
        UI_ctrl(ui_method,1,1,(void *)0x0,(f *)0x0);
        if (-1 < iVar1) {
          do {
            iVar1 = UI_process(ui_method);
            if (-1 < iVar1) {
              sVar2 = strlen(param_3);
              *param_2 = sVar2;
              break;
            }
            iVar1 = UI_ctrl(ui_method,2,0,(void *)0x0,(f *)0x0);
          } while (iVar1 != 0);
        }
        UI_free(ui_method);
        CRYPTO_free(prompt);
        sVar2 = *param_2;
      }
    }
    iVar1 = -(uint)(sVar2 == 0);
  }
  return iVar1;
}

