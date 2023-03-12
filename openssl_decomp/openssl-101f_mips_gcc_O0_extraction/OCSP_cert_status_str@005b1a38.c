
char * OCSP_cert_status_str(long s)

{
  if (s == 0) {
    return "good";
  }
  if (s != 1) {
    if (s != 2) {
      return "(UNKNOWN)";
    }
    return "unknown";
  }
  return "revoked";
}

