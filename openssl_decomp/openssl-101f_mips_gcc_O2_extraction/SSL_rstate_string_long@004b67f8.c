
char * SSL_rstate_string_long(SSL *s)

{
  int iVar1;
  
  iVar1 = s->rstate;
  if (iVar1 == 0xf1) {
    return "read body";
  }
  if (iVar1 != 0xf2) {
    if (iVar1 != 0xf0) {
      return "unknown";
    }
    return "read header";
  }
  return "read done";
}

