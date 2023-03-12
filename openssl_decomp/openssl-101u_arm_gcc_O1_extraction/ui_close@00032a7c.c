
void ui_close(undefined4 param_1)

{
  UI_METHOD *pUVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  pUVar1 = UI_OpenSSL();
  UNRECOVERED_JUMPTABLE = (code *)UI_method_get_closer((UI *)pUVar1);
                    /* WARNING: Could not recover jumptable at 0x00032a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

