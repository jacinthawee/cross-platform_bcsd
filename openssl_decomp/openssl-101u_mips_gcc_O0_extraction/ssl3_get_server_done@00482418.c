
int ssl3_get_server_done(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined *puVar12;
  undefined4 uVar13;
  undefined *puVar14;
  int iVar15;
  code *pcVar16;
  undefined *puVar17;
  int iVar18;
  int *piVar19;
  undefined uVar20;
  uint uStack_314;
  undefined auStack_310 [4];
  undefined auStack_30c [32];
  undefined auStack_2ec [129];
  undefined uStack_26b;
  undefined auStack_268 [516];
  int iStack_64;
  undefined *puStack_60;
  int iStack_5c;
  int local_18;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  piVar4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x1160,0x1161,0xe);
  if ((local_18 != 0) && (bVar1 = 0 < iVar5, iVar5 = 1, bVar1)) {
    ssl3_send_alert(param_1,2,0x32);
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x91,0x9f,"s3_clnt.c");
    iVar5 = -1;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
  if (piVar4 == *(int **)puStack_60) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_5c = param_1;
  if (piVar4[0xd] != 0x1180) goto LAB_0048268c;
  puVar17 = *(undefined **)(piVar4[0xf] + 4);
  uVar6 = *(uint *)(*(int *)(piVar4[0x16] + 0x344) + 0xc);
  puVar14 = puVar17 + 4;
  if ((uVar6 & 1) == 0) {
    if ((uVar6 & 0xe) == 0) {
      if ((uVar6 & 0xe0) != 0) {
        iVar5 = *(int *)(piVar4[0x30] + 0x98);
        if (iVar5 == 0) {
          ssl3_send_alert();
          uVar13 = 0xf4;
          uVar7 = 0xa65;
          goto LAB_00482d24;
        }
        iVar18 = *(int *)(iVar5 + 0x74);
        if (iVar18 == 0) {
          piVar19 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar5 + 0x48));
          if (((piVar19 == (int *)0x0) || (*piVar19 != 0x198)) || (iVar18 = piVar19[5], iVar18 == 0)
             ) {
            uVar13 = 0x44;
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
          uVar13 = 0x44;
          uVar7 = 0xa9c;
LAB_00482f4c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar13,"s3_clnt.c",uVar7);
          goto LAB_00482d3c;
        }
        iVar8 = (*(code *)PTR_EC_KEY_new_006a71a8)();
        if (iVar8 == 0) {
          uVar13 = 0x41;
          uVar7 = 0xaa2;
          goto LAB_00482f4c;
        }
        iVar15 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar8,iVar5);
        if (iVar15 == 0) {
          uVar13 = 0x10;
          uVar7 = 0xaa7;
        }
        else {
          iVar15 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar8);
          if (iVar15 == 0) {
            uVar13 = 0x2b;
            uVar7 = 0xabf;
          }
          else {
            iVar15 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(iVar5);
            if (iVar15 < 1) {
              uVar13 = 0x2b;
              uVar7 = 0xacb;
            }
            else {
              iVar18 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                                 (puVar14,iVar15 + 7 >> 3,iVar18,iVar8,0);
              if (0 < iVar18) {
                iVar15 = piVar4[0x30];
                uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))
                                  (piVar4,iVar15 + 0x14,puVar14,iVar18);
                puVar2 = PTR_memset_006a99f4;
                *(undefined4 *)(iVar15 + 0x10) = uVar7;
                (*(code *)puVar2)(puVar14,0,iVar18);
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
                uVar13 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar8);
                iVar5 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)
                                  (iVar5,uVar13,4,iVar18,uVar7,iVar9);
                puVar17[4] = (char)iVar5;
                iVar15 = iVar5 + 1;
                (*(code *)PTR_memcpy_006a9aec)(puVar17 + 5,iVar18,iVar5);
                (*(code *)PTR_BN_CTX_free_006a7954)(iVar9);
                (*(code *)PTR_CRYPTO_free_006a6e88)(iVar18);
                (*(code *)PTR_EC_KEY_free_006a71d4)(iVar8);
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar19);
                goto LAB_00482658;
              }
              uVar13 = 0x2b;
              uVar7 = 0xad1;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar13,"s3_clnt.c",uVar7);
        (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482dec:
        (*(code *)PTR_EC_KEY_free_006a71d4)(iVar8);
        goto LAB_00482d4c;
      }
      if ((uVar6 & 0x200) == 0) {
        if ((uVar6 & 0x400) == 0) {
          if ((uVar6 & 0x100) == 0) goto LAB_004833a8;
          pcVar16 = (code *)piVar4[0x37];
          if (pcVar16 == (code *)0x0) {
            uVar13 = 0xe0;
            uVar7 = 0xbaa;
            goto LAB_00482d24;
          }
          (*(code *)PTR_memset_006a99f4)(auStack_2ec,0,0x82);
          uVar6 = (*pcVar16)(piVar4,*(undefined4 *)(piVar4[0x30] + 0x8c),auStack_2ec,0x81,
                             auStack_268,0x204);
          if (0x100 < uVar6) {
            uVar13 = 0x44;
            uVar7 = 0xbb5;
LAB_00482ea0:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar13,"s3_clnt.c",uVar7);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2ec,0x82);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_268,0x204);
            ssl3_send_alert(piVar4,2,0x28);
            goto LAB_00482d38;
          }
          if (uVar6 == 0) {
            uVar13 = 0xdf;
            uVar7 = 0xbb9;
            goto LAB_00482ea0;
          }
          uStack_26b = 0;
          uVar11 = (*(code *)PTR_strlen_006a9a24)(auStack_2ec);
          if (0x80 < uVar11) {
            uVar13 = 0x44;
            uVar7 = 0xbc0;
            goto LAB_00482ea0;
          }
          (*(code *)PTR_memmove_006a9af4)(auStack_268 + uVar6 + 4,auStack_268,uVar6);
          uVar20 = (undefined)(uVar6 >> 8);
          auStack_268[0] = uVar20;
          auStack_268[1] = (char)uVar6;
          (*(code *)PTR___memset_chk_006a998c)(auStack_268 + 2,0,uVar6,0x202);
          iVar5 = piVar4[0x30];
          (auStack_268 + 2)[uVar6] = uVar20;
          auStack_268[uVar6 + 3] = (char)uVar6;
          if (*(int *)(iVar5 + 0x8c) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar5 = piVar4[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(*(undefined4 *)(piVar4[0x39] + 0x14c));
          iVar18 = piVar4[0x39];
          iVar15 = piVar4[0x30];
          *(undefined4 *)(iVar5 + 0x8c) = uVar7;
          if ((*(int *)(iVar18 + 0x14c) != 0) && (*(int *)(iVar15 + 0x8c) == 0)) {
            uVar13 = 0x41;
            uVar7 = 0xbd3;
            goto LAB_00482ea0;
          }
          if (*(int *)(iVar15 + 0x90) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar15 = piVar4[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(auStack_2ec);
          iVar5 = piVar4[0x30];
          *(undefined4 *)(iVar15 + 0x90) = uVar7;
          if (*(int *)(iVar5 + 0x90) == 0) {
            uVar13 = 0x41;
            uVar7 = 0xbdc;
            goto LAB_00482ea0;
          }
          iVar15 = uVar11 + 2;
          uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))
                            (piVar4,iVar5 + 0x14,auStack_268,uVar6 * 2 + 4);
          *(undefined4 *)(iVar5 + 0x10) = uVar7;
          puVar17[5] = (char)uVar11;
          puVar14 = PTR_memcpy_006a9aec;
          puVar17[4] = 0;
          (*(code *)puVar14)(puVar17 + 6,auStack_2ec,uVar11);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2ec,0x82);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_268,0x204);
        }
        else {
          if (piVar4[0x6e] == 0) {
            uVar13 = 0x44;
            uVar7 = 0xb83;
            goto LAB_00482d24;
          }
          iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)();
          puVar14 = PTR_BN_bn2bin_006a7200;
          iVar5 = iVar18 + 7;
          if (iVar18 + 7 < 0) {
            iVar5 = iVar18 + 0xe;
          }
          iVar15 = (iVar5 >> 3) + 2;
          puVar17[5] = (char)(iVar5 >> 3);
          puVar17[4] = (char)(iVar5 >> 0xb);
          (*(code *)puVar14)(piVar4[0x6e],puVar17 + 6);
          iVar5 = piVar4[0x30];
          if (*(int *)(iVar5 + 0xf0) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar5 = piVar4[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(piVar4[0x69]);
          iVar18 = piVar4[0x30];
          *(undefined4 *)(iVar5 + 0xf0) = uVar7;
          if (*(int *)(iVar18 + 0xf0) == 0) {
            uVar13 = 0x41;
            uVar7 = 0xb8b;
            goto LAB_00482d24;
          }
          iVar5 = (*(code *)PTR_SRP_generate_client_master_secret_006a808c)(piVar4,iVar18 + 0x14);
          *(int *)(iVar18 + 0x10) = iVar5;
          if (iVar5 < 0) {
            uVar13 = 0x44;
            uVar7 = 0xb94;
            goto LAB_00482d24;
          }
        }
      }
      else {
        if ((*(int *)(*(int *)(piVar4[0x30] + 0x98) + 0x60) == 0) &&
           (*(int *)(*(int *)(piVar4[0x30] + 0x98) + 0x54) == 0)) {
          uVar13 = 0x14a;
          uVar7 = 0xb24;
          goto LAB_00482d24;
        }
        uVar7 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
        iVar5 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(uVar7,0);
        if (iVar5 == 0) {
          uVar13 = 0x41;
          uVar7 = 0xb2c;
          goto LAB_00482d24;
        }
        iVar18 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(iVar5);
        if (iVar18 < 1) {
LAB_00483224:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar5);
          uVar13 = 0x44;
          uVar7 = 0xb3e;
          goto LAB_00482d24;
        }
        iVar18 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_30c,0x20);
        if (iVar18 < 1) goto LAB_00483224;
        uVar13 = (*(code *)PTR_EVP_MD_CTX_create_006a8084)();
        uVar10 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x329);
        uVar10 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar10);
        iVar18 = (*(code *)PTR_EVP_DigestInit_006a7e40)(uVar13,uVar10);
        if (((iVar18 < 1) ||
            (iVar18 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar13,piVar4[0x16] + 0xc0,0x20),
            iVar18 < 1)) ||
           (iVar18 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar13,piVar4[0x16] + 0xa0,0x20),
           iVar18 < 1)) {
LAB_004831a8:
          (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar13);
          uVar13 = 0x44;
          uVar7 = 0xb4f;
          goto LAB_00482d24;
        }
        iVar18 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(uVar13,auStack_2ec,auStack_310);
        if (iVar18 < 1) goto LAB_004831a8;
        (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar13);
        iVar18 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar5,0xffffffff,0x100,8,8,auStack_2ec);
        puVar14 = PTR_EVP_PKEY_encrypt_006a7d14;
        if (iVar18 < 0) {
          uVar13 = 0x112;
          uVar7 = 0xb57;
          goto LAB_00482d24;
        }
        puVar17[4] = 0x30;
        uStack_314 = 0xff;
        iVar18 = (*(code *)puVar14)(iVar5,auStack_268,&uStack_314,auStack_30c,0x20);
        if (iVar18 < 1) {
          uVar13 = 0x112;
          uVar7 = 0xb63;
          goto LAB_00482d24;
        }
        uVar20 = (undefined)uStack_314;
        if (uStack_314 < 0x80) {
          puVar14 = puVar17 + 6;
          iVar15 = uStack_314 + 2;
        }
        else {
          puVar14 = puVar17 + 7;
          puVar17[6] = uVar20;
          iVar15 = uStack_314 + 3;
          uVar20 = 0x81;
        }
        puVar2 = PTR_memcpy_006a9aec;
        puVar17[5] = uVar20;
        (*(code *)puVar2)(puVar14,auStack_268);
        (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar5);
        iVar5 = piVar4[0x30];
        uVar13 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))
                           (piVar4,iVar5 + 0x14,auStack_30c,0x20);
        puVar14 = PTR_EVP_PKEY_free_006a6e78;
        *(undefined4 *)(iVar5 + 0x10) = uVar13;
        (*(code *)puVar14)(uVar7);
      }
    }
    else {
      if (*(int *)(piVar4[0x30] + 0x98) == 0) {
        ssl3_send_alert();
        uVar13 = 0xf4;
        uVar7 = 0xa22;
        goto LAB_00482d24;
      }
      iVar5 = *(int *)(*(int *)(piVar4[0x30] + 0x98) + 0x70);
      if (iVar5 == 0) {
        ssl3_send_alert();
        uVar13 = 0xee;
        uVar7 = 0xa2c;
        goto LAB_00482d24;
      }
      iVar18 = (*(code *)PTR_DHparams_dup_006a7f8c)(iVar5);
      if (iVar18 == 0) {
        uVar13 = 5;
        uVar7 = 0xa32;
        goto LAB_00482d24;
      }
      iVar15 = (*(code *)PTR_DH_generate_key_006a7f90)(iVar18);
      if (iVar15 == 0) {
        uVar7 = 0xa36;
LAB_00482f78:
        piVar19 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,5,"s3_clnt.c",uVar7);
        (*(code *)PTR_DH_free_006a7508)(iVar18);
        goto LAB_00482d3c;
      }
      iVar5 = (*(code *)PTR_DH_compute_key_006a7fa4)(puVar14,*(undefined4 *)(iVar5 + 0x14),iVar18);
      if (iVar5 < 1) {
        uVar7 = 0xa43;
        goto LAB_00482f78;
      }
      iVar15 = piVar4[0x30];
      uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))(piVar4,iVar15 + 0x14,puVar14,iVar5);
      puVar2 = PTR_memset_006a99f4;
      *(undefined4 *)(iVar15 + 0x10) = uVar7;
      (*(code *)puVar2)(puVar14,0,iVar5);
      iVar15 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar18 + 0x14));
      puVar14 = PTR_BN_bn2bin_006a7200;
      iVar5 = iVar15 + 7;
      if (iVar15 + 7 < 0) {
        iVar5 = iVar15 + 0xe;
      }
      iVar15 = (iVar5 >> 3) + 2;
      puVar17[5] = (char)(iVar5 >> 3);
      puVar17[4] = (char)(iVar5 >> 0xb);
      (*(code *)puVar14)(*(undefined4 *)(iVar18 + 0x14),puVar17 + 6);
      (*(code *)PTR_DH_free_006a7508)(iVar18);
    }
  }
  else {
    iVar5 = *(int *)(piVar4[0x30] + 0x98);
    if (iVar5 == 0) {
      uVar13 = 0x44;
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
    auStack_268[1] = (undefined)piVar4[0x44];
    auStack_268[0] = (undefined)((uint)piVar4[0x44] >> 8);
    iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_268 + 2,0x2e);
    puVar2 = PTR_RSA_public_encrypt_006a7654;
    if (iVar5 < 1) goto LAB_00482d38;
    puVar12 = puVar17 + 6;
    if (*piVar4 < 0x301) {
      puVar12 = puVar14;
    }
    *(undefined4 *)(piVar4[0x30] + 0x10) = 0x30;
    iVar5 = (*(code *)puVar2)(0x30,auStack_268,puVar12,iVar18,1);
    if (iVar5 < 1) {
      uVar13 = 0x77;
      uVar7 = 0x986;
      goto LAB_00482d24;
    }
    iVar15 = iVar5;
    if (0x300 < *piVar4) {
      puVar17[5] = (char)iVar5;
      iVar15 = iVar5 + 2;
      puVar17[4] = (char)((uint)iVar5 >> 8);
    }
    iVar5 = piVar4[0x30];
    uVar7 = (**(code **)(*(int *)(piVar4[2] + 100) + 0xc))(piVar4,iVar5 + 0x14,auStack_268,0x30);
    puVar14 = PTR_OPENSSL_cleanse_006a7074;
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    (*(code *)puVar14)(auStack_268,0x30);
  }
LAB_00482658:
  puVar17[3] = (char)iVar15;
  puVar17[2] = (char)((uint)iVar15 >> 8);
  puVar17[1] = (char)((uint)iVar15 >> 0x10);
  *puVar17 = 0x10;
  piVar4[0x11] = iVar15 + 4;
  piVar4[0xd] = 0x1181;
  piVar4[0x12] = 0;
LAB_0048268c:
  iVar5 = ssl3_do_write(piVar4,0x16);
  while (iStack_64 != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004833a8:
    ssl3_send_alert();
    uVar13 = 0x44;
    uVar7 = 0xbf5;
LAB_00482d24:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar13,"s3_clnt.c",uVar7);
LAB_00482d38:
    piVar19 = (int *)0x0;
LAB_00482d3c:
    (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482d4c:
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar19);
    iVar5 = -1;
    piVar4[0xd] = 5;
  }
  return iVar5;
}

