
undefined4 ui_read(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  char **ppcVar4;
  
  uVar1 = (*(code *)PTR_UI_get_input_flags_006a7b08)(param_2);
  if ((((uVar1 & 2) != 0) &&
      (iVar2 = (*(code *)PTR_UI_get0_user_data_006a7b0c)(param_1), iVar2 != 0)) &&
     (iVar2 = (*(code *)PTR_UI_get_string_type_006a7b10)(param_2), iVar2 - 1U < 2)) {
    ppcVar4 = (char **)(*(code *)PTR_UI_get0_user_data_006a7b0c)(param_1);
    if ((*ppcVar4 != (char *)0x0) && (**ppcVar4 != '\0')) {
      (*(code *)PTR_UI_set_result_006a7b1c)(param_1,param_2);
      return 1;
    }
  }
  uVar3 = (*(code *)PTR_UI_OpenSSL_006a7b00)();
  UNRECOVERED_JUMPTABLE = (code *)(*(code *)PTR_UI_method_get_reader_006a7b18)(uVar3);
                    /* WARNING: Could not recover jumptable at 0x0045926c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar3;
}

