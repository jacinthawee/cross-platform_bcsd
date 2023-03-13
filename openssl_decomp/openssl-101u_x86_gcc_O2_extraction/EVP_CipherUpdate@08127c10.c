
int EVP_CipherUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  bool bVar1;
  EVP_CIPHER *pEVar2;
  int iVar3;
  uchar *out_00;
  uint __n;
  uint uVar4;
  size_t __n_00;
  size_t sVar5;
  uchar *local_34;
  size_t local_28;
  
  local_34 = out;
  if (ctx->encrypt != 0) {
    pEVar2 = ctx->cipher;
    if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) == 0) {
      if (0 < inl) {
        iVar3 = ctx->buf_len;
        if (iVar3 == 0) {
          if ((ctx->block_mask & inl) == 0) {
            iVar3 = (*pEVar2->do_cipher)(ctx,out,in,inl);
            if (iVar3 != 0) {
              *outl = inl;
              return 1;
            }
            goto LAB_08127ff0;
          }
          sVar5 = pEVar2->block_size;
          if (0x20 < (int)sVar5) {
            OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
          }
          *outl = 0;
        }
        else {
          sVar5 = pEVar2->block_size;
          if (0x20 < (int)sVar5) {
            OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
          }
          __n_00 = sVar5 - iVar3;
          if (inl < (int)__n_00) {
            memcpy(ctx->buf + iVar3,in,inl);
            ctx->buf_len = ctx->buf_len + inl;
            *outl = 0;
            return 1;
          }
          memcpy(ctx->buf + iVar3,in,__n_00);
          iVar3 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,sVar5);
          if (iVar3 == 0) {
            return 0;
          }
          inl = inl - __n_00;
          local_34 = out + sVar5;
          in = in + __n_00;
          *outl = sVar5;
        }
        uVar4 = sVar5 - 1 & inl;
        sVar5 = inl - uVar4;
        if (0 < (int)sVar5) {
          iVar3 = (*ctx->cipher->do_cipher)(ctx,local_34,in,sVar5);
          if (iVar3 == 0) {
            return 0;
          }
          *outl = *outl + sVar5;
        }
        if (uVar4 != 0) {
          memcpy(ctx->buf,in + sVar5,uVar4);
        }
        ctx->buf_len = uVar4;
        return 1;
      }
LAB_08127ef0:
      *outl = 0;
      return (uint)(inl == 0);
    }
    iVar3 = (*pEVar2->do_cipher)(ctx,out,in,inl);
    if (iVar3 < 0) {
      return 0;
    }
LAB_08127d95:
    *outl = iVar3;
    return 1;
  }
  pEVar2 = ctx->cipher;
  if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) != 0) {
    iVar3 = (*pEVar2->do_cipher)(ctx,out,in,inl);
    if (iVar3 < 0) {
LAB_08127ff0:
      *outl = 0;
      return 0;
    }
    goto LAB_08127d95;
  }
  if (inl < 1) goto LAB_08127ef0;
  if ((*(byte *)((int)&ctx->flags + 1) & 1) != 0) {
    iVar3 = EVP_EncryptUpdate(ctx,out,outl,in,inl);
    return iVar3;
  }
  uVar4 = pEVar2->block_size;
  if (uVar4 < 0x21) {
    if (ctx->final_used != 0) {
LAB_08127f28:
      memcpy(out,ctx->final,uVar4);
      local_34 = out + uVar4;
      bVar1 = true;
      goto LAB_08127e75;
    }
    bVar1 = false;
  }
  else {
    OpenSSLDie("evp_enc.c",0x1ba,"b <= sizeof ctx->final");
    bVar1 = false;
    if (ctx->final_used != 0) goto LAB_08127f28;
LAB_08127e75:
    pEVar2 = ctx->cipher;
    if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) != 0) {
      iVar3 = (*pEVar2->do_cipher)(ctx,local_34,in,inl);
      if (iVar3 < 0) {
        return 0;
      }
      *outl = iVar3;
      goto LAB_08127e94;
    }
  }
  iVar3 = ctx->buf_len;
  if (iVar3 == 0) {
    if ((ctx->block_mask & inl) == 0) {
      iVar3 = (*pEVar2->do_cipher)(ctx,local_34,in,inl);
      if (iVar3 == 0) {
        *outl = 0;
        return 0;
      }
      *outl = inl;
      goto LAB_08127e94;
    }
    local_28 = pEVar2->block_size;
    if (0x20 < (int)local_28) {
      OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
    }
    *outl = 0;
    out_00 = local_34;
  }
  else {
    local_28 = pEVar2->block_size;
    if (0x20 < (int)local_28) {
      OpenSSLDie("evp_enc.c",0x14f,"bl <= (int)sizeof(ctx->buf)");
    }
    sVar5 = local_28 - iVar3;
    if (inl < (int)sVar5) {
      memcpy(ctx->buf + iVar3,in,inl);
      ctx->buf_len = ctx->buf_len + inl;
      *outl = 0;
      goto LAB_08127e94;
    }
    memcpy(ctx->buf + iVar3,in,sVar5);
    iVar3 = (*ctx->cipher->do_cipher)(ctx,local_34,ctx->buf,local_28);
    if (iVar3 == 0) {
      return 0;
    }
    inl = inl - sVar5;
    in = in + sVar5;
    *outl = local_28;
    out_00 = local_34 + local_28;
  }
  __n = local_28 - 1 & inl;
  sVar5 = inl - __n;
  if (0 < (int)sVar5) {
    iVar3 = (*ctx->cipher->do_cipher)(ctx,out_00,in,sVar5);
    if (iVar3 == 0) {
      return 0;
    }
    *outl = *outl + sVar5;
  }
  if (__n != 0) {
    memcpy(ctx->buf,in + sVar5,__n);
  }
  ctx->buf_len = __n;
LAB_08127e94:
  if ((uVar4 < 2) || (ctx->buf_len != 0)) {
    ctx->final_used = 0;
  }
  else {
    *outl = *outl - uVar4;
    ctx->final_used = 1;
    memcpy(ctx->final,local_34 + *outl,uVar4);
  }
  if (!bVar1) {
    return 1;
  }
  *outl = *outl + uVar4;
  return 1;
}

