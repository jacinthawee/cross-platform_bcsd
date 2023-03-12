
char * SSL_alert_type_string(int value)

{
  if (value >> 8 == 1) {
    return "W";
  }
  if (value >> 8 != 2) {
    return "U";
  }
  return "F";
}

