
undefined4 ssl3_send_newsession_ticket(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined uVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *local_1b8;
  undefined *local_1b4;
  undefined *local_1b0;
  int local_1ac;
  undefined auStack_1a8 [140];
  undefined auStack_11c [208];
  undefined auStack_4c [16];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (*(int *)(param_1 + 0x34) == 0x21f0) {
    iVar6 = *(int *)(param_1 + 0x170);
    iVar3 = (*(code *)PTR_i2d_SSL_SESSION_006a7c88)(*(undefined4 *)(param_1 + 0xc0),0);
    if ((iVar3 != 0) && (iVar3 < 0xff01)) {
      puVar7 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"s3_srvr.c",0xd4c);
      if (puVar7 != (undefined *)0x0) {
        (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_1a8);
        (*(code *)PTR_HMAC_CTX_init_006a7a1c)(auStack_11c);
        local_1b8 = puVar7;
        iVar4 = (*(code *)PTR_i2d_SSL_SESSION_006a7c88)(*(undefined4 *)(param_1 + 0xc0),&local_1b8);
        if (iVar4 != 0) {
          local_1b4 = puVar7;
          iVar4 = (*(code *)PTR_d2i_SSL_SESSION_006a7c80)(0,&local_1b4,iVar3);
          puVar9 = PTR_i2d_SSL_SESSION_006a7c88;
          if (iVar4 != 0) {
            *(undefined4 *)(iVar4 + 0x44) = 0;
            iVar5 = (*(code *)puVar9)(iVar4,0);
            if ((iVar5 == 0) || (iVar3 < iVar5)) {
              (*(code *)PTR_SSL_SESSION_free_006a79b4)(iVar4);
            }
            else {
              local_1b8 = puVar7;
              iVar3 = (*(code *)PTR_i2d_SSL_SESSION_006a7c88)(iVar4,&local_1b8);
              if (iVar3 == 0) {
                (*(code *)PTR_SSL_SESSION_free_006a79b4)(iVar4);
              }
              else {
                (*(code *)PTR_SSL_SESSION_free_006a79b4)();
                iVar3 = (*(code *)PTR_BUF_MEM_grow_006a74a0)
                                  (*(undefined4 *)(param_1 + 0x3c),iVar5 + 0x8a);
                if (iVar3 != 0) {
                  local_1b8 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
                  *local_1b8 = 4;
                  local_1b8 = local_1b8 + 4;
                  if (*(code **)(iVar6 + 0x138) == (code *)0x0) {
                    iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_4c,0x10);
                    if (0 < iVar3) {
                      uVar2 = (*(code *)PTR_EVP_aes_128_cbc_006a72a8)();
                      iVar3 = (*(code *)PTR_EVP_EncryptInit_ex_006a7a98)
                                        (auStack_1a8,uVar2,0,iVar6 + 0x128,auStack_4c);
                      if (iVar3 != 0) {
                        uVar2 = (*(code *)PTR_EVP_sha256_006a8000)();
                        iVar3 = (*(code *)PTR_HMAC_Init_ex_006a7acc)
                                          (auStack_11c,iVar6 + 0x118,0x10,uVar2,0);
                        if (iVar3 != 0) {
                          local_3c = *(undefined4 *)(iVar6 + 0x108);
                          local_38 = *(undefined4 *)(iVar6 + 0x10c);
                          local_34 = *(undefined4 *)(iVar6 + 0x110);
                          local_30 = *(undefined4 *)(iVar6 + 0x114);
                          goto LAB_0047d880;
                        }
                      }
                    }
                  }
                  else {
                    iVar3 = (**(code **)(iVar6 + 0x138))
                                      (param_1,&local_3c,auStack_4c,auStack_1a8,auStack_11c,1);
                    if (-1 < iVar3) {
LAB_0047d880:
                      if (*(int *)(param_1 + 0x6c) == 0) {
                        *local_1b8 = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xa8);
                        if (*(int *)(param_1 + 0x6c) != 0) goto LAB_0047db50;
LAB_0047d8b0:
                        local_1b8[1] = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xa9);
                        if (*(int *)(param_1 + 0x6c) == 0) goto LAB_0047d8d0;
LAB_0047db6c:
                        local_1b8[2] = 0;
                        if (*(int *)(param_1 + 0x6c) != 0) goto LAB_0047db88;
LAB_0047d8f0:
                        uVar8 = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xab);
                      }
                      else {
                        *local_1b8 = 0;
                        if (*(int *)(param_1 + 0x6c) == 0) goto LAB_0047d8b0;
LAB_0047db50:
                        local_1b8[1] = 0;
                        if (*(int *)(param_1 + 0x6c) != 0) goto LAB_0047db6c;
LAB_0047d8d0:
                        local_1b8[2] = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xaa);
                        if (*(int *)(param_1 + 0x6c) == 0) goto LAB_0047d8f0;
LAB_0047db88:
                        uVar8 = 0;
                      }
                      local_1b8[3] = uVar8;
                      puVar9 = local_1b8 + 6;
                      *(undefined4 *)(local_1b8 + 6) = local_3c;
                      *(undefined4 *)(local_1b8 + 10) = local_38;
                      *(undefined4 *)(local_1b8 + 0xe) = local_34;
                      *(undefined4 *)(local_1b8 + 0x12) = local_30;
                      puVar10 = local_1b8 + 0x16;
                      local_1b8 = puVar10;
                      uVar2 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a7ff8)(auStack_1a8);
                      (*(code *)PTR_memcpy_006a9aec)(puVar10,auStack_4c,uVar2);
                      iVar3 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a7ff8)(auStack_1a8);
                      local_1b8 = local_1b8 + iVar3;
                      iVar3 = (*(code *)PTR_EVP_EncryptUpdate_006a7aa0)
                                        (auStack_1a8,local_1b8,&local_1b0,puVar7,iVar5);
                      if (iVar3 != 0) {
                        local_1b8 = local_1b8 + (int)local_1b0;
                        iVar3 = (*(code *)PTR_EVP_EncryptFinal_006a7ffc)
                                          (auStack_1a8,local_1b8,&local_1b0);
                        if (iVar3 != 0) {
                          local_1b8 = local_1b8 + (int)local_1b0;
                          iVar3 = (*(code *)PTR_HMAC_Update_006a7ad0)
                                            (auStack_11c,puVar9,(int)local_1b8 - (int)puVar9);
                          if (iVar3 != 0) {
                            iVar3 = (*(code *)PTR_HMAC_Final_006a7ad4)
                                              (auStack_11c,local_1b8,&local_1ac);
                            if (iVar3 != 0) {
                              (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1a8);
                              (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(auStack_11c);
                              puVar9 = PTR_CRYPTO_free_006a6e88;
                              iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
                              local_1b0 = local_1b8 + (local_1ac - iVar3);
                              *(char *)(iVar3 + 1) = (char)((uint)(local_1b0 + -4) >> 0x10);
                              *(char *)(iVar3 + 2) = (char)((uint)(local_1b0 + -4) >> 8);
                              *(char *)(iVar3 + 3) = (char)local_1b0 + -4;
                              local_1b8 = (undefined *)(iVar3 + 10);
                              *(char *)(iVar3 + 9) = (char)(local_1b0 + -10);
                              *(char *)(iVar3 + 8) = (char)((uint)(local_1b0 + -10) >> 8);
                              *(undefined **)(param_1 + 0x44) = local_1b0;
                              *(undefined4 *)(param_1 + 0x48) = 0;
                              *(undefined4 *)(param_1 + 0x34) = 0x21f1;
                              (*(code *)puVar9)(puVar7);
                              goto LAB_0047d6a8;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(puVar7);
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1a8);
        (*(code *)PTR_HMAC_CTX_cleanup_006a7adc)(auStack_11c);
      }
    }
    uVar2 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
  else {
LAB_0047d6a8:
    uVar2 = ssl3_do_write(param_1,0x16);
  }
  if (local_2c == *(int *)puVar1) {
    return uVar2;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(iVar3 + 0x34) != 0x2200) {
    uVar2 = ssl3_do_write(iVar3,0x16);
    return uVar2;
  }
  iVar6 = (*(code *)PTR_BUF_MEM_grow_006a74a0)
                    (*(undefined4 *)(iVar3 + 0x3c),*(int *)(iVar3 + 0x13c) + 8);
  puVar1 = PTR_memcpy_006a9aec;
  if (iVar6 != 0) {
    puVar7 = *(undefined **)(*(int *)(iVar3 + 0x3c) + 4);
    *puVar7 = 0x16;
    puVar7[1] = (char)((uint)(*(int *)(iVar3 + 0x13c) + 4) >> 0x10);
    puVar7[2] = (char)((uint)(*(int *)(iVar3 + 0x13c) + 4) >> 8);
    puVar7[3] = (char)*(undefined4 *)(iVar3 + 0x13c) + '\x04';
    puVar7[4] = (char)*(undefined4 *)(iVar3 + 0x128);
    puVar7[5] = (char)*(undefined2 *)(iVar3 + 0x13c);
    puVar7[6] = (char)((uint)*(undefined4 *)(iVar3 + 0x13c) >> 8);
    puVar7[7] = (char)*(undefined4 *)(iVar3 + 0x13c);
    (*(code *)puVar1)(puVar7 + 8,*(undefined4 *)(iVar3 + 0x138),*(undefined4 *)(iVar3 + 0x13c));
    *(undefined4 *)(iVar3 + 0x48) = 0;
    *(undefined4 *)(iVar3 + 0x34) = 0x2201;
    *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x13c) + 8;
    uVar2 = ssl3_do_write(iVar3,0x16);
    return uVar2;
  }
  *(undefined4 *)(iVar3 + 0x34) = 5;
  return 0xffffffff;
}

