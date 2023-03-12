
uint ssl3_get_client_hello(int *param_1)

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
  int iVar28;
  ushort *puVar29;
  int iVar30;
  int iVar31;
  undefined4 uVar32;
  uint uVar33;
  undefined4 *puVar34;
  uint uVar35;
  undefined4 uVar36;
  uint uVar37;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  int iVar38;
  int iVar39;
  ushort *puVar40;
  uint unaff_s4;
  int iVar41;
  undefined4 *puVar42;
  uint *puVar43;
  code *pcVar44;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar26 = PTR___stack_chk_guard_006aabf0;
  local_34 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1[0xd] == 0x2110) {
    param_1[0xd] = 0x2111;
  }
  pcVar44 = *(code **)(param_1[2] + 0x30);
  param_1[0x43] = 1;
  uVar27 = (*pcVar44)(param_1,0x2111,0x2112,1,0x4000,&local_40);
  uVar33 = uVar27;
  if (local_40 == 0) goto LAB_0047e25c;
  puVar40 = (ushort *)param_1[0x10];
  param_1[0x43] = 0;
  local_38 = (undefined4 *)(puVar40 + 1);
  uVar33 = (uint)*puVar40;
  param_1[0x44] = uVar33;
  if (*param_1 == 0xfeff) {
    if (uVar33 < 0xff00) goto LAB_0047e2ac;
  }
  else if (*param_1 <= (int)uVar33) {
LAB_0047e2ac:
    uVar37 = 0;
    uVar35 = 0;
    uVar33 = (*(code *)PTR_SSL_ctrl_006a8878)(param_1,0x20);
    uVar33 = uVar33 & 0x2000;
    if ((uVar33 != 0) &&
       (uVar33 = 1, *(byte *)((int)local_38 + *(byte *)(local_38 + 8) + 0x21) == 0))
    goto LAB_0047e25c;
    puVar34 = (undefined4 *)((int)local_38 + 0x21);
    iVar38 = param_1[0x16];
    uVar3 = (uint)(local_38 + 1) & 3;
    iVar28 = *(int *)((int)(local_38 + 1) - uVar3);
    uVar4 = (uint)(local_38 + 2) & 3;
    iVar41 = *(int *)((int)(local_38 + 2) - uVar4);
    uVar5 = (uint)(local_38 + 3) & 3;
    iVar30 = *(int *)((int)(local_38 + 3) - uVar5);
    uVar6 = (uint)(local_38 + 4) & 3;
    iVar31 = *(int *)((int)(local_38 + 4) - uVar6);
    uVar7 = (uint)(local_38 + 5) & 3;
    iVar39 = *(int *)((int)(local_38 + 5) - uVar7);
    uVar8 = (uint)(local_38 + 6) & 3;
    iVar10 = *(int *)((int)(local_38 + 6) - uVar8);
    uVar9 = (uint)(local_38 + 7) & 3;
    iVar11 = *(int *)((int)(local_38 + 7) - uVar9);
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
    *(undefined4 *)(iVar38 + 0xc0) = *local_38;
    *(uint *)(iVar38 + 0xc4) =
         (iVar28 << uVar3 * 8 | in_t3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar12 + 1) * 8 |
         uVar19 >> (3 - uVar12) * 8;
    *(uint *)(iVar38 + 200) =
         (iVar41 << uVar4 * 8 | in_t2 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar13 + 1) * 8 |
         uVar20 >> (3 - uVar13) * 8;
    *(uint *)(iVar38 + 0xcc) =
         (iVar30 << uVar5 * 8 | in_t1 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar14 + 1) * 8 |
         uVar21 >> (3 - uVar14) * 8;
    *(uint *)(iVar38 + 0xd0) =
         (iVar31 << uVar6 * 8 | in_t0 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar15 + 1) * 8 |
         uVar22 >> (3 - uVar15) * 8;
    *(uint *)(iVar38 + 0xd4) =
         (iVar39 << uVar7 * 8 | uVar37 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar16 + 1) * 8 |
         uVar23 >> (3 - uVar16) * 8;
    *(uint *)(iVar38 + 0xd8) =
         (iVar10 << uVar8 * 8 | uVar35 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar17 + 1) * 8 |
         uVar24 >> (3 - uVar17) * 8;
    *(uint *)(iVar38 + 0xdc) =
         (iVar11 << uVar9 * 8 | uVar33 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar18 + 1) * 8 |
         uVar25 >> (3 - uVar18) * 8;
    uVar35 = (uint)*(byte *)(local_38 + 8);
    param_1[0x1b] = 0;
    local_38 = puVar34;
    if ((param_1[10] == 0) || (-1 < param_1[0x40] << 0xf)) {
      iVar28 = (*(code *)PTR_ssl_get_prev_session_006a9050)
                         (param_1,puVar34,uVar35,(int)puVar40 + uVar27);
      if (iVar28 != 1) {
        if (iVar28 == -1) goto LAB_0047e4f0;
        goto LAB_0047e3c4;
      }
      param_1[0x1b] = 1;
    }
    else {
LAB_0047e3c4:
      iVar28 = (*(code *)PTR_ssl_get_new_session_006a904c)(param_1,1);
      if (iVar28 == 0) {
LAB_0047e4f0:
        unaff_s4 = 0xffffffff;
        uVar33 = unaff_s4;
        if (local_34 != 0) goto LAB_0047e248;
        uVar33 = 0xffffffff;
        goto LAB_0047e25c;
      }
    }
    puVar29 = (ushort *)((int)local_38 + uVar35);
    if ((*param_1 == 0xfeff) || (uVar33 = 0xffffffff, *param_1 == 0x100)) {
      local_38 = (undefined4 *)((int)puVar29 + 1);
      uVar37 = (uint)*(byte *)puVar29;
      uVar33 = (*(code *)PTR_SSL_ctrl_006a8878)(param_1,0x20,0,0);
      if (((uVar33 & 0x2000) == 0) || (uVar37 == 0)) {
        uVar33 = 0xffffffff;
      }
      else {
        (*(code *)PTR_memcpy_006aabf4)(param_1[0x17] + 0x104,local_38,uVar37);
        if (*(code **)(param_1[0x39] + 0x7c) == (code *)0x0) {
          iVar28 = param_1[0x17];
          iVar28 = (*(code *)PTR_memcmp_006aabd8)
                             (iVar28 + 0x104,iVar28 + 4,*(undefined4 *)(iVar28 + 0x204));
          if (iVar28 != 0) {
            uVar32 = 0x42d;
            goto LAB_0047e848;
          }
        }
        else {
          iVar28 = (**(code **)(param_1[0x39] + 0x7c))(param_1,param_1[0x17] + 0x104,uVar37);
          if (iVar28 == 0) {
            uVar32 = 0x423;
LAB_0047e848:
            local_3c = 0x28;
            uVar33 = 0xffffffff;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0x134,"s3_srvr.c",uVar32);
            goto LAB_0047e228;
          }
        }
        uVar33 = 2;
      }
      puVar29 = (ushort *)((int)local_38 + uVar37);
    }
    local_38 = (undefined4 *)(puVar29 + 1);
    uVar37 = (uint)*puVar29;
    if (uVar37 == 0) {
      if (uVar35 != 0) {
        uVar36 = 0xb7;
        uVar32 = 0x43c;
        local_3c = 0x2f;
        goto LAB_0047e4cc;
      }
      puVar34 = local_38;
      if ((undefined4 *)((int)puVar40 + uVar27) <= local_38) goto LAB_0047e87c;
    }
    else {
      if ((byte *)((int)puVar40 + uVar27) <= (byte *)((int)local_38 + uVar37)) {
LAB_0047e87c:
        uVar36 = 0x9f;
        uVar32 = 0x443;
        local_3c = 0x32;
        goto LAB_0047e4cc;
      }
      iVar28 = (*(code *)PTR_ssl_bytes_to_cipher_list_006a9068)(param_1,local_38,uVar37,&local_34);
      if (iVar28 == 0) goto LAB_0047e23c;
      local_38 = (undefined4 *)((int)local_38 + uVar37);
      puVar34 = local_38;
      if (param_1[0x1b] != 0) {
        iVar28 = 0;
        iVar41 = *(int *)(*(int *)(param_1[0x30] + 0xb4) + 8);
        while( true ) {
          iVar30 = (*(code *)PTR_sk_num_006a7f2c)(local_34);
          if (iVar30 <= iVar28) {
            uVar36 = 0xd7;
            uVar32 = 0x47b;
            local_3c = 0x2f;
            goto LAB_0047e4cc;
          }
          iVar30 = (*(code *)PTR_sk_value_006a7f24)(local_34,iVar28);
          puVar34 = local_38;
          if (iVar41 == *(int *)(iVar30 + 8)) break;
          iVar28 = iVar28 + 1;
        }
      }
    }
    puVar42 = (undefined4 *)((int)puVar34 + 1);
    uVar35 = (uint)*(byte *)puVar34;
    local_38 = (undefined4 *)((int)puVar42 + uVar35);
    if ((undefined4 *)((int)puVar40 + uVar27) < local_38) {
      uVar36 = 0x9f;
      uVar32 = 0x486;
      local_3c = 0x32;
      local_38 = puVar42;
      goto LAB_0047e4cc;
    }
    if (uVar35 == 0) {
LAB_0047e8a0:
      uVar36 = 0xbb;
      uVar32 = 0x494;
      local_3c = 0x32;
      goto LAB_0047e4cc;
    }
    if (*(byte *)((int)puVar34 + 1) != 0) {
      puVar29 = (ushort *)((int)puVar34 + 2);
      do {
        if ((ushort *)((int)puVar34 + uVar35 + 1) == puVar29) goto LAB_0047e8a0;
        bVar2 = *(byte *)puVar29;
        puVar29 = (ushort *)((int)puVar29 + 1);
      } while (bVar2 != 0);
    }
    if ((0x2ff < *param_1) &&
       (iVar28 = ssl_parse_clienthello_tlsext(param_1,&local_38,puVar40,uVar27,&local_3c),
       iVar28 == 0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0xe3,"s3_srvr.c",0x49f);
      goto LAB_0047e228;
    }
    iVar28 = ssl_check_clienthello_tlsext_early(param_1);
    if (iVar28 < 1) {
      uVar32 = 0x4a4;
      goto LAB_0047e930;
    }
    iVar28 = ssl_fill_hello_random(param_1,1,param_1[0x16] + 0xa0,0x20);
    if (0 < iVar28) {
      if (((param_1[0x1b] == 0) && (0x300 < *param_1)) &&
         (pcVar44 = (code *)param_1[0x5a], pcVar44 != (code *)0x0)) {
        iVar28 = param_1[0x5b];
        iVar41 = param_1[0x30];
        local_30 = 0;
        *(undefined4 *)(iVar41 + 0x10) = 0x30;
        iVar41 = (*pcVar44)(param_1,iVar41 + 0x14,iVar41 + 0x10,local_34,&local_30,iVar28);
        iVar28 = local_34;
        if (iVar41 != 0) {
          iVar41 = param_1[0x30];
          param_1[0x1b] = 1;
          local_34 = 0;
          *(int *)(iVar41 + 0xbc) = iVar28;
          *(undefined4 *)(iVar41 + 0xa0) = 0;
          if (local_30 == 0) {
            uVar32 = (*(code *)PTR_SSL_get_ciphers_006a894c)(param_1);
            local_30 = ssl3_choose_cipher(param_1,iVar28,uVar32);
            if (local_30 == 0) {
              uVar32 = 0x4c9;
              goto LAB_0047eca8;
            }
            iVar41 = param_1[0x30];
          }
          iVar28 = param_1[0x1d];
          *(int *)(iVar41 + 0xb4) = local_30;
          if (iVar28 != 0) {
            (*(code *)PTR_sk_free_006a7f80)();
          }
          if (param_1[0x1e] != 0) {
            (*(code *)PTR_sk_free_006a7f80)();
          }
          iVar28 = (*(code *)PTR_sk_dup_006a9074)(*(undefined4 *)(param_1[0x30] + 0xbc));
          param_1[0x1d] = iVar28;
          iVar28 = (*(code *)PTR_sk_dup_006a9074)(*(undefined4 *)(param_1[0x30] + 0xbc));
          param_1[0x1e] = iVar28;
        }
      }
      iVar28 = param_1[0x30];
      uVar27 = *(uint *)(iVar28 + 0xb0);
      *(undefined4 *)(param_1[0x16] + 0x38c) = 0;
      if (uVar27 != 0) {
        if (param_1[0x40] << 0xe < 0) {
          uVar36 = 0x154;
          uVar32 = 0x4e9;
          local_3c = 0x50;
          goto LAB_0047e4cc;
        }
        puVar43 = (uint *)0x0;
        for (iVar28 = 0;
            iVar41 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1[0x39] + 0x98)),
            iVar28 < iVar41; iVar28 = iVar28 + 1) {
          puVar43 = (uint *)(*(code *)PTR_sk_value_006a7f24)
                                      (*(undefined4 *)(param_1[0x39] + 0x98),iVar28);
          if (uVar27 == *puVar43) {
            iVar28 = param_1[0x16];
            *(uint **)(iVar28 + 0x38c) = puVar43;
            goto LAB_0047e758;
          }
        }
        iVar28 = param_1[0x16];
LAB_0047e758:
        uVar32 = 0x4f9;
        if (*(int *)(iVar28 + 0x38c) == 0) goto LAB_0047ec64;
        uVar37 = 0;
        do {
          if (uVar27 == *(byte *)puVar42) {
            if ((int)uVar37 < (int)uVar35) {
              iVar28 = param_1[0x30];
              if (param_1[0x1b] != 0) goto LAB_0047e9e4;
              if (puVar43 == (uint *)0x0) {
                uVar27 = 0;
              }
              else {
LAB_0047ebac:
                uVar27 = *puVar43;
              }
              goto LAB_0047eae4;
            }
            break;
          }
          uVar37 = uVar37 + 1;
          puVar42 = (undefined4 *)((int)puVar42 + 1);
        } while (uVar35 != uVar37);
        uVar36 = 0x156;
        uVar32 = 0x505;
        local_3c = 0x2f;
        goto LAB_0047e4cc;
      }
      if (param_1[0x1b] == 0) {
        if ((-1 < param_1[0x40] << 0xe) && (*(int *)(param_1[0x39] + 0x98) != 0)) {
          iVar28 = (*(code *)PTR_sk_num_006a7f2c)();
          if (0 < iVar28) {
            iVar41 = 0;
            do {
              puVar43 = (uint *)(*(code *)PTR_sk_value_006a7f24)
                                          (*(undefined4 *)(param_1[0x39] + 0x98),iVar41);
              puVar42 = puVar34;
              do {
                pbVar1 = (byte *)((int)puVar42 + 1);
                puVar42 = (undefined4 *)((int)puVar42 + 1);
                if (*puVar43 == (uint)*pbVar1) {
                  iVar28 = param_1[0x1b];
                  *(uint **)(param_1[0x16] + 0x38c) = puVar43;
                  if (iVar28 != 0) goto LAB_0047e9e0;
                  iVar28 = param_1[0x30];
                  goto LAB_0047ebac;
                }
              } while ((undefined4 *)((int)puVar34 + uVar35) != puVar42);
              iVar41 = iVar41 + 1;
            } while (iVar28 != iVar41);
          }
          if (param_1[0x1b] != 0) {
LAB_0047e9e0:
            iVar28 = param_1[0x30];
            goto LAB_0047e9e4;
          }
          iVar28 = param_1[0x30];
        }
LAB_0047eae4:
        *(uint *)(iVar28 + 0xb0) = uVar27;
        if (*(int *)(iVar28 + 0xbc) != 0) {
          (*(code *)PTR_sk_free_006a7f80)();
          iVar28 = param_1[0x30];
        }
        iVar41 = local_34;
        *(int *)(iVar28 + 0xbc) = local_34;
        if (local_34 == 0) {
          uVar36 = 0xb6;
          uVar32 = 0x53f;
          local_3c = 0x2f;
          goto LAB_0047e4cc;
        }
        local_34 = 0;
        uVar32 = (*(code *)PTR_SSL_get_ciphers_006a894c)(param_1);
        iVar28 = ssl3_choose_cipher(param_1,iVar41,uVar32);
        if (iVar28 == 0) {
          uVar32 = 0x549;
LAB_0047eca8:
          uVar36 = 0xc1;
          local_3c = 0x28;
          goto LAB_0047e4cc;
        }
        *(int *)(param_1[0x16] + 0x344) = iVar28;
      }
      else {
LAB_0047e9e4:
        iVar41 = 0;
        if (param_1[0x40] << 1 < 0) {
          uVar32 = *(undefined4 *)(iVar28 + 0xbc);
          iVar28 = 0;
          iVar30 = 0;
          while (iVar31 = (*(code *)PTR_sk_num_006a7f2c)(uVar32), iVar28 < iVar31) {
            iVar39 = iVar28 + 1;
            iVar31 = (*(code *)PTR_sk_value_006a7f24)(uVar32,iVar28);
            if ((*(uint *)(iVar31 + 0x14) & 0x20) != 0) {
              iVar41 = iVar31;
            }
            iVar28 = iVar39;
            if ((*(uint *)(iVar31 + 0x20) & 2) != 0) {
              iVar30 = iVar31;
            }
          }
          if (iVar41 == 0) {
            if (iVar30 == 0) {
              *(undefined4 *)(param_1[0x16] + 0x344) = *(undefined4 *)(param_1[0x30] + 0xb4);
            }
            else {
              *(int *)(param_1[0x16] + 0x344) = iVar30;
            }
          }
          else {
            *(int *)(param_1[0x16] + 0x344) = iVar41;
          }
        }
        else {
          *(undefined4 *)(param_1[0x16] + 0x344) = *(undefined4 *)(iVar28 + 0xb4);
        }
      }
      iVar28 = *param_1;
      if (((iVar28 >> 8 != 3) || (iVar28 < 0x303)) || ((param_1[0x32] & 1U) == 0)) {
        iVar28 = ssl3_digest_cached_records(param_1);
        if (iVar28 == 0) goto LAB_0047e90c;
        iVar28 = *param_1;
      }
      if ((iVar28 < 0x300) || (iVar28 = ssl_check_clienthello_tlsext_late(param_1), 0 < iVar28)) {
        if (uVar33 != 0xffffffff) goto LAB_0047e23c;
        uVar33 = 1;
        goto LAB_0047e23c;
      }
      uVar32 = 0x586;
LAB_0047e930:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0xe2,"s3_srvr.c",uVar32);
      goto LAB_0047e23c;
    }
LAB_0047e90c:
    local_3c = 0x50;
    goto LAB_0047e228;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,0x10b,"s3_srvr.c",0x3c0);
  if (((param_1[0x44] >> 8 == 3) && (param_1[0x23] == 0)) && (param_1[0x24] == 0)) {
    *param_1 = param_1[0x44];
  }
  uVar33 = 0xffffffff;
  local_3c = 0x46;
LAB_0047e228:
  while( true ) {
    ssl3_send_alert(param_1,2,local_3c);
LAB_0047e23c:
    unaff_s4 = uVar33;
    if (local_34 != 0) {
LAB_0047e248:
      (*(code *)PTR_sk_free_006a7f80)();
      unaff_s4 = uVar33;
    }
LAB_0047e25c:
    if (local_2c == *(int *)puVar26) break;
    uVar32 = (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar33 = unaff_s4;
LAB_0047ec64:
    uVar36 = 0x155;
    local_3c = 0x50;
LAB_0047e4cc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8a,uVar36,"s3_srvr.c",uVar32);
  }
  return uVar33;
}

