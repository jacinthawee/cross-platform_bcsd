
int HMAC_Init(HMAC_CTX *ctx,void *key,int len,EVP_MD *md)

{
  int iVar1;
  size_t sVar2;
  uint *puVar3;
  EVP_MD *pEVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  void *pvVar8;
  EVP_MD_CTX *ctx_00;
  uint *puVar9;
  uint auStack_ac [32];
  uint local_2c [2];
  
  pvVar8 = key;
  if (key != (void *)0x0) {
    pvVar8 = (void *)0x1;
  }
  pEVar4 = md;
  if (md != (EVP_MD *)0x0) {
    pEVar4 = (EVP_MD *)0x1;
  }
  local_2c[0] = __stack_chk_guard;
  if (((uint)pvVar8 & (uint)pEVar4) == 0) {
    if (pEVar4 != (EVP_MD *)0x0) {
      if (md != ctx->md) goto LAB_000736e2;
      goto LAB_000736ee;
    }
    md = ctx->md;
    if (md == (EVP_MD *)0x0) goto LAB_0007370e;
    if (pvVar8 != (void *)0x0) goto LAB_000736f8;
LAB_000737ee:
    iVar1 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    EVP_MD_CTX_init(&ctx->i_ctx);
    EVP_MD_CTX_init(&ctx->o_ctx);
    EVP_MD_CTX_init(&ctx->md_ctx);
    ctx->md = (EVP_MD *)0x0;
LAB_000736e2:
    uVar5 = count_leading_zeroes(key);
    if ((uVar5 >> 5 | (uint)len >> 0x1f) != 0) goto LAB_0007370e;
LAB_000736ee:
    ctx->md = md;
    if (pvVar8 == (void *)0x0) {
LAB_00073768:
      puVar9 = &ctx->key_length;
      puVar6 = auStack_ac;
      puVar3 = puVar9;
      do {
        puVar3 = puVar3 + 1;
        puVar7 = puVar6 + 1;
        *puVar6 = *puVar3 ^ 0x36363636;
        puVar6 = puVar7;
      } while (puVar7 != local_2c);
      iVar1 = EVP_DigestInit_ex(&ctx->i_ctx,md,(ENGINE *)0x0);
      if (iVar1 != 0) {
        sVar2 = EVP_MD_block_size(md);
        iVar1 = EVP_DigestUpdate(&ctx->i_ctx,auStack_ac,sVar2);
        if (iVar1 != 0) {
          puVar3 = auStack_ac;
          do {
            puVar9 = puVar9 + 1;
            puVar6 = puVar3 + 1;
            *puVar3 = *puVar9 ^ 0x5c5c5c5c;
            puVar3 = puVar6;
          } while (puVar6 != local_2c);
          iVar1 = EVP_DigestInit_ex(&ctx->o_ctx,md,(ENGINE *)0x0);
          if (iVar1 != 0) {
            sVar2 = EVP_MD_block_size(md);
            iVar1 = EVP_DigestUpdate(&ctx->o_ctx,auStack_ac,sVar2);
            if (iVar1 != 0) goto LAB_000737ee;
          }
        }
      }
    }
    else {
LAB_000736f8:
      iVar1 = EVP_MD_block_size(md);
      if (0x80 < iVar1) {
        OpenSSLDie("hmac.c",0x6a,"j <= (int)sizeof(ctx->key)");
      }
      if (iVar1 < len) {
        ctx_00 = &ctx->md_ctx;
        iVar1 = EVP_DigestInit_ex(ctx_00,md,(ENGINE *)0x0);
        if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx_00,key,len), iVar1 != 0)) &&
           (iVar1 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar1 != 0)) {
          len = ctx->key_length;
          goto LAB_00073754;
        }
      }
      else if ((uint)len < 0x81) {
        memcpy(ctx->key,key,len);
        ctx->key_length = len;
LAB_00073754:
        if (len != 0x80) {
          memset(ctx->key + len,0,0x80 - len);
        }
        goto LAB_00073768;
      }
    }
LAB_0007370e:
    iVar1 = 0;
  }
  if (local_2c[0] != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

