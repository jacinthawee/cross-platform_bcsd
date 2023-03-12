
SSL * SSL_dup(SSL *ssl)

{
  undefined *puVar1;
  SSL *s;
  SSL_METHOD *pSVar2;
  _func_3151 *p_Var3;
  undefined4 uVar4;
  SSL_CTX *pSVar5;
  stack_st_SSL_CIPHER *psVar6;
  undefined4 uVar7;
  SSL_SESSION *pSVar8;
  _func_3152 *p_Var9;
  int iVar10;
  void *pvVar11;
  BIO *pBVar12;
  cert_st *pcVar13;
  _func_3150 *p_Var14;
  X509_VERIFY_PARAM *pXVar15;
  int iVar16;
  int iVar17;
  ulong uVar18;
  int iVar19;
  ulong uVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  _func_3149 *p_Var25;
  int iVar26;
  _func_3053 *p_Var27;
  
  s = SSL_new((SSL_CTX *)ssl->psk_server_callback);
  if (s == (SSL *)0x0) {
    return (SSL *)0x0;
  }
  iVar10 = ssl->type;
  pSVar2 = ssl->method;
  pSVar8 = ssl->session;
  s->version = ssl->version;
  s->type = iVar10;
  s->method = pSVar2;
  if (pSVar8 == (SSL_SESSION *)0x0) {
    (*pSVar2->ssl_free)(s);
    p_Var27 = ssl->method->ssl_new;
    s->method = ssl->method;
    (*p_Var27)(s);
    pcVar13 = ssl->cert;
    if (pcVar13 != (cert_st *)0x0) {
      if (s->cert != (cert_st *)0x0) {
        ssl_cert_free(s->cert);
        pcVar13 = ssl->cert;
      }
      pcVar13 = (cert_st *)ssl_cert_dup(pcVar13);
      s->cert = pcVar13;
      if (pcVar13 == (cert_st *)0x0) goto LAB_004ab7c8;
    }
    puVar1 = PTR_memcpy_006a9aec;
    if (ssl->sid_ctx_length < 0x21) {
      s->sid_ctx_length = ssl->sid_ctx_length;
      (*(code *)puVar1)(s->sid_ctx,ssl->sid_ctx);
    }
    else {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xda,0x111,"ssl_lib.c",0x1a1);
    }
  }
  else {
    SSL_copy_session_id(s,ssl);
  }
  uVar20 = ssl->options;
  uVar18 = ssl->mode;
  iVar16 = ssl->read_ahead;
  p_Var14 = ssl->msg_callback;
  pvVar11 = ssl->msg_callback_arg;
  iVar10 = ssl->verify_mode;
  p_Var3 = ssl->verify_callback;
  s->references = ssl->references;
  s->options = uVar20;
  s->mode = uVar18;
  s->read_ahead = iVar16;
  s->msg_callback = p_Var14;
  s->msg_callback_arg = pvVar11;
  s->verify_mode = iVar10;
  if (p_Var3 != (_func_3151 *)0x0) {
    s->verify_callback = p_Var3;
  }
  uVar4 = (*(code *)PTR_X509_VERIFY_PARAM_get_depth_006a832c)(ssl->param);
  (*(code *)PTR_X509_VERIFY_PARAM_set_depth_006a7c10)(s->param,uVar4);
  p_Var9 = ssl->info_callback;
  pSVar5 = ssl->ctx;
  s->generate_session_id = ssl->generate_session_id;
  s->info_callback = p_Var9;
  s->ctx = pSVar5;
  iVar10 = CRYPTO_dup_ex_data(1,(CRYPTO_EX_DATA *)&s->verify_result,
                              (CRYPTO_EX_DATA *)&ssl->verify_result);
  if ((iVar10 != 0) &&
     ((ssl->rbio == (BIO *)0x0 ||
      (iVar10 = (*(code *)PTR_BIO_ctrl_006a6e18)(ssl->rbio,0xc,0,&s->rbio), iVar10 != 0)))) {
    pBVar12 = ssl->wbio;
    if (pBVar12 != (BIO *)0x0) {
      if (pBVar12 == ssl->rbio) {
        s->wbio = s->rbio;
      }
      else {
        iVar10 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar12,0xc,0,&s->wbio);
        if (iVar10 == 0) goto LAB_004ab7c8;
      }
    }
    puVar1 = PTR_X509_VERIFY_PARAM_inherit_006a8310;
    iVar26 = ssl->in_handshake;
    p_Var25 = ssl->handshake_func;
    iVar24 = ssl->server;
    uVar23 = ssl->tlsext_hb_seq;
    iVar22 = ssl->new_session;
    iVar21 = ssl->quiet_shutdown;
    iVar19 = ssl->shutdown;
    iVar17 = ssl->state;
    iVar16 = ssl->rstate;
    iVar10 = ssl->hit;
    pXVar15 = ssl->param;
    s->rwstate = ssl->rwstate;
    s->in_handshake = iVar26;
    s->handshake_func = p_Var25;
    s->server = iVar24;
    s->tlsext_hb_seq = uVar23;
    s->new_session = iVar22;
    s->quiet_shutdown = iVar21;
    s->shutdown = iVar19;
    s->state = iVar17;
    s->rstate = iVar16;
    s->init_num = 0;
    s->hit = iVar10;
    (*(code *)puVar1)(s->param,pXVar15);
    if (ssl->cipher_list != (stack_st_SSL_CIPHER *)0x0) {
      psVar6 = (stack_st_SSL_CIPHER *)(*(code *)PTR_sk_dup_006a7f54)();
      s->cipher_list = psVar6;
      if (psVar6 == (stack_st_SSL_CIPHER *)0x0) goto LAB_004ab7c8;
    }
    if (ssl->cipher_list_by_id != (stack_st_SSL_CIPHER *)0x0) {
      psVar6 = (stack_st_SSL_CIPHER *)(*(code *)PTR_sk_dup_006a7f54)();
      s->cipher_list_by_id = psVar6;
      if (psVar6 == (stack_st_SSL_CIPHER *)0x0) goto LAB_004ab7c8;
    }
    if ((ssl->ex_data).dummy == 0) {
      return s;
    }
    iVar10 = (*(code *)PTR_sk_dup_006a7f54)();
    if (iVar10 != 0) {
      (s->ex_data).dummy = iVar10;
      iVar16 = 0;
      do {
        iVar17 = (*(code *)PTR_sk_num_006a6e2c)(iVar10);
        if (iVar17 <= iVar16) {
          return s;
        }
        uVar4 = (*(code *)PTR_sk_value_006a6e24)(iVar10,iVar16);
        uVar7 = (*(code *)PTR_X509_NAME_dup_006a713c)(uVar4);
        iVar17 = (*(code *)PTR_sk_set_006a8358)(iVar10,iVar16,uVar7);
        iVar16 = iVar16 + 1;
      } while (iVar17 != 0);
      (*(code *)PTR_X509_NAME_free_006a6ff8)(uVar4);
    }
  }
LAB_004ab7c8:
  iVar10 = CRYPTO_add_lock((int *)&s->client_CA,-1,0x10,"ssl_lib.c",0x203);
  if (0 < iVar10) {
    return (SSL *)0x0;
  }
  SSL_free_part_7(s);
  return (SSL *)0x0;
}

