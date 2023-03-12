
int tls1_alert_code(uint param_1)

{
  if (param_1 < 0x74) {
    return (int)(char)CSWTCH_72[param_1];
  }
  return -1;
}

