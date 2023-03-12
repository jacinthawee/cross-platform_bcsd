
char * SSL_alert_desc_string(int value)

{
  char *pcVar1;
  
  pcVar1 = "UK";
  if ((value & 0xffU) < 0x74) {
    pcVar1 = *(char **)(CSWTCH_7 + (value & 0xffU) * 4);
  }
  return pcVar1;
}

