
int ssl2_connect(uint *param_1)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined uVar13;
  bool bVar14;
  undefined uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  code *pcVar18;
  uint uVar19;
  undefined4 *puVar20;
  undefined *puVar21;
  uint uVar22;
  undefined *puVar23;
  char *pcVar24;
  int local_68;
  int local_64;
  undefined4 local_54;
  undefined *local_50;
  undefined *local_4c;
  int local_48;
  int local_44 [6];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_54 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_54,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar5 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  pcVar18 = (code *)param_1[0x34];
  *puVar5 = 0;
  puVar23 = PTR_SSL_state_006a88f4;
  if (pcVar18 == (code *)0x0) {
    pcVar18 = *(code **)(param_1[0x39] + 0x9c);
  }
  param_1[7] = param_1[7] + 1;
  uVar6 = (*(code *)puVar23)(param_1);
  if (((uVar6 & 0x3000) == 0) ||
     (uVar6 = (*(code *)PTR_SSL_state_006a88f4)(param_1), (uVar6 & 0x4000) != 0)) {
    (*(code *)PTR_SSL_clear_006a88d4)(param_1);
  }
  bVar2 = (int)param_1[0xd] < 0x1042;
  uVar6 = param_1[0xd];
LAB_0047a7d4:
  while (!bVar2) {
    if ((int)uVar6 < 0x1072) {
      if ((int)uVar6 < 0x1070) {
        if ((int)uVar6 < 0x1050) goto LAB_0047aac8;
        if ((int)uVar6 < 0x1054) goto LAB_0047acfc;
        if (1 < uVar6 - 0x1060) goto LAB_0047aac8;
        pcVar24 = *(char **)(param_1[0xf] + 4);
        if (uVar6 == 0x1060) {
          iVar7 = ssl2_read(param_1,pcVar24 + param_1[0x11],1 - param_1[0x11]);
          if (iVar7 < (int)(1 - param_1[0x11])) goto LAB_0047b660;
          uVar22 = iVar7 + param_1[0x11];
          param_1[0x11] = uVar22;
          param_1[0xd] = 0x1061;
          if (*pcVar24 == '\x05') {
            pcVar24 = *(char **)(param_1[0xf] + 4);
            goto LAB_0047a930;
          }
          if (*pcVar24 == '\0') {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6e,200,"s2_clnt.c",0x39b);
            uVar8 = ssl2_read(param_1,pcVar24 + param_1[0x11],3 - param_1[0x11]);
            iVar7 = ssl2_part_read(param_1,0x6e,uVar8);
            if (iVar7 < 1) {
              uVar6 = param_1[7];
              goto LAB_0047a87c;
            }
            goto LAB_0047a9b0;
          }
          ssl2_return_error(param_1,0);
          uVar16 = 0xd4;
          uVar8 = 0x397;
        }
        else {
          uVar22 = param_1[0x11];
LAB_0047a930:
          iVar10 = *(int *)(param_1[0x15] + 100) + 1;
          iVar12 = iVar10 - uVar22;
          iVar7 = ssl2_read(param_1,pcVar24 + uVar22,iVar12);
          if (iVar7 < iVar12) {
LAB_0047b660:
            iVar7 = ssl2_part_read(param_1,0x6e,iVar7);
            if (iVar7 < 1) {
              uVar6 = param_1[7];
              goto LAB_0047a87c;
            }
            goto LAB_0047a9b0;
          }
          if ((code *)param_1[0x19] != (code *)0x0) {
            (*(code *)param_1[0x19])(0,*param_1,0,pcVar24,iVar10,param_1,param_1[0x1a]);
          }
          iVar7 = (*(code *)PTR_CRYPTO_memcmp_006a9088)
                            (pcVar24 + 1,param_1[0x15] + 0x68,*(undefined4 *)(param_1[0x15] + 100));
          if (iVar7 == 0) goto LAB_0047a9b0;
          ssl2_return_error(param_1,0);
          uVar16 = 0x88;
          uVar8 = 0x3b1;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6e,uVar16,"s2_clnt.c",uVar8);
        iVar7 = -1;
        goto LAB_0047a878;
      }
      pcVar24 = *(char **)(param_1[0xf] + 4);
      if (uVar6 == 0x1070) {
        iVar7 = ssl2_read(param_1,pcVar24 + param_1[0x11],1 - param_1[0x11]);
        if (iVar7 < (int)(1 - param_1[0x11])) goto LAB_0047b684;
        uVar22 = iVar7 + param_1[0x11];
        param_1[0x11] = uVar22;
        cVar1 = *pcVar24;
        if (cVar1 == '\a') {
          param_1[0xd] = 0x1050;
          uVar22 = 0x1050;
          goto LAB_0047aa30;
        }
        if (cVar1 == '\x06') {
          param_1[0xd] = 0x1071;
          goto LAB_0047ad68;
        }
        if (cVar1 != '\0') {
          ssl2_return_error(param_1,0);
          uVar16 = 0xd4;
          uVar8 = 0x3d0;
          goto LAB_0047bdf0;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6c,200,"s2_clnt.c",0x3d4);
        uVar8 = ssl2_read(param_1,pcVar24 + param_1[0x11],3 - param_1[0x11]);
        iVar7 = ssl2_part_read(param_1,0x6e,uVar8);
      }
      else {
        uVar22 = param_1[0x11];
LAB_0047ad68:
        iVar7 = ssl2_read(param_1,pcVar24 + uVar22,0x11 - uVar22);
        if ((int)(0x11 - uVar22) <= iVar7) {
          uVar22 = param_1[0x11];
          param_1[0x11] = iVar7 + uVar22;
          if ((code *)param_1[0x19] != (code *)0x0) {
            (*(code *)param_1[0x19])(0,*param_1,0,pcVar24,iVar7 + uVar22,param_1,param_1[0x1a]);
          }
          if (param_1[0x1b] == 0) {
            uVar22 = param_1[0x30];
            *(undefined4 *)(uVar22 + 0x44) = 0x10;
            uVar17 = *(undefined4 *)(pcVar24 + 5);
            uVar16 = *(undefined4 *)(pcVar24 + 9);
            uVar8 = *(undefined4 *)(pcVar24 + 0xd);
            *(undefined4 *)(uVar22 + 0x48) = *(undefined4 *)(pcVar24 + 1);
            *(undefined4 *)(uVar22 + 0x4c) = uVar17;
            *(undefined4 *)(uVar22 + 0x50) = uVar16;
            *(undefined4 *)(uVar22 + 0x54) = uVar8;
          }
          else if (((param_1[0x40] & 1) == 0) &&
                  ((0x20 < *(uint *)(param_1[0x30] + 0x44) ||
                   (iVar7 = (*(code *)PTR_memcmp_006aabd8)(pcVar24 + 1,param_1[0x30] + 0x48),
                   iVar7 != 0)))) {
            ssl2_return_error(param_1,0);
            uVar16 = 0xe7;
            uVar8 = 0x3f9;
LAB_0047bdf0:
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6c,uVar16,"s2_clnt.c",uVar8);
            iVar7 = -1;
            goto LAB_0047a878;
          }
          param_1[0xd] = 3;
          uVar22 = 3;
          goto LAB_0047aa30;
        }
LAB_0047b684:
        iVar7 = ssl2_part_read(param_1,0x6c,iVar7);
      }
      if (iVar7 < 1) goto LAB_0047a878;
      uVar22 = param_1[0xd];
    }
    else if (uVar6 == 0x1090) {
LAB_0047acfc:
      puVar23 = *(undefined **)(param_1[0xf] + 4);
      if (uVar6 == 0x1050) {
        iVar7 = ssl2_read(param_1,puVar23 + param_1[0x11],0x22 - param_1[0x11]);
        if ((int)(0x12 - param_1[0x11]) <= iVar7) {
          uVar22 = iVar7 + param_1[0x11];
          param_1[0x11] = uVar22;
          if ((code *)param_1[0x19] != (code *)0x0) {
            (*(code *)param_1[0x19])(0,*param_1,0,puVar23,uVar22,param_1,param_1[0x1a]);
          }
          if (puVar23[1] == '\x01') {
            if ((((int **)param_1[0x26] == (int **)0x0) ||
                (piVar9 = *(int **)param_1[0x26], *piVar9 == 0)) || (piVar9[1] == 0)) {
              iVar7 = param_1[0x11] - 2;
              param_1[0xd] = 0x1090;
              goto LAB_0047b618;
            }
            iVar7 = param_1[0x11] - 2;
            param_1[0xd] = 0x1052;
            goto LAB_0047b808;
          }
          ssl2_return_error(param_1,6);
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,100,0x66,"s2_clnt.c",0x309);
          iVar7 = -1;
          goto LAB_0047a878;
        }
        iVar7 = ssl2_part_read(param_1,100,iVar7);
        if (iVar7 < 1) {
          uVar6 = param_1[7];
          goto LAB_0047a87c;
        }
      }
      else {
        iVar7 = param_1[0x11] - 2;
        uVar22 = uVar6;
        if (uVar6 == 0x1090) {
LAB_0047b618:
          local_48 = 0;
          local_44[0] = 0;
          if (*(code **)(param_1[0x39] + 0x74) == (code *)0x0) {
            param_1[6] = 1;
          }
          else {
            iVar12 = (**(code **)(param_1[0x39] + 0x74))(param_1,&local_48,local_44);
            if (iVar12 < 0) {
              param_1[6] = 4;
              iVar7 = -1;
              goto LAB_0047a878;
            }
            param_1[6] = 1;
            puVar21 = PTR_SSL_use_certificate_006a9098;
            if (iVar12 == 1) {
              if (local_44[0] == 0) {
                if ((local_48 != 0) && ((*(code *)PTR_X509_free_006a7f90)(), local_44[0] != 0))
                goto LAB_0047b9b8;
              }
              else {
                if (local_48 != 0) {
                  param_1[0xd] = 0x1052;
                  iVar12 = (*(code *)puVar21)(param_1);
                  if (iVar12 == 0) {
                    bVar14 = false;
                  }
                  else {
                    iVar12 = (*(code *)PTR_SSL_use_PrivateKey_006a909c)(param_1,local_44[0]);
                    bVar14 = iVar12 != 0;
                  }
                  (*(code *)PTR_X509_free_006a7f90)(local_48);
                  (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_44[0]);
                  if (bVar14) goto LAB_0047b658;
                  goto LAB_0047b9f0;
                }
LAB_0047b9b8:
                (*(code *)PTR_EVP_PKEY_free_006a7f78)();
              }
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,100,0x6a,"s2_clnt.c",0x341);
            }
            else if (iVar12 != 0) {
LAB_0047b658:
              uVar22 = param_1[0xd];
              goto LAB_0047ad24;
            }
          }
LAB_0047b9f0:
          param_1[0xd] = 0x1051;
          *puVar23 = 0;
          puVar23[1] = 0;
          puVar23[2] = 2;
          param_1[0x12] = 0;
          param_1[0x11] = 3;
          local_50 = puVar23 + 3;
          uVar22 = param_1[0xd];
        }
LAB_0047ad24:
        if ((uVar22 != 0x1051) && (uVar22 == 0x1052)) {
LAB_0047b808:
          local_50 = puVar23;
          (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(local_44);
          (*(code *)PTR_EVP_DigestInit_ex_006a8670)
                    (local_44,*(undefined4 *)(param_1[0x39] + 0x88),0);
          (*(code *)PTR_EVP_DigestUpdate_006a8674)
                    (local_44,param_1[0x15] + 0xa0,*(undefined4 *)(param_1[0x15] + 0x9c));
          (*(code *)PTR_EVP_DigestUpdate_006a8674)(local_44,puVar23 + 2,iVar7);
          iVar7 = (*(code *)PTR_i2d_X509_006a87d4)
                            (**(undefined4 **)(*(int *)(param_1[0x30] + 0x98) + 8),&local_50);
          if (0 < iVar7) {
            (*(code *)PTR_EVP_DigestUpdate_006a8674)(local_44,puVar23,iVar7);
          }
          puVar21 = PTR_i2d_X509_006a87d4;
          local_4c = puVar23 + 6;
          *puVar23 = 8;
          local_50 = puVar23 + 2;
          puVar23[1] = 1;
          local_48 = (*(code *)puVar21)(**(undefined4 **)param_1[0x26],&local_4c);
          puVar21 = PTR_EVP_SignFinal_006a9094;
          *local_50 = (char)((uint)local_48 >> 8);
          local_50[1] = (char)local_48;
          local_50 = local_50 + 2;
          (*(code *)puVar21)(local_44,local_4c,&local_48,*(undefined4 *)(*(int *)param_1[0x26] + 4))
          ;
          (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(local_44);
          *local_50 = (char)((uint)local_48 >> 8);
          local_50[1] = (char)local_48;
          param_1[0x12] = 0;
          param_1[0xd] = 0x1053;
          local_4c = local_4c + local_48;
          local_50 = local_50 + 2;
          param_1[0x11] = (int)local_4c - (int)puVar23;
        }
        iVar7 = ssl2_do_write(param_1);
        if (iVar7 < 1) {
          uVar6 = param_1[7];
          goto LAB_0047a87c;
        }
      }
LAB_0047a9b0:
      param_1[0x11] = 0;
      uVar22 = 0x1070;
      param_1[0xd] = 0x1070;
    }
    else {
      if ((int)uVar6 < 0x1091) {
        if (uVar6 != 0x1080) {
LAB_0047aac8:
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7b,0xff,"s2_clnt.c",0x136);
          iVar7 = -1;
          goto LAB_0047a8a8;
        }
        iVar7 = ssl2_enc_init(param_1,1);
        if (iVar7 != 0) {
          *(undefined4 *)(param_1[0x15] + 4) = 0;
          param_1[0xd] = 0x1040;
          if (pcVar18 == (code *)0x0) {
            uVar6 = 0x1040;
            goto LAB_0047afc4;
          }
          uVar6 = 0x1080;
          uVar22 = 0x1040;
          goto LAB_0047aa38;
        }
        goto LAB_0047b120;
      }
      if ((uVar6 != 0x4000) && (uVar6 != 0x5000)) goto LAB_0047aac8;
LAB_0047ab00:
      param_1[9] = 0;
      if (pcVar18 != (code *)0x0) {
        (*pcVar18)(param_1,0x10,1);
      }
      uVar22 = param_1[0xf];
      *param_1 = 2;
      param_1[1] = 0x1000;
      if ((uVar22 == 0) && (uVar22 = (*(code *)PTR_BUF_MEM_new_006a859c)(), uVar22 == 0)) {
        iVar7 = -1;
        goto LAB_0047a878;
      }
      iVar7 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(uVar22,0x3fff);
      puVar23 = PTR_BUF_MEM_free_006a8594;
      if (iVar7 == 0) {
        if (uVar22 != param_1[0xf]) {
          param_1[7] = param_1[7] - 1;
          (*(code *)puVar23)(uVar22);
          iVar7 = -1;
          goto LAB_0047a884;
        }
LAB_0047b120:
        iVar7 = -1;
LAB_0047a878:
        while( true ) {
          uVar6 = param_1[7];
LAB_0047a87c:
          param_1[7] = uVar6 - 1;
LAB_0047a884:
          if (pcVar18 != (code *)0x0) {
            (*pcVar18)(param_1,0x1002,iVar7);
          }
LAB_0047a8a8:
          if (local_2c == *(int *)puVar3) break;
          (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0047c0ec:
          ssl2_return_error(param_1,4);
          iVar7 = -1;
        }
        return iVar7;
      }
      param_1[0xf] = uVar22;
      uVar22 = 0x1010;
      param_1[0x11] = 0;
      param_1[0xd] = 0x1010;
      *(int *)(param_1[0x39] + 0x34) = *(int *)(param_1[0x39] + 0x34) + 1;
      param_1[8] = (uint)ssl2_connect;
    }
    if (pcVar18 != (code *)0x0) goto code_r0x0047a9c8;
LAB_0047aaf8:
    uVar6 = uVar22;
    bVar2 = (int)uVar22 < 0x1042;
  }
  if ((int)uVar6 < 0x1040) {
    if (0x1011 < (int)uVar6) {
      if ((int)uVar6 < 0x1020) goto LAB_0047aac8;
      if ((int)uVar6 < 0x1022) {
        pcVar24 = *(char **)(param_1[0xf] + 4);
        if (uVar6 == 0x1020) {
          iVar7 = ssl2_read(param_1,pcVar24 + param_1[0x11],0xb - param_1[0x11]);
          if (iVar7 < (int)(0xb - param_1[0x11])) {
LAB_0047b404:
            iVar7 = ssl2_part_read(param_1,0x6d,iVar7);
            if (iVar7 < 1) {
              uVar6 = param_1[7];
              goto LAB_0047a87c;
            }
LAB_0047af40:
            param_1[0x11] = 0;
            if (param_1[0x1b] == 0) {
              uVar22 = 0x1030;
              param_1[0xd] = 0x1030;
              goto LAB_0047aa30;
            }
            goto LAB_0047aa20;
          }
          param_1[0x11] = 0xb;
          if (*pcVar24 == '\x04') {
            uVar22 = param_1[0x15];
            uVar19 = *param_1;
            param_1[0x1b] = (uint)(pcVar24[1] != '\0');
            *(uint *)(uVar22 + 0xdc) = (uint)(byte)pcVar24[2];
            if ((int)(uint)*(ushort *)(pcVar24 + 3) < (int)uVar19) {
              *param_1 = (uint)*(ushort *)(pcVar24 + 3);
            }
            *(uint *)(uVar22 + 0xe0) = (uint)*(ushort *)(pcVar24 + 5);
            *(uint *)(uVar22 + 0xe4) = (uint)*(ushort *)(pcVar24 + 7);
            *(uint *)(uVar22 + 0xd8) = (uint)*(ushort *)(pcVar24 + 9);
            param_1[0xd] = 0x1021;
            goto LAB_0047ae3c;
          }
          if (*pcVar24 == '\0') {
            uVar16 = 200;
            uVar8 = 0x167;
          }
          else {
            ssl2_return_error(param_1,0);
            uVar16 = 0xd4;
            uVar8 = 0x163;
          }
        }
        else {
          uVar22 = param_1[0x15];
LAB_0047ae3c:
          uVar22 = *(int *)(uVar22 + 0xe0) + *(int *)(uVar22 + 0xe4) + 0xb + *(int *)(uVar22 + 0xd8)
          ;
          if (uVar22 < 0x4000) {
            iVar12 = uVar22 - param_1[0x11];
            iVar7 = ssl2_read(param_1,pcVar24 + param_1[0x11],iVar12);
            if (iVar12 != iVar7) goto LAB_0047b404;
            if ((code *)param_1[0x19] != (code *)0x0) {
              (*(code *)param_1[0x19])(0,*param_1,0,pcVar24,uVar22,param_1,param_1[0x1a]);
            }
            pcVar24 = pcVar24 + 0xb;
            if (param_1[0x1b] == 0) {
              if ((*(int *)(param_1[0x30] + 0x44) != 0) &&
                 (iVar7 = (*(code *)PTR_ssl_get_new_session_006a904c)(param_1,0), iVar7 == 0))
              goto LAB_0047bb34;
              iVar7 = ssl2_set_certificate
                                (param_1,*(undefined4 *)(param_1[0x15] + 0xdc),
                                 *(undefined4 *)(param_1[0x15] + 0xe0),pcVar24);
              if (iVar7 < 1) goto LAB_0047c0ec;
              iVar7 = *(int *)(param_1[0x15] + 0xe0);
              iVar12 = *(int *)(param_1[0x15] + 0xe4);
              if (iVar12 == 0) {
                ssl2_return_error(param_1,1);
                uVar16 = 0xb8;
                uVar8 = 0x1c4;
              }
              else {
                iVar12 = (*(code *)PTR_ssl_bytes_to_cipher_list_006a9068)
                                   (param_1,pcVar24 + iVar7,iVar12,param_1[0x30] + 0xbc);
                pcVar24 = pcVar24 + iVar7 + *(int *)(param_1[0x15] + 0xe4);
                if (iVar12 == 0) {
                  ssl2_return_error(param_1,0);
                  uVar16 = 0x41;
                  uVar8 = 0x1d3;
                }
                else {
                  (*(code *)PTR_sk_set_cmp_func_006a9090)(iVar12,PTR_ssl_cipher_ptr_id_cmp_006a908c)
                  ;
                  iVar10 = (*(code *)PTR_SSL_get_ciphers_006a894c)(param_1);
                  (*(code *)PTR_sk_set_cmp_func_006a9090)(iVar10,PTR_ssl_cipher_ptr_id_cmp_006a908c)
                  ;
                  iVar7 = iVar10;
                  if ((int)(param_1[0x40] << 9) < 0) {
                    iVar7 = iVar12;
                    iVar12 = iVar10;
                  }
                  for (iVar10 = 0; iVar11 = (*(code *)PTR_sk_num_006a7f2c)(iVar7), iVar10 < iVar11;
                      iVar10 = iVar10 + 1) {
                    uVar8 = (*(code *)PTR_sk_value_006a7f24)(iVar7,iVar10);
                    iVar11 = (*(code *)PTR_sk_find_006a906c)(iVar12,uVar8);
                    if (-1 < iVar11) break;
                  }
                  iVar12 = (*(code *)PTR_sk_num_006a7f2c)(iVar7);
                  if (iVar10 < iVar12) {
                    uVar19 = param_1[0x30];
                    uVar8 = (*(code *)PTR_sk_value_006a7f24)(iVar7,iVar10);
                    uVar22 = param_1[0x30];
                    *(undefined4 *)(uVar19 + 0xb4) = uVar8;
                    puVar23 = PTR_CRYPTO_add_lock_006a9080;
                    if (*(int *)(uVar22 + 0x9c) == 0) {
                      iVar7 = **(int **)(*(int *)(uVar22 + 0x98) + 8);
                      *(int *)(uVar22 + 0x9c) = iVar7;
                      (*(code *)puVar23)(iVar7 + 0x10,1,3,"s2_clnt.c",0x20a);
                      goto LAB_0047aef4;
                    }
                    ssl2_return_error(param_1,0);
                    uVar16 = 0x44;
                    uVar8 = 0x204;
                  }
                  else {
                    ssl2_return_error(param_1,1);
                    uVar16 = 0xb9;
                    uVar8 = 0x1fb;
                  }
                }
              }
            }
            else {
              uVar22 = param_1[0x15];
              if (*(int *)(uVar22 + 0xe0) == 0) {
                if ((*(int *)(uVar22 + 0xdc) == 0) || ((param_1[0x40] & 0x10) != 0)) {
                  if (*(int *)(uVar22 + 0xe4) == 0) {
LAB_0047aef4:
                    iVar7 = *(int *)(param_1[0x30] + 0x98);
                    if ((iVar7 == 0) || (*(int *)(param_1[0x30] + 0x9c) != **(int **)(iVar7 + 8))) {
                      ssl2_return_error(param_1,0);
                      uVar16 = 0x44;
                      uVar8 = 0x212;
                    }
                    else {
                      uVar22 = param_1[0x15];
                      *(uint *)(uVar22 + 0x88) = *(uint *)(uVar22 + 0xd8);
                      if (*(uint *)(uVar22 + 0xd8) < 0x11) {
                        (*(code *)PTR_memcpy_006aabf4)(uVar22 + 0x8c,pcVar24);
                        goto LAB_0047af40;
                      }
                      ssl2_return_error(param_1,0);
                      uVar16 = 299;
                      uVar8 = 0x21a;
                    }
                  }
                  else {
                    uVar16 = 0xda;
                    uVar8 = 0x19e;
                  }
                }
                else {
                  uVar16 = 0xd9;
                  uVar8 = 0x198;
                }
              }
              else {
                uVar16 = 0xd8;
                uVar8 = 400;
              }
            }
          }
          else {
            uVar16 = 0x128;
            uVar8 = 0x180;
          }
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6d,uVar16,"s2_clnt.c",uVar8);
        iVar7 = -1;
      }
      else {
        if (1 < uVar6 - 0x1030) goto LAB_0047aac8;
        if (uVar6 != 0x1030) {
LAB_0047aa08:
          iVar7 = ssl2_do_write(param_1);
          if (0 < iVar7) {
            param_1[0x11] = 0;
LAB_0047aa20:
            uVar22 = 0x1080;
            param_1[0xd] = 0x1080;
            goto LAB_0047aa30;
          }
          goto LAB_0047a878;
        }
        puVar23 = *(undefined **)(param_1[0xf] + 4);
        iVar7 = (*(code *)PTR_ssl_cipher_get_evp_006a9038)(param_1[0x30],&local_48,local_44,0,0,0);
        if (iVar7 == 0) {
          ssl2_return_error(param_1,1);
          uVar16 = 0xce;
          uVar8 = 0x275;
        }
        else {
          uVar22 = param_1[0x30];
          *puVar23 = 2;
          iVar7 = (**(code **)(param_1[2] + 0x4c))(*(undefined4 *)(uVar22 + 0xb4),puVar23 + 1);
          puVar21 = puVar23 + 1 + iVar7;
          iVar7 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(local_48);
          *(int *)(uVar22 + 4) = iVar7;
          if (iVar7 < 9) {
            if ((iVar7 < 1) ||
               (iVar7 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(uVar22 + 8,iVar7), 0 < iVar7)) {
              iVar7 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(local_48);
              *(int *)(uVar22 + 0x10) = iVar7;
              if (0 < iVar7) {
                if (0x30 < iVar7) {
                  ssl2_return_error(param_1,0);
                  uVar16 = 0x44;
                  uVar8 = 0x295;
                  goto LAB_0047be34;
                }
                iVar12 = (*(code *)PTR_RAND_bytes_006a8d44)(uVar22 + 0x14,iVar7);
                if (iVar12 < 1) goto LAB_0047bb34;
              }
              puVar4 = PTR_memcpy_006aabf4;
              if ((*(uint *)(*(int *)(uVar22 + 0xb4) + 0x24) & 2) == 0) {
                uVar13 = 0;
                if ((*(uint *)(*(int *)(uVar22 + 0xb4) + 0x20) & 2) != 0) {
                  iVar12 = 5;
                  local_64 = 5;
                  goto LAB_0047b020;
                }
                local_68 = 0;
                uVar15 = 0;
                local_64 = iVar7;
              }
              else {
                iVar12 = 8;
                local_64 = 8;
LAB_0047b020:
                local_68 = iVar7 - iVar12;
                if (iVar7 < iVar12) {
                  ssl2_return_error(param_1,0);
                  uVar16 = 0x8b;
                  uVar8 = 0x2a9;
                  goto LAB_0047be34;
                }
                uVar15 = (undefined)((uint)local_68 >> 8);
                uVar13 = (undefined)local_68;
              }
              *puVar21 = uVar15;
              puVar21[1] = uVar13;
              (*(code *)puVar4)(puVar23 + 10,uVar22 + 0x14,local_68);
              uVar8 = 2;
              if (*(int *)(param_1[0x15] + 0xc) == 0) {
                uVar8 = 1;
              }
              if (((*(int *)(uVar22 + 0x98) == 0) || (**(int **)(*(int *)(uVar22 + 0x98) + 8) == 0))
                 || (piVar9 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)(), piVar9 == (int *)0x0
                    )) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbc,0xc0,"s2_clnt.c",0x450);
              }
              else {
                if (*piVar9 == 6) {
                  iVar7 = (*(code *)PTR_RSA_public_encrypt_006a8744)
                                    (local_64,uVar22 + local_68 + 0x14,puVar23 + local_68 + 10,
                                     piVar9[5],uVar8);
                  if (-1 < iVar7) {
                    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar9);
                    if (iVar7 != 0) {
                      puVar21[3] = (char)iVar7;
                      puVar21[2] = (char)((uint)iVar7 >> 8);
                      iVar12 = *(int *)(uVar22 + 4);
                      puVar21[5] = (char)iVar12;
                      puVar21[4] = (char)((uint)iVar12 >> 8);
                      if (iVar12 < 9) {
                        iVar7 = (*(code *)PTR_memcpy_006aabf4)
                                          (puVar23 + local_68 + 10 + iVar7,uVar22 + 8,iVar12);
                        param_1[0x12] = 0;
                        param_1[0xd] = 0x1031;
                        param_1[0x11] = (iVar7 + iVar12) - (int)puVar23;
                        goto LAB_0047aa08;
                      }
                      ssl2_return_error(param_1,0);
                      uVar16 = 0x44;
                      uVar8 = 0x2c6;
                      goto LAB_0047be34;
                    }
                    goto LAB_0047b0e8;
                  }
                  uVar16 = 4;
                  uVar8 = 0x45c;
                }
                else {
                  uVar16 = 0xd1;
                  uVar8 = 0x455;
                }
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbc,uVar16,"s2_clnt.c",uVar8);
                (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar9);
              }
LAB_0047b0e8:
              ssl2_return_error(param_1,0);
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x66,0xd0,"s2_clnt.c",0x2b7);
            }
            goto LAB_0047b120;
          }
          ssl2_return_error(param_1,0);
          uVar16 = 0x44;
          uVar8 = 0x286;
        }
LAB_0047be34:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x66,uVar16,"s2_clnt.c",uVar8);
        iVar7 = -1;
      }
      goto LAB_0047a878;
    }
    if ((int)uVar6 < 0x1010) {
      if ((uVar6 == 0x1000) || (uVar6 == 0x1003)) goto LAB_0047ab00;
      if (uVar6 != 3) goto LAB_0047aac8;
      if (param_1[0xf] != 0) {
        (*(code *)PTR_BUF_MEM_free_006a8594)();
        param_1[0xf] = 0;
      }
      puVar23 = PTR_ssl_update_cache_006a9028;
      param_1[0x11] = 0;
      (*(code *)puVar23)(param_1,1);
      if (param_1[0x1b] == 0) {
        *(int *)(param_1[0x39] + 0x3c) = *(int *)(param_1[0x39] + 0x3c) + 1;
      }
      else {
        uVar6 = param_1[0x39];
        *(int *)(uVar6 + 0x58) = *(int *)(uVar6 + 0x58) + 1;
        *(int *)(uVar6 + 0x3c) = *(int *)(uVar6 + 0x3c) + 1;
      }
      if (pcVar18 == (code *)0x0) {
        iVar7 = 1;
      }
      else {
        (*pcVar18)(param_1,0x20,1);
        iVar7 = 1;
      }
      goto LAB_0047a878;
    }
    param_1[0xc] = 0;
    if (uVar6 == 0x1010) {
      puVar23 = *(undefined **)(param_1[0xf] + 4);
      if ((((uint *)param_1[0x30] == (uint *)0x0) || (*(uint *)param_1[0x30] != *param_1)) &&
         (iVar7 = (*(code *)PTR_ssl_get_new_session_006a904c)(param_1,0), iVar7 == 0)) {
LAB_0047bb34:
        ssl2_return_error(param_1,0);
        iVar7 = -1;
        goto LAB_0047a878;
      }
      puVar21 = PTR_SSL_get_ciphers_006a894c;
      puVar23[1] = 0;
      *puVar23 = 1;
      puVar23[2] = 2;
      uVar8 = (*(code *)puVar21)(param_1);
      iVar7 = (*(code *)PTR_ssl_cipher_list_to_bytes_006a9064)(param_1,uVar8,puVar23 + 9,0);
      puVar5 = (undefined4 *)(puVar23 + 9 + iVar7);
      if (iVar7 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x65,0xb5,"s2_clnt.c",0x241);
        iVar7 = -1;
        goto LAB_0047a878;
      }
      puVar23[4] = (char)iVar7;
      puVar23[3] = (char)((uint)iVar7 >> 8);
      puVar21 = PTR_memcpy_006aabf4;
      iVar7 = *(int *)(param_1[0x30] + 0x44);
      if (iVar7 - 1U < 0x20) {
        puVar23[5] = 0;
        puVar20 = (undefined4 *)((int)puVar5 + iVar7);
        puVar23[6] = (char)iVar7;
        (*(code *)puVar21)(puVar5,param_1[0x30] + 0x48);
      }
      else {
        puVar23[5] = 0;
        puVar23[6] = 0;
        puVar20 = puVar5;
      }
      puVar21 = PTR_RAND_pseudo_bytes_006a8664;
      *(undefined4 *)(param_1[0x15] + 100) = 0x10;
      puVar23[7] = 0;
      puVar23[8] = 0x10;
      iVar7 = (*(code *)puVar21)(param_1[0x15] + 0x68,0x10);
      if (iVar7 < 1) goto LAB_0047b120;
      uVar22 = param_1[0x15];
      uVar17 = *(undefined4 *)(uVar22 + 0x6c);
      uVar16 = *(undefined4 *)(uVar22 + 0x70);
      uVar8 = *(undefined4 *)(uVar22 + 0x74);
      *puVar20 = *(undefined4 *)(uVar22 + 0x68);
      puVar20[1] = uVar17;
      puVar20[2] = uVar16;
      puVar20[3] = uVar8;
      param_1[0xd] = 0x1011;
      param_1[0x11] = (uint)((int)puVar20 + (0x10 - (int)puVar23));
      param_1[0x12] = 0;
    }
    iVar7 = ssl2_do_write(param_1);
    if (iVar7 < 1) goto LAB_0047a878;
    param_1[0x11] = 0;
    uVar22 = 0x1020;
    param_1[0xd] = 0x1020;
  }
  else {
    if (uVar6 == 0x1040) {
LAB_0047afc4:
      puVar23 = *(undefined **)(param_1[0xf] + 4);
      *puVar23 = 3;
      if (0x10 < *(uint *)(param_1[0x15] + 0x88)) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa7,0x44,"s2_clnt.c",0x2df);
        iVar7 = -1;
        goto LAB_0047a878;
      }
      (*(code *)PTR_memcpy_006aabf4)(puVar23 + 1,param_1[0x15] + 0x8c);
      param_1[0xd] = 0x1041;
      iVar7 = *(int *)(param_1[0x15] + 0x88);
      param_1[0x12] = 0;
      param_1[0x11] = iVar7 + 1;
    }
    iVar7 = ssl2_do_write(param_1);
    if (iVar7 < 1) goto LAB_0047a878;
    param_1[0x11] = 0;
    uVar22 = 0x1060;
    param_1[0xd] = 0x1060;
  }
LAB_0047aa30:
  if (pcVar18 == (code *)0x0) goto LAB_0047aaf8;
  goto LAB_0047aa38;
code_r0x0047a9c8:
  if (uVar6 != uVar22) {
LAB_0047aa38:
    param_1[0xd] = uVar6;
    (*pcVar18)(param_1,0x1001,1);
    bVar2 = (int)uVar22 < 0x1042;
    param_1[0xd] = uVar22;
    uVar6 = uVar22;
  }
  goto LAB_0047a7d4;
}

