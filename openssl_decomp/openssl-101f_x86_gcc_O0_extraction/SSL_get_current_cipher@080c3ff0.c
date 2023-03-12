
SSL_CIPHER * SSL_get_current_cipher(SSL *s)

{
  if (s->session != (SSL_SESSION *)0x0) {
    return *(SSL_CIPHER **)(s->session->krb5_client_princ + 0x24);
  }
  return (SSL_CIPHER *)0x0;
}

