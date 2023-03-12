
void SSL_CTX_set_cert_verify_callback(SSL_CTX *ctx,cb *cb,void *arg)

{
  ctx->app_verify_callback = (_func_3090 *)cb;
  ctx->app_verify_arg = arg;
  return;
}

