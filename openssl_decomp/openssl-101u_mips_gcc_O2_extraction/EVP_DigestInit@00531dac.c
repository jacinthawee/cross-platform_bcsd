
int EVP_DigestInit(EVP_MD_CTX *ctx,EVP_MD *type)

{
  undefined *puVar1;
  ENGINE *e;
  EVP_MD *pEVar2;
  void *pvVar3;
  int iVar4;
  EVP_PKEY_CTX *ctx_00;
  _func_1078 *UNRECOVERED_JUMPTABLE;
  
  (*(code *)PTR_memset_006a99f4)(ctx,0,0x18);
  EVP_MD_CTX_clear_flags(ctx,2);
  if (ctx->engine == (ENGINE *)0x0) {
    if (type != (EVP_MD *)0x0) goto LAB_00531e3c;
    if (ctx->digest == (EVP_MD *)0x0) goto LAB_00531fac;
LAB_00531ed4:
    ctx_00 = ctx->pctx;
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) goto LAB_00531ee4;
  }
  else {
    if (ctx->digest == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_00531fac:
        ERR_put_error(6,0x80,0x8b,"digest.c",0xc4);
        return 0;
      }
    }
    else if ((type == (EVP_MD *)0x0) || (type->type == ctx->digest->type)) goto LAB_00531ed4;
    ENGINE_finish(ctx->engine);
LAB_00531e3c:
    e = ENGINE_get_digest_engine(type->type);
    if (e == (ENGINE *)0x0) {
      ctx->engine = (ENGINE *)0x0;
    }
    else {
      type = ENGINE_get_digest(e,type->type);
      if (type == (EVP_MD *)0x0) {
        ERR_put_error(6,0x80,0x86,"digest.c",0xb5);
        ENGINE_finish(e);
        return 0;
      }
      ctx->engine = e;
    }
    pEVar2 = ctx->digest;
    if (pEVar2 == type) goto LAB_00531ed4;
    if ((pEVar2 != (EVP_MD *)0x0) && (pEVar2->ctx_size != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(ctx->md_data);
      ctx->md_data = (void *)0x0;
    }
    ctx->digest = type;
    puVar1 = PTR_CRYPTO_malloc_006a7008;
    if ((ctx->flags & 0x100) == 0) {
      iVar4 = type->ctx_size;
      if (iVar4 != 0) {
        ctx->update = (_func_1088 *)type->update;
        pvVar3 = (void *)(*(code *)puVar1)(iVar4,"digest.c",0xd2);
        ctx->md_data = pvVar3;
        if (pvVar3 == (void *)0x0) {
          ERR_put_error(6,0x80,0x41,"digest.c",0xd4);
          return 0;
        }
        goto LAB_00531ed4;
      }
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        UNRECOVERED_JUMPTABLE = type->init;
        goto LAB_00531f34;
      }
    }
    else {
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        return 1;
      }
    }
LAB_00531ee4:
    iVar4 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,7,0,ctx);
    if ((iVar4 < 1) && (iVar4 != -2)) {
      return 0;
    }
  }
  if ((ctx->flags & 0x100) != 0) {
    return 1;
  }
  UNRECOVERED_JUMPTABLE = ctx->digest->init;
LAB_00531f34:
                    /* WARNING: Could not recover jumptable at 0x00531f48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar4 = (*UNRECOVERED_JUMPTABLE)(ctx);
  return iVar4;
}

