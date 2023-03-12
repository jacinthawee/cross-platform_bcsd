
undefined4
tls_decrypt_ticket(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int *param_6)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_1d4;
  int local_1d0;
  int local_1cc;
  undefined auStack_1c8 [140];
  undefined4 local_13c [52];
  undefined auStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (0x2f < param_3) {
    iVar5 = *(int *)(param_1 + 0x170);
    (*(code *)PTR_HMAC_CTX_init_006a8b0c)(local_13c);
    (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_1c8);
    if (*(code **)(iVar5 + 0x138) == (code *)0x0) {
      iVar4 = (*(code *)PTR_memcmp_006aabd8)(param_2,iVar5 + 0x108,0x10);
      if (iVar4 != 0) goto LAB_00495574;
      bVar1 = false;
      uVar3 = (*(code *)PTR_EVP_sha256_006a916c)();
      (*(code *)PTR_HMAC_Init_ex_006a8ba0)(local_13c,iVar5 + 0x118,0x10,uVar3,0);
      uVar3 = (*(code *)PTR_EVP_aes_128_cbc_006a83b4)();
      (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)(auStack_1c8,uVar3,0,iVar5 + 0x128,param_2 + 0x10);
    }
    else {
      iVar5 = (**(code **)(iVar5 + 0x138))(param_1,param_2,param_2 + 0x10,auStack_1c8,local_13c,0);
      if (iVar5 < 0) {
        uVar3 = 0xffffffff;
        goto LAB_00495578;
      }
      if (iVar5 == 0) goto LAB_00495574;
      bVar1 = iVar5 == 2;
    }
    local_1cc = (*(code *)PTR_EVP_MD_size_006a8f2c)(local_13c[0]);
    if (local_1cc < 0) {
LAB_0049583c:
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_1c8);
      uVar3 = 0xffffffff;
      goto LAB_00495578;
    }
    param_3 = param_3 - local_1cc;
    (*(code *)PTR_HMAC_Update_006a8ba4)(local_13c,param_2,param_3);
    (*(code *)PTR_HMAC_Final_006a8ba8)(local_13c,auStack_6c,0);
    (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(local_13c);
    iVar5 = (*(code *)PTR_CRYPTO_memcmp_006a9088)(auStack_6c,param_2 + param_3,local_1cc);
    if (iVar5 == 0) {
      iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(auStack_1c8);
      local_1d4 = param_2 + iVar5 + 0x10;
      iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(auStack_1c8);
      param_3 = param_3 - (iVar5 + 0x10);
      iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(param_3,"t1_lib.c",0x913);
      if (iVar5 == 0) goto LAB_0049583c;
      (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)(auStack_1c8,iVar5,&local_1d0,local_1d4,param_3);
      iVar4 = (*(code *)PTR_EVP_DecryptFinal_006a92cc)(auStack_1c8,iVar5 + local_1d0,&local_1cc);
      if (0 < iVar4) {
        local_1d0 = local_1d0 + local_1cc;
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_1c8);
        local_1d4 = iVar5;
        iVar4 = (*(code *)PTR_d2i_SSL_SESSION_006a8d70)(0,&local_1d4,local_1d0);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
        if (iVar4 == 0) goto LAB_0049587c;
        if (param_5 != 0) {
          (*(code *)PTR_memcpy_006aabf4)(iVar4 + 0x48,param_4,param_5);
        }
        *(int *)(iVar4 + 0x44) = param_5;
        uVar3 = 3;
        *param_6 = iVar4;
        if (!bVar1) goto LAB_00495578;
        uVar3 = 4;
        goto LAB_00495578;
      }
    }
  }
LAB_00495574:
  while( true ) {
    uVar3 = 2;
LAB_00495578:
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0049587c:
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
  }
  return uVar3;
}

