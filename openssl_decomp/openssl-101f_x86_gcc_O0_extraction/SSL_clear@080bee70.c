
int SSL_clear(SSL *s)

{
  int iVar1;
  SSL_METHOD *pSVar2;
  int line;
  
  if (s->method == (SSL_METHOD *)0x0) {
    line = 0xbe;
    iVar1 = 0xbc;
  }
  else {
    iVar1 = ssl_clear_bad_session(s);
    if (iVar1 != 0) {
      SSL_SESSION_free(s->session);
      s->session = (SSL_SESSION *)0x0;
    }
    s->error = 0;
    s->hit = 0;
    s->shutdown = 0;
    if (s->tlsext_hb_seq == 0) {
      s->type = 0;
      s->state = (-(uint)(s->server == 0) & 0xfffff000) + 0x6000;
      iVar1 = s->method->version;
      s->rwstate = 1;
      s->rstate = 0xf0;
      s->version = iVar1;
      s->first_packet = iVar1;
      if (s->init_buf != (BUF_MEM *)0x0) {
        BUF_MEM_free(s->init_buf);
        s->init_buf = (BUF_MEM *)0x0;
      }
      if (s->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
        EVP_CIPHER_CTX_cleanup(s->enc_read_ctx);
        CRYPTO_free(s->enc_read_ctx);
        s->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
      }
      if (s->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
        EVP_CIPHER_CTX_cleanup(s->enc_write_ctx);
        CRYPTO_free(s->enc_write_ctx);
        s->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
      }
      if (s->expand != (COMP_CTX *)0x0) {
        COMP_CTX_free(s->expand);
        s->expand = (COMP_CTX *)0x0;
      }
      if (s->compress != (COMP_CTX *)0x0) {
        COMP_CTX_free(s->compress);
        s->compress = (COMP_CTX *)0x0;
      }
      if (s->read_hash != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(s->read_hash);
      }
      s->read_hash = (EVP_MD_CTX *)0x0;
      if (s->write_hash != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(s->write_hash);
      }
      s->write_hash = (EVP_MD_CTX *)0x0;
      s->max_cert_list = 0;
      if ((s->in_handshake == 0) && (s->session == (SSL_SESSION *)0x0)) {
        pSVar2 = *(SSL_METHOD **)s->psk_server_callback;
        if (s->method != pSVar2) {
          (*s->method->ssl_free)(s);
          pSVar2 = *(SSL_METHOD **)s->psk_server_callback;
          s->method = pSVar2;
          iVar1 = (*pSVar2->ssl_new)(s);
          return (uint)(iVar1 != 0);
        }
      }
      else {
        pSVar2 = s->method;
      }
      (*pSVar2->ssl_clear)(s);
      return 1;
    }
    line = 0xd4;
    iVar1 = 0x44;
  }
  ERR_put_error(0x14,0xa4,iVar1,"ssl_lib.c",line);
  return 0;
}

