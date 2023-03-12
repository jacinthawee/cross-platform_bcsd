
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  uint __n;
  bool bVar1;
  EVP_CIPHER *pEVar2;
  size_t sVar3;
  int iVar4;
  uchar *out_00;
  uint __n_00;
  size_t local_28;
  
  pEVar2 = ctx->cipher;
  if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) != 0) {
    iVar4 = (*pEVar2->do_cipher)(ctx,out,in,inl);
    if (-1 < iVar4) {
      *outl = iVar4;
      return 1;
    }
    *outl = 0;
    return 0;
  }
  if (inl < 1) {
    *outl = 0;
    return (uint)(inl == 0);
  }
  if ((*(byte *)((int)&ctx->flags + 1) & 1) != 0) {
    iVar4 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
    return iVar4;
  }
  __n = pEVar2->block_size;
  if (__n < 0x21) {
    if (ctx->final_used != 0) {
LAB_0812aeb9:
      memcpy(out,ctx->final,__n);
      out = out + __n;
      bVar1 = true;
      goto LAB_0812aee1;
    }
    bVar1 = false;
  }
  else {
    OpenSSLDie("evp_enc.c",0x1ce,"b <= sizeof ctx->final");
    bVar1 = false;
    if (ctx->final_used != 0) goto LAB_0812aeb9;
LAB_0812aee1:
    pEVar2 = ctx->cipher;
    if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) != 0) {
      iVar4 = (*pEVar2->do_cipher)(ctx,out,in,inl);
      if (iVar4 < 0) {
        return 0;
      }
      *outl = iVar4;
      goto LAB_0812af01;
    }
  }
  iVar4 = ctx->buf_len;
  if (iVar4 == 0) {
    if ((ctx->block_mask & inl) == 0) {
      iVar4 = (*pEVar2->do_cipher)(ctx,out,in,inl);
      if (iVar4 == 0) {
        *outl = 0;
        return 0;
      }
      *outl = inl;
      goto LAB_0812af01;
    }
    local_28 = pEVar2->block_size;
    if (0x20 < (int)local_28) {
      OpenSSLDie("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
    }
    *outl = 0;
    out_00 = out;
  }
  else {
    local_28 = pEVar2->block_size;
    if (0x20 < (int)local_28) {
      OpenSSLDie("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
    }
    if (inl + iVar4 < (int)local_28) {
      memcpy(ctx->buf + iVar4,in,inl);
      ctx->buf_len = ctx->buf_len + inl;
      *outl = 0;
      goto LAB_0812af01;
    }
    sVar3 = local_28 - iVar4;
    memcpy(ctx->buf + iVar4,in,sVar3);
    iVar4 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,local_28);
    if (iVar4 == 0) {
      return 0;
    }
    inl = inl - sVar3;
    in = in + sVar3;
    *outl = local_28;
    out_00 = out + local_28;
  }
  __n_00 = local_28 - 1 & inl;
  sVar3 = inl - __n_00;
  if (0 < (int)sVar3) {
    iVar4 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar3);
    if (iVar4 == 0) {
      return 0;
    }
    *outl = *outl + sVar3;
  }
  if (__n_00 != 0) {
    memcpy(ctx->buf,in + sVar3,__n_00);
  }
  ctx->buf_len = __n_00;
LAB_0812af01:
  if ((__n < 2) || (ctx->buf_len != 0)) {
    ctx->final_used = 0;
  }
  else {
    *outl = *outl - __n;
    ctx->final_used = 1;
    memcpy(ctx->final,out + *outl,__n);
  }
  if (!bVar1) {
    return 1;
  }
  *outl = *outl + __n;
  return 1;
}

