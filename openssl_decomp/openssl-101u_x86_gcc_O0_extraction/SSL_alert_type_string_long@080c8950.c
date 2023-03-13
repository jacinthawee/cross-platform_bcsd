
char * SSL_alert_type_string_long(int value)

{
  char *pcVar1;
  
  if (value >> 8 != 1) {
    pcVar1 = "fatal";
    if (value >> 8 != 2) {
      pcVar1 = "unknown";
    }
    return pcVar1;
  }
  return "warning";
}

