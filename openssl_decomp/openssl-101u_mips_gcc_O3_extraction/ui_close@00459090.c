
void ui_close(undefined4 param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = (*(code *)PTR_UI_OpenSSL_006a7b00)();
  UNRECOVERED_JUMPTABLE = (code *)(*(code *)PTR_UI_method_get_closer_006a7b04)(uVar1);
                    /* WARNING: Could not recover jumptable at 0x004590d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

