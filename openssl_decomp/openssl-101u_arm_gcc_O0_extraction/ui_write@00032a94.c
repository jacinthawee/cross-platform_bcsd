
undefined4 ui_write(UI *param_1,UI_STRING *param_2)

{
  int iVar1;
  void *pvVar2;
  UI_string_types UVar3;
  UI_METHOD *pUVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar5;
  char **ppcVar6;
  UI_STRING *extraout_r1;
  
  iVar1 = UI_get_input_flags(param_2);
  if (((iVar1 << 0x1e < 0) && (pvVar2 = UI_get0_user_data(param_1), pvVar2 != (void *)0x0)) &&
     (UVar3 = UI_get_string_type(param_2), UVar3 + ~UIT_NONE < 2)) {
    ppcVar6 = (char **)UI_get0_user_data(param_1);
    if ((*ppcVar6 != (char *)0x0) && (**ppcVar6 != '\0')) {
      return 1;
    }
  }
  pUVar4 = UI_OpenSSL();
  UNRECOVERED_JUMPTABLE = (code *)UI_method_get_writer((UI *)pUVar4,extraout_r1);
                    /* WARNING: Could not recover jumptable at 0x00032aca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return uVar5;
}

