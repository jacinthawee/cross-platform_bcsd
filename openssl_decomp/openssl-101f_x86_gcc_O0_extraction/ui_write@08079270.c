
undefined4 ui_write(UI *param_1,UI_STRING *param_2)

{
  uint uVar1;
  void *pvVar2;
  UI_string_types UVar3;
  UI_METHOD *pUVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar5;
  char **ppcVar6;
  UI_STRING *in_stack_ffffffe8;
  
  uVar1 = UI_get_input_flags(param_2);
  if ((uVar1 & 2) != 0) {
    pvVar2 = UI_get0_user_data(param_1);
    if (pvVar2 != (void *)0x0) {
      UVar3 = UI_get_string_type(param_2);
      if (UVar3 + ~UIT_NONE < 2) {
        ppcVar6 = (char **)UI_get0_user_data(param_1);
        if ((*ppcVar6 != (char *)0x0) && (**ppcVar6 != '\0')) {
          return 1;
        }
      }
    }
  }
  pUVar4 = UI_OpenSSL();
  UNRECOVERED_JUMPTABLE = (code *)UI_method_get_writer((UI *)pUVar4,in_stack_ffffffe8);
                    /* WARNING: Could not recover jumptable at 0x080792c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)();
  return uVar5;
}

