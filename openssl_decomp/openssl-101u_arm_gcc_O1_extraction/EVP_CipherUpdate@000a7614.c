
int EVP_CipherUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  int iVar1;
  uchar *out_00;
  size_t sVar2;
  int iVar3;
  uint __n;
  uint uVar4;
  size_t sVar5;
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
      uVar4 = pEVar6->block_size;
      if (0x20 < uVar4) {
        OpenSSLDie("evp_enc.c",0x1ba,"b <= sizeof ctx->final");
      }
      local_30 = ctx->final_used;
      if (local_30 != 0) {
        memcpy(out,ctx->final,uVar4);
        out = out + uVar4;
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
          sVar2 = pEVar6->block_size;
          if (0x20 < (int)sVar2) {
            OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
          }
          if (iVar3 == 0) {
            *outl = 0;
            out_00 = out;
          }
          else {
            sVar5 = sVar2 - iVar3;
            if (inl < (int)sVar5) {
              memcpy(ctx->buf + iVar3,in,inl);
              ctx->buf_len = ctx->buf_len + inl;
              *outl = 0;
              goto LAB_000a7804;
            }
            memcpy(ctx->buf + iVar3,in,sVar5);
            iVar3 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar2);
            if (iVar3 == 0) {
              return 0;
            }
            inl = inl - sVar5;
            in = in + sVar5;
            *outl = sVar2;
            out_00 = out + sVar2;
          }
          __n = inl & sVar2 - 1;
          sVar2 = inl - __n;
          if (0 < (int)sVar2) {
            iVar3 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar2);
            if (iVar3 == 0) {
              return 0;
            }
            *outl = *outl + sVar2;
          }
          if (__n != 0) {
            memcpy(ctx->buf,in + sVar2,__n);
          }
          ctx->buf_len = __n;
        }
      }
LAB_000a7804:
      if ((uVar4 < 2) || (ctx->buf_len != 0)) {
        ctx->final_used = 0;
      }
      else {
        *outl = *outl - uVar4;
        ctx->final_used = 1;
        memcpy(ctx->final,out + *outl,uVar4);
      }
      if (local_30 != 0) {
        *outl = *outl + uVar4;
        return 1;
      }
      return 1;
    }
    iVar1 = (*pEVar6->do_cipher)(ctx,out,in,inl);
    if (iVar1 < 0) goto LAB_000a7874;
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
        sVar2 = pEVar6->block_size;
        if (0x20 < (int)sVar2) {
          OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
        }
        if (iVar3 == 0) {
          *outl = 0;
        }
        else {
          sVar5 = sVar2 - iVar3;
          if (inl < (int)sVar5) {
            memcpy(ctx->buf + iVar3,in,inl);
            ctx->buf_len = ctx->buf_len + inl;
            *outl = 0;
            return 1;
          }
          memcpy(ctx->buf + iVar3,in,sVar5);
          iVar3 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar2);
          if (iVar3 == 0) {
            return 0;
          }
          inl = inl - sVar5;
          in = in + sVar5;
          out = out + sVar2;
          *outl = sVar2;
        }
        uVar4 = inl & sVar2 - 1;
        sVar2 = inl - uVar4;
        if (0 < (int)sVar2) {
          iVar3 = (*ctx->cipher->do_cipher)(ctx,out,in,sVar2);
          if (iVar3 == 0) {
            return 0;
          }
          *outl = *outl + sVar2;
        }
        if (uVar4 != 0) {
          memcpy(ctx->buf,in + sVar2,uVar4);
        }
        ctx->buf_len = uVar4;
        return 1;
      }
      iVar3 = (*pEVar6->do_cipher)(ctx,out,in,inl);
      if (iVar3 != 0) {
        *outl = inl;
        return 1;
      }
LAB_000a7874:
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

