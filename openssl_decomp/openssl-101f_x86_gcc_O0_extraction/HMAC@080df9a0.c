
uchar * HMAC(EVP_MD *evp_md,void *key,int key_len,uchar *d,size_t n,uchar *md,uint *md_len)

{
  EVP_MD_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  int iVar1;
  int in_GS_OFFSET;
  size_t local_134;
  HMAC_CTX local_130;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (md == (uchar *)0x0) {
    md = m_8494;
  }
  EVP_MD_CTX_init(&local_130.i_ctx);
  ctx = &local_130.o_ctx;
  EVP_MD_CTX_init(ctx);
  ctx_00 = &local_130.md_ctx;
  EVP_MD_CTX_init(ctx_00);
  if ((key != (void *)0x0) && (evp_md != (EVP_MD *)0x0)) {
    EVP_MD_CTX_init(&local_130.i_ctx);
    EVP_MD_CTX_init(ctx);
    EVP_MD_CTX_init(ctx_00);
  }
  iVar1 = HMAC_Init_ex(&local_130,key,key_len,evp_md,(ENGINE *)0x0);
  if (iVar1 != 0) {
    iVar1 = EVP_DigestUpdate(ctx_00,d,n);
    if (iVar1 != 0) {
      iVar1 = EVP_DigestFinal_ex(ctx_00,local_60,&local_134);
      if (iVar1 != 0) {
        iVar1 = EVP_MD_CTX_copy_ex(ctx_00,ctx);
        if (iVar1 != 0) {
          iVar1 = EVP_DigestUpdate(ctx_00,local_60,local_134);
          if (iVar1 != 0) {
            iVar1 = EVP_DigestFinal_ex(ctx_00,md,md_len);
            if (iVar1 != 0) {
              EVP_MD_CTX_cleanup(&local_130.i_ctx);
              EVP_MD_CTX_cleanup(ctx);
              EVP_MD_CTX_cleanup(ctx_00);
              goto LAB_080dfa9e;
            }
          }
        }
      }
    }
  }
  md = (uchar *)0x0;
LAB_080dfa9e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return md;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

