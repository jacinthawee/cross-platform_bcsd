
void SSL_free(SSL *ssl)

{
  int iVar1;
  BIO *pBVar2;
  BIO *pBVar3;
  void *pvVar4;
  _func_3154 *p_Var5;
  
  if ((ssl != (SSL *)0x0) &&
     (iVar1 = CRYPTO_add_lock((int *)&ssl->client_CA,-1,0x10,"ssl_lib.c",0x200), iVar1 < 1)) {
    if (ssl->param != (X509_VERIFY_PARAM *)0x0) {
      (*(code *)PTR_X509_VERIFY_PARAM_free_006a83cc)();
    }
    CRYPTO_free_ex_data(1,ssl,(CRYPTO_EX_DATA *)&ssl->verify_result);
    pBVar3 = ssl->bbio;
    if (pBVar3 != (BIO *)0x0) {
      if (pBVar3 == ssl->wbio) {
        pBVar2 = (BIO *)(*(code *)PTR_BIO_pop_006a8ab4)();
        pBVar3 = ssl->bbio;
        ssl->wbio = pBVar2;
      }
      (*(code *)PTR_BIO_free_006a7f70)(pBVar3);
      ssl->bbio = (BIO *)0x0;
    }
    if (ssl->rbio != (BIO *)0x0) {
      (*(code *)PTR_BIO_free_all_006a7f74)();
    }
    if ((ssl->wbio != (BIO *)0x0) && (ssl->wbio != ssl->rbio)) {
      (*(code *)PTR_BIO_free_all_006a7f74)();
    }
    if (ssl->init_buf != (BUF_MEM *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    if (ssl->cipher_list != (stack_st_SSL_CIPHER *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)();
    }
    if (ssl->cipher_list_by_id != (stack_st_SSL_CIPHER *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)();
    }
    if (ssl->session != (SSL_SESSION *)0x0) {
      ssl_clear_bad_session(ssl);
      SSL_SESSION_free(ssl->session);
    }
    if (ssl->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
      CRYPTO_free(ssl->enc_read_ctx);
      ssl->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (ssl->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
      CRYPTO_free(ssl->enc_write_ctx);
      ssl->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (ssl->expand != (COMP_CTX *)0x0) {
      (*(code *)PTR_COMP_CTX_free_006a9210)();
      ssl->expand = (COMP_CTX *)0x0;
    }
    if (ssl->compress != (COMP_CTX *)0x0) {
      (*(code *)PTR_COMP_CTX_free_006a9210)();
      ssl->compress = (COMP_CTX *)0x0;
    }
    if (ssl->read_hash != (EVP_MD_CTX *)0x0) {
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)();
    }
    ssl->read_hash = (EVP_MD_CTX *)0x0;
    if (ssl->write_hash != (EVP_MD_CTX *)0x0) {
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)();
    }
    ssl->write_hash = (EVP_MD_CTX *)0x0;
    if (ssl->cert != (cert_st *)0x0) {
      ssl_cert_free();
    }
    if (ssl->tlsext_debug_arg != (void *)0x0) {
      CRYPTO_free(ssl->tlsext_debug_arg);
    }
    pvVar4 = ssl->tls_session_secret_cb_arg;
    if ((pvVar4 != (void *)0x0) &&
       (iVar1 = CRYPTO_add_lock((int *)((int)pvVar4 + 0x60),-1,0xc,"ssl_lib.c",0x773), iVar1 < 1)) {
      SSL_CTX_free_part_6(pvVar4);
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
    if (ssl->tlsext_ocsp_ids != (stack_st_OCSP_RESPID *)0x0) {
      (*(code *)PTR_sk_pop_free_006a8158)(ssl->tlsext_ocsp_ids,PTR_X509_EXTENSION_free_006a8268);
    }
    if (ssl->tlsext_status_expected != 0) {
      (*(code *)PTR_sk_pop_free_006a8158)(ssl->tlsext_status_expected,PTR_OCSP_RESPID_free_006a9314)
      ;
    }
    if (ssl->tlsext_ocsp_exts != (X509_EXTENSIONS *)0x0) {
      CRYPTO_free(ssl->tlsext_ocsp_exts);
    }
    iVar1 = (ssl->ex_data).dummy;
    if (iVar1 != 0) {
      (*(code *)PTR_sk_pop_free_006a8158)(iVar1,PTR_X509_NAME_free_006a80f8);
    }
    if (ssl->method != (SSL_METHOD *)0x0) {
      (*ssl->method->ssl_free)(ssl);
    }
    p_Var5 = ssl->psk_server_callback;
    if ((p_Var5 != (_func_3154 *)0x0) &&
       (iVar1 = CRYPTO_add_lock((int *)(p_Var5 + 0x60),-1,0xc,"ssl_lib.c",0x773), iVar1 < 1)) {
      SSL_CTX_free_part_6(p_Var5);
    }
    if (ssl->initial_ctx != (SSL_CTX *)0x0) {
      CRYPTO_free(ssl->initial_ctx);
    }
    if (*(int *)&ssl->next_proto_negotiated_len != 0) {
      (*(code *)PTR_sk_free_006a7f80)();
    }
    CRYPTO_free(ssl);
    return;
  }
  return;
}

