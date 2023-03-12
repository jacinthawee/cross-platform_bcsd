
uint ssl3_send_certificate_request(int *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  undefined uVar12;
  uint *puVar10;
  byte *pbVar11;
  byte *pbVar13;
  ushort *puVar14;
  undefined4 uVar15;
  int unaff_s0;
  int unaff_s1;
  uint uVar16;
  int iVar17;
  undefined *unaff_s2;
  code *pcVar18;
  int unaff_s4;
  int iVar19;
  int unaff_s5;
  uint unaff_s6;
  int unaff_s7;
  undefined **unaff_s8;
  byte bVar20;
  undefined4 uVar21;
  int iStack_32c;
  ushort *puStack_328;
  undefined4 uStack_324;
  int iStack_320;
  int iStack_31c;
  undefined4 uStack_318;
  undefined auStack_314 [132];
  byte abStack_290 [516];
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
  
  local_38 = (uint **)PTR___stack_chk_guard_006a9ae8;
  local_48 = &_gp;
  local_2c = *(uint **)PTR___stack_chk_guard_006a9ae8;
  if (param_1[0xd] == 0x2160) {
    unaff_s4 = param_1[0xf];
    unaff_s0 = *(int *)(unaff_s4 + 4);
    local_30 = (undefined *)(unaff_s0 + 5);
    iVar19 = ssl3_get_req_cert_type(param_1,local_30);
    local_34 = iVar19 + 1;
    *(char *)(unaff_s0 + 4) = (char)iVar19;
    local_30 = local_30 + iVar19;
    if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
      iVar19 = tls12_get_req_sig_algs(param_1,local_30 + 2);
      *local_30 = (char)((uint)iVar19 >> 8);
      local_34 = local_34 + iVar19 + 2;
      local_30[1] = (char)iVar19;
      local_30 = local_30 + iVar19 + 4;
    }
    local_30 = local_30 + 2;
    unaff_s6 = 0;
    unaff_s1 = local_34 + 2;
    unaff_s5 = (**(code **)(local_48 + -0x7464))(param_1);
    if (unaff_s5 == 0) {
      uVar12 = 0;
    }
    else {
      unaff_s0 = 0;
      unaff_s8 = &local_30;
      iVar19 = (**(code **)(local_48 + -0x7fb4))(unaff_s5);
      if (0 < iVar19) {
        do {
          unaff_s2 = (undefined *)(unaff_s1 + 4);
          local_3c = (**(code **)(local_48 + -0x7fbc))(unaff_s5,unaff_s0);
          unaff_s7 = (**(code **)(local_48 + -0x76f4))(local_3c,0);
          iVar19 = (**(code **)(local_48 + -0x72a0))(unaff_s4,unaff_s2 + unaff_s7 + 2);
          if (iVar19 == 0) {
            pcVar18 = *(code **)(local_48 + -0x6eac);
            local_50 = 0x845;
            goto LAB_0047b70c;
          }
          unaff_s2 = unaff_s2 + *(int *)(unaff_s4 + 4);
          if ((param_1[0x40] & 0x20000000U) == 0) {
            pcVar18 = *(code **)(local_48 + -0x76f4);
            *unaff_s2 = (char)((uint)unaff_s7 >> 8);
            unaff_s2[1] = (char)unaff_s7;
            local_30 = unaff_s2 + 2;
            (*pcVar18)(local_3c,unaff_s8);
            iVar19 = unaff_s7 + 2;
          }
          else {
            local_30 = unaff_s2;
            (**(code **)(local_48 + -0x76f4))(local_3c,unaff_s8);
            unaff_s2[1] = (char)(unaff_s7 + -2);
            *unaff_s2 = (char)((uint)(unaff_s7 + -2) >> 8);
            iVar19 = unaff_s7;
          }
          unaff_s6 = unaff_s6 + iVar19;
          unaff_s1 = unaff_s1 + iVar19;
          unaff_s0 = unaff_s0 + 1;
          iVar19 = (**(code **)(local_48 + -0x7fb4))(unaff_s5);
        } while (unaff_s0 < iVar19);
      }
      uVar12 = (undefined)(unaff_s6 >> 8);
      unaff_s6 = unaff_s6 & 0xff;
    }
    pcVar18 = *(code **)(local_48 + -0x72a0);
    local_30 = (undefined *)(*(int *)(unaff_s4 + 4) + local_34 + 4);
    *local_30 = uVar12;
    local_30[1] = (char)unaff_s6;
    puVar5 = *(undefined **)(unaff_s4 + 4);
    local_30 = local_30 + 2;
    puVar5[1] = (char)((uint)unaff_s1 >> 0x10);
    puVar5[2] = (char)((uint)unaff_s1 >> 8);
    *puVar5 = 0xd;
    puVar5[3] = (char)unaff_s1;
    param_1[0x11] = unaff_s1 + 4;
    param_1[0x12] = 0;
    iVar19 = (*pcVar18)(unaff_s4,unaff_s1 + 8);
    if (iVar19 != 0) {
      puVar5 = (undefined *)(*(int *)(param_1[0xf] + 4) + param_1[0x11]);
      *puVar5 = 0xe;
      puVar5[1] = 0;
      puVar5[2] = 0;
      local_30 = puVar5 + 4;
      puVar5[3] = 0;
      param_1[0xd] = 0x2161;
      param_1[0x11] = param_1[0x11] + 4;
      goto LAB_0047b438;
    }
    pcVar18 = *(code **)(local_48 + -0x6eac);
    local_50 = 0x869;
LAB_0047b70c:
    (*pcVar18)(0x14,0x96,7,"s3_srvr.c");
    uVar4 = 0xffffffff;
    param_1[0xd] = 5;
  }
  else {
LAB_0047b438:
    uVar4 = ssl3_do_write(param_1,0x16);
  }
  if (local_2c == *local_38) {
    return uVar4;
  }
  pcStack_64 = ssl3_get_client_key_exchange;
  puVar10 = local_2c;
  (**(code **)(local_48 + -0x5330))();
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  piVar9 = &iStack_32c;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
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
  uVar4 = (**(code **)(puVar10[2] + 0x30))();
  if (iStack_32c == 0) goto LAB_0047ba44;
  uVar8 = puVar10[0x16];
  puStack_328 = (ushort *)puVar10[0x10];
  uVar16 = *(uint *)(*(int *)(uVar8 + 0x344) + 0xc);
  if ((uVar16 & 1) == 0) {
    if ((uVar16 & 0xe) != 0) {
      puVar14 = puStack_328 + 1;
      uVar16 = (uint)*puStack_328;
      if (uVar4 != uVar16 + 2) {
        if ((puVar10[0x40] & 0x80) == 0) {
          uVar15 = 0x94;
          uVar21 = 0x938;
          puStack_328 = puVar14;
          goto LAB_0047be78;
        }
        puVar14 = puStack_328;
        uVar16 = uVar4;
        if (uVar4 == 0) {
          uVar15 = 0xec;
          uVar21 = 0x943;
          goto LAB_0047bb94;
        }
      }
      iVar19 = *(int *)(uVar8 + 0x348);
      puStack_328 = puVar14;
      if (iVar19 != 0) {
        iVar6 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar14,uVar16,0);
        if (iVar6 == 0) {
          uVar15 = 0x82;
          uVar21 = 0x951;
          goto LAB_0047be78;
        }
        iVar19 = (*(code *)PTR_DH_compute_key_006a7fa4)(puStack_328,iVar6,iVar19);
        if (0 < iVar19) {
          (*(code *)PTR_DH_free_006a7508)(*(undefined4 *)(puVar10[0x16] + 0x348));
          puVar3 = PTR_BN_clear_free_006a7fa8;
          *(undefined4 *)(puVar10[0x16] + 0x348) = 0;
          (*(code *)puVar3)(iVar6);
          uVar8 = puVar10[0x30];
          uVar21 = (**(code **)(*(int *)(puVar10[2] + 100) + 0xc))
                             (puVar10,uVar8 + 0x14,puStack_328,iVar19);
          goto LAB_0047ba2c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,5,"s3_srvr.c",0x958);
        (*(code *)PTR_BN_clear_free_006a7fa8)(iVar6);
        goto LAB_0047bc4c;
      }
      uVar15 = 0xab;
      uVar21 = 0x949;
      goto LAB_0047bb94;
    }
    if ((uVar16 & 0xe0) != 0) {
      iVar19 = (*(code *)PTR_EC_KEY_new_006a71a8)();
      if (iVar19 == 0) {
        uVar15 = 0x41;
        uVar21 = 0xa32;
        goto LAB_0047be78;
      }
      if ((uVar16 & 0x60) == 0) {
        uVar21 = *(undefined4 *)(puVar10[0x16] + 0x34c);
      }
      else {
        uVar21 = *(undefined4 *)(*(int *)(puVar10[0x26] + 0x70) + 0x14);
      }
      uVar15 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar21);
      uVar21 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(uVar21);
      iVar6 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar19,uVar15);
      if ((iVar6 == 0) ||
         (iVar6 = (*(code *)PTR_EC_KEY_set_private_key_006a7fbc)(iVar19,uVar21), iVar6 == 0)) {
        iVar17 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x10,"s3_srvr.c",0xa47);
        iVar6 = 0;
        piVar9 = (int *)0x0;
      }
      else {
        iVar6 = (*(code *)PTR_EC_POINT_new_006a7fc0)(uVar15);
        if (iVar6 == 0) {
          iVar17 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x41,"s3_srvr.c",0xa4d);
          piVar9 = (int *)0x0;
        }
        else {
          if (uVar4 == 0) {
            if ((uVar16 & 0x80) == 0) {
              piVar9 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                        (*(undefined4 *)(puVar10[0x30] + 0x9c));
              if ((piVar9 != (int *)0x0) && (*piVar9 == 0x198)) {
                uVar21 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(piVar9[5]);
                iVar17 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(iVar6,uVar21);
                if (iVar17 != 0) {
                  uVar4 = 2;
                  iVar17 = 0;
                  goto LAB_0047c060;
                }
                iVar17 = 0;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x10,"s3_srvr.c",0xa6d);
                goto LAB_0047c30c;
              }
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x139,"s3_srvr.c",0xa66);
            }
            else {
              piVar9 = (int *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x137,"s3_srvr.c",0xa57);
            }
            ssl3_send_alert(puVar10,2,0x28);
            iVar17 = 0;
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar9);
            (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
            goto LAB_0047c2c4;
          }
          iVar17 = (*(code *)PTR_BN_CTX_new_006a794c)();
          if (iVar17 == 0) {
            uVar15 = 0x41;
            uVar21 = 0xa78;
          }
          else {
            puVar14 = (ushort *)((int)puStack_328 + 1);
            bVar20 = *(byte *)puStack_328;
            puStack_328 = puVar14;
            if (uVar4 == bVar20 + 1) {
              iVar7 = (*(code *)PTR_EC_POINT_oct2point_006a7fc8)
                                (uVar15,iVar6,puVar14,(uint)bVar20,iVar17);
              if (iVar7 != 0) {
                uVar4 = 1;
                piVar9 = (int *)0x0;
                puStack_328 = *(ushort **)(puVar10[0xf] + 4);
LAB_0047c060:
                iVar7 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(uVar15);
                if (iVar7 < 1) {
                  uVar21 = 0xa91;
                }
                else {
                  iVar7 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                                    (puStack_328,iVar7 + 7 >> 3,iVar6,iVar19,0);
                  if (0 < iVar7) {
                    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar9);
                    (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
                    (*(code *)PTR_EC_KEY_free_006a71d4)(iVar19);
                    (*(code *)PTR_BN_CTX_free_006a7954)(iVar17);
                    (*(code *)PTR_EC_KEY_free_006a71d4)(*(undefined4 *)(puVar10[0x16] + 0x34c));
                    uVar8 = puVar10[0x30];
                    iVar19 = *(int *)(puVar10[2] + 100);
                    *(undefined4 *)(puVar10[0x16] + 0x34c) = 0;
                    uVar21 = (**(code **)(iVar19 + 0xc))(puVar10,uVar8 + 0x14,puStack_328,iVar7);
                    puVar3 = PTR_OPENSSL_cleanse_006a7074;
                    *(undefined4 *)(uVar8 + 0x10) = uVar21;
                    (*(code *)puVar3)(puStack_328,iVar7);
                    goto LAB_0047ba44;
                  }
                  uVar21 = 0xa97;
                }
                (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x2b,"s3_srvr.c",uVar21);
                goto LAB_0047c30c;
              }
              uVar15 = 0x10;
              uVar21 = 0xa84;
            }
            else {
              uVar15 = 0x10;
              uVar21 = 0xa80;
            }
          }
          piVar9 = (int *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar15,"s3_srvr.c",uVar21);
        }
      }
LAB_0047c30c:
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar9);
      (*(code *)PTR_EC_POINT_free_006a7fac)(iVar6);
LAB_0047c2c4:
      (*(code *)PTR_EC_KEY_free_006a71d4)(iVar19);
      goto LAB_0047bc68;
    }
    if ((uVar16 & 0x100) == 0) {
      if ((uVar16 & 0x400) == 0) {
        if ((uVar16 & 0x200) == 0) {
          uVar15 = 0xf9;
          uVar21 = 0xb7b;
          goto LAB_0047bb94;
        }
        uVar8 = *(uint *)(*(int *)(uVar8 + 0x344) + 0x10);
        uStack_324 = 0x20;
        if ((uVar8 & 0x100) == 0) {
          if ((uVar8 & 0x200) == 0) {
            uVar21 = 0;
          }
          else {
            uVar21 = *(undefined4 *)(puVar10[0x26] + 0x88);
          }
        }
        else {
          uVar21 = *(undefined4 *)(puVar10[0x26] + 0x7c);
        }
        iVar19 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(uVar21,0);
        if (iVar19 != 0) {
          iVar6 = (*(code *)PTR_EVP_PKEY_decrypt_init_006a7ce4)(iVar19);
          if (iVar6 < 1) {
            iVar6 = 0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x44,"s3_srvr.c",0xb46);
          }
          else {
            iVar6 = (*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(puVar10[0x30] + 0x9c));
            if ((iVar6 != 0) &&
               (iVar17 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a7cf0)(iVar19,iVar6), iVar17 < 1)
               ) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            iVar17 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                               (&puStack_328,&uStack_318,&iStack_320,&iStack_31c,uVar4);
            if (((iVar17 == 0x20) && (iStack_320 == 0x10)) && (iStack_31c == 0)) {
              iVar17 = (*(code *)PTR_EVP_PKEY_decrypt_006a7d0c)
                                 (iVar19,abStack_290,&uStack_324,puStack_328,uStack_318);
              if (0 < iVar17) {
                uVar4 = puVar10[0x30];
                uVar21 = (**(code **)(*(int *)(puVar10[2] + 100) + 0xc))
                                   (puVar10,uVar4 + 0x14,abStack_290,0x20);
                *(undefined4 *)(uVar4 + 0x10) = uVar21;
                uVar4 = 1;
                (*(code *)PTR_OPENSSL_cleanse_006a7074)(abStack_290,0x20);
                iVar17 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)
                                   (iVar19,0xffffffff,0xffffffff,2,2,0);
                if (0 < iVar17) {
                  uVar4 = 2;
                }
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar6);
                (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar19);
                puVar10 = (uint *)&SUB_00000002;
                goto LAB_0047ba44;
              }
              uVar21 = 0xb62;
            }
            else {
              uVar21 = 0xb5a;
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x93,"s3_srvr.c",uVar21);
          }
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar6);
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar19);
          goto LAB_0047bc4c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x41,"s3_srvr.c",0xb42);
        uVar21 = 0x50;
      }
      else {
        puVar14 = puStack_328 + 1;
        uVar2 = *puStack_328;
        if ((int)uVar4 < (int)(uVar2 + 2)) {
          uVar15 = 0x15b;
          uVar21 = 0xb0e;
          goto LAB_0047c654;
        }
        puStack_328 = puVar14;
        uVar4 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar14,(uint)uVar2,0);
        puVar10[0x6e] = uVar4;
        if (uVar4 == 0) {
          uVar15 = 3;
          uVar21 = 0xb12;
          goto LAB_0047be78;
        }
        iVar19 = (*(code *)PTR_BN_ucmp_006a7fb4)(uVar4,puVar10[0x6a]);
        if ((iVar19 < 0) && (*(int *)(puVar10[0x6e] + 4) != 0)) {
          uVar4 = puVar10[0x30];
          if (*(int *)(uVar4 + 0xf0) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            uVar4 = puVar10[0x30];
          }
          uVar21 = (*(code *)PTR_BUF_strdup_006a6fdc)(puVar10[0x69]);
          uVar8 = puVar10[0x30];
          *(undefined4 *)(uVar4 + 0xf0) = uVar21;
          if (*(int *)(uVar8 + 0xf0) == 0) goto LAB_0047c7c0;
          uVar4 = 1;
          iVar19 = (*(code *)PTR_SRP_generate_server_master_secret_006a7fb8)(puVar10,uVar8 + 0x14);
          *(int *)(uVar8 + 0x10) = iVar19;
          if (-1 < iVar19) goto LAB_0047ba44;
          uVar15 = 0x44;
          uVar21 = 0xb27;
          goto LAB_0047be78;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0x173,"s3_srvr.c",0xb19,piVar9);
        uVar21 = 0x2f;
      }
      goto LAB_0047bc30;
    }
    puVar14 = puStack_328 + 1;
    uVar8 = (uint)*puStack_328;
    puStack_328 = puVar14;
    if (uVar4 == uVar8 + 2) {
      if (0x80 < uVar8) {
        uVar15 = 0x92;
        uVar21 = 0xabe;
        goto LAB_0047bbf8;
      }
      pcVar18 = (code *)puVar10[0x38];
      if (pcVar18 == (code *)0x0) {
        uVar15 = 0xe1;
        uVar21 = 0xac3;
        goto LAB_0047bbf8;
      }
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_314,puVar14,uVar8,0x81,uVar21);
      (*(code *)PTR_memset_006a99f4)(auStack_314 + uVar8,0,0x81 - uVar8);
      uVar4 = (*pcVar18)(puVar10,auStack_314,abStack_290,0x204);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_314,0x81);
      if (uVar4 < 0x101) {
        if (uVar4 != 0) {
          (*(code *)PTR_memmove_006a9af4)(abStack_290 + uVar4 + 4,abStack_290,uVar4);
          bVar20 = (byte)(uVar4 >> 8);
          abStack_290[0] = bVar20;
          abStack_290[1] = (byte)uVar4;
          (*(code *)PTR___memset_chk_006a998c)(abStack_290 + 2,0,uVar4,0x202);
          uVar16 = puVar10[0x30];
          (abStack_290 + 2)[uVar4] = bVar20;
          abStack_290[uVar4 + 3] = (byte)uVar4;
          if (*(int *)(uVar16 + 0x90) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            uVar16 = puVar10[0x30];
          }
          uVar21 = (*(code *)PTR_BUF_strndup_006a7fcc)(puStack_328,uVar8);
          uVar8 = puVar10[0x30];
          *(undefined4 *)(uVar16 + 0x90) = uVar21;
          if (*(int *)(uVar8 + 0x90) == 0) {
            uVar15 = 0x41;
            uVar21 = 0xaeb;
          }
          else {
            if (*(int *)(uVar8 + 0x8c) != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
              uVar8 = puVar10[0x30];
            }
            uVar21 = (*(code *)PTR_BUF_strdup_006a6fdc)(*(undefined4 *)(puVar10[0x39] + 0x14c));
            uVar16 = puVar10[0x39];
            *(undefined4 *)(uVar8 + 0x8c) = uVar21;
            uVar8 = puVar10[0x30];
            if ((*(int *)(uVar16 + 0x14c) == 0) || (*(int *)(uVar8 + 0x8c) != 0)) {
              uVar21 = (**(code **)(*(int *)(puVar10[2] + 100) + 0xc))
                                 (puVar10,uVar8 + 0x14,abStack_290,uVar4 * 2 + 4);
              *(undefined4 *)(uVar8 + 0x10) = uVar21;
              uVar4 = 1;
              (*(code *)PTR_OPENSSL_cleanse_006a7074)(abStack_290,0x204);
              goto LAB_0047ba44;
            }
            uVar15 = 0x41;
            uVar21 = 0xaf4;
          }
          goto LAB_0047c47c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0xdf,"s3_srvr.c",0xad9);
        uVar21 = 0x73;
      }
      else {
        uVar15 = 0x44;
        uVar21 = 0xad2;
LAB_0047c47c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar15,"s3_srvr.c",uVar21);
        uVar21 = 0x28;
      }
    }
    else {
      uVar15 = 0x9f;
      uVar21 = 0xab9;
LAB_0047bbf8:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar15,"s3_srvr.c",uVar21);
      uVar21 = 0x28;
    }
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(abStack_290,0x204);
  }
  else {
    if (*(int *)(uVar8 + 0x370) == 0) {
      piVar9 = *(int **)(puVar10[0x26] + 0x34);
      if (((piVar9 != (int *)0x0) && (*piVar9 == 6)) && (iVar19 = piVar9[5], iVar19 != 0)) {
LAB_0047b888:
        uVar8 = uVar4;
        puVar14 = puStack_328;
        if ((((int)*puVar10 < 0x301) ||
            (uVar8 = (uint)*puStack_328, puVar14 = puStack_328 + 1, uVar4 == *puStack_328 + 2)) ||
           (uVar8 = uVar4, puVar14 = puStack_328, (puVar10[0x40] & 0x100) != 0)) {
          puStack_328 = puVar14;
          if (0x2f < (int)uVar8) {
            pbVar11 = abStack_290;
            iVar6 = (*(code *)PTR_RAND_bytes_006a7574)(pbVar11,0x30);
            if (0 < iVar6) {
              uVar4 = (*(code *)PTR_RSA_private_decrypt_006a7644)
                                (uVar8,puStack_328,puStack_328,iVar19,1);
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
              uVar8 = puVar10[0x44];
              bVar20 = ~(byte)((int)uVar8 >> 0x1f) &
                       (byte)(((int)uVar8 >> 8 ^ (uint)*(byte *)puStack_328) - 1 >> 0x18) &
                       (byte)((uVar8 & 0xff ^ (uint)*(byte *)((int)puStack_328 + 1)) - 1 >> 0x18);
              if ((int)(puVar10[0x40] << 8) < 0) {
                uVar8 = *puVar10;
                bVar20 = bVar20 | ~(byte)((int)uVar8 >> 0x1f) &
                                  (byte)(((int)uVar8 >> 8 ^ (uint)*(byte *)puStack_328) - 1 >> 0x18)
                                  & (byte)((uVar8 & 0xff ^ (uint)*(byte *)((int)puStack_328 + 1)) -
                                           1 >> 0x18);
              }
              iVar19 = 0;
              do {
                pbVar13 = (byte *)((int)puStack_328 + iVar19);
                bVar1 = *pbVar11;
                iVar19 = iVar19 + 1;
                pbVar11 = pbVar11 + 1;
                *pbVar13 = bVar1 ^ (char)(bVar20 & ~(byte)(uVar4 >> 0x18) &
                                                   (byte)((uVar4 ^ 0x30) - 1 >> 0x18)) >> 7 &
                                   (bVar1 ^ *pbVar13);
              } while (iVar19 != 0x30);
              uVar8 = puVar10[0x30];
              uVar21 = (**(code **)(*(int *)(puVar10[2] + 100) + 0xc))
                                 (puVar10,uVar8 + 0x14,puStack_328,0x30);
              iVar19 = 0x30;
LAB_0047ba2c:
              puVar3 = PTR_OPENSSL_cleanse_006a7074;
              uVar4 = 1;
              *(undefined4 *)(uVar8 + 0x10) = uVar21;
              (*(code *)puVar3)(puStack_328,iVar19);
              goto LAB_0047ba44;
            }
            goto LAB_0047bc4c;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,0xea,"s3_srvr.c",0x8de);
          uVar21 = 0x33;
        }
        else {
          uVar15 = 0xea;
          uVar21 = 0x8cc;
LAB_0047c654:
          puStack_328 = puStack_328 + 1;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar15,"s3_srvr.c",uVar21);
          uVar21 = 0x32;
        }
        goto LAB_0047bc30;
      }
      uVar15 = 0xa8;
      uVar21 = 0x8bf;
    }
    else {
      if ((puVar10[0x26] != 0) && (iVar19 = *(int *)(puVar10[0x26] + 0x18), iVar19 != 0))
      goto LAB_0047b888;
      uVar15 = 0xad;
      uVar21 = 0x8b5;
    }
LAB_0047bb94:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar15,"s3_srvr.c",uVar21);
    uVar21 = 0x28;
  }
LAB_0047bc30:
  ssl3_send_alert(puVar10,2,uVar21);
LAB_0047bc4c:
  while( true ) {
    iVar17 = 0;
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(0);
    (*(code *)PTR_EC_POINT_free_006a7fac)(0);
LAB_0047bc68:
    uVar4 = 0xffffffff;
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar17);
    puVar10[0xd] = 5;
LAB_0047ba44:
    if (iStack_8c == *(int *)puVar5) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0047c7c0:
    uVar15 = 0x41;
    uVar21 = 0xb20;
LAB_0047be78:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8b,uVar15,"s3_srvr.c",uVar21);
  }
  return uVar4;
}

