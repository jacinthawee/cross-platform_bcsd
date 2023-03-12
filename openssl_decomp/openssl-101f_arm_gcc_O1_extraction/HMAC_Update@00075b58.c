
int HMAC_Update(HMAC_CTX *ctx,uchar *data,size_t len)

{
  int iVar1;
  
  iVar1 = EVP_DigestUpdate(&ctx->md_ctx,data,len);
  return iVar1;
}

