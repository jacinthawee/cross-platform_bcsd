
char * OCSP_cert_status_str(long s)

{
  char *pcVar1;
  
  if (s == 0) {
    return "good";
  }
  if (s != 1) {
    pcVar1 = "(UNKNOWN)";
    if (s == 2) {
      pcVar1 = "unknown";
    }
    return pcVar1;
  }
  return "revoked";
}

