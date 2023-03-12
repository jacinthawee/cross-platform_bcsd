
X509 * SSL_get_peer_certificate(SSL *s)

{
  X509 *pXVar1;
  
  if (s == (SSL *)0x0) {
    pXVar1 = (X509 *)0x0;
  }
  else {
    pXVar1 = (X509 *)0x0;
    if ((s->session != (SSL_SESSION *)0x0) &&
       (pXVar1 = *(X509 **)(s->session->krb5_client_princ + 0xc), pXVar1 != (X509 *)0x0)) {
      CRYPTO_add_lock(&pXVar1->references,1,3,"ssl_lib.c",0x34a);
    }
  }
  return pXVar1;
}

