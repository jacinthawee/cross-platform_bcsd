
SSL * SSL_new(SSL_CTX *ctx)

{
  SSL_METHOD *pSVar1;
  SSL *s;
  cert_st *pcVar2;
  X509_VERIFY_PARAM *to;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  byte bVar6;
  int line;
  
  bVar6 = 0;
  if (ctx == (SSL_CTX *)0x0) {
    line = 0x119;
    iVar3 = 0xc3;
    goto LAB_080bf453;
  }
  if (ctx->method == (SSL_METHOD *)0x0) {
    line = 0x11e;
    iVar3 = 0xe4;
    goto LAB_080bf453;
  }
  s = (SSL *)CRYPTO_malloc(0x1d4,"ssl_lib.c",0x122);
  if (s != (SSL *)0x0) {
    s->version = 0;
    s[1].rstate = 0;
    puVar5 = (undefined4 *)((uint)&s->type & 0xfffffffc);
    uVar4 = (uint)((int)s + (0x1d4 - (int)puVar5)) >> 2;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
    }
    s->references = ctx->options;
    s->options = ctx->mode;
    s->mode = ctx->max_cert_list;
    if (ctx->cert == (cert_st *)0x0) {
      s->cert = (cert_st *)0x0;
LAB_080bf1f0:
      s->read_ahead = ctx->read_ahead;
      s->msg_callback = (_func_3150 *)ctx->msg_callback;
      s->msg_callback_arg = ctx->msg_callback_arg;
      s->verify_mode = ctx->verify_mode;
      uVar4 = ctx->sid_ctx_length;
      s->sid_ctx_length = uVar4;
      if (0x20 < uVar4) {
        OpenSSLDie("ssl_lib.c",0x149,"s->sid_ctx_length <= sizeof s->sid_ctx");
      }
      *(undefined4 *)s->sid_ctx = *(undefined4 *)ctx->sid_ctx;
      *(undefined4 *)(s->sid_ctx + 4) = *(undefined4 *)(ctx->sid_ctx + 4);
      *(undefined4 *)(s->sid_ctx + 8) = *(undefined4 *)(ctx->sid_ctx + 8);
      *(undefined4 *)(s->sid_ctx + 0xc) = *(undefined4 *)(ctx->sid_ctx + 0xc);
      *(undefined4 *)(s->sid_ctx + 0x10) = *(undefined4 *)(ctx->sid_ctx + 0x10);
      *(undefined4 *)(s->sid_ctx + 0x14) = *(undefined4 *)(ctx->sid_ctx + 0x14);
      *(undefined4 *)(s->sid_ctx + 0x18) = *(undefined4 *)(ctx->sid_ctx + 0x18);
      *(undefined4 *)(s->sid_ctx + 0x1c) = *(undefined4 *)(ctx->sid_ctx + 0x1c);
      s->verify_callback = (_func_3151 *)ctx->default_verify_callback;
      s->generate_session_id = ctx->generate_session_id;
      to = X509_VERIFY_PARAM_new();
      s->param = to;
      if (to != (X509_VERIFY_PARAM *)0x0) {
        X509_VERIFY_PARAM_inherit(to,ctx->param);
        s->quiet_shutdown = ctx->quiet_shutdown;
        s->client_version = ctx->max_send_fragment;
        CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x159);
        s->psk_server_callback = (_func_3154 *)ctx;
        s->max_send_fragment = 0;
        s->tlsext_debug_cb = (_func_3155 *)0x0;
        s->tlsext_ocsp_resplen = 0;
        s->servername_done = -1;
        s->tlsext_status_type = 0;
        s->tlsext_status_expected = 0;
        s->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)0x0;
        s->tlsext_ocsp_exts = (X509_EXTENSIONS *)0x0;
        s->tlsext_ocsp_resp = (uchar *)0xffffffff;
        CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x165);
        pSVar1 = ctx->method;
        s->tls_session_secret_cb_arg = ctx;
        s->initial_ctx = (SSL_CTX *)0x0;
        s->debug = 0;
        s->method = pSVar1;
        iVar3 = (*pSVar1->ssl_new)(s);
        if (iVar3 != 0) {
          pSVar1 = ctx->method;
          s->client_CA = (stack_st_X509_NAME *)0x1;
          s->server = (uint)(pSVar1->ssl_accept != ssl_undefined_function);
          SSL_clear(s);
          CRYPTO_new_ex_data(1,s,(CRYPTO_EX_DATA *)&s->verify_result);
          s->kssl_ctx = (KSSL_CTX *)ctx->psk_client_callback;
          s->psk_client_callback = (_func_3153 *)ctx->psk_server_callback;
          return s;
        }
      }
      if (s->cert != (cert_st *)0x0) {
        ssl_cert_free(s->cert);
      }
    }
    else {
      pcVar2 = (cert_st *)ssl_cert_dup(ctx->cert);
      s->cert = pcVar2;
      if (pcVar2 != (cert_st *)0x0) goto LAB_080bf1f0;
    }
    if (s->psk_server_callback != (_func_3154 *)0x0) {
      iVar3 = CRYPTO_add_lock((int *)(s->psk_server_callback + 0x60),-1,0xc,"ssl_lib.c",0x773);
      if (iVar3 < 1) {
        SSL_CTX_free_part_6();
      }
    }
    CRYPTO_free(s);
  }
  line = 0x189;
  iVar3 = 0x41;
LAB_080bf453:
  ERR_put_error(0x14,0xba,iVar3,"ssl_lib.c",line);
  return (SSL *)0x0;
}

