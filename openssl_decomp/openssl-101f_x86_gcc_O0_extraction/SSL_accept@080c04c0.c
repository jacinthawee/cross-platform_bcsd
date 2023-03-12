
int SSL_accept(SSL *ssl)

{
  int iVar1;
  
  if (ssl->handshake_func != (_func_3149 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x080c04dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*ssl->method->ssl_accept)(ssl);
    return iVar1;
  }
  ssl->server = 1;
  ssl->shutdown = 0;
  ssl->state = 0x6000;
  ssl->handshake_func = (_func_3149 *)ssl->method->ssl_accept;
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
                    /* WARNING: Could not recover jumptable at 0x080c05e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*ssl->method->ssl_accept)(ssl);
  return iVar1;
}

