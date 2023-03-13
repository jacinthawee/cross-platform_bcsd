
EVP_MD * EVP_MD_CTX_md(EVP_MD_CTX *ctx)

{
  if (ctx != (EVP_MD_CTX *)0x0) {
    return ctx->digest;
  }
  return (EVP_MD *)0x0;
}

