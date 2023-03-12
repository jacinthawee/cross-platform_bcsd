
char * SSL_alert_type_string(int value)

{
  char *pcVar1;
  
  if (value >> 8 != 1) {
    pcVar1 = "U";
    if (value >> 8 == 2) {
      pcVar1 = "F";
    }
    return pcVar1;
  }
  return "W";
}

