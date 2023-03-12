
int read_string(undefined4 param_1,UI_STRING *param_2)

{
  FILE *pFVar1;
  UI_string_types UVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char *__s2;
  
  UVar2 = UI_get_string_type(param_2);
  pFVar1 = tty_out;
  if (UVar2 == UIT_VERIFY) {
    pcVar3 = UI_get0_output_string(param_2);
    __fprintf_chk(pFVar1,1,"Verifying - %s",pcVar3);
    fflush(tty_out);
    uVar4 = UI_get_input_flags(param_2);
    iVar5 = read_string_inner(param_1,param_2,uVar4 & 1);
    if (iVar5 < 1) {
      return iVar5;
    }
    pcVar3 = UI_get0_result_string(param_2);
    __s2 = UI_get0_test_string(param_2);
    iVar5 = strcmp(pcVar3,__s2);
    if (iVar5 != 0) {
      fwrite("Verify failure\n",1,0xf,tty_out);
      fflush(tty_out);
      return 0;
    }
  }
  else {
    if (UVar2 == UIT_BOOLEAN) {
      pcVar3 = UI_get0_output_string(param_2);
      fputs(pcVar3,tty_out);
      pcVar3 = UI_get0_action_string(param_2);
      fputs(pcVar3,tty_out);
      fflush(tty_out);
      uVar4 = UI_get_input_flags(param_2);
      iVar5 = read_string_inner(param_1,param_2,uVar4 & 1,0);
      return iVar5;
    }
    if (UVar2 == UIT_PROMPT) {
      pcVar3 = UI_get0_output_string(param_2);
      fputs(pcVar3,tty_out);
      fflush(tty_out);
      uVar4 = UI_get_input_flags(param_2);
      iVar5 = read_string_inner(param_1,param_2,uVar4 & 1,1);
      return iVar5;
    }
  }
  return 1;
}

