
int EVP_CipherUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  bool bVar1;
  undefined *puVar2;
  EVP_CIPHER *pEVar3;
  int iVar4;
  uchar *out_00;
  size_t sVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  pEVar3 = ctx->cipher;
  if (ctx->encrypt != 0) {
    if (-1 < (int)(pEVar3->flags << 0xb)) {
      if (0 < inl) {
        iVar7 = ctx->buf_len;
        if (iVar7 == 0) {
          if ((inl & ctx->block_mask) == 0) {
            iVar7 = (*pEVar3->do_cipher)(ctx,out,in,inl);
            if (iVar7 != 0) {
              *outl = inl;
              return 1;
            }
            goto LAB_00535d04;
          }
          sVar5 = pEVar3->block_size;
          if (0x20 < (int)sVar5) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
          }
          *outl = 0;
        }
        else {
          sVar5 = pEVar3->block_size;
          if (0x20 < (int)sVar5) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
          }
          iVar4 = sVar5 - iVar7;
          if (inl < iVar4) {
            (*(code *)PTR_memcpy_006a9aec)(ctx->buf + iVar7,in,inl);
            ctx->buf_len = ctx->buf_len + inl;
            *outl = 0;
            return 1;
          }
          (*(code *)PTR_memcpy_006a9aec)(ctx->buf + iVar7,in,iVar4);
          iVar7 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar5);
          if (iVar7 == 0) {
            return 0;
          }
          inl = inl - iVar4;
          *outl = sVar5;
          in = in + iVar4;
          out = out + sVar5;
        }
        uVar8 = sVar5 - 1 & inl;
        sVar5 = inl - uVar8;
        if (0 < (int)sVar5) {
          iVar7 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar5);
          if (iVar7 == 0) {
            return 0;
          }
          *outl = *outl + sVar5;
        }
        if (uVar8 == 0) {
          ctx->buf_len = 0;
        }
        else {
          (*(code *)PTR_memcpy_006a9aec)(ctx->buf,in + sVar5,uVar8);
          ctx->buf_len = uVar8;
        }
        return 1;
      }
LAB_00535d4c:
      *outl = 0;
      return (uint)(inl == 0);
    }
    iVar7 = (*pEVar3->do_cipher)(ctx,out,in,inl);
    if (iVar7 < 0) {
      return 0;
    }
LAB_00535b68:
    *outl = iVar7;
    return 1;
  }
  if ((int)(pEVar3->flags << 0xb) < 0) {
    iVar7 = (*pEVar3->do_cipher)(ctx,out,in,inl);
    if (iVar7 < 0) {
LAB_00535d04:
      *outl = 0;
      return 0;
    }
    goto LAB_00535b68;
  }
  if (inl < 1) goto LAB_00535d4c;
  if ((ctx->flags & 0x100) != 0) {
    iVar7 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
    return iVar7;
  }
  uVar8 = pEVar3->block_size;
  if (uVar8 < 0x21) {
    if (ctx->final_used != 0) {
LAB_00535da0:
      (*(code *)PTR_memcpy_006a9aec)(out,ctx->final,uVar8);
      out = out + uVar8;
      bVar1 = true;
      goto LAB_00535c6c;
    }
    bVar1 = false;
  }
  else {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_enc.c",0x1ba,"b <= sizeof ctx->final");
    if (ctx->final_used != 0) goto LAB_00535da0;
    bVar1 = false;
LAB_00535c6c:
    pEVar3 = ctx->cipher;
    if ((int)(pEVar3->flags << 0xb) < 0) {
      iVar7 = (*pEVar3->do_cipher)(ctx,out,in,inl);
      if (iVar7 < 0) {
        return 0;
      }
      *outl = iVar7;
      goto LAB_00535ca4;
    }
  }
  iVar7 = ctx->buf_len;
  if (iVar7 == 0) {
    if ((inl & ctx->block_mask) == 0) {
      iVar7 = (*pEVar3->do_cipher)(ctx,out,in,inl);
      if (iVar7 == 0) {
        *outl = 0;
        return 0;
      }
      *outl = inl;
      goto LAB_00535ca4;
    }
    sVar5 = pEVar3->block_size;
    if (0x20 < (int)sVar5) {
      (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
    }
    *outl = 0;
    out_00 = out;
  }
  else {
    sVar5 = pEVar3->block_size;
    if (0x20 < (int)sVar5) {
      (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
    }
    iVar4 = sVar5 - iVar7;
    if (inl < iVar4) {
      (*(code *)PTR_memcpy_006a9aec)(ctx->buf + iVar7,in,inl);
      ctx->buf_len = ctx->buf_len + inl;
      *outl = 0;
      goto LAB_00535ca4;
    }
    (*(code *)PTR_memcpy_006a9aec)(ctx->buf + iVar7,in,iVar4);
    iVar7 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar5);
    if (iVar7 == 0) {
      return 0;
    }
    out_00 = out + sVar5;
    *outl = sVar5;
    inl = inl - iVar4;
    in = in + iVar4;
  }
  uVar6 = sVar5 - 1 & inl;
  sVar5 = inl - uVar6;
  if (0 < (int)sVar5) {
    iVar7 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar5);
    if (iVar7 == 0) {
      return 0;
    }
    *outl = *outl + sVar5;
  }
  if (uVar6 == 0) {
    ctx->buf_len = 0;
  }
  else {
    (*(code *)PTR_memcpy_006a9aec)(ctx->buf,in + sVar5,uVar6);
    ctx->buf_len = uVar6;
  }
LAB_00535ca4:
  puVar2 = PTR_memcpy_006a9aec;
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

