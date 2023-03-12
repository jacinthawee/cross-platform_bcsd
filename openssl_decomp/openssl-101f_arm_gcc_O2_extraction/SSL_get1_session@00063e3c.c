
SSL_SESSION * SSL_get1_session(SSL *ssl)

{
  SSL_SESSION *pSVar1;
  
  CRYPTO_lock(9,0xe,"ssl_sess.c",0xa3);
  pSVar1 = ssl->session;
  if (pSVar1 != (SSL_SESSION *)0x0) {
    *(int *)(pSVar1->krb5_client_princ + 0x14) = *(int *)(pSVar1->krb5_client_princ + 0x14) + 1;
  }
  CRYPTO_lock(10,0xe,"ssl_sess.c",0xa7);
  return pSVar1;
}

