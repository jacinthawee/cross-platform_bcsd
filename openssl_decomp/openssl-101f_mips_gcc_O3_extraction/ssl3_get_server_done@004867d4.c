
int ssl3_get_server_done(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  undefined uVar11;
  undefined *puVar12;
  undefined4 uVar13;
  char *pcVar14;
  undefined *puVar15;
  int iVar16;
  undefined *puVar17;
  char *unaff_s4;
  char *unaff_s5;
  int *piVar18;
  char cVar19;
  uint uStack_310;
  undefined auStack_30c [4];
  undefined auStack_308 [32];
  char acStack_2e8 [128];
  char acStack_268 [516];
  int iStack_64;
  undefined *puStack_60;
  int iStack_5c;
  int local_18;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  pcVar14 = &DAT_0000000e;
  piVar4 = *(int **)PTR___stack_chk_guard_006aabf0;
  iVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x1160,0x1161,0xe);
  if ((local_18 != 0) && (bVar1 = 0 < iVar5, iVar5 = 1, bVar1)) {
    ssl3_send_alert(param_1,2,0x32);
    pcVar14 = "s3_clnt.c";
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x91,0x9f,"s3_clnt.c");
    iVar5 = -1;
  }
  if (piVar4 == *(int **)puStack_60) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_5c = param_1;
  if (piVar4[0xd] != 0x1180) goto LAB_00486a38;
  puVar17 = *(undefined **)(piVar4[0xf] + 4);
  uVar6 = *(uint *)(*(int *)(piVar4[0x16] + 0x344) + 0xc);
  puVar15 = puVar17 + 4;
  if ((uVar6 & 1) == 0) {
    if ((uVar6 & 0xe) == 0) {
      if ((uVar6 & 0xe0) != 0) {
        unaff_s4 = *(char **)(*(int *)(piVar4[0x30] + 0x98) + 0x74);
        if (unaff_s4 == (char *)0x0) {
          piVar18 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                     (*(undefined4 *)(*(int *)(piVar4[0x30] + 0x98) + 0x48));
          if (((piVar18 == (int *)0x0) || (*piVar18 != 0x198)) ||
             (unaff_s4 = (char *)piVar18[5], unaff_s4 == (char *)0x0)) {
            uVar13 = 0x44;
            uVar7 = 0x9fb;
            goto LAB_004872f8;
          }
        }
        else {
          piVar18 = (int *)0x0;
        }
        unaff_s5 = (char *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(unaff_s4);
        iVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
        if ((unaff_s5 == (char *)0x0) || (iVar5 == 0)) {
          uVar13 = 0x44;
          uVar7 = 0xa08;
LAB_004872f8:
          pcVar14 = "s3_clnt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar13,"s3_clnt.c",uVar7);
          goto LAB_00487124;
        }
        unaff_s4 = (char *)(*(code *)PTR_EC_KEY_new_006a82a8)();
        if (unaff_s4 == (char *)0x0) {
          uVar13 = 0x41;
          uVar7 = 0xa0e;
          goto LAB_004872f8;
        }
        iVar16 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(unaff_s4,unaff_s5);
        if (iVar16 == 0) {
          uVar13 = 0x10;
          uVar7 = 0xa14;
        }
        else {
          iVar16 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(unaff_s4);
          if (iVar16 == 0) {
            uVar13 = 0x2b;
            uVar7 = 0xa30;
          }
          else {
            iVar16 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(unaff_s5);
            if (iVar16 < 1) {
              uVar13 = 0x2b;
              uVar7 = 0xa3d;
            }
            else {
              iVar5 = (*(code *)PTR_ECDH_compute_key_006a8bd4)
                                (puVar15,iVar16 + 7 >> 3,iVar5,unaff_s4,0);
              if (0 < iVar5) {
                iVar16 = piVar4[0x30];
                uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))
                                  (piVar4,iVar16 + 0x14,puVar15,iVar5);
                puVar2 = PTR_memset_006aab00;
                *(undefined4 *)(iVar16 + 0x10) = uVar7;
                (*(code *)puVar2)(puVar15,0,iVar5);
                uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
                uVar7 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(unaff_s5,uVar7,4,0,0,0);
                pcVar8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar7,"s3_clnt.c",0xa62);
                iVar5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
                if (pcVar8 == (char *)0x0) {
                  pcVar14 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
                  goto LAB_004871d0;
                }
                if (iVar5 == 0) {
                  pcVar14 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(0);
                  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar8);
                  goto LAB_004871d0;
                }
                uVar13 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
                pcVar14 = pcVar8;
                iVar9 = (*(code *)PTR_EC_POINT_point2oct_006a9118)
                                  (unaff_s5,uVar13,4,pcVar8,uVar7,iVar5);
                puVar17[4] = (char)iVar9;
                iVar16 = iVar9 + 1;
                (*(code *)PTR_memcpy_006aabf4)(puVar17 + 5,pcVar8,iVar9);
                (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
                (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar8);
                (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
                (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar18);
                goto LAB_00486a04;
              }
              uVar13 = 0x2b;
              uVar7 = 0xa44;
            }
          }
        }
        pcVar14 = "s3_clnt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar13,"s3_clnt.c",uVar7);
        (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_004871d0:
        (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
        goto LAB_00487134;
      }
      if ((uVar6 & 0x200) == 0) {
        if ((uVar6 & 0x400) == 0) {
          if ((uVar6 & 0x100) == 0) {
            ssl3_send_alert();
            uVar13 = 0x44;
            uVar7 = 0xb54;
          }
          else {
            if ((code *)piVar4[0x37] != (code *)0x0) {
              unaff_s4 = acStack_268;
              unaff_s5 = acStack_2e8;
              uVar7 = 0x204;
              pcVar14 = unaff_s4;
              uVar6 = (*(code *)piVar4[0x37])();
              if (0x100 < uVar6) {
                uVar13 = 0x44;
                pcVar14 = "s3_clnt.c";
                uVar7 = 0xb14;
                goto LAB_00487250;
              }
              if (uVar6 == 0) {
                uVar13 = 0xdf;
                pcVar14 = "s3_clnt.c";
                uVar7 = 0xb1a;
                goto LAB_00487250;
              }
              (*(code *)PTR_memmove_006aabfc)(unaff_s4 + uVar6 + 4,unaff_s4,uVar6);
              cVar19 = (char)(uVar6 >> 8);
              acStack_268[0] = cVar19;
              acStack_268[1] = (char)uVar6;
              (*(code *)PTR___memset_chk_006aaa98)(acStack_268 + 2,0,uVar6,0x202,pcVar14,uVar7);
              iVar5 = piVar4[0x30];
              (acStack_268 + 2)[uVar6] = cVar19;
              acStack_268[uVar6 + 3] = (char)uVar6;
              pcVar14 = (char *)(uVar6 * 2 + 4);
              if (*(int *)(iVar5 + 0x8c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar5 = piVar4[0x30];
              }
              uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(piVar4[0x39] + 0x14c));
              iVar16 = piVar4[0x39];
              iVar9 = piVar4[0x30];
              *(undefined4 *)(iVar5 + 0x8c) = uVar7;
              if ((*(int *)(iVar16 + 0x14c) != 0) && (pcVar8 = "s\n", *(int *)(iVar9 + 0x8c) == 0))
              goto LAB_00487694;
              if (*(int *)(iVar9 + 0x90) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar9 = piVar4[0x30];
              }
              uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(unaff_s5);
              iVar5 = piVar4[0x30];
              *(undefined4 *)(iVar9 + 0x90) = uVar7;
              if (*(int *)(iVar5 + 0x90) == 0) {
                uVar13 = 0x41;
                pcVar14 = "s3_clnt.c";
                uVar7 = 0xb38;
                goto LAB_00487250;
              }
              uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))
                                (piVar4,iVar5 + 0x14,unaff_s4,pcVar14);
              puVar15 = PTR_strlen_006aab30;
              *(undefined4 *)(iVar5 + 0x10) = uVar7;
              iVar5 = (*(code *)puVar15)(unaff_s5);
              puVar17[5] = (char)iVar5;
              puVar17[4] = (char)((uint)iVar5 >> 8);
              iVar16 = iVar5 + 2;
              (*(code *)PTR_memcpy_006aabf4)(puVar17 + 6,unaff_s5,iVar5);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s5,0x80);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
              goto LAB_00486a04;
            }
            uVar13 = 0xe0;
            uVar7 = 0xb0a;
          }
        }
        else {
          pcVar14 = "s\n";
          if (piVar4[0x6e] == 0) {
            uVar13 = 0x44;
            uVar7 = 0xae9;
          }
          else {
            iVar16 = (*(code *)PTR_BN_num_bits_006a82f4)();
            puVar15 = PTR_BN_bn2bin_006a8300;
            iVar5 = iVar16 + 7;
            if (iVar16 + 7 < 0) {
              iVar5 = iVar16 + 0xe;
            }
            iVar16 = (iVar5 >> 3) + 2;
            puVar17[5] = (char)(iVar5 >> 3);
            puVar17[4] = (char)(iVar5 >> 0xb);
            (*(code *)puVar15)(piVar4[0x6e],puVar17 + 6);
            unaff_s5 = (char *)piVar4[0x30];
            if (*(int *)(unaff_s5 + 0xf0) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              unaff_s5 = (char *)piVar4[0x30];
            }
            uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(piVar4[0x69]);
            unaff_s4 = (char *)piVar4[0x30];
            *(undefined4 *)(unaff_s5 + 0xf0) = uVar7;
            if (*(int *)(unaff_s4 + 0xf0) == 0) {
              uVar13 = 0x41;
              uVar7 = 0xaf2;
            }
            else {
              iVar5 = (*(code *)PTR_SRP_generate_client_master_secret_006a91cc)
                                (piVar4,unaff_s4 + 0x14);
              *(int *)(unaff_s4 + 0x10) = iVar5;
              if (-1 < iVar5) goto LAB_00486a04;
              uVar13 = 0x44;
              uVar7 = 0xaf8;
            }
          }
        }
      }
      else if ((*(int *)(*(int *)(piVar4[0x30] + 0x98) + 0x60) == 0) &&
              (*(int *)(*(int *)(piVar4[0x30] + 0x98) + 0x54) == 0)) {
        uVar13 = 0x14a;
        uVar7 = 0xa93;
      }
      else {
        uVar7 = (*(code *)PTR_X509_get_pubkey_006a8008)();
        unaff_s5 = (char *)(*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(uVar7,0);
        (*(code *)PTR_EVP_PKEY_encrypt_init_006a8ddc)(unaff_s5);
        (*(code *)PTR_RAND_bytes_006a8d44)(auStack_308,0x20);
        if (((*(int *)(piVar4[0x16] + 0x358) != 0) && (*(int *)(*(int *)piVar4[0x26] + 4) != 0)) &&
           (iVar5 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(unaff_s5), iVar5 < 1)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        unaff_s4 = acStack_2e8;
        uVar13 = (*(code *)PTR_EVP_MD_CTX_create_006a91c4)();
        uVar10 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x329);
        uVar10 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar10);
        (*(code *)PTR_EVP_DigestInit_006a8f30)(uVar13,uVar10);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar13,piVar4[0x16] + 0xc0,0x20);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar13,piVar4[0x16] + 0xa0,0x20);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(uVar13,unaff_s4,auStack_30c);
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(uVar13);
        iVar5 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(unaff_s5,0xffffffff,0x100,8,8,unaff_s4);
        puVar15 = PTR_EVP_PKEY_encrypt_006a8e04;
        if (iVar5 < 0) {
          uVar13 = 0x112;
          uVar7 = 0xab7;
        }
        else {
          unaff_s4 = acStack_268;
          puVar17[4] = 0x30;
          uStack_310 = 0xff;
          iVar5 = (*(code *)puVar15)(unaff_s5,unaff_s4,&uStack_310,auStack_308,0x20);
          if (-1 < iVar5) {
            iVar16 = uStack_310 + 2;
            uVar11 = (undefined)uStack_310;
            if (uStack_310 < 0x80) {
              puVar15 = puVar17 + 6;
            }
            else {
              puVar15 = puVar17 + 7;
              puVar17[6] = uVar11;
              iVar16 = uStack_310 + 3;
              uVar11 = 0x81;
            }
            puVar2 = PTR_memcpy_006aabf4;
            puVar17[5] = uVar11;
            (*(code *)puVar2)(puVar15,unaff_s4);
            iVar5 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(unaff_s5,0xffffffff,0xffffffff,2,2,0);
            if (0 < iVar5) {
              *(uint *)piVar4[0x16] = *(uint *)piVar4[0x16] | 0x10;
            }
            (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(unaff_s5);
            pcVar14 = &DAT_00000020;
            unaff_s4 = (char *)piVar4[0x30];
            uVar13 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))
                               (piVar4,unaff_s4 + 0x14,auStack_308,0x20);
            puVar15 = PTR_EVP_PKEY_free_006a7f78;
            *(undefined4 *)(unaff_s4 + 0x10) = uVar13;
            (*(code *)puVar15)(uVar7);
            goto LAB_00486a04;
          }
          uVar13 = 0x112;
          uVar7 = 0xac0;
        }
      }
    }
    else if (*(int *)(piVar4[0x30] + 0x98) == 0) {
      ssl3_send_alert();
      uVar13 = 0xf4;
      uVar7 = 0x98f;
    }
    else {
      unaff_s5 = *(char **)(*(int *)(piVar4[0x30] + 0x98) + 0x70);
      if (unaff_s5 == (char *)0x0) {
        ssl3_send_alert();
        uVar13 = 0xee;
        uVar7 = 0x999;
      }
      else {
        unaff_s4 = (char *)(*(code *)PTR_DHparams_dup_006a90f8)(unaff_s5);
        if (unaff_s4 != (char *)0x0) {
          iVar5 = (*(code *)PTR_DH_generate_key_006a90fc)(unaff_s4);
          if (iVar5 == 0) {
            uVar7 = 0x9a5;
LAB_004874a8:
            pcVar14 = "s3_clnt.c";
            piVar18 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,5,"s3_clnt.c",uVar7);
            (*(code *)PTR_DH_free_006a8604)(unaff_s4);
            goto LAB_00487124;
          }
          unaff_s5 = (char *)(*(code *)PTR_DH_compute_key_006a912c)
                                       (puVar15,*(undefined4 *)(unaff_s5 + 0x14),unaff_s4);
          if ((int)unaff_s5 < 1) {
            uVar7 = 0x9b1;
            goto LAB_004874a8;
          }
          iVar5 = piVar4[0x30];
          pcVar14 = unaff_s5;
          uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))
                            (piVar4,iVar5 + 0x14,puVar15,unaff_s5);
          puVar2 = PTR_memset_006aab00;
          *(undefined4 *)(iVar5 + 0x10) = uVar7;
          (*(code *)puVar2)(puVar15,0,unaff_s5);
          iVar16 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(unaff_s4 + 0x14));
          puVar15 = PTR_BN_bn2bin_006a8300;
          iVar5 = iVar16 + 7;
          if (iVar16 + 7 < 0) {
            iVar5 = iVar16 + 0xe;
          }
          iVar16 = (iVar5 >> 3) + 2;
          puVar17[5] = (char)(iVar5 >> 3);
          puVar17[4] = (char)(iVar5 >> 0xb);
          (*(code *)puVar15)(*(undefined4 *)(unaff_s4 + 0x14),puVar17 + 6);
          (*(code *)PTR_DH_free_006a8604)(unaff_s4);
          goto LAB_00486a04;
        }
        uVar13 = 5;
        uVar7 = 0x9a0;
      }
    }
  }
  else {
    unaff_s5 = *(char **)(*(int *)(piVar4[0x30] + 0x98) + 0x6c);
    if (unaff_s5 == (char *)0x0) {
      piVar18 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                 (*(undefined4 *)(*(int *)(piVar4[0x30] + 0x98) + 0xc));
      if (((piVar18 == (int *)0x0) || (pcVar14 = "s\n", *piVar18 != 6)) ||
         (unaff_s5 = (char *)piVar18[5], unaff_s5 == (char *)0x0)) {
        uVar13 = 0x44;
        uVar7 = 0x8d5;
        goto LAB_0048710c;
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar18);
    }
    acStack_268[1] = (char)piVar4[0x44];
    acStack_268[0] = (char)((uint)piVar4[0x44] >> 8);
    iVar5 = (*(code *)PTR_RAND_bytes_006a8d44)(acStack_268 + 2,0x2e);
    puVar2 = PTR_RSA_public_encrypt_006a8744;
    if (iVar5 < 1) goto LAB_00487120;
    unaff_s4 = acStack_268;
    puVar12 = puVar17 + 6;
    if (*piVar4 < 0x301) {
      puVar12 = puVar15;
    }
    *(undefined4 *)(piVar4[0x30] + 0x10) = 0x30;
    iVar5 = (*(code *)puVar2)(0x30,unaff_s4,puVar12,unaff_s5,1);
    if (0 < iVar5) {
      iVar16 = iVar5;
      if (0x300 < *piVar4) {
        puVar17[5] = (char)iVar5;
        iVar16 = iVar5 + 2;
        puVar17[4] = (char)((uint)iVar5 >> 8);
      }
      pcVar14 = &DAT_00000030;
      unaff_s5 = (char *)piVar4[0x30];
      uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))(piVar4,unaff_s5 + 0x14,unaff_s4,0x30);
      puVar15 = PTR_OPENSSL_cleanse_006a8174;
      *(undefined4 *)(unaff_s5 + 0x10) = uVar7;
      (*(code *)puVar15)(unaff_s4,0x30);
LAB_00486a04:
      puVar17[3] = (char)iVar16;
      puVar17[2] = (char)((uint)iVar16 >> 8);
      puVar17[1] = (char)((uint)iVar16 >> 0x10);
      *puVar17 = 0x10;
      piVar4[0x11] = iVar16 + 4;
      piVar4[0xd] = 0x1181;
      piVar4[0x12] = 0;
LAB_00486a38:
      iVar5 = ssl3_do_write(piVar4,0x16);
      pcVar8 = pcVar14;
      goto LAB_00486a48;
    }
    uVar13 = 0x77;
    uVar7 = 0x8ef;
  }
LAB_0048710c:
  pcVar14 = "s3_clnt.c";
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar13,"s3_clnt.c",uVar7);
LAB_00487120:
  while( true ) {
    piVar18 = (int *)0x0;
LAB_00487124:
    (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_00487134:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar18);
    iVar5 = -1;
    pcVar8 = pcVar14;
LAB_00486a48:
    if (iStack_64 == *(int *)puVar3) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00487694:
    uVar13 = 0x41;
    pcVar14 = pcVar8 + 0x6958;
    uVar7 = 0xb2e;
LAB_00487250:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar13,pcVar14,uVar7);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s5,0x80);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
    ssl3_send_alert(piVar4,2,0x28);
  }
  return iVar5;
}

