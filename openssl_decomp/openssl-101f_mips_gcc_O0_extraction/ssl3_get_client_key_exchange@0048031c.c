
undefined * ssl3_get_client_key_exchange(uint *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  byte bVar11;
  undefined4 uVar12;
  char *pcVar13;
  ushort *puVar14;
  uint *puVar15;
  ushort *puVar16;
  uint uVar17;
  int iVar18;
  code *pcVar19;
  undefined uVar20;
  int local_2bc;
  undefined4 local_2b8;
  undefined auStack_2b4 [132];
  undefined local_230 [516];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcVar13 = (char *)0x10;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar2 = (undefined *)
           (**(code **)(param_1[2] + 0x30))(param_1,0x2190,0x2191,0x10,0x800,&local_2bc);
  if (local_2bc == 0) goto LAB_004804d0;
  uVar3 = param_1[0x16];
  uVar17 = *(uint *)(*(int *)(uVar3 + 0x344) + 0xc);
  puVar16 = (ushort *)param_1[0x10];
  if ((uVar17 & 1) == 0) {
    if ((uVar17 & 0xe) == 0) {
      if ((uVar17 & 0xe0) != 0) {
        iVar6 = (*(code *)PTR_EC_KEY_new_006a82a8)();
        if (iVar6 == 0) {
          uVar12 = 0x41;
          uVar7 = 0x9e4;
          goto LAB_00480820;
        }
        if ((uVar17 & 0x60) == 0) {
          uVar7 = *(undefined4 *)(param_1[0x16] + 0x34c);
        }
        else {
          uVar7 = *(undefined4 *)(*(int *)(param_1[0x26] + 0x70) + 0x14);
        }
        uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar7);
        uVar7 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(uVar7);
        iVar8 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar6,uVar12);
        if ((iVar8 == 0) ||
           (iVar8 = (*(code *)PTR_EC_KEY_set_private_key_006a913c)(iVar6,uVar7), iVar8 == 0)) {
          pcVar13 = "s3_srvr.c";
          iVar18 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x10,"s3_srvr.c",0x9fd);
          iVar8 = 0;
          piVar4 = (int *)0x0;
        }
        else {
          iVar8 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar12);
          if (iVar8 == 0) {
            pcVar13 = "s3_srvr.c";
            iVar18 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x41,"s3_srvr.c",0xa05);
            piVar4 = (int *)0x0;
          }
          else {
            if (puVar2 == (undefined *)0x0) {
              if ((uVar17 & 0x80) == 0) {
                piVar4 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                          (*(undefined4 *)(param_1[0x30] + 0x9c));
                if ((piVar4 != (int *)0x0) && (*piVar4 == 0x198)) {
                  uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(piVar4[5]);
                  iVar18 = (*(code *)PTR_EC_POINT_copy_006a9144)(iVar8,uVar7);
                  if (iVar18 != 0) {
                    puVar2 = &SUB_00000002;
                    iVar18 = 0;
                    goto LAB_00480af0;
                  }
                  pcVar13 = "s3_srvr.c";
                  iVar18 = 0;
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x10,"s3_srvr.c",0xa2c);
                  goto LAB_00480ec0;
                }
                pcVar13 = "s3_srvr.c";
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x139,"s3_srvr.c",0xa24);
              }
              else {
                pcVar13 = "s3_srvr.c";
                piVar4 = (int *)0x0;
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x137,"s3_srvr.c",0xa10);
              }
              ssl3_send_alert(param_1,2,0x28);
              iVar18 = 0;
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
              (*(code *)PTR_EC_POINT_free_006a9134)(iVar8);
              goto LAB_00480ee0;
            }
            iVar18 = (*(code *)PTR_BN_CTX_new_006a8a38)();
            if (iVar18 == 0) {
              uVar12 = 0x41;
              uVar7 = 0xa39;
            }
            else if (puVar2 == (undefined *)(*(byte *)puVar16 + 1)) {
              iVar10 = (*(code *)PTR_EC_POINT_oct2point_006a9148)
                                 (uVar12,iVar8,(byte *)((int)puVar16 + 1),(uint)*(byte *)puVar16,
                                  iVar18);
              if (iVar10 != 0) {
                puVar2 = (undefined *)0x1;
                piVar4 = (int *)0x0;
                puVar16 = *(ushort **)(param_1[0xf] + 4);
LAB_00480af0:
                iVar10 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(uVar12);
                if (iVar10 < 1) {
                  uVar7 = 0xa58;
                }
                else {
                  pcVar9 = (char *)(*(code *)PTR_ECDH_compute_key_006a8bd4)
                                             (puVar16,iVar10 + 7 >> 3,iVar8,iVar6,0);
                  if (0 < (int)pcVar9) {
                    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
                    (*(code *)PTR_EC_POINT_free_006a9134)(iVar8);
                    (*(code *)PTR_EC_KEY_free_006a82d8)(iVar6);
                    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar18);
                    (*(code *)PTR_EC_KEY_free_006a82d8)(*(undefined4 *)(param_1[0x16] + 0x34c));
                    uVar3 = param_1[0x30];
                    iVar6 = *(int *)(param_1[2] + 100);
                    *(undefined4 *)(param_1[0x16] + 0x34c) = 0;
                    pcVar13 = pcVar9;
                    uVar7 = (**(code **)(iVar6 + 0xc))(param_1,uVar3 + 0x14,puVar16,pcVar9);
                    puVar5 = PTR_OPENSSL_cleanse_006a8174;
                    *(undefined4 *)(uVar3 + 0x10) = uVar7;
                    (*(code *)puVar5)(puVar16,pcVar9);
                    goto LAB_004804d0;
                  }
                  uVar7 = 0xa5f;
                }
                pcVar13 = "s3_srvr.c";
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x2b,"s3_srvr.c",uVar7);
                goto LAB_00480ec0;
              }
              uVar12 = 0x10;
              uVar7 = 0xa4a;
            }
            else {
              uVar12 = 0x10;
              uVar7 = 0xa43;
            }
            pcVar13 = "s3_srvr.c";
            piVar4 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar7);
          }
        }
LAB_00480ec0:
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
        (*(code *)PTR_EC_POINT_free_006a9134)(iVar8);
LAB_00480ee0:
        (*(code *)PTR_EC_KEY_free_006a82d8)(iVar6);
        goto LAB_00480700;
      }
      if ((uVar17 & 0x100) != 0) {
        uVar3 = (uint)*puVar16;
        if (puVar2 == (undefined *)(uVar3 + 2)) {
          if (uVar3 < 0x81) {
            pcVar19 = (code *)param_1[0x38];
            if (pcVar19 != (code *)0x0) {
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_2b4,puVar16 + 1,uVar3,0x81);
              puVar5 = local_230;
              (*(code *)PTR_memset_006aab00)(auStack_2b4 + uVar3,0,0x81 - uVar3);
              uVar3 = (*pcVar19)(param_1,auStack_2b4,puVar5,0x204);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_2b4,0x81);
              if (0x100 < uVar3) {
                uVar12 = 0x44;
                pcVar13 = "s3_srvr.c";
                uVar7 = 0xa9d;
                goto LAB_00480f70;
              }
              if (uVar3 != 0) {
                (*(code *)PTR_memmove_006aabfc)(puVar5 + uVar3 + 4,puVar5,uVar3);
                uVar20 = (undefined)(uVar3 >> 8);
                local_230[0] = uVar20;
                local_230[1] = (char)uVar3;
                (*(code *)PTR___memset_chk_006aaa98)(local_230 + 2,0,uVar3,0x202);
                uVar17 = param_1[0x30];
                (local_230 + 2)[uVar3] = uVar20;
                local_230[uVar3 + 3] = (char)uVar3;
                pcVar13 = (char *)(uVar3 * 2 + 4);
                if (*(int *)(uVar17 + 0x90) != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                  uVar17 = param_1[0x30];
                }
                uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(puVar16 + 1);
                uVar3 = param_1[0x30];
                *(undefined4 *)(uVar17 + 0x90) = uVar7;
                pcVar9 = "s\n";
                if (*(int *)(uVar3 + 0x90) == 0) goto LAB_00481188;
                if (*(int *)(uVar3 + 0x8c) != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                  uVar3 = param_1[0x30];
                }
                uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(param_1[0x39] + 0x14c));
                uVar17 = param_1[0x39];
                *(undefined4 *)(uVar3 + 0x8c) = uVar7;
                uVar3 = param_1[0x30];
                if ((*(int *)(uVar17 + 0x14c) != 0) && (*(int *)(uVar3 + 0x8c) == 0)) {
                  uVar12 = 0x41;
                  pcVar13 = "s3_srvr.c";
                  uVar7 = 0xac3;
                  goto LAB_00480f70;
                }
                uVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,uVar3 + 0x14,puVar5,pcVar13);
                *(undefined4 *)(uVar3 + 0x10) = uVar7;
                puVar2 = (undefined *)0x1;
                (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar5,0x204);
                goto LAB_004804d0;
              }
              pcVar13 = "s3_srvr.c";
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0xdf,"s3_srvr.c",0xaa4);
              uVar7 = 0x73;
              goto LAB_004806ac;
            }
            uVar12 = 0xe1;
            uVar7 = 0xa8e;
          }
          else {
            uVar12 = 0x92;
            uVar7 = 0xa88;
          }
        }
        else {
          uVar12 = 0x9f;
          uVar7 = 0xa82;
        }
        pcVar13 = "s3_srvr.c";
        puVar5 = local_230;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar7);
        uVar7 = 0x28;
        goto LAB_004806ac;
      }
      if ((uVar17 & 0x400) != 0) {
        if ((int)(*puVar16 + 2) <= (int)puVar2) {
          uVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar16 + 1,(uint)*puVar16,0);
          param_1[0x6e] = uVar3;
          if (uVar3 == 0) {
            uVar12 = 3;
            uVar7 = 0xae1;
          }
          else {
            uVar3 = param_1[0x30];
            if (*(int *)(uVar3 + 0xf0) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              uVar3 = param_1[0x30];
            }
            uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)(param_1[0x69]);
            uVar17 = param_1[0x30];
            *(undefined4 *)(uVar3 + 0xf0) = uVar7;
            if (*(int *)(uVar17 + 0xf0) == 0) {
              uVar12 = 0x41;
              uVar7 = 0xaea;
            }
            else {
              puVar2 = (undefined *)0x1;
              iVar6 = (*(code *)PTR_SRP_generate_server_master_secret_006a9138)
                                (param_1,uVar17 + 0x14);
              *(int *)(uVar17 + 0x10) = iVar6;
              if (-1 < iVar6) goto LAB_004804d0;
              uVar12 = 0x44;
              uVar7 = 0xaf0;
            }
          }
          goto LAB_00480820;
        }
        pcVar13 = "s3_srvr.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x15b,"s3_srvr.c",0xadc);
        uVar7 = 0x32;
        goto LAB_004806c8;
      }
      if ((uVar17 & 0x200) != 0) {
        uVar3 = *(uint *)(*(int *)(uVar3 + 0x344) + 0x10);
        local_2b8 = 0x20;
        if ((uVar3 & 0x100) == 0) {
          if ((uVar3 & 0x200) == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined4 *)(param_1[0x26] + 0x88);
          }
        }
        else {
          uVar7 = *(undefined4 *)(param_1[0x26] + 0x7c);
        }
        uVar7 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(uVar7,0);
        (*(code *)PTR_EVP_PKEY_decrypt_init_006a8dd4)(uVar7);
        iVar6 = (*(code *)PTR_X509_get_pubkey_006a8008)(*(undefined4 *)(param_1[0x30] + 0x9c));
        if ((iVar6 != 0) &&
           (iVar8 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(uVar7,iVar6), iVar8 < 1)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        if (*(byte *)puVar16 == 0x30) {
          bVar11 = *(byte *)((int)puVar16 + 1);
          if (bVar11 == 0x81) {
            puVar14 = (ushort *)((int)puVar16 + 3);
            bVar11 = *(byte *)(puVar16 + 1);
          }
          else {
            if ((char)bVar11 < '\0') {
              uVar12 = 0xb26;
              goto LAB_004808e0;
            }
            puVar14 = puVar16 + 1;
          }
          iVar8 = (*(code *)PTR_EVP_PKEY_decrypt_006a8dfc)
                            (uVar7,local_230,&local_2b8,puVar14,bVar11);
          if (0 < iVar8) {
            uVar3 = param_1[0x30];
            uVar12 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                               (param_1,uVar3 + 0x14,local_230,0x20);
            pcVar13 = (char *)0x2;
            *(undefined4 *)(uVar3 + 0x10) = uVar12;
            puVar2 = (undefined *)0x1;
            iVar8 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(uVar7,0xffffffff,0xffffffff,2,2,0);
            if (0 < iVar8) {
              puVar2 = &SUB_00000002;
            }
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar6);
            (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(uVar7);
            param_1 = (uint *)&SUB_00000002;
            goto LAB_004804d0;
          }
          uVar12 = 0xb2c;
        }
        else {
          uVar12 = 0xb17;
        }
LAB_004808e0:
        pcVar13 = "s3_srvr.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x93,"s3_srvr.c",uVar12);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar6);
        (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(uVar7);
        goto LAB_004806e4;
      }
      uVar12 = 0xf9;
      uVar7 = 0xb44;
    }
    else {
      puVar5 = (undefined *)(uint)*puVar16;
      if (puVar2 == puVar5 + 2) {
        puVar16 = puVar16 + 1;
      }
      else {
        if ((param_1[0x40] & 0x80) == 0) {
          uVar12 = 0x94;
          uVar7 = 0x8de;
          goto LAB_00480820;
        }
        puVar5 = puVar2;
        if (puVar2 == (undefined *)0x0) {
          uVar12 = 0xec;
          uVar7 = 0x8eb;
          goto LAB_00480634;
        }
      }
      iVar6 = *(int *)(uVar3 + 0x348);
      if (iVar6 != 0) {
        iVar8 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar16,puVar5,0);
        if (iVar8 != 0) {
          pcVar9 = (char *)(*(code *)PTR_DH_compute_key_006a912c)(puVar16,iVar8,iVar6);
          if (0 < (int)pcVar9) {
            (*(code *)PTR_DH_free_006a8604)(*(undefined4 *)(param_1[0x16] + 0x348));
            puVar5 = PTR_BN_clear_free_006a9130;
            puVar2 = (undefined *)0x1;
            *(undefined4 *)(param_1[0x16] + 0x348) = 0;
            (*(code *)puVar5)(iVar8);
            puVar15 = (uint *)param_1[0x30];
            pcVar13 = pcVar9;
            uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                              (param_1,puVar15 + 5,puVar16,pcVar9);
            puVar5 = PTR_OPENSSL_cleanse_006a8174;
            puVar15[4] = uVar3;
            (*(code *)puVar5)(puVar16,pcVar9);
            param_1 = puVar15;
            goto LAB_004804d0;
          }
          pcVar13 = "s3_srvr.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,5,"s3_srvr.c",0x905);
          (*(code *)PTR_BN_clear_free_006a9130)(iVar8);
          goto LAB_004806e4;
        }
        uVar12 = 0x82;
        uVar7 = 0x8fd;
        goto LAB_00480820;
      }
      uVar12 = 0xab;
      uVar7 = 0x8f3;
    }
  }
  else if (*(int *)(uVar3 + 0x370) == 0) {
    piVar4 = *(int **)(param_1[0x26] + 0x34);
    if (((piVar4 != (int *)0x0) && (*piVar4 == 6)) &&
       (pcVar13 = (char *)piVar4[5], pcVar13 != (char *)0x0)) {
LAB_004803ec:
      puVar5 = puVar2;
      if (0x300 < (int)*param_1) {
        puVar5 = (undefined *)(uint)*puVar16;
        if (puVar2 == puVar5 + 2) {
          puVar16 = puVar16 + 1;
        }
        else {
          puVar5 = puVar2;
          if ((param_1[0x40] & 0x100) == 0) {
            uVar12 = 0xea;
            uVar7 = 0x894;
LAB_00480820:
            pcVar13 = "s3_srvr.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar7);
            goto LAB_004806e4;
          }
        }
      }
      iVar6 = (*(code *)PTR_RSA_private_decrypt_006a8734)(puVar5,puVar16,puVar16,pcVar13,1);
      if (iVar6 == 0x30) {
        if (((uint)*(byte *)puVar16 == (int)param_1[0x44] >> 8) &&
           ((uint)*(byte *)((int)puVar16 + 1) == (param_1[0x44] & 0xff))) {
          uVar3 = param_1[2];
          goto LAB_00480490;
        }
        if (((int)(param_1[0x40] << 8) < 0) &&
           (((uint)*(byte *)puVar16 == (int)*param_1 >> 8 &&
            ((uint)*(byte *)((int)puVar16 + 1) == (*param_1 & 0xff))))) {
          uVar3 = param_1[2];
          goto LAB_00480490;
        }
      }
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      puVar2 = PTR_RAND_pseudo_bytes_006a8664;
      *(byte *)puVar16 = (byte)(param_1[0x44] >> 8);
      *(byte *)((int)puVar16 + 1) = (byte)param_1[0x44];
      iVar6 = (*(code *)puVar2)(puVar16 + 1,0x2e);
      if (iVar6 < 1) goto LAB_004806e4;
      uVar3 = param_1[2];
LAB_00480490:
      pcVar13 = (char *)0x30;
      uVar17 = param_1[0x30];
      uVar7 = (**(code **)(*(int *)(uVar3 + 100) + 0xc))(param_1,uVar17 + 0x14,puVar16,0x30);
      *(undefined4 *)(uVar17 + 0x10) = uVar7;
      puVar2 = (undefined *)0x1;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar16,0x30);
      goto LAB_004804d0;
    }
    uVar12 = 0xa8;
    uVar7 = 0x886;
  }
  else {
    if ((param_1[0x26] != 0) && (pcVar13 = *(char **)(param_1[0x26] + 0x18), pcVar13 != (char *)0x0)
       ) goto LAB_004803ec;
    uVar12 = 0xad;
    uVar7 = 0x879;
  }
LAB_00480634:
  pcVar13 = "s3_srvr.c";
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar7);
  uVar7 = 0x28;
LAB_004806c8:
  while( true ) {
    ssl3_send_alert(param_1,2,uVar7);
LAB_004806e4:
    iVar18 = 0;
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(0);
    (*(code *)PTR_EC_POINT_free_006a9134)(0);
LAB_00480700:
    puVar2 = (undefined *)0xffffffff;
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar18);
LAB_004804d0:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    pcVar9 = pcVar13;
    puVar5 = puVar2;
LAB_00481188:
    uVar12 = 0x41;
    pcVar13 = pcVar9 + 0x6930;
    uVar7 = 0xab8;
LAB_00480f70:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,pcVar13,uVar7);
    uVar7 = 0x28;
LAB_004806ac:
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar5,0x204);
  }
  return puVar2;
}

