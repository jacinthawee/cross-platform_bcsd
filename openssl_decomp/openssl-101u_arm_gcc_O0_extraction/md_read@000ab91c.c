
BIO * md_read(BIO *param_1,void *param_2,int param_3)

{
  BIO *pBVar1;
  int iVar2;
  BIO *ctx;
  
  if (param_2 == (void *)0x0) {
    return (BIO *)0x0;
  }
  ctx = (BIO *)param_1->ptr;
  pBVar1 = ctx;
  if ((ctx != (BIO *)0x0) && (pBVar1 = param_1->next_bio, pBVar1 != (BIO *)0x0)) {
    pBVar1 = (BIO *)BIO_read(pBVar1,param_2,param_3);
    if ((param_1->init != 0) &&
       ((0 < (int)pBVar1 &&
        (iVar2 = EVP_DigestUpdate((EVP_MD_CTX *)ctx,param_2,(size_t)pBVar1), iVar2 < 1)))) {
      return (BIO *)0xffffffff;
    }
    BIO_clear_flags(param_1,0xf);
    BIO_copy_next_retry(param_1);
    return pBVar1;
  }
  return pBVar1;
}

