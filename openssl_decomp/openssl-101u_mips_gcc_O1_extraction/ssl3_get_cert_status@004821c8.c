
/* WARNING: Heritage AFTER dead removal. Example location: r0x006a7f34 : 0x00482300 */
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
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  char *pcVar12;
  undefined *puVar13;
  undefined4 uVar14;
  undefined *puVar15;
  int iVar16;
  uint unaff_s2;
  undefined *puVar17;
  int iVar18;
  int *piVar19;
  code *pcVar20;
  undefined uVar21;
  uint uStack_34c;
  undefined auStack_348 [4];
  undefined auStack_344 [32];
  undefined auStack_324 [129];
  undefined uStack_2a3;
  undefined auStack_2a0 [516];
  int iStack_9c;
  undefined *puStack_98;
  int iStack_94;
  uint uStack_90;
  int iStack_50;
  int local_18;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11f0,0x11f1,0xffffffff);
  if (local_18 != 0) {
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x340) == 0x16) {
      if (uVar4 < 4) {
        uVar7 = 0x9f;
      }
      else {
        pcVar12 = *(char **)(param_1 + 0x40);
        if (*pcVar12 == '\x01') {
          unaff_s2 = (uint)(byte)pcVar12[1] << 0x10 | (uint)(byte)pcVar12[2] << 8 |
                     (uint)(byte)pcVar12[3];
          if (uVar4 == unaff_s2 + 4) {
            iVar5 = (*(code *)PTR_BUF_memdup_006a8080)(pcVar12 + 4,unaff_s2);
            *(int *)(param_1 + 0x138) = iVar5;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x13c) = unaff_s2;
              goto LAB_0048224c;
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,0x41,"s3_clnt.c");
            uVar7 = 0x50;
            goto LAB_00482328;
          }
          uVar7 = 0x9f;
        }
        else {
          uVar7 = 0x149;
        }
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,uVar7,"s3_clnt.c");
      uVar7 = 0x32;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x354) = 1;
LAB_0048224c:
      pcVar20 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
      if (pcVar20 == (code *)0x0) {
LAB_00482278:
        uVar4 = 1;
        goto LAB_0048227c;
      }
      iVar5 = (*pcVar20)(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,0x148,"s3_clnt.c");
        uVar7 = 0x71;
      }
      else {
        if (-1 < iVar5) goto LAB_00482278;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x121,0x41,"s3_clnt.c");
        uVar7 = 0x50;
      }
    }
LAB_00482328:
    ssl3_send_alert(param_1,2,uVar7);
    uVar4 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
LAB_0048227c:
  if (iStack_94 == *(int *)puVar3) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_98 = PTR___stack_chk_guard_006a9ae8;
  piVar6 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar4 = (**(code **)(*(int *)(iStack_94 + 8) + 0x30))();
  if ((iStack_50 != 0) && (bVar1 = 0 < (int)uVar4, uVar4 = 1, bVar1)) {
    ssl3_send_alert(iStack_94,2,0x32);
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x91,0x9f,"s3_clnt.c");
    uVar4 = 0xffffffff;
    *(undefined4 *)(iStack_94 + 0x34) = 5;
  }
  if (piVar6 == *(int **)puStack_98) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_9c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_90 = unaff_s2;
  if (piVar6[0xd] != 0x1180) goto LAB_0048268c;
  puVar17 = *(undefined **)(piVar6[0xf] + 4);
  uVar4 = *(uint *)(*(int *)(piVar6[0x16] + 0x344) + 0xc);
  puVar15 = puVar17 + 4;
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 0xe) == 0) {
      if ((uVar4 & 0xe0) != 0) {
        iVar5 = *(int *)(piVar6[0x30] + 0x98);
        if (iVar5 == 0) {
          ssl3_send_alert();
          uVar14 = 0xf4;
          uVar7 = 0xa65;
          goto LAB_00482d24;
        }
        iVar18 = *(int *)(iVar5 + 0x74);
        if (iVar18 == 0) {
          piVar19 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar5 + 0x48));
          if (((piVar19 == (int *)0x0) || (*piVar19 != 0x198)) || (iVar18 = piVar19[5], iVar18 == 0)
             ) {
            uVar14 = 0x44;
            uVar7 = 0xa90;
            goto LAB_00482f4c;
          }
        }
        else {
          piVar19 = (int *)0x0;
        }
        iVar5 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar18);
        iVar18 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar18);
        if ((iVar5 == 0) || (iVar18 == 0)) {
          uVar14 = 0x44;
          uVar7 = 0xa9c;
LAB_00482f4c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar14,"s3_clnt.c",uVar7);
          goto LAB_00482d3c;
        }
        iVar8 = (*(code *)PTR_EC_KEY_new_006a71a8)();
        if (iVar8 == 0) {
          uVar14 = 0x41;
          uVar7 = 0xaa2;
          goto LAB_00482f4c;
        }
        iVar16 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar8,iVar5);
        if (iVar16 == 0) {
          uVar14 = 0x10;
          uVar7 = 0xaa7;
        }
        else {
          iVar16 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar8);
          if (iVar16 == 0) {
            uVar14 = 0x2b;
            uVar7 = 0xabf;
          }
          else {
            iVar16 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(iVar5);
            if (iVar16 < 1) {
              uVar14 = 0x2b;
              uVar7 = 0xacb;
            }
            else {
              iVar18 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                                 (puVar15,iVar16 + 7 >> 3,iVar18,iVar8,0);
              if (0 < iVar18) {
                iVar16 = piVar6[0x30];
                uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))
                                  (piVar6,iVar16 + 0x14,puVar15,iVar18);
                puVar2 = PTR_memset_006a99f4;
                *(undefined4 *)(iVar16 + 0x10) = uVar7;
                (*(code *)puVar2)(puVar15,0,iVar18);
                uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar8);
                uVar7 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar5,uVar7,4,0,0,0);
                iVar18 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar7,"s3_clnt.c",0xaed);
                iVar9 = (*(code *)PTR_BN_CTX_new_006a794c)();
                if (iVar18 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(iVar9);
                  goto LAB_00482dec;
                }
                if (iVar9 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(0);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar18);
                  goto LAB_00482dec;
                }
                uVar14 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar8);
                iVar5 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)
                                  (iVar5,uVar14,4,iVar18,uVar7,iVar9);
                puVar17[4] = (char)iVar5;
                iVar16 = iVar5 + 1;
                (*(code *)PTR_memcpy_006a9aec)(puVar17 + 5,iVar18,iVar5);
                (*(code *)PTR_BN_CTX_free_006a7954)(iVar9);
                (*(code *)PTR_CRYPTO_free_006a6e88)(iVar18);
                (*(code *)PTR_EC_KEY_free_006a71d4)(iVar8);
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar19);
                goto LAB_00482658;
              }
              uVar14 = 0x2b;
              uVar7 = 0xad1;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar14,"s3_clnt.c",uVar7);
        (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482dec:
        (*(code *)PTR_EC_KEY_free_006a71d4)(iVar8);
        goto LAB_00482d4c;
      }
      if ((uVar4 & 0x200) == 0) {
        if ((uVar4 & 0x400) == 0) {
          if ((uVar4 & 0x100) == 0) goto LAB_004833a8;
          pcVar20 = (code *)piVar6[0x37];
          if (pcVar20 == (code *)0x0) {
            uVar14 = 0xe0;
            uVar7 = 0xbaa;
            goto LAB_00482d24;
          }
          (*(code *)PTR_memset_006a99f4)(auStack_324,0,0x82);
          uVar4 = (*pcVar20)(piVar6,*(undefined4 *)(piVar6[0x30] + 0x8c),auStack_324,0x81,
                             auStack_2a0,0x204);
          if (0x100 < uVar4) {
            uVar14 = 0x44;
            uVar7 = 0xbb5;
LAB_00482ea0:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar14,"s3_clnt.c",uVar7);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_324,0x82);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2a0,0x204);
            ssl3_send_alert(piVar6,2,0x28);
            goto LAB_00482d38;
          }
          if (uVar4 == 0) {
            uVar14 = 0xdf;
            uVar7 = 0xbb9;
            goto LAB_00482ea0;
          }
          uStack_2a3 = 0;
          uVar11 = (*(code *)PTR_strlen_006a9a24)(auStack_324);
          if (0x80 < uVar11) {
            uVar14 = 0x44;
            uVar7 = 0xbc0;
            goto LAB_00482ea0;
          }
          (*(code *)PTR_memmove_006a9af4)(auStack_2a0 + uVar4 + 4,auStack_2a0,uVar4);
          uVar21 = (undefined)(uVar4 >> 8);
          auStack_2a0[0] = uVar21;
          auStack_2a0[1] = (char)uVar4;
          (*(code *)PTR___memset_chk_006a998c)(auStack_2a0 + 2,0,uVar4,0x202);
          iVar5 = piVar6[0x30];
          (auStack_2a0 + 2)[uVar4] = uVar21;
          auStack_2a0[uVar4 + 3] = (char)uVar4;
          if (*(int *)(iVar5 + 0x8c) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar5 = piVar6[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(*(undefined4 *)(piVar6[0x39] + 0x14c));
          iVar18 = piVar6[0x39];
          iVar16 = piVar6[0x30];
          *(undefined4 *)(iVar5 + 0x8c) = uVar7;
          if ((*(int *)(iVar18 + 0x14c) != 0) && (*(int *)(iVar16 + 0x8c) == 0)) {
            uVar14 = 0x41;
            uVar7 = 0xbd3;
            goto LAB_00482ea0;
          }
          if (*(int *)(iVar16 + 0x90) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar16 = piVar6[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(auStack_324);
          iVar5 = piVar6[0x30];
          *(undefined4 *)(iVar16 + 0x90) = uVar7;
          if (*(int *)(iVar5 + 0x90) == 0) {
            uVar14 = 0x41;
            uVar7 = 0xbdc;
            goto LAB_00482ea0;
          }
          iVar16 = uVar11 + 2;
          uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))
                            (piVar6,iVar5 + 0x14,auStack_2a0,uVar4 * 2 + 4);
          *(undefined4 *)(iVar5 + 0x10) = uVar7;
          puVar17[5] = (char)uVar11;
          puVar15 = PTR_memcpy_006a9aec;
          puVar17[4] = 0;
          (*(code *)puVar15)(puVar17 + 6,auStack_324,uVar11);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_324,0x82);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2a0,0x204);
        }
        else {
          if (piVar6[0x6e] == 0) {
            uVar14 = 0x44;
            uVar7 = 0xb83;
            goto LAB_00482d24;
          }
          iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)();
          puVar15 = PTR_BN_bn2bin_006a7200;
          iVar5 = iVar18 + 7;
          if (iVar18 + 7 < 0) {
            iVar5 = iVar18 + 0xe;
          }
          iVar16 = (iVar5 >> 3) + 2;
          puVar17[5] = (char)(iVar5 >> 3);
          puVar17[4] = (char)(iVar5 >> 0xb);
          (*(code *)puVar15)(piVar6[0x6e],puVar17 + 6);
          iVar5 = piVar6[0x30];
          if (*(int *)(iVar5 + 0xf0) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar5 = piVar6[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(piVar6[0x69]);
          iVar18 = piVar6[0x30];
          *(undefined4 *)(iVar5 + 0xf0) = uVar7;
          if (*(int *)(iVar18 + 0xf0) == 0) {
            uVar14 = 0x41;
            uVar7 = 0xb8b;
            goto LAB_00482d24;
          }
          iVar5 = (*(code *)PTR_SRP_generate_client_master_secret_006a808c)(piVar6,iVar18 + 0x14);
          *(int *)(iVar18 + 0x10) = iVar5;
          if (iVar5 < 0) {
            uVar14 = 0x44;
            uVar7 = 0xb94;
            goto LAB_00482d24;
          }
        }
      }
      else {
        if ((*(int *)(*(int *)(piVar6[0x30] + 0x98) + 0x60) == 0) &&
           (*(int *)(*(int *)(piVar6[0x30] + 0x98) + 0x54) == 0)) {
          uVar14 = 0x14a;
          uVar7 = 0xb24;
          goto LAB_00482d24;
        }
        uVar7 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
        iVar5 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(uVar7,0);
        if (iVar5 == 0) {
          uVar14 = 0x41;
          uVar7 = 0xb2c;
          goto LAB_00482d24;
        }
        iVar18 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(iVar5);
        if (iVar18 < 1) {
LAB_00483224:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar5);
          uVar14 = 0x44;
          uVar7 = 0xb3e;
          goto LAB_00482d24;
        }
        iVar18 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_344,0x20);
        if (iVar18 < 1) goto LAB_00483224;
        uVar14 = (*(code *)PTR_EVP_MD_CTX_create_006a8084)();
        uVar10 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x329);
        uVar10 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar10);
        iVar18 = (*(code *)PTR_EVP_DigestInit_006a7e40)(uVar14,uVar10);
        if (((iVar18 < 1) ||
            (iVar18 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar14,piVar6[0x16] + 0xc0,0x20),
            iVar18 < 1)) ||
           (iVar18 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar14,piVar6[0x16] + 0xa0,0x20),
           iVar18 < 1)) {
LAB_004831a8:
          (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar14);
          uVar14 = 0x44;
          uVar7 = 0xb4f;
          goto LAB_00482d24;
        }
        iVar18 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(uVar14,auStack_324,auStack_348);
        if (iVar18 < 1) goto LAB_004831a8;
        (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar14);
        iVar18 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar5,0xffffffff,0x100,8,8,auStack_324);
        puVar15 = PTR_EVP_PKEY_encrypt_006a7d14;
        if (iVar18 < 0) {
          uVar14 = 0x112;
          uVar7 = 0xb57;
          goto LAB_00482d24;
        }
        puVar17[4] = 0x30;
        uStack_34c = 0xff;
        iVar18 = (*(code *)puVar15)(iVar5,auStack_2a0,&uStack_34c,auStack_344,0x20);
        if (iVar18 < 1) {
          uVar14 = 0x112;
          uVar7 = 0xb63;
          goto LAB_00482d24;
        }
        uVar21 = (undefined)uStack_34c;
        if (uStack_34c < 0x80) {
          puVar15 = puVar17 + 6;
          iVar16 = uStack_34c + 2;
        }
        else {
          puVar15 = puVar17 + 7;
          puVar17[6] = uVar21;
          iVar16 = uStack_34c + 3;
          uVar21 = 0x81;
        }
        puVar2 = PTR_memcpy_006a9aec;
        puVar17[5] = uVar21;
        (*(code *)puVar2)(puVar15,auStack_2a0);
        (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar5);
        iVar5 = piVar6[0x30];
        uVar14 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))
                           (piVar6,iVar5 + 0x14,auStack_344,0x20);
        puVar15 = PTR_EVP_PKEY_free_006a6e78;
        *(undefined4 *)(iVar5 + 0x10) = uVar14;
        (*(code *)puVar15)(uVar7);
      }
    }
    else {
      if (*(int *)(piVar6[0x30] + 0x98) == 0) {
        ssl3_send_alert();
        uVar14 = 0xf4;
        uVar7 = 0xa22;
        goto LAB_00482d24;
      }
      iVar5 = *(int *)(*(int *)(piVar6[0x30] + 0x98) + 0x70);
      if (iVar5 == 0) {
        ssl3_send_alert();
        uVar14 = 0xee;
        uVar7 = 0xa2c;
        goto LAB_00482d24;
      }
      iVar18 = (*(code *)PTR_DHparams_dup_006a7f8c)(iVar5);
      if (iVar18 == 0) {
        uVar14 = 5;
        uVar7 = 0xa32;
        goto LAB_00482d24;
      }
      iVar16 = (*(code *)PTR_DH_generate_key_006a7f90)(iVar18);
      if (iVar16 == 0) {
        uVar7 = 0xa36;
LAB_00482f78:
        piVar19 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,5,"s3_clnt.c",uVar7);
        (*(code *)PTR_DH_free_006a7508)(iVar18);
        goto LAB_00482d3c;
      }
      iVar5 = (*(code *)PTR_DH_compute_key_006a7fa4)(puVar15,*(undefined4 *)(iVar5 + 0x14),iVar18);
      if (iVar5 < 1) {
        uVar7 = 0xa43;
        goto LAB_00482f78;
      }
      iVar16 = piVar6[0x30];
      uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))(piVar6,iVar16 + 0x14,puVar15,iVar5);
      puVar2 = PTR_memset_006a99f4;
      *(undefined4 *)(iVar16 + 0x10) = uVar7;
      (*(code *)puVar2)(puVar15,0,iVar5);
      iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar18 + 0x14));
      puVar15 = PTR_BN_bn2bin_006a7200;
      iVar5 = iVar16 + 7;
      if (iVar16 + 7 < 0) {
        iVar5 = iVar16 + 0xe;
      }
      iVar16 = (iVar5 >> 3) + 2;
      puVar17[5] = (char)(iVar5 >> 3);
      puVar17[4] = (char)(iVar5 >> 0xb);
      (*(code *)puVar15)(*(undefined4 *)(iVar18 + 0x14),puVar17 + 6);
      (*(code *)PTR_DH_free_006a7508)(iVar18);
    }
  }
  else {
    iVar5 = *(int *)(piVar6[0x30] + 0x98);
    if (iVar5 == 0) {
      uVar14 = 0x44;
      uVar7 = 0x95b;
      goto LAB_00482d24;
    }
    iVar18 = *(int *)(iVar5 + 0x6c);
    if (iVar18 == 0) {
      piVar19 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar5 + 0xc));
      if (((piVar19 == (int *)0x0) || (*piVar19 != 6)) || (iVar18 = piVar19[5], iVar18 == 0)) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x44,"s3_clnt.c",0x969);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar19);
        goto LAB_00482d38;
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar19);
    }
    auStack_2a0[1] = (undefined)piVar6[0x44];
    auStack_2a0[0] = (undefined)((uint)piVar6[0x44] >> 8);
    iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_2a0 + 2,0x2e);
    puVar2 = PTR_RSA_public_encrypt_006a7654;
    if (iVar5 < 1) goto LAB_00482d38;
    puVar13 = puVar17 + 6;
    if (*piVar6 < 0x301) {
      puVar13 = puVar15;
    }
    *(undefined4 *)(piVar6[0x30] + 0x10) = 0x30;
    iVar5 = (*(code *)puVar2)(0x30,auStack_2a0,puVar13,iVar18,1);
    if (iVar5 < 1) {
      uVar14 = 0x77;
      uVar7 = 0x986;
      goto LAB_00482d24;
    }
    iVar16 = iVar5;
    if (0x300 < *piVar6) {
      puVar17[5] = (char)iVar5;
      iVar16 = iVar5 + 2;
      puVar17[4] = (char)((uint)iVar5 >> 8);
    }
    iVar5 = piVar6[0x30];
    uVar7 = (**(code **)(*(int *)(piVar6[2] + 100) + 0xc))(piVar6,iVar5 + 0x14,auStack_2a0,0x30);
    puVar15 = PTR_OPENSSL_cleanse_006a7074;
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    (*(code *)puVar15)(auStack_2a0,0x30);
  }
LAB_00482658:
  puVar17[3] = (char)iVar16;
  puVar17[2] = (char)((uint)iVar16 >> 8);
  puVar17[1] = (char)((uint)iVar16 >> 0x10);
  *puVar17 = 0x10;
  piVar6[0x11] = iVar16 + 4;
  piVar6[0xd] = 0x1181;
  piVar6[0x12] = 0;
LAB_0048268c:
  uVar4 = ssl3_do_write(piVar6,0x16);
  while (iStack_9c != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004833a8:
    ssl3_send_alert();
    uVar14 = 0x44;
    uVar7 = 0xbf5;
LAB_00482d24:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar14,"s3_clnt.c",uVar7);
LAB_00482d38:
    piVar19 = (int *)0x0;
LAB_00482d3c:
    (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482d4c:
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar19);
    uVar4 = 0xffffffff;
    piVar6[0xd] = 5;
  }
  return uVar4;
}

