
/* WARNING: Heritage AFTER dead removal. Example location: r0x006a7f88 : 0x00486640 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint ssl3_get_cert_status(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  undefined uVar11;
  char *pcVar12;
  undefined *puVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined *puVar16;
  int iVar17;
  undefined *puVar18;
  char *unaff_s3;
  char *unaff_s4;
  char *unaff_s5;
  int *piVar19;
  code *pcVar20;
  char cVar21;
  uint uStack_350;
  undefined auStack_34c [4];
  undefined auStack_348 [32];
  char acStack_328 [128];
  char acStack_2a8 [516];
  int iStack_a4;
  undefined *puStack_a0;
  int iStack_9c;
  undefined *puStack_98;
  char *pcStack_94;
  int iStack_58;
  int local_20;
  
  puStack_98 = PTR___stack_chk_guard_006aabf0;
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11f0,0x11f1,0x16);
  if (local_20 != 0) {
    if (uVar4 < 4) {
      uVar7 = 0x9f;
LAB_00486720:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,uVar7,"s3_clnt.c");
      uVar7 = 0x32;
    }
    else {
      pcVar12 = *(char **)(param_1 + 0x40);
      if (*pcVar12 != '\x01') {
        uVar7 = 0x149;
        goto LAB_00486720;
      }
      uVar15 = (uint)(byte)pcVar12[1] << 0x10 | (uint)(byte)pcVar12[2] << 8 | (uint)(byte)pcVar12[3]
      ;
      unaff_s3 = pcVar12 + 4;
      if (uVar4 != uVar15 + 4) {
        uVar7 = 0x9f;
        goto LAB_00486720;
      }
      if (*(int *)(param_1 + 0x138) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      iVar5 = (*(code *)PTR_BUF_memdup_006a91c0)(unaff_s3,uVar15);
      *(int *)(param_1 + 0x138) = iVar5;
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,0x41,"s3_clnt.c");
        uVar7 = 0x50;
      }
      else {
        *(uint *)(param_1 + 0x13c) = uVar15;
        pcVar20 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
        if (pcVar20 == (code *)0x0) {
LAB_004866a0:
          uVar4 = 1;
          goto LAB_004866a4;
        }
        iVar5 = (*pcVar20)(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
        if (iVar5 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,0x148,"s3_clnt.c");
          uVar7 = 0x71;
        }
        else {
          if (-1 < iVar5) goto LAB_004866a0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,0x41,"s3_clnt.c");
          uVar7 = 0x50;
        }
      }
    }
    ssl3_send_alert(param_1,2,uVar7);
    uVar4 = 0xffffffff;
  }
LAB_004866a4:
  if (iStack_9c == *(int *)puStack_98) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_a0 = PTR___stack_chk_guard_006aabf0;
  pcVar12 = &DAT_0000000e;
  piVar6 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar4 = (**(code **)(*(int *)(iStack_9c + 8) + 0x30))();
  if ((iStack_58 != 0) && (bVar1 = 0 < (int)uVar4, uVar4 = 1, bVar1)) {
    ssl3_send_alert(iStack_9c,2,0x32);
    pcVar12 = "s3_clnt.c";
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x91,0x9f,"s3_clnt.c");
    uVar4 = 0xffffffff;
  }
  if (piVar6 == *(int **)puStack_a0) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_94 = unaff_s3;
  if (piVar6[0xd] != 0x1180) goto LAB_00486a38;
  puVar18 = *(undefined **)(piVar6[0xf] + 4);
  uVar4 = *(uint *)(*(int *)(piVar6[0x16] + 0x344) + 0xc);
  puVar16 = puVar18 + 4;
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 0xe) == 0) {
      if ((uVar4 & 0xe0) != 0) {
        unaff_s4 = *(char **)(*(int *)(piVar6[0x30] + 0x98) + 0x74);
        if (unaff_s4 == (char *)0x0) {
          piVar19 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                     (*(undefined4 *)(*(int *)(piVar6[0x30] + 0x98) + 0x48));
          if (((piVar19 == (int *)0x0) || (*piVar19 != 0x198)) ||
             (unaff_s4 = (char *)piVar19[5], unaff_s4 == (char *)0x0)) {
            uVar14 = 0x44;
            uVar7 = 0x9fb;
            goto LAB_004872f8;
          }
        }
        else {
          piVar19 = (int *)0x0;
        }
        unaff_s5 = (char *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(unaff_s4);
        iVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
        if ((unaff_s5 == (char *)0x0) || (iVar5 == 0)) {
          uVar14 = 0x44;
          uVar7 = 0xa08;
LAB_004872f8:
          pcVar12 = "s3_clnt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar14,"s3_clnt.c",uVar7);
          goto LAB_00487124;
        }
        unaff_s4 = (char *)(*(code *)PTR_EC_KEY_new_006a82a8)();
        if (unaff_s4 == (char *)0x0) {
          uVar14 = 0x41;
          uVar7 = 0xa0e;
          goto LAB_004872f8;
        }
        iVar17 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(unaff_s4,unaff_s5);
        if (iVar17 == 0) {
          uVar14 = 0x10;
          uVar7 = 0xa14;
        }
        else {
          iVar17 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(unaff_s4);
          if (iVar17 == 0) {
            uVar14 = 0x2b;
            uVar7 = 0xa30;
          }
          else {
            iVar17 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(unaff_s5);
            if (iVar17 < 1) {
              uVar14 = 0x2b;
              uVar7 = 0xa3d;
            }
            else {
              iVar5 = (*(code *)PTR_ECDH_compute_key_006a8bd4)
                                (puVar16,iVar17 + 7 >> 3,iVar5,unaff_s4,0);
              if (0 < iVar5) {
                iVar17 = piVar6[0x30];
                uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))
                                  (piVar6,iVar17 + 0x14,puVar16,iVar5);
                puVar2 = PTR_memset_006aab00;
                *(undefined4 *)(iVar17 + 0x10) = uVar7;
                (*(code *)puVar2)(puVar16,0,iVar5);
                uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
                uVar7 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(unaff_s5,uVar7,4,0,0,0);
                pcVar8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar7,"s3_clnt.c",0xa62);
                iVar5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
                if (pcVar8 == (char *)0x0) {
                  pcVar12 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
                  goto LAB_004871d0;
                }
                if (iVar5 == 0) {
                  pcVar12 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(0);
                  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar8);
                  goto LAB_004871d0;
                }
                uVar14 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
                pcVar12 = pcVar8;
                iVar9 = (*(code *)PTR_EC_POINT_point2oct_006a9118)
                                  (unaff_s5,uVar14,4,pcVar8,uVar7,iVar5);
                puVar18[4] = (char)iVar9;
                iVar17 = iVar9 + 1;
                (*(code *)PTR_memcpy_006aabf4)(puVar18 + 5,pcVar8,iVar9);
                (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
                (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar8);
                (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
                (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar19);
                goto LAB_00486a04;
              }
              uVar14 = 0x2b;
              uVar7 = 0xa44;
            }
          }
        }
        pcVar12 = "s3_clnt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar14,"s3_clnt.c",uVar7);
        (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_004871d0:
        (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
        goto LAB_00487134;
      }
      if ((uVar4 & 0x200) == 0) {
        if ((uVar4 & 0x400) == 0) {
          if ((uVar4 & 0x100) == 0) {
            ssl3_send_alert();
            uVar14 = 0x44;
            uVar7 = 0xb54;
          }
          else {
            if ((code *)piVar6[0x37] != (code *)0x0) {
              unaff_s4 = acStack_2a8;
              unaff_s5 = acStack_328;
              uVar7 = 0x204;
              pcVar12 = unaff_s4;
              uVar4 = (*(code *)piVar6[0x37])();
              if (0x100 < uVar4) {
                uVar14 = 0x44;
                pcVar12 = "s3_clnt.c";
                uVar7 = 0xb14;
                goto LAB_00487250;
              }
              if (uVar4 == 0) {
                uVar14 = 0xdf;
                pcVar12 = "s3_clnt.c";
                uVar7 = 0xb1a;
                goto LAB_00487250;
              }
              (*(code *)PTR_memmove_006aabfc)(unaff_s4 + uVar4 + 4,unaff_s4,uVar4);
              cVar21 = (char)(uVar4 >> 8);
              acStack_2a8[0] = cVar21;
              acStack_2a8[1] = (char)uVar4;
              (*(code *)PTR___memset_chk_006aaa98)(acStack_2a8 + 2,0,uVar4,0x202,pcVar12,uVar7);
              iVar5 = piVar6[0x30];
              (acStack_2a8 + 2)[uVar4] = cVar21;
              acStack_2a8[uVar4 + 3] = (char)uVar4;
              pcVar12 = (char *)(uVar4 * 2 + 4);
              if (*(int *)(iVar5 + 0x8c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar5 = piVar6[0x30];
              }
              uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(piVar6[0x39] + 0x14c));
              iVar17 = piVar6[0x39];
              iVar9 = piVar6[0x30];
              *(undefined4 *)(iVar5 + 0x8c) = uVar7;
              if ((*(int *)(iVar17 + 0x14c) != 0) && (pcVar8 = "s\n", *(int *)(iVar9 + 0x8c) == 0))
              goto LAB_00487694;
              if (*(int *)(iVar9 + 0x90) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar9 = piVar6[0x30];
              }
              uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(unaff_s5);
              iVar5 = piVar6[0x30];
              *(undefined4 *)(iVar9 + 0x90) = uVar7;
              if (*(int *)(iVar5 + 0x90) == 0) {
                uVar14 = 0x41;
                pcVar12 = "s3_clnt.c";
                uVar7 = 0xb38;
                goto LAB_00487250;
              }
              uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))
                                (piVar6,iVar5 + 0x14,unaff_s4,pcVar12);
              puVar16 = PTR_strlen_006aab30;
              *(undefined4 *)(iVar5 + 0x10) = uVar7;
              iVar5 = (*(code *)puVar16)(unaff_s5);
              puVar18[5] = (char)iVar5;
              puVar18[4] = (char)((uint)iVar5 >> 8);
              iVar17 = iVar5 + 2;
              (*(code *)PTR_memcpy_006aabf4)(puVar18 + 6,unaff_s5,iVar5);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s5,0x80);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
              goto LAB_00486a04;
            }
            uVar14 = 0xe0;
            uVar7 = 0xb0a;
          }
        }
        else {
          pcVar12 = "s\n";
          if (piVar6[0x6e] == 0) {
            uVar14 = 0x44;
            uVar7 = 0xae9;
          }
          else {
            iVar17 = (*(code *)PTR_BN_num_bits_006a82f4)();
            puVar16 = PTR_BN_bn2bin_006a8300;
            iVar5 = iVar17 + 7;
            if (iVar17 + 7 < 0) {
              iVar5 = iVar17 + 0xe;
            }
            iVar17 = (iVar5 >> 3) + 2;
            puVar18[5] = (char)(iVar5 >> 3);
            puVar18[4] = (char)(iVar5 >> 0xb);
            (*(code *)puVar16)(piVar6[0x6e],puVar18 + 6);
            unaff_s5 = (char *)piVar6[0x30];
            if (*(int *)(unaff_s5 + 0xf0) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              unaff_s5 = (char *)piVar6[0x30];
            }
            uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(piVar6[0x69]);
            unaff_s4 = (char *)piVar6[0x30];
            *(undefined4 *)(unaff_s5 + 0xf0) = uVar7;
            if (*(int *)(unaff_s4 + 0xf0) == 0) {
              uVar14 = 0x41;
              uVar7 = 0xaf2;
            }
            else {
              iVar5 = (*(code *)PTR_SRP_generate_client_master_secret_006a91cc)
                                (piVar6,unaff_s4 + 0x14);
              *(int *)(unaff_s4 + 0x10) = iVar5;
              if (-1 < iVar5) goto LAB_00486a04;
              uVar14 = 0x44;
              uVar7 = 0xaf8;
            }
          }
        }
      }
      else if ((*(int *)(*(int *)(piVar6[0x30] + 0x98) + 0x60) == 0) &&
              (*(int *)(*(int *)(piVar6[0x30] + 0x98) + 0x54) == 0)) {
        uVar14 = 0x14a;
        uVar7 = 0xa93;
      }
      else {
        uVar7 = (*(code *)PTR_X509_get_pubkey_006a8008)();
        unaff_s5 = (char *)(*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(uVar7,0);
        (*(code *)PTR_EVP_PKEY_encrypt_init_006a8ddc)(unaff_s5);
        (*(code *)PTR_RAND_bytes_006a8d44)(auStack_348,0x20);
        if (((*(int *)(piVar6[0x16] + 0x358) != 0) && (*(int *)(*(int *)piVar6[0x26] + 4) != 0)) &&
           (iVar5 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(unaff_s5), iVar5 < 1)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        unaff_s4 = acStack_328;
        uVar14 = (*(code *)PTR_EVP_MD_CTX_create_006a91c4)();
        uVar10 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x329);
        uVar10 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar10);
        (*(code *)PTR_EVP_DigestInit_006a8f30)(uVar14,uVar10);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar14,piVar6[0x16] + 0xc0,0x20);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar14,piVar6[0x16] + 0xa0,0x20);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(uVar14,unaff_s4,auStack_34c);
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(uVar14);
        iVar5 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(unaff_s5,0xffffffff,0x100,8,8,unaff_s4);
        puVar16 = PTR_EVP_PKEY_encrypt_006a8e04;
        if (iVar5 < 0) {
          uVar14 = 0x112;
          uVar7 = 0xab7;
        }
        else {
          unaff_s4 = acStack_2a8;
          puVar18[4] = 0x30;
          uStack_350 = 0xff;
          iVar5 = (*(code *)puVar16)(unaff_s5,unaff_s4,&uStack_350,auStack_348,0x20);
          if (-1 < iVar5) {
            iVar17 = uStack_350 + 2;
            uVar11 = (undefined)uStack_350;
            if (uStack_350 < 0x80) {
              puVar16 = puVar18 + 6;
            }
            else {
              puVar16 = puVar18 + 7;
              puVar18[6] = uVar11;
              iVar17 = uStack_350 + 3;
              uVar11 = 0x81;
            }
            puVar2 = PTR_memcpy_006aabf4;
            puVar18[5] = uVar11;
            (*(code *)puVar2)(puVar16,unaff_s4);
            iVar5 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(unaff_s5,0xffffffff,0xffffffff,2,2,0);
            if (0 < iVar5) {
              *(uint *)piVar6[0x16] = *(uint *)piVar6[0x16] | 0x10;
            }
            (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(unaff_s5);
            pcVar12 = &DAT_00000020;
            unaff_s4 = (char *)piVar6[0x30];
            uVar14 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))
                               (piVar6,unaff_s4 + 0x14,auStack_348,0x20);
            puVar16 = PTR_EVP_PKEY_free_006a7f78;
            *(undefined4 *)(unaff_s4 + 0x10) = uVar14;
            (*(code *)puVar16)(uVar7);
            goto LAB_00486a04;
          }
          uVar14 = 0x112;
          uVar7 = 0xac0;
        }
      }
    }
    else if (*(int *)(piVar6[0x30] + 0x98) == 0) {
      ssl3_send_alert();
      uVar14 = 0xf4;
      uVar7 = 0x98f;
    }
    else {
      unaff_s5 = *(char **)(*(int *)(piVar6[0x30] + 0x98) + 0x70);
      if (unaff_s5 == (char *)0x0) {
        ssl3_send_alert();
        uVar14 = 0xee;
        uVar7 = 0x999;
      }
      else {
        unaff_s4 = (char *)(*(code *)PTR_DHparams_dup_006a90f8)(unaff_s5);
        if (unaff_s4 != (char *)0x0) {
          iVar5 = (*(code *)PTR_DH_generate_key_006a90fc)(unaff_s4);
          if (iVar5 == 0) {
            uVar7 = 0x9a5;
LAB_004874a8:
            pcVar12 = "s3_clnt.c";
            piVar19 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,5,"s3_clnt.c",uVar7);
            (*(code *)PTR_DH_free_006a8604)(unaff_s4);
            goto LAB_00487124;
          }
          unaff_s5 = (char *)(*(code *)PTR_DH_compute_key_006a912c)
                                       (puVar16,*(undefined4 *)(unaff_s5 + 0x14),unaff_s4);
          if ((int)unaff_s5 < 1) {
            uVar7 = 0x9b1;
            goto LAB_004874a8;
          }
          iVar5 = piVar6[0x30];
          pcVar12 = unaff_s5;
          uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))
                            (piVar6,iVar5 + 0x14,puVar16,unaff_s5);
          puVar2 = PTR_memset_006aab00;
          *(undefined4 *)(iVar5 + 0x10) = uVar7;
          (*(code *)puVar2)(puVar16,0,unaff_s5);
          iVar17 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(unaff_s4 + 0x14));
          puVar16 = PTR_BN_bn2bin_006a8300;
          iVar5 = iVar17 + 7;
          if (iVar17 + 7 < 0) {
            iVar5 = iVar17 + 0xe;
          }
          iVar17 = (iVar5 >> 3) + 2;
          puVar18[5] = (char)(iVar5 >> 3);
          puVar18[4] = (char)(iVar5 >> 0xb);
          (*(code *)puVar16)(*(undefined4 *)(unaff_s4 + 0x14),puVar18 + 6);
          (*(code *)PTR_DH_free_006a8604)(unaff_s4);
          goto LAB_00486a04;
        }
        uVar14 = 5;
        uVar7 = 0x9a0;
      }
    }
  }
  else {
    unaff_s5 = *(char **)(*(int *)(piVar6[0x30] + 0x98) + 0x6c);
    if (unaff_s5 == (char *)0x0) {
      piVar19 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                 (*(undefined4 *)(*(int *)(piVar6[0x30] + 0x98) + 0xc));
      if (((piVar19 == (int *)0x0) || (pcVar12 = "s\n", *piVar19 != 6)) ||
         (unaff_s5 = (char *)piVar19[5], unaff_s5 == (char *)0x0)) {
        uVar14 = 0x44;
        uVar7 = 0x8d5;
        goto LAB_0048710c;
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar19);
    }
    acStack_2a8[1] = (char)piVar6[0x44];
    acStack_2a8[0] = (char)((uint)piVar6[0x44] >> 8);
    iVar5 = (*(code *)PTR_RAND_bytes_006a8d44)(acStack_2a8 + 2,0x2e);
    puVar2 = PTR_RSA_public_encrypt_006a8744;
    if (iVar5 < 1) goto LAB_00487120;
    unaff_s4 = acStack_2a8;
    puVar13 = puVar18 + 6;
    if (*piVar6 < 0x301) {
      puVar13 = puVar16;
    }
    *(undefined4 *)(piVar6[0x30] + 0x10) = 0x30;
    iVar5 = (*(code *)puVar2)(0x30,unaff_s4,puVar13,unaff_s5,1);
    if (0 < iVar5) {
      iVar17 = iVar5;
      if (0x300 < *piVar6) {
        puVar18[5] = (char)iVar5;
        iVar17 = iVar5 + 2;
        puVar18[4] = (char)((uint)iVar5 >> 8);
      }
      pcVar12 = &DAT_00000030;
      unaff_s5 = (char *)piVar6[0x30];
      uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))(piVar6,unaff_s5 + 0x14,unaff_s4,0x30);
      puVar16 = PTR_OPENSSL_cleanse_006a8174;
      *(undefined4 *)(unaff_s5 + 0x10) = uVar7;
      (*(code *)puVar16)(unaff_s4,0x30);
LAB_00486a04:
      puVar18[3] = (char)iVar17;
      puVar18[2] = (char)((uint)iVar17 >> 8);
      puVar18[1] = (char)((uint)iVar17 >> 0x10);
      *puVar18 = 0x10;
      piVar6[0x11] = iVar17 + 4;
      piVar6[0xd] = 0x1181;
      piVar6[0x12] = 0;
LAB_00486a38:
      uVar4 = ssl3_do_write(piVar6,0x16);
      pcVar8 = pcVar12;
      goto LAB_00486a48;
    }
    uVar14 = 0x77;
    uVar7 = 0x8ef;
  }
LAB_0048710c:
  pcVar12 = "s3_clnt.c";
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar14,"s3_clnt.c",uVar7);
LAB_00487120:
  while( true ) {
    piVar19 = (int *)0x0;
LAB_00487124:
    (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_00487134:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar19);
    uVar4 = 0xffffffff;
    pcVar8 = pcVar12;
LAB_00486a48:
    if (iStack_a4 == *(int *)puVar3) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00487694:
    uVar14 = 0x41;
    pcVar12 = pcVar8 + 0x6958;
    uVar7 = 0xb2e;
LAB_00487250:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar14,pcVar12,uVar7);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s5,0x80);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
    ssl3_send_alert(piVar6,2,0x28);
  }
  return uVar4;
}

