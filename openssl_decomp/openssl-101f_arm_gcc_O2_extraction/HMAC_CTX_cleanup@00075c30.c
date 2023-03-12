
void HMAC_CTX_cleanup(HMAC_CTX *ctx)

{
  EVP_MD_CTX_cleanup(&ctx->i_ctx);
  EVP_MD_CTX_cleanup(&ctx->o_ctx);
  EVP_MD_CTX_cleanup(&ctx->md_ctx);
  (*(code *)PTR_memset_0018a15c)(ctx,0,0xd0);
  return;
}

