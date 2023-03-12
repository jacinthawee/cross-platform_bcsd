
int EVP_CipherUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  uchar *out_00;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  uint __n;
  uint uVar5;
  EVP_CIPHER *pEVar6;
  int local_30;
  
  iVar3 = ctx->encrypt;
  if (iVar3 == 0) {
    pEVar6 = ctx->cipher;
    if (-1 < (int)(pEVar6->flags << 0xb)) {
      if (inl < 1) {
        *outl = 0;
        return (uint)(inl == 0);
      }
      if ((int)(ctx->flags << 0x17) < 0) {
        iVar3 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
        return iVar3;
      }
      uVar5 = pEVar6->block_size;
      if (0x20 < uVar5) {
        OpenSSLDie("evp_enc.c",0x1ce,"b <= sizeof ctx->final");
      }
      local_30 = ctx->final_used;
      if (local_30 != 0) {
        memcpy(out,ctx->final,uVar5);
        out = out + uVar5;
        local_30 = 1;
      }
      pEVar6 = ctx->cipher;
      if ((int)(pEVar6->flags << 0xb) < 0) {
        iVar3 = (*pEVar6->do_cipher)(ctx,out,in,inl);
        if (iVar3 < 0) {
          return 0;
        }
        *outl = iVar3;
      }
      else {
        iVar3 = ctx->buf_len;
        if ((iVar3 == 0) && ((inl & ctx->block_mask) == 0)) {
          iVar3 = (*pEVar6->do_cipher)(ctx,out,in,inl);
          if (iVar3 == 0) {
            *outl = 0;
            return 0;
          }
          *outl = inl;
        }
        else {
          sVar4 = pEVar6->block_size;
          if (0x20 < (int)sVar4) {
            OpenSSLDie("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
          }
          if (iVar3 == 0) {
            *outl = 0;
            out_00 = out;
          }
          else {
            if (inl + iVar3 < (int)sVar4) {
              memcpy(ctx->buf + iVar3,in,inl);
              ctx->buf_len = ctx->buf_len + inl;
              *outl = 0;
              goto LAB_000aa3ba;
            }
            sVar2 = sVar4 - iVar3;
            memcpy(ctx->buf + iVar3,in,sVar2);
            iVar3 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar4);
            if (iVar3 == 0) {
              return 0;
            }
            *outl = sVar4;
            inl = inl - sVar2;
            in = in + sVar2;
            out_00 = out + sVar4;
          }
          __n = inl & sVar4 - 1;
          sVar4 = inl - __n;
          if (0 < (int)sVar4) {
            iVar3 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar4);
            if (iVar3 == 0) {
              return 0;
            }
            *outl = *outl + sVar4;
          }
          if (__n != 0) {
            memcpy(ctx->buf,in + sVar4,__n);
          }
          ctx->buf_len = __n;
        }
      }
LAB_000aa3ba:
      if ((uVar5 < 2) || (ctx->buf_len != 0)) {
        ctx->final_used = 0;
      }
      else {
        *outl = *outl - uVar5;
        ctx->final_used = 1;
        memcpy(ctx->final,out + *outl,uVar5);
      }
      if (local_30 != 0) {
        *outl = *outl + uVar5;
        return 1;
      }
      return 1;
    }
    iVar1 = (*pEVar6->do_cipher)(ctx,out,in,inl);
    if (iVar1 < 0) goto LAB_000aa428;
  }
  else {
    pEVar6 = ctx->cipher;
    if ((pEVar6->flags & 0x100000) == 0) {
      if (inl < 1) {
        *outl = 0;
        return (uint)(inl == 0);
      }
      iVar3 = ctx->buf_len;
      if ((iVar3 != 0) || ((inl & ctx->block_mask) != 0)) {
        sVar4 = pEVar6->block_size;
        if (0x20 < (int)sVar4) {
          OpenSSLDie("evp_enc.c",0x157,"bl <= (int)sizeof(ctx->buf)");
        }
        if (iVar3 == 0) {
          *outl = 0;
        }
        else {
          if (inl + iVar3 < (int)sVar4) {
            memcpy(ctx->buf + iVar3,in,inl);
            ctx->buf_len = ctx->buf_len + inl;
            *outl = 0;
            return 1;
          }
          sVar2 = sVar4 - iVar3;
          memcpy(ctx->buf + iVar3,in,sVar2);
          iVar3 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar4);
          if (iVar3 == 0) {
            return 0;
          }
          inl = inl - sVar2;
          in = in + sVar2;
          out = out + sVar4;
          *outl = sVar4;
        }
        uVar5 = inl & sVar4 - 1;
        sVar4 = inl - uVar5;
        if (0 < (int)sVar4) {
          iVar3 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar4);
          if (iVar3 == 0) {
            return 0;
          }
          *outl = *outl + sVar4;
        }
        if (uVar5 != 0) {
          memcpy(ctx->buf,in + sVar4,uVar5);
        }
        ctx->buf_len = uVar5;
        return 1;
      }
      iVar3 = (*pEVar6->do_cipher)(ctx,out,in,inl);
      if (iVar3 != 0) {
        *outl = inl;
        return 1;
      }
LAB_000aa428:
      *outl = iVar3;
      return iVar3;
    }
    iVar1 = (*pEVar6->do_cipher)(ctx,out,in,inl);
    if (iVar1 < 0) {
      return 0;
    }
  }
  *outl = iVar1;
  return 1;
}

