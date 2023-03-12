
int EVP_CipherInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,uchar *key,uchar *iv,int enc)

{
  int iVar1;
  ENGINE *e;
  size_t sVar2;
  void *pvVar3;
  int iVar4;
  EVP_CIPHER *pEVar5;
  ulong uVar6;
  
  if (cipher != (EVP_CIPHER *)0x0) {
    memset(ctx,0,0x8c);
  }
  if (enc == -1) {
    enc = ctx->encrypt;
  }
  else {
    if (enc != 0) {
      enc = 1;
    }
    ctx->encrypt = enc;
  }
  pEVar5 = ctx->cipher;
  if (ctx->engine == (ENGINE *)0x0) {
    if (cipher == (EVP_CIPHER *)0x0) {
      if (pEVar5 == (EVP_CIPHER *)0x0) {
LAB_000a61ec:
        ERR_put_error(6,0x7b,0x83,"evp_enc.c",0xc2);
        return 0;
      }
      goto LAB_000a60a4;
    }
    if (pEVar5 != (EVP_CIPHER *)0x0) {
LAB_000a6032:
      uVar6 = ctx->flags;
      if ((pEVar5->cleanup == (_func_1091 *)0x0) || (iVar1 = (*pEVar5->cleanup)(ctx), iVar1 != 0)) {
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
      ctx->flags = uVar6;
    }
LAB_000a6068:
    e = ENGINE_get_cipher_engine(cipher->nid);
    if (e == (ENGINE *)0x0) {
LAB_000a6086:
      iVar1 = cipher->ctx_size;
      ctx->engine = e;
      ctx->cipher = cipher;
      if (iVar1 == 0) {
        ctx->cipher_data = (void *)0x0;
        pEVar5 = cipher;
      }
      else {
        pvVar3 = CRYPTO_malloc(iVar1,"evp_enc.c",0xb1);
        ctx->cipher_data = pvVar3;
        if (pvVar3 == (void *)0x0) {
          ERR_put_error(6,0x7b,0x41,"evp_enc.c",0xb3);
          return 0;
        }
        pEVar5 = ctx->cipher;
      }
      uVar6 = pEVar5->flags;
      iVar1 = cipher->key_len;
      ctx->flags = 0;
      ctx->key_len = iVar1;
      if (-1 < (int)(uVar6 << 0x19)) goto LAB_000a60a4;
      if (pEVar5->ctrl == (_func_1094 *)0x0) {
        ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x25a);
LAB_000a621e:
        iVar1 = 0xbd;
        goto LAB_000a6224;
      }
      iVar1 = (*pEVar5->ctrl)(ctx,0,0,(void *)0x0);
      if (iVar1 == -1) {
        ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x261);
        goto LAB_000a621e;
      }
      if (iVar1 == 0) goto LAB_000a621e;
      iVar1 = ctx->cipher->block_size;
      if (iVar1 != 1 && iVar1 != 8) goto LAB_000a60e4;
      goto LAB_000a60ae;
    }
    cipher = ENGINE_get_cipher(e,cipher->nid);
    iVar1 = 0x9d;
    if (cipher != (EVP_CIPHER *)0x0) goto LAB_000a6086;
LAB_000a6224:
    ERR_put_error(6,0x7b,0x86,"evp_enc.c",iVar1);
switchD_000a611e_caseD_6:
    iVar1 = 0;
  }
  else {
    if (pEVar5 == (EVP_CIPHER *)0x0) {
      if (cipher == (EVP_CIPHER *)0x0) goto LAB_000a61ec;
      goto LAB_000a6068;
    }
    if ((cipher != (EVP_CIPHER *)0x0) && (cipher->nid != pEVar5->nid)) goto LAB_000a6032;
LAB_000a60a4:
    iVar1 = pEVar5->block_size;
    if (iVar1 == 1 || iVar1 == 8) {
LAB_000a60ae:
      uVar6 = EVP_CIPHER_CTX_flags(ctx);
    }
    else {
LAB_000a60e4:
      if (iVar1 == 0x10) goto LAB_000a60ae;
      OpenSSLDie("evp_enc.c",0xcf,
                 "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                );
      uVar6 = EVP_CIPHER_CTX_flags(ctx);
    }
    if (-1 < (int)(uVar6 << 0x1b)) {
      uVar6 = EVP_CIPHER_CTX_flags(ctx);
      switch(uVar6 & 0xf0007) {
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
          sVar2 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->oiv,iv,sVar2);
        }
        sVar2 = EVP_CIPHER_CTX_iv_length(ctx);
        memcpy(ctx->iv,ctx->oiv,sVar2);
        break;
      case 5:
        ctx->num = 0;
        if (iv != (uchar *)0x0) {
          sVar2 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->iv,iv,sVar2);
        }
        break;
      default:
        goto switchD_000a611e_caseD_6;
      }
    }
    pEVar5 = ctx->cipher;
    if ((key != (uchar *)0x0) || ((int)(pEVar5->flags << 0x1a) < 0)) {
      iVar1 = (*pEVar5->init)(ctx,key,iv,enc);
      if (iVar1 == 0) {
        return 0;
      }
      pEVar5 = ctx->cipher;
    }
    iVar4 = pEVar5->block_size;
    iVar1 = 1;
    ctx->buf_len = 0;
    ctx->final_used = 0;
    ctx->block_mask = iVar4 + -1;
  }
  return iVar1;
}

