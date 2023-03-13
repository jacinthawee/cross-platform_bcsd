
int EVP_DecryptInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv)

{
  _func_1091 **pp_Var1;
  int iVar2;
  EVP_CIPHER *pEVar3;
  ulong uVar4;
  void *pvVar5;
  size_t sVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte bVar9;
  int line;
  
  bVar9 = 0;
  ctx->encrypt = 0;
  pEVar3 = ctx->cipher;
  if (ctx->engine == (ENGINE *)0x0) {
    if (cipher == (EVP_CIPHER *)0x0) {
      if (pEVar3 != (EVP_CIPHER *)0x0) goto LAB_081276e3;
LAB_08127840:
      line = 0xc2;
      iVar2 = 0x83;
    }
    else {
      if (pEVar3 != (EVP_CIPHER *)0x0) {
LAB_081275f1:
        pp_Var1 = &pEVar3->cleanup;
        pEVar3 = (EVP_CIPHER *)ctx->flags;
        if ((*pp_Var1 == (_func_1091 *)0x0) || (iVar2 = (**pp_Var1)(ctx), iVar2 != 0)) {
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
        ctx->encrypt = 0;
        ctx->flags = (ulong)pEVar3;
      }
LAB_0812767f:
      if (impl == (ENGINE *)0x0) {
        impl = ENGINE_get_cipher_engine(cipher->nid);
        if (impl != (ENGINE *)0x0) goto LAB_0812769b;
        ctx->engine = (ENGINE *)0x0;
LAB_081276b6:
        iVar2 = cipher->ctx_size;
        ctx->cipher = cipher;
        if (iVar2 == 0) {
          ctx->cipher_data = (void *)0x0;
          pEVar3 = cipher;
        }
        else {
          pvVar5 = CRYPTO_malloc(iVar2,"evp_enc.c",0xb1);
          ctx->cipher_data = pvVar5;
          if (pvVar5 == (void *)0x0) {
            line = 0xb3;
            iVar2 = 0x41;
            goto LAB_08127858;
          }
          pEVar3 = ctx->cipher;
        }
        bVar9 = *(byte *)&pEVar3->flags;
        iVar2 = cipher->key_len;
        ctx->flags = 0;
        ctx->key_len = iVar2;
        if ((bVar9 & 0x40) == 0) goto LAB_081276e3;
        if (pEVar3->ctrl == (_func_1094 *)0x0) {
          ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x25a);
        }
        else {
          iVar2 = (*pEVar3->ctrl)(ctx,0,0,(void *)0x0);
          if (iVar2 == -1) {
            ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x261);
          }
          else if (iVar2 != 0) {
            pEVar3 = ctx->cipher;
            goto LAB_081276e3;
          }
        }
        line = 0xbd;
      }
      else {
        iVar2 = ENGINE_init((ENGINE *)pEVar3);
        if (iVar2 == 0) {
          ERR_put_error(6,0x7b,0x86,"evp_enc.c",0x8e);
          return 0;
        }
LAB_0812769b:
        cipher = ENGINE_get_cipher(impl,cipher->nid);
        if (cipher != (EVP_CIPHER *)0x0) {
          ctx->engine = impl;
          goto LAB_081276b6;
        }
        line = 0x9d;
      }
      iVar2 = 0x86;
    }
LAB_08127858:
    ERR_put_error(6,0x7b,iVar2,"evp_enc.c",line);
switchD_08127782_caseD_6:
    iVar2 = 0;
  }
  else {
    if (pEVar3 == (EVP_CIPHER *)0x0) {
      if (cipher == (EVP_CIPHER *)0x0) goto LAB_08127840;
      goto LAB_0812767f;
    }
    if ((cipher != (EVP_CIPHER *)0x0) && (cipher->nid != pEVar3->nid)) goto LAB_081275f1;
LAB_081276e3:
    if (((pEVar3->block_size - 8U & 0xfffffff7) != 0) && (pEVar3->block_size != 1)) {
      OpenSSLDie("evp_enc.c",0xcf,
                 "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                );
    }
    uVar4 = EVP_CIPHER_CTX_flags(ctx);
    if ((uVar4 & 0x10) == 0) {
      uVar4 = EVP_CIPHER_CTX_flags(ctx);
      switch(uVar4 & 0xf0007) {
      case 0:
      case 1:
        break;
      case 3:
      case 4:
        ctx->num = 0;
      case 2:
        iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
        if (0x10 < iVar2) {
          OpenSSLDie("evp_enc.c",0xe1,"EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)");
        }
        if (iv != (uchar *)0x0) {
          sVar6 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->oiv,iv,sVar6);
        }
        sVar6 = EVP_CIPHER_CTX_iv_length(ctx);
        memcpy(ctx->iv,ctx->oiv,sVar6);
        break;
      case 5:
        ctx->num = 0;
        if (iv != (uchar *)0x0) {
          sVar6 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->iv,iv,sVar6);
        }
        break;
      default:
        goto switchD_08127782_caseD_6;
      }
    }
    pEVar3 = ctx->cipher;
    if ((key != (uchar *)0x0) || ((*(byte *)&pEVar3->flags & 0x20) != 0)) {
      iVar2 = (*pEVar3->init)(ctx,key,iv,0);
      if (iVar2 == 0) {
        return 0;
      }
      pEVar3 = ctx->cipher;
    }
    iVar2 = pEVar3->block_size;
    ctx->buf_len = 0;
    ctx->final_used = 0;
    ctx->block_mask = iVar2 + -1;
    iVar2 = 1;
  }
  return iVar2;
}

