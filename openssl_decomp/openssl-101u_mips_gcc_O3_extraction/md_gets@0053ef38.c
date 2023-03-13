
size_t md_gets(int param_1,uchar *param_2,int param_3)

{
  undefined *puVar1;
  size_t sVar2;
  int iVar3;
  BIO *b;
  EVP_MD_CTX *ctx;
  size_t local_10;
  BIO *local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  sVar2 = 0;
  if (((*(EVP_MD_CTX **)(param_1 + 0x20))->digest->md_size <= param_3) &&
     (iVar3 = EVP_DigestFinal_ex(*(EVP_MD_CTX **)(param_1 + 0x20),param_2,&local_10),
     sVar2 = local_10, iVar3 < 1)) {
    sVar2 = 0xffffffff;
  }
  if (local_c == *(BIO **)puVar1) {
    return sVar2;
  }
  b = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (param_2 == (uchar *)0x0) {
    return 0;
  }
  ctx = (EVP_MD_CTX *)b->ptr;
  if ((ctx != (EVP_MD_CTX *)0x0) && (b->next_bio != (bio_st *)0x0)) {
    sVar2 = (*(code *)PTR_BIO_read_006a74c0)(b->next_bio);
    if (((b->init == 0) || ((int)sVar2 < 1)) ||
       (iVar3 = EVP_DigestUpdate(ctx,param_2,sVar2), 0 < iVar3)) {
      (*(code *)PTR_BIO_clear_flags_006a8138)(b,0xf);
      BIO_copy_next_retry(b);
    }
    else {
      sVar2 = 0xffffffff;
    }
    return sVar2;
  }
  return 0;
}

