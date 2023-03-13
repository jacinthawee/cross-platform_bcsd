
int SSL_renegotiate_abbreviated(SSL *s)

{
  int iVar1;
  
  if (s->tlsext_hb_seq == 0) {
    s->tlsext_hb_seq = 1;
  }
  s->new_session = 0;
                    /* WARNING: Could not recover jumptable at 0x080be089. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*s->method->ssl_renegotiate)(s);
  return iVar1;
}

