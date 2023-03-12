
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  int iVar2;
  size_t __n;
  uchar *puVar3;
  
  *outl = 0;
  if (inl < 1) {
    return;
  }
  iVar1 = ctx->length;
  if (iVar1 < 0x51) {
    iVar2 = ctx->num;
    __n = iVar1 - iVar2;
  }
  else {
    OpenSSLDie("encode.c",0xa0,"ctx->length <= (int)sizeof(ctx->enc_data)");
    iVar1 = ctx->length;
    iVar2 = ctx->num;
    __n = iVar1 - iVar2;
  }
  if (inl < (int)__n) {
    memcpy(ctx->enc_data + iVar2,in,inl);
    ctx->num = ctx->num + inl;
    return;
  }
  if (iVar2 == 0) {
    if (inl < iVar1) {
LAB_0010b29c:
      if (inl != 0) {
        memcpy(ctx->enc_data,in,inl);
      }
      ctx->num = inl;
      *outl = iVar2;
      return;
    }
  }
  else {
    memcpy(ctx->enc_data + iVar2,in,__n);
    iVar2 = EVP_EncodeBlock(out,ctx->enc_data,ctx->length);
    ctx->num = 0;
    inl = inl - __n;
    in = in + __n;
    puVar3 = out + iVar2;
    iVar2 = iVar2 + 1;
    out = puVar3 + 1;
    *out = '\0';
    *puVar3 = '\n';
    iVar1 = ctx->length;
    if (inl < iVar1) {
LAB_0010b296:
      if (-1 < iVar2) goto LAB_0010b29c;
      goto LAB_0010b2fc;
    }
    if (iVar2 < 0) goto LAB_0010b2fc;
  }
  do {
    iVar1 = EVP_EncodeBlock(out,in,iVar1);
    inl = inl - ctx->length;
    in = in + ctx->length;
    puVar3 = out + iVar1;
    out = puVar3 + 1;
    iVar2 = iVar2 + iVar1 + 1;
    *puVar3 = '\n';
    puVar3[1] = '\0';
    iVar1 = ctx->length;
    if (inl < iVar1) goto LAB_0010b296;
  } while (-1 < iVar2);
LAB_0010b2fc:
  *outl = 0;
  return;
}

