
SSL * SSL_new(SSL_CTX *ctx)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  undefined *puVar27;
  SSL *s;
  uint uVar28;
  GEN_SESSION_CB pGVar29;
  X509_VERIFY_PARAM *pXVar30;
  SSL_METHOD *pSVar31;
  undefined4 uVar32;
  ulong uVar33;
  int iVar34;
  _func_3153 *p_Var35;
  cert_st *pcVar36;
  char *pcVar37;
  ulong uVar38;
  void *pvVar39;
  char *pcVar40;
  undefined4 uVar41;
  uint in_a3;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  
  if (ctx == (SSL_CTX *)0x0) {
    uVar41 = 0xc3;
    uVar32 = 0x122;
LAB_004a6d48:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xba,uVar41,"ssl_lib.c",uVar32);
    return (SSL *)0x0;
  }
  if (ctx->method == (SSL_METHOD *)0x0) {
    uVar41 = 0xe4;
    uVar32 = 0x126;
    goto LAB_004a6d48;
  }
  s = (SSL *)CRYPTO_malloc(0x1d4,"ssl_lib.c",0x12a);
  if (s == (SSL *)0x0) goto LAB_004a6ca0;
  (*(code *)PTR_memset_006a99f4)(s,0,0x1d4);
  uVar38 = ctx->options;
  uVar33 = ctx->mode;
  pcVar36 = ctx->cert;
  s->mode = ctx->max_cert_list;
  s->references = uVar38;
  s->options = uVar33;
  s->client_CA = (stack_st_X509_NAME *)0x1;
  if (pcVar36 == (cert_st *)0x0) {
    uVar28 = ctx->sid_ctx_length;
    pcVar40 = (char *)ctx->read_ahead;
    pvVar39 = ctx->msg_callback_arg;
    pcVar37 = (char *)ctx->verify_mode;
    s->msg_callback = (_func_3150 *)ctx->msg_callback;
    s->cert = (cert_st *)0x0;
    s->read_ahead = (int)pcVar40;
    s->msg_callback_arg = pvVar39;
    s->verify_mode = (int)pcVar37;
    s->sid_ctx_length = uVar28;
joined_r0x004a6d0c:
    if (0x20 < uVar28) {
      pvVar39 = (void *)0x151;
      pcVar40 = "s->sid_ctx_length <= sizeof s->sid_ctx";
      pcVar37 = "ssl_lib.c";
      OpenSSLDie("ssl_lib.c",0x151,"s->sid_ctx_length <= sizeof s->sid_ctx");
    }
    puVar27 = PTR_X509_VERIFY_PARAM_new_006a7c00;
    uVar28 = (uint)(ctx->sid_ctx + 4) & 3;
    iVar34 = *(int *)(ctx->sid_ctx + 4 + -uVar28);
    uVar1 = (uint)(ctx->sid_ctx + 8) & 3;
    iVar7 = *(int *)(ctx->sid_ctx + 8 + -uVar1);
    uVar2 = (uint)(ctx->sid_ctx + 0xc) & 3;
    iVar8 = *(int *)(ctx->sid_ctx + 0xc + -uVar2);
    uVar3 = (uint)(ctx->sid_ctx + 0x10) & 3;
    iVar9 = *(int *)(ctx->sid_ctx + 0x10 + -uVar3);
    uVar4 = (uint)(ctx->sid_ctx + 0x14) & 3;
    iVar10 = *(int *)(ctx->sid_ctx + 0x14 + -uVar4);
    uVar5 = (uint)(ctx->sid_ctx + 0x18) & 3;
    iVar11 = *(int *)(ctx->sid_ctx + 0x18 + -uVar5);
    uVar6 = (uint)(ctx->sid_ctx + 0x1c) & 3;
    iVar12 = *(int *)(ctx->sid_ctx + 0x1c + -uVar6);
    uVar13 = (uint)(ctx->sid_ctx + 7) & 3;
    uVar20 = *(uint *)(ctx->sid_ctx + 7 + -uVar13);
    uVar14 = (uint)(ctx->sid_ctx + 0xb) & 3;
    uVar21 = *(uint *)(ctx->sid_ctx + 0xb + -uVar14);
    uVar15 = (uint)(ctx->sid_ctx + 0xf) & 3;
    uVar22 = *(uint *)(ctx->sid_ctx + 0xf + -uVar15);
    uVar16 = (uint)(ctx->sid_ctx + 0x13) & 3;
    uVar23 = *(uint *)(ctx->sid_ctx + 0x13 + -uVar16);
    uVar17 = (uint)(ctx->sid_ctx + 0x17) & 3;
    uVar24 = *(uint *)(ctx->sid_ctx + 0x17 + -uVar17);
    uVar18 = (uint)(ctx->sid_ctx + 0x1b) & 3;
    uVar25 = *(uint *)(ctx->sid_ctx + 0x1b + -uVar18);
    uVar19 = (uint)(ctx->sid_ctx + 0x1f) & 3;
    uVar26 = *(uint *)(ctx->sid_ctx + 0x1f + -uVar19);
    *(undefined4 *)s->sid_ctx = *(undefined4 *)ctx->sid_ctx;
    *(uint *)(s->sid_ctx + 4) =
         (iVar34 << uVar28 * 8 | in_t2 & 0xffffffffU >> (4 - uVar28) * 8) & -1 << (uVar13 + 1) * 8 |
         uVar20 >> (3 - uVar13) * 8;
    *(uint *)(s->sid_ctx + 8) =
         (iVar7 << uVar1 * 8 | in_t1 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar14 + 1) * 8 |
         uVar21 >> (3 - uVar14) * 8;
    *(uint *)(s->sid_ctx + 0xc) =
         (iVar8 << uVar2 * 8 | in_t0 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar15 + 1) * 8 |
         uVar22 >> (3 - uVar15) * 8;
    *(uint *)(s->sid_ctx + 0x10) =
         (iVar9 << uVar3 * 8 | in_a3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar16 + 1) * 8 |
         uVar23 >> (3 - uVar16) * 8;
    *(uint *)(s->sid_ctx + 0x14) =
         (iVar10 << uVar4 * 8 | (uint)pcVar40 & 0xffffffffU >> (4 - uVar4) * 8) &
         -1 << (uVar17 + 1) * 8 | uVar24 >> (3 - uVar17) * 8;
    *(uint *)(s->sid_ctx + 0x18) =
         (iVar11 << uVar5 * 8 | (uint)pvVar39 & 0xffffffffU >> (4 - uVar5) * 8) &
         -1 << (uVar18 + 1) * 8 | uVar25 >> (3 - uVar18) * 8;
    *(uint *)(s->sid_ctx + 0x1c) =
         (iVar12 << uVar6 * 8 | (uint)pcVar37 & 0xffffffffU >> (4 - uVar6) * 8) &
         -1 << (uVar19 + 1) * 8 | uVar26 >> (3 - uVar19) * 8;
    pGVar29 = ctx->generate_session_id;
    s->verify_callback = (_func_3151 *)ctx->default_verify_callback;
    s->generate_session_id = pGVar29;
    pXVar30 = (X509_VERIFY_PARAM *)(*(code *)puVar27)();
    s->param = pXVar30;
    if (pXVar30 != (X509_VERIFY_PARAM *)0x0) {
      (*(code *)PTR_X509_VERIFY_PARAM_inherit_006a8310)(pXVar30,ctx->param);
      iVar34 = ctx->quiet_shutdown;
      s->client_version = ctx->max_send_fragment;
      s->quiet_shutdown = iVar34;
      CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x161);
      s->psk_server_callback = (_func_3154 *)ctx;
      s->servername_done = -1;
      s->tlsext_ocsp_resp = (uchar *)0xffffffff;
      s->max_send_fragment = 0;
      s->tlsext_debug_cb = (_func_3155 *)0x0;
      s->tlsext_ocsp_resplen = 0;
      s->tlsext_status_type = 0;
      s->tlsext_status_expected = 0;
      s->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)0x0;
      s->tlsext_ocsp_exts = (X509_EXTENSIONS *)0x0;
      CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x16d);
      pSVar31 = ctx->method;
      s->tls_session_secret_cb_arg = ctx;
      s->initial_ctx = (SSL_CTX *)0x0;
      s->debug = 0;
      s->method = pSVar31;
      iVar34 = (*pSVar31->ssl_new)(s);
      if (iVar34 != 0) {
        s->server = (uint)(ctx->method->ssl_accept != ssl_undefined_function);
        SSL_clear(s);
        CRYPTO_new_ex_data(1,s,(CRYPTO_EX_DATA *)&s->verify_result);
        p_Var35 = (_func_3153 *)ctx->psk_server_callback;
        s->kssl_ctx = (KSSL_CTX *)ctx->psk_client_callback;
        s->psk_client_callback = p_Var35;
        return s;
      }
    }
  }
  else {
    pcVar36 = (cert_st *)ssl_cert_dup();
    s->cert = pcVar36;
    if (pcVar36 != (cert_st *)0x0) {
      uVar28 = ctx->sid_ctx_length;
      pcVar40 = (char *)ctx->read_ahead;
      pvVar39 = ctx->msg_callback_arg;
      pcVar37 = (char *)ctx->verify_mode;
      s->msg_callback = (_func_3150 *)ctx->msg_callback;
      s->read_ahead = (int)pcVar40;
      s->msg_callback_arg = pvVar39;
      s->verify_mode = (int)pcVar37;
      s->sid_ctx_length = uVar28;
      goto joined_r0x004a6d0c;
    }
  }
  iVar34 = CRYPTO_add_lock((int *)&s->client_CA,-1,0x10,"ssl_lib.c",0x203);
  if (iVar34 < 1) {
    SSL_free_part_7(s);
  }
LAB_004a6ca0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xba,0x41,"ssl_lib.c",0x18a);
  return (SSL *)0x0;
}

