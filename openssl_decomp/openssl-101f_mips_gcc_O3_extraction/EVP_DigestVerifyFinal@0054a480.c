
int EVP_DigestVerifyFinal(EVP_MD_CTX *ctx,uchar *sig,size_t siglen)

{
  undefined *puVar1;
  int iVar2;
  size_t local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(*(int *)ctx->pctx + 0x48) == 0) {
    EVP_MD_CTX_init(&EStack_7c);
    iVar2 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
    if (iVar2 != 0) {
      iVar2 = EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_80);
      EVP_MD_CTX_cleanup(&EStack_7c);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = EVP_PKEY_verify(ctx->pctx,sig,siglen,auStack_64,local_80);
      }
      goto LAB_0054a53c;
    }
  }
  else {
    EVP_MD_CTX_init(&EStack_7c);
    iVar2 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*(int *)EStack_7c.pctx + 0x48))(EStack_7c.pctx,sig,siglen,&EStack_7c);
      EVP_MD_CTX_cleanup(&EStack_7c);
      goto LAB_0054a53c;
    }
  }
  iVar2 = -1;
LAB_0054a53c:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return 0;
}

