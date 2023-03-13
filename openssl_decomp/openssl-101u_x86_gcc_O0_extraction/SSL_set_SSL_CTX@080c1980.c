
SSL_CTX * SSL_set_SSL_CTX(SSL *ssl,SSL_CTX *ctx)

{
  cert_st *pcVar1;
  _func_3154 *p_Var2;
  cert_st *pcVar3;
  int iVar4;
  
  pcVar1 = ssl->cert;
  if ((SSL_CTX *)ssl->psk_server_callback != ctx) {
    if (ctx == (SSL_CTX *)0x0) {
      ctx = (SSL_CTX *)ssl->tls_session_secret_cb_arg;
    }
    pcVar3 = (cert_st *)ssl_cert_dup(ctx->cert);
    ssl->cert = pcVar3;
    if (pcVar1 != (cert_st *)0x0) {
      *(undefined4 *)(pcVar3 + 0x38) = *(undefined4 *)(pcVar1 + 0x38);
      *(undefined4 *)(pcVar3 + 0x44) = *(undefined4 *)(pcVar1 + 0x44);
      *(undefined4 *)(pcVar3 + 0x50) = *(undefined4 *)(pcVar1 + 0x50);
      *(undefined4 *)(pcVar3 + 0x5c) = *(undefined4 *)(pcVar1 + 0x5c);
      *(undefined4 *)(pcVar3 + 0x68) = *(undefined4 *)(pcVar1 + 0x68);
      *(undefined4 *)(pcVar3 + 0x74) = *(undefined4 *)(pcVar1 + 0x74);
      *(undefined4 *)(pcVar3 + 0x80) = *(undefined4 *)(pcVar1 + 0x80);
      *(undefined4 *)(pcVar3 + 0x8c) = *(undefined4 *)(pcVar1 + 0x8c);
      ssl_cert_free(pcVar1);
    }
    if (0x20 < ssl->sid_ctx_length) {
      OpenSSLDie("ssl_lib.c",0xb8e,"ssl->sid_ctx_length <= sizeof(ssl->sid_ctx)");
    }
    p_Var2 = ssl->psk_server_callback;
    if ((p_Var2 != (_func_3154 *)0x0) && (ssl->sid_ctx_length == *(size_t *)(p_Var2 + 0xc4))) {
      iVar4 = memcmp(ssl->sid_ctx,p_Var2 + 200,ssl->sid_ctx_length);
      if (iVar4 == 0) {
        ssl->sid_ctx_length = ctx->sid_ctx_length;
        *(undefined4 *)ssl->sid_ctx = *(undefined4 *)ctx->sid_ctx;
        *(undefined4 *)(ssl->sid_ctx + 4) = *(undefined4 *)(ctx->sid_ctx + 4);
        *(undefined4 *)(ssl->sid_ctx + 8) = *(undefined4 *)(ctx->sid_ctx + 8);
        *(undefined4 *)(ssl->sid_ctx + 0xc) = *(undefined4 *)(ctx->sid_ctx + 0xc);
        *(undefined4 *)(ssl->sid_ctx + 0x10) = *(undefined4 *)(ctx->sid_ctx + 0x10);
        *(undefined4 *)(ssl->sid_ctx + 0x14) = *(undefined4 *)(ctx->sid_ctx + 0x14);
        *(undefined4 *)(ssl->sid_ctx + 0x18) = *(undefined4 *)(ctx->sid_ctx + 0x18);
        *(undefined4 *)(ssl->sid_ctx + 0x1c) = *(undefined4 *)(ctx->sid_ctx + 0x1c);
      }
    }
    CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0xb9d);
    if (ssl->psk_server_callback != (_func_3154 *)0x0) {
      iVar4 = CRYPTO_add_lock((int *)(ssl->psk_server_callback + 0x60),-1,0xc,"ssl_lib.c",0x795);
      if (iVar4 < 1) {
        SSL_CTX_free_part_6();
      }
    }
    ssl->psk_server_callback = (_func_3154 *)ctx;
  }
  return ctx;
}

