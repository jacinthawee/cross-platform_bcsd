
int EVP_DigestVerifyFinal(EVP_MD_CTX *ctx,uchar *sig,size_t siglen)

{
  int iVar1;
  size_t local_78;
  EVP_MD_CTX EStack_74;
  uchar auStack_5c [64];
  int local_1c;
  
  local_1c = __TMC_END__;
  if (*(int *)(*(int *)ctx->pctx + 0x48) == 0) {
    EVP_MD_CTX_init(&EStack_74);
    iVar1 = EVP_MD_CTX_copy_ex(&EStack_74,ctx);
    if (iVar1 != 0) {
      iVar1 = EVP_DigestFinal_ex(&EStack_74,auStack_5c,&local_78);
      EVP_MD_CTX_cleanup(&EStack_74);
      if (iVar1 != 0) {
        iVar1 = EVP_PKEY_verify(ctx->pctx,sig,siglen,auStack_5c,local_78);
      }
      goto LAB_000b2288;
    }
  }
  else {
    EVP_MD_CTX_init(&EStack_74);
    iVar1 = EVP_MD_CTX_copy_ex(&EStack_74,ctx);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*(int *)EStack_74.pctx + 0x48))(EStack_74.pctx,sig,siglen,&EStack_74);
      EVP_MD_CTX_cleanup(&EStack_74);
      goto LAB_000b2288;
    }
  }
  iVar1 = -1;
LAB_000b2288:
  if (local_1c == __TMC_END__) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

