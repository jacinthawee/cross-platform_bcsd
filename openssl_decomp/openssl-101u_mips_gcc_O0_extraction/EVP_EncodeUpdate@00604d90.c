
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  *outl = 0;
  if (inl < 1) {
    return;
  }
  iVar3 = ctx->length;
  if (iVar3 < 0x51) {
    iVar2 = ctx->num;
    iVar5 = iVar3 - iVar2;
  }
  else {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("encode.c",0xa0,"ctx->length <= (int)sizeof(ctx->enc_data)");
    iVar3 = ctx->length;
    iVar2 = ctx->num;
    iVar5 = iVar3 - iVar2;
  }
  if (inl < iVar5) {
    (*(code *)PTR_memcpy_006a9aec)(ctx->enc_data + iVar2,in,inl);
    ctx->num = ctx->num + inl;
    return;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
    if (inl < iVar3) {
      iVar2 = 0;
LAB_00604fac:
      (*(code *)PTR_memcpy_006a9aec)(ctx->enc_data,in,inl);
      ctx->num = inl;
      *outl = iVar2;
      return;
    }
    uVar4 = 10;
  }
  else {
    (*(code *)PTR_memcpy_006a9aec)(ctx->enc_data + iVar2,in,iVar5);
    inl = inl - iVar5;
    in = in + iVar5;
    iVar3 = EVP_EncodeBlock(out,ctx->enc_data,ctx->length);
    ctx->num = 0;
    iVar2 = iVar3 + 1;
    out[iVar3] = '\n';
    (out + iVar3)[1] = '\0';
    out = out + iVar2;
    iVar3 = ctx->length;
    if (inl < iVar3) {
LAB_00604e5c:
      if (-1 < iVar2) {
        if (inl == 0) {
          ctx->num = 0;
          *outl = iVar2;
          return;
        }
        goto LAB_00604fac;
      }
      goto LAB_00604f04;
    }
    uVar4 = 10;
    if (iVar2 < 0) goto LAB_00604f04;
  }
  do {
    iVar5 = EVP_EncodeBlock(out,in,iVar3);
    iVar1 = ctx->length;
    out[iVar5] = (uchar)uVar4;
    (out + iVar5)[1] = '\0';
    inl = inl - iVar1;
    iVar3 = ctx->length;
    iVar2 = iVar2 + iVar5 + 1;
    out = out + iVar5 + 1;
    in = in + iVar1;
    if (inl < iVar3) goto LAB_00604e5c;
  } while (-1 < iVar2);
LAB_00604f04:
  *outl = 0;
  return;
}

