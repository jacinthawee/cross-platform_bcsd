
char * SSL_get_version(SSL *s)

{
  int iVar1;
  
  iVar1 = s->version;
  if (iVar1 == 0x303) {
    return "TLSv1.2";
  }
  if (iVar1 == 0x302) {
    return "TLSv1.1";
  }
  if (iVar1 == 0x301) {
    return "TLSv1";
  }
  if (iVar1 != 0x300) {
    if (iVar1 != 2) {
      return "unknown";
    }
    return "SSLv2";
  }
  return "SSLv3";
}

