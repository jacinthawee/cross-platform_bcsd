
int ssl_verify_alarm_type(int param_1)

{
  if (param_1 - 1U < 0x42) {
    return (int)(char)(&DAT_006472ef)[param_1];
  }
  return 0x2e;
}

