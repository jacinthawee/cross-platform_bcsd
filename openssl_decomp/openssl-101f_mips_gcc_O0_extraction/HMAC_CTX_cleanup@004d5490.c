
void HMAC_CTX_cleanup(HMAC_CTX *ctx)

{
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(&ctx->i_ctx);
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(&ctx->o_ctx);
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(&ctx->md_ctx);
                    /* WARNING: Could not recover jumptable at 0x004d54f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_memset_006aab00)(ctx,0,0xd0);
  return;
}
