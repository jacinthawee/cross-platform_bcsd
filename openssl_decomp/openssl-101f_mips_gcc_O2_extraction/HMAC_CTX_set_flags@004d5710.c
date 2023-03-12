
void HMAC_CTX_set_flags(HMAC_CTX *ctx,ulong flags)

{
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(&ctx->i_ctx);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(&ctx->o_ctx,flags);
                    /* WARNING: Could not recover jumptable at 0x004d5770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(&ctx->md_ctx,flags);
  return;
}

