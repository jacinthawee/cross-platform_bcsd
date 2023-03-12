
undefined4 ssl3_send_newsession_ticket(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  undefined uVar9;
  undefined *puVar10;
  undefined *puVar11;
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
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(param_1 + 0x34) != 0x21f0) {
LAB_004820ac:
    uVar3 = ssl3_do_write(param_1,0x16);
    goto LAB_004820c0;
  }
  iVar7 = *(int *)(param_1 + 0x170);
  iVar4 = (*(code *)PTR_i2d_SSL_SESSION_006a8d78)(*(undefined4 *)(param_1 + 0xc0),0);
  if (iVar4 < 0xff01) {
    puVar8 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,"s3_srvr.c",0xd31);
    if (puVar8 != (undefined *)0x0) {
      local_1b8 = puVar8;
      (*(code *)PTR_i2d_SSL_SESSION_006a8d78)(*(undefined4 *)(param_1 + 0xc0),&local_1b8);
      local_1b4 = puVar8;
      iVar5 = (*(code *)PTR_d2i_SSL_SESSION_006a8d70)(0,&local_1b4,iVar4);
      puVar1 = PTR_i2d_SSL_SESSION_006a8d78;
      if (iVar5 != 0) {
        *(undefined4 *)(iVar5 + 0x44) = 0;
        iVar6 = (*(code *)puVar1)(iVar5,0);
        if (iVar6 <= iVar4) {
          local_1b8 = puVar8;
          (*(code *)PTR_i2d_SSL_SESSION_006a8d78)(iVar5,&local_1b8);
          (*(code *)PTR_SSL_SESSION_free_006a8aa0)(iVar5);
          iVar4 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(*(undefined4 *)(param_1 + 0x3c),iVar6 + 0x8a)
          ;
          puVar1 = PTR_EVP_CIPHER_CTX_init_006a8b50;
          if (iVar4 != 0) {
            local_1b8 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
            *local_1b8 = 4;
            local_1b8 = local_1b8 + 4;
            (*(code *)puVar1)(auStack_1a8);
            (*(code *)PTR_HMAC_CTX_init_006a8b0c)(auStack_11c);
            if (*(code **)(iVar7 + 0x138) == (code *)0x0) {
              (*(code *)PTR_RAND_pseudo_bytes_006a8664)(auStack_4c,0x10);
              uVar3 = (*(code *)PTR_EVP_aes_128_cbc_006a83b4)();
              (*(code *)PTR_EVP_EncryptInit_ex_006a8b84)
                        (auStack_1a8,uVar3,0,iVar7 + 0x128,auStack_4c);
              uVar3 = (*(code *)PTR_EVP_sha256_006a916c)();
              (*(code *)PTR_HMAC_Init_ex_006a8ba0)(auStack_11c,iVar7 + 0x118,0x10,uVar3,0);
              local_3c = *(undefined4 *)(iVar7 + 0x108);
              local_38 = *(undefined4 *)(iVar7 + 0x10c);
              local_34 = *(undefined4 *)(iVar7 + 0x110);
              local_30 = *(undefined4 *)(iVar7 + 0x114);
            }
            else {
              iVar4 = (**(code **)(iVar7 + 0x138))
                                (param_1,&local_3c,auStack_4c,auStack_1a8,auStack_11c,1);
              if (iVar4 < 0) goto LAB_004824dc;
            }
            if (*(int *)(param_1 + 0x6c) == 0) {
              uVar9 = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xa8);
            }
            else {
              uVar9 = 0;
            }
            *local_1b8 = uVar9;
            if (*(int *)(param_1 + 0x6c) == 0) {
              uVar9 = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xa9);
            }
            else {
              uVar9 = 0;
            }
            local_1b8[1] = uVar9;
            if (*(int *)(param_1 + 0x6c) == 0) {
              uVar9 = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xaa);
            }
            else {
              uVar9 = 0;
            }
            local_1b8[2] = uVar9;
            if (*(int *)(param_1 + 0x6c) == 0) {
              uVar9 = *(undefined *)(*(int *)(param_1 + 0xc0) + 0xab);
            }
            else {
              uVar9 = 0;
            }
            local_1b8[3] = uVar9;
            puVar1 = PTR_EVP_CIPHER_CTX_iv_length_006a9164;
            puVar11 = local_1b8 + 6;
            *(undefined4 *)(local_1b8 + 6) = local_3c;
            *(undefined4 *)(local_1b8 + 10) = local_38;
            *(undefined4 *)(local_1b8 + 0xe) = local_34;
            *(undefined4 *)(local_1b8 + 0x12) = local_30;
            puVar10 = local_1b8 + 0x16;
            local_1b8 = puVar10;
            uVar3 = (*(code *)puVar1)(auStack_1a8);
            (*(code *)PTR_memcpy_006aabf4)(puVar10,auStack_4c,uVar3);
            iVar4 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(auStack_1a8);
            local_1b8 = local_1b8 + iVar4;
            (*(code *)PTR_EVP_EncryptUpdate_006a8b8c)(auStack_1a8,local_1b8,&local_1b0,puVar8,iVar6)
            ;
            local_1b8 = local_1b8 + (int)local_1b0;
            (*(code *)PTR_EVP_EncryptFinal_006a9168)(auStack_1a8,local_1b8,&local_1b0);
            local_1b8 = local_1b8 + (int)local_1b0;
            (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_1a8);
            (*(code *)PTR_HMAC_Update_006a8ba4)(auStack_11c,puVar11,(int)local_1b8 - (int)puVar11);
            (*(code *)PTR_HMAC_Final_006a8ba8)(auStack_11c,local_1b8,&local_1ac);
            (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_11c);
            puVar1 = PTR_CRYPTO_free_006a7f88;
            iVar4 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
            local_1b0 = local_1b8 + (local_1ac - iVar4);
            *(char *)(iVar4 + 1) = (char)((uint)(local_1b0 + -4) >> 0x10);
            *(char *)(iVar4 + 2) = (char)((uint)(local_1b0 + -4) >> 8);
            *(char *)(iVar4 + 3) = (char)local_1b0 + -4;
            local_1b8 = (undefined *)(iVar4 + 10);
            *(char *)(iVar4 + 9) = (char)(local_1b0 + -10);
            *(char *)(iVar4 + 8) = (char)((uint)(local_1b0 + -10) >> 8);
            *(undefined **)(param_1 + 0x44) = local_1b0;
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(undefined4 *)(param_1 + 0x34) = 0x21f1;
            (*(code *)puVar1)(puVar8);
            goto LAB_004820ac;
          }
          goto LAB_004824ec;
        }
      }
LAB_004824dc:
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar8);
    }
  }
LAB_004824ec:
  uVar3 = 0xffffffff;
LAB_004820c0:
  if (local_2c == *(int *)puVar2) {
    return uVar3;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar4 + 0x34) != 0x2200) {
    uVar3 = ssl3_do_write(iVar4,0x16);
    return uVar3;
  }
  iVar7 = (*(code *)PTR_BUF_MEM_grow_006a85a0)
                    (*(undefined4 *)(iVar4 + 0x3c),*(int *)(iVar4 + 0x13c) + 8);
  puVar2 = PTR_memcpy_006aabf4;
  if (iVar7 != 0) {
    puVar8 = *(undefined **)(*(int *)(iVar4 + 0x3c) + 4);
    *puVar8 = 0x16;
    puVar8[1] = (char)((uint)(*(int *)(iVar4 + 0x13c) + 4) >> 0x10);
    puVar8[2] = (char)((uint)(*(int *)(iVar4 + 0x13c) + 4) >> 8);
    puVar8[3] = (char)*(undefined4 *)(iVar4 + 0x13c) + '\x04';
    puVar8[4] = (char)*(undefined4 *)(iVar4 + 0x128);
    puVar8[5] = (char)*(undefined2 *)(iVar4 + 0x13c);
    puVar8[6] = (char)((uint)*(undefined4 *)(iVar4 + 0x13c) >> 8);
    puVar8[7] = (char)*(undefined4 *)(iVar4 + 0x13c);
    (*(code *)puVar2)(puVar8 + 8,*(undefined4 *)(iVar4 + 0x138),*(undefined4 *)(iVar4 + 0x13c));
    *(undefined4 *)(iVar4 + 0x48) = 0;
    *(undefined4 *)(iVar4 + 0x34) = 0x2201;
    *(int *)(iVar4 + 0x44) = *(int *)(iVar4 + 0x13c) + 8;
    uVar3 = ssl3_do_write(iVar4,0x16);
    return uVar3;
  }
  return 0xffffffff;
}

