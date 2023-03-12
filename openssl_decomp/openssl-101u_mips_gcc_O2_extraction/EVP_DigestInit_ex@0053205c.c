
int EVP_DigestInit_ex(EVP_MD_CTX *ctx,EVP_MD *type,ENGINE *impl)

{
  undefined *puVar1;
  int iVar2;
  EVP_MD *pEVar3;
  void *pvVar4;
  EVP_PKEY_CTX *ctx_00;
  _func_1078 *UNRECOVERED_JUMPTABLE;
  
  EVP_MD_CTX_clear_flags(ctx,2);
  if (ctx->engine == (ENGINE *)0x0) {
    if (type != (EVP_MD *)0x0) goto LAB_005320d4;
    if (ctx->digest == (EVP_MD *)0x0) goto LAB_00532278;
LAB_00532170:
    ctx_00 = ctx->pctx;
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) goto LAB_00532180;
  }
  else {
    if (ctx->digest == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_00532278:
        ERR_put_error(6,0x80,0x8b,"digest.c",0xc4);
        return 0;
      }
    }
    else if ((type == (EVP_MD *)0x0) || (type->type == ctx->digest->type)) goto LAB_00532170;
    ENGINE_finish(ctx->engine);
LAB_005320d4:
    if (impl == (ENGINE *)0x0) {
      impl = ENGINE_get_digest_engine(type->type);
      if (impl != (ENGINE *)0x0) goto LAB_005320ec;
      ctx->engine = (ENGINE *)0x0;
    }
    else {
      iVar2 = ENGINE_init(impl);
      if (iVar2 == 0) {
        ERR_put_error(6,0x80,0x86,"digest.c",0xaa);
        return 0;
      }
LAB_005320ec:
      type = ENGINE_get_digest(impl,type->type);
      if (type == (EVP_MD *)0x0) {
        ERR_put_error(6,0x80,0x86,"digest.c",0xb5);
        ENGINE_finish(impl);
        return 0;
      }
      ctx->engine = impl;
    }
    pEVar3 = ctx->digest;
    if (type == pEVar3) goto LAB_00532170;
    if ((pEVar3 != (EVP_MD *)0x0) && (pEVar3->ctx_size != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(ctx->md_data);
      ctx->md_data = (void *)0x0;
    }
    ctx->digest = type;
    puVar1 = PTR_CRYPTO_malloc_006a7008;
    if ((ctx->flags & 0x100) == 0) {
      iVar2 = type->ctx_size;
      if (iVar2 != 0) {
        ctx->update = (_func_1088 *)type->update;
        pvVar4 = (void *)(*(code *)puVar1)(iVar2,"digest.c",0xd2);
        ctx->md_data = pvVar4;
        if (pvVar4 == (void *)0x0) {
          ERR_put_error(6,0x80,0x41,"digest.c",0xd4);
          return 0;
        }
        goto LAB_00532170;
      }
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        UNRECOVERED_JUMPTABLE = type->init;
        goto LAB_005321d0;
      }
    }
    else {
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        return 1;
      }
    }
LAB_00532180:
    iVar2 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,7,0,ctx);
    if ((iVar2 < 1) && (iVar2 != -2)) {
      return 0;
    }
  }
  if ((ctx->flags & 0x100) != 0) {
    return 1;
  }
  UNRECOVERED_JUMPTABLE = ctx->digest->init;
LAB_005321d0:
                    /* WARNING: Could not recover jumptable at 0x005321e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*UNRECOVERED_JUMPTABLE)(ctx);
  return iVar2;
}

