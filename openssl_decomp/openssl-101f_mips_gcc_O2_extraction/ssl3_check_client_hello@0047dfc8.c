
uint ssl3_check_client_hello(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
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
  uint uVar27;
  uint uVar28;
  int iVar29;
  ushort *puVar30;
  int iVar31;
  int iVar32;
  undefined4 uVar33;
  uint *puVar34;
  int *piVar35;
  undefined4 *puVar36;
  uint uVar37;
  undefined4 uVar38;
  uint uVar39;
  uint uVar40;
  int *piVar41;
  uint in_t2;
  uint in_t3;
  int iVar42;
  int iVar43;
  ushort *puVar44;
  uint unaff_s4;
  int iVar45;
  undefined4 *puVar46;
  code *pcVar47;
  int iStack_78;
  undefined4 uStack_74;
  undefined4 *puStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  undefined *puStack_5c;
  int local_18;
  int *local_14;
  
  puStack_5c = PTR___stack_chk_guard_006aabf0;
  uVar40 = *(uint *)(param_1 + 0x108);
  piVar41 = &local_18;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar27 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x2180,0x2181,0xffffffff);
  if (local_18 != 0) {
    puVar34 = *(uint **)(param_1 + 0x58);
    uVar27 = 1;
    puVar34[0xd5] = 1;
    if (puVar34[0xd0] == 1) {
      if ((*puVar34 & 0x40) == 0) {
        if (puVar34[0xd2] != 0) {
          (*(code *)PTR_DH_free_006a8604)();
          puVar34 = *(uint **)(param_1 + 0x58);
          puVar34[0xd2] = 0;
        }
        if (puVar34[0xd3] != 0) {
          (*(code *)PTR_EC_KEY_free_006a82d8)();
          puVar34 = *(uint **)(param_1 + 0x58);
          puVar34[0xd3] = 0;
        }
        uVar27 = 2;
        *puVar34 = *puVar34 | 0x40;
      }
      else {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x130,0x15a,"s3_srvr.c");
        uVar27 = 0xffffffff;
      }
    }
  }
  if (local_14 == *(int **)puStack_5c) {
    return uVar27;
  }
  piVar35 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar26 = PTR___stack_chk_guard_006aabf0;
  iStack_6c = 0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (piVar35[0xd] == 0x2110) {
    piVar35[0xd] = 0x2111;
  }
  pcVar47 = *(code **)(piVar35[2] + 0x30);
  piVar35[0x43] = 1;
  iStack_60 = param_1;
  uVar28 = (*pcVar47)(piVar35,0x2111,0x2112,1,0x4000,&iStack_78);
  uVar27 = uVar28;
  if (iStack_78 == 0) goto LAB_0047e25c;
  puVar44 = (ushort *)piVar35[0x10];
  piVar35[0x43] = 0;
  puStack_70 = (undefined4 *)(puVar44 + 1);
  uVar27 = (uint)*puVar44;
  piVar35[0x44] = uVar27;
  if (*piVar35 == 0xfeff) {
    if (uVar27 < 0xff00) goto LAB_0047e2ac;
  }
  else if (*piVar35 <= (int)uVar27) {
LAB_0047e2ac:
    uVar39 = 0;
    uVar37 = 0;
    uVar27 = (*(code *)PTR_SSL_ctrl_006a8878)(piVar35,0x20);
    uVar27 = uVar27 & 0x2000;
    if ((uVar27 != 0) &&
       (uVar27 = 1, *(byte *)((int)puStack_70 + *(byte *)(puStack_70 + 8) + 0x21) == 0))
    goto LAB_0047e25c;
    puVar36 = (undefined4 *)((int)puStack_70 + 0x21);
    iVar42 = piVar35[0x16];
    uVar3 = (uint)(puStack_70 + 1) & 3;
    iVar29 = *(int *)((int)(puStack_70 + 1) - uVar3);
    uVar4 = (uint)(puStack_70 + 2) & 3;
    iVar45 = *(int *)((int)(puStack_70 + 2) - uVar4);
    uVar5 = (uint)(puStack_70 + 3) & 3;
    iVar31 = *(int *)((int)(puStack_70 + 3) - uVar5);
    uVar6 = (uint)(puStack_70 + 4) & 3;
    iVar32 = *(int *)((int)(puStack_70 + 4) - uVar6);
    uVar7 = (uint)(puStack_70 + 5) & 3;
    iVar43 = *(int *)((int)(puStack_70 + 5) - uVar7);
    uVar8 = (uint)(puStack_70 + 6) & 3;
    iVar10 = *(int *)((int)(puStack_70 + 6) - uVar8);
    uVar9 = (uint)(puStack_70 + 7) & 3;
    iVar11 = *(int *)((int)(puStack_70 + 7) - uVar9);
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
    *(undefined4 *)(iVar42 + 0xc0) = *puStack_70;
    *(uint *)(iVar42 + 0xc4) =
         (iVar29 << uVar3 * 8 | in_t3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar12 + 1) * 8 |
         uVar19 >> (3 - uVar12) * 8;
    *(uint *)(iVar42 + 200) =
         (iVar45 << uVar4 * 8 | in_t2 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar13 + 1) * 8 |
         uVar20 >> (3 - uVar13) * 8;
    *(uint *)(iVar42 + 0xcc) =
         (iVar31 << uVar5 * 8 | (uint)piVar41 & 0xffffffffU >> (4 - uVar5) * 8) &
         -1 << (uVar14 + 1) * 8 | uVar21 >> (3 - uVar14) * 8;
    *(uint *)(iVar42 + 0xd0) =
         (iVar32 << uVar6 * 8 | uVar40 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar15 + 1) * 8 |
         uVar22 >> (3 - uVar15) * 8;
    *(uint *)(iVar42 + 0xd4) =
         (iVar43 << uVar7 * 8 | uVar39 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar16 + 1) * 8 |
         uVar23 >> (3 - uVar16) * 8;
    *(uint *)(iVar42 + 0xd8) =
         (iVar10 << uVar8 * 8 | uVar37 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar17 + 1) * 8 |
         uVar24 >> (3 - uVar17) * 8;
    *(uint *)(iVar42 + 0xdc) =
         (iVar11 << uVar9 * 8 | uVar27 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar18 + 1) * 8 |
         uVar25 >> (3 - uVar18) * 8;
    uVar40 = (uint)*(byte *)(puStack_70 + 8);
    piVar35[0x1b] = 0;
    puStack_70 = puVar36;
    if ((piVar35[10] == 0) || (-1 < piVar35[0x40] << 0xf)) {
      iVar29 = (*(code *)PTR_ssl_get_prev_session_006a9050)
                         (piVar35,puVar36,uVar40,(int)puVar44 + uVar28);
      if (iVar29 != 1) {
        if (iVar29 == -1) goto LAB_0047e4f0;
        goto LAB_0047e3c4;
      }
      piVar35[0x1b] = 1;
    }
    else {
LAB_0047e3c4:
      iVar29 = (*(code *)PTR_ssl_get_new_session_006a904c)(piVar35,1);
      if (iVar29 == 0) {
LAB_0047e4f0:
        unaff_s4 = 0xffffffff;
        uVar27 = unaff_s4;
        if (iStack_6c != 0) goto LAB_0047e248;
        uVar27 = 0xffffffff;
        goto LAB_0047e25c;
      }
    }
    puVar30 = (ushort *)((int)puStack_70 + uVar40);
    if ((*piVar35 == 0xfeff) || (uVar27 = 0xffffffff, *piVar35 == 0x100)) {
      puStack_70 = (undefined4 *)((int)puVar30 + 1);
      uVar37 = (uint)*(byte *)puVar30;
      uVar27 = (*(code *)PTR_SSL_ctrl_006a8878)(piVar35,0x20,0,0);
      if (((uVar27 & 0x2000) == 0) || (uVar37 == 0)) {
        uVar27 = 0xffffffff;
      }
      else {
        (*(code *)PTR_memcpy_006aabf4)(piVar35[0x17] + 0x104,puStack_70,uVar37);
        if (*(code **)(piVar35[0x39] + 0x7c) == (code *)0x0) {
          iVar29 = piVar35[0x17];
          iVar29 = (*(code *)PTR_memcmp_006aabd8)
                             (iVar29 + 0x104,iVar29 + 4,*(undefined4 *)(iVar29 + 0x204));
          if (iVar29 != 0) {
            uVar33 = 0x42d;
            goto LAB_0047e848;
          }
        }
        else {
          iVar29 = (**(code **)(piVar35[0x39] + 0x7c))(piVar35,piVar35[0x17] + 0x104,uVar37);
          if (iVar29 == 0) {
            uVar33 = 0x423;
LAB_0047e848:
            uStack_74 = 0x28;
            uVar27 = 0xffffffff;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0x134,"s3_srvr.c",uVar33);
            goto LAB_0047e228;
          }
        }
        uVar27 = 2;
      }
      puVar30 = (ushort *)((int)puStack_70 + uVar37);
    }
    puStack_70 = (undefined4 *)(puVar30 + 1);
    uVar37 = (uint)*puVar30;
    if (uVar37 == 0) {
      if (uVar40 != 0) {
        uVar38 = 0xb7;
        uVar33 = 0x43c;
        uStack_74 = 0x2f;
        goto LAB_0047e4cc;
      }
      puVar36 = puStack_70;
      if ((undefined4 *)((int)puVar44 + uVar28) <= puStack_70) goto LAB_0047e87c;
    }
    else {
      if ((byte *)((int)puVar44 + uVar28) <= (byte *)((int)puStack_70 + uVar37)) {
LAB_0047e87c:
        uVar38 = 0x9f;
        uVar33 = 0x443;
        uStack_74 = 0x32;
        goto LAB_0047e4cc;
      }
      iVar29 = (*(code *)PTR_ssl_bytes_to_cipher_list_006a9068)
                         (piVar35,puStack_70,uVar37,&iStack_6c);
      if (iVar29 == 0) goto LAB_0047e23c;
      puStack_70 = (undefined4 *)((int)puStack_70 + uVar37);
      puVar36 = puStack_70;
      if (piVar35[0x1b] != 0) {
        iVar29 = 0;
        iVar45 = *(int *)(*(int *)(piVar35[0x30] + 0xb4) + 8);
        while( true ) {
          iVar31 = (*(code *)PTR_sk_num_006a7f2c)(iStack_6c);
          if (iVar31 <= iVar29) {
            uVar38 = 0xd7;
            uVar33 = 0x47b;
            uStack_74 = 0x2f;
            goto LAB_0047e4cc;
          }
          iVar31 = (*(code *)PTR_sk_value_006a7f24)(iStack_6c,iVar29);
          puVar36 = puStack_70;
          if (iVar45 == *(int *)(iVar31 + 8)) break;
          iVar29 = iVar29 + 1;
        }
      }
    }
    puVar46 = (undefined4 *)((int)puVar36 + 1);
    uVar40 = (uint)*(byte *)puVar36;
    puStack_70 = (undefined4 *)((int)puVar46 + uVar40);
    if ((undefined4 *)((int)puVar44 + uVar28) < puStack_70) {
      uVar38 = 0x9f;
      uVar33 = 0x486;
      uStack_74 = 0x32;
      puStack_70 = puVar46;
      goto LAB_0047e4cc;
    }
    if (uVar40 == 0) {
LAB_0047e8a0:
      uVar38 = 0xbb;
      uVar33 = 0x494;
      uStack_74 = 0x32;
      goto LAB_0047e4cc;
    }
    if (*(byte *)((int)puVar36 + 1) != 0) {
      puVar30 = (ushort *)((int)puVar36 + 2);
      do {
        if ((ushort *)((int)puVar36 + uVar40 + 1) == puVar30) goto LAB_0047e8a0;
        bVar2 = *(byte *)puVar30;
        puVar30 = (ushort *)((int)puVar30 + 1);
      } while (bVar2 != 0);
    }
    if ((0x2ff < *piVar35) &&
       (iVar29 = ssl_parse_clienthello_tlsext(piVar35,&puStack_70,puVar44,uVar28,&uStack_74),
       iVar29 == 0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0xe3,"s3_srvr.c",0x49f);
      goto LAB_0047e228;
    }
    iVar29 = ssl_check_clienthello_tlsext_early(piVar35);
    if (iVar29 < 1) {
      uVar33 = 0x4a4;
      goto LAB_0047e930;
    }
    iVar29 = ssl_fill_hello_random(piVar35,1,piVar35[0x16] + 0xa0,0x20);
    if (0 < iVar29) {
      if (((piVar35[0x1b] == 0) && (0x300 < *piVar35)) &&
         (pcVar47 = (code *)piVar35[0x5a], pcVar47 != (code *)0x0)) {
        iVar29 = piVar35[0x5b];
        iVar45 = piVar35[0x30];
        iStack_68 = 0;
        *(undefined4 *)(iVar45 + 0x10) = 0x30;
        iVar45 = (*pcVar47)(piVar35,iVar45 + 0x14,iVar45 + 0x10,iStack_6c,&iStack_68,iVar29);
        iVar29 = iStack_6c;
        if (iVar45 != 0) {
          iVar45 = piVar35[0x30];
          piVar35[0x1b] = 1;
          iStack_6c = 0;
          *(int *)(iVar45 + 0xbc) = iVar29;
          *(undefined4 *)(iVar45 + 0xa0) = 0;
          if (iStack_68 == 0) {
            uVar33 = (*(code *)PTR_SSL_get_ciphers_006a894c)(piVar35);
            iStack_68 = ssl3_choose_cipher(piVar35,iVar29,uVar33);
            if (iStack_68 == 0) {
              uVar33 = 0x4c9;
              goto LAB_0047eca8;
            }
            iVar45 = piVar35[0x30];
          }
          iVar29 = piVar35[0x1d];
          *(int *)(iVar45 + 0xb4) = iStack_68;
          if (iVar29 != 0) {
            (*(code *)PTR_sk_free_006a7f80)();
          }
          if (piVar35[0x1e] != 0) {
            (*(code *)PTR_sk_free_006a7f80)();
          }
          iVar29 = (*(code *)PTR_sk_dup_006a9074)(*(undefined4 *)(piVar35[0x30] + 0xbc));
          piVar35[0x1d] = iVar29;
          iVar29 = (*(code *)PTR_sk_dup_006a9074)(*(undefined4 *)(piVar35[0x30] + 0xbc));
          piVar35[0x1e] = iVar29;
        }
      }
      iVar29 = piVar35[0x30];
      uVar28 = *(uint *)(iVar29 + 0xb0);
      *(undefined4 *)(piVar35[0x16] + 0x38c) = 0;
      if (uVar28 != 0) {
        if (piVar35[0x40] << 0xe < 0) {
          uVar38 = 0x154;
          uVar33 = 0x4e9;
          uStack_74 = 0x50;
          goto LAB_0047e4cc;
        }
        puVar34 = (uint *)0x0;
        for (iVar29 = 0;
            iVar45 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(piVar35[0x39] + 0x98)),
            iVar29 < iVar45; iVar29 = iVar29 + 1) {
          puVar34 = (uint *)(*(code *)PTR_sk_value_006a7f24)
                                      (*(undefined4 *)(piVar35[0x39] + 0x98),iVar29);
          if (uVar28 == *puVar34) {
            iVar29 = piVar35[0x16];
            *(uint **)(iVar29 + 0x38c) = puVar34;
            goto LAB_0047e758;
          }
        }
        iVar29 = piVar35[0x16];
LAB_0047e758:
        uVar33 = 0x4f9;
        if (*(int *)(iVar29 + 0x38c) == 0) goto LAB_0047ec64;
        uVar37 = 0;
        do {
          if (uVar28 == *(byte *)puVar46) {
            if ((int)uVar37 < (int)uVar40) {
              iVar29 = piVar35[0x30];
              if (piVar35[0x1b] != 0) goto LAB_0047e9e4;
              if (puVar34 == (uint *)0x0) {
                uVar28 = 0;
              }
              else {
LAB_0047ebac:
                uVar28 = *puVar34;
              }
              goto LAB_0047eae4;
            }
            break;
          }
          uVar37 = uVar37 + 1;
          puVar46 = (undefined4 *)((int)puVar46 + 1);
        } while (uVar40 != uVar37);
        uVar38 = 0x156;
        uVar33 = 0x505;
        uStack_74 = 0x2f;
        goto LAB_0047e4cc;
      }
      if (piVar35[0x1b] == 0) {
        if ((-1 < piVar35[0x40] << 0xe) && (*(int *)(piVar35[0x39] + 0x98) != 0)) {
          iVar29 = (*(code *)PTR_sk_num_006a7f2c)();
          if (0 < iVar29) {
            iVar45 = 0;
            do {
              puVar34 = (uint *)(*(code *)PTR_sk_value_006a7f24)
                                          (*(undefined4 *)(piVar35[0x39] + 0x98),iVar45);
              puVar46 = puVar36;
              do {
                pbVar1 = (byte *)((int)puVar46 + 1);
                puVar46 = (undefined4 *)((int)puVar46 + 1);
                if (*puVar34 == (uint)*pbVar1) {
                  iVar29 = piVar35[0x1b];
                  *(uint **)(piVar35[0x16] + 0x38c) = puVar34;
                  if (iVar29 != 0) goto LAB_0047e9e0;
                  iVar29 = piVar35[0x30];
                  goto LAB_0047ebac;
                }
              } while ((undefined4 *)((int)puVar36 + uVar40) != puVar46);
              iVar45 = iVar45 + 1;
            } while (iVar29 != iVar45);
          }
          if (piVar35[0x1b] != 0) {
LAB_0047e9e0:
            iVar29 = piVar35[0x30];
            goto LAB_0047e9e4;
          }
          iVar29 = piVar35[0x30];
        }
LAB_0047eae4:
        *(uint *)(iVar29 + 0xb0) = uVar28;
        if (*(int *)(iVar29 + 0xbc) != 0) {
          (*(code *)PTR_sk_free_006a7f80)();
          iVar29 = piVar35[0x30];
        }
        iVar45 = iStack_6c;
        *(int *)(iVar29 + 0xbc) = iStack_6c;
        if (iStack_6c == 0) {
          uVar38 = 0xb6;
          uVar33 = 0x53f;
          uStack_74 = 0x2f;
          goto LAB_0047e4cc;
        }
        iStack_6c = 0;
        uVar33 = (*(code *)PTR_SSL_get_ciphers_006a894c)(piVar35);
        iVar29 = ssl3_choose_cipher(piVar35,iVar45,uVar33);
        if (iVar29 == 0) {
          uVar33 = 0x549;
LAB_0047eca8:
          uVar38 = 0xc1;
          uStack_74 = 0x28;
          goto LAB_0047e4cc;
        }
        *(int *)(piVar35[0x16] + 0x344) = iVar29;
      }
      else {
LAB_0047e9e4:
        iVar45 = 0;
        if (piVar35[0x40] << 1 < 0) {
          uVar33 = *(undefined4 *)(iVar29 + 0xbc);
          iVar29 = 0;
          iVar31 = 0;
          while (iVar32 = (*(code *)PTR_sk_num_006a7f2c)(uVar33), iVar29 < iVar32) {
            iVar43 = iVar29 + 1;
            iVar32 = (*(code *)PTR_sk_value_006a7f24)(uVar33,iVar29);
            if ((*(uint *)(iVar32 + 0x14) & 0x20) != 0) {
              iVar45 = iVar32;
            }
            iVar29 = iVar43;
            if ((*(uint *)(iVar32 + 0x20) & 2) != 0) {
              iVar31 = iVar32;
            }
          }
          if (iVar45 == 0) {
            if (iVar31 == 0) {
              *(undefined4 *)(piVar35[0x16] + 0x344) = *(undefined4 *)(piVar35[0x30] + 0xb4);
            }
            else {
              *(int *)(piVar35[0x16] + 0x344) = iVar31;
            }
          }
          else {
            *(int *)(piVar35[0x16] + 0x344) = iVar45;
          }
        }
        else {
          *(undefined4 *)(piVar35[0x16] + 0x344) = *(undefined4 *)(iVar29 + 0xb4);
        }
      }
      iVar29 = *piVar35;
      if (((iVar29 >> 8 != 3) || (iVar29 < 0x303)) || ((piVar35[0x32] & 1U) == 0)) {
        iVar29 = ssl3_digest_cached_records(piVar35);
        if (iVar29 == 0) goto LAB_0047e90c;
        iVar29 = *piVar35;
      }
      if ((iVar29 < 0x300) || (iVar29 = ssl_check_clienthello_tlsext_late(piVar35), 0 < iVar29)) {
        if (uVar27 != 0xffffffff) goto LAB_0047e23c;
        uVar27 = 1;
        goto LAB_0047e23c;
      }
      uVar33 = 0x586;
LAB_0047e930:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0xe2,"s3_srvr.c",uVar33);
      goto LAB_0047e23c;
    }
LAB_0047e90c:
    uStack_74 = 0x50;
    goto LAB_0047e228;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0x10b,"s3_srvr.c",0x3c0);
  if (((piVar35[0x44] >> 8 == 3) && (piVar35[0x23] == 0)) && (piVar35[0x24] == 0)) {
    *piVar35 = piVar35[0x44];
  }
  uVar27 = 0xffffffff;
  uStack_74 = 0x46;
LAB_0047e228:
  while( true ) {
    ssl3_send_alert(piVar35,2,uStack_74);
LAB_0047e23c:
    unaff_s4 = uVar27;
    if (iStack_6c != 0) {
LAB_0047e248:
      (*(code *)PTR_sk_free_006a7f80)();
      unaff_s4 = uVar27;
    }
LAB_0047e25c:
    if (iStack_64 == *(int *)puVar26) break;
    uVar33 = (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar27 = unaff_s4;
LAB_0047ec64:
    uVar38 = 0x155;
    uStack_74 = 0x50;
LAB_0047e4cc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,uVar38,"s3_srvr.c",uVar33);
  }
  return uVar27;
}

