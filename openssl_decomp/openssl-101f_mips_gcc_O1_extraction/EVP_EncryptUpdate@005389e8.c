
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  EVP_CIPHER *pEVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  pEVar1 = ctx->cipher;
  if ((int)(pEVar1->flags << 0xb) < 0) {
    iVar4 = (*pEVar1->do_cipher)(ctx,out,in,inl);
    if (iVar4 < 0) {
      return 0;
    }
    *outl = iVar4;
    return 1;
  }
  if (inl < 1) {
    *outl = 0;
    return (uint)(inl == 0);
  }
  iVar4 = ctx->buf_len;
  if (iVar4 == 0) {
    if ((inl & ctx->block_mask) == 0) {
      iVar4 = (*pEVar1->do_cipher)(ctx,out,in,inl);
      if (iVar4 != 0) {
        *outl = inl;
        return 1;
      }
LAB_00538c18:
      *outl = 0;
      return iVar4;
    }
    sVar2 = pEVar1->block_size;
    if (0x20 < (int)sVar2) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
    }
    *outl = 0;
  }
  else {
    sVar2 = pEVar1->block_size;
    if (0x20 < (int)sVar2) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
    }
    if (inl + iVar4 < (int)sVar2) {
      (*(code *)PTR_memcpy_006aabf4)(ctx->buf + iVar4,in,inl);
      iVar4 = 1;
      ctx->buf_len = ctx->buf_len + inl;
      goto LAB_00538c18;
    }
    iVar5 = sVar2 - iVar4;
    (*(code *)PTR_memcpy_006aabf4)(ctx->buf + iVar4,in,iVar5);
    iVar4 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar2);
    if (iVar4 == 0) {
      return 0;
    }
    inl = inl - iVar5;
    *outl = sVar2;
    in = in + iVar5;
    out = out + sVar2;
  }
  uVar3 = sVar2 - 1 & inl;
  sVar2 = inl - uVar3;
  if (0 < (int)sVar2) {
    iVar4 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar2);
    if (iVar4 == 0) {
      return 0;
    }
    *outl = *outl + sVar2;
  }
  if (uVar3 != 0) {
    (*(code *)PTR_memcpy_006aabf4)(ctx->buf,in + sVar2,uVar3);
  }
  ctx->buf_len = uVar3;
  return 1;
}

