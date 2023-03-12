
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  uchar *puVar1;
  int iVar2;
  size_t __n;
  int iVar3;
  int local_20;
  
  *outl = 0;
  if (inl == 0) {
    return;
  }
  iVar2 = ctx->length;
  if (iVar2 < 0x51) {
    iVar3 = ctx->num;
    if (inl + iVar3 < iVar2) {
LAB_081c984a:
      memcpy(ctx->enc_data + iVar3,in,inl);
      ctx->num = ctx->num + inl;
      return;
    }
  }
  else {
    OpenSSLDie("encode.c",0x8b,"ctx->length <= (int)sizeof(ctx->enc_data)");
    iVar3 = ctx->num;
    iVar2 = ctx->length;
    if (inl + iVar3 < iVar2) goto LAB_081c984a;
  }
  if (iVar3 == 0) {
    local_20 = 0;
    if (iVar2 <= inl) {
LAB_081c97c8:
      do {
        iVar2 = EVP_EncodeBlock(out,in,iVar2);
        in = in + ctx->length;
        inl = inl - ctx->length;
        puVar1 = out + iVar2;
        local_20 = local_20 + iVar2 + 1;
        out = out + iVar2 + 1;
        *puVar1 = '\n';
        puVar1[1] = '\0';
        iVar2 = ctx->length;
      } while (iVar2 <= inl);
      goto LAB_081c9801;
    }
  }
  else {
    __n = iVar2 - iVar3;
    memcpy(ctx->enc_data + iVar3,in,__n);
    in = in + __n;
    inl = inl - __n;
    local_20 = EVP_EncodeBlock(out,ctx->enc_data,ctx->length);
    puVar1 = out + local_20;
    local_20 = local_20 + 1;
    ctx->num = 0;
    out = out + local_20;
    *puVar1 = '\n';
    puVar1[1] = '\0';
    iVar2 = ctx->length;
    if (iVar2 <= inl) goto LAB_081c97c8;
LAB_081c9801:
    iVar3 = local_20;
    if (inl == 0) goto LAB_081c9809;
  }
  local_20 = iVar3;
  memcpy(ctx->enc_data,in,inl);
LAB_081c9809:
  ctx->num = inl;
  *outl = local_20;
  return;
}

