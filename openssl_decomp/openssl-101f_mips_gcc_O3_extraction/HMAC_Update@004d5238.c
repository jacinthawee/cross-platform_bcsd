
int HMAC_Update(HMAC_CTX *ctx,uchar *data,size_t len)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004d5244. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(&ctx->md_ctx);
  return iVar1;
}

