
int HMAC_CTX_copy(HMAC_CTX *dctx,HMAC_CTX *sctx)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  iVar1 = EVP_MD_CTX_copy(&dctx->i_ctx,&sctx->i_ctx);
  if (((iVar1 != 0) && (iVar1 = EVP_MD_CTX_copy(&dctx->o_ctx,&sctx->o_ctx), iVar1 != 0)) &&
     (iVar1 = EVP_MD_CTX_copy(&dctx->md_ctx,&sctx->md_ctx), iVar1 != 0)) {
    puVar4 = (undefined4 *)((uint)(dctx->key + 4) & 0xfffffffc);
    *(undefined4 *)dctx->key = *(undefined4 *)sctx->key;
    iVar1 = (int)dctx + (0x50 - (int)puVar4);
    *(undefined4 *)(dctx->key + 0x7c) = *(undefined4 *)(sctx->key + 0x7c);
    puVar3 = (undefined4 *)((int)sctx + (0x50 - iVar1));
    for (uVar2 = iVar1 + 0x80U >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
    dctx->key_length = sctx->key_length;
    dctx->md = sctx->md;
    return 1;
  }
  return 0;
}

