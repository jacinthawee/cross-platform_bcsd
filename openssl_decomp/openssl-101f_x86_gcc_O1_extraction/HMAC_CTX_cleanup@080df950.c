
void HMAC_CTX_cleanup(HMAC_CTX *ctx)

{
  uint uVar1;
  undefined4 *puVar2;
  byte bVar3;
  
  bVar3 = 0;
  EVP_MD_CTX_cleanup(&ctx->i_ctx);
  EVP_MD_CTX_cleanup(&ctx->o_ctx);
  puVar2 = (undefined4 *)((uint)&ctx->md_ctx & 0xfffffffc);
  EVP_MD_CTX_cleanup(&ctx->md_ctx);
  ctx->md = (EVP_MD *)0x0;
  *(undefined4 *)(ctx->key + 0x7c) = 0;
  uVar1 = (uint)((int)ctx + (0xd0 - (int)puVar2)) >> 2;
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
  }
  return;
}

