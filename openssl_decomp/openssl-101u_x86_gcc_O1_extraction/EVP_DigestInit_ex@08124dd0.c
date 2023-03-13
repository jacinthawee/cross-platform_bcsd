
int EVP_DigestInit_ex(EVP_MD_CTX *ctx,EVP_MD *type,ENGINE *impl)

{
  byte bVar1;
  EVP_MD *pEVar2;
  ENGINE *e;
  int iVar3;
  EVP_PKEY_CTX *ctx_00;
  void *pvVar4;
  int line;
  
  EVP_MD_CTX_clear_flags(ctx,2);
  e = ctx->engine;
  if (e == (ENGINE *)0x0) {
    if (type != (EVP_MD *)0x0) goto LAB_08124e21;
    if (ctx->digest == (EVP_MD *)0x0) goto LAB_08124f88;
LAB_08124eb8:
    ctx_00 = ctx->pctx;
    if (ctx_00 == (EVP_PKEY_CTX *)0x0) goto LAB_08124ef0;
  }
  else {
    if (ctx->digest == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_08124f88:
        line = 0xc4;
        iVar3 = 0x8b;
        goto LAB_08124f4e;
      }
    }
    else if ((type == (EVP_MD *)0x0) || (type->type == ctx->digest->type)) goto LAB_08124eb8;
    e = (ENGINE *)ENGINE_finish(e);
LAB_08124e21:
    if (impl == (ENGINE *)0x0) {
      impl = ENGINE_get_digest_engine(type->type);
      if (impl != (ENGINE *)0x0) goto LAB_08124e3f;
      ctx->engine = (ENGINE *)0x0;
    }
    else {
      iVar3 = ENGINE_init(e);
      if (iVar3 == 0) {
        ERR_put_error(6,0x80,0x86,"digest.c",0xaa);
        return 0;
      }
LAB_08124e3f:
      type = ENGINE_get_digest(impl,type->type);
      if (type == (EVP_MD *)0x0) {
        ERR_put_error(6,0x80,0x86,"digest.c",0xb5);
        ENGINE_finish((ENGINE *)type);
        return 0;
      }
      ctx->engine = impl;
    }
    pEVar2 = ctx->digest;
    if (type == pEVar2) goto LAB_08124eb8;
    if ((pEVar2 != (EVP_MD *)0x0) && (pEVar2->ctx_size != 0)) {
      CRYPTO_free(ctx->md_data);
      ctx->md_data = (void *)0x0;
    }
    bVar1 = *(byte *)((int)&ctx->flags + 1);
    ctx->digest = type;
    if ((bVar1 & 1) == 0) {
      iVar3 = type->ctx_size;
      if (iVar3 != 0) {
        ctx->update = (_func_1088 *)type->update;
        pvVar4 = CRYPTO_malloc(iVar3,"digest.c",0xd2);
        ctx->md_data = pvVar4;
        if (pvVar4 == (void *)0x0) {
          line = 0xd4;
          iVar3 = 0x41;
LAB_08124f4e:
          ERR_put_error(6,0x80,iVar3,"digest.c",line);
          return 0;
        }
        goto LAB_08124eb8;
      }
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08124e9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar3 = (*type->init)(ctx);
        return iVar3;
      }
    }
    else {
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        return 1;
      }
    }
  }
  iVar3 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,7,0,ctx);
  if ((iVar3 < 1) && (iVar3 != -2)) {
    return 0;
  }
LAB_08124ef0:
  if ((*(byte *)((int)&ctx->flags + 1) & 1) != 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x08124f78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*ctx->digest->init)(ctx);
  return iVar3;
}

