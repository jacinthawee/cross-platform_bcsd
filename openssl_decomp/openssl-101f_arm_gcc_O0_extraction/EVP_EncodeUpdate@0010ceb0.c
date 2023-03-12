
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  size_t __n;
  
  *outl = 0;
  if (inl != 0) {
    iVar1 = ctx->length;
    if (iVar1 < 0x51) {
      iVar2 = ctx->num;
      if (iVar2 + inl < iVar1) {
LAB_0010cf46:
        memcpy(ctx->enc_data + iVar2,in,inl);
        ctx->num = ctx->num + inl;
        return;
      }
    }
    else {
      OpenSSLDie("encode.c",0x8b,"ctx->length <= (int)sizeof(ctx->enc_data)");
      iVar2 = ctx->num;
      iVar1 = ctx->length;
      if (iVar2 + inl < iVar1) goto LAB_0010cf46;
    }
    if (iVar2 != 0) {
      __n = iVar1 - iVar2;
      inl = inl - __n;
      memcpy(ctx->enc_data + iVar2,in,__n);
      iVar2 = EVP_EncodeBlock(out,ctx->enc_data,ctx->length);
      in = in + __n;
      ctx->num = 0;
      puVar3 = out + iVar2;
      iVar2 = iVar2 + 1;
      out = puVar3 + 1;
      puVar3[1] = '\0';
      *puVar3 = '\n';
      iVar1 = ctx->length;
    }
    if (iVar1 <= inl) {
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
      } while (iVar1 <= inl);
    }
    if (inl != 0) {
      memcpy(ctx->enc_data,in,inl);
    }
    ctx->num = inl;
    *outl = iVar2;
  }
  return;
}

