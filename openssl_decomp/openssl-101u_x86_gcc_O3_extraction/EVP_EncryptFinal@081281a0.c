
int EVP_EncryptFinal(EVP_CIPHER_CTX *ctx,uchar *out,int *outl)

{
  byte bVar1;
  EVP_CIPHER *pEVar2;
  uint inl;
  uint uVar3;
  int iVar4;
  
  pEVar2 = ctx->cipher;
  if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) != 0) {
    iVar4 = (*pEVar2->do_cipher)(ctx,out,(uchar *)0x0,0);
    if (iVar4 < 0) {
      return 0;
    }
    *outl = iVar4;
    return 1;
  }
  inl = pEVar2->block_size;
  if (inl < 0x21) {
    if (inl == 1) goto LAB_081281d3;
    bVar1 = *(byte *)((int)&ctx->flags + 1);
    uVar3 = ctx->buf_len;
  }
  else {
    OpenSSLDie("evp_enc.c",0x186,"b <= sizeof ctx->buf");
    bVar1 = *(byte *)((int)&ctx->flags + 1);
    uVar3 = ctx->buf_len;
  }
  if ((bVar1 & 1) == 0) {
    if (uVar3 < inl) {
      memset(ctx->buf + uVar3,inl - uVar3 & 0xff,inl - uVar3);
    }
    iVar4 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,inl);
    if (iVar4 == 0) {
      return 0;
    }
    *outl = inl;
    return iVar4;
  }
  if (uVar3 != 0) {
    ERR_put_error(6,0x7f,0x8a,"evp_enc.c",399);
    return 0;
  }
LAB_081281d3:
  *outl = 0;
  return 1;
}

