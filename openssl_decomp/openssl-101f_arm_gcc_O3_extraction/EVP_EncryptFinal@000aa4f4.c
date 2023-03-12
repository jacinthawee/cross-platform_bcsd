
int EVP_EncryptFinal(EVP_CIPHER_CTX *ctx,uchar *out,int *outl)

{
  int iVar1;
  ulong uVar2;
  EVP_CIPHER *pEVar3;
  uint uVar4;
  uint inl;
  
  pEVar3 = ctx->cipher;
  if ((int)(pEVar3->flags << 0xb) < 0) {
    iVar1 = (*pEVar3->do_cipher)(ctx,out,(uchar *)0x0,0);
    if (iVar1 < 0) {
      return 0;
    }
    *outl = iVar1;
    return 1;
  }
  inl = pEVar3->block_size;
  if (inl < 0x21) {
    if (inl == 1) goto LAB_000aa51c;
    uVar2 = ctx->flags;
    uVar4 = ctx->buf_len;
  }
  else {
    OpenSSLDie("evp_enc.c",0x193,"b <= sizeof ctx->buf");
    uVar2 = ctx->flags;
    uVar4 = ctx->buf_len;
  }
  if (-1 < (int)(uVar2 << 0x17)) {
    if (uVar4 < inl) {
      memset(ctx->buf + uVar4,inl - uVar4 & 0xff,inl - uVar4);
    }
    iVar1 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,inl);
    if (iVar1 == 0) {
      return 0;
    }
    *outl = inl;
    return iVar1;
  }
  if (uVar4 != 0) {
    ERR_put_error(6,0x7f,0x8a,"evp_enc.c",0x19e);
    return 0;
  }
LAB_000aa51c:
  *outl = 0;
  return 1;
}

