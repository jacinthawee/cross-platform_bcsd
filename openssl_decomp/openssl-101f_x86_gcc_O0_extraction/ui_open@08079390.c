
void ui_open(void)

{
  UI_METHOD *pUVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  pUVar1 = UI_OpenSSL();
  UNRECOVERED_JUMPTABLE = (code *)UI_method_get_opener((UI *)pUVar1);
                    /* WARNING: Could not recover jumptable at 0x080793ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

