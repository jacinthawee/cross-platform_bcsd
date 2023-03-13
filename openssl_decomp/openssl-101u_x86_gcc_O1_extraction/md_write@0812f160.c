
size_t md_write(BIO *param_1,void *param_2,int param_3)

{
  EVP_MD_CTX *ctx;
  size_t cnt;
  int iVar1;
  
  if ((param_2 == (void *)0x0) || (param_3 < 1)) {
    return 0;
  }
  ctx = (EVP_MD_CTX *)param_1->ptr;
  if (ctx == (EVP_MD_CTX *)0x0) {
    cnt = 0;
  }
  else {
    if (param_1->next_bio == (BIO *)0x0) {
      return 0;
    }
    cnt = BIO_write(param_1->next_bio,param_2,param_3);
    if (((param_1->init != 0) && (0 < (int)cnt)) &&
       (iVar1 = EVP_DigestUpdate(ctx,param_2,cnt), iVar1 == 0)) {
      BIO_clear_flags(param_1,0xf);
      return 0;
    }
  }
  if (param_1->next_bio != (bio_st *)0x0) {
    BIO_clear_flags(param_1,0xf);
    BIO_copy_next_retry(param_1);
  }
  return cnt;
}

