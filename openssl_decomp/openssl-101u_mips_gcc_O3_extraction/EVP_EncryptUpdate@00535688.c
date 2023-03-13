
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  
  pEVar2 = ctx->cipher;
  if ((int)(pEVar2->flags << 0xb) < 0) {
    iVar5 = (*pEVar2->do_cipher)(ctx,out,in,inl);
    if (iVar5 < 0) {
      return 0;
    }
    *outl = iVar5;
    return 1;
  }
  if (inl < 1) {
    *outl = 0;
    return (uint)(inl == 0);
  }
  iVar5 = ctx->buf_len;
  if (iVar5 == 0) {
    if ((inl & ctx->block_mask) == 0) {
      iVar5 = (*pEVar2->do_cipher)(ctx,out,in,inl);
      if (iVar5 != 0) {
        *outl = inl;
        return 1;
      }
LAB_005358c4:
      *outl = 0;
      return iVar5;
    }
    sVar3 = pEVar2->block_size;
    if (0x20 < (int)sVar3) {
      (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
    }
    *outl = 0;
  }
  else {
    sVar3 = pEVar2->block_size;
    if (0x20 < (int)sVar3) {
      (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
    }
    iVar1 = sVar3 - iVar5;
    if (inl < iVar1) {
      (*(code *)PTR_memcpy_006a9aec)(ctx->buf + iVar5,in,inl);
      iVar5 = 1;
      ctx->buf_len = ctx->buf_len + inl;
      goto LAB_005358c4;
    }
    (*(code *)PTR_memcpy_006a9aec)(ctx->buf + iVar5,in,iVar1);
    iVar5 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar3);
    if (iVar5 == 0) {
      return 0;
    }
    inl = inl - iVar1;
    *outl = sVar3;
    in = in + iVar1;
    out = out + sVar3;
  }
  uVar4 = sVar3 - 1 & inl;
  sVar3 = inl - uVar4;
  if (0 < (int)sVar3) {
    iVar5 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar3);
    if (iVar5 == 0) {
      return 0;
    }
    *outl = *outl + sVar3;
  }
  if (uVar4 != 0) {
    (*(code *)PTR_memcpy_006a9aec)(ctx->buf,in + sVar3,uVar4);
  }
  ctx->buf_len = uVar4;
  return 1;
}

