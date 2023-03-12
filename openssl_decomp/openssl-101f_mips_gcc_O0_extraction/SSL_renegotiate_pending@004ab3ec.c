
int SSL_renegotiate_pending(SSL *s)

{
  return (uint)(s->tlsext_hb_seq != 0);
}

