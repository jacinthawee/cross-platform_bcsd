
int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv,
                     int enc)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  EVP_CIPHER *pEVar4;
  ulong uVar5;
  
  if (enc == -1) {
    enc = ctx->encrypt;
  }
  else {
    if (enc != 0) {
      enc = 1;
    }
    ctx->encrypt = enc;
  }
  pEVar4 = ctx->cipher;
  if (ctx->engine == (ENGINE *)0x0) {
    if (cipher == (EVP_CIPHER *)0x0) {
      if (pEVar4 == (EVP_CIPHER *)0x0) goto LAB_000a9024;
      goto LAB_000a8f02;
    }
    if (pEVar4 != (EVP_CIPHER *)0x0) goto LAB_000a8e88;
  }
  else if (pEVar4 == (EVP_CIPHER *)0x0) {
    if (cipher == (EVP_CIPHER *)0x0) {
LAB_000a9024:
      ERR_put_error(6,0x7b,0x83,"evp_enc.c",0xcb);
      return 0;
    }
  }
  else {
    if ((cipher == (EVP_CIPHER *)0x0) || (cipher->nid == pEVar4->nid)) goto LAB_000a8f02;
LAB_000a8e88:
    uVar5 = ctx->flags;
    if ((pEVar4->cleanup == (_func_1091 *)0x0) || (iVar1 = (*pEVar4->cleanup)(ctx), iVar1 != 0)) {
      if (ctx->cipher_data != (void *)0x0) {
        OPENSSL_cleanse(ctx->cipher_data,ctx->cipher->ctx_size);
        if (ctx->cipher_data != (void *)0x0) {
          CRYPTO_free(ctx->cipher_data);
        }
      }
      if (ctx->engine != (ENGINE *)0x0) {
        ENGINE_finish(ctx->engine);
      }
      memset(ctx,0,0x8c);
    }
    ctx->encrypt = enc;
    ctx->flags = uVar5;
  }
  if (impl == (ENGINE *)0x0) {
    impl = ENGINE_get_cipher_engine(cipher->nid);
    if (impl != (ENGINE *)0x0) goto LAB_000a8ed4;
  }
  else {
    iVar1 = ENGINE_init(impl);
    if (iVar1 == 0) {
      ERR_put_error(6,0x7b,0x86,"evp_enc.c",0x8d);
      return 0;
    }
LAB_000a8ed4:
    cipher = ENGINE_get_cipher(impl,cipher->nid);
    if (cipher == (EVP_CIPHER *)0x0) {
      ERR_put_error(6,0x7b,0x86,"evp_enc.c",0x9e);
      return 0;
    }
  }
  iVar1 = cipher->ctx_size;
  ctx->engine = impl;
  ctx->cipher = cipher;
  if (iVar1 == 0) {
    ctx->cipher_data = (void *)0x0;
    pEVar4 = cipher;
  }
  else {
    pvVar2 = CRYPTO_malloc(iVar1,"evp_enc.c",0xb3);
    ctx->cipher_data = pvVar2;
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(6,0x7b,0x41,"evp_enc.c",0xb6);
      return 0;
    }
    pEVar4 = ctx->cipher;
  }
  uVar5 = pEVar4->flags;
  iVar1 = cipher->key_len;
  ctx->flags = 0;
  ctx->key_len = iVar1;
  if (-1 < (int)(uVar5 << 0x19)) {
LAB_000a8f02:
    iVar1 = pEVar4->block_size;
    if ((iVar1 == 1 || iVar1 == 8) || (iVar1 == 0x10)) {
      uVar5 = EVP_CIPHER_CTX_flags(ctx);
    }
    else {
      OpenSSLDie("evp_enc.c",0xd8,
                 "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                );
      uVar5 = EVP_CIPHER_CTX_flags(ctx);
    }
    if (-1 < (int)(uVar5 << 0x1b)) {
      uVar5 = EVP_CIPHER_CTX_flags(ctx);
      switch(uVar5 & 0xf0007) {
      case 0:
      case 1:
        break;
      case 3:
      case 4:
        ctx->num = 0;
      case 2:
        iVar1 = EVP_CIPHER_CTX_iv_length(ctx);
        if (0x10 < iVar1) {
          OpenSSLDie("evp_enc.c",0xea,"EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)");
        }
        if (iv != (uchar *)0x0) {
          sVar3 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->oiv,iv,sVar3);
        }
        sVar3 = EVP_CIPHER_CTX_iv_length(ctx);
        memcpy(ctx->iv,ctx->oiv,sVar3);
        break;
      case 5:
        ctx->num = 0;
        if (iv != (uchar *)0x0) {
          sVar3 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->iv,iv,sVar3);
        }
        break;
      default:
        return 0;
      }
    }
    pEVar4 = ctx->cipher;
    if ((key != (uchar *)0x0) || ((int)(pEVar4->flags << 0x1a) < 0)) {
      iVar1 = (*pEVar4->init)(ctx,key,iv,enc);
      if (iVar1 == 0) {
        return 0;
      }
      pEVar4 = ctx->cipher;
    }
    iVar1 = pEVar4->block_size;
    ctx->buf_len = 0;
    ctx->final_used = 0;
    ctx->block_mask = iVar1 + -1;
    return 1;
  }
  if (pEVar4->ctrl == (_func_1094 *)0x0) {
    ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x272);
  }
  else {
    iVar1 = (*pEVar4->ctrl)(ctx,0,0,(void *)0x0);
    if (iVar1 == -1) {
      ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x278);
    }
    else if (iVar1 != 0) {
      pEVar4 = ctx->cipher;
      goto LAB_000a8f02;
    }
  }
  ERR_put_error(6,0x7b,0x86,"evp_enc.c",0xc4);
  return 0;
}

