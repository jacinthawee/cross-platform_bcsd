
int EVP_DigestVerifyFinal(EVP_MD_CTX *ctx,uchar *sig,size_t siglen)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  size_t local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(*(int *)ctx->pctx + 0x48) == 0) {
    EVP_MD_CTX_init(&local_78);
    iVar1 = EVP_MD_CTX_copy_ex(&local_78,ctx);
    if (iVar1 != 0) {
      iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
      EVP_MD_CTX_cleanup(&local_78);
      iVar1 = 0;
      if (iVar2 != 0) {
        iVar1 = EVP_PKEY_verify(ctx->pctx,sig,siglen,local_60,local_7c);
      }
      goto LAB_0813540c;
    }
  }
  else {
    EVP_MD_CTX_init(&local_78);
    iVar1 = EVP_MD_CTX_copy_ex(&local_78,ctx);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*(int *)local_78.pctx + 0x48))(local_78.pctx,sig,siglen,&local_78);
      EVP_MD_CTX_cleanup(&local_78);
      goto LAB_0813540c;
    }
  }
  iVar1 = -1;
LAB_0813540c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

