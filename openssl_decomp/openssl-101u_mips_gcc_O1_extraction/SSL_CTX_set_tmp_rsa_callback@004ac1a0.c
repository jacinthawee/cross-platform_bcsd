
void SSL_CTX_set_tmp_rsa_callback(SSL_CTX *ctx,cb *cb)

{
                    /* WARNING: Could not recover jumptable at 0x004ac1ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*ctx->method->ssl_ctx_callback_ctrl)(ctx,5,(fp *)cb);
  return;
}

