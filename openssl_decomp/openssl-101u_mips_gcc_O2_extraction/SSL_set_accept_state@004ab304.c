
void SSL_set_accept_state(SSL *s)

{
  _func_3056 *p_Var1;
  
  p_Var1 = s->method->ssl_accept;
  s->shutdown = 0;
  s->server = 1;
  s->handshake_func = (_func_3149 *)p_Var1;
  s->state = 0x6000;
  if (s->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)();
    CRYPTO_free(s->enc_read_ctx);
    s->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (s->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)();
    CRYPTO_free(s->enc_write_ctx);
    s->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (s->expand != (COMP_CTX *)0x0) {
    (*(code *)PTR_COMP_CTX_free_006a80e0)();
    s->expand = (COMP_CTX *)0x0;
  }
  if (s->compress != (COMP_CTX *)0x0) {
    (*(code *)PTR_COMP_CTX_free_006a80e0)();
    s->compress = (COMP_CTX *)0x0;
  }
  if (s->read_hash != (EVP_MD_CTX *)0x0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  s->read_hash = (EVP_MD_CTX *)0x0;
  if (s->write_hash != (EVP_MD_CTX *)0x0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  s->write_hash = (EVP_MD_CTX *)0x0;
  return;
}

