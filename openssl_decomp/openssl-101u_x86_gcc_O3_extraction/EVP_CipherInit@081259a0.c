
int EVP_CipherInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,uchar *key,uchar *iv,int enc)

{
  int iVar1;
  ENGINE *e;
  EVP_CIPHER *pEVar2;
  ulong uVar3;
  size_t sVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte bVar9;
  int line;
  
  bVar9 = 0;
  if (cipher != (EVP_CIPHER *)0x0) {
    ctx->cipher = (EVP_CIPHER *)0x0;
    *(undefined4 *)(ctx->final + 0x1c) = 0;
    puVar8 = (undefined4 *)((uint)&ctx->engine & 0xfffffffc);
    uVar6 = (uint)((int)ctx + (0x8c - (int)puVar8)) >> 2;
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
  }
  if (enc == -1) {
    uVar6 = ctx->encrypt;
    pEVar2 = ctx->cipher;
    if (ctx->engine == (ENGINE *)0x0) goto LAB_08125ba0;
LAB_08125a00:
    if (pEVar2 != (EVP_CIPHER *)0x0) {
      if ((cipher != (EVP_CIPHER *)0x0) && (cipher->nid != pEVar2->nid)) {
LAB_08125a1b:
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
          ctx->cipher = (EVP_CIPHER *)0x0;
          *(undefined4 *)(ctx->final + 0x1c) = 0;
          puVar8 = (undefined4 *)((uint)&ctx->engine & 0xfffffffc);
          uVar7 = (uint)((int)ctx + (0x8c - (int)puVar8)) >> 2;
          for (; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar8 = 0;
            puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
          }
        }
        ctx->encrypt = uVar6;
        ctx->flags = uVar3;
        goto LAB_08125aa5;
      }
      goto LAB_08125b06;
    }
    if (cipher == (EVP_CIPHER *)0x0) {
LAB_08125d08:
      line = 0xc2;
      iVar1 = 0x83;
    }
    else {
LAB_08125aa5:
      e = ENGINE_get_cipher_engine(cipher->nid);
      if (e == (ENGINE *)0x0) {
        iVar1 = cipher->ctx_size;
        ctx->engine = (ENGINE *)0x0;
        ctx->cipher = cipher;
joined_r0x08125ae0:
        if (iVar1 == 0) {
          ctx->cipher_data = (void *)0x0;
          pEVar2 = cipher;
        }
        else {
          pvVar5 = CRYPTO_malloc(iVar1,"evp_enc.c",0xb1);
          ctx->cipher_data = pvVar5;
          if (pvVar5 == (void *)0x0) {
            line = 0xb3;
            iVar1 = 0x41;
            goto LAB_08125d50;
          }
          pEVar2 = ctx->cipher;
        }
        bVar9 = *(byte *)&pEVar2->flags;
        iVar1 = cipher->key_len;
        ctx->flags = 0;
        ctx->key_len = iVar1;
        if ((bVar9 & 0x40) == 0) goto LAB_08125b06;
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
            goto LAB_08125b06;
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
          goto joined_r0x08125ae0;
        }
        line = 0x9d;
      }
      iVar1 = 0x86;
    }
LAB_08125d50:
    ERR_put_error(6,0x7b,iVar1,"evp_enc.c",line);
switchD_08125bd2_caseD_6:
    iVar1 = 0;
  }
  else {
    uVar6 = (uint)(enc != 0);
    ctx->encrypt = uVar6;
    pEVar2 = ctx->cipher;
    if (ctx->engine != (ENGINE *)0x0) goto LAB_08125a00;
LAB_08125ba0:
    if (cipher != (EVP_CIPHER *)0x0) {
      if (pEVar2 != (EVP_CIPHER *)0x0) goto LAB_08125a1b;
      goto LAB_08125aa5;
    }
    if (pEVar2 == (EVP_CIPHER *)0x0) goto LAB_08125d08;
LAB_08125b06:
    if (((pEVar2->block_size - 8U & 0xfffffff7) != 0) && (pEVar2->block_size != 1)) {
      OpenSSLDie("evp_enc.c",0xcf,
                 "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                );
    }
    uVar3 = EVP_CIPHER_CTX_flags(ctx);
    if ((uVar3 & 0x10) == 0) {
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
          sVar4 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->oiv,iv,sVar4);
        }
        sVar4 = EVP_CIPHER_CTX_iv_length(ctx);
        memcpy(ctx->iv,ctx->oiv,sVar4);
        break;
      case 5:
        ctx->num = 0;
        if (iv != (uchar *)0x0) {
          sVar4 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->iv,iv,sVar4);
        }
        break;
      default:
        goto switchD_08125bd2_caseD_6;
      }
    }
    pEVar2 = ctx->cipher;
    if ((key != (uchar *)0x0) || ((*(byte *)&pEVar2->flags & 0x20) != 0)) {
      iVar1 = (*pEVar2->init)(ctx,key,iv,uVar6);
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
  return iVar1;
}

