
int ssl_verify_alarm_type(int param_1)

{
  int iVar1;
  
  if (param_1 - 1U < 0x42) {
    iVar1 = (int)(char)(&UNK_00138f83)[param_1];
  }
  else {
    iVar1 = 0x2e;
  }
  return iVar1;
}

