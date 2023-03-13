
int ssl_verify_alarm_type(int param_1)

{
  int iVar1;
  
  iVar1 = 0x2e;
  if (param_1 - 1U < 0x42) {
    iVar1 = (int)(char)(&DAT_081ff35f)[param_1];
  }
  return iVar1;
}

