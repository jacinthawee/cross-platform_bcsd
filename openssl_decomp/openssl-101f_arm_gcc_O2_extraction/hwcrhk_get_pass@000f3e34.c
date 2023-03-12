
undefined4
hwcrhk_get_pass(char *param_1,size_t *param_2,char *param_3,UI_METHOD **param_4,UI_METHOD **param_5)

{
  UI *ui_method;
  char *prompt;
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  UI_METHOD **ppUVar4;
  UI_METHOD **user_data;
  uint uVar5;
  UI_METHOD **ppUVar6;
  
  if ((param_1 != (char *)0x0) && (*param_1 == '\0')) {
    param_1 = (char *)0x0;
  }
  ppUVar4 = param_5;
  ppUVar6 = param_5;
  if (param_5 != (UI_METHOD **)0x0) {
    ppUVar6 = (UI_METHOD **)*param_5;
    ppUVar4 = param_5 + 2;
    param_5 = (UI_METHOD **)param_5[1];
    ppUVar4 = (UI_METHOD **)*ppUVar4;
  }
  if (param_4 == (UI_METHOD **)0x0) {
    uVar5 = count_leading_zeroes(ppUVar6);
    uVar5 = uVar5 >> 5;
    user_data = ppUVar4;
  }
  else {
    if (*param_4 == (UI_METHOD *)0x0) {
      uVar5 = count_leading_zeroes(ppUVar6);
      uVar5 = uVar5 >> 5;
    }
    else {
      uVar5 = 1;
      ppUVar6 = (UI_METHOD **)0x0;
      param_5 = (UI_METHOD **)*param_4;
    }
    user_data = (UI_METHOD **)param_4[1];
    if (param_4[1] == (UI_METHOD *)0x0) {
      user_data = ppUVar4;
    }
  }
  if (param_5 == (UI_METHOD **)0x0) {
    uVar5 = uVar5 & 1;
  }
  else {
    uVar5 = 0;
  }
  if (uVar5 == 0) {
    if (param_5 == (UI_METHOD **)0x0) {
      sVar2 = (*(code *)ppUVar6)(param_3,*param_2,0,user_data);
      *param_2 = sVar2;
    }
    else {
      ui_method = UI_new_method((UI_METHOD *)param_5);
      if (ui_method != (UI *)0x0) {
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
      }
      sVar2 = *param_2;
    }
    uVar3 = 0xffffffff;
    if (sVar2 != 0) {
      uVar3 = 0;
    }
  }
  else {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x66,0x6c,"e_chil.c",0x4bd);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

