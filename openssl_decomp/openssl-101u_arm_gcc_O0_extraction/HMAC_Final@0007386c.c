
int HMAC_Final(HMAC_CTX *ctx,uchar *md,uint *len)

{
  int iVar1;
  EVP_MD_CTX *ctx_00;
  size_t local_60;
  uchar auStack_5c [64];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (ctx->md != (EVP_MD *)0x0) {
    ctx_00 = &ctx->md_ctx;
    iVar1 = EVP_DigestFinal_ex(ctx_00,auStack_5c,&local_60);
    if (((iVar1 != 0) && (iVar1 = EVP_MD_CTX_copy_ex(ctx_00,&ctx->o_ctx), iVar1 != 0)) &&
       (iVar1 = EVP_DigestUpdate(ctx_00,auStack_5c,local_60), iVar1 != 0)) {
      iVar1 = EVP_DigestFinal_ex(ctx_00,md,len);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      goto LAB_00073898;
    }
  }
  iVar1 = 0;
LAB_00073898:
  if (local_1c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

