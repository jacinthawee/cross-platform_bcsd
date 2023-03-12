
int SSL_do_handshake(SSL *s)

{
  int iVar1;
  
  if (s->handshake_func == (_func_3149 *)0x0) {
    ERR_put_error(0x14,0xb4,0x90,"ssl_lib.c",0x9fc);
    iVar1 = -1;
  }
  else {
    (*s->method->ssl_renegotiate_check)(s);
    if ((s->state & 0x7000U) != 0) {
                    /* WARNING: Could not recover jumptable at 0x080c3850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*s->handshake_func)(s);
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

