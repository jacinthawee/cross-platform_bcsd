
int EVP_DigestInit_ex(EVP_MD_CTX *ctx,EVP_MD *type,ENGINE *impl)

{
  byte bVar1;
  ENGINE *e;
  int iVar2;
  EVP_MD *pEVar3;
  void *pvVar4;
  EVP_PKEY_CTX *ctx_00;
  int line;
  
  EVP_MD_CTX_clear_flags(ctx,2);
  e = ctx->engine;
  if (e == (ENGINE *)0x0) {
    if (type != (EVP_MD *)0x0) goto LAB_08127711;
    pEVar3 = ctx->digest;
    if (pEVar3 == (EVP_MD *)0x0) goto LAB_08127858;
LAB_08127754:
    if (pEVar3->ctx_size != 0) {
      CRYPTO_free(ctx->md_data);
    }
LAB_0812775f:
    bVar1 = *(byte *)((int)&ctx->flags + 1);
    ctx->digest = type;
    if ((bVar1 & 1) == 0) {
      iVar2 = type->ctx_size;
      if (iVar2 != 0) {
        ctx->update = (_func_1088 *)type->update;
        pvVar4 = CRYPTO_malloc(iVar2,"digest.c",0xd2);
        ctx->md_data = pvVar4;
        if (pvVar4 == (void *)0x0) {
          line = 0xd6;
          iVar2 = 0x41;
LAB_0812786a:
          ERR_put_error(6,0x80,iVar2,"digest.c",line);
          return 0;
        }
        goto LAB_081277c0;
      }
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08127787. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*type->init)(ctx);
        return iVar2;
      }
    }
    else {
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        return 1;
      }
    }
  }
  else {
    if (ctx->digest == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_08127858:
        line = 0xc6;
        iVar2 = 0x8b;
        goto LAB_0812786a;
      }
LAB_08127705:
      e = (ENGINE *)ENGINE_finish(e);
LAB_08127711:
      if (impl == (ENGINE *)0x0) {
        impl = ENGINE_get_digest_engine(type->type);
        if (impl != (ENGINE *)0x0) goto LAB_0812772f;
        ctx->engine = (ENGINE *)0x0;
      }
      else {
        iVar2 = ENGINE_init(e);
        if (iVar2 == 0) {
          ERR_put_error(6,0x80,0x86,"digest.c",0xa7);
          return 0;
        }
LAB_0812772f:
        type = ENGINE_get_digest(impl,type->type);
        if (type == (EVP_MD *)0x0) {
          ERR_put_error(6,0x80,0x86,"digest.c",0xb5);
          ENGINE_finish((ENGINE *)type);
          return 0;
        }
        ctx->engine = impl;
      }
      pEVar3 = ctx->digest;
      if (type != pEVar3) {
        if (pEVar3 != (EVP_MD *)0x0) goto LAB_08127754;
        goto LAB_0812775f;
      }
    }
    else if ((type != (EVP_MD *)0x0) && (type->type != ctx->digest->type)) goto LAB_08127705;
LAB_081277c0:
    ctx_00 = ctx->pctx;
    if (ctx_00 == (EVP_PKEY_CTX *)0x0) goto LAB_081277f8;
  }
  iVar2 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,7,0,ctx);
  if ((iVar2 < 1) && (iVar2 != -2)) {
    return 0;
  }
LAB_081277f8:
  if ((*(byte *)((int)&ctx->flags + 1) & 1) != 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x08127830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*ctx->digest->init)(ctx);
  return iVar2;
}

