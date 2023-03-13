
int EVP_EncryptInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,uchar *key,uchar *iv)

{
  int iVar1;
  ENGINE *e;
  EVP_CIPHER *pEVar2;
  ulong uVar3;
  void *pvVar4;
  size_t sVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  int line;
  
  bVar8 = 0;
  if (cipher == (EVP_CIPHER *)0x0) {
    pEVar2 = ctx->cipher;
    ctx->encrypt = 1;
    if (pEVar2 == (EVP_CIPHER *)0x0) {
      line = 0xc2;
      iVar1 = 0x83;
      goto LAB_08126ce0;
    }
LAB_08126aa5:
    if (((pEVar2->block_size - 8U & 0xfffffff7) != 0) && (pEVar2->block_size != 1)) {
      OpenSSLDie("evp_enc.c",0xcf,
                 "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                );
    }
    uVar3 = EVP_CIPHER_CTX_flags(ctx);
    if ((uVar3 & 0x10) != 0) goto switchD_08126b42_caseD_0;
    uVar3 = EVP_CIPHER_CTX_flags(ctx);
    switch(uVar3 & 0xf0007) {
    case 0:
    case 1:
      break;
    case 3:
    case 4:
      ctx->num = 0;
    case 2:
      iVar1 = EVP_CIPHER_CTX_iv_length(ctx);
      if (0x10 < iVar1) {
        OpenSSLDie("evp_enc.c",0xe1,"EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)");
      }
      if (iv != (uchar *)0x0) {
        sVar5 = EVP_CIPHER_CTX_iv_length(ctx);
        memcpy(ctx->oiv,iv,sVar5);
      }
      sVar5 = EVP_CIPHER_CTX_iv_length(ctx);
      memcpy(ctx->iv,ctx->oiv,sVar5);
      break;
    case 5:
      ctx->num = 0;
      if (iv != (uchar *)0x0) {
        sVar5 = EVP_CIPHER_CTX_iv_length(ctx);
        memcpy(ctx->iv,iv,sVar5);
      }
      break;
    default:
      goto switchD_08126b42_caseD_6;
    }
switchD_08126b42_caseD_0:
    pEVar2 = ctx->cipher;
    if ((key != (uchar *)0x0) || ((*(byte *)&pEVar2->flags & 0x20) != 0)) {
      iVar1 = (*pEVar2->init)(ctx,key,iv,1);
      if (iVar1 == 0) {
        return 0;
      }
      pEVar2 = ctx->cipher;
    }
    iVar1 = pEVar2->block_size;
    ctx->buf_len = 0;
    ctx->final_used = 0;
    ctx->block_mask = iVar1 + -1;
    iVar1 = 1;
  }
  else {
    ctx->cipher = (EVP_CIPHER *)0x0;
    *(undefined4 *)(ctx->final + 0x1c) = 0;
    puVar7 = (undefined4 *)((uint)&ctx->engine & 0xfffffffc);
    uVar6 = (uint)((int)ctx + (0x8c - (int)puVar7)) >> 2;
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    ctx->encrypt = 1;
    if (ctx->engine == (ENGINE *)0x0) {
      pEVar2 = ctx->cipher;
      if (pEVar2 != (EVP_CIPHER *)0x0) goto LAB_081269b7;
    }
    else {
      pEVar2 = ctx->cipher;
      if (pEVar2 != (EVP_CIPHER *)0x0) {
        if (cipher->nid == pEVar2->nid) goto LAB_08126aa5;
LAB_081269b7:
        uVar3 = ctx->flags;
        if ((pEVar2->cleanup == (_func_1091 *)0x0) || (iVar1 = (*pEVar2->cleanup)(ctx), iVar1 != 0))
        {
          if (ctx->cipher_data != (void *)0x0) {
            OPENSSL_cleanse(ctx->cipher_data,ctx->cipher->ctx_size);
            if (ctx->cipher_data != (void *)0x0) {
              CRYPTO_free(ctx->cipher_data);
            }
          }
          if (ctx->engine != (ENGINE *)0x0) {
            ENGINE_finish(ctx->engine);
          }
          puVar7 = (undefined4 *)((uint)&ctx->engine & 0xfffffffc);
          ctx->cipher = (EVP_CIPHER *)0x0;
          *(undefined4 *)(ctx->final + 0x1c) = 0;
          uVar6 = (uint)((int)ctx + (0x8c - (int)puVar7)) >> 2;
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
          }
        }
        ctx->encrypt = 1;
        ctx->flags = uVar3;
      }
    }
    e = ENGINE_get_cipher_engine(cipher->nid);
    if (e == (ENGINE *)0x0) {
      iVar1 = cipher->ctx_size;
      ctx->engine = (ENGINE *)0x0;
      ctx->cipher = cipher;
      pEVar2 = cipher;
      if (iVar1 == 0) goto LAB_08126a85;
LAB_08126ba4:
      pvVar4 = CRYPTO_malloc(iVar1,"evp_enc.c",0xb1);
      ctx->cipher_data = pvVar4;
      if (pvVar4 == (void *)0x0) {
        line = 0xb3;
        iVar1 = 0x41;
        goto LAB_08126ce0;
      }
      pEVar2 = ctx->cipher;
LAB_08126a8e:
      bVar8 = *(byte *)&pEVar2->flags;
      iVar1 = cipher->key_len;
      ctx->flags = 0;
      ctx->key_len = iVar1;
      if ((bVar8 & 0x40) == 0) goto LAB_08126aa5;
      if (pEVar2->ctrl == (_func_1094 *)0x0) {
        ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x25a);
      }
      else {
        iVar1 = (*pEVar2->ctrl)(ctx,0,0,(void *)0x0);
        if (iVar1 == -1) {
          ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x261);
        }
        else if (iVar1 != 0) {
          pEVar2 = ctx->cipher;
          goto LAB_08126aa5;
        }
      }
      line = 0xbd;
    }
    else {
      cipher = ENGINE_get_cipher(e,cipher->nid);
      if (cipher != (EVP_CIPHER *)0x0) {
        iVar1 = cipher->ctx_size;
        ctx->engine = e;
        ctx->cipher = cipher;
        pEVar2 = cipher;
        if (iVar1 != 0) goto LAB_08126ba4;
LAB_08126a85:
        ctx->cipher_data = (void *)0x0;
        cipher = pEVar2;
        goto LAB_08126a8e;
      }
      line = 0x9d;
    }
    iVar1 = 0x86;
LAB_08126ce0:
    ERR_put_error(6,0x7b,iVar1,"evp_enc.c",line);
switchD_08126b42_caseD_6:
    iVar1 = 0;
  }
  return iVar1;
}

