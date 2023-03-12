
int EVP_CipherInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,uchar *key,uchar *iv,int enc)

{
  EVP_CIPHER *pEVar1;
  int iVar2;
  ENGINE *e;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  uint enc_00;
  ulong uVar6;
  _func_1091 *p_Var7;
  _func_1089 *p_Var8;
  
  if (cipher != (EVP_CIPHER *)0x0) {
    (*(code *)PTR_memset_006aab00)(ctx,0,0x8c);
  }
  if (enc == -1) {
    enc_00 = ctx->encrypt;
    if (ctx->engine != (ENGINE *)0x0) goto LAB_00536360;
LAB_00536598:
    pEVar1 = ctx->cipher;
    if (cipher == (EVP_CIPHER *)0x0) {
      if (pEVar1 == (EVP_CIPHER *)0x0) goto LAB_00536708;
      goto LAB_00536470;
    }
    if (pEVar1 != (EVP_CIPHER *)0x0) {
      p_Var7 = pEVar1->cleanup;
      goto LAB_00536388;
    }
LAB_00536410:
    e = ENGINE_get_cipher_engine(cipher->nid);
    if (e == (ENGINE *)0x0) {
      iVar2 = cipher->ctx_size;
      ctx->engine = (ENGINE *)0x0;
      ctx->cipher = cipher;
      pEVar1 = cipher;
      if (iVar2 == 0) goto LAB_00536450;
LAB_005366d0:
      pvVar3 = (void *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"evp_enc.c",0xb3);
      ctx->cipher_data = pvVar3;
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0x41;
        iVar2 = 0xb6;
        goto LAB_00536768;
      }
      pEVar1 = ctx->cipher;
    }
    else {
      cipher = ENGINE_get_cipher(e,cipher->nid);
      if (cipher == (EVP_CIPHER *)0x0) {
        iVar5 = 0x86;
        iVar2 = 0x9e;
LAB_00536714:
        ERR_put_error(6,0x7b,iVar5,"evp_enc.c",iVar2);
        return 0;
      }
      iVar2 = cipher->ctx_size;
      ctx->engine = e;
      ctx->cipher = cipher;
      pEVar1 = cipher;
      if (iVar2 != 0) goto LAB_005366d0;
LAB_00536450:
      ctx->cipher_data = (void *)0x0;
      cipher = pEVar1;
    }
    uVar4 = pEVar1->flags;
    iVar2 = cipher->key_len;
    ctx->flags = 0;
    ctx->key_len = iVar2;
    if ((uVar4 & 0x40) == 0) goto LAB_00536470;
    if (pEVar1->ctrl == (_func_1094 *)0x0) {
      iVar5 = 0x84;
      iVar2 = 0x272;
LAB_00536740:
      ERR_put_error(6,0x7c,iVar5,"evp_enc.c",iVar2);
LAB_00536754:
      iVar5 = 0x86;
      iVar2 = 0xc4;
LAB_00536768:
      ERR_put_error(6,0x7b,iVar5,"evp_enc.c",iVar2);
      return 0;
    }
    iVar2 = (*pEVar1->ctrl)(ctx,0,0,(void *)0x0);
    if (iVar2 == -1) {
      iVar5 = 0x85;
      iVar2 = 0x278;
      goto LAB_00536740;
    }
    if (iVar2 == 0) goto LAB_00536754;
    uVar4 = ctx->cipher->block_size;
    if (uVar4 < 0x11) goto LAB_00536484;
LAB_00536518:
    (*(code *)PTR_OpenSSLDie_006a8d4c)
              ("evp_enc.c",0xd8,
               "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
              );
    uVar4 = EVP_CIPHER_CTX_flags(ctx);
  }
  else {
    enc_00 = (uint)(enc != 0);
    ctx->encrypt = enc_00;
    if (ctx->engine == (ENGINE *)0x0) goto LAB_00536598;
LAB_00536360:
    pEVar1 = ctx->cipher;
    if (pEVar1 == (EVP_CIPHER *)0x0) {
      if (cipher == (EVP_CIPHER *)0x0) {
LAB_00536708:
        iVar5 = 0x83;
        iVar2 = 0xcb;
        goto LAB_00536714;
      }
      goto LAB_00536410;
    }
    if ((cipher != (EVP_CIPHER *)0x0) && (cipher->nid != pEVar1->nid)) {
      p_Var7 = pEVar1->cleanup;
LAB_00536388:
      uVar6 = ctx->flags;
      if ((p_Var7 == (_func_1091 *)0x0) || (iVar2 = (*p_Var7)(ctx), iVar2 != 0)) {
        if ((ctx->cipher_data != (void *)0x0) &&
           ((*(code *)PTR_OPENSSL_cleanse_006a8174)(ctx->cipher_data,ctx->cipher->ctx_size),
           ctx->cipher_data != (void *)0x0)) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
        }
        if (ctx->engine != (ENGINE *)0x0) {
          ENGINE_finish(ctx->engine);
        }
        (*(code *)PTR_memset_006aab00)(ctx,0,0x8c);
      }
      ctx->encrypt = enc_00;
      ctx->flags = uVar6;
      goto LAB_00536410;
    }
LAB_00536470:
    uVar4 = pEVar1->block_size;
    if (0x10 < uVar4) goto LAB_00536518;
LAB_00536484:
    if ((0x10102U >> (uVar4 & 0x1f) & 1) == 0) goto LAB_00536518;
    uVar4 = EVP_CIPHER_CTX_flags(ctx);
  }
  if ((uVar4 & 0x10) == 0) {
    uVar6 = EVP_CIPHER_CTX_flags(ctx);
    switch(uVar6 & 0xf0007) {
    case 0:
    case 1:
      break;
    case 3:
    case 4:
      ctx->num = 0;
    case 2:
      iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
      if (0x10 < iVar2) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)
                  ("evp_enc.c",0xea,"EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)");
      }
      if (iv != (uchar *)0x0) {
        iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
        (*(code *)PTR_memcpy_006aabf4)(ctx->oiv,iv,iVar2);
      }
      iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
      (*(code *)PTR_memcpy_006aabf4)(ctx->iv,ctx->oiv,iVar2);
      break;
    case 5:
      ctx->num = 0;
      if (iv != (uchar *)0x0) {
        iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
        (*(code *)PTR_memcpy_006aabf4)(ctx->iv,iv,iVar2);
      }
      break;
    default:
      return 0;
    }
  }
  pEVar1 = ctx->cipher;
  if (key == (uchar *)0x0) {
    if ((pEVar1->flags & 0x20) == 0) goto LAB_005364d8;
    p_Var8 = pEVar1->init;
  }
  else {
    p_Var8 = pEVar1->init;
  }
  iVar2 = (*p_Var8)(ctx,key,iv,enc_00);
  if (iVar2 == 0) {
    return 0;
  }
  pEVar1 = ctx->cipher;
LAB_005364d8:
  iVar2 = pEVar1->block_size;
  ctx->buf_len = 0;
  ctx->final_used = 0;
  ctx->block_mask = iVar2 + -1;
  return 1;
}

