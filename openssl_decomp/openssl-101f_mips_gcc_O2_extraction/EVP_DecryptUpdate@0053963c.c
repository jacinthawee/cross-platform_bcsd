
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  bool bVar1;
  undefined *puVar2;
  EVP_CIPHER *pEVar3;
  uchar *out_00;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  pEVar3 = ctx->cipher;
  if ((int)(pEVar3->flags << 0xb) < 0) {
    iVar6 = (*pEVar3->do_cipher)(ctx,out,in,inl);
    if (iVar6 < 0) {
      *outl = 0;
    }
    else {
      *outl = iVar6;
    }
    return (uint)(iVar6 >= 0);
  }
  if (inl < 1) {
    *outl = 0;
    return (uint)(inl == 0);
  }
  if ((ctx->flags & 0x100) != 0) {
    iVar6 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
    return iVar6;
  }
  uVar8 = pEVar3->block_size;
  if (uVar8 < 0x21) {
    bVar1 = false;
    if (ctx->final_used != 0) {
LAB_005398a4:
      (*(code *)PTR_memcpy_006aabf4)(out,ctx->final,uVar8);
      out = out + uVar8;
      bVar1 = true;
      goto LAB_005398c4;
    }
  }
  else {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x1ce,"b <= sizeof ctx->final");
    if (ctx->final_used != 0) goto LAB_005398a4;
    bVar1 = false;
LAB_005398c4:
    pEVar3 = ctx->cipher;
    if ((int)(pEVar3->flags << 0xb) < 0) {
      iVar6 = (*pEVar3->do_cipher)(ctx,out,in,inl);
      if (iVar6 < 0) {
        return 0;
      }
      *outl = iVar6;
      goto LAB_005398fc;
    }
  }
  iVar6 = ctx->buf_len;
  if (iVar6 == 0) {
    if ((inl & ctx->block_mask) == 0) {
      iVar6 = (*pEVar3->do_cipher)(ctx,out,in,inl);
      if (iVar6 == 0) {
        *outl = 0;
        return 0;
      }
      *outl = inl;
      goto LAB_005398fc;
    }
    sVar4 = pEVar3->block_size;
    if (0x20 < (int)sVar4) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
    }
    *outl = 0;
    out_00 = out;
  }
  else {
    sVar4 = pEVar3->block_size;
    if (0x20 < (int)sVar4) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
    }
    if (inl + iVar6 < (int)sVar4) {
      (*(code *)PTR_memcpy_006aabf4)(ctx->buf + iVar6,in,inl);
      ctx->buf_len = ctx->buf_len + inl;
      *outl = 0;
      goto LAB_005398fc;
    }
    iVar7 = sVar4 - iVar6;
    (*(code *)PTR_memcpy_006aabf4)(ctx->buf + iVar6,in,iVar7);
    iVar6 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar4);
    if (iVar6 == 0) {
      return 0;
    }
    inl = inl - iVar7;
    *outl = sVar4;
    in = in + iVar7;
    out_00 = out + sVar4;
  }
  uVar5 = sVar4 - 1 & inl;
  sVar4 = inl - uVar5;
  if (0 < (int)sVar4) {
    iVar6 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar4);
    if (iVar6 == 0) {
      return 0;
    }
    *outl = *outl + sVar4;
  }
  if (uVar5 == 0) {
    ctx->buf_len = 0;
  }
  else {
    (*(code *)PTR_memcpy_006aabf4)(ctx->buf,in + sVar4,uVar5);
    ctx->buf_len = uVar5;
  }
LAB_005398fc:
  puVar2 = PTR_memcpy_006aabf4;
  if ((uVar8 < 2) || (ctx->buf_len != 0)) {
    ctx->final_used = 0;
  }
  else {
    *outl = *outl - uVar8;
    ctx->final_used = 1;
    (*(code *)puVar2)(ctx->final,out + *outl,uVar8);
  }
  if (!bVar1) {
    return 1;
  }
  *outl = *outl + uVar8;
  return 1;
}

