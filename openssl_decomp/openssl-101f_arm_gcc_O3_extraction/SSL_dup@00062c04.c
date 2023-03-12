
SSL * SSL_dup(SSL *ssl)

{
  SSL *s;
  _func_3151 *p_Var1;
  long lVar2;
  BIO *bp;
  _func_3149 *p_Var3;
  _STACK *p_Var4;
  X509_NAME *xn;
  X509_NAME *pXVar5;
  cert_st *pcVar6;
  _func_3150 *p_Var7;
  int iVar8;
  void *pvVar9;
  size_t __n;
  SSL_METHOD *pSVar10;
  SSL_CTX *pSVar11;
  SSL_SESSION *pSVar12;
  int iVar13;
  _func_3152 *p_Var14;
  int iVar15;
  ulong uVar16;
  int iVar17;
  ulong uVar18;
  uint uVar19;
  int iVar20;
  
  s = SSL_new((SSL_CTX *)ssl->psk_server_callback);
  if (s == (SSL *)0x0) {
    return (SSL *)0x0;
  }
  iVar8 = ssl->type;
  pSVar10 = ssl->method;
  pSVar12 = ssl->session;
  s->version = ssl->version;
  s->type = iVar8;
  s->method = pSVar10;
  if (pSVar12 == (SSL_SESSION *)0x0) {
    (*pSVar10->ssl_free)(s);
    pSVar10 = ssl->method;
    s->method = pSVar10;
    (*pSVar10->ssl_new)(s);
    pcVar6 = ssl->cert;
    if (pcVar6 != (cert_st *)0x0) {
      if (s->cert != (cert_st *)0x0) {
        ssl_cert_free(s->cert);
        pcVar6 = ssl->cert;
      }
      pcVar6 = (cert_st *)ssl_cert_dup(pcVar6);
      s->cert = pcVar6;
      if (pcVar6 == (cert_st *)0x0) goto LAB_00062ca8;
    }
    __n = ssl->sid_ctx_length;
    if (__n < 0x21) {
      s->sid_ctx_length = __n;
      memcpy(s->sid_ctx,ssl->sid_ctx,__n);
    }
    else {
      ERR_put_error(0x14,0xda,0x111,"ssl_lib.c",0x1a0);
    }
  }
  else {
    SSL_copy_session_id(s,ssl);
  }
  uVar18 = ssl->options;
  uVar16 = ssl->mode;
  iVar13 = ssl->read_ahead;
  p_Var7 = ssl->msg_callback;
  pvVar9 = ssl->msg_callback_arg;
  p_Var1 = ssl->verify_callback;
  s->verify_mode = ssl->verify_mode;
  iVar8 = ssl->references;
  s->options = uVar18;
  s->mode = uVar16;
  s->references = iVar8;
  s->read_ahead = iVar13;
  s->msg_callback = p_Var7;
  s->msg_callback_arg = pvVar9;
  if (p_Var1 != (_func_3151 *)0x0) {
    s->verify_callback = p_Var1;
  }
  iVar8 = X509_VERIFY_PARAM_get_depth(ssl->param);
  X509_VERIFY_PARAM_set_depth(s->param,iVar8);
  p_Var14 = ssl->info_callback;
  pSVar11 = ssl->ctx;
  s->generate_session_id = ssl->generate_session_id;
  s->info_callback = p_Var14;
  s->ctx = pSVar11;
  iVar8 = CRYPTO_dup_ex_data(1,(CRYPTO_EX_DATA *)&s->verify_result,
                             (CRYPTO_EX_DATA *)&ssl->verify_result);
  if ((iVar8 != 0) &&
     ((ssl->rbio == (BIO *)0x0 || (lVar2 = BIO_ctrl(ssl->rbio,0xc,0,&s->rbio), lVar2 != 0)))) {
    bp = ssl->wbio;
    if (bp != (BIO *)0x0) {
      if (bp == ssl->rbio) {
        s->wbio = s->rbio;
      }
      else {
        lVar2 = BIO_ctrl(bp,0xc,0,&s->wbio);
        if (lVar2 == 0) goto LAB_00062ca8;
      }
    }
    p_Var3 = ssl->handshake_func;
    iVar8 = ssl->server;
    uVar19 = ssl->tlsext_hb_seq;
    iVar17 = ssl->rwstate;
    iVar15 = ssl->in_handshake;
    s->new_session = ssl->new_session;
    iVar13 = ssl->shutdown;
    s->tlsext_hb_seq = uVar19;
    iVar20 = ssl->quiet_shutdown;
    s->shutdown = iVar13;
    s->state = ssl->state;
    s->rstate = ssl->rstate;
    iVar13 = ssl->hit;
    s->handshake_func = p_Var3;
    s->server = iVar8;
    s->hit = iVar13;
    s->rwstate = iVar17;
    s->in_handshake = iVar15;
    s->quiet_shutdown = iVar20;
    s->init_num = 0;
    X509_VERIFY_PARAM_inherit(s->param,ssl->param);
    if ((_STACK *)ssl->cipher_list != (_STACK *)0x0) {
      p_Var4 = sk_dup((_STACK *)ssl->cipher_list);
      s->cipher_list = (stack_st_SSL_CIPHER *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00062ca8;
    }
    if ((_STACK *)ssl->cipher_list_by_id != (_STACK *)0x0) {
      p_Var4 = sk_dup((_STACK *)ssl->cipher_list_by_id);
      s->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00062ca8;
    }
    p_Var4 = (_STACK *)(ssl->ex_data).dummy;
    if (p_Var4 == (_STACK *)0x0) {
      return s;
    }
    p_Var4 = sk_dup(p_Var4);
    if (p_Var4 != (_STACK *)0x0) {
      (s->ex_data).dummy = (int)p_Var4;
      iVar8 = 0;
      do {
        iVar13 = sk_num(p_Var4);
        if (iVar13 <= iVar8) {
          return s;
        }
        xn = (X509_NAME *)sk_value(p_Var4,iVar8);
        pXVar5 = X509_NAME_dup(xn);
        pvVar9 = sk_set(p_Var4,iVar8,pXVar5);
        iVar8 = iVar8 + 1;
      } while (pvVar9 != (void *)0x0);
      X509_NAME_free(xn);
    }
  }
LAB_00062ca8:
  SSL_free(s);
  return (SSL *)0x0;
}

