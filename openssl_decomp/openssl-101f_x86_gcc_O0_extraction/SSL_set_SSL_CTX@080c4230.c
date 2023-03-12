
SSL_CTX * SSL_set_SSL_CTX(SSL *ssl,SSL_CTX *ctx)

{
  cert_st *pcVar1;
  int iVar2;
  
  if ((SSL_CTX *)ssl->psk_server_callback != ctx) {
    if (ctx == (SSL_CTX *)0x0) {
      ctx = (SSL_CTX *)ssl->tls_session_secret_cb_arg;
    }
    if (ssl->cert != (cert_st *)0x0) {
      ssl_cert_free(ssl->cert);
    }
    pcVar1 = (cert_st *)ssl_cert_dup(ctx->cert);
    ssl->cert = pcVar1;
    CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0xb83);
    if (ssl->psk_server_callback != (_func_3154 *)0x0) {
      iVar2 = CRYPTO_add_lock((int *)(ssl->psk_server_callback + 0x60),-1,0xc,"ssl_lib.c",0x773);
      if (iVar2 < 1) {
        SSL_CTX_free_part_6();
      }
    }
    ssl->psk_server_callback = (_func_3154 *)ctx;
  }
  return ctx;
}

