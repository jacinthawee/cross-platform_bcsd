
undefined4 ssl3_send_client_key_exchange(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined *puVar12;
  int iVar13;
  code *pcVar14;
  undefined *puVar15;
  int iVar16;
  int *piVar17;
  undefined uVar18;
  uint local_2dc;
  undefined auStack_2d8 [4];
  undefined auStack_2d4 [32];
  undefined auStack_2b4 [129];
  undefined local_233;
  undefined local_230 [516];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_1[0xd] != 0x1180) goto LAB_0048268c;
  puVar15 = *(undefined **)(param_1[0xf] + 4);
  uVar3 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  puVar12 = puVar15 + 4;
  if ((uVar3 & 1) == 0) {
    if ((uVar3 & 0xe) == 0) {
      if ((uVar3 & 0xe0) != 0) {
        iVar4 = *(int *)(param_1[0x30] + 0x98);
        if (iVar4 == 0) {
          ssl3_send_alert(param_1,2,10);
          uVar11 = 0xf4;
          uVar5 = 0xa65;
          goto LAB_00482d24;
        }
        iVar16 = *(int *)(iVar4 + 0x74);
        if (iVar16 == 0) {
          piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar4 + 0x48));
          if (((piVar17 == (int *)0x0) || (*piVar17 != 0x198)) || (iVar16 = piVar17[5], iVar16 == 0)
             ) {
            uVar11 = 0x44;
            uVar5 = 0xa90;
            goto LAB_00482f4c;
          }
        }
        else {
          piVar17 = (int *)0x0;
        }
        iVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar16);
        iVar16 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar16);
        if ((iVar4 == 0) || (iVar16 == 0)) {
          uVar11 = 0x44;
          uVar5 = 0xa9c;
LAB_00482f4c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar11,"s3_clnt.c",uVar5);
          goto LAB_00482d3c;
        }
        iVar6 = (*(code *)PTR_EC_KEY_new_006a71a8)();
        if (iVar6 == 0) {
          uVar11 = 0x41;
          uVar5 = 0xaa2;
          goto LAB_00482f4c;
        }
        iVar13 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar6,iVar4);
        if (iVar13 == 0) {
          uVar11 = 0x10;
          uVar5 = 0xaa7;
        }
        else {
          iVar13 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar6);
          if (iVar13 == 0) {
            uVar11 = 0x2b;
            uVar5 = 0xabf;
          }
          else {
            iVar13 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(iVar4);
            if (iVar13 < 1) {
              uVar11 = 0x2b;
              uVar5 = 0xacb;
            }
            else {
              iVar16 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                                 (puVar12,iVar13 + 7 >> 3,iVar16,iVar6,0);
              if (0 < iVar16) {
                iVar13 = param_1[0x30];
                uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar13 + 0x14,puVar12,iVar16);
                puVar1 = PTR_memset_006a99f4;
                *(undefined4 *)(iVar13 + 0x10) = uVar5;
                (*(code *)puVar1)(puVar12,0,iVar16);
                uVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar6);
                uVar5 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar4,uVar5,4,0,0,0);
                iVar16 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar5,"s3_clnt.c",0xaed);
                iVar7 = (*(code *)PTR_BN_CTX_new_006a794c)();
                if (iVar16 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(iVar7);
                  goto LAB_00482dec;
                }
                if (iVar7 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(0);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar16);
                  goto LAB_00482dec;
                }
                uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar6);
                iVar4 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)
                                  (iVar4,uVar11,4,iVar16,uVar5,iVar7);
                puVar15[4] = (char)iVar4;
                iVar13 = iVar4 + 1;
                (*(code *)PTR_memcpy_006a9aec)(puVar15 + 5,iVar16,iVar4);
                (*(code *)PTR_BN_CTX_free_006a7954)(iVar7);
                (*(code *)PTR_CRYPTO_free_006a6e88)(iVar16);
                (*(code *)PTR_EC_KEY_free_006a71d4)(iVar6);
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
                goto LAB_00482658;
              }
              uVar11 = 0x2b;
              uVar5 = 0xad1;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar11,"s3_clnt.c",uVar5);
        (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482dec:
        (*(code *)PTR_EC_KEY_free_006a71d4)(iVar6);
        goto LAB_00482d4c;
      }
      if ((uVar3 & 0x200) == 0) {
        if ((uVar3 & 0x400) == 0) {
          if ((uVar3 & 0x100) == 0) goto LAB_004833a8;
          pcVar14 = (code *)param_1[0x37];
          if (pcVar14 == (code *)0x0) {
            uVar11 = 0xe0;
            uVar5 = 0xbaa;
            goto LAB_00482d24;
          }
          (*(code *)PTR_memset_006a99f4)(auStack_2b4,0,0x82);
          uVar3 = (*pcVar14)(param_1,*(undefined4 *)(param_1[0x30] + 0x8c),auStack_2b4,0x81,
                             local_230,0x204);
          if (0x100 < uVar3) {
            uVar11 = 0x44;
            uVar5 = 0xbb5;
LAB_00482ea0:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar11,"s3_clnt.c",uVar5);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2b4,0x82);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_230,0x204);
            ssl3_send_alert(param_1,2,0x28);
            goto LAB_00482d38;
          }
          if (uVar3 == 0) {
            uVar11 = 0xdf;
            uVar5 = 0xbb9;
            goto LAB_00482ea0;
          }
          local_233 = 0;
          uVar9 = (*(code *)PTR_strlen_006a9a24)(auStack_2b4);
          if (0x80 < uVar9) {
            uVar11 = 0x44;
            uVar5 = 0xbc0;
            goto LAB_00482ea0;
          }
          (*(code *)PTR_memmove_006a9af4)(local_230 + uVar3 + 4,local_230,uVar3);
          uVar18 = (undefined)(uVar3 >> 8);
          local_230[0] = uVar18;
          local_230[1] = (char)uVar3;
          (*(code *)PTR___memset_chk_006a998c)(local_230 + 2,0,uVar3,0x202);
          iVar4 = param_1[0x30];
          (local_230 + 2)[uVar3] = uVar18;
          local_230[uVar3 + 3] = (char)uVar3;
          if (*(int *)(iVar4 + 0x8c) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar4 = param_1[0x30];
          }
          uVar5 = (*(code *)PTR_BUF_strdup_006a6fdc)(*(undefined4 *)(param_1[0x39] + 0x14c));
          iVar16 = param_1[0x39];
          iVar13 = param_1[0x30];
          *(undefined4 *)(iVar4 + 0x8c) = uVar5;
          if ((*(int *)(iVar16 + 0x14c) != 0) && (*(int *)(iVar13 + 0x8c) == 0)) {
            uVar11 = 0x41;
            uVar5 = 0xbd3;
            goto LAB_00482ea0;
          }
          if (*(int *)(iVar13 + 0x90) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar13 = param_1[0x30];
          }
          uVar5 = (*(code *)PTR_BUF_strdup_006a6fdc)(auStack_2b4);
          iVar4 = param_1[0x30];
          *(undefined4 *)(iVar13 + 0x90) = uVar5;
          if (*(int *)(iVar4 + 0x90) == 0) {
            uVar11 = 0x41;
            uVar5 = 0xbdc;
            goto LAB_00482ea0;
          }
          iVar13 = uVar9 + 2;
          uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar4 + 0x14,local_230,uVar3 * 2 + 4);
          *(undefined4 *)(iVar4 + 0x10) = uVar5;
          puVar15[5] = (char)uVar9;
          puVar12 = PTR_memcpy_006a9aec;
          puVar15[4] = 0;
          (*(code *)puVar12)(puVar15 + 6,auStack_2b4,uVar9);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2b4,0x82);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_230,0x204);
        }
        else {
          if (param_1[0x6e] == 0) {
            uVar11 = 0x44;
            uVar5 = 0xb83;
            goto LAB_00482d24;
          }
          iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)();
          puVar12 = PTR_BN_bn2bin_006a7200;
          iVar4 = iVar16 + 7;
          if (iVar16 + 7 < 0) {
            iVar4 = iVar16 + 0xe;
          }
          iVar13 = (iVar4 >> 3) + 2;
          puVar15[5] = (char)(iVar4 >> 3);
          puVar15[4] = (char)(iVar4 >> 0xb);
          (*(code *)puVar12)(param_1[0x6e],puVar15 + 6);
          iVar4 = param_1[0x30];
          if (*(int *)(iVar4 + 0xf0) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar4 = param_1[0x30];
          }
          uVar5 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_1[0x69]);
          iVar16 = param_1[0x30];
          *(undefined4 *)(iVar4 + 0xf0) = uVar5;
          if (*(int *)(iVar16 + 0xf0) == 0) {
            uVar11 = 0x41;
            uVar5 = 0xb8b;
            goto LAB_00482d24;
          }
          iVar4 = (*(code *)PTR_SRP_generate_client_master_secret_006a808c)(param_1,iVar16 + 0x14);
          *(int *)(iVar16 + 0x10) = iVar4;
          if (iVar4 < 0) {
            uVar11 = 0x44;
            uVar5 = 0xb94;
            goto LAB_00482d24;
          }
        }
      }
      else {
        if ((*(int *)(*(int *)(param_1[0x30] + 0x98) + 0x60) == 0) &&
           (*(int *)(*(int *)(param_1[0x30] + 0x98) + 0x54) == 0)) {
          uVar11 = 0x14a;
          uVar5 = 0xb24;
          goto LAB_00482d24;
        }
        uVar5 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
        iVar4 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(uVar5,0);
        if (iVar4 == 0) {
          uVar11 = 0x41;
          uVar5 = 0xb2c;
          goto LAB_00482d24;
        }
        iVar16 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(iVar4);
        if (iVar16 < 1) {
LAB_00483224:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar4);
          uVar11 = 0x44;
          uVar5 = 0xb3e;
          goto LAB_00482d24;
        }
        iVar16 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_2d4,0x20);
        if (iVar16 < 1) goto LAB_00483224;
        uVar11 = (*(code *)PTR_EVP_MD_CTX_create_006a8084)();
        uVar8 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x329);
        uVar8 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar8);
        iVar16 = (*(code *)PTR_EVP_DigestInit_006a7e40)(uVar11,uVar8);
        if (((iVar16 < 1) ||
            (iVar16 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar11,param_1[0x16] + 0xc0,0x20),
            iVar16 < 1)) ||
           (iVar16 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar11,param_1[0x16] + 0xa0,0x20),
           iVar16 < 1)) {
LAB_004831a8:
          (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar11);
          uVar11 = 0x44;
          uVar5 = 0xb4f;
          goto LAB_00482d24;
        }
        iVar16 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(uVar11,auStack_2b4,auStack_2d8);
        if (iVar16 < 1) goto LAB_004831a8;
        (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar11);
        iVar16 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar4,0xffffffff,0x100,8,8,auStack_2b4);
        puVar12 = PTR_EVP_PKEY_encrypt_006a7d14;
        if (iVar16 < 0) {
          uVar11 = 0x112;
          uVar5 = 0xb57;
          goto LAB_00482d24;
        }
        puVar15[4] = 0x30;
        local_2dc = 0xff;
        iVar16 = (*(code *)puVar12)(iVar4,local_230,&local_2dc,auStack_2d4,0x20);
        if (iVar16 < 1) {
          uVar11 = 0x112;
          uVar5 = 0xb63;
          goto LAB_00482d24;
        }
        uVar18 = (undefined)local_2dc;
        if (local_2dc < 0x80) {
          puVar12 = puVar15 + 6;
          iVar13 = local_2dc + 2;
        }
        else {
          puVar12 = puVar15 + 7;
          puVar15[6] = uVar18;
          iVar13 = local_2dc + 3;
          uVar18 = 0x81;
        }
        puVar1 = PTR_memcpy_006a9aec;
        puVar15[5] = uVar18;
        (*(code *)puVar1)(puVar12,local_230);
        (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar4);
        iVar4 = param_1[0x30];
        uVar11 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                           (param_1,iVar4 + 0x14,auStack_2d4,0x20);
        puVar12 = PTR_EVP_PKEY_free_006a6e78;
        *(undefined4 *)(iVar4 + 0x10) = uVar11;
        (*(code *)puVar12)(uVar5);
      }
    }
    else {
      if (*(int *)(param_1[0x30] + 0x98) == 0) {
        ssl3_send_alert(param_1,2,10);
        uVar11 = 0xf4;
        uVar5 = 0xa22;
        goto LAB_00482d24;
      }
      iVar4 = *(int *)(*(int *)(param_1[0x30] + 0x98) + 0x70);
      if (iVar4 == 0) {
        ssl3_send_alert(param_1,2,0x28);
        uVar11 = 0xee;
        uVar5 = 0xa2c;
        goto LAB_00482d24;
      }
      iVar16 = (*(code *)PTR_DHparams_dup_006a7f8c)(iVar4);
      if (iVar16 == 0) {
        uVar11 = 5;
        uVar5 = 0xa32;
        goto LAB_00482d24;
      }
      iVar13 = (*(code *)PTR_DH_generate_key_006a7f90)(iVar16);
      if (iVar13 == 0) {
        uVar5 = 0xa36;
LAB_00482f78:
        piVar17 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,5,"s3_clnt.c",uVar5);
        (*(code *)PTR_DH_free_006a7508)(iVar16);
        goto LAB_00482d3c;
      }
      iVar4 = (*(code *)PTR_DH_compute_key_006a7fa4)(puVar12,*(undefined4 *)(iVar4 + 0x14),iVar16);
      if (iVar4 < 1) {
        uVar5 = 0xa43;
        goto LAB_00482f78;
      }
      iVar13 = param_1[0x30];
      uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar13 + 0x14,puVar12,iVar4);
      puVar1 = PTR_memset_006a99f4;
      *(undefined4 *)(iVar13 + 0x10) = uVar5;
      (*(code *)puVar1)(puVar12,0,iVar4);
      iVar13 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar16 + 0x14));
      puVar12 = PTR_BN_bn2bin_006a7200;
      iVar4 = iVar13 + 7;
      if (iVar13 + 7 < 0) {
        iVar4 = iVar13 + 0xe;
      }
      iVar13 = (iVar4 >> 3) + 2;
      puVar15[5] = (char)(iVar4 >> 3);
      puVar15[4] = (char)(iVar4 >> 0xb);
      (*(code *)puVar12)(*(undefined4 *)(iVar16 + 0x14),puVar15 + 6);
      (*(code *)PTR_DH_free_006a7508)(iVar16);
    }
  }
  else {
    iVar4 = *(int *)(param_1[0x30] + 0x98);
    if (iVar4 == 0) {
      uVar11 = 0x44;
      uVar5 = 0x95b;
      goto LAB_00482d24;
    }
    iVar16 = *(int *)(iVar4 + 0x6c);
    if (iVar16 == 0) {
      piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar4 + 0xc));
      if (((piVar17 == (int *)0x0) || (*piVar17 != 6)) || (iVar16 = piVar17[5], iVar16 == 0)) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x44,"s3_clnt.c",0x969);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
        goto LAB_00482d38;
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
    }
    local_230[1] = (undefined)param_1[0x44];
    local_230[0] = (undefined)((uint)param_1[0x44] >> 8);
    iVar4 = (*(code *)PTR_RAND_bytes_006a7574)(local_230 + 2,0x2e);
    puVar1 = PTR_RSA_public_encrypt_006a7654;
    if (iVar4 < 1) goto LAB_00482d38;
    puVar10 = puVar15 + 6;
    if (*param_1 < 0x301) {
      puVar10 = puVar12;
    }
    *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
    iVar4 = (*(code *)puVar1)(0x30,local_230,puVar10,iVar16,1);
    if (iVar4 < 1) {
      uVar11 = 0x77;
      uVar5 = 0x986;
      goto LAB_00482d24;
    }
    iVar13 = iVar4;
    if (0x300 < *param_1) {
      puVar15[5] = (char)iVar4;
      iVar13 = iVar4 + 2;
      puVar15[4] = (char)((uint)iVar4 >> 8);
    }
    iVar4 = param_1[0x30];
    uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar4 + 0x14,local_230,0x30);
    puVar12 = PTR_OPENSSL_cleanse_006a7074;
    *(undefined4 *)(iVar4 + 0x10) = uVar5;
    (*(code *)puVar12)(local_230,0x30);
  }
LAB_00482658:
  puVar15[3] = (char)iVar13;
  puVar15[2] = (char)((uint)iVar13 >> 8);
  puVar15[1] = (char)((uint)iVar13 >> 0x10);
  *puVar15 = 0x10;
  param_1[0x11] = iVar13 + 4;
  param_1[0xd] = 0x1181;
  param_1[0x12] = 0;
LAB_0048268c:
  uVar5 = ssl3_do_write(param_1,0x16);
  while (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004833a8:
    ssl3_send_alert();
    uVar11 = 0x44;
    uVar5 = 0xbf5;
LAB_00482d24:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar11,"s3_clnt.c",uVar5);
LAB_00482d38:
    piVar17 = (int *)0x0;
LAB_00482d3c:
    (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482d4c:
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
    uVar5 = 0xffffffff;
    param_1[0xd] = 5;
  }
  return uVar5;
}

