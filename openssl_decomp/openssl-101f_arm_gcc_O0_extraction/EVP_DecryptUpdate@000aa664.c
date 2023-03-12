
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  uchar *out_00;
  size_t __n;
  int iVar1;
  int iVar2;
  size_t sVar3;
  uint __n_00;
  uchar *out_01;
  uint __n_01;
  EVP_CIPHER *pEVar4;
  
  pEVar4 = ctx->cipher;
  if ((pEVar4->flags & 0x100000) != 0) {
    iVar1 = (*pEVar4->do_cipher)(ctx,out,in,inl);
    if (iVar1 < 0) {
      *outl = 0;
      return 0;
    }
    *outl = iVar1;
    return 1;
  }
  if (inl < 1) {
    *outl = 0;
    return (uint)(inl == 0);
  }
  if ((int)(ctx->flags << 0x17) < 0) {
    iVar1 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
    return iVar1;
  }
  __n_01 = pEVar4->block_size;
  if (0x20 < __n_01) {
    OpenSSLDie("evp_enc.c",0x1ce,"b <= sizeof ctx->final");
  }
  iVar1 = ctx->final_used;
  out_01 = out;
  if (iVar1 != 0) {
    out_01 = out + __n_01;
    memcpy(out,ctx->final,__n_01);
    iVar1 = 1;
  }
  pEVar4 = ctx->cipher;
  if ((int)(pEVar4->flags << 0xb) < 0) {
    iVar2 = (*pEVar4->do_cipher)(ctx,out_01,in,inl);
    if (iVar2 < 0) {
      return 0;
    }
    *outl = iVar2;
    goto LAB_000aa7a2;
  }
  iVar2 = ctx->buf_len;
  if ((iVar2 == 0) && ((inl & ctx->block_mask) == 0)) {
    iVar2 = (*pEVar4->do_cipher)(ctx,out_01,in,inl);
    if (iVar2 == 0) {
      *outl = 0;
      return 0;
    }
    *outl = inl;
    goto LAB_000aa7a2;
  }
  sVar3 = pEVar4->block_size;
  if ((int)sVar3 < 0x21) {
    if (iVar2 == 0) goto LAB_000aa6c0;
LAB_000aa71a:
    if (inl + iVar2 < (int)sVar3) {
      memcpy(ctx->buf + iVar2,in,inl);
      ctx->buf_len = ctx->buf_len + inl;
      *outl = 0;
      goto LAB_000aa7a2;
    }
    __n = sVar3 - iVar2;
    memcpy(ctx->buf + iVar2,in,__n);
    iVar2 = (*ctx->cipher->do_cipher)(ctx,out_01,ctx->buf,sVar3);
    if (iVar2 == 0) {
      return 0;
    }
    out_00 = out_01 + sVar3;
    *outl = sVar3;
    inl = inl - __n;
    in = in + __n;
  }
  else {
    OpenSSLDie("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
    if (iVar2 != 0) goto LAB_000aa71a;
LAB_000aa6c0:
    *outl = iVar2;
    out_00 = out_01;
  }
  __n_00 = sVar3 - 1 & inl;
  sVar3 = inl - __n_00;
  if (0 < (int)sVar3) {
    iVar2 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar3);
    if (iVar2 == 0) {
      return 0;
    }
    *outl = *outl + sVar3;
  }
  if (__n_00 != 0) {
    memcpy(ctx->buf,in + sVar3,__n_00);
  }
  ctx->buf_len = __n_00;
LAB_000aa7a2:
  if ((__n_01 < 2) || (ctx->buf_len != 0)) {
    ctx->final_used = 0;
  }
  else {
    *outl = *outl - __n_01;
    ctx->final_used = 1;
    memcpy(ctx->final,out_01 + *outl,__n_01);
  }
  if (iVar1 == 0) {
    return 1;
  }
  *outl = *outl + __n_01;
  return 1;
}

