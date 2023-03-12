
undefined * ssl3_send_certificate_request(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  byte bVar10;
  uint *puVar11;
  undefined4 uVar12;
  char *pcVar13;
  ushort *puVar14;
  int unaff_s0;
  uint *puVar15;
  int unaff_s1;
  ushort *puVar16;
  undefined *unaff_s2;
  int unaff_s4;
  uint uVar17;
  int iVar18;
  int unaff_s5;
  uint unaff_s6;
  code *pcVar19;
  int unaff_s7;
  undefined **unaff_s8;
  undefined uVar20;
  undefined4 uVar21;
  int iStack_31c;
  undefined4 uStack_318;
  undefined auStack_314 [132];
  undefined auStack_290 [516];
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  undefined *puStack_80;
  int *piStack_7c;
  int iStack_78;
  int iStack_74;
  uint uStack_70;
  int iStack_6c;
  undefined **ppuStack_68;
  code *pcStack_64;
  undefined4 local_50;
  undefined *local_48;
  undefined4 local_3c;
  uint **local_38;
  int local_34;
  undefined *local_30;
  uint *local_2c;
  
  local_38 = (uint **)PTR___stack_chk_guard_006aabf0;
  local_48 = &_gp;
  local_2c = *(uint **)PTR___stack_chk_guard_006aabf0;
  if (param_1[0xd] == 0x2160) {
    unaff_s4 = param_1[0xf];
    unaff_s0 = *(int *)(unaff_s4 + 4);
    local_30 = (undefined *)(unaff_s0 + 5);
    iVar6 = ssl3_get_req_cert_type(param_1,local_30);
    local_34 = iVar6 + 1;
    *(char *)(unaff_s0 + 4) = (char)iVar6;
    local_30 = local_30 + iVar6;
    if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
      iVar6 = tls12_get_req_sig_algs(param_1,local_30 + 2);
      *local_30 = (char)((uint)iVar6 >> 8);
      local_34 = local_34 + iVar6 + 2;
      local_30[1] = (char)iVar6;
      local_30 = local_30 + iVar6 + 4;
    }
    local_30 = local_30 + 2;
    unaff_s6 = 0;
    unaff_s1 = local_34 + 2;
    unaff_s5 = (**(code **)(local_48 + -0x7478))(param_1);
    if (unaff_s5 == 0) {
      uVar20 = 0;
    }
    else {
      unaff_s0 = 0;
      unaff_s8 = &local_30;
      iVar6 = (**(code **)(local_48 + -0x7fb4))(unaff_s5);
      if (0 < iVar6) {
        do {
          unaff_s2 = (undefined *)(unaff_s1 + 4);
          local_3c = (**(code **)(local_48 + -0x7fbc))(unaff_s5,unaff_s0);
          unaff_s7 = (**(code **)(local_48 + -0x7708))(local_3c,0);
          iVar6 = (**(code **)(local_48 + -0x72b4))(unaff_s4,unaff_s2 + unaff_s7 + 2);
          if (iVar6 == 0) {
            local_50 = 0x811;
            (**(code **)(local_48 + -0x6eb0))(0x14,0x96,7,"s3_srvr.c");
            puVar1 = (undefined *)0xffffffff;
            goto LAB_00480004;
          }
          unaff_s2 = unaff_s2 + *(int *)(unaff_s4 + 4);
          if ((param_1[0x40] & 0x20000000U) == 0) {
            pcVar19 = *(code **)(local_48 + -0x7708);
            *unaff_s2 = (char)((uint)unaff_s7 >> 8);
            unaff_s2[1] = (char)unaff_s7;
            local_30 = unaff_s2 + 2;
            (*pcVar19)(local_3c,unaff_s8);
            iVar6 = unaff_s7 + 2;
          }
          else {
            local_30 = unaff_s2;
            (**(code **)(local_48 + -0x7708))(local_3c,unaff_s8);
            unaff_s2[1] = (char)(unaff_s7 + -2);
            *unaff_s2 = (char)((uint)(unaff_s7 + -2) >> 8);
            iVar6 = unaff_s7;
          }
          unaff_s6 = unaff_s6 + iVar6;
          unaff_s1 = unaff_s1 + iVar6;
          unaff_s0 = unaff_s0 + 1;
          iVar6 = (**(code **)(local_48 + -0x7fb4))(unaff_s5);
        } while (unaff_s0 < iVar6);
      }
      uVar20 = (undefined)(unaff_s6 >> 8);
      unaff_s6 = unaff_s6 & 0xff;
    }
    puVar1 = (undefined *)(*(int *)(unaff_s4 + 4) + local_34 + 4);
    *puVar1 = uVar20;
    puVar1[1] = (char)unaff_s6;
    puVar1 = *(undefined **)(unaff_s4 + 4);
    *puVar1 = 0xd;
    puVar1[1] = (char)((uint)unaff_s1 >> 0x10);
    puVar1[2] = (char)((uint)unaff_s1 >> 8);
    puVar1[3] = (char)unaff_s1;
    param_1[0x11] = unaff_s1 + 4;
    param_1[0x12] = 0;
    puVar1 = (undefined *)(*(int *)(param_1[0xf] + 4) + unaff_s1 + 4);
    *puVar1 = 0xe;
    puVar1[1] = 0;
    puVar1[2] = 0;
    local_30 = puVar1 + 4;
    puVar1[3] = 0;
    param_1[0xd] = 0x2161;
    param_1[0x11] = param_1[0x11] + 4;
  }
  puVar1 = (undefined *)ssl3_do_write(param_1,0x16);
LAB_00480004:
  if (local_2c == *local_38) {
    return puVar1;
  }
  pcStack_64 = ssl3_get_client_key_exchange;
  puVar11 = local_2c;
  (**(code **)(local_48 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  piVar4 = &iStack_31c;
  pcVar13 = (char *)0x10;
  iStack_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar21 = 0x800;
  iStack_88 = unaff_s0;
  iStack_84 = unaff_s1;
  puStack_80 = unaff_s2;
  piStack_7c = param_1;
  iStack_78 = unaff_s4;
  iStack_74 = unaff_s5;
  uStack_70 = unaff_s6;
  iStack_6c = unaff_s7;
  ppuStack_68 = unaff_s8;
  puVar2 = (undefined *)(**(code **)(puVar11[2] + 0x30))();
  if (iStack_31c == 0) goto LAB_004804d0;
  uVar3 = puVar11[0x16];
  uVar17 = *(uint *)(*(int *)(uVar3 + 0x344) + 0xc);
  puVar16 = (ushort *)puVar11[0x10];
  if ((uVar17 & 1) == 0) {
    if ((uVar17 & 0xe) == 0) {
      if ((uVar17 & 0xe0) != 0) {
        iVar6 = (*(code *)PTR_EC_KEY_new_006a82a8)();
        if (iVar6 == 0) {
          uVar12 = 0x41;
          uVar21 = 0x9e4;
          goto LAB_00480820;
        }
        if ((uVar17 & 0x60) == 0) {
          uVar21 = *(undefined4 *)(puVar11[0x16] + 0x34c);
        }
        else {
          uVar21 = *(undefined4 *)(*(int *)(puVar11[0x26] + 0x70) + 0x14);
        }
        uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar21);
        uVar21 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(uVar21);
        iVar7 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar6,uVar12);
        if ((iVar7 == 0) ||
           (iVar7 = (*(code *)PTR_EC_KEY_set_private_key_006a913c)(iVar6,uVar21), iVar7 == 0)) {
          pcVar13 = "s3_srvr.c";
          iVar18 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x10,"s3_srvr.c",0x9fd);
          iVar7 = 0;
          piVar4 = (int *)0x0;
        }
        else {
          iVar7 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar12);
          if (iVar7 == 0) {
            pcVar13 = "s3_srvr.c";
            iVar18 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x41,"s3_srvr.c",0xa05);
            piVar4 = (int *)0x0;
          }
          else {
            if (puVar2 == (undefined *)0x0) {
              if ((uVar17 & 0x80) == 0) {
                piVar4 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                          (*(undefined4 *)(puVar11[0x30] + 0x9c));
                if ((piVar4 != (int *)0x0) && (*piVar4 == 0x198)) {
                  uVar21 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(piVar4[5]);
                  iVar18 = (*(code *)PTR_EC_POINT_copy_006a9144)(iVar7,uVar21);
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
              ssl3_send_alert(puVar11,2,0x28);
              iVar18 = 0;
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
              (*(code *)PTR_EC_POINT_free_006a9134)(iVar7);
              goto LAB_00480ee0;
            }
            iVar18 = (*(code *)PTR_BN_CTX_new_006a8a38)();
            if (iVar18 == 0) {
              uVar12 = 0x41;
              uVar21 = 0xa39;
            }
            else if (puVar2 == (undefined *)(*(byte *)puVar16 + 1)) {
              iVar9 = (*(code *)PTR_EC_POINT_oct2point_006a9148)
                                (uVar12,iVar7,(byte *)((int)puVar16 + 1),(uint)*(byte *)puVar16,
                                 iVar18);
              if (iVar9 != 0) {
                puVar2 = (undefined *)0x1;
                piVar4 = (int *)0x0;
                puVar16 = *(ushort **)(puVar11[0xf] + 4);
LAB_00480af0:
                iVar9 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(uVar12);
                if (iVar9 < 1) {
                  uVar21 = 0xa58;
                }
                else {
                  pcVar8 = (char *)(*(code *)PTR_ECDH_compute_key_006a8bd4)
                                             (puVar16,iVar9 + 7 >> 3,iVar7,iVar6,0);
                  if (0 < (int)pcVar8) {
                    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
                    (*(code *)PTR_EC_POINT_free_006a9134)(iVar7);
                    (*(code *)PTR_EC_KEY_free_006a82d8)(iVar6);
                    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar18);
                    (*(code *)PTR_EC_KEY_free_006a82d8)(*(undefined4 *)(puVar11[0x16] + 0x34c));
                    uVar3 = puVar11[0x30];
                    iVar6 = *(int *)(puVar11[2] + 100);
                    *(undefined4 *)(puVar11[0x16] + 0x34c) = 0;
                    pcVar13 = pcVar8;
                    uVar21 = (**(code **)(iVar6 + 0xc))(puVar11,uVar3 + 0x14,puVar16,pcVar8);
                    puVar5 = PTR_OPENSSL_cleanse_006a8174;
                    *(undefined4 *)(uVar3 + 0x10) = uVar21;
                    (*(code *)puVar5)(puVar16,pcVar8);
                    goto LAB_004804d0;
                  }
                  uVar21 = 0xa5f;
                }
                pcVar13 = "s3_srvr.c";
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x2b,"s3_srvr.c",uVar21);
                goto LAB_00480ec0;
              }
              uVar12 = 0x10;
              uVar21 = 0xa4a;
            }
            else {
              uVar12 = 0x10;
              uVar21 = 0xa43;
            }
            pcVar13 = "s3_srvr.c";
            piVar4 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar21);
          }
        }
LAB_00480ec0:
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
        (*(code *)PTR_EC_POINT_free_006a9134)(iVar7);
LAB_00480ee0:
        (*(code *)PTR_EC_KEY_free_006a82d8)(iVar6);
        goto LAB_00480700;
      }
      if ((uVar17 & 0x100) != 0) {
        uVar3 = (uint)*puVar16;
        if (puVar2 == (undefined *)(uVar3 + 2)) {
          if (uVar3 < 0x81) {
            pcVar19 = (code *)puVar11[0x38];
            if (pcVar19 != (code *)0x0) {
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_314,puVar16 + 1,uVar3,0x81,uVar21);
              puVar5 = auStack_290;
              (*(code *)PTR_memset_006aab00)(auStack_314 + uVar3,0,0x81 - uVar3);
              uVar3 = (*pcVar19)(puVar11,auStack_314,puVar5,0x204);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_314,0x81);
              if (0x100 < uVar3) {
                uVar12 = 0x44;
                pcVar13 = "s3_srvr.c";
                uVar21 = 0xa9d;
                goto LAB_00480f70;
              }
              if (uVar3 != 0) {
                (*(code *)PTR_memmove_006aabfc)(puVar5 + uVar3 + 4,puVar5,uVar3);
                uVar20 = (undefined)(uVar3 >> 8);
                auStack_290[0] = uVar20;
                auStack_290[1] = (char)uVar3;
                (*(code *)PTR___memset_chk_006aaa98)(auStack_290 + 2,0,uVar3,0x202);
                uVar17 = puVar11[0x30];
                (auStack_290 + 2)[uVar3] = uVar20;
                auStack_290[uVar3 + 3] = (char)uVar3;
                pcVar13 = (char *)(uVar3 * 2 + 4);
                if (*(int *)(uVar17 + 0x90) != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                  uVar17 = puVar11[0x30];
                }
                uVar21 = (*(code *)PTR_BUF_strdup_006a80dc)(puVar16 + 1);
                uVar3 = puVar11[0x30];
                *(undefined4 *)(uVar17 + 0x90) = uVar21;
                pcVar8 = "s\n";
                if (*(int *)(uVar3 + 0x90) == 0) goto LAB_00481188;
                if (*(int *)(uVar3 + 0x8c) != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                  uVar3 = puVar11[0x30];
                }
                uVar21 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(puVar11[0x39] + 0x14c));
                uVar17 = puVar11[0x39];
                *(undefined4 *)(uVar3 + 0x8c) = uVar21;
                uVar3 = puVar11[0x30];
                if ((*(int *)(uVar17 + 0x14c) != 0) && (*(int *)(uVar3 + 0x8c) == 0)) {
                  uVar12 = 0x41;
                  pcVar13 = "s3_srvr.c";
                  uVar21 = 0xac3;
                  goto LAB_00480f70;
                }
                uVar21 = (**(code **)(*(int *)(puVar11[2] + 100) + 0xc))
                                   (puVar11,uVar3 + 0x14,puVar5,pcVar13);
                *(undefined4 *)(uVar3 + 0x10) = uVar21;
                puVar2 = (undefined *)0x1;
                (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar5,0x204);
                goto LAB_004804d0;
              }
              pcVar13 = "s3_srvr.c";
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0xdf,"s3_srvr.c",0xaa4);
              uVar21 = 0x73;
              goto LAB_004806ac;
            }
            uVar12 = 0xe1;
            uVar21 = 0xa8e;
          }
          else {
            uVar12 = 0x92;
            uVar21 = 0xa88;
          }
        }
        else {
          uVar12 = 0x9f;
          uVar21 = 0xa82;
        }
        pcVar13 = "s3_srvr.c";
        puVar5 = auStack_290;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar21);
        uVar21 = 0x28;
        goto LAB_004806ac;
      }
      if ((uVar17 & 0x400) != 0) {
        if ((int)(*puVar16 + 2) <= (int)puVar2) {
          uVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar16 + 1,(uint)*puVar16,0);
          puVar11[0x6e] = uVar3;
          if (uVar3 == 0) {
            uVar12 = 3;
            uVar21 = 0xae1;
          }
          else {
            uVar3 = puVar11[0x30];
            if (*(int *)(uVar3 + 0xf0) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              uVar3 = puVar11[0x30];
            }
            uVar21 = (*(code *)PTR_BUF_strdup_006a80dc)(puVar11[0x69]);
            uVar17 = puVar11[0x30];
            *(undefined4 *)(uVar3 + 0xf0) = uVar21;
            if (*(int *)(uVar17 + 0xf0) == 0) {
              uVar12 = 0x41;
              uVar21 = 0xaea;
            }
            else {
              puVar2 = (undefined *)0x1;
              iVar6 = (*(code *)PTR_SRP_generate_server_master_secret_006a9138)
                                (puVar11,uVar17 + 0x14);
              *(int *)(uVar17 + 0x10) = iVar6;
              if (-1 < iVar6) goto LAB_004804d0;
              uVar12 = 0x44;
              uVar21 = 0xaf0;
            }
          }
          goto LAB_00480820;
        }
        pcVar13 = "s3_srvr.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,0x15b,"s3_srvr.c",0xadc,piVar4);
        uVar21 = 0x32;
        goto LAB_004806c8;
      }
      if ((uVar17 & 0x200) != 0) {
        uVar3 = *(uint *)(*(int *)(uVar3 + 0x344) + 0x10);
        uStack_318 = 0x20;
        if ((uVar3 & 0x100) == 0) {
          if ((uVar3 & 0x200) == 0) {
            uVar21 = 0;
          }
          else {
            uVar21 = *(undefined4 *)(puVar11[0x26] + 0x88);
          }
        }
        else {
          uVar21 = *(undefined4 *)(puVar11[0x26] + 0x7c);
        }
        uVar21 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(uVar21,0);
        (*(code *)PTR_EVP_PKEY_decrypt_init_006a8dd4)(uVar21);
        iVar6 = (*(code *)PTR_X509_get_pubkey_006a8008)(*(undefined4 *)(puVar11[0x30] + 0x9c));
        if ((iVar6 != 0) &&
           (iVar7 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(uVar21,iVar6), iVar7 < 1)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        if (*(byte *)puVar16 == 0x30) {
          bVar10 = *(byte *)((int)puVar16 + 1);
          if (bVar10 == 0x81) {
            puVar14 = (ushort *)((int)puVar16 + 3);
            bVar10 = *(byte *)(puVar16 + 1);
          }
          else {
            if ((char)bVar10 < '\0') {
              uVar12 = 0xb26;
              goto LAB_004808e0;
            }
            puVar14 = puVar16 + 1;
          }
          iVar7 = (*(code *)PTR_EVP_PKEY_decrypt_006a8dfc)
                            (uVar21,auStack_290,&uStack_318,puVar14,bVar10);
          if (0 < iVar7) {
            uVar3 = puVar11[0x30];
            uVar12 = (**(code **)(*(int *)(puVar11[2] + 100) + 0xc))
                               (puVar11,uVar3 + 0x14,auStack_290,0x20);
            pcVar13 = (char *)0x2;
            *(undefined4 *)(uVar3 + 0x10) = uVar12;
            puVar2 = (undefined *)0x1;
            iVar7 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(uVar21,0xffffffff,0xffffffff,2,2,0);
            if (0 < iVar7) {
              puVar2 = &SUB_00000002;
            }
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar6);
            (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(uVar21);
            puVar11 = (uint *)&SUB_00000002;
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
        (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(uVar21);
        goto LAB_004806e4;
      }
      uVar12 = 0xf9;
      uVar21 = 0xb44;
    }
    else {
      puVar5 = (undefined *)(uint)*puVar16;
      if (puVar2 == puVar5 + 2) {
        puVar16 = puVar16 + 1;
      }
      else {
        if ((puVar11[0x40] & 0x80) == 0) {
          uVar12 = 0x94;
          uVar21 = 0x8de;
          goto LAB_00480820;
        }
        puVar5 = puVar2;
        if (puVar2 == (undefined *)0x0) {
          uVar12 = 0xec;
          uVar21 = 0x8eb;
          goto LAB_00480634;
        }
      }
      iVar6 = *(int *)(uVar3 + 0x348);
      if (iVar6 != 0) {
        iVar7 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar16,puVar5,0);
        if (iVar7 != 0) {
          pcVar8 = (char *)(*(code *)PTR_DH_compute_key_006a912c)(puVar16,iVar7,iVar6);
          if (0 < (int)pcVar8) {
            (*(code *)PTR_DH_free_006a8604)(*(undefined4 *)(puVar11[0x16] + 0x348));
            puVar5 = PTR_BN_clear_free_006a9130;
            puVar2 = (undefined *)0x1;
            *(undefined4 *)(puVar11[0x16] + 0x348) = 0;
            (*(code *)puVar5)(iVar7);
            puVar15 = (uint *)puVar11[0x30];
            pcVar13 = pcVar8;
            uVar3 = (**(code **)(*(int *)(puVar11[2] + 100) + 0xc))
                              (puVar11,puVar15 + 5,puVar16,pcVar8);
            puVar5 = PTR_OPENSSL_cleanse_006a8174;
            puVar15[4] = uVar3;
            (*(code *)puVar5)(puVar16,pcVar8);
            puVar11 = puVar15;
            goto LAB_004804d0;
          }
          pcVar13 = "s3_srvr.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,5,"s3_srvr.c",0x905);
          (*(code *)PTR_BN_clear_free_006a9130)(iVar7);
          goto LAB_004806e4;
        }
        uVar12 = 0x82;
        uVar21 = 0x8fd;
        goto LAB_00480820;
      }
      uVar12 = 0xab;
      uVar21 = 0x8f3;
    }
  }
  else if (*(int *)(uVar3 + 0x370) == 0) {
    piVar4 = *(int **)(puVar11[0x26] + 0x34);
    if (((piVar4 != (int *)0x0) && (*piVar4 == 6)) &&
       (pcVar13 = (char *)piVar4[5], pcVar13 != (char *)0x0)) {
LAB_004803ec:
      puVar5 = puVar2;
      if (0x300 < (int)*puVar11) {
        puVar5 = (undefined *)(uint)*puVar16;
        if (puVar2 == puVar5 + 2) {
          puVar16 = puVar16 + 1;
        }
        else {
          puVar5 = puVar2;
          if ((puVar11[0x40] & 0x100) == 0) {
            uVar12 = 0xea;
            uVar21 = 0x894;
LAB_00480820:
            pcVar13 = "s3_srvr.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar21);
            goto LAB_004806e4;
          }
        }
      }
      iVar6 = (*(code *)PTR_RSA_private_decrypt_006a8734)(puVar5,puVar16,puVar16,pcVar13,1);
      if (iVar6 == 0x30) {
        if (((uint)*(byte *)puVar16 == (int)puVar11[0x44] >> 8) &&
           ((uint)*(byte *)((int)puVar16 + 1) == (puVar11[0x44] & 0xff))) {
          uVar3 = puVar11[2];
          goto LAB_00480490;
        }
        if (((int)(puVar11[0x40] << 8) < 0) &&
           (((uint)*(byte *)puVar16 == (int)*puVar11 >> 8 &&
            ((uint)*(byte *)((int)puVar16 + 1) == (*puVar11 & 0xff))))) {
          uVar3 = puVar11[2];
          goto LAB_00480490;
        }
      }
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      puVar2 = PTR_RAND_pseudo_bytes_006a8664;
      *(byte *)puVar16 = (byte)(puVar11[0x44] >> 8);
      *(byte *)((int)puVar16 + 1) = (byte)puVar11[0x44];
      iVar6 = (*(code *)puVar2)(puVar16 + 1,0x2e);
      if (iVar6 < 1) goto LAB_004806e4;
      uVar3 = puVar11[2];
LAB_00480490:
      pcVar13 = (char *)0x30;
      uVar17 = puVar11[0x30];
      uVar21 = (**(code **)(*(int *)(uVar3 + 100) + 0xc))(puVar11,uVar17 + 0x14,puVar16,0x30);
      *(undefined4 *)(uVar17 + 0x10) = uVar21;
      puVar2 = (undefined *)0x1;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar16,0x30);
      goto LAB_004804d0;
    }
    uVar12 = 0xa8;
    uVar21 = 0x886;
  }
  else {
    if ((puVar11[0x26] != 0) && (pcVar13 = *(char **)(puVar11[0x26] + 0x18), pcVar13 != (char *)0x0)
       ) goto LAB_004803ec;
    uVar12 = 0xad;
    uVar21 = 0x879;
  }
LAB_00480634:
  pcVar13 = "s3_srvr.c";
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,"s3_srvr.c",uVar21);
  uVar21 = 0x28;
LAB_004806c8:
  while( true ) {
    ssl3_send_alert(puVar11,2,uVar21);
LAB_004806e4:
    iVar18 = 0;
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(0);
    (*(code *)PTR_EC_POINT_free_006a9134)(0);
LAB_00480700:
    puVar2 = (undefined *)0xffffffff;
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar18);
LAB_004804d0:
    if (iStack_8c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    pcVar8 = pcVar13;
    puVar5 = puVar2;
LAB_00481188:
    uVar12 = 0x41;
    pcVar13 = pcVar8 + 0x6930;
    uVar21 = 0xab8;
LAB_00480f70:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8b,uVar12,pcVar13,uVar21);
    uVar21 = 0x28;
LAB_004806ac:
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar5,0x204);
  }
  return puVar2;
}

