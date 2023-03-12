
size_t md_gets(int param_1,uchar *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  EVP_MD_CTX *ctx;
  size_t local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  sVar3 = 0;
  if (((*(EVP_MD_CTX **)(param_1 + 0x20))->digest->md_size <= param_3) &&
     (iVar2 = EVP_DigestFinal_ex(*(EVP_MD_CTX **)(param_1 + 0x20),param_2,&local_10),
     sVar3 = local_10, iVar2 < 1)) {
    sVar3 = 0xffffffff;
  }
  if (local_c == *(int *)puVar1) {
    return sVar3;
  }
  iVar2 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (param_2 == (uchar *)0x0) {
    return 0;
  }
  ctx = *(EVP_MD_CTX **)(iVar2 + 0x20);
  if ((ctx != (EVP_MD_CTX *)0x0) && (*(int *)(iVar2 + 0x24) != 0)) {
    sVar3 = (*(code *)PTR_BIO_read_006a85bc)(*(int *)(iVar2 + 0x24));
    if (((*(int *)(iVar2 + 0xc) == 0) || ((int)sVar3 < 1)) ||
       (iVar4 = EVP_DigestUpdate(ctx,param_2,sVar3), 0 < iVar4)) {
      (*(code *)PTR_BIO_clear_flags_006a9260)(iVar2,0xf);
      (*(code *)PTR_BIO_copy_next_retry_006a9554)(iVar2);
    }
    else {
      sVar3 = 0xffffffff;
    }
    return sVar3;
  }
  return 0;
}

