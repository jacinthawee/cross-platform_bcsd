
/* WARNING: Could not reconcile some variable overlaps */

uint tls1_mac(int *param_1,undefined4 param_2,uint *param_3,undefined4 *param_4)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
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
  undefined4 uVar21;
  uint uVar22;
  char cVar28;
  int iVar23;
  uint *puVar24;
  int iVar25;
  uint *puVar26;
  undefined4 uVar27;
  uint *puVar29;
  undefined uVar34;
  uint uVar30;
  uint *puVar31;
  int iVar32;
  int iVar33;
  uint uVar35;
  char *pcVar36;
  int *piVar37;
  uint uVar38;
  uint uVar39;
  undefined4 *puVar40;
  undefined4 *puVar41;
  uint uVar42;
  uint in_t0;
  uint uVar43;
  uint in_t1;
  uint uVar44;
  uint in_t2;
  uint uVar45;
  uint in_t3;
  uint uVar46;
  uint uVar47;
  int iVar48;
  undefined *puVar49;
  int iVar50;
  uint unaff_s7;
  int iVar51;
  uint uStack_158;
  int iStack_154;
  undefined4 uStack_150;
  int iStack_14c;
  char *pcStack_118;
  int iStack_104;
  int iStack_100;
  uint uStack_fc;
  uint uStack_f8;
  uint uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  undefined4 *puStack_c8;
  int *piStack_c4;
  uint *puStack_c0;
  uint uStack_bc;
  undefined *puStack_b8;
  undefined *puStack_b4;
  undefined4 uStack_b0;
  uint uStack_ac;
  uint *puStack_a8;
  code *pcStack_a4;
  uint local_90;
  int local_8c;
  uint local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined *local_78;
  uint local_6c;
  uint local_68;
  undefined4 *local_64;
  uint local_60;
  undefined auStack_5c [24];
  undefined local_44 [4];
  undefined local_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  int local_2c;
  
  puStack_b4 = PTR___stack_chk_guard_006a9ae8;
  local_78 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar48 = param_1[0x16];
  puStack_c0 = (uint *)(iVar48 + 0x10c);
  if (param_3 == (uint *)0x0) {
    puVar49 = (undefined *)param_1[0x21];
    puStack_c8 = (undefined4 *)(iVar48 + 8);
    uStack_bc = param_1[0x1f] & 1;
  }
  else {
    puVar49 = (undefined *)param_1[0x24];
    puStack_c0 = (uint *)(iVar48 + 0x130);
    puStack_c8 = (undefined4 *)(iVar48 + 0x54);
    uStack_bc = param_1[0x1f] & 2;
  }
  pcVar36 = (char *)param_3;
  uVar21 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(puVar49);
  local_60 = (**(code **)(local_78 + -0x6fa4))(uVar21);
  if ((int)local_60 < 0) {
    pcVar36 = "t >= 0";
    local_6c = local_60;
    (**(code **)(local_78 + -0x7184))(&DAT_0064760c,0x3f4);
    local_60 = local_6c;
  }
  puStack_b8 = puVar49;
  if (uStack_bc == 0) {
    puStack_b8 = auStack_5c;
    iVar48 = (**(code **)(local_78 + -0x6be0))(puStack_b8,puVar49);
    if (iVar48 == 0) {
      uVar22 = 0xffffffff;
      goto LAB_0049788c;
    }
  }
  iVar48 = *param_1;
  if ((iVar48 == 0xfeff) || (iVar48 == 0x100)) {
    if (param_3 == (uint *)0x0) {
      uVar2 = *(undefined2 *)(param_1[0x17] + 0x208);
      uVar34 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
      uVar34 = (undefined)((ushort)uVar2 >> 8);
    }
    local_44 = (undefined  [4])CONCAT13(uVar34,CONCAT12((char)uVar2,SUB42(local_44,0)));
    bVar1 = *(byte *)((int)puStack_c8 + 6);
    in_t0 = (uint)bVar1;
    uVar30 = *(uint *)((int)puStack_c8 + 2);
    cVar28 = *(char *)((int)puStack_c8 + 7);
    puVar49 = local_44 + 2;
    uVar22 = (uint)puVar49 & 3;
    *(uint *)(puVar49 + -uVar22) =
         *(uint *)(puVar49 + -uVar22) & -1 << (4 - uVar22) * 8 | uVar30 >> uVar22 * 8;
    puVar49 = local_40 + 1;
    uVar22 = (uint)puVar49 & 3;
    *(uint *)(puVar49 + -uVar22) =
         *(uint *)(puVar49 + -uVar22) & 0xffffffffU >> (uVar22 + 1) * 8 | uVar30 << (3 - uVar22) * 8
    ;
    local_40 = (undefined  [4])CONCAT31(CONCAT21(local_40._0_2_,bVar1),cVar28);
    local_38 = local_40;
    local_3c = local_44;
  }
  else {
    local_3c = *puStack_c8;
    local_38 = puStack_c8[1];
  }
  local_6c = puStack_c0[1];
  unaff_s7 = *puStack_c0;
  local_68 = local_60;
  param_4 = (undefined4 *)(unaff_s7 & 0xff);
  *puStack_c0 = (uint)param_4;
  local_34 = (undefined)unaff_s7;
  local_33 = (undefined)((uint)iVar48 >> 8);
  local_32 = (undefined)iVar48;
  local_31 = (undefined)(local_6c >> 8);
  local_30 = (undefined)local_6c;
  if (((param_3 == (uint *)0x0) &&
      (local_64 = &local_3c, uVar22 = (**(code **)(local_78 + -0x6cd8))(param_1[0x20]),
      (uVar22 & 0xf0007) == 2)) &&
     (iVar48 = ssl3_cbc_record_digest_supported(puStack_b8,local_64), iVar48 != 0)) {
    in_t0 = unaff_s7 >> 8;
    local_7c = 0;
    local_84 = param_1[0x16] + 0x14;
    local_80 = *(undefined4 *)(param_1[0x16] + 0x10);
    unaff_s7 = local_6c + local_68 + in_t0;
    pcVar36 = (char *)&local_60;
    local_8c = puStack_c0[1] + local_60;
    local_90 = puStack_c0[4];
    param_4 = local_64;
    local_88 = unaff_s7;
    iVar48 = ssl3_cbc_digest_record(puStack_b8,param_2);
joined_r0x00497878:
    if (0 < iVar48) {
      if (uStack_bc == 0) {
        (**(code **)(local_78 + -0x7fac))(auStack_5c);
      }
      uVar22 = local_60;
      if (((((*param_1 != 0xfeff) && (*param_1 != 0x100)) &&
           ((cVar28 = *(char *)((int)puStack_c8 + 7) + '\x01',
            *(char *)((int)puStack_c8 + 7) = cVar28, cVar28 == '\0' &&
            ((cVar28 = *(char *)((int)puStack_c8 + 6) + '\x01',
             *(char *)((int)puStack_c8 + 6) = cVar28, cVar28 == '\0' &&
             (cVar28 = *(char *)((int)puStack_c8 + 5) + '\x01',
             *(char *)((int)puStack_c8 + 5) = cVar28, cVar28 == '\0')))))) &&
          (cVar28 = *(char *)(puStack_c8 + 1), *(char *)(puStack_c8 + 1) = cVar28 + '\x01',
          (char)(cVar28 + '\x01') == '\0')) &&
         (((cVar28 = *(char *)((int)puStack_c8 + 3) + '\x01',
           *(char *)((int)puStack_c8 + 3) = cVar28, cVar28 == '\0' &&
           (cVar28 = *(char *)((int)puStack_c8 + 2) + '\x01',
           *(char *)((int)puStack_c8 + 2) = cVar28, cVar28 == '\0')) &&
          (cVar28 = *(char *)((int)puStack_c8 + 1) + '\x01', *(char *)((int)puStack_c8 + 1) = cVar28
          , cVar28 == '\0')))) {
        *(char *)puStack_c8 = *(char *)puStack_c8 + '\x01';
      }
      goto LAB_0049788c;
    }
  }
  else {
    pcVar36 = &DAT_0000000d;
    iVar48 = (**(code **)(local_78 + -0x7860))(puStack_b8);
    if (0 < iVar48) {
      pcVar36 = (char *)puStack_c0[1];
      iVar48 = (**(code **)(local_78 + -0x7860))(puStack_b8,puStack_c0[4]);
      if (0 < iVar48) {
        pcVar36 = (char *)&local_60;
        iVar48 = (**(code **)(local_78 + -0x7910))(puStack_b8,param_2);
        goto joined_r0x00497878;
      }
    }
  }
  if (uStack_bc == 0) {
    (**(code **)(local_78 + -0x7fac))(auStack_5c);
  }
  uVar22 = 0xffffffff;
LAB_0049788c:
  if (local_2c == *(int *)puStack_b4) {
    return uVar22;
  }
  pcStack_a4 = tls1_generate_master_secret;
  iVar48 = local_2c;
  (**(code **)(local_78 + -0x5330))();
  puVar49 = PTR___stack_chk_guard_006a9ae8;
  uStack_cc = *(uint *)PTR___stack_chk_guard_006a9ae8;
  puVar40 = param_4;
  piStack_c4 = param_1;
  uStack_b0 = param_2;
  uStack_ac = unaff_s7;
  puStack_a8 = param_3;
  uVar22 = ssl_get_algorithm2();
  iVar51 = *(int *)(iVar48 + 0xc0);
  iVar50 = 0;
  iVar23 = *(int *)(iVar48 + 0x58) + 0xc0;
  puVar24 = (uint *)(iVar51 + 0x14);
  iVar48 = 0;
  while (iVar25 = ssl_get_handshake_digest(iVar50,&iStack_104,&iStack_100), iVar25 != 0) {
    iVar50 = iVar50 + 1;
    if ((iStack_104 << 10 & uVar22) != 0) {
      iVar48 = iVar48 + 1;
    }
  }
  if (iVar48 == 0) {
    piVar37 = (int *)0x44;
    puVar40 = (undefined4 *)&DAT_0064760c;
    uStack_158 = 0x10a;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
  }
  else {
    if (iVar48 == 0) {
      trap(7);
    }
    iVar50 = (int)param_4 / iVar48;
    if (iVar48 == 1) {
      param_4 = (undefined4 *)0x0;
    }
    (*(code *)PTR_memset_006a99f4)(puVar24,0,0x30);
    iVar48 = 0;
    pcStack_118 = "master secret";
    piVar37 = &iStack_100;
    iVar25 = ssl_get_handshake_digest(0,&iStack_104);
    while (iVar25 != 0) {
      if ((iStack_104 << 10 & uVar22) != 0) {
        if (iStack_100 == 0) {
          piVar37 = (int *)0x146;
          puVar40 = (undefined4 *)&DAT_0064760c;
          uStack_158 = 0x115;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
          break;
        }
        uStack_150 = 0x20;
        iStack_14c = 0;
        uStack_158 = 0xd;
        piVar37 = (int *)(((uint)param_4 & 1) + iVar50);
        puVar40 = (undefined4 *)pcStack_118;
        iVar25 = tls1_P_hash_constprop_2(iStack_100,pcVar36);
        iStack_154 = iVar23;
        if (iVar25 == 0) break;
        pcVar36 = (char *)((int)pcVar36 + iVar50);
        puVar29 = &uStack_fc;
        puVar31 = puVar24;
        if (((uint)puVar24 & 3) == 0 &&
            ((uint *)(iVar51 + 0x18) <= &uStack_fc || &uStack_f8 <= puVar24)) {
          *(uint *)(iVar51 + 0x14) = *(uint *)(iVar51 + 0x14) ^ uStack_fc;
          *(uint *)(iVar51 + 0x18) = uStack_f8 ^ *(uint *)(iVar51 + 0x18);
          puVar40 = (undefined4 *)(uStack_e4 ^ *(uint *)(iVar51 + 0x2c));
          in_t3 = uStack_e8 ^ *(uint *)(iVar51 + 0x28);
          *(uint *)(iVar51 + 0x1c) = uStack_f4 ^ *(uint *)(iVar51 + 0x1c);
          *(uint *)(iVar51 + 0x20) = uStack_f0 ^ *(uint *)(iVar51 + 0x20);
          *(uint *)(iVar51 + 0x24) = uStack_ec ^ *(uint *)(iVar51 + 0x24);
          *(uint *)(iVar51 + 0x28) = in_t3;
          *(undefined4 **)(iVar51 + 0x2c) = puVar40;
          *(uint *)(iVar51 + 0x30) = uStack_e0 ^ *(uint *)(iVar51 + 0x30);
          *(uint *)(iVar51 + 0x38) = uStack_d8 ^ *(uint *)(iVar51 + 0x38);
          *(uint *)(iVar51 + 0x34) = uStack_dc ^ *(uint *)(iVar51 + 0x34);
          *(uint *)(iVar51 + 0x3c) = uStack_d4 ^ *(uint *)(iVar51 + 0x3c);
          *(uint *)(iVar51 + 0x40) = *(uint *)(iVar51 + 0x40) ^ uStack_d0;
        }
        else {
          do {
            puVar26 = (uint *)((int)puVar29 + 1);
            *(byte *)puVar31 = *(byte *)puVar31 ^ *(byte *)puVar29;
            puVar29 = puVar26;
            puVar31 = (uint *)((int)puVar31 + 1);
          } while (puVar26 != &uStack_cc);
        }
      }
      iVar48 = iVar48 + 1;
      piVar37 = &iStack_100;
      iVar25 = ssl_get_handshake_digest(iVar48,&iStack_104);
    }
  }
  uVar21 = 0x30;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(&uStack_fc);
  if (uStack_cc == *(uint *)puVar49) {
    return 0x30;
  }
  uVar22 = uStack_cc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar41 = puVar40;
  iVar48 = (*(code *)PTR_CRYPTO_malloc_006a7008)(piVar37,&DAT_0064760c,0x4a2);
  if (iVar48 == 0) {
    uVar22 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
  }
  else {
    iVar23 = uStack_158 + 0x40;
    if (iStack_14c == 0) {
      iVar51 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar23,&DAT_0064760c,0x4b0);
      iVar50 = iVar23;
    }
    else {
      iVar50 = uStack_150 + 2 + iVar23;
      iVar51 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar50,&DAT_0064760c,0x4b0);
    }
    if (iVar51 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar48);
      return 0;
    }
    uVar38 = uStack_158;
    (*(code *)PTR_memcpy_006a9aec)(iVar51);
    puVar29 = (uint *)(iVar51 + uStack_158);
    iVar32 = *(int *)(uVar22 + 0x58);
    puVar24 = (uint *)(iVar51 + uStack_158 + 0x20);
    uVar47 = *(uint *)(iVar32 + 0xc0);
    uVar30 = iVar32 + 0xc4U & 3;
    uVar3 = iVar32 + 200U & 3;
    uVar4 = iVar32 + 0xccU & 3;
    uVar5 = iVar32 + 0xd0U & 3;
    uVar6 = iVar32 + 0xd4U & 3;
    uVar7 = iVar32 + 0xd8U & 3;
    iVar25 = *(int *)((iVar32 + 0xd8U) - uVar7);
    uVar8 = iVar32 + 0xdcU & 3;
    iVar9 = *(int *)((iVar32 + 0xdcU) - uVar8);
    uVar12 = iVar32 + 199U & 3;
    uVar46 = (*(int *)((iVar32 + 0xc4U) - uVar30) << uVar30 * 8 |
             in_t3 & 0xffffffffU >> (4 - uVar30) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((iVar32 + 199U) - uVar12) >> (3 - uVar12) * 8;
    uVar30 = iVar32 + 0xcbU & 3;
    uVar45 = (*(int *)((iVar32 + 200U) - uVar3) << uVar3 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar30 + 1) * 8 |
             *(uint *)((iVar32 + 0xcbU) - uVar30) >> (3 - uVar30) * 8;
    uVar30 = iVar32 + 0xcfU & 3;
    uVar44 = (*(int *)((iVar32 + 0xccU) - uVar4) << uVar4 * 8 |
             in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar30 + 1) * 8 |
             *(uint *)((iVar32 + 0xcfU) - uVar30) >> (3 - uVar30) * 8;
    uVar30 = iVar32 + 0xd3U & 3;
    uVar43 = (*(int *)((iVar32 + 0xd0U) - uVar5) << uVar5 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar30 + 1) * 8 |
             *(uint *)((iVar32 + 0xd3U) - uVar30) >> (3 - uVar30) * 8;
    uVar30 = iVar32 + 0xd7U & 3;
    uVar42 = (*(int *)((iVar32 + 0xd4U) - uVar6) << uVar6 * 8 |
             (uint)puVar41 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar30 + 1) * 8 |
             *(uint *)((iVar32 + 0xd7U) - uVar30) >> (3 - uVar30) * 8;
    uVar30 = iVar32 + 0xdbU & 3;
    uVar4 = *(uint *)((iVar32 + 0xdbU) - uVar30);
    uVar3 = iVar32 + 0xdfU & 3;
    uVar5 = *(uint *)((iVar32 + 0xdfU) - uVar3);
    *puVar29 = uVar47;
    puVar29[1] = uVar46;
    puVar29[2] = uVar45;
    puVar29[3] = uVar44;
    puVar29[4] = uVar43;
    puVar29[5] = uVar42;
    puVar29[6] = (iVar25 << uVar7 * 8 | uVar38 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar30 + 1) * 8 | uVar4 >> (3 - uVar30) * 8;
    puVar29[7] = (iVar9 << uVar8 * 8 | (uint)puVar40 & 0xffffffffU >> (4 - uVar8) * 8) &
                 -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
    iVar33 = *(int *)(uVar22 + 0x58);
    uVar30 = iVar33 + 0xa0U & 3;
    uVar3 = iVar33 + 0xa4U & 3;
    iVar25 = *(int *)((iVar33 + 0xa4U) - uVar3);
    uVar4 = iVar33 + 0xa8U & 3;
    iVar9 = *(int *)((iVar33 + 0xa8U) - uVar4);
    uVar5 = iVar33 + 0xacU & 3;
    iVar32 = *(int *)((iVar33 + 0xacU) - uVar5);
    uVar6 = iVar33 + 0xb0U & 3;
    iVar10 = *(int *)((iVar33 + 0xb0U) - uVar6);
    uVar7 = iVar33 + 0xb4U & 3;
    iVar11 = *(int *)((iVar33 + 0xb4U) - uVar7);
    uVar8 = iVar33 + 0xa3U & 3;
    uVar12 = iVar33 + 0xa7U & 3;
    uVar16 = *(uint *)((iVar33 + 0xa7U) - uVar12);
    uVar38 = iVar33 + 0xabU & 3;
    uVar17 = *(uint *)((iVar33 + 0xabU) - uVar38);
    uVar13 = iVar33 + 0xafU & 3;
    uVar18 = *(uint *)((iVar33 + 0xafU) - uVar13);
    uVar14 = iVar33 + 0xb3U & 3;
    uVar19 = *(uint *)((iVar33 + 0xb3U) - uVar14);
    uVar15 = iVar33 + 0xb7U & 3;
    uVar20 = *(uint *)((iVar33 + 0xb7U) - uVar15);
    uVar39 = *(uint *)(iVar33 + 0xb8);
    uVar35 = *(uint *)(iVar33 + 0xbc);
    *puVar24 = (*(int *)((iVar33 + 0xa0U) - uVar30) << uVar30 * 8 |
               uVar47 & 0xffffffffU >> (4 - uVar30) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)((iVar33 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
    puVar24[1] = (iVar25 << uVar3 * 8 | uVar46 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
    puVar24[2] = (iVar9 << uVar4 * 8 | uVar45 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar38 + 1) * 8 | uVar17 >> (3 - uVar38) * 8;
    puVar24[3] = (iVar32 << uVar5 * 8 | uVar44 & 0xffffffffU >> (4 - uVar5) * 8) &
                 -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
    puVar24[4] = (iVar10 << uVar6 * 8 | uVar43 & 0xffffffffU >> (4 - uVar6) * 8) &
                 -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
    puVar24[5] = (iVar11 << uVar7 * 8 | uVar42 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
    puVar24[6] = uVar39;
    puVar24[7] = uVar35;
    if (iStack_14c != 0) {
      *(char *)(iVar51 + iVar23) = (char)((uint)uStack_150 >> 8);
      *(undefined *)((int)puVar29 + 0x41) = (undefined)uStack_150;
      if ((uStack_150 != 0) || (iStack_154 != 0)) {
        (*(code *)PTR_memcpy_006a9aec)(iVar51 + uStack_158 + 0x42,iStack_154,uStack_150);
      }
    }
    iVar23 = (*(code *)PTR_memcmp_006a9ad0)(iVar51,"client finished",0xf);
    if (((iVar23 == 0) ||
        (iVar23 = (*(code *)PTR_memcmp_006a9ad0)(iVar51,"server finished",0xf), iVar23 == 0)) ||
       ((iVar23 = (*(code *)PTR_memcmp_006a9ad0)(iVar51,"master secret",0xd), iVar23 == 0 ||
        (iVar23 = (*(code *)PTR_memcmp_006a9ad0)(iVar51,"key expansion",0xd), iVar23 == 0)))) {
      uVar22 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x16f,&DAT_0064760c,0x4e8);
    }
    else {
      uVar27 = ssl_get_algorithm2(uVar22);
      uVar22 = tls1_PRF_constprop_1
                         (uVar27,iVar51,iVar50,0,0,0,0,0,0,*(int *)(uVar22 + 0xc0) + 0x14,
                          *(undefined4 *)(*(int *)(uVar22 + 0xc0) + 0x10),uVar21,iVar48,piVar37);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar51,iVar50);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar48,piVar37);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar48);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar51);
  }
  return uVar22;
}

