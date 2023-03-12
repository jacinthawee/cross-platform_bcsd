
int ssl2_accept(uint *param_1)

{
  bool bVar1;
  ushort uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined2 uVar10;
  int iVar8;
  undefined4 uVar9;
  char cVar11;
  uint uVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  code *pcVar16;
  int iVar17;
  uint uVar18;
  char *pcVar19;
  undefined *puVar20;
  int iVar21;
  undefined *puVar22;
  undefined4 local_50;
  int local_4c;
  int local_48;
  undefined4 *local_44 [6];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_50 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_50,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar4 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  pcVar16 = (code *)param_1[0x34];
  *puVar4 = 0;
  puVar20 = PTR_SSL_state_006a88f4;
  if (pcVar16 == (code *)0x0) {
    pcVar16 = *(code **)(param_1[0x39] + 0x9c);
  }
  param_1[7] = param_1[7] + 1;
  uVar5 = (*(code *)puVar20)(param_1);
  if (((uVar5 & 0x3000) == 0) ||
     (uVar5 = (*(code *)PTR_SSL_state_006a88f4)(param_1), (uVar5 & 0x4000) != 0)) {
    (*(code *)PTR_SSL_clear_006a88d4)(param_1);
  }
  if (param_1[0x26] == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7a,0xb3,"s2_srvr.c",0xa9);
    iVar6 = -1;
    goto LAB_004788d8;
  }
  *puVar4 = 0;
  bVar1 = (int)param_1[0xd] < 0x2042;
  uVar5 = param_1[0xd];
  do {
    while (puVar20 = PTR_RAND_pseudo_bytes_006a8664, bVar1) {
      if ((int)uVar5 < 0x2040) {
        if ((int)uVar5 < 0x2013) {
          if ((int)uVar5 < 0x2010) {
            if ((uVar5 == 0x2000) || (uVar5 == 0x2003)) goto LAB_00478e2c;
            if (uVar5 == 3) {
              (*(code *)PTR_BUF_MEM_free_006a8594)(param_1[0xf]);
              (*(code *)PTR_ssl_free_wbio_buffer_006a9024)(param_1);
              param_1[0xf] = 0;
              puVar20 = PTR_ssl_update_cache_006a9028;
              param_1[0x11] = 0;
              (*(code *)puVar20)(param_1,2);
              *(int *)(param_1[0x39] + 0x48) = *(int *)(param_1[0x39] + 0x48) + 1;
              if (pcVar16 == (code *)0x0) {
                iVar6 = 1;
                param_1[7] = param_1[7] - 1;
                goto LAB_004788d8;
              }
              (*pcVar16)(param_1,0x20,1);
              iVar6 = 1;
              param_1[7] = param_1[7] - 1;
              goto LAB_004788b4;
            }
            goto LAB_00478dac;
          }
          param_1[0xc] = 0;
          if (uVar5 == 0x2010) {
            param_1[0x43] = 1;
            pcVar19 = *(char **)(param_1[0xf] + 4);
            param_1[0xd] = 0x2011;
LAB_0047946c:
            iVar6 = ssl2_read(param_1,pcVar19 + param_1[0x11],9 - param_1[0x11]);
            if (iVar6 < (int)(9 - param_1[0x11])) {
LAB_0047949c:
              iVar6 = ssl2_part_read(param_1,0x6a,iVar6);
              if (iVar6 < 1) {
                uVar5 = param_1[7];
                goto LAB_00478dd8;
              }
LAB_00479198:
              param_1[0x11] = 0;
              uVar18 = 0x2020;
              param_1[0xd] = 0x2020;
              goto joined_r0x00478d80;
            }
            param_1[0x11] = 9;
            if (*pcVar19 == '\x01') {
              if ((int)(uint)*(ushort *)(pcVar19 + 1) < (int)*param_1) {
                *param_1 = (uint)*(ushort *)(pcVar19 + 1);
              }
              uVar18 = param_1[0x15];
              *(uint *)(uVar18 + 0x110) = (uint)*(ushort *)(pcVar19 + 3);
              *(uint *)(uVar18 + 0x114) = (uint)*(ushort *)(pcVar19 + 5);
              uVar2 = *(ushort *)(pcVar19 + 7);
              *(uint *)(uVar18 + 100) = (uint)uVar2;
              if (uVar2 - 0x10 < 0x11) {
                param_1[0xd] = 0x2012;
                pcVar19 = *(char **)(param_1[0xf] + 4);
                goto LAB_004790b4;
              }
              ssl2_return_error(param_1,0);
              uVar13 = 0x9e;
              uVar9 = 0x237;
            }
            else if (*pcVar19 == '\0') {
              uVar13 = 200;
              uVar9 = 0x22b;
            }
            else {
              ssl2_return_error(param_1,0);
              uVar13 = 0xd4;
              uVar9 = 0x228;
            }
          }
          else {
            pcVar19 = *(char **)(param_1[0xf] + 4);
            if (uVar5 == 0x2011) goto LAB_0047946c;
            uVar18 = param_1[0x15];
LAB_004790b4:
            uVar18 = *(int *)(uVar18 + 0x110) + *(int *)(uVar18 + 100) + 9 +
                     *(int *)(uVar18 + 0x114);
            if (uVar18 < 0x4000) {
              iVar17 = uVar18 - param_1[0x11];
              iVar6 = ssl2_read(param_1,pcVar19 + param_1[0x11],iVar17);
              if (iVar17 != iVar6) goto LAB_0047949c;
              if ((code *)param_1[0x19] != (code *)0x0) {
                (*(code *)param_1[0x19])(0,*param_1,0,pcVar19,uVar18,param_1,param_1[0x1a]);
              }
              pcVar19 = pcVar19 + 9;
              iVar6 = *(int *)(param_1[0x15] + 0x114);
              if (iVar6 == 0) {
LAB_00479140:
                iVar6 = (*(code *)PTR_ssl_get_new_session_006a904c)(param_1,1);
                if (iVar6 == 0) {
LAB_0047a124:
                  ssl2_return_error(param_1,0);
                  iVar6 = -1;
                  goto LAB_00478dd4;
                }
                if (param_1[0x1b] == 0) {
                  iVar6 = (*(code *)PTR_ssl_bytes_to_cipher_list_006a9068)
                                    (param_1,pcVar19,*(undefined4 *)(param_1[0x15] + 0x110),
                                     param_1[0x30] + 0xbc);
                  if ((iVar6 == 0) ||
                     ((iVar21 = (*(code *)PTR_SSL_get_ciphers_006a894c)(param_1), iVar17 = iVar6,
                      (int)(param_1[0x40] << 9) < 0 &&
                      (iVar17 = (*(code *)PTR_sk_dup_006a9074)(iVar21), iVar21 = iVar6, iVar17 == 0)
                      ))) {
                    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6a,0x41,"s2_srvr.c",0x2b5);
                    iVar6 = 0;
                    goto LAB_00478dd4;
                  }
                  iVar6 = 0;
                  while (iVar8 = (*(code *)PTR_sk_num_006a7f2c)(iVar17), iVar6 < iVar8) {
                    uVar9 = (*(code *)PTR_sk_value_006a7f24)(iVar17,iVar6);
                    iVar8 = (*(code *)PTR_sk_find_006a906c)(iVar21,uVar9);
                    if (iVar8 < 0) {
                      (*(code *)PTR_sk_delete_006a8398)(iVar17,iVar6);
                    }
                    else {
                      iVar6 = iVar6 + 1;
                    }
                  }
                  if ((int)(param_1[0x40] << 9) < 0) {
                    (*(code *)PTR_sk_free_006a7f80)(*(undefined4 *)(param_1[0x30] + 0xbc));
                    *(int *)(param_1[0x30] + 0xbc) = iVar17;
                  }
                }
LAB_00479164:
                uVar18 = param_1[0x15];
                if (*(uint *)(uVar18 + 100) < 0x21) {
                  (*(code *)PTR_memcpy_006aabf4)
                            (uVar18 + 0x68,
                             pcVar19 + *(int *)(uVar18 + 0x110) + *(int *)(uVar18 + 0x114));
                  goto LAB_00479198;
                }
                ssl2_return_error(param_1,0);
                uVar13 = 0x44;
                uVar9 = 0x2af;
              }
              else if (iVar6 == 0x10) {
                iVar6 = (*(code *)PTR_ssl_get_prev_session_006a9050)
                                  (param_1,pcVar19 + *(int *)(param_1[0x15] + 0x110),0x10,0);
                if (iVar6 == 1) {
                  param_1[0x1b] = 1;
                  goto LAB_00479164;
                }
                if (iVar6 == -1) goto LAB_0047a124;
                if (param_1[0x26] != 0) goto LAB_00479140;
                ssl2_return_error(param_1,2);
                uVar13 = 0xb3;
                uVar9 = 0x272;
              }
              else {
                ssl2_return_error(param_1,0);
                uVar13 = 0x7d;
                uVar9 = 0x254;
              }
            }
            else {
              ssl2_return_error(param_1,0);
              uVar13 = 0x128;
              uVar9 = 0x243;
            }
          }
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6a,uVar13,"s2_srvr.c",uVar9);
          iVar6 = -1;
          goto LAB_00478dd4;
        }
        if ((int)uVar5 < 0x2020) goto LAB_00478dac;
        if (0x2021 < (int)uVar5) {
          if (1 < uVar5 - 0x2030) goto LAB_00478dac;
          puVar7 = (uint *)param_1[0xf];
          pcVar19 = (char *)puVar7[1];
          if (uVar5 == 0x2030) {
            iVar6 = ssl2_read(param_1,pcVar19 + param_1[0x11],10 - param_1[0x11]);
            if ((int)(10 - param_1[0x11]) <= iVar6) {
              param_1[0x11] = 10;
              if (*pcVar19 == '\x02') {
                iVar6 = ssl2_get_cipher_by_char(pcVar19 + 1);
                if (iVar6 == 0) {
                  ssl2_return_error(param_1,1);
                  uVar13 = 0xb9;
                  uVar9 = 0x18e;
                }
                else {
                  uVar18 = param_1[0x30];
                  uVar12 = param_1[0x15];
                  *(int *)(uVar18 + 0xb4) = iVar6;
                  *(uint *)(uVar12 + 0xe8) = (uint)*(ushort *)(pcVar19 + 4);
                  *(uint *)(uVar12 + 0xec) = (uint)*(ushort *)(pcVar19 + 6);
                  if (*(ushort *)(pcVar19 + 8) < 9) {
                    puVar7 = (uint *)param_1[0xf];
                    *(uint *)(uVar18 + 4) = (uint)*(ushort *)(pcVar19 + 8);
                    param_1[0xd] = 0x2031;
                    pcVar19 = (char *)puVar7[1];
                    goto LAB_00478b48;
                  }
                  ssl2_return_error(param_1,0);
                  uVar13 = 0x11c;
                  uVar9 = 0x19a;
                }
              }
              else if (*pcVar19 == '\0') {
                uVar13 = 200;
                uVar9 = 0x186;
              }
              else {
                ssl2_return_error(param_1,0);
                uVar13 = 0xd4;
                uVar9 = 0x183;
              }
              goto LAB_00479340;
            }
LAB_0047940c:
            iVar6 = ssl2_part_read(param_1,0x6b,iVar6);
            if (0 < iVar6) {
              param_1[0x11] = 0;
              goto LAB_00479084;
            }
            goto LAB_00478dd4;
          }
LAB_00478b48:
          if (*puVar7 < 0x3fff) {
            ssl2_return_error(param_1,0);
            uVar13 = 0x44;
            uVar9 = 0x1a6;
          }
          else {
            iVar17 = *(int *)(param_1[0x30] + 4);
            uVar18 = iVar17 + *(int *)(param_1[0x15] + 0xe8) + 10 + *(int *)(param_1[0x15] + 0xec);
            if (uVar18 < 0x4000) {
              iVar21 = uVar18 - param_1[0x11];
              iVar6 = ssl2_read(param_1,pcVar19 + param_1[0x11],iVar21);
              if (iVar21 != iVar6) goto LAB_0047940c;
              if ((code *)param_1[0x19] != (code *)0x0) {
                (*(code *)param_1[0x19])(0,*param_1,0,pcVar19,uVar18,param_1,param_1[0x1a]);
              }
              pcVar19 = pcVar19 + 10;
              (*(code *)PTR_memcpy_006aabf4)
                        (param_1[0x30] + 8,
                         pcVar19 + *(int *)(param_1[0x15] + 0xe8) + *(int *)(param_1[0x15] + 0xec),
                         iVar17);
              piVar14 = *(int **)(param_1[0x26] + 0x34);
              if (piVar14 == (int *)0x0) {
                ssl2_return_error(param_1,0);
                uVar13 = 0xbd;
                uVar9 = 0x1be;
                goto LAB_00479340;
              }
              uVar18 = param_1[0x15];
              uVar9 = 2;
              if (*(int *)(uVar18 + 0xc) == 0) {
                uVar9 = 1;
              }
              if (*piVar14 == 6) {
                iVar6 = (*(code *)PTR_RSA_private_decrypt_006a8734)
                                  (*(undefined4 *)(uVar18 + 0xec),pcVar19 + *(int *)(uVar18 + 0xe8),
                                   pcVar19 + *(int *)(uVar18 + 0xe8),piVar14[5],uVar9);
                if (iVar6 < 0) {
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbb,4,"s2_srvr.c",0x473);
                }
              }
              else {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbb,0xd1,"s2_srvr.c",0x46b);
                iVar6 = -1;
              }
              uVar18 = *(uint *)(*(int *)(param_1[0x30] + 0xb4) + 0x20);
              iVar17 = (*(code *)PTR_ssl_cipher_get_evp_006a9038)
                                 (param_1[0x30],&local_48,local_44,0,0,0);
              if (iVar17 == 0) {
                ssl2_return_error(param_1,1);
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6b,0xce,"s2_srvr.c",0x1ca);
                iVar6 = 0;
                goto LAB_00478dd4;
              }
              if ((*(uint *)(*(int *)(param_1[0x30] + 0xb4) + 0x24) & 2) == 0) {
                uVar18 = uVar18 & 2;
                if (iVar6 < 0) {
                  (*(code *)PTR_ERR_clear_error_006a7fe0)();
                  if (uVar18 == 0) {
LAB_00478ce0:
                    iVar6 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(local_48);
                    iVar17 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(pcVar19,iVar6);
                    if (0 < iVar17) goto LAB_00479058;
                  }
                  else {
                    iVar6 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(pcVar19,5);
                    if (0 < iVar6) {
                      iVar17 = 5;
                      goto LAB_0047904c;
                    }
                  }
LAB_00478d0c:
                  iVar6 = 0;
                  goto LAB_00478dd4;
                }
                if (uVar18 != 0) {
                  iVar17 = 5;
                  iVar21 = 5;
                  goto LAB_00479018;
                }
                iVar17 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(local_48);
                if (iVar17 != iVar6) {
                  (*(code *)PTR_ERR_clear_error_006a7fe0)();
                  goto LAB_00478ce0;
                }
              }
              else {
                iVar17 = 8;
                if (iVar6 < 0) {
                  (*(code *)PTR_ERR_clear_error_006a7fe0)();
                  iVar6 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(pcVar19,8);
                  if (iVar6 < 1) goto LAB_00478d0c;
                  iVar17 = 8;
LAB_0047904c:
                  uVar18 = param_1[0x15];
                }
                else {
                  iVar21 = 8;
LAB_00479018:
                  if ((iVar6 != iVar21) ||
                     (iVar8 = *(int *)(param_1[0x15] + 0xe8),
                     iVar6 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(local_48),
                     iVar17 + iVar8 != iVar6)) {
                    (*(code *)PTR_ERR_clear_error_006a7fe0)();
                    iVar6 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(pcVar19,iVar21);
                    if (iVar6 < 1) goto LAB_00478d0c;
                    goto LAB_0047904c;
                  }
                  uVar18 = param_1[0x15];
                }
                iVar6 = iVar17 + *(int *)(uVar18 + 0xe8);
              }
LAB_00479058:
              puVar20 = PTR_memcpy_006aabf4;
              if (iVar6 < 0x31) {
                uVar18 = param_1[0x30];
                *(int *)(uVar18 + 0x10) = iVar6;
                (*(code *)puVar20)(uVar18 + 0x14,pcVar19,iVar6);
                param_1[0x11] = 0;
                goto LAB_00479084;
              }
              ssl2_return_error(param_1,0);
              uVar13 = 0x44;
              uVar9 = 0x201;
            }
            else {
              ssl2_return_error(param_1,0);
              uVar13 = 0x128;
              uVar9 = 0x1ae;
            }
          }
LAB_00479340:
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x6b,uVar13,"s2_srvr.c",uVar9);
LAB_00479354:
          iVar6 = -1;
LAB_00478dd4:
          while( true ) {
            uVar5 = param_1[7];
LAB_00478dd8:
            param_1[7] = uVar5 - 1;
            if (pcVar16 != (code *)0x0) {
LAB_004788b4:
              (*pcVar16)(param_1,0x2002,iVar6);
            }
LAB_004788d8:
            if (local_2c == *(int *)puVar3) break;
            (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0047a23c:
            ssl2_return_error(param_1,4);
            uVar13 = 199;
            uVar9 = 0x3dd;
LAB_00478ad0:
            iVar21 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x71,uVar13,"s2_srvr.c",uVar9);
            iVar17 = 0;
            iVar6 = -1;
LAB_00478af0:
            (*(code *)PTR_sk_free_006a7f80)(iVar21);
            (*(code *)PTR_X509_free_006a7f90)(iVar17);
          }
          return iVar6;
        }
        if (uVar5 == 0x2020) {
          puVar20 = *(undefined **)(param_1[0xf] + 4);
          local_44[0] = (undefined4 *)(puVar20 + 0xb);
          *puVar20 = 4;
          uVar18 = param_1[0x1b];
          puVar20[1] = (char)uVar18;
          if (uVar18 == 0) {
            uVar18 = param_1[0x30];
            if (*(int *)(uVar18 + 0x98) != 0) {
              (*(code *)PTR_ssl_sess_cert_free_006a905c)();
              uVar18 = param_1[0x30];
            }
            uVar9 = (*(code *)PTR_ssl_sess_cert_new_006a9060)();
            uVar12 = param_1[0x30];
            *(undefined4 *)(uVar18 + 0x98) = uVar9;
            puVar22 = PTR_i2d_X509_006a87d4;
            if (*(int *)(uVar12 + 0x98) == 0) {
              uVar13 = 0x41;
              uVar9 = 0x2d0;
LAB_004799c0:
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x72,uVar13,"s2_srvr.c",uVar9);
              iVar6 = -1;
              goto LAB_00478dd4;
            }
            if (param_1[0x26] == 0) goto LAB_00479998;
            puVar20[2] = 1;
            puVar20[3] = (char)(*param_1 >> 8);
            puVar20[4] = (char)*param_1;
            uVar10 = (*(code *)puVar22)(*(undefined4 *)(param_1[0x26] + 0x30),0);
            puVar20[6] = (char)uVar10;
            puVar20[5] = (char)((ushort)uVar10 >> 8);
            (*(code *)PTR_i2d_X509_006a87d4)(*(undefined4 *)(param_1[0x26] + 0x30),local_44);
            iVar6 = (*(code *)PTR_ssl_cipher_list_to_bytes_006a9064)
                              (param_1,*(undefined4 *)(param_1[0x30] + 0xbc),local_44[0],0);
            local_44[0] = (undefined4 *)((int)local_44[0] + iVar6);
            puVar20[7] = (char)((uint)iVar6 >> 8);
            puVar20[8] = (char)iVar6;
          }
          else {
            if (param_1[0x26] == 0) {
LAB_00479998:
              ssl2_return_error(param_1,2);
              uVar13 = 0xb4;
              uVar9 = 0x2f5;
              goto LAB_004799c0;
            }
            puVar20[2] = 0;
            puVar20[3] = (char)(*param_1 >> 8);
            uVar18 = *param_1;
            puVar20[5] = 0;
            puVar20[6] = 0;
            puVar20[7] = 0;
            puVar20[4] = (char)uVar18;
            puVar20[8] = 0;
          }
          puVar22 = PTR_RAND_pseudo_bytes_006a8664;
          puVar20[9] = 0;
          puVar20[10] = 0x10;
          uVar18 = param_1[0x15];
          *(undefined4 *)(uVar18 + 0x88) = 0x10;
          iVar6 = (*(code *)puVar22)(uVar18 + 0x8c,0x10);
          if (iVar6 < 1) goto LAB_00479354;
          uVar18 = param_1[0x15];
          uVar15 = *(undefined4 *)(uVar18 + 0x90);
          uVar13 = *(undefined4 *)(uVar18 + 0x94);
          uVar9 = *(undefined4 *)(uVar18 + 0x98);
          *local_44[0] = *(undefined4 *)(uVar18 + 0x8c);
          local_44[0][1] = uVar15;
          local_44[0][2] = uVar13;
          local_44[0][3] = uVar9;
          param_1[0xd] = 0x2021;
          local_44[0] = local_44[0] + 4;
          iVar6 = *(int *)(param_1[0xf] + 4);
          param_1[0x12] = 0;
          param_1[0x11] = (int)local_44[0] - iVar6;
        }
        if ((param_1[0x1b] != 0) &&
           (iVar6 = (*(code *)PTR_ssl_init_wbio_buffer_006a9048)(param_1,1), iVar6 == 0))
        goto LAB_00479354;
        iVar6 = ssl2_do_write(param_1);
        if (iVar6 < 1) goto LAB_00478dd4;
        param_1[0x11] = 0;
        if (param_1[0x1b] == 0) {
          uVar18 = 0x2030;
          param_1[0xd] = 0x2030;
          goto joined_r0x00478d80;
        }
LAB_00479084:
        uVar18 = 0x2080;
        param_1[0xd] = 0x2080;
      }
      else {
        if (uVar5 == 0x2040) {
          puVar20 = *(undefined **)(param_1[0xf] + 4);
          *puVar20 = 5;
          if (0x20 < *(uint *)(param_1[0x15] + 100)) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf0,0x44,"s2_srvr.c",0x370);
            iVar6 = -1;
            goto LAB_00478dd4;
          }
          (*(code *)PTR_memcpy_006aabf4)(puVar20 + 1,param_1[0x15] + 0x68);
          param_1[0xd] = 0x2041;
          iVar6 = *(int *)(param_1[0x15] + 100);
          param_1[0x12] = 0;
          param_1[0x11] = iVar6 + 1;
        }
        iVar6 = ssl2_do_write(param_1);
        if (iVar6 < 1) goto LAB_00478dd4;
        param_1[0x11] = 0;
        if (param_1[0x1b] == 0) {
          uVar18 = 0x2050;
          param_1[0xd] = 0x2050;
        }
        else {
          uVar18 = 0x2042;
          param_1[0xd] = 0x2042;
        }
      }
joined_r0x00478d80:
      if (pcVar16 == (code *)0x0) {
        bVar1 = uVar18 < 0x2042;
        uVar5 = uVar18;
      }
      else if (uVar18 != uVar5) goto LAB_00478a08;
    }
    if ((int)uVar5 < 0x2062) {
      if (0x205f < (int)uVar5) {
        if (uVar5 == 0x2060) {
          puVar20 = *(undefined **)(param_1[0xf] + 4);
          *puVar20 = 6;
          if (0x20 < *(uint *)(param_1[0x30] + 0x44)) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xef,0x44,"s2_srvr.c",0x388);
            iVar6 = -1;
            goto LAB_00478dd4;
          }
          (*(code *)PTR_memcpy_006aabf4)(puVar20 + 1,param_1[0x30] + 0x48);
          param_1[0xd] = 0x2061;
          iVar6 = *(int *)(param_1[0x30] + 0x44);
          param_1[0x12] = 0;
          param_1[0x11] = iVar6 + 1;
        }
        iVar6 = ssl2_do_write(param_1);
        if (0 < iVar6) {
          param_1[0x11] = 0;
          uVar18 = 3;
          param_1[0xd] = 3;
          goto joined_r0x00478d80;
        }
        goto LAB_00478dd4;
      }
      if (uVar5 != 0x2042) {
        if (1 < uVar5 - 0x2050) goto LAB_00478dac;
        pcVar19 = *(char **)(param_1[0xf] + 4);
        if (uVar5 == 0x2050) {
          iVar6 = ssl2_read(param_1,pcVar19 + param_1[0x11],1 - param_1[0x11]);
          if (iVar6 < (int)(1 - param_1[0x11])) {
LAB_00479430:
            iVar6 = ssl2_part_read(param_1,0x69,iVar6);
            if (iVar6 < 1) {
              uVar5 = param_1[7];
              goto LAB_00478dd8;
            }
LAB_004789e8:
            param_1[0x11] = 0;
            uVar18 = 0x2070;
            param_1[0xd] = 0x2070;
            goto joined_r0x00478d80;
          }
          param_1[0x11] = iVar6 + param_1[0x11];
          if (*pcVar19 == '\x03') {
            param_1[0xd] = 0x2051;
            goto LAB_0047895c;
          }
          if (*pcVar19 == '\0') {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x69,200,"s2_srvr.c",0x342);
            uVar9 = ssl2_read(param_1,pcVar19 + param_1[0x11],3 - param_1[0x11]);
            iVar6 = ssl2_part_read(param_1,0x6e,uVar9);
            if (iVar6 < 1) {
              uVar5 = param_1[7];
              goto LAB_00478dd8;
            }
            goto LAB_004789e8;
          }
          ssl2_return_error(param_1,0);
          uVar13 = 0xd4;
          uVar9 = 0x33e;
        }
        else {
LAB_0047895c:
          iVar17 = *(uint *)(param_1[0x15] + 0x88) + 1;
          if (*(uint *)(param_1[0x15] + 0x88) < 0x11) {
            iVar21 = iVar17 - param_1[0x11];
            iVar6 = ssl2_read(param_1,pcVar19 + param_1[0x11],iVar21);
            if (iVar6 < iVar21) goto LAB_00479430;
            if ((code *)param_1[0x19] != (code *)0x0) {
              (*(code *)param_1[0x19])(0,*param_1,0,pcVar19,iVar17,param_1,param_1[0x1a]);
            }
            iVar6 = (*(code *)PTR_memcmp_006aabd8)
                              (pcVar19 + 1,param_1[0x15] + 0x8c,
                               *(undefined4 *)(param_1[0x15] + 0x88));
            if (iVar6 == 0) goto LAB_004789e8;
            ssl2_return_error(param_1,0);
            uVar13 = 0x8f;
            uVar9 = 0x360;
          }
          else {
            ssl2_return_error(param_1,0);
            uVar13 = 0x44;
            uVar9 = 0x350;
          }
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x69,uVar13,"s2_srvr.c",uVar9);
        iVar6 = -1;
        goto LAB_00478dd4;
      }
      iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_1[4],3,0,0);
      puVar20 = PTR_BIO_ctrl_006a7f18;
      if (0 < iVar6) {
        param_1[6] = 2;
        iVar6 = (*(code *)puVar20)(param_1[4],0xb,0,0);
        if (iVar6 < 1) goto LAB_00479354;
        param_1[6] = 1;
      }
      uVar18 = 0x2050;
      uVar12 = (*(code *)PTR_BIO_pop_006a8ab4)(param_1[4]);
      param_1[4] = uVar12;
      param_1[0xd] = 0x2050;
      if (pcVar16 != (code *)0x0) goto LAB_00478a08;
      uVar5 = 0x2050;
      goto LAB_00478e20;
    }
    if (uVar5 != 0x2080) {
      if ((int)uVar5 < 0x2081) {
        if (uVar5 - 0x2070 < 4) {
          if (((param_1[0x32] & 1) != 0) &&
             ((*(int *)(param_1[0x30] + 0x9c) == 0 || ((param_1[0x32] & 4) == 0)))) {
            uVar18 = param_1[0x15];
            puVar4 = (undefined4 *)(uVar18 + 0xf0);
            if (uVar5 == 0x2070) {
              puVar22 = *(undefined **)(param_1[0xf] + 4);
              *puVar22 = 7;
              puVar22[1] = 1;
              iVar6 = (*(code *)puVar20)(puVar4,0x10);
              if (iVar6 < 1) goto LAB_00479354;
              uVar15 = *(undefined4 *)(uVar18 + 0xf4);
              uVar13 = *(undefined4 *)(uVar18 + 0xf8);
              uVar9 = *(undefined4 *)(uVar18 + 0xfc);
              *(undefined4 *)(puVar22 + 2) = *puVar4;
              *(undefined4 *)(puVar22 + 6) = uVar15;
              *(undefined4 *)(puVar22 + 10) = uVar13;
              *(undefined4 *)(puVar22 + 0xe) = uVar9;
              param_1[0x12] = 0;
              param_1[0xd] = 0x2071;
              param_1[0x11] = 0x12;
LAB_00479c3c:
              iVar6 = ssl2_do_write(param_1);
              if (iVar6 < 1) {
                iVar21 = 0;
                iVar17 = 0;
                goto LAB_00478af0;
              }
              param_1[0x11] = 0;
              iVar6 = 6;
              uVar18 = 0;
              param_1[0xd] = 0x2072;
LAB_00479c64:
              pcVar19 = *(char **)(param_1[0xf] + 4);
              iVar6 = ssl2_read(param_1,pcVar19 + uVar18,iVar6);
              if ((int)(3 - param_1[0x11]) <= iVar6) {
                uVar18 = iVar6 + param_1[0x11];
                param_1[0x11] = uVar18;
                if ((int)uVar18 < 3) {
                  cVar11 = *pcVar19;
                }
                else {
                  cVar11 = *pcVar19;
                  if (cVar11 == '\0') {
                    if (pcVar19[1] == '\x02') {
                      if ((code *)param_1[0x19] != (code *)0x0) {
                        (*(code *)param_1[0x19])(0,*param_1,0,pcVar19 + 2,3,param_1,param_1[0x1a]);
                      }
                      if ((param_1[0x32] & 2) != 0) goto LAB_0047a23c;
                      (*(code *)PTR_sk_free_006a7f80)(0);
                      (*(code *)PTR_X509_free_006a7f90)(0);
                      param_1[0x11] = 0;
                      goto LAB_00478d7c;
                    }
                    iVar6 = 3;
                    param_1[0x11] = uVar18 - 3;
                    goto LAB_00479a08;
                  }
                }
                if ((cVar11 != '\b') || ((int)uVar18 < 6)) {
                  ssl2_return_error(param_1,0);
                  uVar13 = 0xdb;
                  uVar9 = 0x3e6;
                  goto LAB_00478ad0;
                }
                if (uVar18 != 6) {
                  uVar13 = 0x44;
                  uVar9 = 0x3eb;
                  goto LAB_00478ad0;
                }
                if (pcVar19[1] != '\x01') {
                  ssl2_return_error(param_1,6);
                  uVar13 = 0x75;
                  uVar9 = 0x3f5;
                  goto LAB_00478ad0;
                }
                uVar18 = param_1[0x15];
                *(uint *)(uVar18 + 0x118) = (uint)*(ushort *)(pcVar19 + 2);
                *(uint *)(uVar18 + 0x11c) = (uint)*(ushort *)(pcVar19 + 4);
                param_1[0xd] = 0x2073;
                goto LAB_00478aa0;
              }
LAB_00479a08:
              iVar6 = ssl2_part_read(param_1,0x71,iVar6);
              iVar21 = 0;
              iVar17 = 0;
            }
            else {
              if (uVar5 == 0x2071) goto LAB_00479c3c;
              if (uVar5 == 0x2072) {
                uVar18 = param_1[0x11];
                iVar6 = 6 - uVar18;
                goto LAB_00479c64;
              }
LAB_00478aa0:
              uVar18 = *(int *)(uVar18 + 0x118) + *(int *)(uVar18 + 0x11c) + 6;
              if (0x3fff < uVar18) {
                uVar13 = 0x128;
                uVar9 = 0x402;
                goto LAB_00478ad0;
              }
              iVar17 = *(int *)(param_1[0xf] + 4);
              iVar21 = uVar18 - param_1[0x11];
              iVar6 = ssl2_read(param_1,iVar17 + param_1[0x11],iVar21);
              if (iVar6 < iVar21) goto LAB_00479a08;
              if ((code *)param_1[0x19] != (code *)0x0) {
                (*(code *)param_1[0x19])(0,*param_1,0,iVar17,uVar18,param_1,param_1[0x1a]);
              }
              local_4c = iVar17 + 6;
              iVar17 = (*(code *)PTR_d2i_X509_006a9070)
                                 (0,&local_4c,*(undefined4 *)(param_1[0x15] + 0x118));
              if (iVar17 == 0) {
                iVar21 = 0;
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x71,0xb,"s2_srvr.c",0x414);
LAB_00479904:
                ssl2_return_error(param_1,4);
                iVar6 = -1;
                goto LAB_00478af0;
              }
              iVar21 = (*(code *)PTR_sk_new_null_006a80a4)();
              if ((iVar21 == 0) ||
                 (iVar6 = (*(code *)PTR_sk_push_006a80a8)(iVar21,iVar17), iVar6 == 0)) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x71,0x41,"s2_srvr.c",0x41a);
                goto LAB_00479904;
              }
              iVar6 = (*(code *)PTR_ssl_verify_cert_chain_006a9078)(param_1,iVar21);
              if (iVar6 < 1) goto LAB_00479904;
              (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(local_44);
              iVar6 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)
                                (local_44,*(undefined4 *)(param_1[0x39] + 0x88),0);
              if (((iVar6 == 0) ||
                  (iVar6 = (*(code *)PTR_EVP_DigestUpdate_006a8674)
                                     (local_44,param_1[0x15] + 0xa0,
                                      *(undefined4 *)(param_1[0x15] + 0x9c)), iVar6 == 0)) ||
                 (iVar6 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(local_44,puVar4,0x10), iVar6 == 0
                 )) goto LAB_00479904;
              uVar9 = (*(code *)PTR_i2d_X509_006a87d4)(*(undefined4 *)(param_1[0x26] + 0x30),0);
              iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar9,"s2_srvr.c",0x42e);
              if (iVar6 == 0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x71,0x41,"s2_srvr.c",0x431);
                goto LAB_00479904;
              }
              local_48 = iVar6;
              uVar9 = (*(code *)PTR_i2d_X509_006a87d4)
                                (*(undefined4 *)(param_1[0x26] + 0x30),&local_48);
              iVar8 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(local_44,iVar6,uVar9);
              if (iVar8 == 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                goto LAB_00479904;
              }
              (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
              iVar6 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar17);
              if (iVar6 == 0) {
                iVar6 = -1;
              }
              else {
                iVar8 = (*(code *)PTR_EVP_VerifyFinal_006a907c)
                                  (local_44,local_4c,*(undefined4 *)(param_1[0x15] + 0x11c),iVar6);
                (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar6);
                (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(local_44);
                if (iVar8 < 1) {
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x71,0x68,"s2_srvr.c",0x44f);
                  goto LAB_00479904;
                }
                uVar18 = param_1[0x30];
                if (*(int *)(uVar18 + 0x9c) != 0) {
                  (*(code *)PTR_X509_free_006a7f90)();
                  uVar18 = param_1[0x30];
                }
                puVar20 = PTR_CRYPTO_add_lock_006a9080;
                *(int *)(uVar18 + 0x9c) = iVar17;
                (*(code *)puVar20)(iVar17 + 0x10,1,3,"s2_srvr.c",0x448);
                iVar6 = 1;
                *(uint *)(param_1[0x30] + 0xa0) = param_1[0x3b];
              }
            }
            (*(code *)PTR_sk_free_006a7f80)(iVar21);
            (*(code *)PTR_X509_free_006a7f90)(iVar17);
            if (iVar6 < 1) goto LAB_00478dd4;
            param_1[0x11] = 0;
          }
LAB_00478d7c:
          uVar18 = 0x2060;
          param_1[0xd] = 0x2060;
          goto joined_r0x00478d80;
        }
      }
      else if ((uVar5 == 0x4000) || (uVar5 == 0x6000)) {
LAB_00478e2c:
        param_1[9] = 1;
        if (pcVar16 != (code *)0x0) {
          (*pcVar16)(param_1,0x10,1);
        }
        uVar18 = param_1[0xf];
        *param_1 = 2;
        param_1[1] = 0x2000;
        if ((uVar18 == 0) && (uVar18 = (*(code *)PTR_BUF_MEM_new_006a859c)(), uVar18 == 0)) {
          iVar6 = -1;
          goto LAB_00478dd4;
        }
        iVar6 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(uVar18,0x3fff);
        if (iVar6 != 0) {
          param_1[0xf] = uVar18;
          uVar18 = 0x2010;
          param_1[0x11] = 0;
          *(int *)(param_1[0x39] + 0x40) = *(int *)(param_1[0x39] + 0x40) + 1;
          param_1[8] = (uint)ssl2_accept;
          param_1[0xd] = 0x2010;
          goto joined_r0x00478d80;
        }
        goto LAB_00479354;
      }
LAB_00478dac:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7a,0xff,"s2_srvr.c",0x157);
      iVar6 = -1;
      goto LAB_00478dd4;
    }
    iVar6 = ssl2_enc_init(param_1,0);
    if (iVar6 == 0) goto LAB_00479354;
    uVar18 = 0x2040;
    *(undefined4 *)(param_1[0x15] + 4) = 0;
    param_1[0xd] = 0x2040;
    if (pcVar16 == (code *)0x0) {
      uVar5 = 0x2040;
LAB_00478e20:
      bVar1 = uVar18 < 0x2042;
    }
    else {
LAB_00478a08:
      param_1[0xd] = uVar5;
      (*pcVar16)(param_1,0x2001,1);
      bVar1 = uVar18 < 0x2042;
      param_1[0xd] = uVar18;
      uVar5 = uVar18;
    }
  } while( true );
}

