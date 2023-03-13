
int ssl3_alert_code(uint param_1)

{
  int iVar1;
  
  iVar1 = -1;
  if (param_1 < 0x74) {
    iVar1 = (int)(char)CSWTCH_67[param_1];
  }
  return iVar1;
}

