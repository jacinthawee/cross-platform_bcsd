
SSL * SSL_new(SSL_CTX *ctx)

{
  ulong uVar1;
  SSL_METHOD *pSVar2;
  SSL *s;
  cert_st *pcVar3;
  X509_VERIFY_PARAM *to;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte bVar7;
  int line;
  
  bVar7 = 0;
  if (ctx == (SSL_CTX *)0x0) {
    line = 0x122;
    iVar4 = 0xc3;
    goto LAB_080bceca;
  }
  if (ctx->method == (SSL_METHOD *)0x0) {
    line = 0x126;
    iVar4 = 0xe4;
    goto LAB_080bceca;
  }
  s = (SSL *)CRYPTO_malloc(0x1d4,"ssl_lib.c",0x12a);
  if (s != (SSL *)0x0) {
    s->version = 0;
    s[1].rstate = 0;
    puVar6 = (undefined4 *)((uint)&s->type & 0xfffffffc);
    uVar5 = (uint)((int)s + (0x1d4 - (int)puVar6)) >> 2;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
    }
    s->references = ctx->options;
    s->options = ctx->mode;
    uVar1 = ctx->max_cert_list;
    s->client_CA = (stack_st_X509_NAME *)0x1;
    s->mode = uVar1;
    if (ctx->cert == (cert_st *)0x0) {
      s->cert = (cert_st *)0x0;
LAB_080bcc9a:
      s->read_ahead = ctx->read_ahead;
      s->msg_callback = (_func_3150 *)ctx->msg_callback;
      s->msg_callback_arg = ctx->msg_callback_arg;
      s->verify_mode = ctx->verify_mode;
      uVar5 = ctx->sid_ctx_length;
      s->sid_ctx_length = uVar5;
      if (0x20 < uVar5) {
        OpenSSLDie("ssl_lib.c",0x151,"s->sid_ctx_length <= sizeof s->sid_ctx");
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
        CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x161);
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
        CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x16d);
        pSVar2 = ctx->method;
        s->tls_session_secret_cb_arg = ctx;
        s->initial_ctx = (SSL_CTX *)0x0;
        s->debug = 0;
        s->method = pSVar2;
        iVar4 = (*pSVar2->ssl_new)(s);
        if (iVar4 != 0) {
          s->server = (uint)(ctx->method->ssl_accept != ssl_undefined_function);
          SSL_clear(s);
          CRYPTO_new_ex_data(1,s,(CRYPTO_EX_DATA *)&s->verify_result);
          s->kssl_ctx = (KSSL_CTX *)ctx->psk_client_callback;
          s->psk_client_callback = (_func_3153 *)ctx->psk_server_callback;
          return s;
        }
      }
    }
    else {
      pcVar3 = (cert_st *)ssl_cert_dup(ctx->cert);
      s->cert = pcVar3;
      if (pcVar3 != (cert_st *)0x0) goto LAB_080bcc9a;
    }
    iVar4 = CRYPTO_add_lock((int *)&s->client_CA,-1,0x10,"ssl_lib.c",0x203);
    if (iVar4 < 1) {
      SSL_free_part_7();
    }
  }
  line = 0x18a;
  iVar4 = 0x41;
LAB_080bceca:
  ERR_put_error(0x14,0xba,iVar4,"ssl_lib.c",line);
  return (SSL *)0x0;
}

