
void HMAC_CTX_init(HMAC_CTX *ctx)

{
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&ctx->i_ctx);
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&ctx->o_ctx);
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&ctx->md_ctx);
  ctx->md = (EVP_MD *)0x0;
  return;
}

