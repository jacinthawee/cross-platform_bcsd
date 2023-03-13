
int HMAC_Final(HMAC_CTX *ctx,uchar *md,uint *len)

{
  EVP_MD_CTX *ctx_00;
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  size_t local_64;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (ctx->md != (EVP_MD *)0x0) {
    ctx_00 = &ctx->md_ctx;
    iVar1 = EVP_DigestFinal_ex(ctx_00,local_60,&local_64);
    if (iVar1 != 0) {
      iVar1 = EVP_MD_CTX_copy_ex(ctx_00,&ctx->o_ctx);
      if (iVar1 != 0) {
        iVar1 = EVP_DigestUpdate(ctx_00,local_60,local_64);
        if (iVar1 != 0) {
          iVar1 = EVP_DigestFinal_ex(ctx_00,md,len);
          uVar2 = (uint)(iVar1 != 0);
          goto LAB_080dd361;
        }
      }
    }
  }
  uVar2 = 0;
LAB_080dd361:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

