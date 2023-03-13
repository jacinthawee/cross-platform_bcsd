
int ssl3_get_client_hello(int *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  undefined *puVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  ushort *puVar30;
  int iVar31;
  undefined4 uVar32;
  int *piVar33;
  uint uVar34;
  uint uVar35;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  uint in_t4;
  int iVar36;
  ushort *puVar37;
  byte *pbVar38;
  int iVar39;
  int unaff_s5;
  int iVar40;
  uint *puVar41;
  code *pcVar42;
  undefined4 uVar43;
  int local_40;
  undefined4 local_3c;
  ushort *local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar26 = PTR___stack_chk_guard_006a9ae8;
  local_34 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_1[0xd] == 0x2110) {
    param_1[0xd] = 0x2111;
  }
  pcVar42 = *(code **)(param_1[2] + 0x30);
  param_1[0x43] = 1;
  iVar27 = (*pcVar42)(param_1,0x2111,0x2112,1,0x4000,&local_40);
  if (local_40 == 0) goto LAB_00479570;
  puVar37 = (ushort *)param_1[0x10];
  param_1[0x43] = 0;
  if (iVar27 < 0x23) {
    uVar32 = 0xa0;
    uVar43 = 0x3ef;
    local_38 = puVar37;
    goto LAB_00479760;
  }
  local_38 = puVar37 + 1;
  uVar28 = (uint)*puVar37;
  param_1[0x44] = uVar28;
  if (*param_1 == 0xfeff) {
    if (uVar28 < 0xff00) goto LAB_004795c0;
  }
  else if (*param_1 <= (int)uVar28) {
LAB_004795c0:
    uVar35 = 0;
    uVar34 = 0;
    piVar33 = param_1;
    uVar28 = (*(code *)PTR_SSL_ctrl_006a7788)(param_1,0x20);
    if ((uVar28 & 0x2000) != 0) {
      piVar33 = (int *)(uint)((byte *)(*(byte *)(local_38 + 0x10) + 0x21) <
                             (byte *)((int)puVar37 + (iVar27 - (int)local_38)));
      if (piVar33 == (int *)0x0) {
        uVar32 = 0xa0;
        uVar43 = 0x415;
        goto LAB_00479760;
      }
      if (*(byte *)((int)local_38 + (int)(byte *)(*(byte *)(local_38 + 0x10) + 0x21)) == 0) {
        iVar27 = 1;
        goto LAB_00479570;
      }
    }
    pbVar38 = (byte *)((int)puVar37 + iVar27);
    uVar28 = (uint)local_38 & 3;
    puVar37 = (ushort *)((int)local_38 + 0x21);
    iVar36 = param_1[0x16];
    uVar2 = (uint)(local_38 + 2) & 3;
    iVar27 = *(int *)((int)(local_38 + 2) - uVar2);
    uVar3 = (uint)(local_38 + 4) & 3;
    iVar40 = *(int *)((int)(local_38 + 4) - uVar3);
    uVar11 = (uint)(byte *)((int)local_38 + 3U) & 3;
    uVar4 = (uint)(local_38 + 6) & 3;
    iVar29 = *(int *)((int)(local_38 + 6) - uVar4);
    uVar5 = (uint)(local_38 + 8) & 3;
    iVar31 = *(int *)((int)(local_38 + 8) - uVar5);
    uVar6 = (uint)(local_38 + 10) & 3;
    iVar39 = *(int *)((int)(local_38 + 10) - uVar6);
    uVar7 = (uint)(local_38 + 0xc) & 3;
    iVar9 = *(int *)((int)(local_38 + 0xc) - uVar7);
    uVar8 = (uint)(local_38 + 0xe) & 3;
    iVar10 = *(int *)((int)(local_38 + 0xe) - uVar8);
    uVar12 = (uint)(byte *)((int)local_38 + 7U) & 3;
    uVar19 = *(uint *)((byte *)((int)local_38 + 7U) + -uVar12);
    uVar13 = (uint)(byte *)((int)local_38 + 0xbU) & 3;
    uVar20 = *(uint *)((byte *)((int)local_38 + 0xbU) + -uVar13);
    uVar14 = (uint)(byte *)((int)local_38 + 0xfU) & 3;
    uVar21 = *(uint *)((byte *)((int)local_38 + 0xfU) + -uVar14);
    uVar15 = (uint)(byte *)((int)local_38 + 0x13U) & 3;
    uVar22 = *(uint *)((byte *)((int)local_38 + 0x13U) + -uVar15);
    uVar16 = (uint)(byte *)((int)local_38 + 0x17U) & 3;
    uVar23 = *(uint *)((byte *)((int)local_38 + 0x17U) + -uVar16);
    uVar17 = (uint)(byte *)((int)local_38 + 0x1bU) & 3;
    uVar24 = *(uint *)((byte *)((int)local_38 + 0x1bU) + -uVar17);
    uVar18 = (uint)(byte *)((int)local_38 + 0x1fU) & 3;
    uVar25 = *(uint *)((byte *)((int)local_38 + 0x1fU) + -uVar18);
    *(uint *)(iVar36 + 0xc0) =
         (*(int *)((int)local_38 - uVar28) << uVar28 * 8 | in_t4 & 0xffffffffU >> (4 - uVar28) * 8)
         & -1 << (uVar11 + 1) * 8 |
         *(uint *)((byte *)((int)local_38 + 3U) + -uVar11) >> (3 - uVar11) * 8;
    *(uint *)(iVar36 + 0xc4) =
         (iVar27 << uVar2 * 8 | in_t3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar12 + 1) * 8 |
         uVar19 >> (3 - uVar12) * 8;
    *(uint *)(iVar36 + 200) =
         (iVar40 << uVar3 * 8 | in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar13 + 1) * 8 |
         uVar20 >> (3 - uVar13) * 8;
    *(uint *)(iVar36 + 0xcc) =
         (iVar29 << uVar4 * 8 | in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar14 + 1) * 8 |
         uVar21 >> (3 - uVar14) * 8;
    *(uint *)(iVar36 + 0xd0) =
         (iVar31 << uVar5 * 8 | in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar15 + 1) * 8 |
         uVar22 >> (3 - uVar15) * 8;
    *(uint *)(iVar36 + 0xd4) =
         (iVar39 << uVar6 * 8 | uVar35 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar16 + 1) * 8 |
         uVar23 >> (3 - uVar16) * 8;
    *(uint *)(iVar36 + 0xd8) =
         (iVar9 << uVar7 * 8 | uVar34 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar17 + 1) * 8 |
         uVar24 >> (3 - uVar17) * 8;
    *(uint *)(iVar36 + 0xdc) =
         (iVar10 << uVar8 * 8 | (uint)piVar33 & 0xffffffffU >> (4 - uVar8) * 8) &
         -1 << (uVar18 + 1) * 8 | uVar25 >> (3 - uVar18) * 8;
    uVar28 = (uint)*(byte *)(local_38 + 0x10);
    local_38 = puVar37;
    if ((int)pbVar38 - (int)puVar37 < (int)uVar28) {
      uVar32 = 0xa0;
      uVar43 = 0x427;
LAB_00479760:
      local_3c = 0x32;
    }
    else {
      if (0x20 < uVar28) {
        uVar32 = 0x9f;
        uVar43 = 0x42d;
        goto LAB_00479760;
      }
      param_1[0x1b] = 0;
      if ((param_1[10] == 0) || (-1 < param_1[0x40] << 0xf)) {
        iVar27 = (*(code *)PTR_ssl_get_prev_session_006a7f3c)(param_1,puVar37,uVar28,pbVar38);
        if (iVar27 != 1) {
          if (iVar27 == -1) goto LAB_00479544;
          goto LAB_004796d8;
        }
        iVar27 = *param_1;
        if (iVar27 != *(int *)param_1[0x30]) goto LAB_004796d8;
        param_1[0x1b] = 1;
      }
      else {
LAB_004796d8:
        iVar27 = (*(code *)PTR_ssl_get_new_session_006a7f40)(param_1,1);
        if (iVar27 == 0) goto LAB_00479544;
        iVar27 = *param_1;
      }
      puVar37 = (ushort *)((int)local_38 + uVar28);
      if ((iVar27 == 0xfeff) || (unaff_s5 = 0, iVar27 == 0x100)) {
        local_38 = (ushort *)((int)puVar37 + 1);
        if ((int)pbVar38 - (int)puVar37 < 1) {
          uVar32 = 0xa0;
          uVar43 = 0x45f;
          local_38 = puVar37;
        }
        else {
          uVar28 = (uint)*(byte *)puVar37;
          if (uVar28 <= (uint)((int)pbVar38 - (int)local_38)) {
            uVar34 = (*(code *)PTR_SSL_ctrl_006a7788)(param_1,0x20,0,0);
            if (((uVar34 & 0x2000) == 0) || (uVar28 == 0)) {
              unaff_s5 = 0;
LAB_004798cc:
              puVar37 = (ushort *)((int)local_38 + uVar28);
              goto LAB_00479710;
            }
            (*(code *)PTR_memcpy_006a9aec)(param_1[0x17] + 0x104,local_38,uVar28);
            if (*(code **)(param_1[0x39] + 0x7c) == (code *)0x0) {
              iVar27 = param_1[0x17];
              iVar27 = (*(code *)PTR_memcmp_006a9ad0)
                                 (iVar27 + 0x104,iVar27 + 4,*(undefined4 *)(iVar27 + 0x204));
              if (iVar27 == 0) goto LAB_0047991c;
              uVar32 = 0x134;
              uVar43 = 0x488;
              local_3c = 0x28;
            }
            else {
              iVar27 = (**(code **)(param_1[0x39] + 0x7c))(param_1,param_1[0x17] + 0x104,uVar28);
              if (iVar27 != 0) {
LAB_0047991c:
                unaff_s5 = 1;
                goto LAB_004798cc;
              }
              uVar32 = 0x134;
              uVar43 = 0x47f;
              local_3c = 0x28;
            }
            goto LAB_00479768;
          }
          uVar32 = 0xa0;
          uVar43 = 0x466;
        }
        goto LAB_00479760;
      }
LAB_00479710:
      local_38 = puVar37 + 1;
      if ((int)pbVar38 - (int)puVar37 < 2) {
        uVar32 = 0xa0;
        uVar43 = 0x493;
        local_38 = puVar37;
        goto LAB_00479760;
      }
      uVar28 = (uint)*puVar37;
      if (uVar28 == 0) {
        uVar32 = 0xb7;
        uVar43 = 0x49a;
        local_3c = 0x2f;
      }
      else {
        if ((int)pbVar38 - (int)local_38 <= (int)uVar28) {
          uVar32 = 0x9f;
          uVar43 = 0x4a2;
          goto LAB_00479760;
        }
        iVar27 = (*(code *)PTR_ssl_bytes_to_cipher_list_006a7f44)(param_1,local_38,uVar28,&local_34)
        ;
        if (iVar27 == 0) goto LAB_00479544;
        local_38 = (ushort *)((int)local_38 + uVar28);
        puVar37 = local_38;
        if (param_1[0x1b] == 0) {
LAB_00479a0c:
          local_38 = (ushort *)((int)puVar37 + 1);
          uVar28 = (uint)*(byte *)puVar37;
          if ((int)pbVar38 - (int)local_38 < (int)uVar28) {
            uVar32 = 0x9f;
            uVar43 = 0x4e4;
            goto LAB_00479760;
          }
          if (uVar28 == 0) {
LAB_00479d74:
            local_38 = (ushort *)((int)local_38 + uVar28);
            uVar32 = 0xbb;
            uVar43 = 0x4f1;
            local_3c = 0x32;
          }
          else {
            if (*(byte *)((int)puVar37 + 1) != 0) {
              puVar30 = puVar37 + 1;
              do {
                if (puVar30 == (ushort *)((int)puVar37 + uVar28 + 1)) goto LAB_00479d74;
                bVar1 = *(byte *)puVar30;
                puVar30 = (ushort *)((int)puVar30 + 1);
              } while (bVar1 != 0);
            }
            local_38 = (ushort *)((int)local_38 + uVar28);
            if ((0x2ff < *param_1) &&
               (iVar27 = ssl_parse_clienthello_tlsext(param_1,&local_38,pbVar38,&local_3c),
               iVar27 == 0)) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8a,0xe3,"s3_srvr.c",0x4f9);
              goto LAB_0047952c;
            }
            iVar27 = ssl_check_clienthello_tlsext_early(param_1);
            if (iVar27 < 1) {
              uVar32 = 0x4fe;
              goto LAB_00479ddc;
            }
            iVar27 = ssl_fill_hello_random(param_1,1,param_1[0x16] + 0xa0,0x20);
            if (iVar27 < 1) goto LAB_00479db8;
            if (((param_1[0x1b] == 0) && (0x300 < *param_1)) &&
               (pcVar42 = (code *)param_1[0x5a], pcVar42 != (code *)0x0)) {
              iVar27 = param_1[0x5b];
              iVar40 = param_1[0x30];
              local_30 = 0;
              *(undefined4 *)(iVar40 + 0x10) = 0x30;
              iVar40 = (*pcVar42)(param_1,iVar40 + 0x14,iVar40 + 0x10,local_34,&local_30,iVar27);
              iVar27 = local_34;
              if (iVar40 != 0) {
                iVar40 = param_1[0x30];
                param_1[0x1b] = 1;
                local_34 = 0;
                *(int *)(iVar40 + 0xbc) = iVar27;
                *(undefined4 *)(iVar40 + 0xa0) = 0;
                if (local_30 == 0) {
                  uVar32 = (*(code *)PTR_SSL_get_ciphers_006a7860)(param_1);
                  local_30 = ssl3_choose_cipher(param_1,iVar27,uVar32);
                  if (local_30 == 0) {
                    uVar32 = 0xc1;
                    uVar43 = 0x528;
                    local_3c = 0x28;
                    goto LAB_00479768;
                  }
                  iVar40 = param_1[0x30];
                }
                iVar27 = param_1[0x1d];
                *(int *)(iVar40 + 0xb4) = local_30;
                if (iVar27 != 0) {
                  (*(code *)PTR_sk_free_006a6e80)();
                }
                if (param_1[0x1e] != 0) {
                  (*(code *)PTR_sk_free_006a6e80)();
                }
                iVar27 = (*(code *)PTR_sk_dup_006a7f54)(*(undefined4 *)(param_1[0x30] + 0xbc));
                param_1[0x1d] = iVar27;
                iVar27 = (*(code *)PTR_sk_dup_006a7f54)(*(undefined4 *)(param_1[0x30] + 0xbc));
                param_1[0x1e] = iVar27;
              }
            }
            iVar27 = param_1[0x30];
            uVar34 = *(uint *)(iVar27 + 0xb0);
            *(undefined4 *)(param_1[0x16] + 0x38c) = 0;
            if (uVar34 == 0) {
              if (param_1[0x1b] != 0) {
LAB_00479ec4:
                if (param_1[0x40] << 1 < 0) {
                  uVar32 = *(undefined4 *)(iVar27 + 0xbc);
                  iVar40 = 0;
                  iVar27 = 0;
                  iVar29 = 0;
                  while (iVar31 = (*(code *)PTR_sk_num_006a6e2c)(uVar32), iVar29 < iVar31) {
                    iVar39 = iVar29 + 1;
                    iVar31 = (*(code *)PTR_sk_value_006a6e24)(uVar32,iVar29);
                    if ((*(uint *)(iVar31 + 0x14) & 0x20) != 0) {
                      iVar40 = iVar31;
                    }
                    iVar29 = iVar39;
                    if ((*(uint *)(iVar31 + 0x20) & 2) != 0) {
                      iVar27 = iVar31;
                    }
                  }
                  if (iVar40 == 0) {
                    if (iVar27 == 0) {
                      *(undefined4 *)(param_1[0x16] + 0x344) = *(undefined4 *)(param_1[0x30] + 0xb4)
                      ;
                    }
                    else {
                      *(int *)(param_1[0x16] + 0x344) = iVar27;
                    }
                  }
                  else {
                    *(int *)(param_1[0x16] + 0x344) = iVar40;
                  }
                }
                else {
                  *(undefined4 *)(param_1[0x16] + 0x344) = *(undefined4 *)(iVar27 + 0xb4);
                }
LAB_00479cd4:
                iVar27 = *param_1;
                if (iVar27 >> 8 != 3) goto LAB_00479e9c;
                if (iVar27 < 0x303) goto LAB_00479e9c;
                if ((param_1[0x32] & 1U) == 0) goto LAB_00479e9c;
                goto LAB_00479d04;
              }
              if ((-1 < param_1[0x40] << 0xe) && (*(int *)(param_1[0x39] + 0x98) != 0)) {
                iVar27 = (*(code *)PTR_sk_num_006a6e2c)();
                for (iVar40 = 0; iVar40 < iVar27; iVar40 = iVar40 + 1) {
                  puVar41 = (uint *)(*(code *)PTR_sk_value_006a6e24)
                                              (*(undefined4 *)(param_1[0x39] + 0x98),iVar40);
                  if (*puVar41 == (uint)*(byte *)((int)puVar37 + 1)) {
LAB_0047a124:
                    iVar27 = param_1[0x1b];
                    *(uint **)(param_1[0x16] + 0x38c) = puVar41;
                    if (iVar27 != 0) goto LAB_00479ec0;
                    iVar27 = param_1[0x30];
                    goto LAB_00479c6c;
                  }
                  puVar30 = puVar37 + 1;
                  iVar29 = 0;
                  while (iVar29 = iVar29 + 1, iVar29 < (int)uVar28) {
                    bVar1 = *(byte *)puVar30;
                    puVar30 = (ushort *)((int)puVar30 + 1);
                    if (*puVar41 == (uint)bVar1) goto LAB_0047a124;
                  }
                }
                if (param_1[0x1b] != 0) {
LAB_00479ec0:
                  iVar27 = param_1[0x30];
                  goto LAB_00479ec4;
                }
                iVar27 = param_1[0x30];
              }
LAB_00479c70:
              *(uint *)(iVar27 + 0xb0) = uVar34;
              if (*(int *)(iVar27 + 0xbc) != 0) {
                (*(code *)PTR_sk_free_006a6e80)();
                iVar27 = param_1[0x30];
              }
              iVar40 = local_34;
              *(int *)(iVar27 + 0xbc) = local_34;
              if (local_34 == 0) {
                uVar32 = 0x44;
                uVar43 = 0x598;
                local_3c = 0x50;
              }
              else {
                local_34 = 0;
                uVar32 = (*(code *)PTR_SSL_get_ciphers_006a7860)(param_1);
                iVar27 = ssl3_choose_cipher(param_1,iVar40,uVar32);
                if (iVar27 != 0) {
                  *(int *)(param_1[0x16] + 0x344) = iVar27;
                  goto LAB_00479cd4;
                }
                uVar32 = 0xc1;
                uVar43 = 0x5a0;
                local_3c = 0x28;
              }
            }
            else {
              iVar27 = 0;
              if (param_1[0x40] << 0xe < 0) {
                uVar32 = 0x154;
                uVar43 = 0x549;
                local_3c = 0x50;
              }
              else {
                puVar41 = (uint *)0x0;
                for (; iVar40 = (*(code *)PTR_sk_num_006a6e2c)
                                          (*(undefined4 *)(param_1[0x39] + 0x98)), iVar27 < iVar40;
                    iVar27 = iVar27 + 1) {
                  puVar41 = (uint *)(*(code *)PTR_sk_value_006a6e24)
                                              (*(undefined4 *)(param_1[0x39] + 0x98),iVar27);
                  if (uVar34 == *puVar41) {
                    iVar27 = param_1[0x16];
                    *(uint **)(iVar27 + 0x38c) = puVar41;
                    goto LAB_00479c24;
                  }
                }
                iVar27 = param_1[0x16];
LAB_00479c24:
                if (*(int *)(iVar27 + 0x38c) != 0) {
                  if (uVar34 != *(byte *)((int)puVar37 + 1)) {
                    puVar30 = puVar37 + 1;
                    do {
                      if (puVar30 == (ushort *)((int)puVar37 + uVar28 + 1)) {
                        uVar32 = 0x156;
                        uVar43 = 0x562;
                        local_3c = 0x2f;
                        goto LAB_00479768;
                      }
                      bVar1 = *(byte *)puVar30;
                      puVar30 = (ushort *)((int)puVar30 + 1);
                    } while (uVar34 != bVar1);
                  }
                  iVar27 = param_1[0x30];
                  if (param_1[0x1b] == 0) {
                    uVar34 = 0;
                    if (puVar41 != (uint *)0x0) {
LAB_00479c6c:
                      uVar34 = *puVar41;
                    }
                    goto LAB_00479c70;
                  }
                  goto LAB_00479ec4;
                }
                uVar32 = 0x155;
                uVar43 = 0x557;
                local_3c = 0x50;
              }
            }
          }
        }
        else {
          iVar40 = *(int *)(*(int *)(param_1[0x30] + 0xb4) + 8);
          for (iVar27 = 0; iVar29 = (*(code *)PTR_sk_num_006a6e2c)(local_34), iVar27 < iVar29;
              iVar27 = iVar27 + 1) {
            iVar29 = (*(code *)PTR_sk_value_006a6e24)(local_34,iVar27);
            puVar37 = local_38;
            if (iVar40 == *(int *)(iVar29 + 8)) goto LAB_00479a0c;
          }
          uVar32 = 0xd7;
          uVar43 = 0x4da;
          local_3c = 0x2f;
        }
      }
    }
LAB_00479768:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8a,uVar32,"s3_srvr.c",uVar43);
    goto LAB_0047952c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8a,0x10b,"s3_srvr.c",0x3fc);
  if (((param_1[0x44] >> 8 == 3) && (param_1[0x23] == 0)) && (param_1[0x24] == 0)) {
    *param_1 = param_1[0x44];
  }
  local_3c = 0x46;
LAB_0047952c:
  ssl3_send_alert(param_1,2,local_3c);
LAB_00479544:
  do {
    iVar27 = -1;
    param_1[0xd] = 5;
    while( true ) {
      if (local_34 != 0) {
        (*(code *)PTR_sk_free_006a6e80)();
      }
LAB_00479570:
      if (local_2c == *(int *)puVar26) {
        return iVar27;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00479e9c:
      iVar27 = ssl3_digest_cached_records(param_1);
      if (iVar27 == 0) goto LAB_00479db8;
      iVar27 = *param_1;
LAB_00479d04:
      if ((0x2ff < iVar27) && (iVar27 = ssl_check_clienthello_tlsext_late(param_1), iVar27 < 1))
      break;
      iVar27 = 2;
      if (unaff_s5 == 0) {
        iVar27 = 1;
      }
    }
    uVar32 = 0x5d6;
LAB_00479ddc:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8a,0xe2,"s3_srvr.c",uVar32);
  } while( true );
LAB_00479db8:
  local_3c = 0x50;
  goto LAB_0047952c;
}

