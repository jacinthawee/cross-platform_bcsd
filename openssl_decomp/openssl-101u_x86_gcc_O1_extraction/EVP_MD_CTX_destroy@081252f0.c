
void EVP_MD_CTX_destroy(EVP_MD_CTX *ctx)

{
  int iVar1;
  EVP_MD *pEVar2;
  uint uVar3;
  uint uVar4;
  
  if (ctx == (EVP_MD_CTX *)0x0) {
    return;
  }
  pEVar2 = ctx->digest;
  if (pEVar2 != (EVP_MD *)0x0) {
    if (pEVar2->cleanup != (_func_1082 *)0x0) {
      iVar1 = EVP_MD_CTX_test_flags(ctx,2);
      if (iVar1 == 0) {
        (*ctx->digest->cleanup)(ctx);
      }
      pEVar2 = ctx->digest;
      if (pEVar2 == (EVP_MD *)0x0) goto LAB_08125330;
    }
    if ((pEVar2->ctx_size != 0) && (ctx->md_data != (void *)0x0)) {
      iVar1 = EVP_MD_CTX_test_flags(ctx,4);
      if (iVar1 == 0) {
        OPENSSL_cleanse(ctx->md_data,ctx->digest->ctx_size);
        CRYPTO_free(ctx->md_data);
      }
    }
  }
LAB_08125330:
  if (ctx->pctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(ctx->pctx);
  }
  if (ctx->engine != (ENGINE *)0x0) {
    ENGINE_finish(ctx->engine);
  }
  ctx->digest = (EVP_MD *)0x0;
  ctx->update = (_func_1088 *)0x0;
  uVar4 = 0;
  uVar3 = (uint)&ctx->engine & 0xfffffffc;
  do {
    *(undefined4 *)(uVar3 + uVar4) = 0;
    uVar4 = uVar4 + 4;
  } while (uVar4 < ((int)ctx + (0x18 - uVar3) & 0xfffffffc));
  CRYPTO_free(ctx);
  return;
}

