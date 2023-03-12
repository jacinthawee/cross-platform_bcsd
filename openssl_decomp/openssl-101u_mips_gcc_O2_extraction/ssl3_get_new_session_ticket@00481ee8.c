
/* WARNING: Heritage AFTER dead removal. Example location: r0x006a7f34 : 0x00482300 */
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
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  undefined *puVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined *puVar17;
  int iVar18;
  uint unaff_s2;
  undefined *puVar19;
  char *unaff_s4;
  undefined4 unaff_s5;
  char *unaff_s6;
  int *piVar20;
  code *pcVar21;
  undefined uVar22;
  uint uStack_394;
  undefined auStack_390 [4];
  undefined auStack_38c [32];
  undefined auStack_36c [129];
  undefined uStack_2eb;
  undefined auStack_2e8 [516];
  int iStack_e4;
  undefined *puStack_e0;
  int iStack_dc;
  uint uStack_d8;
  undefined *puStack_d4;
  char *pcStack_d0;
  undefined4 uStack_cc;
  char *pcStack_c8;
  int iStack_98;
  int iStack_60;
  int local_28;
  
  puStack_d4 = PTR___stack_chk_guard_006a9ae8;
  iVar4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11e0,0x11e1,4);
  if (local_28 != 0) {
    if ((int)uVar5 < 6) {
LAB_00482114:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11b,0x9f,"s3_clnt.c");
      uVar6 = 0x32;
LAB_0048212c:
      ssl3_send_alert(param_1,2,uVar6);
    }
    else {
      puVar16 = *(undefined4 **)(param_1 + 0x40);
      unaff_s2 = (uint)*(ushort *)(puVar16 + 1);
      if (uVar5 != unaff_s2 + 6) goto LAB_00482114;
      uVar5 = 1;
      if (unaff_s2 == 0) goto LAB_0048204c;
      unaff_s4 = *(char **)(param_1 + 0xc0);
      unaff_s5 = *puVar16;
      unaff_s6 = unaff_s4;
      if (*(int *)(unaff_s4 + 0x44) != 0) {
        iVar12 = *(int *)(param_1 + 0x170);
        if ((*(uint *)(iVar12 + 0x20) & 1) != 0) {
          if ((*(uint *)(iVar12 + 0x20) & 0x200) == 0) {
            (*(code *)PTR_SSL_CTX_remove_session_006a807c)(iVar12,unaff_s4);
            unaff_s4 = *(char **)(param_1 + 0xc0);
          }
          else if (*(code **)(iVar12 + 0x2c) != (code *)0x0) {
            (**(code **)(iVar12 + 0x2c))(iVar12,unaff_s4);
            unaff_s4 = *(char **)(param_1 + 0xc0);
          }
        }
        unaff_s6 = (char *)(*(code *)PTR_ssl_session_dup_006a8078)(unaff_s4,0);
        if (unaff_s6 != (char *)0x0) {
          (*(code *)PTR_SSL_SESSION_free_006a79b4)(*(undefined4 *)(param_1 + 0xc0));
          *(char **)(param_1 + 0xc0) = unaff_s6;
          goto LAB_00481fa8;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11b,0x41,"s3_clnt.c");
        uVar6 = 0x50;
        goto LAB_0048212c;
      }
LAB_00481fa8:
      if (*(int *)(unaff_s6 + 0xe4) != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        unaff_s6 = *(char **)(param_1 + 0xc0);
        *(undefined4 *)(unaff_s6 + 0xe8) = 0;
      }
      uVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s2,"s3_clnt.c",0x8b3);
      iVar12 = *(int *)(param_1 + 0xc0);
      *(undefined4 *)(unaff_s6 + 0xe4) = uVar6;
      iVar12 = *(int *)(iVar12 + 0xe4);
      unaff_s4 = unaff_s6;
      if (iVar12 != 0) {
        (*(code *)PTR_memcpy_006a9aec)(iVar12,(int)puVar16 + 6,unaff_s2);
        puVar3 = PTR_EVP_sha256_006a8000;
        iVar12 = *(int *)(param_1 + 0xc0);
        *(undefined4 *)(iVar12 + 0xec) = unaff_s5;
        *(uint *)(iVar12 + 0xe8) = unaff_s2;
        (*(code *)puVar3)();
        (*(code *)PTR_EVP_Digest_006a7a14)((int)puVar16 + 6,unaff_s2,iVar12 + 0x48,iVar12 + 0x44);
        uVar5 = 1;
        unaff_s6 = "-check_ss_sig";
        goto LAB_0048204c;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11b,0x41,"s3_clnt.c");
      unaff_s6 = "-check_ss_sig";
    }
    uVar5 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
LAB_0048204c:
  if (iVar4 == *(int *)puStack_d4) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (**(code **)(*(int *)(iVar4 + 8) + 0x30))();
  if (iStack_60 != 0) {
    if (*(int *)(*(int *)(iVar4 + 0x58) + 0x340) == 0x16) {
      if (uVar5 < 4) {
        uVar6 = 0x9f;
      }
      else {
        pcVar13 = *(char **)(iVar4 + 0x40);
        if (*pcVar13 == '\x01') {
          unaff_s2 = (uint)(byte)pcVar13[1] << 0x10 | (uint)(byte)pcVar13[2] << 8 |
                     (uint)(byte)pcVar13[3];
          if (uVar5 == unaff_s2 + 4) {
            iVar12 = (*(code *)PTR_BUF_memdup_006a8080)(pcVar13 + 4,unaff_s2);
            *(int *)(iVar4 + 0x138) = iVar12;
            if (iVar12 != 0) {
              *(uint *)(iVar4 + 0x13c) = unaff_s2;
              goto LAB_0048224c;
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,0x41,"s3_clnt.c");
            uVar6 = 0x50;
            goto LAB_00482328;
          }
          uVar6 = 0x9f;
        }
        else {
          uVar6 = 0x149;
        }
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,uVar6,"s3_clnt.c");
      uVar6 = 0x32;
    }
    else {
      *(undefined4 *)(*(int *)(iVar4 + 0x58) + 0x354) = 1;
LAB_0048224c:
      pcVar21 = *(code **)(*(int *)(iVar4 + 0xe4) + 0x13c);
      if (pcVar21 == (code *)0x0) {
LAB_00482278:
        uVar5 = 1;
        goto LAB_0048227c;
      }
      iVar12 = (*pcVar21)(iVar4,*(undefined4 *)(*(int *)(iVar4 + 0xe4) + 0x140));
      if (iVar12 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,0x148,"s3_clnt.c");
        uVar6 = 0x71;
      }
      else {
        if (-1 < iVar12) goto LAB_00482278;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,0x41,"s3_clnt.c");
        uVar6 = 0x50;
      }
    }
LAB_00482328:
    ssl3_send_alert(iVar4,2,uVar6);
    uVar5 = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x34) = 5;
  }
LAB_0048227c:
  if (iStack_dc == *(int *)puVar3) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_e0 = PTR___stack_chk_guard_006a9ae8;
  piVar7 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (**(code **)(*(int *)(iStack_dc + 8) + 0x30))();
  if ((iStack_98 != 0) && (bVar1 = 0 < (int)uVar5, uVar5 = 1, bVar1)) {
    ssl3_send_alert(iStack_dc,2,0x32);
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x91,0x9f,"s3_clnt.c");
    uVar5 = 0xffffffff;
    *(undefined4 *)(iStack_dc + 0x34) = 5;
  }
  if (piVar7 == *(int **)puStack_e0) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_d8 = unaff_s2;
  pcStack_d0 = unaff_s4;
  uStack_cc = unaff_s5;
  pcStack_c8 = unaff_s6;
  if (piVar7[0xd] != 0x1180) goto LAB_0048268c;
  puVar19 = *(undefined **)(piVar7[0xf] + 4);
  uVar5 = *(uint *)(*(int *)(piVar7[0x16] + 0x344) + 0xc);
  puVar17 = puVar19 + 4;
  if ((uVar5 & 1) == 0) {
    if ((uVar5 & 0xe) == 0) {
      if ((uVar5 & 0xe0) != 0) {
        iVar4 = *(int *)(piVar7[0x30] + 0x98);
        if (iVar4 == 0) {
          ssl3_send_alert();
          uVar15 = 0xf4;
          uVar6 = 0xa65;
          goto LAB_00482d24;
        }
        iVar12 = *(int *)(iVar4 + 0x74);
        if (iVar12 == 0) {
          piVar20 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar4 + 0x48));
          if (((piVar20 == (int *)0x0) || (*piVar20 != 0x198)) || (iVar12 = piVar20[5], iVar12 == 0)
             ) {
            uVar15 = 0x44;
            uVar6 = 0xa90;
            goto LAB_00482f4c;
          }
        }
        else {
          piVar20 = (int *)0x0;
        }
        iVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar12);
        iVar12 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar12);
        if ((iVar4 == 0) || (iVar12 == 0)) {
          uVar15 = 0x44;
          uVar6 = 0xa9c;
LAB_00482f4c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar6);
          goto LAB_00482d3c;
        }
        iVar8 = (*(code *)PTR_EC_KEY_new_006a71a8)();
        if (iVar8 == 0) {
          uVar15 = 0x41;
          uVar6 = 0xaa2;
          goto LAB_00482f4c;
        }
        iVar18 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar8,iVar4);
        if (iVar18 == 0) {
          uVar15 = 0x10;
          uVar6 = 0xaa7;
        }
        else {
          iVar18 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar8);
          if (iVar18 == 0) {
            uVar15 = 0x2b;
            uVar6 = 0xabf;
          }
          else {
            iVar18 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(iVar4);
            if (iVar18 < 1) {
              uVar15 = 0x2b;
              uVar6 = 0xacb;
            }
            else {
              iVar12 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                                 (puVar17,iVar18 + 7 >> 3,iVar12,iVar8,0);
              if (0 < iVar12) {
                iVar18 = piVar7[0x30];
                uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))
                                  (piVar7,iVar18 + 0x14,puVar17,iVar12);
                puVar2 = PTR_memset_006a99f4;
                *(undefined4 *)(iVar18 + 0x10) = uVar6;
                (*(code *)puVar2)(puVar17,0,iVar12);
                uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar8);
                uVar6 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar4,uVar6,4,0,0,0);
                iVar12 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar6,"s3_clnt.c",0xaed);
                iVar9 = (*(code *)PTR_BN_CTX_new_006a794c)();
                if (iVar12 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(iVar9);
                  goto LAB_00482dec;
                }
                if (iVar9 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(0);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar12);
                  goto LAB_00482dec;
                }
                uVar15 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar8);
                iVar4 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)
                                  (iVar4,uVar15,4,iVar12,uVar6,iVar9);
                puVar19[4] = (char)iVar4;
                iVar18 = iVar4 + 1;
                (*(code *)PTR_memcpy_006a9aec)(puVar19 + 5,iVar12,iVar4);
                (*(code *)PTR_BN_CTX_free_006a7954)(iVar9);
                (*(code *)PTR_CRYPTO_free_006a6e88)(iVar12);
                (*(code *)PTR_EC_KEY_free_006a71d4)(iVar8);
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
                goto LAB_00482658;
              }
              uVar15 = 0x2b;
              uVar6 = 0xad1;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar6);
        (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482dec:
        (*(code *)PTR_EC_KEY_free_006a71d4)(iVar8);
        goto LAB_00482d4c;
      }
      if ((uVar5 & 0x200) == 0) {
        if ((uVar5 & 0x400) == 0) {
          if ((uVar5 & 0x100) == 0) goto LAB_004833a8;
          pcVar21 = (code *)piVar7[0x37];
          if (pcVar21 == (code *)0x0) {
            uVar15 = 0xe0;
            uVar6 = 0xbaa;
            goto LAB_00482d24;
          }
          (*(code *)PTR_memset_006a99f4)(auStack_36c,0,0x82);
          uVar5 = (*pcVar21)(piVar7,*(undefined4 *)(piVar7[0x30] + 0x8c),auStack_36c,0x81,
                             auStack_2e8,0x204);
          if (0x100 < uVar5) {
            uVar15 = 0x44;
            uVar6 = 0xbb5;
LAB_00482ea0:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar6);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_36c,0x82);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2e8,0x204);
            ssl3_send_alert(piVar7,2,0x28);
            goto LAB_00482d38;
          }
          if (uVar5 == 0) {
            uVar15 = 0xdf;
            uVar6 = 0xbb9;
            goto LAB_00482ea0;
          }
          uStack_2eb = 0;
          uVar11 = (*(code *)PTR_strlen_006a9a24)(auStack_36c);
          if (0x80 < uVar11) {
            uVar15 = 0x44;
            uVar6 = 0xbc0;
            goto LAB_00482ea0;
          }
          (*(code *)PTR_memmove_006a9af4)(auStack_2e8 + uVar5 + 4,auStack_2e8,uVar5);
          uVar22 = (undefined)(uVar5 >> 8);
          auStack_2e8[0] = uVar22;
          auStack_2e8[1] = (char)uVar5;
          (*(code *)PTR___memset_chk_006a998c)(auStack_2e8 + 2,0,uVar5,0x202);
          iVar4 = piVar7[0x30];
          (auStack_2e8 + 2)[uVar5] = uVar22;
          auStack_2e8[uVar5 + 3] = (char)uVar5;
          if (*(int *)(iVar4 + 0x8c) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar4 = piVar7[0x30];
          }
          uVar6 = (*(code *)PTR_BUF_strdup_006a6fdc)(*(undefined4 *)(piVar7[0x39] + 0x14c));
          iVar12 = piVar7[0x39];
          iVar18 = piVar7[0x30];
          *(undefined4 *)(iVar4 + 0x8c) = uVar6;
          if ((*(int *)(iVar12 + 0x14c) != 0) && (*(int *)(iVar18 + 0x8c) == 0)) {
            uVar15 = 0x41;
            uVar6 = 0xbd3;
            goto LAB_00482ea0;
          }
          if (*(int *)(iVar18 + 0x90) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar18 = piVar7[0x30];
          }
          uVar6 = (*(code *)PTR_BUF_strdup_006a6fdc)(auStack_36c);
          iVar4 = piVar7[0x30];
          *(undefined4 *)(iVar18 + 0x90) = uVar6;
          if (*(int *)(iVar4 + 0x90) == 0) {
            uVar15 = 0x41;
            uVar6 = 0xbdc;
            goto LAB_00482ea0;
          }
          iVar18 = uVar11 + 2;
          uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))
                            (piVar7,iVar4 + 0x14,auStack_2e8,uVar5 * 2 + 4);
          *(undefined4 *)(iVar4 + 0x10) = uVar6;
          puVar19[5] = (char)uVar11;
          puVar17 = PTR_memcpy_006a9aec;
          puVar19[4] = 0;
          (*(code *)puVar17)(puVar19 + 6,auStack_36c,uVar11);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_36c,0x82);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2e8,0x204);
        }
        else {
          if (piVar7[0x6e] == 0) {
            uVar15 = 0x44;
            uVar6 = 0xb83;
            goto LAB_00482d24;
          }
          iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)();
          puVar17 = PTR_BN_bn2bin_006a7200;
          iVar4 = iVar12 + 7;
          if (iVar12 + 7 < 0) {
            iVar4 = iVar12 + 0xe;
          }
          iVar18 = (iVar4 >> 3) + 2;
          puVar19[5] = (char)(iVar4 >> 3);
          puVar19[4] = (char)(iVar4 >> 0xb);
          (*(code *)puVar17)(piVar7[0x6e],puVar19 + 6);
          iVar4 = piVar7[0x30];
          if (*(int *)(iVar4 + 0xf0) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar4 = piVar7[0x30];
          }
          uVar6 = (*(code *)PTR_BUF_strdup_006a6fdc)(piVar7[0x69]);
          iVar12 = piVar7[0x30];
          *(undefined4 *)(iVar4 + 0xf0) = uVar6;
          if (*(int *)(iVar12 + 0xf0) == 0) {
            uVar15 = 0x41;
            uVar6 = 0xb8b;
            goto LAB_00482d24;
          }
          iVar4 = (*(code *)PTR_SRP_generate_client_master_secret_006a808c)(piVar7,iVar12 + 0x14);
          *(int *)(iVar12 + 0x10) = iVar4;
          if (iVar4 < 0) {
            uVar15 = 0x44;
            uVar6 = 0xb94;
            goto LAB_00482d24;
          }
        }
      }
      else {
        if ((*(int *)(*(int *)(piVar7[0x30] + 0x98) + 0x60) == 0) &&
           (*(int *)(*(int *)(piVar7[0x30] + 0x98) + 0x54) == 0)) {
          uVar15 = 0x14a;
          uVar6 = 0xb24;
          goto LAB_00482d24;
        }
        uVar6 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
        iVar4 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(uVar6,0);
        if (iVar4 == 0) {
          uVar15 = 0x41;
          uVar6 = 0xb2c;
          goto LAB_00482d24;
        }
        iVar12 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(iVar4);
        if (iVar12 < 1) {
LAB_00483224:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar4);
          uVar15 = 0x44;
          uVar6 = 0xb3e;
          goto LAB_00482d24;
        }
        iVar12 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_38c,0x20);
        if (iVar12 < 1) goto LAB_00483224;
        uVar15 = (*(code *)PTR_EVP_MD_CTX_create_006a8084)();
        uVar10 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x329);
        uVar10 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar10);
        iVar12 = (*(code *)PTR_EVP_DigestInit_006a7e40)(uVar15,uVar10);
        if (((iVar12 < 1) ||
            (iVar12 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar15,piVar7[0x16] + 0xc0,0x20),
            iVar12 < 1)) ||
           (iVar12 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar15,piVar7[0x16] + 0xa0,0x20),
           iVar12 < 1)) {
LAB_004831a8:
          (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar15);
          uVar15 = 0x44;
          uVar6 = 0xb4f;
          goto LAB_00482d24;
        }
        iVar12 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(uVar15,auStack_36c,auStack_390);
        if (iVar12 < 1) goto LAB_004831a8;
        (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar15);
        iVar12 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar4,0xffffffff,0x100,8,8,auStack_36c);
        puVar17 = PTR_EVP_PKEY_encrypt_006a7d14;
        if (iVar12 < 0) {
          uVar15 = 0x112;
          uVar6 = 0xb57;
          goto LAB_00482d24;
        }
        puVar19[4] = 0x30;
        uStack_394 = 0xff;
        iVar12 = (*(code *)puVar17)(iVar4,auStack_2e8,&uStack_394,auStack_38c,0x20);
        if (iVar12 < 1) {
          uVar15 = 0x112;
          uVar6 = 0xb63;
          goto LAB_00482d24;
        }
        uVar22 = (undefined)uStack_394;
        if (uStack_394 < 0x80) {
          puVar17 = puVar19 + 6;
          iVar18 = uStack_394 + 2;
        }
        else {
          puVar17 = puVar19 + 7;
          puVar19[6] = uVar22;
          iVar18 = uStack_394 + 3;
          uVar22 = 0x81;
        }
        puVar2 = PTR_memcpy_006a9aec;
        puVar19[5] = uVar22;
        (*(code *)puVar2)(puVar17,auStack_2e8);
        (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar4);
        iVar4 = piVar7[0x30];
        uVar15 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))
                           (piVar7,iVar4 + 0x14,auStack_38c,0x20);
        puVar17 = PTR_EVP_PKEY_free_006a6e78;
        *(undefined4 *)(iVar4 + 0x10) = uVar15;
        (*(code *)puVar17)(uVar6);
      }
    }
    else {
      if (*(int *)(piVar7[0x30] + 0x98) == 0) {
        ssl3_send_alert();
        uVar15 = 0xf4;
        uVar6 = 0xa22;
        goto LAB_00482d24;
      }
      iVar4 = *(int *)(*(int *)(piVar7[0x30] + 0x98) + 0x70);
      if (iVar4 == 0) {
        ssl3_send_alert();
        uVar15 = 0xee;
        uVar6 = 0xa2c;
        goto LAB_00482d24;
      }
      iVar12 = (*(code *)PTR_DHparams_dup_006a7f8c)(iVar4);
      if (iVar12 == 0) {
        uVar15 = 5;
        uVar6 = 0xa32;
        goto LAB_00482d24;
      }
      iVar18 = (*(code *)PTR_DH_generate_key_006a7f90)(iVar12);
      if (iVar18 == 0) {
        uVar6 = 0xa36;
LAB_00482f78:
        piVar20 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,5,"s3_clnt.c",uVar6);
        (*(code *)PTR_DH_free_006a7508)(iVar12);
        goto LAB_00482d3c;
      }
      iVar4 = (*(code *)PTR_DH_compute_key_006a7fa4)(puVar17,*(undefined4 *)(iVar4 + 0x14),iVar12);
      if (iVar4 < 1) {
        uVar6 = 0xa43;
        goto LAB_00482f78;
      }
      iVar18 = piVar7[0x30];
      uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))(piVar7,iVar18 + 0x14,puVar17,iVar4);
      puVar2 = PTR_memset_006a99f4;
      *(undefined4 *)(iVar18 + 0x10) = uVar6;
      (*(code *)puVar2)(puVar17,0,iVar4);
      iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar12 + 0x14));
      puVar17 = PTR_BN_bn2bin_006a7200;
      iVar4 = iVar18 + 7;
      if (iVar18 + 7 < 0) {
        iVar4 = iVar18 + 0xe;
      }
      iVar18 = (iVar4 >> 3) + 2;
      puVar19[5] = (char)(iVar4 >> 3);
      puVar19[4] = (char)(iVar4 >> 0xb);
      (*(code *)puVar17)(*(undefined4 *)(iVar12 + 0x14),puVar19 + 6);
      (*(code *)PTR_DH_free_006a7508)(iVar12);
    }
  }
  else {
    iVar4 = *(int *)(piVar7[0x30] + 0x98);
    if (iVar4 == 0) {
      uVar15 = 0x44;
      uVar6 = 0x95b;
      goto LAB_00482d24;
    }
    iVar12 = *(int *)(iVar4 + 0x6c);
    if (iVar12 == 0) {
      piVar20 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar4 + 0xc));
      if (((piVar20 == (int *)0x0) || (*piVar20 != 6)) || (iVar12 = piVar20[5], iVar12 == 0)) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x44,"s3_clnt.c",0x969);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
        goto LAB_00482d38;
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
    }
    auStack_2e8[1] = (undefined)piVar7[0x44];
    auStack_2e8[0] = (undefined)((uint)piVar7[0x44] >> 8);
    iVar4 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_2e8 + 2,0x2e);
    puVar2 = PTR_RSA_public_encrypt_006a7654;
    if (iVar4 < 1) goto LAB_00482d38;
    puVar14 = puVar19 + 6;
    if (*piVar7 < 0x301) {
      puVar14 = puVar17;
    }
    *(undefined4 *)(piVar7[0x30] + 0x10) = 0x30;
    iVar4 = (*(code *)puVar2)(0x30,auStack_2e8,puVar14,iVar12,1);
    if (iVar4 < 1) {
      uVar15 = 0x77;
      uVar6 = 0x986;
      goto LAB_00482d24;
    }
    iVar18 = iVar4;
    if (0x300 < *piVar7) {
      puVar19[5] = (char)iVar4;
      iVar18 = iVar4 + 2;
      puVar19[4] = (char)((uint)iVar4 >> 8);
    }
    iVar4 = piVar7[0x30];
    uVar6 = (**(code **)(*(int *)(piVar7[2] + 100) + 0xc))(piVar7,iVar4 + 0x14,auStack_2e8,0x30);
    puVar17 = PTR_OPENSSL_cleanse_006a7074;
    *(undefined4 *)(iVar4 + 0x10) = uVar6;
    (*(code *)puVar17)(auStack_2e8,0x30);
  }
LAB_00482658:
  puVar19[3] = (char)iVar18;
  puVar19[2] = (char)((uint)iVar18 >> 8);
  puVar19[1] = (char)((uint)iVar18 >> 0x10);
  *puVar19 = 0x10;
  piVar7[0x11] = iVar18 + 4;
  piVar7[0xd] = 0x1181;
  piVar7[0x12] = 0;
LAB_0048268c:
  uVar5 = ssl3_do_write(piVar7,0x16);
  while (iStack_e4 != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004833a8:
    ssl3_send_alert();
    uVar15 = 0x44;
    uVar6 = 0xbf5;
LAB_00482d24:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar6);
LAB_00482d38:
    piVar20 = (int *)0x0;
LAB_00482d3c:
    (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482d4c:
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
    uVar5 = 0xffffffff;
    piVar7[0xd] = 5;
  }
  return uVar5;
}

