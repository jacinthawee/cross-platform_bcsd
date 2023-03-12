
int ssl3_setup_key_block(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined auStack_80 [24];
  undefined auStack_68 [24];
  char local_50;
  char local_4f;
  char local_4e;
  char local_4d;
  char local_4c;
  char local_4b;
  char local_4a;
  char local_49;
  char local_48;
  char local_47;
  char local_46;
  char local_45;
  char local_44;
  char local_43;
  char local_42;
  char local_41;
  undefined auStack_40 [20];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar10 = *(int *)(*(int *)(param_1 + 0x58) + 0x374);
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (iVar10 == 0) {
    iVar7 = (*(code *)PTR_ssl_cipher_get_evp_006a80e8)
                      (*(undefined4 *)(param_1 + 0xc0),&local_8c,&local_88,0,0,&local_84);
    puVar1 = PTR_EVP_MD_size_006a7e3c;
    if (iVar7 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9d,0x8a,"s3_enc.c",0x196);
    }
    else {
      iVar7 = *(int *)(param_1 + 0x58);
      *(undefined4 *)(iVar7 + 0x380) = local_88;
      *(undefined4 *)(iVar7 + 0x37c) = local_8c;
      *(undefined4 *)(iVar7 + 0x38c) = local_84;
      iVar7 = (*(code *)puVar1)(local_88);
      if (-1 < iVar7) {
        iVar3 = (*(code *)PTR_EVP_CIPHER_key_length_006a7554)(local_8c);
        iVar4 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(local_8c);
        iVar8 = *(int *)(param_1 + 0x58);
        iVar7 = (iVar7 + iVar3 + iVar4) * 2;
        if (*(int *)(iVar8 + 0x378) != 0) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)
                    (*(int *)(iVar8 + 0x378),*(undefined4 *)(iVar8 + 0x374));
          (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x378));
          iVar8 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(iVar8 + 0x378) = 0;
        }
        puVar1 = PTR_CRYPTO_malloc_006a7008;
        *(undefined4 *)(iVar8 + 0x374) = 0;
        iVar3 = (*(code *)puVar1)(iVar7,"s3_enc.c",0x1ab);
        puVar1 = PTR_EVP_MD_CTX_init_006a6e1c;
        if (iVar3 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9d,0x41,"s3_enc.c",0x1c8);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x58);
          *(int *)(iVar4 + 0x374) = iVar7;
          *(int *)(iVar4 + 0x378) = iVar3;
          (*(code *)puVar1)(auStack_80);
          (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(auStack_80,8);
          (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_68);
          if (iVar7 < 1) {
LAB_00487f48:
            iVar10 = 1;
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_40,0x14);
            (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_80);
            (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_68);
          }
          else {
            iVar8 = 1;
            local_50 = 'A';
            iVar4 = 0;
            while( true ) {
              cVar9 = local_50 + '\x01';
              iVar5 = iVar3 + iVar4;
              iVar4 = iVar4 + 0x10;
              uVar6 = (*(code *)PTR_EVP_sha1_006a75d0)();
              (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_68,uVar6,0);
              (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_68,&local_50,iVar8);
              (*(code *)PTR_EVP_DigestUpdate_006a7580)
                        (auStack_68,*(int *)(param_1 + 0xc0) + 0x14,
                         *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10));
              (*(code *)PTR_EVP_DigestUpdate_006a7580)
                        (auStack_68,*(int *)(param_1 + 0x58) + 0xa0,0x20);
              (*(code *)PTR_EVP_DigestUpdate_006a7580)
                        (auStack_68,*(int *)(param_1 + 0x58) + 0xc0,0x20);
              (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_68,auStack_40,0);
              uVar6 = (*(code *)PTR_EVP_md5_006a70c8)();
              (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_80,uVar6,0);
              (*(code *)PTR_EVP_DigestUpdate_006a7580)
                        (auStack_80,*(int *)(param_1 + 0xc0) + 0x14,
                         *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10));
              (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_80,auStack_40,0x14);
              if (iVar7 < iVar4) {
                (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_80,auStack_40,0);
                (*(code *)PTR_memcpy_006a9aec)(iVar5,auStack_40,(iVar7 + 0x10) - iVar4);
              }
              else {
                (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_80,iVar5);
              }
              if (iVar7 <= iVar4) goto LAB_00487f48;
              iVar8 = iVar8 + 1;
              if (iVar4 == 0x100) break;
              local_50 = cVar9;
              local_4f = cVar9;
              if (((((iVar8 != 2) && (local_4e = cVar9, iVar8 != 3)) &&
                   (local_4d = cVar9, iVar8 != 4)) &&
                  ((((local_4c = cVar9, iVar8 != 5 && (local_4b = cVar9, iVar8 != 6)) &&
                    ((local_4a = cVar9, iVar8 != 7 &&
                     ((local_49 = cVar9, iVar8 != 8 && (local_48 = cVar9, iVar8 != 9)))))) &&
                   (local_47 = cVar9, iVar8 != 10)))) &&
                 ((((local_46 = cVar9, iVar8 != 0xb && (local_45 = cVar9, iVar8 != 0xc)) &&
                   (local_44 = cVar9, iVar8 != 0xd)) &&
                  ((local_43 = cVar9, iVar8 != 0xe && (local_42 = cVar9, iVar8 == 0x10)))))) {
                local_41 = cVar9;
              }
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xee,0x44,"s3_enc.c",0xb6);
          }
          if ((*(uint *)(param_1 + 0x100) & 0x800) == 0) {
            iVar3 = *(int *)(param_1 + 0x58);
            iVar7 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
            *(undefined4 *)(iVar3 + 0xe0) = 1;
            if ((iVar7 != 0) && ((iVar7 = *(int *)(iVar7 + 0x14), iVar7 == 0x20 || (iVar7 == 4)))) {
              *(undefined4 *)(iVar3 + 0xe0) = 0;
            }
          }
        }
      }
    }
  }
  else {
    iVar10 = 1;
  }
  if (local_2c == *(int *)puVar2) {
    return iVar10;
  }
  iVar10 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar7 = *(int *)(iVar10 + 0x58);
  if (*(int *)(iVar7 + 0x378) == 0) {
    *(undefined4 *)(iVar7 + 0x374) = 0;
    return iVar7;
  }
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(*(int *)(iVar7 + 0x378),*(undefined4 *)(iVar7 + 0x374));
  (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(*(int *)(iVar10 + 0x58) + 0x378));
  iVar10 = *(int *)(iVar10 + 0x58);
  *(undefined4 *)(iVar10 + 0x378) = 0;
  *(undefined4 *)(iVar10 + 0x374) = 0;
  return iVar10;
}

