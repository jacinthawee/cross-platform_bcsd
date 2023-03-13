
int SSL_accept(SSL *ssl)

{
  int iVar1;
  _func_3056 *p_Var2;
  
  if (ssl->handshake_func != (_func_3149 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004a7d98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*ssl->method->ssl_accept)(ssl);
    return iVar1;
  }
  ssl->shutdown = 0;
  ssl->server = 1;
  p_Var2 = ssl->method->ssl_accept;
  ssl->state = 0x6000;
  ssl->handshake_func = (_func_3149 *)p_Var2;
  if (ssl->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)();
    CRYPTO_free(ssl->enc_read_ctx);
    ssl->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (ssl->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)();
    CRYPTO_free(ssl->enc_write_ctx);
    ssl->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (ssl->expand != (COMP_CTX *)0x0) {
    (*(code *)PTR_COMP_CTX_free_006a80e0)();
    ssl->expand = (COMP_CTX *)0x0;
  }
  if (ssl->compress != (COMP_CTX *)0x0) {
    (*(code *)PTR_COMP_CTX_free_006a80e0)();
    ssl->compress = (COMP_CTX *)0x0;
  }
  if (ssl->read_hash != (EVP_MD_CTX *)0x0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  ssl->read_hash = (EVP_MD_CTX *)0x0;
  if (ssl->write_hash != (EVP_MD_CTX *)0x0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  ssl->write_hash = (EVP_MD_CTX *)0x0;
                    /* WARNING: Could not recover jumptable at 0x004a7e9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*ssl->method->ssl_accept)(ssl);
  return iVar1;
}

