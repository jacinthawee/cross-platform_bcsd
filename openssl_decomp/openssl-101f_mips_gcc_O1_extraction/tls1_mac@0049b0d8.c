
/* WARNING: Could not reconcile some variable overlaps */

int tls1_mac(int *param_1,undefined4 param_2,int param_3)

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
  char cVar27;
  int iVar23;
  uint *puVar24;
  int iVar25;
  uint *puVar26;
  uint *puVar28;
  undefined uVar33;
  uint uVar29;
  uint *puVar30;
  int iVar31;
  int iVar32;
  int *piVar34;
  uint uVar35;
  int *piVar36;
  uint uVar37;
  uint uVar38;
  undefined4 *puVar39;
  undefined4 *puVar40;
  uint uVar41;
  uint in_t0;
  uint uVar42;
  uint in_t1;
  uint uVar43;
  uint in_t2;
  uint uVar44;
  uint in_t3;
  uint uVar45;
  uint uVar46;
  int iVar47;
  char *pcVar48;
  undefined *puVar49;
  int iVar50;
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
  undefined *puStack_bc;
  uint uStack_b8;
  undefined *puStack_b4;
  undefined4 uStack_b0;
  uint uStack_ac;
  int iStack_a8;
  code *pcStack_a4;
  uint local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined *local_78;
  uint local_6c;
  int local_68;
  undefined4 *local_64;
  int local_60;
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
  
  puStack_b4 = PTR___stack_chk_guard_006aabf0;
  local_78 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar47 = param_1[0x16];
  puStack_c0 = (uint *)(iVar47 + 0x10c);
  if (param_3 == 0) {
    puVar49 = (undefined *)param_1[0x21];
    puStack_c8 = (undefined4 *)(iVar47 + 8);
    uStack_b8 = param_1[0x1f] & 1;
  }
  else {
    puVar49 = (undefined *)param_1[0x24];
    puStack_c0 = (uint *)(iVar47 + 0x130);
    puStack_c8 = (undefined4 *)(iVar47 + 0x54);
    uStack_b8 = param_1[0x1f] & 2;
  }
  uVar21 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(puVar49);
  local_60 = (**(code **)(local_78 + -0x6fb4))(uVar21);
  if (local_60 < 0) {
    local_6c = local_60;
    (**(code **)(local_78 + -0x7194))(&DAT_00647bcc,0x3d3,"t >= 0");
    local_60 = local_6c;
  }
  puStack_bc = puVar49;
  if (uStack_b8 == 0) {
    puStack_bc = auStack_5c;
    (**(code **)(local_78 + -0x6e2c))(puStack_bc,puVar49);
  }
  iVar47 = *param_1;
  if ((iVar47 == 0xfeff) || (iVar47 == 0x100)) {
    if (param_3 == 0) {
      uVar2 = *(undefined2 *)(param_1[0x17] + 0x208);
      uVar33 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
      uVar33 = (undefined)((ushort)uVar2 >> 8);
    }
    local_44 = (undefined  [4])CONCAT13(uVar33,CONCAT12((char)uVar2,SUB42(local_44,0)));
    bVar1 = *(byte *)((int)puStack_c8 + 6);
    in_t0 = (uint)bVar1;
    uVar29 = *(uint *)((int)puStack_c8 + 2);
    cVar27 = *(char *)((int)puStack_c8 + 7);
    puVar49 = local_44 + 2;
    uVar22 = (uint)puVar49 & 3;
    *(uint *)(puVar49 + -uVar22) =
         *(uint *)(puVar49 + -uVar22) & -1 << (4 - uVar22) * 8 | uVar29 >> uVar22 * 8;
    puVar49 = local_40 + 1;
    uVar22 = (uint)puVar49 & 3;
    *(uint *)(puVar49 + -uVar22) =
         *(uint *)(puVar49 + -uVar22) & 0xffffffffU >> (uVar22 + 1) * 8 | uVar29 << (3 - uVar22) * 8
    ;
    local_40 = (undefined  [4])CONCAT31(CONCAT21(local_40._0_2_,bVar1),cVar27);
    local_38 = local_40;
    local_3c = local_44;
  }
  else {
    local_3c = *puStack_c8;
    local_38 = puStack_c8[1];
  }
  local_6c = puStack_c0[1];
  uStack_ac = *puStack_c0;
  local_68 = local_60;
  puVar39 = (undefined4 *)(uStack_ac & 0xff);
  *puStack_c0 = (uint)puVar39;
  local_34 = (undefined)uStack_ac;
  local_33 = (undefined)((uint)iVar47 >> 8);
  local_32 = (undefined)iVar47;
  local_31 = (undefined)(local_6c >> 8);
  local_30 = (undefined)local_6c;
  puVar40 = &local_3c;
  if (((param_3 == 0) &&
      (local_64 = &local_3c, uVar22 = (**(code **)(local_78 + -0x6cb0))(param_1[0x20]),
      puVar40 = local_64, (uVar22 & 0xf0007) == 2)) &&
     (iVar47 = ssl3_cbc_record_digest_supported(puStack_bc,local_64), puVar40 = local_64,
     iVar47 != 0)) {
    local_7c = 0;
    local_84 = param_1[0x16] + 0x14;
    local_80 = *(undefined4 *)(param_1[0x16] + 0x10);
    pcVar48 = (char *)&local_60;
    local_88 = local_6c + local_68 + (uStack_ac >> 8);
    local_8c = puStack_c0[1] + local_60;
    local_90 = puStack_c0[4];
    puVar39 = local_64;
    ssl3_cbc_digest_record(puStack_bc,param_2);
  }
  else {
    (**(code **)(local_78 + -0x786c))(puStack_bc,puVar40,0xd);
    (**(code **)(local_78 + -0x786c))(puStack_bc,puStack_c0[4],puStack_c0[1]);
    pcVar48 = (char *)&local_60;
    iVar47 = (**(code **)(local_78 + -0x7914))(puStack_bc,param_2);
    if (iVar47 < 1) {
      pcVar48 = "t > 0";
      (**(code **)(local_78 + -0x7194))(&DAT_00647bcc,0x40d);
    }
  }
  if (uStack_b8 == 0) {
    (**(code **)(local_78 + -0x7fac))(auStack_5c);
  }
  if (((((*param_1 != 0xfeff) && (*param_1 != 0x100)) &&
       ((cVar27 = *(char *)((int)puStack_c8 + 7) + '\x01', *(char *)((int)puStack_c8 + 7) = cVar27,
        cVar27 == '\0' &&
        ((cVar27 = *(char *)((int)puStack_c8 + 6) + '\x01', *(char *)((int)puStack_c8 + 6) = cVar27,
         cVar27 == '\0' &&
         (cVar27 = *(char *)((int)puStack_c8 + 5) + '\x01', *(char *)((int)puStack_c8 + 5) = cVar27,
         cVar27 == '\0')))))) &&
      (cVar27 = *(char *)(puStack_c8 + 1), *(char *)(puStack_c8 + 1) = cVar27 + '\x01',
      (char)(cVar27 + '\x01') == '\0')) &&
     (((cVar27 = *(char *)((int)puStack_c8 + 3) + '\x01', *(char *)((int)puStack_c8 + 3) = cVar27,
       cVar27 == '\0' &&
       (cVar27 = *(char *)((int)puStack_c8 + 2) + '\x01', *(char *)((int)puStack_c8 + 2) = cVar27,
       cVar27 == '\0')) &&
      (cVar27 = *(char *)((int)puStack_c8 + 1) + '\x01', *(char *)((int)puStack_c8 + 1) = cVar27,
      cVar27 == '\0')))) {
    *(char *)puStack_c8 = *(char *)puStack_c8 + '\x01';
  }
  if (local_2c == *(int *)puStack_b4) {
    return local_60;
  }
  pcStack_a4 = tls1_generate_master_secret;
  iVar47 = local_2c;
  (**(code **)(local_78 + -0x5328))();
  puVar49 = PTR___stack_chk_guard_006aabf0;
  uStack_cc = *(uint *)PTR___stack_chk_guard_006aabf0;
  puVar40 = puVar39;
  piStack_c4 = param_1;
  uStack_b0 = param_2;
  iStack_a8 = param_3;
  uVar22 = ssl_get_algorithm2();
  iVar51 = *(int *)(iVar47 + 0xc0);
  iVar50 = 0;
  iVar23 = *(int *)(iVar47 + 0x58) + 0xc0;
  puVar24 = (uint *)(iVar51 + 0x14);
  iVar47 = 0;
  while (iVar25 = ssl_get_handshake_digest(iVar50,&iStack_104,&iStack_100), iVar25 != 0) {
    iVar50 = iVar50 + 1;
    if ((iStack_104 << 10 & uVar22) != 0) {
      iVar47 = iVar47 + 1;
    }
  }
  if (iVar47 == 0) {
    trap(7);
  }
  iVar50 = (int)puVar39 / iVar47;
  if (iVar47 == 1) {
    puVar39 = (undefined4 *)0x0;
  }
  (*(code *)PTR_memset_006aab00)(puVar24,0,0x30);
  iVar47 = 0;
  pcStack_118 = "master secret";
  piVar34 = &iStack_104;
  piVar36 = &iStack_100;
  iVar25 = ssl_get_handshake_digest(0);
  do {
    if (iVar25 == 0) {
LAB_0049b79c:
      if (uStack_cc == *(uint *)puVar49) {
        return 0x30;
      }
      uVar22 = uStack_cc;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puVar39 = puVar40;
      iVar47 = (*(code *)PTR_CRYPTO_malloc_006a8108)(piVar36,&DAT_00647bcc,0x471);
      if (iVar47 == 0) {
        iVar23 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
      }
      else {
        iVar23 = uStack_158 + 0x40;
        if (iStack_14c == 0) {
          iVar51 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar23,&DAT_00647bcc,0x47f);
          iVar50 = iVar23;
        }
        else {
          iVar50 = uStack_150 + 2 + iVar23;
          iVar51 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar50,&DAT_00647bcc,0x47f);
        }
        if (iVar51 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar47);
          return 0;
        }
        uVar37 = uStack_158;
        (*(code *)PTR_memcpy_006aabf4)(iVar51);
        puVar28 = (uint *)(iVar51 + uStack_158);
        iVar31 = *(int *)(uVar22 + 0x58);
        puVar24 = (uint *)(iVar51 + uStack_158 + 0x20);
        uVar46 = *(uint *)(iVar31 + 0xc0);
        uVar29 = iVar31 + 0xc4U & 3;
        uVar3 = iVar31 + 200U & 3;
        uVar4 = iVar31 + 0xccU & 3;
        uVar5 = iVar31 + 0xd0U & 3;
        uVar6 = iVar31 + 0xd4U & 3;
        uVar7 = iVar31 + 0xd8U & 3;
        iVar25 = *(int *)((iVar31 + 0xd8U) - uVar7);
        uVar8 = iVar31 + 0xdcU & 3;
        iVar9 = *(int *)((iVar31 + 0xdcU) - uVar8);
        uVar12 = iVar31 + 199U & 3;
        uVar45 = (*(int *)((iVar31 + 0xc4U) - uVar29) << uVar29 * 8 |
                 in_t3 & 0xffffffffU >> (4 - uVar29) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)((iVar31 + 199U) - uVar12) >> (3 - uVar12) * 8;
        uVar29 = iVar31 + 0xcbU & 3;
        uVar44 = (*(int *)((iVar31 + 200U) - uVar3) << uVar3 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar29 + 1) * 8 |
                 *(uint *)((iVar31 + 0xcbU) - uVar29) >> (3 - uVar29) * 8;
        uVar29 = iVar31 + 0xcfU & 3;
        uVar43 = (*(int *)((iVar31 + 0xccU) - uVar4) << uVar4 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar29 + 1) * 8 |
                 *(uint *)((iVar31 + 0xcfU) - uVar29) >> (3 - uVar29) * 8;
        uVar29 = iVar31 + 0xd3U & 3;
        uVar42 = (*(int *)((iVar31 + 0xd0U) - uVar5) << uVar5 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar29 + 1) * 8 |
                 *(uint *)((iVar31 + 0xd3U) - uVar29) >> (3 - uVar29) * 8;
        uVar29 = iVar31 + 0xd7U & 3;
        uVar41 = (*(int *)((iVar31 + 0xd4U) - uVar6) << uVar6 * 8 |
                 (uint)puVar39 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar29 + 1) * 8 |
                 *(uint *)((iVar31 + 0xd7U) - uVar29) >> (3 - uVar29) * 8;
        uVar29 = iVar31 + 0xdbU & 3;
        uVar4 = *(uint *)((iVar31 + 0xdbU) - uVar29);
        uVar3 = iVar31 + 0xdfU & 3;
        uVar5 = *(uint *)((iVar31 + 0xdfU) - uVar3);
        *puVar28 = uVar46;
        puVar28[1] = uVar45;
        puVar28[2] = uVar44;
        puVar28[3] = uVar43;
        puVar28[4] = uVar42;
        puVar28[5] = uVar41;
        puVar28[6] = (iVar25 << uVar7 * 8 | uVar37 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar29 + 1) * 8 | uVar4 >> (3 - uVar29) * 8;
        puVar28[7] = (iVar9 << uVar8 * 8 | (uint)puVar40 & 0xffffffffU >> (4 - uVar8) * 8) &
                     -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
        iVar32 = *(int *)(uVar22 + 0x58);
        uVar29 = iVar32 + 0xa0U & 3;
        uVar3 = iVar32 + 0xa4U & 3;
        iVar25 = *(int *)((iVar32 + 0xa4U) - uVar3);
        uVar4 = iVar32 + 0xa8U & 3;
        iVar9 = *(int *)((iVar32 + 0xa8U) - uVar4);
        uVar5 = iVar32 + 0xacU & 3;
        iVar31 = *(int *)((iVar32 + 0xacU) - uVar5);
        uVar6 = iVar32 + 0xb0U & 3;
        iVar10 = *(int *)((iVar32 + 0xb0U) - uVar6);
        uVar7 = iVar32 + 0xb4U & 3;
        iVar11 = *(int *)((iVar32 + 0xb4U) - uVar7);
        uVar8 = iVar32 + 0xa3U & 3;
        uVar12 = iVar32 + 0xa7U & 3;
        uVar16 = *(uint *)((iVar32 + 0xa7U) - uVar12);
        uVar37 = iVar32 + 0xabU & 3;
        uVar17 = *(uint *)((iVar32 + 0xabU) - uVar37);
        uVar13 = iVar32 + 0xafU & 3;
        uVar18 = *(uint *)((iVar32 + 0xafU) - uVar13);
        uVar14 = iVar32 + 0xb3U & 3;
        uVar19 = *(uint *)((iVar32 + 0xb3U) - uVar14);
        uVar15 = iVar32 + 0xb7U & 3;
        uVar20 = *(uint *)((iVar32 + 0xb7U) - uVar15);
        uVar38 = *(uint *)(iVar32 + 0xb8);
        uVar35 = *(uint *)(iVar32 + 0xbc);
        *puVar24 = (*(int *)((iVar32 + 0xa0U) - uVar29) << uVar29 * 8 |
                   uVar46 & 0xffffffffU >> (4 - uVar29) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)((iVar32 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
        puVar24[1] = (iVar25 << uVar3 * 8 | uVar45 & 0xffffffffU >> (4 - uVar3) * 8) &
                     -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
        puVar24[2] = (iVar9 << uVar4 * 8 | uVar44 & 0xffffffffU >> (4 - uVar4) * 8) &
                     -1 << (uVar37 + 1) * 8 | uVar17 >> (3 - uVar37) * 8;
        puVar24[3] = (iVar31 << uVar5 * 8 | uVar43 & 0xffffffffU >> (4 - uVar5) * 8) &
                     -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
        puVar24[4] = (iVar10 << uVar6 * 8 | uVar42 & 0xffffffffU >> (4 - uVar6) * 8) &
                     -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
        puVar24[5] = (iVar11 << uVar7 * 8 | uVar41 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
        puVar24[6] = uVar38;
        puVar24[7] = uVar35;
        if (iStack_14c != 0) {
          *(char *)(iVar51 + iVar23) = (char)((uint)uStack_150 >> 8);
          *(undefined *)((int)puVar28 + 0x41) = (undefined)uStack_150;
          if ((uStack_150 != 0) || (iStack_154 != 0)) {
            (*(code *)PTR_memcpy_006aabf4)(iVar51 + uStack_158 + 0x42,iStack_154,uStack_150);
          }
        }
        iVar23 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"client finished",0xf);
        if (((iVar23 == 0) ||
            (iVar23 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"server finished",0xf), iVar23 == 0)) ||
           ((iVar23 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"master secret",0xd), iVar23 == 0 ||
            (iVar23 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"key expansion",0xd), iVar23 == 0)))) {
          iVar23 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x16f,&DAT_00647bcc,0x4b1);
        }
        else {
          iVar23 = tls1_PRF_constprop_1
                             (*(undefined4 *)(*(int *)(*(int *)(uVar22 + 0x58) + 0x344) + 0x24),
                              iVar51,iVar50,0,0,0,0,0,0,*(int *)(uVar22 + 0xc0) + 0x14,
                              *(undefined4 *)(*(int *)(uVar22 + 0xc0) + 0x10),piVar34,iVar47,piVar36
                             );
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar47);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar51);
      }
      return iVar23;
    }
    if ((iStack_104 << 10 & uVar22) != 0) {
      if (iStack_100 == 0) {
        piVar36 = (int *)0x146;
        puVar40 = (undefined4 *)&DAT_00647bcc;
        uStack_158 = 0x114;
        piVar34 = (int *)0x11c;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14);
        goto LAB_0049b79c;
      }
      uStack_150 = 0x20;
      iStack_14c = 0;
      uStack_158 = 0xd;
      piVar34 = (int *)pcVar48;
      piVar36 = (int *)(((uint)puVar39 & 1) + iVar50);
      puVar40 = (undefined4 *)pcStack_118;
      iVar25 = tls1_P_hash_constprop_2();
      iStack_154 = iVar23;
      if (iVar25 == 0) goto LAB_0049b79c;
      pcVar48 = (char *)((int)pcVar48 + iVar50);
      puVar28 = &uStack_fc;
      puVar30 = puVar24;
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
          puVar26 = (uint *)((int)puVar28 + 1);
          *(byte *)puVar30 = *(byte *)puVar30 ^ *(byte *)puVar28;
          puVar28 = puVar26;
          puVar30 = (uint *)((int)puVar30 + 1);
        } while (puVar26 != &uStack_cc);
      }
    }
    iVar47 = iVar47 + 1;
    piVar34 = &iStack_104;
    piVar36 = &iStack_100;
    iVar25 = ssl_get_handshake_digest(iVar47);
  } while( true );
}

