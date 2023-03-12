
long SSL_CTX_set_timeout(SSL_CTX *ctx,long t)

{
  SSL_CTX *pSVar1;
  
  pSVar1 = ctx;
  if (ctx != (SSL_CTX *)0x0) {
    pSVar1 = (SSL_CTX *)ctx->session_timeout;
    ctx->session_timeout = t;
  }
  return (long)pSVar1;
}

