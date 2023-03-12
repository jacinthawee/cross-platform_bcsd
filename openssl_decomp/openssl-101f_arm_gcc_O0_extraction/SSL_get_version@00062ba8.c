
char * SSL_get_version(SSL *s)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = s->version;
  if (iVar2 == 0x303) {
    return "TLSv1.2";
  }
  if (iVar2 == 0x302) {
    return "TLSv1.1";
  }
  if (iVar2 == 0x301) {
    return "TLSv1";
  }
  if (iVar2 != 0x300) {
    pcVar1 = "unknown";
    if (iVar2 == 2) {
      pcVar1 = "SSLv2";
    }
    return pcVar1;
  }
  return "SSLv3";
}

