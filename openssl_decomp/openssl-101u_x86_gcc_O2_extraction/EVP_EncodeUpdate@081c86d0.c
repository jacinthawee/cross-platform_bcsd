
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  uchar *puVar1;
  int iVar2;
  int n;
  uchar *__src;
  size_t __n;
  int iVar3;
  
  *outl = 0;
  if (inl < 1) {
    return;
  }
  n = ctx->length;
  if (n < 0x51) {
    iVar3 = ctx->num;
    __n = n - iVar3;
  }
  else {
    OpenSSLDie("encode.c",0xa0,"ctx->length <= (int)sizeof(ctx->enc_data)");
    n = ctx->length;
    iVar3 = ctx->num;
    __n = n - iVar3;
  }
  if (inl < (int)__n) {
    memcpy(ctx->enc_data + iVar3,in,inl);
    ctx->num = ctx->num + inl;
    return;
  }
  if (iVar3 == 0) {
    iVar3 = 0;
    __src = in;
    if (n <= inl) {
      do {
        iVar2 = EVP_EncodeBlock(out,in,n);
        __src = in + ctx->length;
        inl = inl - ctx->length;
        out[iVar2] = '\n';
        (out + iVar2)[1] = '\0';
        out = out + iVar2 + 1;
        n = ctx->length;
        iVar3 = iVar3 + iVar2 + 1;
        if (inl < n) goto LAB_081c87d0;
LAB_081c8755:
        in = __src;
      } while (-1 < iVar3);
LAB_081c8759:
      *outl = 0;
      return;
    }
  }
  else {
    inl = inl - __n;
    __src = in + __n;
    memcpy(ctx->enc_data + iVar3,in,__n);
    iVar3 = EVP_EncodeBlock(out,ctx->enc_data,ctx->length);
    puVar1 = out + iVar3;
    iVar3 = iVar3 + 1;
    out = out + iVar3;
    ctx->num = 0;
    *puVar1 = '\n';
    puVar1[1] = '\0';
    n = ctx->length;
    if (n <= inl) goto LAB_081c8755;
LAB_081c87d0:
    if (iVar3 < 0) goto LAB_081c8759;
    if (inl == 0) goto LAB_081c87d8;
  }
  memcpy(ctx->enc_data,__src,inl);
LAB_081c87d8:
  ctx->num = inl;
  *outl = iVar3;
  return;
}

