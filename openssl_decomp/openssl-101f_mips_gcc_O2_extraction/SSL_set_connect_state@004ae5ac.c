
void SSL_set_connect_state(SSL *s)

{
  _func_3057 *p_Var1;
  
  s->server = 0;
  p_Var1 = s->method->ssl_connect;
  s->shutdown = 0;
  s->state = 0x5000;
  s->handshake_func = (_func_3149 *)p_Var1;
  if (s->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
    CRYPTO_free(s->enc_read_ctx);
    s->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (s->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
    CRYPTO_free(s->enc_write_ctx);
    s->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (s->expand != (COMP_CTX *)0x0) {
    (*(code *)PTR_COMP_CTX_free_006a9210)();
    s->expand = (COMP_CTX *)0x0;
  }
  if (s->compress != (COMP_CTX *)0x0) {
    (*(code *)PTR_COMP_CTX_free_006a9210)();
    s->compress = (COMP_CTX *)0x0;
  }
  if (s->read_hash != (EVP_MD_CTX *)0x0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)();
  }
  s->read_hash = (EVP_MD_CTX *)0x0;
  if (s->write_hash != (EVP_MD_CTX *)0x0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)();
  }
  s->write_hash = (EVP_MD_CTX *)0x0;
  return;
}

