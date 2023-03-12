
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx,uchar *md,uint *s)

{
  int iVar1;
  EVP_MD *pEVar2;
  
  pEVar2 = ctx->digest;
  if (0x40 < pEVar2->md_size) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("digest.c",0x10f,"ctx->digest->md_size <= EVP_MAX_MD_SIZE");
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
  (*(code *)PTR_memset_006aab00)(ctx->md_data,0,pEVar2->ctx_size);
  return iVar1;
}

