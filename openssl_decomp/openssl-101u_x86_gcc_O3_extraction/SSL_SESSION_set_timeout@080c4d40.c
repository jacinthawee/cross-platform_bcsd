
long SSL_SESSION_set_timeout(SSL_SESSION *s,long t)

{
  if (s != (SSL_SESSION *)0x0) {
    *(long *)(s->krb5_client_princ + 0x18) = t;
    return 1;
  }
  return 0;
}

