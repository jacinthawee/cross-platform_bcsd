
int HMAC_Init(HMAC_CTX *ctx,void *key,int len,EVP_MD *md)

{
  EVP_MD_CTX *ctx_00;
  uint uVar1;
  int iVar2;
  size_t sVar3;
  int in_GS_OFFSET;
  uint local_a0 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((key == (void *)0x0) || (md == (EVP_MD *)0x0)) {
    if (md != (EVP_MD *)0x0) {
      if (md != ctx->md) goto joined_r0x080dd0d6;
      goto LAB_080dd0e1;
    }
    md = ctx->md;
    if (md == (EVP_MD *)0x0) goto LAB_080dd0a0;
    if (key != (void *)0x0) goto LAB_080dd0e7;
LAB_080dd225:
    iVar2 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
    uVar1 = (uint)(iVar2 != 0);
  }
  else {
    EVP_MD_CTX_init(&ctx->i_ctx);
    EVP_MD_CTX_init(&ctx->o_ctx);
    EVP_MD_CTX_init(&ctx->md_ctx);
    ctx->md = (EVP_MD *)0x0;
joined_r0x080dd0d6:
    if ((key != (void *)0x0) && (-1 < len)) {
LAB_080dd0e1:
      ctx->md = md;
      if (key != (void *)0x0) {
LAB_080dd0e7:
        iVar2 = EVP_MD_block_size(md);
        if (iVar2 < 0x81) {
          if (iVar2 < len) goto LAB_080dd26f;
LAB_080dd106:
          if (0x80 < (uint)len) goto LAB_080dd0a0;
          memcpy(ctx->key,key,len);
          ctx->key_length = len;
        }
        else {
          OpenSSLDie("hmac.c",0x6a,"j <= (int)sizeof(ctx->key)");
          if (len <= iVar2) goto LAB_080dd106;
LAB_080dd26f:
          ctx_00 = &ctx->md_ctx;
          iVar2 = EVP_DigestInit_ex(ctx_00,md,(ENGINE *)0x0);
          if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(ctx_00,key,len), iVar2 == 0)) ||
             (iVar2 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar2 == 0))
          goto LAB_080dd0a0;
          len = ctx->key_length;
        }
        if (len != 0x80) {
          memset(ctx->key + len,0,0x80 - len);
        }
      }
      iVar2 = 0;
      do {
        *(uint *)((int)local_a0 + iVar2) = *(uint *)(ctx->key + iVar2) ^ 0x36363636;
        iVar2 = iVar2 + 4;
      } while (iVar2 != 0x80);
      iVar2 = EVP_DigestInit_ex(&ctx->i_ctx,md,(ENGINE *)0x0);
      if (iVar2 != 0) {
        sVar3 = EVP_MD_block_size(md);
        iVar2 = EVP_DigestUpdate(&ctx->i_ctx,local_a0,sVar3);
        if (iVar2 != 0) {
          iVar2 = 0;
          do {
            *(uint *)((int)local_a0 + iVar2) = *(uint *)(ctx->key + iVar2) ^ 0x5c5c5c5c;
            iVar2 = iVar2 + 4;
          } while (iVar2 != 0x80);
          iVar2 = EVP_DigestInit_ex(&ctx->o_ctx,md,(ENGINE *)0x0);
          if (iVar2 != 0) {
            sVar3 = EVP_MD_block_size(md);
            iVar2 = EVP_DigestUpdate(&ctx->o_ctx,local_a0,sVar3);
            if (iVar2 != 0) goto LAB_080dd225;
          }
        }
      }
    }
LAB_080dd0a0:
    uVar1 = 0;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}

