
long SSL_SESSION_get_time(SSL_SESSION *s)

{
  if (s != (SSL_SESSION *)0x0) {
    return *(long *)(s->krb5_client_princ + 0x1c);
  }
  return 0;
}

