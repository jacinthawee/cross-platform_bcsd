
int EVP_DecryptInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv)

{
  EVP_CIPHER *pEVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  _func_1091 *p_Var7;
  _func_1089 *p_Var8;
  
  ctx->encrypt = 0;
  if (ctx->engine == (ENGINE *)0x0) {
    pEVar1 = ctx->cipher;
    if (cipher != (EVP_CIPHER *)0x0) {
      if (pEVar1 != (EVP_CIPHER *)0x0) {
        p_Var7 = pEVar1->cleanup;
        goto LAB_005351d0;
      }
      goto LAB_00535254;
    }
    if (pEVar1 == (EVP_CIPHER *)0x0) goto LAB_005354e4;
LAB_005352b8:
    if (((uint)pEVar1->block_size < 0x11) && ((0x10102U >> (pEVar1->block_size & 0x1fU) & 1) != 0))
    {
      uVar4 = EVP_CIPHER_CTX_flags(ctx);
    }
    else {
      (*(code *)PTR_OpenSSLDie_006a7c5c)
                ("evp_enc.c",0xcf,
                 "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                );
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
          (*(code *)PTR_OpenSSLDie_006a7c5c)
                    ("evp_enc.c",0xe1,"EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)");
        }
        if (iv != (uchar *)0x0) {
          iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
          (*(code *)PTR_memcpy_006a9aec)(ctx->oiv,iv,iVar2);
        }
        iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
        (*(code *)PTR_memcpy_006a9aec)(ctx->iv,ctx->oiv,iVar2);
        break;
      case 5:
        ctx->num = 0;
        if (iv != (uchar *)0x0) {
          iVar2 = EVP_CIPHER_CTX_iv_length(ctx);
          (*(code *)PTR_memcpy_006a9aec)(ctx->iv,iv,iVar2);
        }
        break;
      default:
        goto switchD_005353c4_caseD_6;
      }
    }
    pEVar1 = ctx->cipher;
    if (key == (uchar *)0x0) {
      if ((pEVar1->flags & 0x20) == 0) goto LAB_00535320;
      p_Var8 = pEVar1->init;
    }
    else {
      p_Var8 = pEVar1->init;
    }
    iVar2 = (*p_Var8)(ctx,key,iv,0);
    if (iVar2 == 0) {
      return 0;
    }
    pEVar1 = ctx->cipher;
LAB_00535320:
    iVar2 = pEVar1->block_size;
    ctx->buf_len = 0;
    ctx->final_used = 0;
    ctx->block_mask = iVar2 + -1;
    return 1;
  }
  pEVar1 = ctx->cipher;
  if (pEVar1 == (EVP_CIPHER *)0x0) {
    if (cipher == (EVP_CIPHER *)0x0) {
LAB_005354e4:
      iVar5 = 0x83;
      iVar2 = 0xc2;
      goto LAB_005354f0;
    }
  }
  else {
    if ((cipher == (EVP_CIPHER *)0x0) || (cipher->nid == pEVar1->nid)) goto LAB_005352b8;
    p_Var7 = pEVar1->cleanup;
LAB_005351d0:
    uVar6 = ctx->flags;
    if ((p_Var7 == (_func_1091 *)0x0) || (iVar2 = (*p_Var7)(ctx), iVar2 != 0)) {
      if ((ctx->cipher_data != (void *)0x0) &&
         ((*(code *)PTR_OPENSSL_cleanse_006a7074)(ctx->cipher_data,ctx->cipher->ctx_size),
         ctx->cipher_data != (void *)0x0)) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      if (ctx->engine != (ENGINE *)0x0) {
        ENGINE_finish(ctx->engine);
      }
      (*(code *)PTR_memset_006a99f4)(ctx,0,0x8c);
    }
    ctx->encrypt = 0;
    ctx->flags = uVar6;
  }
LAB_00535254:
  if (impl == (ENGINE *)0x0) {
    impl = ENGINE_get_cipher_engine(cipher->nid);
    if (impl != (ENGINE *)0x0) goto LAB_0053526c;
    ctx->engine = (ENGINE *)0x0;
  }
  else {
    iVar2 = ENGINE_init(impl);
    if (iVar2 == 0) {
      ERR_put_error(6,0x7b,0x86,"evp_enc.c",0x8e);
      return 0;
    }
LAB_0053526c:
    cipher = ENGINE_get_cipher(impl,cipher->nid);
    if (cipher == (EVP_CIPHER *)0x0) {
      iVar5 = 0x86;
      iVar2 = 0x9d;
LAB_005354f0:
      ERR_put_error(6,0x7b,iVar5,"evp_enc.c",iVar2);
      return 0;
    }
    ctx->engine = impl;
  }
  iVar2 = cipher->ctx_size;
  ctx->cipher = cipher;
  if (iVar2 == 0) {
    ctx->cipher_data = (void *)0x0;
    pEVar1 = cipher;
LAB_005352a0:
    uVar4 = pEVar1->flags;
    iVar2 = cipher->key_len;
    ctx->flags = 0;
    ctx->key_len = iVar2;
    if ((uVar4 & 0x40) == 0) goto LAB_005352b8;
    if (pEVar1->ctrl == (_func_1094 *)0x0) {
      iVar5 = 0x84;
      iVar2 = 0x25a;
LAB_005355d0:
      ERR_put_error(6,0x7c,iVar5,"evp_enc.c",iVar2);
    }
    else {
      iVar2 = (*pEVar1->ctrl)(ctx,0,0,(void *)0x0);
      if (iVar2 == -1) {
        iVar5 = 0x85;
        iVar2 = 0x261;
        goto LAB_005355d0;
      }
      if (iVar2 != 0) {
        pEVar1 = ctx->cipher;
        goto LAB_005352b8;
      }
    }
    iVar5 = 0x86;
    iVar2 = 0xbd;
  }
  else {
    pvVar3 = (void *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"evp_enc.c",0xb1);
    ctx->cipher_data = pvVar3;
    if (pvVar3 != (void *)0x0) {
      pEVar1 = ctx->cipher;
      goto LAB_005352a0;
    }
    iVar5 = 0x41;
    iVar2 = 0xb3;
  }
  ERR_put_error(6,0x7b,iVar5,"evp_enc.c",iVar2);
switchD_005353c4_caseD_6:
  return 0;
}

