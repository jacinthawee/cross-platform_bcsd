
int ssl3_check_client_hello(int param_1)

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
  uint *puVar33;
  int *piVar34;
  int *piVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int *piVar39;
  uint in_t2;
  uint in_t3;
  uint in_t4;
  int iVar40;
  ushort *puVar41;
  byte *pbVar42;
  int iVar43;
  int unaff_s5;
  int iVar44;
  code *pcVar45;
  undefined4 uVar46;
  int iStack_78;
  undefined4 uStack_74;
  ushort *puStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  undefined *puStack_5c;
  int local_18;
  int *local_14;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  uVar38 = *(uint *)(param_1 + 0x108);
  piVar39 = &local_18;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar27 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x2180,0x2181,0xffffffff);
  if (local_18 != 0) {
    puVar33 = *(uint **)(param_1 + 0x58);
    iVar27 = 1;
    puVar33[0xd5] = 1;
    if (puVar33[0xd0] == 1) {
      if ((*puVar33 & 0x40) == 0) {
        if (puVar33[0xd2] != 0) {
          (*(code *)PTR_DH_free_006a7508)();
          puVar33 = *(uint **)(param_1 + 0x58);
          puVar33[0xd2] = 0;
        }
        if (puVar33[0xd3] != 0) {
          (*(code *)PTR_EC_KEY_free_006a71d4)();
          puVar33 = *(uint **)(param_1 + 0x58);
          puVar33[0xd3] = 0;
        }
        iVar27 = 2;
        *puVar33 = *puVar33 | 0x40;
      }
      else {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x130,0x15a,"s3_srvr.c");
        iVar27 = -1;
      }
    }
  }
  if (local_14 == *(int **)puStack_5c) {
    return iVar27;
  }
  piVar34 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar26 = PTR___stack_chk_guard_006a9ae8;
  iStack_6c = 0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (piVar34[0xd] == 0x2110) {
    piVar34[0xd] = 0x2111;
  }
  pcVar45 = *(code **)(piVar34[2] + 0x30);
  piVar34[0x43] = 1;
  iStack_60 = param_1;
  iVar27 = (*pcVar45)(piVar34,0x2111,0x2112,1,0x4000,&iStack_78);
  if (iStack_78 == 0) goto LAB_00479570;
  puVar41 = (ushort *)piVar34[0x10];
  piVar34[0x43] = 0;
  if (iVar27 < 0x23) {
    uVar32 = 0xa0;
    uVar46 = 0x3ef;
    puStack_70 = puVar41;
    goto LAB_00479760;
  }
  puStack_70 = puVar41 + 1;
  uVar28 = (uint)*puVar41;
  piVar34[0x44] = uVar28;
  if (*piVar34 == 0xfeff) {
    if (uVar28 < 0xff00) goto LAB_004795c0;
  }
  else if (*piVar34 <= (int)uVar28) {
LAB_004795c0:
    uVar37 = 0;
    uVar36 = 0;
    piVar35 = piVar34;
    uVar28 = (*(code *)PTR_SSL_ctrl_006a7788)(piVar34,0x20);
    if ((uVar28 & 0x2000) != 0) {
      piVar35 = (int *)(uint)((byte *)(*(byte *)(puStack_70 + 0x10) + 0x21) <
                             (byte *)((int)puVar41 + (iVar27 - (int)puStack_70)));
      if (piVar35 == (int *)0x0) {
        uVar32 = 0xa0;
        uVar46 = 0x415;
        goto LAB_00479760;
      }
      if (*(byte *)((int)puStack_70 + (int)(byte *)(*(byte *)(puStack_70 + 0x10) + 0x21)) == 0) {
        iVar27 = 1;
        goto LAB_00479570;
      }
    }
    pbVar42 = (byte *)((int)puVar41 + iVar27);
    uVar28 = (uint)puStack_70 & 3;
    puVar41 = (ushort *)((int)puStack_70 + 0x21);
    iVar40 = piVar34[0x16];
    uVar2 = (uint)(puStack_70 + 2) & 3;
    iVar27 = *(int *)((int)(puStack_70 + 2) - uVar2);
    uVar3 = (uint)(puStack_70 + 4) & 3;
    iVar44 = *(int *)((int)(puStack_70 + 4) - uVar3);
    uVar11 = (uint)(byte *)((int)puStack_70 + 3U) & 3;
    uVar4 = (uint)(puStack_70 + 6) & 3;
    iVar29 = *(int *)((int)(puStack_70 + 6) - uVar4);
    uVar5 = (uint)(puStack_70 + 8) & 3;
    iVar31 = *(int *)((int)(puStack_70 + 8) - uVar5);
    uVar6 = (uint)(puStack_70 + 10) & 3;
    iVar43 = *(int *)((int)(puStack_70 + 10) - uVar6);
    uVar7 = (uint)(puStack_70 + 0xc) & 3;
    iVar9 = *(int *)((int)(puStack_70 + 0xc) - uVar7);
    uVar8 = (uint)(puStack_70 + 0xe) & 3;
    iVar10 = *(int *)((int)(puStack_70 + 0xe) - uVar8);
    uVar12 = (uint)(byte *)((int)puStack_70 + 7U) & 3;
    uVar19 = *(uint *)((byte *)((int)puStack_70 + 7U) + -uVar12);
    uVar13 = (uint)(byte *)((int)puStack_70 + 0xbU) & 3;
    uVar20 = *(uint *)((byte *)((int)puStack_70 + 0xbU) + -uVar13);
    uVar14 = (uint)(byte *)((int)puStack_70 + 0xfU) & 3;
    uVar21 = *(uint *)((byte *)((int)puStack_70 + 0xfU) + -uVar14);
    uVar15 = (uint)(byte *)((int)puStack_70 + 0x13U) & 3;
    uVar22 = *(uint *)((byte *)((int)puStack_70 + 0x13U) + -uVar15);
    uVar16 = (uint)(byte *)((int)puStack_70 + 0x17U) & 3;
    uVar23 = *(uint *)((byte *)((int)puStack_70 + 0x17U) + -uVar16);
    uVar17 = (uint)(byte *)((int)puStack_70 + 0x1bU) & 3;
    uVar24 = *(uint *)((byte *)((int)puStack_70 + 0x1bU) + -uVar17);
    uVar18 = (uint)(byte *)((int)puStack_70 + 0x1fU) & 3;
    uVar25 = *(uint *)((byte *)((int)puStack_70 + 0x1fU) + -uVar18);
    *(uint *)(iVar40 + 0xc0) =
         (*(int *)((int)puStack_70 - uVar28) << uVar28 * 8 | in_t4 & 0xffffffffU >> (4 - uVar28) * 8
         ) & -1 << (uVar11 + 1) * 8 |
         *(uint *)((byte *)((int)puStack_70 + 3U) + -uVar11) >> (3 - uVar11) * 8;
    *(uint *)(iVar40 + 0xc4) =
         (iVar27 << uVar2 * 8 | in_t3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar12 + 1) * 8 |
         uVar19 >> (3 - uVar12) * 8;
    *(uint *)(iVar40 + 200) =
         (iVar44 << uVar3 * 8 | in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar13 + 1) * 8 |
         uVar20 >> (3 - uVar13) * 8;
    *(uint *)(iVar40 + 0xcc) =
         (iVar29 << uVar4 * 8 | (uint)piVar39 & 0xffffffffU >> (4 - uVar4) * 8) &
         -1 << (uVar14 + 1) * 8 | uVar21 >> (3 - uVar14) * 8;
    *(uint *)(iVar40 + 0xd0) =
         (iVar31 << uVar5 * 8 | uVar38 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar15 + 1) * 8 |
         uVar22 >> (3 - uVar15) * 8;
    *(uint *)(iVar40 + 0xd4) =
         (iVar43 << uVar6 * 8 | uVar37 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar16 + 1) * 8 |
         uVar23 >> (3 - uVar16) * 8;
    *(uint *)(iVar40 + 0xd8) =
         (iVar9 << uVar7 * 8 | uVar36 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar17 + 1) * 8 |
         uVar24 >> (3 - uVar17) * 8;
    *(uint *)(iVar40 + 0xdc) =
         (iVar10 << uVar8 * 8 | (uint)piVar35 & 0xffffffffU >> (4 - uVar8) * 8) &
         -1 << (uVar18 + 1) * 8 | uVar25 >> (3 - uVar18) * 8;
    uVar38 = (uint)*(byte *)(puStack_70 + 0x10);
    puStack_70 = puVar41;
    if ((int)pbVar42 - (int)puVar41 < (int)uVar38) {
      uVar32 = 0xa0;
      uVar46 = 0x427;
LAB_00479760:
      uStack_74 = 0x32;
    }
    else {
      if (0x20 < uVar38) {
        uVar32 = 0x9f;
        uVar46 = 0x42d;
        goto LAB_00479760;
      }
      piVar34[0x1b] = 0;
      if ((piVar34[10] == 0) || (-1 < piVar34[0x40] << 0xf)) {
        iVar27 = (*(code *)PTR_ssl_get_prev_session_006a7f3c)(piVar34,puVar41,uVar38,pbVar42);
        if (iVar27 != 1) {
          if (iVar27 == -1) goto LAB_00479544;
          goto LAB_004796d8;
        }
        iVar27 = *piVar34;
        if (iVar27 != *(int *)piVar34[0x30]) goto LAB_004796d8;
        piVar34[0x1b] = 1;
      }
      else {
LAB_004796d8:
        iVar27 = (*(code *)PTR_ssl_get_new_session_006a7f40)(piVar34,1);
        if (iVar27 == 0) goto LAB_00479544;
        iVar27 = *piVar34;
      }
      puVar41 = (ushort *)((int)puStack_70 + uVar38);
      if ((iVar27 == 0xfeff) || (unaff_s5 = 0, iVar27 == 0x100)) {
        puStack_70 = (ushort *)((int)puVar41 + 1);
        if ((int)pbVar42 - (int)puVar41 < 1) {
          uVar32 = 0xa0;
          uVar46 = 0x45f;
          puStack_70 = puVar41;
        }
        else {
          uVar38 = (uint)*(byte *)puVar41;
          if (uVar38 <= (uint)((int)pbVar42 - (int)puStack_70)) {
            uVar28 = (*(code *)PTR_SSL_ctrl_006a7788)(piVar34,0x20,0,0);
            if (((uVar28 & 0x2000) == 0) || (uVar38 == 0)) {
              unaff_s5 = 0;
LAB_004798cc:
              puVar41 = (ushort *)((int)puStack_70 + uVar38);
              goto LAB_00479710;
            }
            (*(code *)PTR_memcpy_006a9aec)(piVar34[0x17] + 0x104,puStack_70,uVar38);
            if (*(code **)(piVar34[0x39] + 0x7c) == (code *)0x0) {
              iVar27 = piVar34[0x17];
              iVar27 = (*(code *)PTR_memcmp_006a9ad0)
                                 (iVar27 + 0x104,iVar27 + 4,*(undefined4 *)(iVar27 + 0x204));
              if (iVar27 == 0) goto LAB_0047991c;
              uVar32 = 0x134;
              uVar46 = 0x488;
              uStack_74 = 0x28;
            }
            else {
              iVar27 = (**(code **)(piVar34[0x39] + 0x7c))(piVar34,piVar34[0x17] + 0x104,uVar38);
              if (iVar27 != 0) {
LAB_0047991c:
                unaff_s5 = 1;
                goto LAB_004798cc;
              }
              uVar32 = 0x134;
              uVar46 = 0x47f;
              uStack_74 = 0x28;
            }
            goto LAB_00479768;
          }
          uVar32 = 0xa0;
          uVar46 = 0x466;
        }
        goto LAB_00479760;
      }
LAB_00479710:
      puStack_70 = puVar41 + 1;
      if ((int)pbVar42 - (int)puVar41 < 2) {
        uVar32 = 0xa0;
        uVar46 = 0x493;
        puStack_70 = puVar41;
        goto LAB_00479760;
      }
      uVar38 = (uint)*puVar41;
      if (uVar38 == 0) {
        uVar32 = 0xb7;
        uVar46 = 0x49a;
        uStack_74 = 0x2f;
      }
      else {
        if ((int)pbVar42 - (int)puStack_70 <= (int)uVar38) {
          uVar32 = 0x9f;
          uVar46 = 0x4a2;
          goto LAB_00479760;
        }
        iVar27 = (*(code *)PTR_ssl_bytes_to_cipher_list_006a7f44)
                           (piVar34,puStack_70,uVar38,&iStack_6c);
        if (iVar27 == 0) goto LAB_00479544;
        puStack_70 = (ushort *)((int)puStack_70 + uVar38);
        puVar41 = puStack_70;
        if (piVar34[0x1b] == 0) {
LAB_00479a0c:
          puStack_70 = (ushort *)((int)puVar41 + 1);
          uVar38 = (uint)*(byte *)puVar41;
          if ((int)pbVar42 - (int)puStack_70 < (int)uVar38) {
            uVar32 = 0x9f;
            uVar46 = 0x4e4;
            goto LAB_00479760;
          }
          if (uVar38 == 0) {
LAB_00479d74:
            puStack_70 = (ushort *)((int)puStack_70 + uVar38);
            uVar32 = 0xbb;
            uVar46 = 0x4f1;
            uStack_74 = 0x32;
          }
          else {
            if (*(byte *)((int)puVar41 + 1) != 0) {
              puVar30 = puVar41 + 1;
              do {
                if (puVar30 == (ushort *)((int)puVar41 + uVar38 + 1)) goto LAB_00479d74;
                bVar1 = *(byte *)puVar30;
                puVar30 = (ushort *)((int)puVar30 + 1);
              } while (bVar1 != 0);
            }
            puStack_70 = (ushort *)((int)puStack_70 + uVar38);
            if ((0x2ff < *piVar34) &&
               (iVar27 = ssl_parse_clienthello_tlsext(piVar34,&puStack_70,pbVar42,&uStack_74),
               iVar27 == 0)) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8a,0xe3,"s3_srvr.c",0x4f9);
              goto LAB_0047952c;
            }
            iVar27 = ssl_check_clienthello_tlsext_early(piVar34);
            if (iVar27 < 1) {
              uVar32 = 0x4fe;
              goto LAB_00479ddc;
            }
            iVar27 = ssl_fill_hello_random(piVar34,1,piVar34[0x16] + 0xa0,0x20);
            if (iVar27 < 1) goto LAB_00479db8;
            if (((piVar34[0x1b] == 0) && (0x300 < *piVar34)) &&
               (pcVar45 = (code *)piVar34[0x5a], pcVar45 != (code *)0x0)) {
              iVar27 = piVar34[0x5b];
              iVar44 = piVar34[0x30];
              iStack_68 = 0;
              *(undefined4 *)(iVar44 + 0x10) = 0x30;
              iVar44 = (*pcVar45)(piVar34,iVar44 + 0x14,iVar44 + 0x10,iStack_6c,&iStack_68,iVar27);
              iVar27 = iStack_6c;
              if (iVar44 != 0) {
                iVar44 = piVar34[0x30];
                piVar34[0x1b] = 1;
                iStack_6c = 0;
                *(int *)(iVar44 + 0xbc) = iVar27;
                *(undefined4 *)(iVar44 + 0xa0) = 0;
                if (iStack_68 == 0) {
                  uVar32 = (*(code *)PTR_SSL_get_ciphers_006a7860)(piVar34);
                  iStack_68 = ssl3_choose_cipher(piVar34,iVar27,uVar32);
                  if (iStack_68 == 0) {
                    uVar32 = 0xc1;
                    uVar46 = 0x528;
                    uStack_74 = 0x28;
                    goto LAB_00479768;
                  }
                  iVar44 = piVar34[0x30];
                }
                iVar27 = piVar34[0x1d];
                *(int *)(iVar44 + 0xb4) = iStack_68;
                if (iVar27 != 0) {
                  (*(code *)PTR_sk_free_006a6e80)();
                }
                if (piVar34[0x1e] != 0) {
                  (*(code *)PTR_sk_free_006a6e80)();
                }
                iVar27 = (*(code *)PTR_sk_dup_006a7f54)(*(undefined4 *)(piVar34[0x30] + 0xbc));
                piVar34[0x1d] = iVar27;
                iVar27 = (*(code *)PTR_sk_dup_006a7f54)(*(undefined4 *)(piVar34[0x30] + 0xbc));
                piVar34[0x1e] = iVar27;
              }
            }
            iVar27 = piVar34[0x30];
            uVar28 = *(uint *)(iVar27 + 0xb0);
            *(undefined4 *)(piVar34[0x16] + 0x38c) = 0;
            if (uVar28 == 0) {
              if (piVar34[0x1b] != 0) {
LAB_00479ec4:
                if (piVar34[0x40] << 1 < 0) {
                  uVar32 = *(undefined4 *)(iVar27 + 0xbc);
                  iVar44 = 0;
                  iVar27 = 0;
                  iVar29 = 0;
                  while (iVar31 = (*(code *)PTR_sk_num_006a6e2c)(uVar32), iVar29 < iVar31) {
                    iVar43 = iVar29 + 1;
                    iVar31 = (*(code *)PTR_sk_value_006a6e24)(uVar32,iVar29);
                    if ((*(uint *)(iVar31 + 0x14) & 0x20) != 0) {
                      iVar44 = iVar31;
                    }
                    iVar29 = iVar43;
                    if ((*(uint *)(iVar31 + 0x20) & 2) != 0) {
                      iVar27 = iVar31;
                    }
                  }
                  if (iVar44 == 0) {
                    if (iVar27 == 0) {
                      *(undefined4 *)(piVar34[0x16] + 0x344) = *(undefined4 *)(piVar34[0x30] + 0xb4)
                      ;
                    }
                    else {
                      *(int *)(piVar34[0x16] + 0x344) = iVar27;
                    }
                  }
                  else {
                    *(int *)(piVar34[0x16] + 0x344) = iVar44;
                  }
                }
                else {
                  *(undefined4 *)(piVar34[0x16] + 0x344) = *(undefined4 *)(iVar27 + 0xb4);
                }
LAB_00479cd4:
                iVar27 = *piVar34;
                if (iVar27 >> 8 != 3) goto LAB_00479e9c;
                if (iVar27 < 0x303) goto LAB_00479e9c;
                if ((piVar34[0x32] & 1U) == 0) goto LAB_00479e9c;
                goto LAB_00479d04;
              }
              if ((-1 < piVar34[0x40] << 0xe) && (*(int *)(piVar34[0x39] + 0x98) != 0)) {
                iVar27 = (*(code *)PTR_sk_num_006a6e2c)();
                for (iVar44 = 0; iVar44 < iVar27; iVar44 = iVar44 + 1) {
                  puVar33 = (uint *)(*(code *)PTR_sk_value_006a6e24)
                                              (*(undefined4 *)(piVar34[0x39] + 0x98),iVar44);
                  if (*puVar33 == (uint)*(byte *)((int)puVar41 + 1)) {
LAB_0047a124:
                    iVar27 = piVar34[0x1b];
                    *(uint **)(piVar34[0x16] + 0x38c) = puVar33;
                    if (iVar27 != 0) goto LAB_00479ec0;
                    iVar27 = piVar34[0x30];
                    goto LAB_00479c6c;
                  }
                  puVar30 = puVar41 + 1;
                  iVar29 = 0;
                  while (iVar29 = iVar29 + 1, iVar29 < (int)uVar38) {
                    bVar1 = *(byte *)puVar30;
                    puVar30 = (ushort *)((int)puVar30 + 1);
                    if (*puVar33 == (uint)bVar1) goto LAB_0047a124;
                  }
                }
                if (piVar34[0x1b] != 0) {
LAB_00479ec0:
                  iVar27 = piVar34[0x30];
                  goto LAB_00479ec4;
                }
                iVar27 = piVar34[0x30];
              }
LAB_00479c70:
              *(uint *)(iVar27 + 0xb0) = uVar28;
              if (*(int *)(iVar27 + 0xbc) != 0) {
                (*(code *)PTR_sk_free_006a6e80)();
                iVar27 = piVar34[0x30];
              }
              iVar44 = iStack_6c;
              *(int *)(iVar27 + 0xbc) = iStack_6c;
              if (iStack_6c == 0) {
                uVar32 = 0x44;
                uVar46 = 0x598;
                uStack_74 = 0x50;
              }
              else {
                iStack_6c = 0;
                uVar32 = (*(code *)PTR_SSL_get_ciphers_006a7860)(piVar34);
                iVar27 = ssl3_choose_cipher(piVar34,iVar44,uVar32);
                if (iVar27 != 0) {
                  *(int *)(piVar34[0x16] + 0x344) = iVar27;
                  goto LAB_00479cd4;
                }
                uVar32 = 0xc1;
                uVar46 = 0x5a0;
                uStack_74 = 0x28;
              }
            }
            else {
              iVar27 = 0;
              if (piVar34[0x40] << 0xe < 0) {
                uVar32 = 0x154;
                uVar46 = 0x549;
                uStack_74 = 0x50;
              }
              else {
                puVar33 = (uint *)0x0;
                for (; iVar44 = (*(code *)PTR_sk_num_006a6e2c)
                                          (*(undefined4 *)(piVar34[0x39] + 0x98)), iVar27 < iVar44;
                    iVar27 = iVar27 + 1) {
                  puVar33 = (uint *)(*(code *)PTR_sk_value_006a6e24)
                                              (*(undefined4 *)(piVar34[0x39] + 0x98),iVar27);
                  if (uVar28 == *puVar33) {
                    iVar27 = piVar34[0x16];
                    *(uint **)(iVar27 + 0x38c) = puVar33;
                    goto LAB_00479c24;
                  }
                }
                iVar27 = piVar34[0x16];
LAB_00479c24:
                if (*(int *)(iVar27 + 0x38c) != 0) {
                  if (uVar28 != *(byte *)((int)puVar41 + 1)) {
                    puVar30 = puVar41 + 1;
                    do {
                      if (puVar30 == (ushort *)((int)puVar41 + uVar38 + 1)) {
                        uVar32 = 0x156;
                        uVar46 = 0x562;
                        uStack_74 = 0x2f;
                        goto LAB_00479768;
                      }
                      bVar1 = *(byte *)puVar30;
                      puVar30 = (ushort *)((int)puVar30 + 1);
                    } while (uVar28 != bVar1);
                  }
                  iVar27 = piVar34[0x30];
                  if (piVar34[0x1b] == 0) {
                    uVar28 = 0;
                    if (puVar33 != (uint *)0x0) {
LAB_00479c6c:
                      uVar28 = *puVar33;
                    }
                    goto LAB_00479c70;
                  }
                  goto LAB_00479ec4;
                }
                uVar32 = 0x155;
                uVar46 = 0x557;
                uStack_74 = 0x50;
              }
            }
          }
        }
        else {
          iVar44 = *(int *)(*(int *)(piVar34[0x30] + 0xb4) + 8);
          for (iVar27 = 0; iVar29 = (*(code *)PTR_sk_num_006a6e2c)(iStack_6c), iVar27 < iVar29;
              iVar27 = iVar27 + 1) {
            iVar29 = (*(code *)PTR_sk_value_006a6e24)(iStack_6c,iVar27);
            puVar41 = puStack_70;
            if (iVar44 == *(int *)(iVar29 + 8)) goto LAB_00479a0c;
          }
          uVar32 = 0xd7;
          uVar46 = 0x4da;
          uStack_74 = 0x2f;
        }
      }
    }
LAB_00479768:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8a,uVar32,"s3_srvr.c",uVar46);
    goto LAB_0047952c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8a,0x10b,"s3_srvr.c",0x3fc);
  if (((piVar34[0x44] >> 8 == 3) && (piVar34[0x23] == 0)) && (piVar34[0x24] == 0)) {
    *piVar34 = piVar34[0x44];
  }
  uStack_74 = 0x46;
LAB_0047952c:
  ssl3_send_alert(piVar34,2,uStack_74);
LAB_00479544:
  do {
    iVar27 = -1;
    piVar34[0xd] = 5;
    while( true ) {
      if (iStack_6c != 0) {
        (*(code *)PTR_sk_free_006a6e80)();
      }
LAB_00479570:
      if (iStack_64 == *(int *)puVar26) {
        return iVar27;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00479e9c:
      iVar27 = ssl3_digest_cached_records(piVar34);
      if (iVar27 == 0) goto LAB_00479db8;
      iVar27 = *piVar34;
LAB_00479d04:
      if ((0x2ff < iVar27) && (iVar27 = ssl_check_clienthello_tlsext_late(piVar34), iVar27 < 1))
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
  uStack_74 = 0x50;
  goto LAB_0047952c;
}

