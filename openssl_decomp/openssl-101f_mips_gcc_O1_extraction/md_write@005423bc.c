
size_t md_write(int param_1,void *param_2,int param_3)

{
  size_t cnt;
  int iVar1;
  EVP_MD_CTX *ctx;
  
  if ((param_2 == (void *)0x0) || (param_3 < 1)) {
    return 0;
  }
  ctx = *(EVP_MD_CTX **)(param_1 + 0x20);
  if (ctx == (EVP_MD_CTX *)0x0) {
    cnt = 0;
  }
  else {
    if (*(int *)(param_1 + 0x24) == 0) {
      return 0;
    }
    cnt = (*(code *)PTR_BIO_write_006a7f14)();
    if (((*(int *)(param_1 + 0xc) != 0) && (0 < (int)cnt)) &&
       (iVar1 = EVP_DigestUpdate(ctx,param_2,cnt), iVar1 == 0)) {
      (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
      return 0;
    }
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
    (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
  }
  return cnt;
}
