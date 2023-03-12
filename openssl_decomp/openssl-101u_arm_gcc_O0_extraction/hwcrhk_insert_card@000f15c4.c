
void hwcrhk_insert_card(int param_1,char *param_2,UI_METHOD **param_3,UI_METHOD *param_4)

{
  UI_METHOD **ppUVar1;
  UI_METHOD *pUVar2;
  UI *ui;
  uint uVar3;
  UI_METHOD *pUVar4;
  uint uVar5;
  byte abStack_2030 [8];
  char acStack_2028 [8196];
  int local_24;
  
  local_24 = __stack_chk_guard;
  pUVar4 = param_4;
  if (param_4 != (UI_METHOD *)0x0) {
    ppUVar1 = (UI_METHOD **)(param_4 + 8);
    param_4 = *(UI_METHOD **)(param_4 + 4);
    pUVar4 = *ppUVar1;
  }
  pUVar2 = pUVar4;
  if (param_3 != (UI_METHOD **)0x0) {
    pUVar2 = *param_3;
    if (*param_3 == (UI_METHOD *)0x0) {
      pUVar2 = param_4;
    }
    param_4 = pUVar2;
    pUVar2 = param_3[1];
    if (param_3[1] == (UI_METHOD *)0x0) {
      pUVar2 = pUVar4;
    }
  }
  if (param_4 == (UI_METHOD *)0x0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x68,0x6c,"e_chil.c",0x4f4);
  }
  else {
    ui = UI_new_method(param_4);
    if (ui != (UI *)0x0) {
      if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
        acStack_2028[0] = '\0';
      }
      else {
        BIO_snprintf(acStack_2028,0x1fff,"Current card: \"%s\"\n",param_2);
      }
      uVar3 = UI_dup_info_string(ui,acStack_2028);
      uVar5 = ~uVar3 >> 0x1f;
      if (param_1 == 0) {
        uVar5 = 0;
      }
      if (uVar5 != 0) {
        BIO_snprintf(acStack_2028,0x1fff,"Insert card \"%s\"",param_1);
        uVar3 = UI_dup_input_boolean
                          (ui,acStack_2028,"\n then hit <enter> or C<enter> to cancel\n","\r\n","Cc"
                           ,1,(char *)abStack_2030);
      }
      UI_add_user_data(ui,pUVar2);
      if (-1 < (int)uVar3) {
        uVar3 = UI_process(ui);
      }
      UI_free(ui);
      if ((uVar3 != 0xfffffffe) && (-1 < (int)uVar3)) {
        count_leading_zeroes(abStack_2030[0] - 0x43);
      }
    }
  }
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

