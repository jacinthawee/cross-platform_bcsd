
int EVP_DigestFinal(EVP_MD_CTX *ctx,uchar *md,uint *s)

{
  int iVar1;
  EVP_MD *pEVar2;
  
  pEVar2 = ctx->digest;
  if (0x40 < pEVar2->md_size) {
    OpenSSLDie("digest.c",0x10c,"ctx->digest->md_size <= EVP_MAX_MD_SIZE");
    pEVar2 = ctx->digest;
  }
  iVar1 = (*pEVar2->final)(ctx,md);
  pEVar2 = ctx->digest;
  if (s != (uint *)0x0) {
    *s = pEVar2->md_size;
  }
  if (pEVar2->cleanup != (_func_1082 *)0x0) {
    (*pEVar2->cleanup)(ctx);
    EVP_MD_CTX_set_flags(ctx,2);
    pEVar2 = ctx->digest;
  }
  OPENSSL_cleanse(ctx->md_data,pEVar2->ctx_size);
  EVP_MD_CTX_cleanup(ctx);
  return iVar1;
}

