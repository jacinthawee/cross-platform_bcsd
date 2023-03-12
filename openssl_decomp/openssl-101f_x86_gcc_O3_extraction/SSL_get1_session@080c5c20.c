
SSL_SESSION * __regparm1 SSL_get1_session(SSL *ssl)

{
  SSL_SESSION *pSVar1;
  int in_stack_00000004;
  
  CRYPTO_lock((int)ssl,9,(char *)0xe,(int)"ssl_sess.c");
  pSVar1 = *(SSL_SESSION **)(in_stack_00000004 + 0xc0);
  if (pSVar1 != (SSL_SESSION *)0x0) {
    *(int *)(pSVar1->krb5_client_princ + 0x14) = *(int *)(pSVar1->krb5_client_princ + 0x14) + 1;
  }
  CRYPTO_lock(in_stack_00000004,10,(char *)0xe,(int)"ssl_sess.c");
  return pSVar1;
}

