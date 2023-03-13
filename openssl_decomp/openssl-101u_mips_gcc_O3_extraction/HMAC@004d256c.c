
uchar * HMAC(EVP_MD *evp_md,void *key,int key_len,uchar *d,size_t n,uchar *md,uint *md_len)

{
  undefined *puVar1;
  int iVar2;
  uchar *puVar3;
  undefined *puVar4;
  undefined4 local_140;
  undefined local_13c [28];
  undefined auStack_120 [24];
  uchar auStack_108 [156];
  uchar auStack_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (md == (uchar *)0x0) {
    md = m_8521;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_120);
  puVar4 = local_13c + 4;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_108);
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puVar4);
  local_13c._0_4_ = (EVP_MD *)0x0;
  if ((key != (void *)0x0) && (evp_md != (EVP_MD *)0x0)) {
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_120);
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_108);
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puVar4);
  }
  local_13c._0_4_ = (EVP_MD *)0x0;
  iVar2 = HMAC_Init_ex((HMAC_CTX *)local_13c,key,key_len,evp_md,(ENGINE *)0x0);
  if ((iVar2 != 0) && (local_13c._0_4_ != (EVP_MD *)0x0)) {
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(puVar4,d,n);
    key = d;
    if ((iVar2 != 0) && (key = d, local_13c._0_4_ != (EVP_MD *)0x0)) {
      puVar3 = auStack_6c;
      key = puVar3;
      iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(puVar4,puVar3,&local_140);
      if (iVar2 != 0) {
        key = auStack_108;
        iVar2 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(puVar4,auStack_108);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(puVar4,puVar3,local_140);
          key = puVar3;
          if (iVar2 != 0) {
            key = md;
            iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(puVar4,md,md_len);
            if (iVar2 != 0) {
              (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_120);
              (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_108);
              (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(puVar4);
              goto LAB_004d26ec;
            }
          }
        }
      }
    }
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_120);
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_108);
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(puVar4);
  md = (uchar *)0x0;
LAB_004d26ec:
  if (local_2c == *(int *)puVar1) {
    return md;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(iVar2 + 0x1c);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(iVar2 + 0x34,key);
                    /* WARNING: Could not recover jumptable at 0x004d2828. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar3 = (uchar *)(*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(iVar2 + 4,key);
  return puVar3;
}

