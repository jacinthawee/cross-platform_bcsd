
void X509_STORE_CTX_trusted_stack(X509_STORE_CTX *ctx,stack_st_X509 *sk)

{
  ctx->get_issuer = get_issuer_sk;
  ctx->other_ctx = sk;
  return;
}

