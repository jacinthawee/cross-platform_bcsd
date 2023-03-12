
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  uchar *out_00;
  size_t sVar1;
  int iVar2;
  int iVar3;
  uint __n;
  uchar *out_01;
  uint __n_00;
  size_t __n_01;
  EVP_CIPHER *pEVar4;
  
  pEVar4 = ctx->cipher;
  if ((pEVar4->flags & 0x100000) != 0) {
    iVar2 = (*pEVar4->do_cipher)(ctx,out,in,inl);
    if (iVar2 < 0) {
      *outl = 0;
      return 0;
    }
    *outl = iVar2;
    return 1;
  }
  if (inl < 1) {
    *outl = 0;
    return (uint)(inl == 0);
  }
  if ((int)(ctx->flags << 0x17) < 0) {
    iVar2 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
    return iVar2;
  }
  __n_00 = pEVar4->block_size;
  if (0x20 < __n_00) {
    OpenSSLDie("evp_enc.c",0x1ba,"b <= sizeof ctx->final");
  }
  iVar2 = ctx->final_used;
  out_01 = out;
  if (iVar2 != 0) {
    out_01 = out + __n_00;
    memcpy(out,ctx->final,__n_00);
    iVar2 = 1;
  }
  pEVar4 = ctx->cipher;
  if ((int)(pEVar4->flags << 0xb) < 0) {
    iVar3 = (*pEVar4->do_cipher)(ctx,out_01,in,inl);
    if (iVar3 < 0) {
      return 0;
    }
    *outl = iVar3;
    goto LAB_000a7bf8;
  }
  iVar3 = ctx->buf_len;
  if ((iVar3 == 0) && ((inl & ctx->block_mask) == 0)) {
    iVar3 = (*pEVar4->do_cipher)(ctx,out_01,in,inl);
    if (iVar3 == 0) {
      *outl = 0;
      return 0;
    }
    *outl = inl;
    goto LAB_000a7bf8;
  }
  sVar1 = pEVar4->block_size;
  if ((int)sVar1 < 0x21) {
    if (iVar3 == 0) goto LAB_000a7b00;
LAB_000a7b5c:
    __n_01 = sVar1 - iVar3;
    if (inl < (int)__n_01) {
      memcpy(ctx->buf + iVar3,in,inl);
      ctx->buf_len = ctx->buf_len + inl;
      *outl = 0;
      goto LAB_000a7bf8;
    }
    memcpy(ctx->buf + iVar3,in,__n_01);
    iVar3 = (*ctx->cipher->do_cipher)(ctx,out_01,ctx->buf,sVar1);
    if (iVar3 == 0) {
      return 0;
    }
    inl = inl - __n_01;
    in = in + __n_01;
    *outl = sVar1;
    out_00 = out_01 + sVar1;
  }
  else {
    OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
    if (iVar3 != 0) goto LAB_000a7b5c;
LAB_000a7b00:
    *outl = iVar3;
    out_00 = out_01;
  }
  __n = sVar1 - 1 & inl;
  sVar1 = inl - __n;
  if (0 < (int)sVar1) {
    iVar3 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar1);
    if (iVar3 == 0) {
      return 0;
    }
    *outl = *outl + sVar1;
  }
  if (__n != 0) {
    memcpy(ctx->buf,in + sVar1,__n);
  }
  ctx->buf_len = __n;
LAB_000a7bf8:
  if ((__n_00 < 2) || (ctx->buf_len != 0)) {
    ctx->final_used = 0;
  }
  else {
    *outl = *outl - __n_00;
    ctx->final_used = 1;
    memcpy(ctx->final,out_01 + *outl,__n_00);
  }
  if (iVar2 == 0) {
    return 1;
  }
  *outl = *outl + __n_00;
  return 1;
}

