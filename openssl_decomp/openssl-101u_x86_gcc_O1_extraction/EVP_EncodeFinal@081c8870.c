
void EVP_EncodeFinal(EVP_ENCODE_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  
  iVar1 = ctx->num;
  if (iVar1 != 0) {
    iVar1 = EVP_EncodeBlock(out,ctx->enc_data,iVar1);
    out[iVar1] = '\n';
    out[iVar1 + 1] = '\0';
    ctx->num = 0;
    iVar1 = iVar1 + 1;
  }
  *outl = iVar1;
  return;
}

