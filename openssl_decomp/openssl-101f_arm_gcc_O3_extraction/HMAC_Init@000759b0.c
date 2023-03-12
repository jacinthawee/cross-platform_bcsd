
int HMAC_Init(HMAC_CTX *ctx,void *key,int len,EVP_MD *md)

{
  int iVar1;
  size_t sVar2;
  EVP_MD *pEVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  void *pvVar7;
  EVP_MD_CTX *ctx_00;
  uint *puVar8;
  uint auStack_ac [32];
  uint local_2c [2];
  
  pvVar7 = key;
  if (key != (void *)0x0) {
    pvVar7 = (void *)0x1;
  }
  pEVar3 = md;
  if (md != (EVP_MD *)0x0) {
    pEVar3 = (EVP_MD *)0x1;
  }
  local_2c[0] = __TMC_END__;
  if (((uint)pvVar7 & (uint)pEVar3) == 0) {
    if (pEVar3 != (EVP_MD *)0x0) goto LAB_000759e4;
    md = ctx->md;
    if (pvVar7 != (void *)0x0) goto LAB_000759ee;
LAB_00075b2c:
    iVar1 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    EVP_MD_CTX_init(&ctx->i_ctx);
    EVP_MD_CTX_init(&ctx->o_ctx);
    EVP_MD_CTX_init(&ctx->md_ctx);
LAB_000759e4:
    ctx->md = md;
    if (pvVar7 == (void *)0x0) {
LAB_00075a2c:
      puVar8 = &ctx->key_length;
      puVar5 = auStack_ac;
      puVar4 = puVar8;
      do {
        puVar4 = puVar4 + 1;
        puVar6 = puVar5 + 1;
        *puVar5 = *puVar4 ^ 0x36363636;
        puVar5 = puVar6;
      } while (puVar6 != local_2c);
      iVar1 = EVP_DigestInit_ex(&ctx->i_ctx,md,(ENGINE *)0x0);
      if (iVar1 != 0) {
        sVar2 = EVP_MD_block_size(md);
        iVar1 = EVP_DigestUpdate(&ctx->i_ctx,auStack_ac,sVar2);
        if (iVar1 != 0) {
          puVar4 = auStack_ac;
          do {
            puVar8 = puVar8 + 1;
            puVar5 = puVar4 + 1;
            *puVar4 = *puVar8 ^ 0x5c5c5c5c;
            puVar4 = puVar5;
          } while (puVar5 != local_2c);
          iVar1 = EVP_DigestInit_ex(&ctx->o_ctx,md,(ENGINE *)0x0);
          if (iVar1 != 0) {
            sVar2 = EVP_MD_block_size(md);
            iVar1 = EVP_DigestUpdate(&ctx->o_ctx,auStack_ac,sVar2);
            if (iVar1 != 0) goto LAB_00075b2c;
          }
        }
      }
    }
    else {
LAB_000759ee:
      iVar1 = EVP_MD_block_size(md);
      if (iVar1 < 0x81) {
        if (iVar1 < len) goto LAB_00075ab4;
LAB_000759fe:
        if (0x80 < (uint)len) {
          OpenSSLDie("hmac.c",0x75,"len>=0 && len<=(int)sizeof(ctx->key)");
        }
        memcpy(ctx->key,key,len);
        ctx->key_length = len;
LAB_00075a18:
        if (len != 0x80) {
          memset(ctx->key + len,0,0x80 - len);
        }
        goto LAB_00075a2c;
      }
      OpenSSLDie("hmac.c",0x68,"j <= (int)sizeof(ctx->key)");
      if (len <= iVar1) goto LAB_000759fe;
LAB_00075ab4:
      ctx_00 = &ctx->md_ctx;
      iVar1 = EVP_DigestInit_ex(ctx_00,md,(ENGINE *)0x0);
      if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx_00,key,len), iVar1 != 0)) &&
         (iVar1 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar1 != 0)) {
        len = ctx->key_length;
        goto LAB_00075a18;
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

