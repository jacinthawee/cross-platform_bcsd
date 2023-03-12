
int EVP_DigestInit(EVP_MD_CTX *ctx,EVP_MD *type)

{
  byte bVar1;
  EVP_MD *pEVar2;
  ENGINE *e;
  EVP_PKEY_CTX *ctx_00;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  int line;
  
  uVar6 = 0;
  ctx->digest = (EVP_MD *)0x0;
  ctx->update = (_func_1088 *)0x0;
  uVar5 = (uint)&ctx->engine & 0xfffffffc;
  do {
    *(undefined4 *)(uVar5 + uVar6) = 0;
    uVar6 = uVar6 + 4;
  } while (uVar6 < ((int)ctx + (0x18 - uVar5) & 0xfffffffc));
  EVP_MD_CTX_clear_flags(ctx,2);
  if (ctx->engine == (ENGINE *)0x0) {
    if (type != (EVP_MD *)0x0) goto LAB_081274f9;
    pEVar2 = ctx->digest;
    if (pEVar2 == (EVP_MD *)0x0) goto LAB_08127648;
LAB_08127539:
    if (pEVar2->ctx_size != 0) {
      CRYPTO_free(ctx->md_data);
    }
LAB_08127544:
    bVar1 = *(byte *)((int)&ctx->flags + 1);
    ctx->digest = type;
    if ((bVar1 & 1) == 0) {
      iVar3 = type->ctx_size;
      if (iVar3 != 0) {
        ctx->update = (_func_1088 *)type->update;
        pvVar4 = CRYPTO_malloc(iVar3,"digest.c",0xd2);
        ctx->md_data = pvVar4;
        if (pvVar4 == (void *)0x0) {
          line = 0xd6;
          iVar3 = 0x41;
LAB_0812765a:
          ERR_put_error(6,0x80,iVar3,"digest.c",line);
          return 0;
        }
        goto LAB_081275c0;
      }
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) goto LAB_081275f2;
    }
    else {
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        return 1;
      }
    }
LAB_08127562:
    iVar3 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,7,0,ctx);
    if ((iVar3 < 1) && (iVar3 != -2)) {
      return 0;
    }
  }
  else {
    pEVar2 = ctx->digest;
    if (pEVar2 == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_08127648:
        line = 0xc6;
        iVar3 = 0x8b;
        goto LAB_0812765a;
      }
LAB_081274ed:
      ENGINE_finish((ENGINE *)pEVar2);
LAB_081274f9:
      e = ENGINE_get_digest_engine(type->type);
      if (e == (ENGINE *)0x0) {
        ctx->engine = (ENGINE *)0x0;
      }
      else {
        type = ENGINE_get_digest(e,type->type);
        if (type == (EVP_MD *)0x0) {
          ERR_put_error(6,0x80,0x86,"digest.c",0xb5);
          ENGINE_finish((ENGINE *)type);
          return 0;
        }
        ctx->engine = e;
      }
      pEVar2 = ctx->digest;
      if (pEVar2 != type) {
        if (pEVar2 != (EVP_MD *)0x0) goto LAB_08127539;
        goto LAB_08127544;
      }
    }
    else if ((type != (EVP_MD *)0x0) &&
            (pEVar2 = (EVP_MD *)pEVar2->type, (EVP_MD *)type->type != pEVar2)) goto LAB_081274ed;
LAB_081275c0:
    ctx_00 = ctx->pctx;
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) goto LAB_08127562;
  }
  if ((*(byte *)((int)&ctx->flags + 1) & 1) != 0) {
    return 1;
  }
  type = ctx->digest;
LAB_081275f2:
                    /* WARNING: Could not recover jumptable at 0x081275fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*type->init)(ctx);
  return iVar3;
}

