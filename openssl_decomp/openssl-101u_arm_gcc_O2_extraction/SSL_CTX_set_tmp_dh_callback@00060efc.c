
void SSL_CTX_set_tmp_dh_callback(SSL_CTX *ctx,dh *dh)

{
                    /* WARNING: Could not recover jumptable at 0x00060f04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*ctx->method->ssl_ctx_callback_ctrl)(ctx,6,(fp *)dh);
  return;
}

