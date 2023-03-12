
char * SSL_alert_desc_string_long(int value)

{
  char *pcVar1;
  
  if ((value & 0xffU) < 0x74) {
    pcVar1 = *(char **)(CSWTCH_9 + (value & 0xffU) * 4);
  }
  else {
    pcVar1 = "unknown";
  }
  return pcVar1;
}

