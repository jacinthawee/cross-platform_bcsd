
char * SSL_get_psk_identity(SSL *s)

{
  if ((s != (SSL *)0x0) && (s->session != (SSL_SESSION *)0x0)) {
    return *(char **)s->session->krb5_client_princ;
  }
  return (char *)0x0;
}

