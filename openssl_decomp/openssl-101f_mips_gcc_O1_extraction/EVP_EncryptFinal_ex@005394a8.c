
int EVP_EncryptFinal_ex(EVP_CIPHER_CTX *ctx,uchar *out,int *outl)

{
  uint uVar1;
  int iVar2;
  EVP_CIPHER *pEVar3;
  uint uVar4;
  uint inl;
  
  pEVar3 = ctx->cipher;
  if ((int)(pEVar3->flags << 0xb) < 0) {
    iVar2 = (*pEVar3->do_cipher)(ctx,out,(uchar *)0x0,0);
    if (iVar2 < 0) {
      return 0;
    }
    *outl = iVar2;
    return 1;
  }
  inl = pEVar3->block_size;
  if (inl < 0x21) {
    if (inl == 1) goto LAB_0053957c;
    uVar1 = ctx->flags;
    uVar4 = ctx->buf_len;
  }
  else {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x193,"b <= sizeof ctx->buf");
    uVar1 = ctx->flags;
    uVar4 = ctx->buf_len;
  }
  if ((uVar1 & 0x100) == 0) {
    if (uVar4 < inl) {
      (*(code *)PTR_memset_006aab00)(ctx->buf + uVar4,inl - uVar4 & 0xff);
    }
    iVar2 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,inl);
    if (iVar2 == 0) {
      return 0;
    }
    *outl = inl;
    return iVar2;
  }
  if (uVar4 != 0) {
    ERR_put_error(6,0x7f,0x8a,"evp_enc.c",0x19e);
    return 0;
  }
LAB_0053957c:
  *outl = 0;
  return 1;
}

