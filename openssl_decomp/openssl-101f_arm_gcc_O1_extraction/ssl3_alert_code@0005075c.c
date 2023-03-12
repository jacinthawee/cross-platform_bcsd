
int ssl3_alert_code(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1;
  if (param_1 < 0x74) {
    uVar1 = (int)&salt_18572 + param_1;
  }
  if (param_1 < 0x74) {
    iVar2 = (int)*(char *)(uVar1 + 0xc);
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

