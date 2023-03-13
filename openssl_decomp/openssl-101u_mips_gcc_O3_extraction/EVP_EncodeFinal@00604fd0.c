
void EVP_EncodeFinal(EVP_ENCODE_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  
  if (ctx->num == 0) {
    *outl = 0;
    return;
  }
  iVar1 = EVP_EncodeBlock(out,ctx->enc_data,ctx->num);
  out[iVar1] = '\n';
  out[iVar1 + 1] = '\0';
  ctx->num = 0;
  *outl = iVar1 + 1;
  return;
}

