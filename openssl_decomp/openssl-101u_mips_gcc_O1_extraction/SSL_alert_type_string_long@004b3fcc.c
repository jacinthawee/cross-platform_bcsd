
char * SSL_alert_type_string_long(int value)

{
  if (value >> 8 == 1) {
    return "warning";
  }
  if (value >> 8 != 2) {
    return "unknown";
  }
  return "fatal";
}

