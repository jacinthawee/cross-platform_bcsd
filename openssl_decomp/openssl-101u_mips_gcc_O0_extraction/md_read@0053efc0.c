
size_t md_read(BIO *param_1,void *param_2)

{
  size_t cnt;
  int iVar1;
  EVP_MD_CTX *ctx;
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  ctx = (EVP_MD_CTX *)param_1->ptr;
  if (ctx == (EVP_MD_CTX *)0x0) {
    return 0;
  }
  if (param_1->next_bio == (bio_st *)0x0) {
    return 0;
  }
  cnt = (*(code *)PTR_BIO_read_006a74c0)(param_1->next_bio);
  if (((param_1->init != 0) && (0 < (int)cnt)) &&
     (iVar1 = EVP_DigestUpdate(ctx,param_2,cnt), iVar1 < 1)) {
    return 0xffffffff;
  }
  (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf);
  BIO_copy_next_retry(param_1);
  return cnt;
}

