
int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv,
                     int enc)

{
  uint enc_00;
  int iVar1;
  EVP_CIPHER *pEVar2;
  ulong uVar3;
  void *pvVar4;
  size_t sVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  int reason;
  
  bVar8 = 0;
  if (enc == -1) {
    enc_00 = ctx->encrypt;
    pEVar2 = ctx->cipher;
    if (ctx->engine != (ENGINE *)0x0) goto LAB_08128716;
LAB_081288c0:
    if (cipher != (EVP_CIPHER *)0x0) {
      if (pEVar2 != (EVP_CIPHER *)0x0) {
LAB_08128730:
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
          puVar7 = (undefined4 *)((uint)&ctx->engine & 0xfffffffc);
          uVar6 = (uint)((int)ctx + (0x8c - (int)puVar7)) >> 2;
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
          }
        }
        ctx->encrypt = enc_00;
        ctx->flags = uVar3;
      }
      goto LAB_081287ba;
    }
    if (pEVar2 != (EVP_CIPHER *)0x0) goto LAB_0812882c;
LAB_081289b0:
    iVar1 = 0xcb;
    reason = 0x83;
LAB_081289c8:
    ERR_put_error(6,0x7b,reason,"evp_enc.c",iVar1);
switchD_081288f2_caseD_6:
    iVar1 = 0;
  }
  else {
    enc_00 = (uint)(enc != 0);
    ctx->encrypt = enc_00;
    pEVar2 = ctx->cipher;
    if (ctx->engine == (ENGINE *)0x0) goto LAB_081288c0;
LAB_08128716:
    if (pEVar2 != (EVP_CIPHER *)0x0) {
      if ((cipher != (EVP_CIPHER *)0x0) && (cipher->nid != pEVar2->nid)) goto LAB_08128730;
      goto LAB_0812882c;
    }
    if (cipher == (EVP_CIPHER *)0x0) goto LAB_081289b0;
LAB_081287ba:
    if (impl != (ENGINE *)0x0) {
      iVar1 = ENGINE_init(impl);
      if (iVar1 == 0) {
        ERR_put_error(6,0x7b,0x86,"evp_enc.c",0x8d);
        return 0;
      }
LAB_081287dd:
      cipher = ENGINE_get_cipher(impl,cipher->nid);
      if (cipher != (EVP_CIPHER *)0x0) {
        ctx->engine = impl;
        goto LAB_081287ff;
      }
      iVar1 = 0x9e;
LAB_08128ade:
      reason = 0x86;
      goto LAB_081289c8;
    }
    impl = ENGINE_get_cipher_engine(cipher->nid);
    if (impl != (ENGINE *)0x0) goto LAB_081287dd;
    ctx->engine = (ENGINE *)0x0;
LAB_081287ff:
    iVar1 = cipher->ctx_size;
    ctx->cipher = cipher;
    if (iVar1 == 0) {
      ctx->cipher_data = (void *)0x0;
      pEVar2 = cipher;
    }
    else {
      pvVar4 = CRYPTO_malloc(iVar1,"evp_enc.c",0xb3);
      ctx->cipher_data = pvVar4;
      if (pvVar4 == (void *)0x0) {
        iVar1 = 0xb6;
        reason = 0x41;
        goto LAB_081289c8;
      }
      pEVar2 = ctx->cipher;
    }
    bVar8 = *(byte *)&pEVar2->flags;
    iVar1 = cipher->key_len;
    ctx->flags = 0;
    ctx->key_len = iVar1;
    if ((bVar8 & 0x40) != 0) {
      if (pEVar2->ctrl == (_func_1094 *)0x0) {
        ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x272);
      }
      else {
        iVar1 = (*pEVar2->ctrl)(ctx,0,0,(void *)0x0);
        if (iVar1 == -1) {
          ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x278);
        }
        else if (iVar1 != 0) {
          pEVar2 = ctx->cipher;
          goto LAB_0812882c;
        }
      }
      iVar1 = 0xc4;
      goto LAB_08128ade;
    }
LAB_0812882c:
    if (((pEVar2->block_size - 8U & 0xfffffff7) != 0) && (pEVar2->block_size != 1)) {
      OpenSSLDie("evp_enc.c",0xd8,
                 "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                );
    }
    uVar3 = EVP_CIPHER_CTX_flags(ctx);
    if ((uVar3 & 0x10) != 0) goto switchD_081288f2_caseD_0;
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
        OpenSSLDie("evp_enc.c",0xea,"EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)");
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
      goto switchD_081288f2_caseD_6;
    }
switchD_081288f2_caseD_0:
    pEVar2 = ctx->cipher;
    if ((key != (uchar *)0x0) || ((*(byte *)&pEVar2->flags & 0x20) != 0)) {
      iVar1 = (*pEVar2->init)(ctx,key,iv,enc_00);
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

