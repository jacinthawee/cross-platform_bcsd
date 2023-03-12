
void EVP_EncodeInit(EVP_ENCODE_CTX *ctx)

{
  ctx->num = 0;
  ctx->line_num = 0;
  ctx->length = 0x30;
  return;
}

