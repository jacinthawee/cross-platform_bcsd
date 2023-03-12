
int EVP_DigestInit(EVP_MD_CTX *ctx,EVP_MD *type)

{
  ENGINE *e;
  int iVar1;
  void *pvVar2;
  EVP_MD *pEVar3;
  
  memset(ctx,0,0x18);
  EVP_MD_CTX_clear_flags(ctx,2);
  if (ctx->engine == (ENGINE *)0x0) {
    if (type == (EVP_MD *)0x0) {
      if (ctx->digest == (EVP_MD *)0x0) goto LAB_000a5900;
      goto LAB_000a58b8;
    }
  }
  else {
    if (ctx->digest == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_000a5900:
        ERR_put_error(6,0x80,0x8b,"digest.c",0xc4);
        return 0;
      }
    }
    else if ((type == (EVP_MD *)0x0) || (type->type == ctx->digest->type)) goto LAB_000a58b8;
    ENGINE_finish(ctx->engine);
  }
  e = ENGINE_get_digest_engine(type->type);
  if ((e != (ENGINE *)0x0) && (type = ENGINE_get_digest(e,type->type), type == (EVP_MD *)0x0)) {
    ERR_put_error(6,0x80,0x86,"digest.c",0xb5);
    ENGINE_finish(e);
    return 0;
  }
  pEVar3 = ctx->digest;
  ctx->engine = e;
  if (pEVar3 != type) {
    if ((pEVar3 != (EVP_MD *)0x0) && (pEVar3->ctx_size != 0)) {
      CRYPTO_free(ctx->md_data);
      ctx->md_data = (void *)0x0;
    }
    ctx->digest = type;
    if ((-1 < (int)(ctx->flags << 0x17)) && (iVar1 = type->ctx_size, iVar1 != 0)) {
      ctx->update = (_func_1088 *)type->update;
      pvVar2 = CRYPTO_malloc(iVar1,"digest.c",0xd2);
      ctx->md_data = pvVar2;
      if (pvVar2 == (void *)0x0) {
        ERR_put_error(6,0x80,0x41,"digest.c",0xd4);
        return 0;
      }
    }
  }
LAB_000a58b8:
  if ((ctx->pctx != (EVP_PKEY_CTX *)0x0) &&
     (iVar1 = EVP_PKEY_CTX_ctrl(ctx->pctx,-1,0xf8,7,0,ctx), iVar1 != -2 && iVar1 < 1)) {
    return 0;
  }
  if ((int)(ctx->flags << 0x17) < 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000a58fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*ctx->digest->init)(ctx);
  return iVar1;
}

