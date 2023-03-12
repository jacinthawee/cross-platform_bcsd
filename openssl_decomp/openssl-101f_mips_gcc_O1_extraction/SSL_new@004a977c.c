
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
  ulong uVar28;
  uint uVar29;
  GEN_SESSION_CB pGVar30;
  X509_VERIFY_PARAM *pXVar31;
  SSL_METHOD *pSVar32;
  undefined4 uVar33;
  ulong uVar34;
  int iVar35;
  _func_3056 *p_Var36;
  _func_3153 *p_Var37;
  cert_st *pcVar38;
  char *pcVar39;
  undefined *puVar40;
  char *pcVar41;
  undefined4 uVar42;
  uint in_a3;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  _func_3154 *p_Var43;
  
  if (ctx == (SSL_CTX *)0x0) {
    uVar42 = 0xc3;
    uVar33 = 0x119;
LAB_004a9b40:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xba,uVar42,"ssl_lib.c",uVar33);
    return (SSL *)0x0;
  }
  if (ctx->method == (SSL_METHOD *)0x0) {
    uVar42 = 0xe4;
    uVar33 = 0x11e;
    goto LAB_004a9b40;
  }
  s = (SSL *)CRYPTO_malloc(0x1d4,"ssl_lib.c",0x122);
  if (s == (SSL *)0x0) goto LAB_004a9a98;
  (*(code *)PTR_memset_006aab00)(s,0,0x1d4);
  uVar34 = ctx->mode;
  uVar28 = ctx->max_cert_list;
  pcVar38 = ctx->cert;
  s->references = ctx->options;
  s->options = uVar34;
  s->mode = uVar28;
  if (pcVar38 == (cert_st *)0x0) {
    uVar29 = ctx->sid_ctx_length;
    pcVar41 = (char *)ctx->read_ahead;
    puVar40 = (undefined *)ctx->msg_callback_arg;
    pcVar39 = (char *)ctx->verify_mode;
    s->msg_callback = (_func_3150 *)ctx->msg_callback;
    s->cert = (cert_st *)0x0;
    s->read_ahead = (int)pcVar41;
    s->msg_callback_arg = puVar40;
    s->verify_mode = (int)pcVar39;
    s->sid_ctx_length = uVar29;
joined_r0x004a9b04:
    if (0x20 < uVar29) {
      puVar40 = &DAT_00000149;
      pcVar41 = "s->sid_ctx_length <= sizeof s->sid_ctx";
      pcVar39 = "ssl_lib.c";
      OpenSSLDie("ssl_lib.c",0x149,"s->sid_ctx_length <= sizeof s->sid_ctx");
    }
    puVar27 = PTR_X509_VERIFY_PARAM_new_006a8cec;
    uVar29 = (uint)(ctx->sid_ctx + 4) & 3;
    iVar35 = *(int *)(ctx->sid_ctx + 4 + -uVar29);
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
         (iVar35 << uVar29 * 8 | in_t2 & 0xffffffffU >> (4 - uVar29) * 8) & -1 << (uVar13 + 1) * 8 |
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
         (iVar10 << uVar4 * 8 | (uint)pcVar41 & 0xffffffffU >> (4 - uVar4) * 8) &
         -1 << (uVar17 + 1) * 8 | uVar24 >> (3 - uVar17) * 8;
    *(uint *)(s->sid_ctx + 0x18) =
         (iVar11 << uVar5 * 8 | (uint)puVar40 & 0xffffffffU >> (4 - uVar5) * 8) &
         -1 << (uVar18 + 1) * 8 | uVar25 >> (3 - uVar18) * 8;
    *(uint *)(s->sid_ctx + 0x1c) =
         (iVar12 << uVar6 * 8 | (uint)pcVar39 & 0xffffffffU >> (4 - uVar6) * 8) &
         -1 << (uVar19 + 1) * 8 | uVar26 >> (3 - uVar19) * 8;
    pGVar30 = ctx->generate_session_id;
    s->verify_callback = (_func_3151 *)ctx->default_verify_callback;
    s->generate_session_id = pGVar30;
    pXVar31 = (X509_VERIFY_PARAM *)(*(code *)puVar27)();
    s->param = pXVar31;
    if (pXVar31 != (X509_VERIFY_PARAM *)0x0) {
      (*(code *)PTR_X509_VERIFY_PARAM_inherit_006a942c)(pXVar31,ctx->param);
      iVar35 = ctx->quiet_shutdown;
      s->client_version = ctx->max_send_fragment;
      s->quiet_shutdown = iVar35;
      CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x159);
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
      CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0x165);
      pSVar32 = ctx->method;
      s->tls_session_secret_cb_arg = ctx;
      s->initial_ctx = (SSL_CTX *)0x0;
      s->debug = 0;
      s->method = pSVar32;
      iVar35 = (*pSVar32->ssl_new)(s);
      if (iVar35 != 0) {
        p_Var36 = ctx->method->ssl_accept;
        s->client_CA = (stack_st_X509_NAME *)0x1;
        s->server = (uint)(p_Var36 != ssl_undefined_function);
        SSL_clear(s);
        CRYPTO_new_ex_data(1,s,(CRYPTO_EX_DATA *)&s->verify_result);
        p_Var37 = (_func_3153 *)ctx->psk_server_callback;
        s->kssl_ctx = (KSSL_CTX *)ctx->psk_client_callback;
        s->psk_client_callback = p_Var37;
        return s;
      }
    }
    if (s->cert != (cert_st *)0x0) {
      ssl_cert_free();
    }
  }
  else {
    pcVar38 = (cert_st *)ssl_cert_dup();
    s->cert = pcVar38;
    if (pcVar38 != (cert_st *)0x0) {
      uVar29 = ctx->sid_ctx_length;
      pcVar41 = (char *)ctx->read_ahead;
      puVar40 = (undefined *)ctx->msg_callback_arg;
      pcVar39 = (char *)ctx->verify_mode;
      s->msg_callback = (_func_3150 *)ctx->msg_callback;
      s->read_ahead = (int)pcVar41;
      s->msg_callback_arg = puVar40;
      s->verify_mode = (int)pcVar39;
      s->sid_ctx_length = uVar29;
      goto joined_r0x004a9b04;
    }
  }
  p_Var43 = s->psk_server_callback;
  if ((p_Var43 != (_func_3154 *)0x0) &&
     (iVar35 = CRYPTO_add_lock((int *)(p_Var43 + 0x60),-1,0xc,"ssl_lib.c",0x773), iVar35 < 1)) {
    SSL_CTX_free_part_6(p_Var43);
  }
  CRYPTO_free(s);
LAB_004a9a98:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xba,0x41,"ssl_lib.c",0x189);
  return (SSL *)0x0;
}

