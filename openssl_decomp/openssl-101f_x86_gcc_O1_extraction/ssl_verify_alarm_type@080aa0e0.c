
int ssl_verify_alarm_type(int param_1)

{
  int iVar1;
  
  iVar1 = 0x2e;
  if (param_1 - 2U < 0x31) {
    iVar1 = (int)(char)(&DAT_081fef3e)[param_1];
  }
  return iVar1;
}

