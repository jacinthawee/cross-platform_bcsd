
int RSA_verify_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (*(code *)PTR_RSA_size_006a7640)(rsa);
  if (uVar2 != siglen) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x78,0x77,"rsa_saos.c",0x74);
    iVar3 = 0;
    goto LAB_005f91bc;
  }
  iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar2,"rsa_saos.c",0x78);
  if (iVar5 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x78,0x41,"rsa_saos.c",0x7a);
    iVar3 = 0;
    goto LAB_005f91bc;
  }
  iVar3 = (*(code *)PTR_RSA_public_decrypt_006a7650)(uVar2,sigbuf,iVar5,rsa,1);
  if (iVar3 < 1) {
LAB_005f92c0:
    iVar3 = 0;
  }
  else {
    local_30 = iVar5;
    puVar4 = (uint *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(0,&local_30,iVar3);
    if (puVar4 == (uint *)0x0) goto LAB_005f92c0;
    if (*puVar4 == m_length) {
      iVar3 = (*(code *)PTR_memcmp_006a9ad0)(m,puVar4[2]);
      if (iVar3 != 0) goto LAB_005f9284;
      iVar3 = 1;
    }
    else {
LAB_005f9284:
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x78,0x68,"rsa_saos.c",0x89);
    }
    (*(code *)PTR_ASN1_STRING_free_006a879c)(puVar4);
  }
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar5,uVar2);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
LAB_005f91bc:
  if (local_2c == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar5 = (*(code *)PTR_ERR_func_error_string_006a8440)(RSA_str_functs._0_4_);
  if (iVar5 != 0) {
    return iVar5;
  }
  (*(code *)PTR_ERR_load_strings_006a8444)(0,RSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005f93a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar5 = (*(code *)PTR_ERR_load_strings_006a8444)(0,RSA_str_reasons);
  return iVar5;
}

