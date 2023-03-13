
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  EVP_CIPHER *pEVar1;
  size_t __n;
  int iVar2;
  size_t sVar3;
  uint __n_00;
  
  pEVar1 = ctx->cipher;
  if ((*(byte *)((int)&pEVar1->flags + 2) & 0x10) != 0) {
    iVar2 = (*pEVar1->do_cipher)(ctx,out,in,inl);
    if (iVar2 < 0) {
      return 0;
    }
    *outl = iVar2;
    return 1;
  }
  if (0 < inl) {
    iVar2 = ctx->buf_len;
    if (iVar2 == 0) {
      if ((ctx->block_mask & inl) == 0) {
        iVar2 = (*pEVar1->do_cipher)(ctx,out,in,inl);
        if (iVar2 != 0) {
          *outl = inl;
          return 1;
        }
        *outl = 0;
        return 0;
      }
      sVar3 = pEVar1->block_size;
      if (0x20 < (int)sVar3) {
        OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
      }
      *outl = 0;
    }
    else {
      sVar3 = pEVar1->block_size;
      if (0x20 < (int)sVar3) {
        OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
      }
      __n = sVar3 - iVar2;
      if (inl < (int)__n) {
        memcpy(ctx->buf + iVar2,in,inl);
        ctx->buf_len = ctx->buf_len + inl;
        *outl = 0;
        return 1;
      }
      memcpy(ctx->buf + iVar2,in,__n);
      iVar2 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar3);
      if (iVar2 == 0) {
        return 0;
      }
      in = in + __n;
      out = out + sVar3;
      inl = inl - __n;
      *outl = sVar3;
    }
    __n_00 = sVar3 - 1 & inl;
    sVar3 = inl - __n_00;
    if (0 < (int)sVar3) {
      iVar2 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar3);
      if (iVar2 == 0) {
        return 0;
      }
      *outl = *outl + sVar3;
    }
    if (__n_00 != 0) {
      memcpy(ctx->buf,in + sVar3,__n_00);
    }
    ctx->buf_len = __n_00;
    return 1;
  }
  *outl = 0;
  return (uint)(inl == 0);
}

