
int EVP_DecodeFinal(EVP_ENCODE_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  int iVar2;
  
  *outl = 0;
  if (ctx->num == 0) {
    return 1;
  }
  iVar1 = EVP_DecodeBlock(out,ctx->enc_data,ctx->num);
  if (iVar1 < 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = 1;
    ctx->num = 0;
    *outl = iVar1;
  }
  return iVar2;
}

