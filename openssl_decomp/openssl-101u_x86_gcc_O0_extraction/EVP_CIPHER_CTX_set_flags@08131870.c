
void EVP_CIPHER_CTX_set_flags(EVP_CIPHER_CTX *ctx,int flags)

{
  ctx->flags = ctx->flags | flags;
  return;
}

