
void SSL_CTX_set_tmp_ecdh_callback(SSL_CTX *ctx,ecdh *ecdh)

{
                    /* WARNING: Could not recover jumptable at 0x004af23c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*ctx->method->ssl_ctx_callback_ctrl)(ctx,7,(fp *)ecdh);
  return;
}
