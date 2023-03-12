
SSL * SSL_new(SSL_CTX *ctx)

{
  SSL *s;
  cert_st *pcVar1;
  _func_3095 *p_Var2;
  undefined4 uVar3;
  X509_VERIFY_PARAM *to;
  void *pvVar4;
  undefined4 uVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  GEN_SESSION_CB pGVar10;
  SSL_METHOD *pSVar11;
  code *pcVar12;
  _func_3153 *p_Var13;
  undefined4 uVar14;
  
  if (ctx == (SSL_CTX *)0x0) {
    ERR_put_error(0x14,0xba,0xc3,"ssl_lib.c",0x122);
    return (SSL *)0x0;
  }
  if (ctx->method == (SSL_METHOD *)0x0) {
    ERR_put_error(0x14,0xba,0xe4,"ssl_lib.c",0x126);
    return (SSL *)0x0;
  }
  s = (SSL *)CRYPTO_malloc(0x1d4,"ssl_lib.c",0x12a);
  if (s == (SSL *)0x0) goto LAB_0005f860;
  memset(s,0,0x1d4);
  uVar6 = ctx->mode;
  uVar8 = ctx->max_cert_list;
  pcVar1 = ctx->cert;
  s->references = ctx->options;
  s->options = uVar6;
  s->mode = uVar8;
  s->client_CA = (stack_st_X509_NAME *)0x1;
  if (pcVar1 == (cert_st *)0x0) {
    s->cert = (cert_st *)0x0;
LAB_0005f720:
    p_Var2 = ctx->msg_callback;
    pvVar4 = ctx->msg_callback_arg;
    iVar7 = ctx->verify_mode;
    uVar9 = ctx->sid_ctx_length;
    s->read_ahead = ctx->read_ahead;
    s->msg_callback = (_func_3150 *)p_Var2;
    s->msg_callback_arg = pvVar4;
    s->verify_mode = iVar7;
    s->sid_ctx_length = uVar9;
    if (0x20 < uVar9) {
      OpenSSLDie("ssl_lib.c",0x151,"s->sid_ctx_length <= sizeof s->sid_ctx");
    }
    uVar14 = *(undefined4 *)(ctx->sid_ctx + 4);
    uVar3 = *(undefined4 *)(ctx->sid_ctx + 8);
    uVar5 = *(undefined4 *)(ctx->sid_ctx + 0xc);
    *(undefined4 *)s->sid_ctx = *(undefined4 *)ctx->sid_ctx;
    *(undefined4 *)(s->sid_ctx + 4) = uVar14;
    *(undefined4 *)(s->sid_ctx + 8) = uVar3;
    *(undefined4 *)(s->sid_ctx + 0xc) = uVar5;
    uVar14 = *(undefined4 *)(ctx->sid_ctx + 0x14);
    uVar3 = *(undefined4 *)(ctx->sid_ctx + 0x18);
    uVar5 = *(undefined4 *)(ctx->sid_ctx + 0x1c);
    *(undefined4 *)(s->sid_ctx + 0x10) = *(undefined4 *)(ctx->sid_ctx + 0x10);
    *(undefined4 *)(s->sid_ctx + 0x14) = uVar14;
    *(undefined4 *)(s->sid_ctx + 0x18) = uVar3;
    *(undefined4 *)(s->sid_ctx + 0x1c) = uVar5;
    pGVar10 = ctx->generate_session_id;
    s->verify_callback = (_func_3151 *)ctx->default_verify_callback;
    s->generate_session_id = pGVar10;
    to = X509_VERIFY_PARAM_new();
    s->param = to;
    if (to != (X509_VERIFY_PARAM *)0x0) {
      X509_VERIFY_PARAM_inherit(to,ctx->param);
      uVar9 = ctx->max_send_fragment;
      s->quiet_shutdown = ctx->quiet_shutdown;
      s->client_version = uVar9;
      CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x161);
      s->psk_server_callback = (_func_3154 *)ctx;
      s->max_send_fragment = 0;
      s->tlsext_debug_cb = (_func_3155 *)0x0;
      s->tlsext_ocsp_resplen = 0;
      s->tlsext_status_type = 0;
      s->tlsext_status_expected = 0;
      s->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)0x0;
      s->tlsext_ocsp_exts = (X509_EXTENSIONS *)0x0;
      s->servername_done = -1;
      s->tlsext_ocsp_resp = (uchar *)0xffffffff;
      CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x16d);
      pSVar11 = ctx->method;
      s->initial_ctx = (SSL_CTX *)0x0;
      s->debug = 0;
      s->method = pSVar11;
      s->tls_session_secret_cb_arg = ctx;
      iVar7 = (*pSVar11->ssl_new)(s);
      if (iVar7 != 0) {
        pcVar12 = ctx->method->ssl_accept + -0x5dd61;
        if (pcVar12 != (code *)0x0) {
          pcVar12 = (code *)0x1;
        }
        s->server = (int)pcVar12;
        SSL_clear(s);
        CRYPTO_new_ex_data(1,s,(CRYPTO_EX_DATA *)&s->verify_result);
        p_Var13 = (_func_3153 *)ctx->psk_server_callback;
        s->kssl_ctx = (KSSL_CTX *)ctx->psk_client_callback;
        s->psk_client_callback = p_Var13;
        return s;
      }
    }
  }
  else {
    pcVar1 = (cert_st *)ssl_cert_dup();
    s->cert = pcVar1;
    if (pcVar1 != (cert_st *)0x0) goto LAB_0005f720;
  }
  SSL_free(s);
LAB_0005f860:
  ERR_put_error(0x14,0xba,0x41,"ssl_lib.c",0x18a);
  return (SSL *)0x0;
}

