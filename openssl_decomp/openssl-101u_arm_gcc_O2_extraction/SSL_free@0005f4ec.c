
void SSL_free(SSL *ssl)

{
  int iVar1;
  _STACK *st;
  BIO *pBVar2;
  BIO *pBVar3;
  
  if (ssl != (SSL *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)&ssl->client_CA,-1,0x10,"ssl_lib.c",0x203);
    if (iVar1 < 1) {
      if (ssl->param != (X509_VERIFY_PARAM *)0x0) {
        X509_VERIFY_PARAM_free(ssl->param);
      }
      CRYPTO_free_ex_data(1,ssl,(CRYPTO_EX_DATA *)&ssl->verify_result);
      pBVar3 = ssl->bbio;
      if (pBVar3 != (BIO *)0x0) {
        if (pBVar3 == ssl->wbio) {
          pBVar2 = BIO_pop(pBVar3);
          pBVar3 = ssl->bbio;
          ssl->wbio = pBVar2;
        }
        BIO_free(pBVar3);
        ssl->bbio = (BIO *)0x0;
      }
      if (ssl->rbio != (BIO *)0x0) {
        BIO_free_all(ssl->rbio);
      }
      pBVar3 = ssl->wbio;
      if ((pBVar3 != (BIO *)0x0) && (pBVar3 != ssl->rbio)) {
        BIO_free_all(pBVar3);
      }
      if (ssl->init_buf != (BUF_MEM *)0x0) {
        BUF_MEM_free(ssl->init_buf);
      }
      if ((_STACK *)ssl->cipher_list != (_STACK *)0x0) {
        sk_free((_STACK *)ssl->cipher_list);
      }
      if ((_STACK *)ssl->cipher_list_by_id != (_STACK *)0x0) {
        sk_free((_STACK *)ssl->cipher_list_by_id);
      }
      if (ssl->session != (SSL_SESSION *)0x0) {
        ssl_clear_bad_session(ssl);
        SSL_SESSION_free(ssl->session);
      }
      if (ssl->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
        EVP_CIPHER_CTX_cleanup(ssl->enc_read_ctx);
        CRYPTO_free(ssl->enc_read_ctx);
        ssl->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
      }
      if (ssl->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
        EVP_CIPHER_CTX_cleanup(ssl->enc_write_ctx);
        CRYPTO_free(ssl->enc_write_ctx);
        ssl->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
      }
      if (ssl->expand != (COMP_CTX *)0x0) {
        COMP_CTX_free(ssl->expand);
        ssl->expand = (COMP_CTX *)0x0;
      }
      if (ssl->compress != (COMP_CTX *)0x0) {
        COMP_CTX_free(ssl->compress);
        ssl->compress = (COMP_CTX *)0x0;
      }
      if (ssl->read_hash != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(ssl->read_hash);
      }
      ssl->read_hash = (EVP_MD_CTX *)0x0;
      if (ssl->write_hash != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(ssl->write_hash);
      }
      ssl->write_hash = (EVP_MD_CTX *)0x0;
      if (ssl->cert != (cert_st *)0x0) {
        ssl_cert_free();
      }
      if (ssl->tlsext_debug_arg != (void *)0x0) {
        CRYPTO_free(ssl->tlsext_debug_arg);
      }
      if ((SSL_CTX *)ssl->tls_session_secret_cb_arg != (SSL_CTX *)0x0) {
        SSL_CTX_free((SSL_CTX *)ssl->tls_session_secret_cb_arg);
      }
      if ((void *)ssl->tlsext_ecpointformatlist_length != (void *)0x0) {
        CRYPTO_free((void *)ssl->tlsext_ecpointformatlist_length);
      }
      if ((void *)ssl->tlsext_ellipticcurvelist_length != (void *)0x0) {
        CRYPTO_free((void *)ssl->tlsext_ellipticcurvelist_length);
      }
      if (ssl->tlsext_ellipticcurvelist != (uchar *)0x0) {
        CRYPTO_free(ssl->tlsext_ellipticcurvelist);
      }
      if ((_STACK *)ssl->tlsext_ocsp_ids != (_STACK *)0x0) {
        sk_pop_free((_STACK *)ssl->tlsext_ocsp_ids,X509_EXTENSION_free + 1);
      }
      if ((_STACK *)ssl->tlsext_status_expected != (_STACK *)0x0) {
        sk_pop_free((_STACK *)ssl->tlsext_status_expected,OCSP_RESPID_free + 1);
      }
      if (ssl->tlsext_ocsp_exts != (X509_EXTENSIONS *)0x0) {
        CRYPTO_free(ssl->tlsext_ocsp_exts);
      }
      st = (_STACK *)(ssl->ex_data).dummy;
      if (st != (_STACK *)0x0) {
        sk_pop_free(st,X509_NAME_free + 1);
      }
      if (ssl->method != (SSL_METHOD *)0x0) {
        (*ssl->method->ssl_free)(ssl);
      }
      if ((SSL_CTX *)ssl->psk_server_callback != (SSL_CTX *)0x0) {
        SSL_CTX_free((SSL_CTX *)ssl->psk_server_callback);
      }
      if (ssl->initial_ctx != (SSL_CTX *)0x0) {
        CRYPTO_free(ssl->initial_ctx);
      }
      if (*(_STACK **)&ssl->next_proto_negotiated_len != (_STACK *)0x0) {
        sk_free(*(_STACK **)&ssl->next_proto_negotiated_len);
      }
      CRYPTO_free(ssl);
      return;
    }
  }
  return;
}

