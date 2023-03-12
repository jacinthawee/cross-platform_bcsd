
int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  int iVar1;
  size_t sVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  EVP_MD_CTX *ctx_00;
  uint *puVar6;
  uint auStack_ac [32];
  uint local_2c [2];
  
  local_2c[0] = __TMC_END__;
  if (md == (EVP_MD *)0x0) {
    md = ctx->md;
    if (key != (void *)0x0) goto LAB_00075854;
LAB_0007591a:
    iVar1 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    ctx->md = md;
    if (key == (void *)0x0) {
LAB_00075894:
      puVar6 = &ctx->key_length;
      puVar4 = auStack_ac;
      puVar3 = puVar6;
      do {
        puVar3 = puVar3 + 1;
        puVar5 = puVar4 + 1;
        *puVar4 = *puVar3 ^ 0x36363636;
        puVar4 = puVar5;
      } while (puVar5 != local_2c);
      iVar1 = EVP_DigestInit_ex(&ctx->i_ctx,md,impl);
      if (iVar1 != 0) {
        sVar2 = EVP_MD_block_size(md);
        iVar1 = EVP_DigestUpdate(&ctx->i_ctx,auStack_ac,sVar2);
        if (iVar1 != 0) {
          puVar3 = auStack_ac;
          do {
            puVar6 = puVar6 + 1;
            puVar4 = puVar3 + 1;
            *puVar3 = *puVar6 ^ 0x5c5c5c5c;
            puVar3 = puVar4;
          } while (puVar4 != local_2c);
          iVar1 = EVP_DigestInit_ex(&ctx->o_ctx,md,impl);
          if (iVar1 != 0) {
            sVar2 = EVP_MD_block_size(md);
            iVar1 = EVP_DigestUpdate(&ctx->o_ctx,auStack_ac,sVar2);
            if (iVar1 != 0) goto LAB_0007591a;
          }
        }
      }
    }
    else {
LAB_00075854:
      iVar1 = EVP_MD_block_size(md);
      if (iVar1 < 0x81) {
        if (iVar1 < len) goto LAB_0007592c;
LAB_00075866:
        if (0x80 < (uint)len) {
          OpenSSLDie("hmac.c",0x75,"len>=0 && len<=(int)sizeof(ctx->key)");
        }
        memcpy(ctx->key,key,len);
        ctx->key_length = len;
LAB_00075880:
        if (len != 0x80) {
          memset(ctx->key + len,0,0x80 - len);
        }
        goto LAB_00075894;
      }
      OpenSSLDie("hmac.c",0x68,"j <= (int)sizeof(ctx->key)");
      if (len <= iVar1) goto LAB_00075866;
LAB_0007592c:
      ctx_00 = &ctx->md_ctx;
      iVar1 = EVP_DigestInit_ex(ctx_00,md,impl);
      if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx_00,key,len), iVar1 != 0)) &&
         (iVar1 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar1 != 0)) {
        len = ctx->key_length;
        goto LAB_00075880;
      }
    }
    iVar1 = 0;
  }
  if (local_2c[0] != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

