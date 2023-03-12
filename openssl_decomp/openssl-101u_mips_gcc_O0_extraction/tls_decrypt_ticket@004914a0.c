
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar5 = *(int *)(param_1 + 0x170);
  (*(code *)PTR_HMAC_CTX_init_006a7a1c)(local_13c);
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_1c8);
  if (*(code **)(iVar5 + 0x138) == (code *)0x0) {
    iVar4 = (*(code *)PTR_memcmp_006a9ad0)(param_2,iVar5 + 0x108,0x10);
    if (iVar4 == 0) {
      uVar3 = (*(code *)PTR_EVP_sha256_006a8000)();
      iVar4 = (*(code *)PTR_HMAC_Init_ex_006a7acc)(local_13c,iVar5 + 0x118,0x10,uVar3,0);
      if (0 < iVar4) {
        uVar3 = (*(code *)PTR_EVP_aes_128_cbc_006a72a8)();
        iVar5 = (*(code *)PTR_EVP_DecryptInit_ex_006a7a68)
                          (auStack_1c8,uVar3,0,iVar5 + 0x128,param_2 + 0x10);
        if (0 < iVar5) {
          bVar1 = false;
          goto LAB_004915a0;
        }
      }
LAB_00491718:
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1c8);
      (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(local_13c);
      uVar3 = 0xffffffff;
      goto LAB_00491560;
    }
  }
  else {
    iVar5 = (**(code **)(iVar5 + 0x138))(param_1,param_2,param_2 + 0x10,auStack_1c8,local_13c,0);
    if (iVar5 < 0) {
      uVar3 = 0xffffffff;
      goto LAB_00491560;
    }
    if (iVar5 != 0) {
      bVar1 = iVar5 == 2;
LAB_004915a0:
      local_1cc = (*(code *)PTR_EVP_MD_size_006a7e3c)(local_13c[0]);
      if (-1 < local_1cc) {
        iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a7ff8)(auStack_1c8);
        if (param_3 <= iVar5 + 0x10 + local_1cc) {
          (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(local_13c);
          (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1c8);
          uVar3 = 2;
          goto LAB_00491560;
        }
        param_3 = param_3 - local_1cc;
        iVar5 = (*(code *)PTR_HMAC_Update_006a7ad0)(local_13c,param_2,param_3);
        if (0 < iVar5) {
          iVar5 = (*(code *)PTR_HMAC_Final_006a7ad4)(local_13c,auStack_6c,0);
          if (0 < iVar5) {
            (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(local_13c);
            iVar5 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(auStack_6c,param_2 + param_3,local_1cc);
            if (iVar5 != 0) {
              (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1c8);
              uVar3 = 2;
              goto LAB_00491560;
            }
            iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a7ff8)(auStack_1c8);
            local_1d4 = param_2 + iVar5 + 0x10;
            iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a7ff8)(auStack_1c8);
            param_3 = param_3 - (iVar5 + 0x10);
            iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(param_3,"t1_lib.c",0x926);
            if ((iVar5 == 0) ||
               (iVar4 = (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                                  (auStack_1c8,iVar5,&local_1d0,local_1d4,param_3), iVar4 < 1)) {
              (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1c8);
              (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
              uVar3 = 0xffffffff;
              goto LAB_00491560;
            }
            iVar4 = (*(code *)PTR_EVP_DecryptFinal_006a819c)
                              (auStack_1c8,iVar5 + local_1d0,&local_1cc);
            if (iVar4 < 1) {
              (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1c8);
              (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
              uVar3 = 2;
              goto LAB_00491560;
            }
            local_1d0 = local_1d0 + local_1cc;
            (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1c8);
            local_1d4 = iVar5;
            iVar4 = (*(code *)PTR_d2i_SSL_SESSION_006a7c80)(0,&local_1d4,local_1d0);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
            if (iVar4 != 0) {
              if (param_5 == 0) {
                param_5 = 0;
              }
              else {
                (*(code *)PTR_memcpy_006a9aec)(iVar4 + 0x48,param_4,param_5);
              }
              uVar3 = 4;
              *(int *)(iVar4 + 0x44) = param_5;
              *param_6 = iVar4;
              if (!bVar1) {
                uVar3 = 3;
              }
              goto LAB_00491560;
            }
            (*(code *)PTR_ERR_clear_error_006a6ee0)();
            goto LAB_0049155c;
          }
        }
      }
      goto LAB_00491718;
    }
  }
LAB_0049155c:
  uVar3 = 2;
LAB_00491560:
  if (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return 0x1c20;
  }
  return uVar3;
}

