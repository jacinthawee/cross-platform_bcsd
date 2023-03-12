
X509 * SSL_get_peer_certificate(SSL *s)

{
  if (((s != (SSL *)0x0) && (s = (SSL *)s->session, (SSL_SESSION *)s != (SSL_SESSION *)0x0)) &&
     (s = *(SSL **)((int)((SSL_SESSION *)s)->krb5_client_princ + 0xc),
     (SSL_SESSION *)s != (SSL_SESSION *)0x0)) {
    CRYPTO_add_lock(&((SSL_SESSION *)s)->master_key_length,1,3,"ssl_lib.c",0x34a);
  }
  return (X509 *)(SSL_SESSION *)s;
}

