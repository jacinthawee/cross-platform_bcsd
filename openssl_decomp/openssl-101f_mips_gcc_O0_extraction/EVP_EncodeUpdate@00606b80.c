
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  *outl = 0;
  if (inl == 0) {
    return;
  }
  iVar2 = ctx->length;
  if (iVar2 < 0x51) {
    iVar5 = ctx->num;
    if (inl + iVar5 < iVar2) {
LAB_00606ca8:
      (*(code *)PTR_memcpy_006aabf4)(ctx->enc_data + iVar5,in,inl);
      ctx->num = ctx->num + inl;
      return;
    }
  }
  else {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("encode.c",0x8b,"ctx->length <= (int)sizeof(ctx->enc_data)");
    iVar5 = ctx->num;
    iVar2 = ctx->length;
    if (inl + iVar5 < iVar2) goto LAB_00606ca8;
  }
  if (iVar5 == 0) {
    iVar3 = 0;
    if (inl < iVar2) goto LAB_00606cec;
LAB_00606bf8:
    uVar4 = 10;
    do {
      iVar5 = EVP_EncodeBlock(out,in,iVar2);
      iVar1 = ctx->length;
      out[iVar5] = (uchar)uVar4;
      (out + iVar5)[1] = '\0';
      inl = inl - iVar1;
      iVar2 = ctx->length;
      out = out + iVar5 + 1;
      iVar3 = iVar3 + iVar5 + 1;
      in = in + iVar1;
    } while (iVar2 <= inl);
  }
  else {
    iVar2 = iVar2 - iVar5;
    (*(code *)PTR_memcpy_006aabf4)(ctx->enc_data + iVar5,in,iVar2);
    inl = inl - iVar2;
    in = in + iVar2;
    iVar2 = EVP_EncodeBlock(out,ctx->enc_data,ctx->length);
    iVar3 = iVar2 + 1;
    ctx->num = 0;
    (out + iVar2)[1] = '\0';
    out[iVar2] = '\n';
    iVar2 = ctx->length;
    out = out + iVar3;
    if (iVar2 <= inl) goto LAB_00606bf8;
  }
  iVar5 = iVar3;
  if (inl == 0) {
    ctx->num = 0;
    *outl = iVar3;
    return;
  }
LAB_00606cec:
  (*(code *)PTR_memcpy_006aabf4)(ctx->enc_data,in,inl);
  ctx->num = inl;
  *outl = iVar5;
  return;
}

