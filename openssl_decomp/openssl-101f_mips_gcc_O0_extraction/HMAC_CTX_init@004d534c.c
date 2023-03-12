
void HMAC_CTX_init(HMAC_CTX *ctx)

{
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(&ctx->i_ctx);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(&ctx->o_ctx);
                    /* WARNING: Could not recover jumptable at 0x004d5398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(&ctx->md_ctx);
  return;
}

