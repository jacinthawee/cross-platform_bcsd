
uint hwcrhk_insert_card(int param_1,char *param_2,UI_METHOD **param_3,int param_4)

{
  UI_METHOD *method;
  UI *ui;
  int iVar1;
  uint uVar2;
  UI_METHOD *pUVar3;
  UI_METHOD *pUVar4;
  UI_METHOD *user_data;
  int in_GS_OFFSET;
  char local_2021;
  char local_2020 [8192];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_4 == 0) {
    pUVar3 = (UI_METHOD *)0x0;
    pUVar4 = (UI_METHOD *)0x0;
    if (param_3 != (UI_METHOD **)0x0) goto LAB_081a1c70;
LAB_081a1dcc:
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x68,0x6c,"e_chil.c",0x4f4);
    uVar2 = 0xffffffff;
    goto LAB_081a1d0f;
  }
  pUVar3 = *(UI_METHOD **)(param_4 + 4);
  pUVar4 = *(UI_METHOD **)(param_4 + 8);
  method = pUVar3;
  user_data = pUVar4;
  if (param_3 == (UI_METHOD **)0x0) {
LAB_081a1e0c:
    if (method == (UI_METHOD *)0x0) goto LAB_081a1dcc;
  }
  else {
LAB_081a1c70:
    method = *param_3;
    user_data = param_3[1];
    if (method == (UI_METHOD *)0x0) {
      method = pUVar3;
      if (user_data == (UI_METHOD *)0x0) {
        user_data = pUVar4;
      }
      goto LAB_081a1e0c;
    }
    if (user_data == (UI_METHOD *)0x0) {
      user_data = pUVar4;
    }
  }
  ui = UI_new_method(method);
  if (ui != (UI *)0x0) {
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
      local_2020[0] = '\0';
    }
    else {
      BIO_snprintf(local_2020,0x1fff,"Current card: \"%s\"\n",param_2);
    }
    iVar1 = UI_dup_info_string(ui,local_2020);
    if ((-1 < iVar1) && (param_1 != 0)) {
      BIO_snprintf(local_2020,0x1fff,"Insert card \"%s\"",param_1);
      iVar1 = UI_dup_input_boolean
                        (ui,local_2020,"\n then hit <enter> or C<enter> to cancel\n","\r\n","Cc",1,
                         &local_2021);
    }
    UI_add_user_data(ui,user_data);
    if (iVar1 < 0) {
      UI_free(ui);
      if (iVar1 == -2) goto LAB_081a1d81;
    }
    else {
      iVar1 = UI_process(ui);
      UI_free(ui);
      if (iVar1 == -2) {
LAB_081a1d81:
        uVar2 = 1;
        goto LAB_081a1d0f;
      }
      if (-1 < iVar1) {
        uVar2 = (uint)(local_2021 == 'C');
        goto LAB_081a1d0f;
      }
    }
  }
  uVar2 = 0xffffffff;
LAB_081a1d0f:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

