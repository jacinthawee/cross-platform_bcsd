
long SSL_CTX_get_timeout(SSL_CTX *ctx)

{
  if (ctx != (SSL_CTX *)0x0) {
    return ctx->session_timeout;
  }
  return 0;
}

