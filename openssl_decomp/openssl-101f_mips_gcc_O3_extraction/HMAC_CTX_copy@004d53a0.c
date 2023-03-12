
int HMAC_CTX_copy(HMAC_CTX *dctx,HMAC_CTX *sctx)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  EVP_MD *pEVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  iVar1 = (*(code *)PTR_EVP_MD_CTX_copy_006a90b4)(&dctx->i_ctx,&sctx->i_ctx);
  if ((iVar1 != 0) &&
     (iVar1 = (*(code *)PTR_EVP_MD_CTX_copy_006a90b4)(&dctx->o_ctx,&sctx->o_ctx), iVar1 != 0)) {
    iVar1 = (*(code *)PTR_EVP_MD_CTX_copy_006a90b4)(&dctx->md_ctx,&sctx->md_ctx);
    puVar3 = sctx->key;
    if (iVar1 != 0) {
      puVar2 = dctx->key;
      do {
        uVar8 = *(undefined4 *)puVar3;
        uVar7 = *(undefined4 *)(puVar3 + 4);
        uVar6 = *(undefined4 *)(puVar3 + 8);
        uVar5 = *(undefined4 *)(puVar3 + 0xc);
        puVar3 = puVar3 + 0x10;
        *(undefined4 *)puVar2 = uVar8;
        *(undefined4 *)(puVar2 + 4) = uVar7;
        *(undefined4 *)(puVar2 + 8) = uVar6;
        *(undefined4 *)(puVar2 + 0xc) = uVar5;
        puVar2 = puVar2 + 0x10;
      } while ((HMAC_CTX *)puVar3 != sctx + 1);
      pEVar4 = sctx->md;
      dctx->key_length = sctx->key_length;
      dctx->md = pEVar4;
      return 1;
    }
  }
  return 0;
}

