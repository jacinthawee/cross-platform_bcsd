
/* WARNING: Could not reconcile some variable overlaps */

undefined4 tls1_generate_master_secret(int param_1,undefined4 param_2,int *param_3,char *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
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
  undefined *puVar20;
  uint uVar21;
  int iVar22;
  uint *puVar23;
  int iVar24;
  uint *puVar25;
  uint *puVar26;
  uint *puVar27;
  int iVar28;
  int iVar29;
  int *piVar30;
  uint uVar31;
  int *piVar32;
  uint uVar33;
  uint uVar34;
  char *pcVar35;
  char *pcVar36;
  uint uVar37;
  uint in_t0;
  uint uVar38;
  uint in_t1;
  uint uVar39;
  uint in_t2;
  uint uVar40;
  uint in_t3;
  uint uVar41;
  uint uVar42;
  undefined4 uVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  uint local_b8;
  int local_b4;
  undefined4 local_b0;
  int local_ac;
  char *local_78;
  int local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  puVar20 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  pcVar35 = param_4;
  uVar21 = ssl_get_algorithm2();
  iVar46 = *(int *)(param_1 + 0xc0);
  iVar45 = 0;
  iVar22 = *(int *)(param_1 + 0x58) + 0xc0;
  puVar23 = (uint *)(iVar46 + 0x14);
  iVar44 = 0;
  while (iVar24 = ssl_get_handshake_digest(iVar45,&local_64,&local_60), iVar24 != 0) {
    iVar45 = iVar45 + 1;
    if ((local_64 << 10 & uVar21) != 0) {
      iVar44 = iVar44 + 1;
    }
  }
  if (iVar44 == 0) {
    trap(7);
  }
  iVar45 = (int)param_4 / iVar44;
  if (iVar44 == 1) {
    param_4 = (char *)0x0;
  }
  (*(code *)PTR_memset_006aab00)(puVar23,0,0x30);
  iVar44 = 0;
  local_78 = "master secret";
  piVar30 = &local_64;
  piVar32 = &local_60;
  iVar24 = ssl_get_handshake_digest(0);
  do {
    if (iVar24 == 0) {
LAB_0049b79c:
      if (local_2c == *(uint *)puVar20) {
        return 0x30;
      }
      uVar21 = local_2c;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      pcVar36 = pcVar35;
      iVar44 = (*(code *)PTR_CRYPTO_malloc_006a8108)(piVar32,&DAT_00647bcc,0x471);
      if (iVar44 == 0) {
        uVar43 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
      }
      else {
        iVar22 = local_b8 + 0x40;
        if (local_ac == 0) {
          iVar46 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar22,&DAT_00647bcc,0x47f);
          iVar45 = iVar22;
        }
        else {
          iVar45 = local_b0 + 2 + iVar22;
          iVar46 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar45,&DAT_00647bcc,0x47f);
        }
        if (iVar46 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar44);
          return 0;
        }
        uVar33 = local_b8;
        (*(code *)PTR_memcpy_006aabf4)(iVar46);
        puVar26 = (uint *)(iVar46 + local_b8);
        iVar28 = *(int *)(uVar21 + 0x58);
        puVar23 = (uint *)(iVar46 + local_b8 + 0x20);
        uVar42 = *(uint *)(iVar28 + 0xc0);
        uVar1 = iVar28 + 0xc4U & 3;
        uVar2 = iVar28 + 200U & 3;
        uVar3 = iVar28 + 0xccU & 3;
        uVar4 = iVar28 + 0xd0U & 3;
        uVar5 = iVar28 + 0xd4U & 3;
        uVar6 = iVar28 + 0xd8U & 3;
        iVar24 = *(int *)((iVar28 + 0xd8U) - uVar6);
        uVar7 = iVar28 + 0xdcU & 3;
        iVar8 = *(int *)((iVar28 + 0xdcU) - uVar7);
        uVar11 = iVar28 + 199U & 3;
        uVar41 = (*(int *)((iVar28 + 0xc4U) - uVar1) << uVar1 * 8 |
                 in_t3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar11 + 1) * 8 |
                 *(uint *)((iVar28 + 199U) - uVar11) >> (3 - uVar11) * 8;
        uVar1 = iVar28 + 0xcbU & 3;
        uVar40 = (*(int *)((iVar28 + 200U) - uVar2) << uVar2 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
                 *(uint *)((iVar28 + 0xcbU) - uVar1) >> (3 - uVar1) * 8;
        uVar1 = iVar28 + 0xcfU & 3;
        uVar39 = (*(int *)((iVar28 + 0xccU) - uVar3) << uVar3 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar1 + 1) * 8 |
                 *(uint *)((iVar28 + 0xcfU) - uVar1) >> (3 - uVar1) * 8;
        uVar1 = iVar28 + 0xd3U & 3;
        uVar38 = (*(int *)((iVar28 + 0xd0U) - uVar4) << uVar4 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar1 + 1) * 8 |
                 *(uint *)((iVar28 + 0xd3U) - uVar1) >> (3 - uVar1) * 8;
        uVar1 = iVar28 + 0xd7U & 3;
        uVar37 = (*(int *)((iVar28 + 0xd4U) - uVar5) << uVar5 * 8 |
                 (uint)pcVar36 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
                 *(uint *)((iVar28 + 0xd7U) - uVar1) >> (3 - uVar1) * 8;
        uVar1 = iVar28 + 0xdbU & 3;
        uVar3 = *(uint *)((iVar28 + 0xdbU) - uVar1);
        uVar2 = iVar28 + 0xdfU & 3;
        uVar4 = *(uint *)((iVar28 + 0xdfU) - uVar2);
        *puVar26 = uVar42;
        puVar26[1] = uVar41;
        puVar26[2] = uVar40;
        puVar26[3] = uVar39;
        puVar26[4] = uVar38;
        puVar26[5] = uVar37;
        puVar26[6] = (iVar24 << uVar6 * 8 | uVar33 & 0xffffffffU >> (4 - uVar6) * 8) &
                     -1 << (uVar1 + 1) * 8 | uVar3 >> (3 - uVar1) * 8;
        puVar26[7] = (iVar8 << uVar7 * 8 | (uint)pcVar35 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar2 + 1) * 8 | uVar4 >> (3 - uVar2) * 8;
        iVar29 = *(int *)(uVar21 + 0x58);
        uVar1 = iVar29 + 0xa0U & 3;
        uVar2 = iVar29 + 0xa4U & 3;
        iVar24 = *(int *)((iVar29 + 0xa4U) - uVar2);
        uVar3 = iVar29 + 0xa8U & 3;
        iVar8 = *(int *)((iVar29 + 0xa8U) - uVar3);
        uVar4 = iVar29 + 0xacU & 3;
        iVar28 = *(int *)((iVar29 + 0xacU) - uVar4);
        uVar5 = iVar29 + 0xb0U & 3;
        iVar9 = *(int *)((iVar29 + 0xb0U) - uVar5);
        uVar6 = iVar29 + 0xb4U & 3;
        iVar10 = *(int *)((iVar29 + 0xb4U) - uVar6);
        uVar7 = iVar29 + 0xa3U & 3;
        uVar11 = iVar29 + 0xa7U & 3;
        uVar15 = *(uint *)((iVar29 + 0xa7U) - uVar11);
        uVar33 = iVar29 + 0xabU & 3;
        uVar16 = *(uint *)((iVar29 + 0xabU) - uVar33);
        uVar12 = iVar29 + 0xafU & 3;
        uVar17 = *(uint *)((iVar29 + 0xafU) - uVar12);
        uVar13 = iVar29 + 0xb3U & 3;
        uVar18 = *(uint *)((iVar29 + 0xb3U) - uVar13);
        uVar14 = iVar29 + 0xb7U & 3;
        uVar19 = *(uint *)((iVar29 + 0xb7U) - uVar14);
        uVar34 = *(uint *)(iVar29 + 0xb8);
        uVar31 = *(uint *)(iVar29 + 0xbc);
        *puVar23 = (*(int *)((iVar29 + 0xa0U) - uVar1) << uVar1 * 8 |
                   uVar42 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar7 + 1) * 8 |
                   *(uint *)((iVar29 + 0xa3U) - uVar7) >> (3 - uVar7) * 8;
        puVar23[1] = (iVar24 << uVar2 * 8 | uVar41 & 0xffffffffU >> (4 - uVar2) * 8) &
                     -1 << (uVar11 + 1) * 8 | uVar15 >> (3 - uVar11) * 8;
        puVar23[2] = (iVar8 << uVar3 * 8 | uVar40 & 0xffffffffU >> (4 - uVar3) * 8) &
                     -1 << (uVar33 + 1) * 8 | uVar16 >> (3 - uVar33) * 8;
        puVar23[3] = (iVar28 << uVar4 * 8 | uVar39 & 0xffffffffU >> (4 - uVar4) * 8) &
                     -1 << (uVar12 + 1) * 8 | uVar17 >> (3 - uVar12) * 8;
        puVar23[4] = (iVar9 << uVar5 * 8 | uVar38 & 0xffffffffU >> (4 - uVar5) * 8) &
                     -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
        puVar23[5] = (iVar10 << uVar6 * 8 | uVar37 & 0xffffffffU >> (4 - uVar6) * 8) &
                     -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
        puVar23[6] = uVar34;
        puVar23[7] = uVar31;
        if (local_ac != 0) {
          *(char *)(iVar46 + iVar22) = (char)((uint)local_b0 >> 8);
          *(undefined *)((int)puVar26 + 0x41) = (undefined)local_b0;
          if ((local_b0 != 0) || (local_b4 != 0)) {
            (*(code *)PTR_memcpy_006aabf4)(iVar46 + local_b8 + 0x42,local_b4,local_b0);
          }
        }
        iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar46,"client finished",0xf);
        if ((((iVar22 == 0) ||
             (iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar46,"server finished",0xf), iVar22 == 0))
            || (iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar46,"master secret",0xd), iVar22 == 0))
           || (iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar46,"key expansion",0xd), iVar22 == 0)) {
          uVar43 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x16f,&DAT_00647bcc,0x4b1);
        }
        else {
          uVar43 = tls1_PRF_constprop_1
                             (*(undefined4 *)(*(int *)(*(int *)(uVar21 + 0x58) + 0x344) + 0x24),
                              iVar46,iVar45,0,0,0,0,0,0,*(int *)(uVar21 + 0xc0) + 0x14,
                              *(undefined4 *)(*(int *)(uVar21 + 0xc0) + 0x10),piVar30,iVar44,piVar32
                             );
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar44);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar46);
      }
      return uVar43;
    }
    if ((local_64 << 10 & uVar21) != 0) {
      if (local_60 == 0) {
        piVar32 = (int *)0x146;
        pcVar35 = &DAT_00647bcc;
        local_b8 = 0x114;
        piVar30 = (int *)0x11c;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14);
        goto LAB_0049b79c;
      }
      local_b0 = 0x20;
      local_ac = 0;
      local_b8 = 0xd;
      piVar30 = param_3;
      piVar32 = (int *)(((uint)param_4 & 1) + iVar45);
      pcVar35 = local_78;
      iVar24 = tls1_P_hash_constprop_2();
      local_b4 = iVar22;
      if (iVar24 == 0) goto LAB_0049b79c;
      param_3 = (int *)((int)param_3 + iVar45);
      puVar26 = &local_5c;
      puVar27 = puVar23;
      if (((uint)puVar23 & 3) == 0 && ((uint *)(iVar46 + 0x18) <= &local_5c || &local_58 <= puVar23)
         ) {
        *(uint *)(iVar46 + 0x14) = *(uint *)(iVar46 + 0x14) ^ local_5c;
        *(uint *)(iVar46 + 0x18) = local_58 ^ *(uint *)(iVar46 + 0x18);
        pcVar35 = (char *)(local_44 ^ *(uint *)(iVar46 + 0x2c));
        in_t3 = local_48 ^ *(uint *)(iVar46 + 0x28);
        *(uint *)(iVar46 + 0x1c) = local_54 ^ *(uint *)(iVar46 + 0x1c);
        *(uint *)(iVar46 + 0x20) = local_50 ^ *(uint *)(iVar46 + 0x20);
        *(uint *)(iVar46 + 0x24) = local_4c ^ *(uint *)(iVar46 + 0x24);
        *(uint *)(iVar46 + 0x28) = in_t3;
        *(char **)(iVar46 + 0x2c) = pcVar35;
        *(uint *)(iVar46 + 0x30) = local_40 ^ *(uint *)(iVar46 + 0x30);
        *(uint *)(iVar46 + 0x38) = local_38 ^ *(uint *)(iVar46 + 0x38);
        *(uint *)(iVar46 + 0x34) = local_3c ^ *(uint *)(iVar46 + 0x34);
        *(uint *)(iVar46 + 0x3c) = local_34 ^ *(uint *)(iVar46 + 0x3c);
        *(uint *)(iVar46 + 0x40) = *(uint *)(iVar46 + 0x40) ^ local_30;
      }
      else {
        do {
          puVar25 = (uint *)((int)puVar26 + 1);
          *(byte *)puVar27 = *(byte *)puVar27 ^ *(byte *)puVar26;
          puVar26 = puVar25;
          puVar27 = (uint *)((int)puVar27 + 1);
        } while (puVar25 != &local_2c);
      }
    }
    iVar44 = iVar44 + 1;
    piVar30 = &local_64;
    piVar32 = &local_60;
    iVar24 = ssl_get_handshake_digest(iVar44);
  } while( true );
}

