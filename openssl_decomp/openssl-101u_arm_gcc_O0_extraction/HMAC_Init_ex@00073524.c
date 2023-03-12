
int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  EVP_MD_CTX *ctx_00;
  uint *puVar7;
  uint auStack_ac [32];
  uint local_2c [2];
  
  local_2c[0] = __stack_chk_guard;
  if (md == (EVP_MD *)0x0) {
    md = ctx->md;
    if (md != (EVP_MD *)0x0) {
      if (key != (void *)0x0) goto LAB_0007356a;
LAB_00073696:
      iVar1 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      goto LAB_00073580;
    }
  }
  else if ((ctx->md == md) ||
          (uVar3 = count_leading_zeroes(key), (uVar3 >> 5 | (uint)len >> 0x1f) == 0)) {
    ctx->md = md;
    if (key == (void *)0x0) {
LAB_000735ba:
      puVar7 = &ctx->key_length;
      puVar5 = auStack_ac;
      puVar4 = puVar7;
      do {
        puVar4 = puVar4 + 1;
        puVar6 = puVar5 + 1;
        *puVar5 = *puVar4 ^ 0x36363636;
        puVar5 = puVar6;
      } while (puVar6 != local_2c);
      iVar1 = EVP_DigestInit_ex(&ctx->i_ctx,md,impl);
      if (iVar1 != 0) {
        sVar2 = EVP_MD_block_size(md);
        iVar1 = EVP_DigestUpdate(&ctx->i_ctx,auStack_ac,sVar2);
        if (iVar1 != 0) {
          puVar4 = auStack_ac;
          do {
            puVar7 = puVar7 + 1;
            puVar5 = puVar4 + 1;
            *puVar4 = *puVar7 ^ 0x5c5c5c5c;
            puVar4 = puVar5;
          } while (puVar5 != local_2c);
          iVar1 = EVP_DigestInit_ex(&ctx->o_ctx,md,impl);
          if (iVar1 != 0) {
            sVar2 = EVP_MD_block_size(md);
            iVar1 = EVP_DigestUpdate(&ctx->o_ctx,auStack_ac,sVar2);
            if (iVar1 != 0) goto LAB_00073696;
          }
        }
      }
    }
    else {
LAB_0007356a:
      iVar1 = EVP_MD_block_size(md);
      if (0x80 < iVar1) {
        OpenSSLDie("hmac.c",0x6a,"j <= (int)sizeof(ctx->key)");
      }
      if (iVar1 < len) {
        ctx_00 = &ctx->md_ctx;
        iVar1 = EVP_DigestInit_ex(ctx_00,md,impl);
        if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx_00,key,len), iVar1 != 0)) &&
           (iVar1 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar1 != 0)) {
          len = ctx->key_length;
          goto LAB_000735a6;
        }
      }
      else if ((uint)len < 0x81) {
        memcpy(ctx->key,key,len);
        ctx->key_length = len;
LAB_000735a6:
        if (len != 0x80) {
          memset(ctx->key + len,0,0x80 - len);
        }
        goto LAB_000735ba;
      }
    }
  }
  iVar1 = 0;
LAB_00073580:
  if (local_2c[0] != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

