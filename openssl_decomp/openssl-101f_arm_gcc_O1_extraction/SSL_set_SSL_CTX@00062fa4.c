
SSL_CTX * SSL_set_SSL_CTX(SSL *ssl,SSL_CTX *ctx)

{
  SSL_CTX *pSVar1;
  cert_st *pcVar2;
  
  pSVar1 = (SSL_CTX *)ssl->psk_server_callback;
  if (pSVar1 != ctx) {
    pSVar1 = ctx;
    if (ctx == (SSL_CTX *)0x0) {
      pSVar1 = (SSL_CTX *)ssl->tls_session_secret_cb_arg;
    }
    if (ssl->cert != (cert_st *)0x0) {
      ssl_cert_free();
    }
    pcVar2 = (cert_st *)ssl_cert_dup(pSVar1->cert);
    ssl->cert = pcVar2;
    CRYPTO_add_lock(&pSVar1->references,1,0xc,"ssl_lib.c",0xb83);
    if ((SSL_CTX *)ssl->psk_server_callback != (SSL_CTX *)0x0) {
      SSL_CTX_free((SSL_CTX *)ssl->psk_server_callback);
    }
    ssl->psk_server_callback = (_func_3154 *)pSVar1;
  }
  return pSVar1;
}

