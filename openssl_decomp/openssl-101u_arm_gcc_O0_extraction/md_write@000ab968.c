
EVP_MD_CTX * md_write(BIO *param_1,void *param_2,int param_3)

{
  EVP_MD_CTX *cnt;
  int iVar1;
  bio_st *pbVar2;
  EVP_MD_CTX *unaff_r5;
  bool bVar3;
  bool bVar4;
  
  bVar3 = (int)param_2 < 0;
  bVar4 = param_2 == (void *)0x0;
  if (!bVar4) {
    bVar3 = param_3 < 0;
  }
  if ((bVar4 || param_3 == 0) || bVar3) {
    unaff_r5 = (EVP_MD_CTX *)0x0;
  }
  if ((!bVar4 && param_3 != 0) && !bVar3) {
    unaff_r5 = (EVP_MD_CTX *)param_1->ptr;
    if (unaff_r5 == (EVP_MD_CTX *)0x0) {
      pbVar2 = param_1->next_bio;
    }
    else {
      if (param_1->next_bio == (BIO *)0x0) {
        return (EVP_MD_CTX *)0x0;
      }
      cnt = (EVP_MD_CTX *)BIO_write(param_1->next_bio,param_2,param_3);
      if (((param_1->init != 0) && (0 < (int)cnt)) &&
         (iVar1 = EVP_DigestUpdate(unaff_r5,param_2,(size_t)cnt), iVar1 == 0)) {
        BIO_clear_flags(param_1,0xf);
        return (EVP_MD_CTX *)0x0;
      }
      pbVar2 = param_1->next_bio;
      unaff_r5 = cnt;
    }
    if (pbVar2 != (bio_st *)0x0) {
      BIO_clear_flags(param_1,0xf);
      BIO_copy_next_retry(param_1);
    }
  }
  return unaff_r5;
}

