
SSL * SSL_dup(SSL *ssl)

{
  SSL_SESSION *pSVar1;
  SSL_METHOD *pSVar2;
  _func_3151 *p_Var3;
  BIO *bp;
  uint __n;
  SSL *s;
  int iVar4;
  long lVar5;
  _STACK *p_Var6;
  X509_NAME *xn;
  X509_NAME *pXVar7;
  void *pvVar8;
  int iVar9;
  cert_st *pcVar10;
  
  s = SSL_new((SSL_CTX *)ssl->psk_server_callback);
  if (s == (SSL *)0x0) {
    return (SSL *)0x0;
  }
  pSVar1 = ssl->session;
  s->version = ssl->version;
  s->type = ssl->type;
  pSVar2 = ssl->method;
  s->method = pSVar2;
  if (pSVar1 == (SSL_SESSION *)0x0) {
    (*pSVar2->ssl_free)(s);
    pSVar2 = ssl->method;
    s->method = pSVar2;
    (*pSVar2->ssl_new)(s);
    pcVar10 = ssl->cert;
    if (pcVar10 != (cert_st *)0x0) {
      if (s->cert != (cert_st *)0x0) {
        ssl_cert_free(s->cert);
        pcVar10 = ssl->cert;
      }
      pcVar10 = (cert_st *)ssl_cert_dup(pcVar10);
      s->cert = pcVar10;
      if (pcVar10 == (cert_st *)0x0) goto LAB_080c3ca9;
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
  iVar4 = ssl->verify_mode;
  s->references = ssl->references;
  s->options = ssl->options;
  s->mode = ssl->mode;
  s->read_ahead = ssl->read_ahead;
  s->msg_callback = ssl->msg_callback;
  s->msg_callback_arg = ssl->msg_callback_arg;
  p_Var3 = ssl->verify_callback;
  s->verify_mode = iVar4;
  if (p_Var3 != (_func_3151 *)0x0) {
    s->verify_callback = p_Var3;
  }
  iVar4 = X509_VERIFY_PARAM_get_depth(ssl->param);
  X509_VERIFY_PARAM_set_depth(s->param,iVar4);
  s->generate_session_id = ssl->generate_session_id;
  s->info_callback = ssl->info_callback;
  s->ctx = ssl->ctx;
  iVar4 = CRYPTO_dup_ex_data(1,(CRYPTO_EX_DATA *)&s->verify_result,
                             (CRYPTO_EX_DATA *)&ssl->verify_result);
  if ((iVar4 != 0) &&
     ((ssl->rbio == (BIO *)0x0 || (lVar5 = BIO_ctrl(ssl->rbio,0xc,0,&s->rbio), lVar5 != 0)))) {
    bp = ssl->wbio;
    if (bp != (BIO *)0x0) {
      if (bp == ssl->rbio) {
        s->wbio = s->rbio;
      }
      else {
        lVar5 = BIO_ctrl(bp,0xc,0,&s->wbio);
        if (lVar5 == 0) goto LAB_080c3ca9;
      }
    }
    s->rwstate = ssl->rwstate;
    s->in_handshake = ssl->in_handshake;
    s->handshake_func = ssl->handshake_func;
    s->server = ssl->server;
    s->tlsext_hb_seq = ssl->tlsext_hb_seq;
    s->new_session = ssl->new_session;
    s->quiet_shutdown = ssl->quiet_shutdown;
    s->shutdown = ssl->shutdown;
    s->state = ssl->state;
    iVar4 = ssl->rstate;
    s->init_num = 0;
    s->rstate = iVar4;
    s->hit = ssl->hit;
    X509_VERIFY_PARAM_inherit(s->param,ssl->param);
    if ((_STACK *)ssl->cipher_list != (_STACK *)0x0) {
      p_Var6 = sk_dup((_STACK *)ssl->cipher_list);
      s->cipher_list = (stack_st_SSL_CIPHER *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_080c3ca9;
    }
    if ((_STACK *)ssl->cipher_list_by_id != (_STACK *)0x0) {
      p_Var6 = sk_dup((_STACK *)ssl->cipher_list_by_id);
      s->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var6;
      if (p_Var6 == (_STACK *)0x0) goto LAB_080c3ca9;
    }
    p_Var6 = (_STACK *)(ssl->ex_data).dummy;
    if (p_Var6 == (_STACK *)0x0) {
      return s;
    }
    p_Var6 = sk_dup(p_Var6);
    if (p_Var6 != (_STACK *)0x0) {
      (s->ex_data).dummy = (int)p_Var6;
      iVar4 = 0;
      while( true ) {
        iVar9 = sk_num(p_Var6);
        if (iVar9 <= iVar4) {
          return s;
        }
        xn = (X509_NAME *)sk_value(p_Var6,iVar4);
        pXVar7 = X509_NAME_dup(xn);
        pvVar8 = sk_set(p_Var6,iVar4,pXVar7);
        if (pvVar8 == (void *)0x0) break;
        iVar4 = iVar4 + 1;
      }
      X509_NAME_free(xn);
    }
  }
LAB_080c3ca9:
  SSL_free(s);
  return (SSL *)0x0;
}

