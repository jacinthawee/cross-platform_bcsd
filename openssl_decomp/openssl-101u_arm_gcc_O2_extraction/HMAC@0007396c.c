
uchar * HMAC(EVP_MD *evp_md,void *key,int key_len,uchar *d,size_t n,uchar *md,uint *md_len)

{
  int iVar1;
  size_t local_140;
  uchar auStack_13c [64];
  HMAC_CTX local_fc;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&local_fc.i_ctx);
  if (md == (uchar *)0x0) {
    md = &m_11152;
  }
  EVP_MD_CTX_init(&local_fc.o_ctx);
  EVP_MD_CTX_init(&local_fc.md_ctx);
  local_fc.md = (EVP_MD *)0x0;
  if (key != (void *)0x0 && evp_md != (EVP_MD *)0x0) {
    EVP_MD_CTX_init(&local_fc.i_ctx);
    EVP_MD_CTX_init(&local_fc.o_ctx);
    EVP_MD_CTX_init(&local_fc.md_ctx);
  }
  local_fc.md = (EVP_MD *)0x0;
  iVar1 = HMAC_Init_ex(&local_fc,key,key_len,evp_md,(ENGINE *)0x0);
  if (((((iVar1 == 0) || (local_fc.md == (EVP_MD *)0x0)) ||
       (iVar1 = EVP_DigestUpdate(&local_fc.md_ctx,d,n), iVar1 == 0)) ||
      ((local_fc.md == (EVP_MD *)0x0 ||
       (iVar1 = EVP_DigestFinal_ex(&local_fc.md_ctx,auStack_13c,&local_140), iVar1 == 0)))) ||
     ((iVar1 = EVP_MD_CTX_copy_ex(&local_fc.md_ctx,&local_fc.o_ctx), iVar1 == 0 ||
      ((iVar1 = EVP_DigestUpdate(&local_fc.md_ctx,auStack_13c,local_140), iVar1 == 0 ||
       (iVar1 = EVP_DigestFinal_ex(&local_fc.md_ctx,md,md_len), iVar1 == 0)))))) {
    EVP_MD_CTX_cleanup(&local_fc.i_ctx);
    EVP_MD_CTX_cleanup(&local_fc.o_ctx);
    EVP_MD_CTX_cleanup(&local_fc.md_ctx);
    memset(&local_fc,0,0xd0);
    md = (uchar *)0x0;
  }
  else {
    EVP_MD_CTX_cleanup(&local_fc.i_ctx);
    EVP_MD_CTX_cleanup(&local_fc.o_ctx);
    EVP_MD_CTX_cleanup(&local_fc.md_ctx);
    memset(&local_fc,0,0xd0);
  }
  if (local_2c == __stack_chk_guard) {
    return md;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

