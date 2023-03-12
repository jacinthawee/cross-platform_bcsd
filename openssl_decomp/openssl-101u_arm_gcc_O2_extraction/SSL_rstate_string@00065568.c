
char * SSL_rstate_string(SSL *s)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = s->rstate - 0xf0;
  if (uVar2 < 3) {
    pcVar1 = *(char **)(CSWTCH_11 + uVar2 * 4);
  }
  else {
    pcVar1 = "unknown";
  }
  return pcVar1;
}

