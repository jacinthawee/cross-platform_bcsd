
void SSL_CTX_set_info_callback(SSL_CTX *ctx,cb *cb)

{
  ctx->info_callback = (_func_3094 *)cb;
  return;
}

