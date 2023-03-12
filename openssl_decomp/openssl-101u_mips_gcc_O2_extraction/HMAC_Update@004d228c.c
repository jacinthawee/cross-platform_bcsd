
int HMAC_Update(HMAC_CTX *ctx,uchar *data,size_t len)

{
  int iVar1;
  
  if (ctx->md != (EVP_MD *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004d22a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(&ctx->md_ctx);
    return iVar1;
  }
  return 0;
}

