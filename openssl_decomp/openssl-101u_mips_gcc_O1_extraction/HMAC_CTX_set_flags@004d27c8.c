
void HMAC_CTX_set_flags(HMAC_CTX *ctx,ulong flags)

{
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(&ctx->i_ctx);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(&ctx->o_ctx,flags);
                    /* WARNING: Could not recover jumptable at 0x004d2828. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(&ctx->md_ctx,flags);
  return;
}

