
undefined4
ssl3_send_client_key_exchange(int *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  undefined uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined *puVar12;
  int iVar13;
  undefined *puVar14;
  char *unaff_s4;
  char *unaff_s5;
  int *piVar15;
  char cVar16;
  uint local_2d8;
  undefined auStack_2d4 [4];
  undefined auStack_2d0 [32];
  char acStack_2b0 [128];
  char local_230 [516];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1[0xd] != 0x1180) goto LAB_00486a38;
  puVar14 = *(undefined **)(param_1[0xf] + 4);
  uVar3 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  puVar12 = puVar14 + 4;
  if ((uVar3 & 1) == 0) {
    if ((uVar3 & 0xe) == 0) {
      if ((uVar3 & 0xe0) != 0) {
        unaff_s4 = *(char **)(*(int *)(param_1[0x30] + 0x98) + 0x74);
        if (unaff_s4 == (char *)0x0) {
          piVar15 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                     (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x48));
          if (((piVar15 == (int *)0x0) || (*piVar15 != 0x198)) ||
             (unaff_s4 = (char *)piVar15[5], unaff_s4 == (char *)0x0)) {
            uVar11 = 0x44;
            uVar5 = 0x9fb;
            goto LAB_004872f8;
          }
        }
        else {
          piVar15 = (int *)0x0;
        }
        unaff_s5 = (char *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(unaff_s4);
        iVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
        if ((unaff_s5 == (char *)0x0) || (iVar4 == 0)) {
          uVar11 = 0x44;
          uVar5 = 0xa08;
LAB_004872f8:
          param_4 = "s3_clnt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar11,"s3_clnt.c",uVar5);
          goto LAB_00487124;
        }
        unaff_s4 = (char *)(*(code *)PTR_EC_KEY_new_006a82a8)();
        if (unaff_s4 == (char *)0x0) {
          uVar11 = 0x41;
          uVar5 = 0xa0e;
          goto LAB_004872f8;
        }
        iVar13 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(unaff_s4,unaff_s5);
        if (iVar13 == 0) {
          uVar11 = 0x10;
          uVar5 = 0xa14;
        }
        else {
          iVar13 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(unaff_s4);
          if (iVar13 == 0) {
            uVar11 = 0x2b;
            uVar5 = 0xa30;
          }
          else {
            iVar13 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(unaff_s5);
            if (iVar13 < 1) {
              uVar11 = 0x2b;
              uVar5 = 0xa3d;
            }
            else {
              iVar4 = (*(code *)PTR_ECDH_compute_key_006a8bd4)
                                (puVar12,iVar13 + 7 >> 3,iVar4,unaff_s4,0);
              if (0 < iVar4) {
                iVar13 = param_1[0x30];
                uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar13 + 0x14,puVar12,iVar4);
                puVar1 = PTR_memset_006aab00;
                *(undefined4 *)(iVar13 + 0x10) = uVar5;
                (*(code *)puVar1)(puVar12,0,iVar4);
                uVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
                uVar5 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(unaff_s5,uVar5,4,0,0,0);
                pcVar6 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar5,"s3_clnt.c",0xa62);
                iVar4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
                if (pcVar6 == (char *)0x0) {
                  param_4 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
                  goto LAB_004871d0;
                }
                if (iVar4 == 0) {
                  param_4 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(0);
                  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar6);
                  goto LAB_004871d0;
                }
                uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
                param_4 = pcVar6;
                iVar7 = (*(code *)PTR_EC_POINT_point2oct_006a9118)
                                  (unaff_s5,uVar11,4,pcVar6,uVar5,iVar4);
                puVar14[4] = (char)iVar7;
                iVar13 = iVar7 + 1;
                (*(code *)PTR_memcpy_006aabf4)(puVar14 + 5,pcVar6,iVar7);
                (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
                (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar6);
                (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
                (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar15);
                goto LAB_00486a04;
              }
              uVar11 = 0x2b;
              uVar5 = 0xa44;
            }
          }
        }
        param_4 = "s3_clnt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar11,"s3_clnt.c",uVar5);
        (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_004871d0:
        (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
        goto LAB_00487134;
      }
      if ((uVar3 & 0x200) == 0) {
        if ((uVar3 & 0x400) == 0) {
          if ((uVar3 & 0x100) == 0) {
            ssl3_send_alert(param_1,2,0x28);
            uVar11 = 0x44;
            uVar5 = 0xb54;
          }
          else {
            if ((code *)param_1[0x37] != (code *)0x0) {
              unaff_s4 = local_230;
              unaff_s5 = acStack_2b0;
              uVar3 = (*(code *)param_1[0x37])
                                (param_1,*(undefined4 *)(param_1[0x39] + 0x14c),unaff_s5,0x80,
                                 unaff_s4,0x204);
              if (0x100 < uVar3) {
                uVar11 = 0x44;
                param_4 = "s3_clnt.c";
                uVar5 = 0xb14;
                goto LAB_00487250;
              }
              if (uVar3 == 0) {
                uVar11 = 0xdf;
                param_4 = "s3_clnt.c";
                uVar5 = 0xb1a;
                goto LAB_00487250;
              }
              (*(code *)PTR_memmove_006aabfc)(unaff_s4 + uVar3 + 4,unaff_s4,uVar3);
              cVar16 = (char)(uVar3 >> 8);
              local_230[0] = cVar16;
              local_230[1] = (char)uVar3;
              (*(code *)PTR___memset_chk_006aaa98)(local_230 + 2,0,uVar3,0x202);
              iVar4 = param_1[0x30];
              (local_230 + 2)[uVar3] = cVar16;
              local_230[uVar3 + 3] = (char)uVar3;
              param_4 = (char *)(uVar3 * 2 + 4);
              if (*(int *)(iVar4 + 0x8c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar4 = param_1[0x30];
              }
              uVar5 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(param_1[0x39] + 0x14c));
              iVar13 = param_1[0x39];
              iVar7 = param_1[0x30];
              *(undefined4 *)(iVar4 + 0x8c) = uVar5;
              if ((*(int *)(iVar13 + 0x14c) != 0) && (pcVar6 = "s\n", *(int *)(iVar7 + 0x8c) == 0))
              goto LAB_00487694;
              if (*(int *)(iVar7 + 0x90) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar7 = param_1[0x30];
              }
              uVar5 = (*(code *)PTR_BUF_strdup_006a80dc)(unaff_s5);
              iVar4 = param_1[0x30];
              *(undefined4 *)(iVar7 + 0x90) = uVar5;
              if (*(int *)(iVar4 + 0x90) == 0) {
                uVar11 = 0x41;
                param_4 = "s3_clnt.c";
                uVar5 = 0xb38;
                goto LAB_00487250;
              }
              uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,iVar4 + 0x14,unaff_s4,param_4);
              puVar12 = PTR_strlen_006aab30;
              *(undefined4 *)(iVar4 + 0x10) = uVar5;
              iVar4 = (*(code *)puVar12)(unaff_s5);
              puVar14[5] = (char)iVar4;
              puVar14[4] = (char)((uint)iVar4 >> 8);
              iVar13 = iVar4 + 2;
              (*(code *)PTR_memcpy_006aabf4)(puVar14 + 6,unaff_s5,iVar4);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s5,0x80);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
              goto LAB_00486a04;
            }
            uVar11 = 0xe0;
            uVar5 = 0xb0a;
          }
        }
        else {
          param_4 = "s\n";
          if (param_1[0x6e] == 0) {
            uVar11 = 0x44;
            uVar5 = 0xae9;
          }
          else {
            iVar13 = (*(code *)PTR_BN_num_bits_006a82f4)();
            puVar12 = PTR_BN_bn2bin_006a8300;
            iVar4 = iVar13 + 7;
            if (iVar13 + 7 < 0) {
              iVar4 = iVar13 + 0xe;
            }
            iVar13 = (iVar4 >> 3) + 2;
            puVar14[5] = (char)(iVar4 >> 3);
            puVar14[4] = (char)(iVar4 >> 0xb);
            (*(code *)puVar12)(param_1[0x6e],puVar14 + 6);
            unaff_s5 = (char *)param_1[0x30];
            if (*(int *)(unaff_s5 + 0xf0) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              unaff_s5 = (char *)param_1[0x30];
            }
            uVar5 = (*(code *)PTR_BUF_strdup_006a80dc)(param_1[0x69]);
            unaff_s4 = (char *)param_1[0x30];
            *(undefined4 *)(unaff_s5 + 0xf0) = uVar5;
            if (*(int *)(unaff_s4 + 0xf0) == 0) {
              uVar11 = 0x41;
              uVar5 = 0xaf2;
            }
            else {
              iVar4 = (*(code *)PTR_SRP_generate_client_master_secret_006a91cc)
                                (param_1,unaff_s4 + 0x14);
              *(int *)(unaff_s4 + 0x10) = iVar4;
              if (-1 < iVar4) goto LAB_00486a04;
              uVar11 = 0x44;
              uVar5 = 0xaf8;
            }
          }
        }
      }
      else if ((*(int *)(*(int *)(param_1[0x30] + 0x98) + 0x60) == 0) &&
              (*(int *)(*(int *)(param_1[0x30] + 0x98) + 0x54) == 0)) {
        uVar11 = 0x14a;
        uVar5 = 0xa93;
      }
      else {
        uVar5 = (*(code *)PTR_X509_get_pubkey_006a8008)();
        unaff_s5 = (char *)(*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(uVar5,0);
        (*(code *)PTR_EVP_PKEY_encrypt_init_006a8ddc)(unaff_s5);
        (*(code *)PTR_RAND_bytes_006a8d44)(auStack_2d0,0x20);
        if (((*(int *)(param_1[0x16] + 0x358) != 0) && (*(int *)(*(int *)param_1[0x26] + 4) != 0))
           && (iVar4 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(unaff_s5), iVar4 < 1)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        unaff_s4 = acStack_2b0;
        uVar11 = (*(code *)PTR_EVP_MD_CTX_create_006a91c4)();
        uVar8 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x329);
        uVar8 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar8);
        (*(code *)PTR_EVP_DigestInit_006a8f30)(uVar11,uVar8);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar11,param_1[0x16] + 0xc0,0x20);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar11,param_1[0x16] + 0xa0,0x20);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(uVar11,unaff_s4,auStack_2d4);
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(uVar11);
        iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(unaff_s5,0xffffffff,0x100,8,8,unaff_s4);
        puVar12 = PTR_EVP_PKEY_encrypt_006a8e04;
        if (iVar4 < 0) {
          uVar11 = 0x112;
          uVar5 = 0xab7;
        }
        else {
          unaff_s4 = local_230;
          puVar14[4] = 0x30;
          local_2d8 = 0xff;
          iVar4 = (*(code *)puVar12)(unaff_s5,unaff_s4,&local_2d8,auStack_2d0,0x20);
          if (-1 < iVar4) {
            iVar13 = local_2d8 + 2;
            uVar9 = (undefined)local_2d8;
            if (local_2d8 < 0x80) {
              puVar12 = puVar14 + 6;
            }
            else {
              puVar12 = puVar14 + 7;
              puVar14[6] = uVar9;
              iVar13 = local_2d8 + 3;
              uVar9 = 0x81;
            }
            puVar1 = PTR_memcpy_006aabf4;
            puVar14[5] = uVar9;
            (*(code *)puVar1)(puVar12,unaff_s4);
            iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(unaff_s5,0xffffffff,0xffffffff,2,2,0);
            if (0 < iVar4) {
              *(uint *)param_1[0x16] = *(uint *)param_1[0x16] | 0x10;
            }
            (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(unaff_s5);
            param_4 = &DAT_00000020;
            unaff_s4 = (char *)param_1[0x30];
            uVar11 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                               (param_1,unaff_s4 + 0x14,auStack_2d0,0x20);
            puVar12 = PTR_EVP_PKEY_free_006a7f78;
            *(undefined4 *)(unaff_s4 + 0x10) = uVar11;
            (*(code *)puVar12)(uVar5);
            goto LAB_00486a04;
          }
          uVar11 = 0x112;
          uVar5 = 0xac0;
        }
      }
    }
    else if (*(int *)(param_1[0x30] + 0x98) == 0) {
      ssl3_send_alert(param_1,2,10);
      uVar11 = 0xf4;
      uVar5 = 0x98f;
    }
    else {
      unaff_s5 = *(char **)(*(int *)(param_1[0x30] + 0x98) + 0x70);
      if (unaff_s5 == (char *)0x0) {
        ssl3_send_alert(param_1,2,0x28);
        uVar11 = 0xee;
        uVar5 = 0x999;
      }
      else {
        unaff_s4 = (char *)(*(code *)PTR_DHparams_dup_006a90f8)(unaff_s5);
        if (unaff_s4 != (char *)0x0) {
          iVar4 = (*(code *)PTR_DH_generate_key_006a90fc)(unaff_s4);
          if (iVar4 == 0) {
            uVar5 = 0x9a5;
LAB_004874a8:
            param_4 = "s3_clnt.c";
            piVar15 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,5,"s3_clnt.c",uVar5);
            (*(code *)PTR_DH_free_006a8604)(unaff_s4);
            goto LAB_00487124;
          }
          unaff_s5 = (char *)(*(code *)PTR_DH_compute_key_006a912c)
                                       (puVar12,*(undefined4 *)(unaff_s5 + 0x14),unaff_s4);
          if ((int)unaff_s5 < 1) {
            uVar5 = 0x9b1;
            goto LAB_004874a8;
          }
          iVar4 = param_1[0x30];
          param_4 = unaff_s5;
          uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar4 + 0x14,puVar12,unaff_s5);
          puVar1 = PTR_memset_006aab00;
          *(undefined4 *)(iVar4 + 0x10) = uVar5;
          (*(code *)puVar1)(puVar12,0,unaff_s5);
          iVar13 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(unaff_s4 + 0x14));
          puVar12 = PTR_BN_bn2bin_006a8300;
          iVar4 = iVar13 + 7;
          if (iVar13 + 7 < 0) {
            iVar4 = iVar13 + 0xe;
          }
          iVar13 = (iVar4 >> 3) + 2;
          puVar14[5] = (char)(iVar4 >> 3);
          puVar14[4] = (char)(iVar4 >> 0xb);
          (*(code *)puVar12)(*(undefined4 *)(unaff_s4 + 0x14),puVar14 + 6);
          (*(code *)PTR_DH_free_006a8604)(unaff_s4);
          goto LAB_00486a04;
        }
        uVar11 = 5;
        uVar5 = 0x9a0;
      }
    }
  }
  else {
    unaff_s5 = *(char **)(*(int *)(param_1[0x30] + 0x98) + 0x6c);
    if (unaff_s5 == (char *)0x0) {
      piVar15 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                 (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
      if (((piVar15 == (int *)0x0) || (param_4 = "s\n", *piVar15 != 6)) ||
         (unaff_s5 = (char *)piVar15[5], unaff_s5 == (char *)0x0)) {
        uVar11 = 0x44;
        uVar5 = 0x8d5;
        goto LAB_0048710c;
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar15);
    }
    local_230[1] = (char)param_1[0x44];
    local_230[0] = (char)((uint)param_1[0x44] >> 8);
    iVar4 = (*(code *)PTR_RAND_bytes_006a8d44)(local_230 + 2,0x2e);
    puVar1 = PTR_RSA_public_encrypt_006a8744;
    if (iVar4 < 1) goto LAB_00487120;
    unaff_s4 = local_230;
    puVar10 = puVar14 + 6;
    if (*param_1 < 0x301) {
      puVar10 = puVar12;
    }
    *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
    iVar4 = (*(code *)puVar1)(0x30,unaff_s4,puVar10,unaff_s5,1);
    if (0 < iVar4) {
      iVar13 = iVar4;
      if (0x300 < *param_1) {
        puVar14[5] = (char)iVar4;
        iVar13 = iVar4 + 2;
        puVar14[4] = (char)((uint)iVar4 >> 8);
      }
      param_4 = &DAT_00000030;
      unaff_s5 = (char *)param_1[0x30];
      uVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,unaff_s5 + 0x14,unaff_s4,0x30)
      ;
      puVar12 = PTR_OPENSSL_cleanse_006a8174;
      *(undefined4 *)(unaff_s5 + 0x10) = uVar5;
      (*(code *)puVar12)(unaff_s4,0x30);
LAB_00486a04:
      puVar14[3] = (char)iVar13;
      puVar14[2] = (char)((uint)iVar13 >> 8);
      puVar14[1] = (char)((uint)iVar13 >> 0x10);
      *puVar14 = 0x10;
      param_1[0x11] = iVar13 + 4;
      param_1[0xd] = 0x1181;
      param_1[0x12] = 0;
LAB_00486a38:
      uVar5 = ssl3_do_write(param_1,0x16);
      pcVar6 = param_4;
      goto LAB_00486a48;
    }
    uVar11 = 0x77;
    uVar5 = 0x8ef;
  }
LAB_0048710c:
  param_4 = "s3_clnt.c";
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar11,"s3_clnt.c",uVar5);
LAB_00487120:
  while( true ) {
    piVar15 = (int *)0x0;
LAB_00487124:
    (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_00487134:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar15);
    uVar5 = 0xffffffff;
    pcVar6 = param_4;
LAB_00486a48:
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00487694:
    uVar11 = 0x41;
    param_4 = pcVar6 + 0x6958;
    uVar5 = 0xb2e;
LAB_00487250:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar11,param_4,uVar5);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s5,0x80);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
    ssl3_send_alert(param_1,2,0x28);
  }
  return uVar5;
}

