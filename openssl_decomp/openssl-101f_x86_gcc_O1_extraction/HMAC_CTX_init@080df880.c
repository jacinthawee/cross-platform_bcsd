
void HMAC_CTX_init(HMAC_CTX *ctx)

{
  EVP_MD_CTX_init(&ctx->i_ctx);
  EVP_MD_CTX_init(&ctx->o_ctx);
  EVP_MD_CTX_init(&ctx->md_ctx);
  return;
}

