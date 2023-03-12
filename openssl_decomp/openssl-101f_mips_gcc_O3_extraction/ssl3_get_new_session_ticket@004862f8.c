
/* WARNING: Heritage AFTER dead removal. Example location: r0x006a7f88 : 0x00486640 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint ssl3_get_new_session_ticket(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  byte *pbVar8;
  undefined4 uVar9;
  undefined uVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  undefined *puVar16;
  undefined4 uVar17;
  undefined *puVar18;
  undefined *puVar19;
  byte *unaff_s4;
  byte *unaff_s5;
  byte *pbVar20;
  int *piVar21;
  code *pcVar22;
  byte bVar23;
  uint uStack_398;
  undefined auStack_394 [4];
  undefined auStack_390 [32];
  byte abStack_370 [128];
  byte abStack_2f0 [516];
  int iStack_ec;
  undefined *puStack_e8;
  int iStack_e4;
  undefined *puStack_e0;
  char *pcStack_dc;
  byte *pbStack_d8;
  byte *pbStack_d4;
  int iStack_a0;
  int iStack_68;
  int local_28;
  
  pcStack_dc = PTR___stack_chk_guard_006aabf0;
  iVar4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11e0,0x11e1,0xffffffff);
  if (local_28 != 0) {
    iVar11 = *(int *)(*(int *)(param_1 + 0x58) + 0x340);
    if (iVar11 == 0x14) {
      uVar5 = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x354) = 1;
    }
    else {
      if (iVar11 == 4) {
        if (5 < (int)uVar5) {
          pbVar12 = *(byte **)(param_1 + 0x40);
          iVar11 = *(int *)(param_1 + 0xc0);
          unaff_s4 = pbVar12 + 6;
          bVar23 = *pbVar12;
          *(uint *)(iVar11 + 0xec) = (uint)bVar23 << 0x18;
          uVar14 = (uint)pbVar12[1] << 0x10 | (uint)bVar23 << 0x18;
          *(uint *)(iVar11 + 0xec) = uVar14;
          uVar14 = (uint)pbVar12[2] << 8 | uVar14;
          *(uint *)(iVar11 + 0xec) = uVar14;
          *(uint *)(iVar11 + 0xec) = pbVar12[3] | uVar14;
          uVar14 = (uint)*(ushort *)(pbVar12 + 4);
          if (uVar5 == uVar14 + 6) {
            if (*(int *)(iVar11 + 0xe4) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              iVar11 = *(int *)(param_1 + 0xc0);
              *(undefined4 *)(iVar11 + 0xe8) = 0;
            }
            unaff_s5 = (byte *)0x640000;
            uVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar14,"s3_clnt.c",0x824);
            iVar13 = *(int *)(param_1 + 0xc0);
            *(undefined4 *)(iVar11 + 0xe4) = uVar6;
            iVar11 = *(int *)(iVar13 + 0xe4);
            if (iVar11 == 0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x11b,0x41,"s3_clnt.c");
              uVar5 = 0xffffffff;
            }
            else {
              (*(code *)PTR_memcpy_006aabf4)(iVar11,unaff_s4,uVar14);
              puVar3 = PTR_EVP_sha256_006a916c;
              iVar11 = *(int *)(param_1 + 0xc0);
              *(uint *)(iVar11 + 0xe8) = uVar14;
              (*(code *)puVar3)();
              (*(code *)PTR_EVP_Digest_006a8b04)(unaff_s4,uVar14,iVar11 + 0x48,iVar11 + 0x44);
              uVar5 = 1;
            }
            goto LAB_00486490;
          }
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x11b,0x9f,"s3_clnt.c");
        uVar6 = 0x32;
      }
      else {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x11b,0x72,"s3_clnt.c");
        uVar6 = 10;
      }
      ssl3_send_alert(param_1,2,uVar6);
      uVar5 = 0xffffffff;
    }
  }
LAB_00486490:
  if (iVar4 == *(int *)pcStack_dc) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x30))();
  if (iStack_68 != 0) {
    if (uVar5 < 4) {
      uVar6 = 0x9f;
LAB_00486720:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,uVar6,"s3_clnt.c");
      uVar6 = 0x32;
    }
    else {
      pcVar15 = *(char **)(iVar4 + 0x40);
      if (*pcVar15 != '\x01') {
        uVar6 = 0x149;
        goto LAB_00486720;
      }
      uVar14 = (uint)(byte)pcVar15[1] << 0x10 | (uint)(byte)pcVar15[2] << 8 | (uint)(byte)pcVar15[3]
      ;
      pcStack_dc = pcVar15 + 4;
      if (uVar5 != uVar14 + 4) {
        uVar6 = 0x9f;
        goto LAB_00486720;
      }
      if (*(int *)(iVar4 + 0x138) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      iVar11 = (*(code *)PTR_BUF_memdup_006a91c0)(pcStack_dc,uVar14);
      *(int *)(iVar4 + 0x138) = iVar11;
      if (iVar11 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,0x41,"s3_clnt.c");
        uVar6 = 0x50;
      }
      else {
        *(uint *)(iVar4 + 0x13c) = uVar14;
        pcVar22 = *(code **)(*(int *)(iVar4 + 0xe4) + 0x13c);
        if (pcVar22 == (code *)0x0) {
LAB_004866a0:
          uVar5 = 1;
          goto LAB_004866a4;
        }
        iVar11 = (*pcVar22)(iVar4,*(undefined4 *)(*(int *)(iVar4 + 0xe4) + 0x140));
        if (iVar11 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,0x148,"s3_clnt.c");
          uVar6 = 0x71;
        }
        else {
          if (-1 < iVar11) goto LAB_004866a0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x121,0x41,"s3_clnt.c");
          uVar6 = 0x50;
        }
      }
    }
    ssl3_send_alert(iVar4,2,uVar6);
    uVar5 = 0xffffffff;
  }
LAB_004866a4:
  if (iStack_e4 == *(int *)puStack_e0) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_e8 = PTR___stack_chk_guard_006aabf0;
  pcVar15 = &DAT_0000000e;
  piVar7 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar5 = (**(code **)(*(int *)(iStack_e4 + 8) + 0x30))();
  if ((iStack_a0 != 0) && (bVar1 = 0 < (int)uVar5, uVar5 = 1, bVar1)) {
    ssl3_send_alert(iStack_e4,2,0x32);
    pcVar15 = "s3_clnt.c";
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x91,0x9f,"s3_clnt.c");
    uVar5 = 0xffffffff;
  }
  if (piVar7 == *(int **)puStack_e8) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_ec = *(int *)PTR___stack_chk_guard_006aabf0;
  pbVar12 = unaff_s4;
  pbVar20 = unaff_s5;
  pbStack_d8 = unaff_s4;
  pbStack_d4 = unaff_s5;
  if (piVar7[0xd] != 0x1180) goto LAB_00486a38;
  puVar19 = *(undefined **)(piVar7[0xf] + 4);
  uVar5 = *(uint *)(*(int *)(piVar7[0x16] + 0x344) + 0xc);
  puVar18 = puVar19 + 4;
  if ((uVar5 & 1) == 0) {
    if ((uVar5 & 0xe) == 0) {
      if ((uVar5 & 0xe0) != 0) {
        pbVar12 = *(byte **)(*(int *)(piVar7[0x30] + 0x98) + 0x74);
        if (pbVar12 == (byte *)0x0) {
          piVar21 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                     (*(undefined4 *)(*(int *)(piVar7[0x30] + 0x98) + 0x48));
          if (((piVar21 == (int *)0x0) || (*piVar21 != 0x198)) ||
             (pbVar12 = (byte *)piVar21[5], pbVar12 == (byte *)0x0)) {
            uVar17 = 0x44;
            uVar6 = 0x9fb;
            goto LAB_004872f8;
          }
        }
        else {
          piVar21 = (int *)0x0;
        }
        pbVar20 = (byte *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(pbVar12);
        iVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(pbVar12);
        if ((pbVar20 == (byte *)0x0) || (iVar4 == 0)) {
          uVar17 = 0x44;
          uVar6 = 0xa08;
LAB_004872f8:
          pcVar15 = "s3_clnt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar17,"s3_clnt.c",uVar6);
          goto LAB_00487124;
        }
        pbVar12 = (byte *)(*(code *)PTR_EC_KEY_new_006a82a8)();
        if (pbVar12 == (byte *)0x0) {
          uVar17 = 0x41;
          uVar6 = 0xa0e;
          goto LAB_004872f8;
        }
        iVar11 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(pbVar12,pbVar20);
        if (iVar11 == 0) {
          uVar17 = 0x10;
          uVar6 = 0xa14;
        }
        else {
          iVar11 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(pbVar12);
          if (iVar11 == 0) {
            uVar17 = 0x2b;
            uVar6 = 0xa30;
          }
          else {
            iVar11 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(pbVar20);
            if (iVar11 < 1) {
              uVar17 = 0x2b;
              uVar6 = 0xa3d;
            }
            else {
              iVar4 = (*(code *)PTR_ECDH_compute_key_006a8bd4)
                                (puVar18,iVar11 + 7 >> 3,iVar4,pbVar12,0);
              if (0 < iVar4) {
                iVar11 = piVar7[0x30];
                uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))
                                  (piVar7,iVar11 + 0x14,puVar18,iVar4);
                puVar2 = PTR_memset_006aab00;
                *(undefined4 *)(iVar11 + 0x10) = uVar6;
                (*(code *)puVar2)(puVar18,0,iVar4);
                uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(pbVar12);
                uVar6 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(pbVar20,uVar6,4,0,0,0);
                pbVar8 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar6,"s3_clnt.c",0xa62);
                iVar4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
                if (pbVar8 == (byte *)0x0) {
                  pcVar15 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
                  goto LAB_004871d0;
                }
                if (iVar4 == 0) {
                  pcVar15 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(0);
                  (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar8);
                  goto LAB_004871d0;
                }
                uVar17 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(pbVar12);
                pcVar15 = (char *)pbVar8;
                iVar13 = (*(code *)PTR_EC_POINT_point2oct_006a9118)
                                   (pbVar20,uVar17,4,pbVar8,uVar6,iVar4);
                puVar19[4] = (char)iVar13;
                iVar11 = iVar13 + 1;
                (*(code *)PTR_memcpy_006aabf4)(puVar19 + 5,pbVar8,iVar13);
                (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
                (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar8);
                (*(code *)PTR_EC_KEY_free_006a82d8)(pbVar12);
                (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar21);
                goto LAB_00486a04;
              }
              uVar17 = 0x2b;
              uVar6 = 0xa44;
            }
          }
        }
        pcVar15 = "s3_clnt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar17,"s3_clnt.c",uVar6);
        (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_004871d0:
        (*(code *)PTR_EC_KEY_free_006a82d8)(pbVar12);
        goto LAB_00487134;
      }
      if ((uVar5 & 0x200) == 0) {
        if ((uVar5 & 0x400) == 0) {
          if ((uVar5 & 0x100) == 0) {
            ssl3_send_alert();
            uVar17 = 0x44;
            uVar6 = 0xb54;
          }
          else {
            if ((code *)piVar7[0x37] != (code *)0x0) {
              pbVar12 = abStack_2f0;
              pbVar20 = abStack_370;
              uVar6 = 0x204;
              pbVar8 = pbVar12;
              uVar5 = (*(code *)piVar7[0x37])();
              if (0x100 < uVar5) {
                uVar17 = 0x44;
                pcVar15 = "s3_clnt.c";
                uVar6 = 0xb14;
                goto LAB_00487250;
              }
              if (uVar5 == 0) {
                uVar17 = 0xdf;
                pcVar15 = "s3_clnt.c";
                uVar6 = 0xb1a;
                goto LAB_00487250;
              }
              (*(code *)PTR_memmove_006aabfc)(pbVar12 + uVar5 + 4,pbVar12,uVar5);
              bVar23 = (byte)(uVar5 >> 8);
              abStack_2f0[0] = bVar23;
              abStack_2f0[1] = (byte)uVar5;
              (*(code *)PTR___memset_chk_006aaa98)(abStack_2f0 + 2,0,uVar5,0x202,pbVar8,uVar6);
              iVar4 = piVar7[0x30];
              (abStack_2f0 + 2)[uVar5] = bVar23;
              abStack_2f0[uVar5 + 3] = (byte)uVar5;
              pcVar15 = (char *)(uVar5 * 2 + 4);
              if (*(int *)(iVar4 + 0x8c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar4 = piVar7[0x30];
              }
              uVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(piVar7[0x39] + 0x14c));
              iVar11 = piVar7[0x39];
              iVar13 = piVar7[0x30];
              *(undefined4 *)(iVar4 + 0x8c) = uVar6;
              if ((*(int *)(iVar11 + 0x14c) != 0) &&
                 (pbVar8 = (byte *)0x640000, *(int *)(iVar13 + 0x8c) == 0)) goto LAB_00487694;
              if (*(int *)(iVar13 + 0x90) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar13 = piVar7[0x30];
              }
              uVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(pbVar20);
              iVar4 = piVar7[0x30];
              *(undefined4 *)(iVar13 + 0x90) = uVar6;
              if (*(int *)(iVar4 + 0x90) == 0) {
                uVar17 = 0x41;
                pcVar15 = "s3_clnt.c";
                uVar6 = 0xb38;
                goto LAB_00487250;
              }
              uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))
                                (piVar7,iVar4 + 0x14,pbVar12,pcVar15);
              puVar18 = PTR_strlen_006aab30;
              *(undefined4 *)(iVar4 + 0x10) = uVar6;
              iVar4 = (*(code *)puVar18)(pbVar20);
              puVar19[5] = (char)iVar4;
              puVar19[4] = (char)((uint)iVar4 >> 8);
              iVar11 = iVar4 + 2;
              (*(code *)PTR_memcpy_006aabf4)(puVar19 + 6,pbVar20,iVar4);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar20,0x80);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar12,0x204);
              goto LAB_00486a04;
            }
            uVar17 = 0xe0;
            uVar6 = 0xb0a;
          }
        }
        else {
          pcVar15 = "s\n";
          if (piVar7[0x6e] == 0) {
            uVar17 = 0x44;
            uVar6 = 0xae9;
          }
          else {
            iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)();
            puVar18 = PTR_BN_bn2bin_006a8300;
            iVar4 = iVar11 + 7;
            if (iVar11 + 7 < 0) {
              iVar4 = iVar11 + 0xe;
            }
            iVar11 = (iVar4 >> 3) + 2;
            puVar19[5] = (char)(iVar4 >> 3);
            puVar19[4] = (char)(iVar4 >> 0xb);
            (*(code *)puVar18)(piVar7[0x6e],puVar19 + 6);
            pbVar20 = (byte *)piVar7[0x30];
            if (*(int *)(pbVar20 + 0xf0) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              pbVar20 = (byte *)piVar7[0x30];
            }
            uVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(piVar7[0x69]);
            pbVar12 = (byte *)piVar7[0x30];
            *(undefined4 *)(pbVar20 + 0xf0) = uVar6;
            unaff_s4 = pbVar12;
            unaff_s5 = pbVar20;
            if (*(int *)(pbVar12 + 0xf0) == 0) {
              uVar17 = 0x41;
              uVar6 = 0xaf2;
            }
            else {
              iVar4 = (*(code *)PTR_SRP_generate_client_master_secret_006a91cc)
                                (piVar7,pbVar12 + 0x14);
              *(int *)(pbVar12 + 0x10) = iVar4;
              if (-1 < iVar4) goto LAB_00486a04;
              uVar17 = 0x44;
              uVar6 = 0xaf8;
            }
          }
        }
      }
      else if ((*(int *)(*(int *)(piVar7[0x30] + 0x98) + 0x60) == 0) &&
              (*(int *)(*(int *)(piVar7[0x30] + 0x98) + 0x54) == 0)) {
        uVar17 = 0x14a;
        uVar6 = 0xa93;
      }
      else {
        uVar6 = (*(code *)PTR_X509_get_pubkey_006a8008)();
        pbVar20 = (byte *)(*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(uVar6,0);
        (*(code *)PTR_EVP_PKEY_encrypt_init_006a8ddc)(pbVar20);
        (*(code *)PTR_RAND_bytes_006a8d44)(auStack_390,0x20);
        if (((*(int *)(piVar7[0x16] + 0x358) != 0) && (*(int *)(*(int *)piVar7[0x26] + 4) != 0)) &&
           (iVar4 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(pbVar20), iVar4 < 1)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        uVar17 = (*(code *)PTR_EVP_MD_CTX_create_006a91c4)();
        uVar9 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x329);
        uVar9 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar9);
        (*(code *)PTR_EVP_DigestInit_006a8f30)(uVar17,uVar9);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar17,piVar7[0x16] + 0xc0,0x20);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar17,piVar7[0x16] + 0xa0,0x20);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(uVar17,abStack_370,auStack_394);
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(uVar17);
        iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(pbVar20,0xffffffff,0x100,8,8,abStack_370);
        puVar18 = PTR_EVP_PKEY_encrypt_006a8e04;
        unaff_s5 = pbVar20;
        if (iVar4 < 0) {
          uVar17 = 0x112;
          uVar6 = 0xab7;
          unaff_s4 = abStack_370;
        }
        else {
          puVar19[4] = 0x30;
          uStack_398 = 0xff;
          iVar4 = (*(code *)puVar18)(pbVar20,abStack_2f0,&uStack_398,auStack_390,0x20);
          if (-1 < iVar4) {
            iVar11 = uStack_398 + 2;
            uVar10 = (undefined)uStack_398;
            if (uStack_398 < 0x80) {
              puVar18 = puVar19 + 6;
            }
            else {
              puVar18 = puVar19 + 7;
              puVar19[6] = uVar10;
              iVar11 = uStack_398 + 3;
              uVar10 = 0x81;
            }
            puVar2 = PTR_memcpy_006aabf4;
            puVar19[5] = uVar10;
            (*(code *)puVar2)(puVar18,abStack_2f0);
            iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(pbVar20,0xffffffff,0xffffffff,2,2,0);
            if (0 < iVar4) {
              *(uint *)piVar7[0x16] = *(uint *)piVar7[0x16] | 0x10;
            }
            (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(pbVar20);
            pcVar15 = &DAT_00000020;
            pbVar12 = (byte *)piVar7[0x30];
            uVar17 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))
                               (piVar7,pbVar12 + 0x14,auStack_390,0x20);
            puVar18 = PTR_EVP_PKEY_free_006a7f78;
            *(undefined4 *)(pbVar12 + 0x10) = uVar17;
            (*(code *)puVar18)(uVar6);
            goto LAB_00486a04;
          }
          uVar17 = 0x112;
          uVar6 = 0xac0;
          unaff_s4 = abStack_2f0;
        }
      }
    }
    else if (*(int *)(piVar7[0x30] + 0x98) == 0) {
      ssl3_send_alert();
      uVar17 = 0xf4;
      uVar6 = 0x98f;
    }
    else {
      pbVar20 = *(byte **)(*(int *)(piVar7[0x30] + 0x98) + 0x70);
      if (pbVar20 == (byte *)0x0) {
        ssl3_send_alert();
        uVar17 = 0xee;
        uVar6 = 0x999;
        unaff_s5 = pbVar20;
      }
      else {
        pbVar12 = (byte *)(*(code *)PTR_DHparams_dup_006a90f8)(pbVar20);
        if (pbVar12 != (byte *)0x0) {
          iVar4 = (*(code *)PTR_DH_generate_key_006a90fc)(pbVar12);
          if (iVar4 == 0) {
            uVar6 = 0x9a5;
LAB_004874a8:
            pcVar15 = "s3_clnt.c";
            piVar21 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,5,"s3_clnt.c",uVar6);
            (*(code *)PTR_DH_free_006a8604)(pbVar12);
            goto LAB_00487124;
          }
          pbVar20 = (byte *)(*(code *)PTR_DH_compute_key_006a912c)
                                      (puVar18,*(undefined4 *)(pbVar20 + 0x14),pbVar12);
          if ((int)pbVar20 < 1) {
            uVar6 = 0x9b1;
            goto LAB_004874a8;
          }
          iVar4 = piVar7[0x30];
          pcVar15 = (char *)pbVar20;
          uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))
                            (piVar7,iVar4 + 0x14,puVar18,pbVar20);
          puVar2 = PTR_memset_006aab00;
          *(undefined4 *)(iVar4 + 0x10) = uVar6;
          (*(code *)puVar2)(puVar18,0,pbVar20);
          iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(pbVar12 + 0x14));
          puVar18 = PTR_BN_bn2bin_006a8300;
          iVar4 = iVar11 + 7;
          if (iVar11 + 7 < 0) {
            iVar4 = iVar11 + 0xe;
          }
          iVar11 = (iVar4 >> 3) + 2;
          puVar19[5] = (char)(iVar4 >> 3);
          puVar19[4] = (char)(iVar4 >> 0xb);
          (*(code *)puVar18)(*(undefined4 *)(pbVar12 + 0x14),puVar19 + 6);
          (*(code *)PTR_DH_free_006a8604)(pbVar12);
          goto LAB_00486a04;
        }
        uVar17 = 5;
        uVar6 = 0x9a0;
        unaff_s4 = pbVar12;
        unaff_s5 = pbVar20;
      }
    }
  }
  else {
    pbVar20 = *(byte **)(*(int *)(piVar7[0x30] + 0x98) + 0x6c);
    if (pbVar20 == (byte *)0x0) {
      piVar21 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                 (*(undefined4 *)(*(int *)(piVar7[0x30] + 0x98) + 0xc));
      if (((piVar21 == (int *)0x0) || (pcVar15 = "s\n", *piVar21 != 6)) ||
         (pbVar20 = (byte *)piVar21[5], pbVar20 == (byte *)0x0)) {
        uVar17 = 0x44;
        uVar6 = 0x8d5;
        unaff_s5 = pbVar20;
        goto LAB_0048710c;
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar21);
    }
    abStack_2f0[1] = (byte)piVar7[0x44];
    abStack_2f0[0] = (byte)((uint)piVar7[0x44] >> 8);
    iVar4 = (*(code *)PTR_RAND_bytes_006a8d44)(abStack_2f0 + 2,0x2e);
    puVar2 = PTR_RSA_public_encrypt_006a8744;
    if (iVar4 < 1) goto LAB_00487120;
    pbVar12 = abStack_2f0;
    puVar16 = puVar19 + 6;
    if (*piVar7 < 0x301) {
      puVar16 = puVar18;
    }
    *(undefined4 *)(piVar7[0x30] + 0x10) = 0x30;
    iVar4 = (*(code *)puVar2)(0x30,pbVar12,puVar16,pbVar20,1);
    if (0 < iVar4) {
      iVar11 = iVar4;
      if (0x300 < *piVar7) {
        puVar19[5] = (char)iVar4;
        iVar11 = iVar4 + 2;
        puVar19[4] = (char)((uint)iVar4 >> 8);
      }
      pcVar15 = &DAT_00000030;
      pbVar20 = (byte *)piVar7[0x30];
      uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))(piVar7,pbVar20 + 0x14,pbVar12,0x30);
      puVar18 = PTR_OPENSSL_cleanse_006a8174;
      *(undefined4 *)(pbVar20 + 0x10) = uVar6;
      (*(code *)puVar18)(pbVar12,0x30);
LAB_00486a04:
      puVar19[3] = (char)iVar11;
      puVar19[2] = (char)((uint)iVar11 >> 8);
      puVar19[1] = (char)((uint)iVar11 >> 0x10);
      *puVar19 = 0x10;
      piVar7[0x11] = iVar11 + 4;
      piVar7[0xd] = 0x1181;
      piVar7[0x12] = 0;
LAB_00486a38:
      uVar5 = ssl3_do_write(piVar7,0x16);
      pbVar8 = (byte *)pcVar15;
      goto LAB_00486a48;
    }
    uVar17 = 0x77;
    uVar6 = 0x8ef;
    unaff_s4 = pbVar12;
    unaff_s5 = pbVar20;
  }
LAB_0048710c:
  pcVar15 = "s3_clnt.c";
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar17,"s3_clnt.c",uVar6);
  pbVar12 = unaff_s4;
  pbVar20 = unaff_s5;
LAB_00487120:
  while( true ) {
    piVar21 = (int *)0x0;
LAB_00487124:
    (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_00487134:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar21);
    uVar5 = 0xffffffff;
    pbVar8 = (byte *)pcVar15;
LAB_00486a48:
    if (iStack_ec == *(int *)puVar3) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00487694:
    uVar17 = 0x41;
    pcVar15 = (char *)(pbVar8 + 0x6958);
    uVar6 = 0xb2e;
LAB_00487250:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar17,pcVar15,uVar6);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar20,0x80);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar12,0x204);
    ssl3_send_alert(piVar7,2,0x28);
  }
  return uVar5;
}

