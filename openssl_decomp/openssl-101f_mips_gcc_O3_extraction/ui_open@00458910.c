
void ui_open(undefined4 param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = (*(code *)PTR_UI_OpenSSL_006a8bec)();
  UNRECOVERED_JUMPTABLE = (code *)(*(code *)PTR_UI_method_get_opener_006a8c0c)(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00458958. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

