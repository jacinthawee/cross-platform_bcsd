
int read_string(undefined4 param_1,UI_STRING *param_2)

{
  FILE *pFVar1;
  UI_string_types UVar2;
  int iVar3;
  char *pcVar4;
  char *__s1;
  int iVar5;
  
  UVar2 = UI_get_string_type(param_2);
  pFVar1 = tty_out;
  if (UVar2 == UIT_VERIFY) {
    pcVar4 = UI_get0_output_string(param_2);
    __fprintf_chk(tty_out,1,"Verifying - %s",pcVar4);
    fflush(tty_out);
    UI_get_input_flags(param_2);
    iVar3 = read_string_inner(1);
    if (0 < iVar3) {
      pcVar4 = UI_get0_test_string(param_2);
      __s1 = UI_get0_result_string(param_2);
      iVar5 = strcmp(__s1,pcVar4);
      iVar3 = 1;
      if (iVar5 != 0) {
        fwrite("Verify failure\n",1,0xf,tty_out);
        fflush(tty_out);
        iVar3 = 0;
      }
    }
  }
  else {
    if (UVar2 == UIT_BOOLEAN) {
      pcVar4 = UI_get0_output_string(param_2);
      fputs(pcVar4,pFVar1);
      pFVar1 = tty_out;
      pcVar4 = UI_get0_action_string(param_2);
      fputs(pcVar4,pFVar1);
      fflush(tty_out);
      UI_get_input_flags(param_2);
      iVar3 = read_string_inner();
      return iVar3;
    }
    if (UVar2 == UIT_PROMPT) {
      pcVar4 = UI_get0_output_string(param_2);
      fputs(pcVar4,pFVar1);
      fflush(tty_out);
      UI_get_input_flags(param_2);
      iVar3 = read_string_inner();
      return iVar3;
    }
    iVar3 = 1;
  }
  return iVar3;
}

