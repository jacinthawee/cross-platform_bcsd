
int SSL_shutdown(SSL *s)

{
  int iVar1;
  
  if (s->handshake_func == (_func_3149 *)0x0) {
    ERR_put_error(0x14,0xe0,0x114,"ssl_lib.c",0x3f4);
    return -1;
  }
  if ((s->state & 0x3000U) != 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0005e854. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*s->method->ssl_shutdown)(s);
  return iVar1;
}

