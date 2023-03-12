
int RSA_verify_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_RSA_size_006a8730)(rsa);
  if (uVar2 != siglen) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x78,0x77,"rsa_saos.c",0x74);
    iVar3 = 0;
    goto LAB_005fb08c;
  }
  iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2,"rsa_saos.c",0x78);
  if (iVar5 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x78,0x41,"rsa_saos.c",0x7b);
    iVar3 = 0;
    goto LAB_005fb08c;
  }
  iVar3 = (*(code *)PTR_RSA_public_decrypt_006a8740)(uVar2,sigbuf,iVar5,rsa,1);
  if (iVar3 < 1) {
LAB_005fb190:
    iVar3 = 0;
  }
  else {
    local_30 = iVar5;
    puVar4 = (uint *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(0,&local_30,iVar3);
    if (puVar4 == (uint *)0x0) goto LAB_005fb190;
    if (*puVar4 == m_length) {
      iVar3 = (*(code *)PTR_memcmp_006aabd8)(m,puVar4[2]);
      if (iVar3 != 0) goto LAB_005fb154;
      iVar3 = 1;
    }
    else {
LAB_005fb154:
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x78,0x68,"rsa_saos.c",0x89);
    }
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(puVar4);
  }
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar5,uVar2);
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
LAB_005fb08c:
  if (local_2c == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = (*(code *)PTR_ERR_func_error_string_006a9560)(RSA_str_functs._0_4_);
  if (iVar5 != 0) {
    return iVar5;
  }
  (*(code *)PTR_ERR_load_strings_006a9564)(0,RSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fb270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar5 = (*(code *)PTR_ERR_load_strings_006a9564)(0,RSA_str_reasons);
  return iVar5;
}

