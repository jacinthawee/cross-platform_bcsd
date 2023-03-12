
int ssl_verify_alarm_type(int param_1)

{
  if (param_1 - 2U < 0x31) {
    return (int)(char)(&DAT_006478fe)[param_1];
  }
  return 0x2e;
}

