
int EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx)

{
  EVP_MD *pEVar1;
  int iVar2;
  
  pEVar1 = ctx->digest;
  if (pEVar1 != (EVP_MD *)0x0) {
    if (pEVar1->cleanup != (_func_1082 *)0x0) {
      iVar2 = EVP_MD_CTX_test_flags(ctx,2);
      if (iVar2 == 0) {
        (*ctx->digest->cleanup)(ctx);
      }
      pEVar1 = ctx->digest;
      if (pEVar1 == (EVP_MD *)0x0) goto LAB_00535bac;
    }
    if ((pEVar1->ctx_size != 0) && (ctx->md_data != (void *)0x0)) {
      iVar2 = EVP_MD_CTX_test_flags(ctx,4);
      if (iVar2 == 0) {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(ctx->md_data,ctx->digest->ctx_size);
        (*(code *)PTR_CRYPTO_free_006a7f88)(ctx->md_data);
      }
    }
  }
LAB_00535bac:
  if (ctx->pctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(ctx->pctx);
  }
  if (ctx->engine != (ENGINE *)0x0) {
    ENGINE_finish(ctx->engine);
  }
  (*(code *)PTR_memset_006aab00)(ctx,0,0x18);
  return 1;
}

