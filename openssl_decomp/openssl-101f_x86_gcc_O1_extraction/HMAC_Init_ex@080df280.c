
int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  EVP_MD_CTX *ctx_00;
  int iVar1;
  uint uVar2;
  size_t sVar3;
  int in_GS_OFFSET;
  uint local_a0 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (md == (EVP_MD *)0x0) {
    if (key != (void *)0x0) {
      md = ctx->md;
      goto LAB_080df2ce;
    }
LAB_080df40b:
    iVar1 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
    uVar2 = (uint)(iVar1 != 0);
  }
  else {
    ctx->md = md;
    if (key == (void *)0x0) {
LAB_080df32f:
      iVar1 = 0;
      do {
        *(uint *)((int)local_a0 + iVar1) = *(uint *)(ctx->key + iVar1) ^ 0x36363636;
        iVar1 = iVar1 + 4;
      } while (iVar1 != 0x80);
      iVar1 = EVP_DigestInit_ex(&ctx->i_ctx,md,impl);
      if (iVar1 != 0) {
        sVar3 = EVP_MD_block_size(md);
        iVar1 = EVP_DigestUpdate(&ctx->i_ctx,local_a0,sVar3);
        if (iVar1 != 0) {
          iVar1 = 0;
          do {
            *(uint *)((int)local_a0 + iVar1) = *(uint *)(ctx->key + iVar1) ^ 0x5c5c5c5c;
            iVar1 = iVar1 + 4;
          } while (iVar1 != 0x80);
          iVar1 = EVP_DigestInit_ex(&ctx->o_ctx,md,impl);
          if (iVar1 != 0) {
            sVar3 = EVP_MD_block_size(md);
            iVar1 = EVP_DigestUpdate(&ctx->o_ctx,local_a0,sVar3);
            if (iVar1 != 0) goto LAB_080df40b;
          }
        }
      }
    }
    else {
LAB_080df2ce:
      iVar1 = EVP_MD_block_size(md);
      if (iVar1 < 0x81) {
        if (iVar1 < len) goto LAB_080df430;
LAB_080df2ed:
        if (0x80 < (uint)len) {
          OpenSSLDie("hmac.c",0x75,"len>=0 && len<=(int)sizeof(ctx->key)");
        }
        memcpy(ctx->key,key,len);
        ctx->key_length = len;
LAB_080df30d:
        if (len != 0x80) {
          memset(ctx->key + len,0,0x80 - len);
        }
        goto LAB_080df32f;
      }
      OpenSSLDie("hmac.c",0x68,"j <= (int)sizeof(ctx->key)");
      if (len <= iVar1) goto LAB_080df2ed;
LAB_080df430:
      ctx_00 = &ctx->md_ctx;
      iVar1 = EVP_DigestInit_ex(ctx_00,md,impl);
      if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx_00,key,len), iVar1 != 0)) &&
         (iVar1 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar1 != 0)) {
        len = ctx->key_length;
        goto LAB_080df30d;
      }
    }
    uVar2 = 0;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

