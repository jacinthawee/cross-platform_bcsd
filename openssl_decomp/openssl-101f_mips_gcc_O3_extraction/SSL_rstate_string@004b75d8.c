
char * SSL_rstate_string(SSL *s)

{
  int iVar1;
  
  iVar1 = s->rstate;
  if (iVar1 == 0xf1) {
    return "RB";
  }
  if (iVar1 != 0xf2) {
    if (iVar1 != 0xf0) {
      return "unknown";
    }
    return "RH";
  }
  return "RD";
}

