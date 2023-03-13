
uint ssl3_get_client_key_exchange(uint *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  byte *pbVar11;
  byte *pbVar12;
  ushort *puVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  code *pcVar17;
  int iVar18;
  byte bVar19;
  int local_2cc;
  ushort *local_2c8;
  undefined4 local_2c4;
  int local_2c0;
  int local_2bc;
  undefined4 local_2b8;
  undefined auStack_2b4 [132];
  byte local_230 [516];
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (**(code **)(param_1[2] + 0x30))(param_1,0x2190,0x2191,0x10,0x800,&local_2cc);
  if (local_2cc == 0) goto LAB_0047ba44;
  uVar9 = param_1[0x16];
  local_2c8 = (ushort *)param_1[0x10];
  uVar15 = *(uint *)(*(int *)(uVar9 + 0x344) + 0xc);
  if ((uVar15 & 1) == 0) {
    if ((uVar15 & 0xe) != 0) {
      puVar13 = local_2c8 + 1;
      uVar15 = (uint)*local_2c8;
      if (uVar5 != uVar15 + 2) {
        if ((param_1[0x40] & 0x80) == 0) {
          uVar14 = 0x94;
          uVar7 = 0x938;
          local_2c8 = puVar13;
          goto LAB_0047be78;
        }
        puVar13 = local_2c8;
        uVar15 = uVar5;
        if (uVar5 == 0) {
          uVar14 = 0xec;
          uVar7 = 0x943;
          goto LAB_0047bb94;
        }
      }
      iVar18 = *(int *)(uVar9 + 0x348);
      local_2c8 = puVar13;
      if (iVar18 != 0) {
        iVar6 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar13,uVar15,0);
        if (iVar6 == 0) {
          uVar14 = 0x82;
          uVar7 = 0x951;
          goto LAB_0047be78;
        }
        iVar18 = (*(code *)PTR_DH_compute_key_006a7fa4)(local_2c8,iVar6,iVar18);
        if (0 < iVar18) {
          (*(code *)PTR_DH_free_006a7508)(*(undefined4 *)(param_1[0x16] + 0x348));
          puVar3 = PTR_BN_clear_free_006a7fa8;
          *(undefined4 *)(param_1[0x16] + 0x348) = 0;
          (*(code *)puVar3)(iVar6);
          uVar9 = param_1[0x30];
          uVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,uVar9 + 0x14,local_2c8,iVar18);
          goto LAB_0047ba2c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,5,"s3_srvr.c",0x958);
        (*(code *)PTR_BN_clear_free_006a7fa8)(iVar6);
        goto LAB_0047bc4c;
      }
      uVar14 = 0xab;
      uVar7 = 0x949;
      goto LAB_0047bb94;
    }
    if ((uVar15 & 0xe0) != 0) {
      iVar18 = (*(code *)PTR_EC_KEY_new_006a71a8)();
      if (iVar18 == 0) {
        uVar14 = 0x41;
        uVar7 = 0xa32;
        goto LAB_0047be78;
      }
      if ((uVar15 & 0x60) == 0) {
        uVar7 = *(undefined4 *)(param_1[0x16] + 0x34c);
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)(param_1[0x26] + 0x70) + 0x14);
      }
      uVar14 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar7);
      uVar7 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(uVar7);
      iVar6 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar18,uVar14);
      if ((iVar6 == 0) ||
         (iVar6 = (*(code *)PTR_EC_KEY_set_private_key_006a7fbc)(iVar18,uVar7), iVar6 == 0)) {
        iVar16 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x10,"s3_srvr.c",0xa47);
        iVar6 = 0;
        piVar10 = (int *)0x0;
      }
      else {
        iVar6 = (*(code *)PTR_EC_POINT_new_006a7fc0)(uVar14);
        if (iVar6 == 0) {
          iVar16 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x41,"s3_srvr.c",0xa4d);
          piVar10 = (int *)0x0;
        }
        else {
          if (uVar5 == 0) {
            if ((uVar15 & 0x80) == 0) {
              piVar10 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                         (*(undefined4 *)(param_1[0x30] + 0x9c));
              if ((piVar10 != (int *)0x0) && (*piVar10 == 0x198)) {
                uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(piVar10[5]);
                iVar16 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(iVar6,uVar7);
                if (iVar16 != 0) {
                  uVar5 = 2;
                  iVar16 = 0;
                  goto LAB_0047c060;
                }
                iVar16 = 0;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x10,"s3_srvr.c",0xa6d);
                goto LAB_0047c30c;
              }
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x139,"s3_srvr.c",0xa66);
            }
            else {
              piVar10 = (int *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x137,"s3_srvr.c",0xa57);
            }
            ssl3_send_alert(param_1,2,0x28);
            iVar16 = 0;
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar10);
            (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
            goto LAB_0047c2c4;
          }
          iVar16 = (*(code *)PTR_BN_CTX_new_006a794c)();
          if (iVar16 == 0) {
            uVar14 = 0x41;
            uVar7 = 0xa78;
          }
          else {
            puVar13 = (ushort *)((int)local_2c8 + 1);
            bVar19 = *(byte *)local_2c8;
            local_2c8 = puVar13;
            if (uVar5 == bVar19 + 1) {
              iVar8 = (*(code *)PTR_EC_POINT_oct2point_006a7fc8)
                                (uVar14,iVar6,puVar13,(uint)bVar19,iVar16);
              if (iVar8 != 0) {
                uVar5 = 1;
                piVar10 = (int *)0x0;
                local_2c8 = *(ushort **)(param_1[0xf] + 4);
LAB_0047c060:
                iVar8 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(uVar14);
                if (iVar8 < 1) {
                  uVar7 = 0xa91;
                }
                else {
                  iVar8 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                                    (local_2c8,iVar8 + 7 >> 3,iVar6,iVar18,0);
                  if (0 < iVar8) {
                    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar10);
                    (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
                    (*(code *)PTR_EC_KEY_free_006a71d4)(iVar18);
                    (*(code *)PTR_BN_CTX_free_006a7954)(iVar16);
                    (*(code *)PTR_EC_KEY_free_006a71d4)(*(undefined4 *)(param_1[0x16] + 0x34c));
                    uVar9 = param_1[0x30];
                    iVar18 = *(int *)(param_1[2] + 100);
                    *(undefined4 *)(param_1[0x16] + 0x34c) = 0;
                    uVar7 = (**(code **)(iVar18 + 0xc))(param_1,uVar9 + 0x14,local_2c8,iVar8);
                    puVar3 = PTR_OPENSSL_cleanse_006a7074;
                    *(undefined4 *)(uVar9 + 0x10) = uVar7;
                    (*(code *)puVar3)(local_2c8,iVar8);
                    goto LAB_0047ba44;
                  }
                  uVar7 = 0xa97;
                }
                (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x2b,"s3_srvr.c",uVar7);
                goto LAB_0047c30c;
              }
              uVar14 = 0x10;
              uVar7 = 0xa84;
            }
            else {
              uVar14 = 0x10;
              uVar7 = 0xa80;
            }
          }
          piVar10 = (int *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar14,"s3_srvr.c",uVar7);
        }
      }
LAB_0047c30c:
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar10);
      (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
LAB_0047c2c4:
      (*(code *)PTR_EC_KEY_free_006a71d4)(iVar18);
      goto LAB_0047bc68;
    }
    if ((uVar15 & 0x100) == 0) {
      if ((uVar15 & 0x400) == 0) {
        if ((uVar15 & 0x200) == 0) {
          uVar14 = 0xf9;
          uVar7 = 0xb7b;
          goto LAB_0047bb94;
        }
        uVar9 = *(uint *)(*(int *)(uVar9 + 0x344) + 0x10);
        local_2c4 = 0x20;
        if ((uVar9 & 0x100) == 0) {
          if ((uVar9 & 0x200) == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined4 *)(param_1[0x26] + 0x88);
          }
        }
        else {
          uVar7 = *(undefined4 *)(param_1[0x26] + 0x7c);
        }
        iVar18 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(uVar7,0);
        if (iVar18 != 0) {
          iVar6 = (*(code *)PTR_EVP_PKEY_decrypt_init_006a7ce4)(iVar18);
          if (iVar6 < 1) {
            iVar6 = 0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x44,"s3_srvr.c",0xb46);
          }
          else {
            iVar6 = (*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(param_1[0x30] + 0x9c));
            if ((iVar6 != 0) &&
               (iVar16 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a7cf0)(iVar18,iVar6), iVar16 < 1)
               ) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            iVar16 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                               (&local_2c8,&local_2b8,&local_2c0,&local_2bc,uVar5);
            if (((iVar16 == 0x20) && (local_2c0 == 0x10)) && (local_2bc == 0)) {
              iVar16 = (*(code *)PTR_EVP_PKEY_decrypt_006a7d0c)
                                 (iVar18,local_230,&local_2c4,local_2c8,local_2b8);
              if (0 < iVar16) {
                uVar5 = param_1[0x30];
                uVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,uVar5 + 0x14,local_230,0x20);
                *(undefined4 *)(uVar5 + 0x10) = uVar7;
                uVar5 = 1;
                (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_230,0x20);
                iVar16 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)
                                   (iVar18,0xffffffff,0xffffffff,2,2,0);
                if (0 < iVar16) {
                  uVar5 = 2;
                }
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar6);
                (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar18);
                param_1 = (uint *)&SUB_00000002;
                goto LAB_0047ba44;
              }
              uVar7 = 0xb62;
            }
            else {
              uVar7 = 0xb5a;
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x93,"s3_srvr.c",uVar7);
          }
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar6);
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar18);
          goto LAB_0047bc4c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x41,"s3_srvr.c",0xb42);
        uVar7 = 0x50;
      }
      else {
        puVar13 = local_2c8 + 1;
        uVar2 = *local_2c8;
        if ((int)uVar5 < (int)(uVar2 + 2)) {
          uVar14 = 0x15b;
          uVar7 = 0xb0e;
          goto LAB_0047c654;
        }
        local_2c8 = puVar13;
        uVar5 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar13,(uint)uVar2,0);
        param_1[0x6e] = uVar5;
        if (uVar5 == 0) {
          uVar14 = 3;
          uVar7 = 0xb12;
          goto LAB_0047be78;
        }
        iVar18 = (*(code *)PTR_BN_ucmp_006a7fb4)(uVar5,param_1[0x6a]);
        if ((iVar18 < 0) && (*(int *)(param_1[0x6e] + 4) != 0)) {
          uVar5 = param_1[0x30];
          if (*(int *)(uVar5 + 0xf0) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            uVar5 = param_1[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_1[0x69]);
          uVar9 = param_1[0x30];
          *(undefined4 *)(uVar5 + 0xf0) = uVar7;
          if (*(int *)(uVar9 + 0xf0) == 0) goto LAB_0047c7c0;
          uVar5 = 1;
          iVar18 = (*(code *)PTR_SRP_generate_server_master_secret_006a7fb8)(param_1,uVar9 + 0x14);
          *(int *)(uVar9 + 0x10) = iVar18;
          if (-1 < iVar18) goto LAB_0047ba44;
          uVar14 = 0x44;
          uVar7 = 0xb27;
          goto LAB_0047be78;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x173,"s3_srvr.c",0xb19);
        uVar7 = 0x2f;
      }
      goto LAB_0047bc30;
    }
    puVar13 = local_2c8 + 1;
    uVar9 = (uint)*local_2c8;
    local_2c8 = puVar13;
    if (uVar5 == uVar9 + 2) {
      if (0x80 < uVar9) {
        uVar14 = 0x92;
        uVar7 = 0xabe;
        goto LAB_0047bbf8;
      }
      pcVar17 = (code *)param_1[0x38];
      if (pcVar17 == (code *)0x0) {
        uVar14 = 0xe1;
        uVar7 = 0xac3;
        goto LAB_0047bbf8;
      }
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_2b4,puVar13,uVar9,0x81);
      (*(code *)PTR_memset_006a99f4)(auStack_2b4 + uVar9,0,0x81 - uVar9);
      uVar5 = (*pcVar17)(param_1,auStack_2b4,local_230,0x204);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_2b4,0x81);
      if (uVar5 < 0x101) {
        if (uVar5 != 0) {
          (*(code *)PTR_memmove_006a9af4)(local_230 + uVar5 + 4,local_230,uVar5);
          bVar19 = (byte)(uVar5 >> 8);
          local_230[0] = bVar19;
          local_230[1] = (byte)uVar5;
          (*(code *)PTR___memset_chk_006a998c)(local_230 + 2,0,uVar5,0x202);
          uVar15 = param_1[0x30];
          (local_230 + 2)[uVar5] = bVar19;
          local_230[uVar5 + 3] = (byte)uVar5;
          if (*(int *)(uVar15 + 0x90) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            uVar15 = param_1[0x30];
          }
          uVar7 = (*(code *)PTR_BUF_strndup_006a7fcc)(local_2c8,uVar9);
          uVar9 = param_1[0x30];
          *(undefined4 *)(uVar15 + 0x90) = uVar7;
          if (*(int *)(uVar9 + 0x90) == 0) {
            uVar14 = 0x41;
            uVar7 = 0xaeb;
          }
          else {
            if (*(int *)(uVar9 + 0x8c) != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
              uVar9 = param_1[0x30];
            }
            uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)(*(undefined4 *)(param_1[0x39] + 0x14c));
            uVar15 = param_1[0x39];
            *(undefined4 *)(uVar9 + 0x8c) = uVar7;
            uVar9 = param_1[0x30];
            if ((*(int *)(uVar15 + 0x14c) == 0) || (*(int *)(uVar9 + 0x8c) != 0)) {
              uVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,uVar9 + 0x14,local_230,uVar5 * 2 + 4);
              *(undefined4 *)(uVar9 + 0x10) = uVar7;
              uVar5 = 1;
              (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_230,0x204);
              goto LAB_0047ba44;
            }
            uVar14 = 0x41;
            uVar7 = 0xaf4;
          }
          goto LAB_0047c47c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0xdf,"s3_srvr.c",0xad9);
        uVar7 = 0x73;
      }
      else {
        uVar14 = 0x44;
        uVar7 = 0xad2;
LAB_0047c47c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar14,"s3_srvr.c",uVar7);
        uVar7 = 0x28;
      }
    }
    else {
      uVar14 = 0x9f;
      uVar7 = 0xab9;
LAB_0047bbf8:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar14,"s3_srvr.c",uVar7);
      uVar7 = 0x28;
    }
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_230,0x204);
  }
  else {
    if (*(int *)(uVar9 + 0x370) == 0) {
      piVar10 = *(int **)(param_1[0x26] + 0x34);
      if (((piVar10 != (int *)0x0) && (*piVar10 == 6)) && (iVar18 = piVar10[5], iVar18 != 0)) {
LAB_0047b888:
        uVar9 = uVar5;
        puVar13 = local_2c8;
        if ((((int)*param_1 < 0x301) ||
            (uVar9 = (uint)*local_2c8, puVar13 = local_2c8 + 1, uVar5 == *local_2c8 + 2)) ||
           (uVar9 = uVar5, puVar13 = local_2c8, (param_1[0x40] & 0x100) != 0)) {
          local_2c8 = puVar13;
          if (0x2f < (int)uVar9) {
            pbVar11 = local_230;
            iVar6 = (*(code *)PTR_RAND_bytes_006a7574)(pbVar11,0x30);
            if (0 < iVar6) {
              uVar5 = (*(code *)PTR_RSA_private_decrypt_006a7644)
                                (uVar9,local_2c8,local_2c8,iVar18,1);
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
              uVar9 = param_1[0x44];
              bVar19 = ~(byte)((int)uVar9 >> 0x1f) &
                       (byte)(((int)uVar9 >> 8 ^ (uint)*(byte *)local_2c8) - 1 >> 0x18) &
                       (byte)((uVar9 & 0xff ^ (uint)*(byte *)((int)local_2c8 + 1)) - 1 >> 0x18);
              if ((int)(param_1[0x40] << 8) < 0) {
                uVar9 = *param_1;
                bVar19 = bVar19 | ~(byte)((int)uVar9 >> 0x1f) &
                                  (byte)(((int)uVar9 >> 8 ^ (uint)*(byte *)local_2c8) - 1 >> 0x18) &
                                  (byte)((uVar9 & 0xff ^ (uint)*(byte *)((int)local_2c8 + 1)) - 1 >>
                                        0x18);
              }
              iVar18 = 0;
              do {
                pbVar12 = (byte *)((int)local_2c8 + iVar18);
                bVar1 = *pbVar11;
                iVar18 = iVar18 + 1;
                pbVar11 = pbVar11 + 1;
                *pbVar12 = bVar1 ^ (char)(bVar19 & ~(byte)(uVar5 >> 0x18) &
                                                   (byte)((uVar5 ^ 0x30) - 1 >> 0x18)) >> 7 &
                                   (bVar1 ^ *pbVar12);
              } while (iVar18 != 0x30);
              uVar9 = param_1[0x30];
              uVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,uVar9 + 0x14,local_2c8,0x30);
              iVar18 = 0x30;
LAB_0047ba2c:
              puVar3 = PTR_OPENSSL_cleanse_006a7074;
              uVar5 = 1;
              *(undefined4 *)(uVar9 + 0x10) = uVar7;
              (*(code *)puVar3)(local_2c8,iVar18);
              goto LAB_0047ba44;
            }
            goto LAB_0047bc4c;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0xea,"s3_srvr.c",0x8de);
          uVar7 = 0x33;
        }
        else {
          uVar14 = 0xea;
          uVar7 = 0x8cc;
LAB_0047c654:
          local_2c8 = local_2c8 + 1;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar14,"s3_srvr.c",uVar7);
          uVar7 = 0x32;
        }
        goto LAB_0047bc30;
      }
      uVar14 = 0xa8;
      uVar7 = 0x8bf;
    }
    else {
      if ((param_1[0x26] != 0) && (iVar18 = *(int *)(param_1[0x26] + 0x18), iVar18 != 0))
      goto LAB_0047b888;
      uVar14 = 0xad;
      uVar7 = 0x8b5;
    }
LAB_0047bb94:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar14,"s3_srvr.c",uVar7);
    uVar7 = 0x28;
  }
LAB_0047bc30:
  ssl3_send_alert(param_1,2,uVar7);
LAB_0047bc4c:
  while( true ) {
    iVar16 = 0;
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(0);
    (*(code *)PTR_EC_POINT_free_006a7fac)(0);
LAB_0047bc68:
    uVar5 = 0xffffffff;
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar16);
    param_1[0xd] = 5;
LAB_0047ba44:
    if (local_2c == *(int *)puVar4) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0047c7c0:
    uVar14 = 0x41;
    uVar7 = 0xb20;
LAB_0047be78:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar14,"s3_srvr.c",uVar7);
  }
  return uVar5;
}

