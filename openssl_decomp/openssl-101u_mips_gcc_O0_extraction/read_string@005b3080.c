
int read_string(undefined4 param_1,UI_STRING *param_2)

{
  undefined4 uVar1;
  UI_string_types UVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  UVar2 = UI_get_string_type(param_2);
  uVar1 = tty_out;
  if (UVar2 == UIT_VERIFY) {
    pcVar3 = UI_get0_output_string(param_2);
    (*(code *)PTR___fprintf_chk_006a9980)(uVar1,1,"Verifying - %s",pcVar3);
    (*(code *)PTR_fflush_006a9b04)(tty_out);
    uVar4 = UI_get_input_flags(param_2);
    iVar5 = read_string_inner(param_1,param_2,uVar4 & 1,1);
    if (iVar5 < 1) {
      return iVar5;
    }
    pcVar3 = UI_get0_result_string(param_2);
    pcVar6 = UI_get0_test_string(param_2);
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar3,pcVar6);
    if (iVar5 != 0) {
      (*(code *)PTR_fwrite_006a9a74)("Verify failure\n",1,0xf,tty_out);
      (*(code *)PTR_fflush_006a9b04)(tty_out);
      return 0;
    }
  }
  else {
    if (UVar2 == UIT_BOOLEAN) {
      pcVar3 = UI_get0_output_string(param_2);
      (*(code *)PTR_fputs_006a9954)(pcVar3,tty_out);
      pcVar3 = UI_get0_action_string(param_2);
      (*(code *)PTR_fputs_006a9954)(pcVar3,tty_out);
      (*(code *)PTR_fflush_006a9b04)(tty_out);
      uVar4 = UI_get_input_flags(param_2);
      iVar5 = read_string_inner(param_1,param_2,uVar4 & 1,0);
      return iVar5;
    }
    if (UVar2 == UIT_PROMPT) {
      pcVar3 = UI_get0_output_string(param_2);
      (*(code *)PTR_fputs_006a9954)(pcVar3,tty_out);
      (*(code *)PTR_fflush_006a9b04)(tty_out);
      uVar4 = UI_get_input_flags(param_2);
      iVar5 = read_string_inner(param_1,param_2,uVar4 & 1,1);
      return iVar5;
    }
  }
  return 1;
}

