
undefined4 ui_read(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  char **ppcVar4;
  
  uVar1 = (*(code *)PTR_UI_get_input_flags_006a8bf4)(param_2);
  if ((((uVar1 & 2) != 0) &&
      (iVar2 = (*(code *)PTR_UI_get0_user_data_006a8bf8)(param_1), iVar2 != 0)) &&
     (iVar2 = (*(code *)PTR_UI_get_string_type_006a8bfc)(param_2), iVar2 - 1U < 2)) {
    ppcVar4 = (char **)(*(code *)PTR_UI_get0_user_data_006a8bf8)(param_1);
    if ((*ppcVar4 != (char *)0x0) && (**ppcVar4 != '\0')) {
      (*(code *)PTR_UI_set_result_006a8c08)(param_1,param_2);
      return 1;
    }
  }
  uVar3 = (*(code *)PTR_UI_OpenSSL_006a8bec)();
  UNRECOVERED_JUMPTABLE = (code *)(*(code *)PTR_UI_method_get_reader_006a8c04)(uVar3);
                    /* WARNING: Could not recover jumptable at 0x004588bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar3;
}

