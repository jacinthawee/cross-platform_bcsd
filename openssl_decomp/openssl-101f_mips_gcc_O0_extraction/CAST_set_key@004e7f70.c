
void CAST_set_key(CAST_KEY *key,int len,uchar *data)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint *local_144;
  int local_13c;
  int local_134;
  uint local_130;
  uint local_12c;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  int *local_78;
  uint *local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_memset_006aab00)(&local_ec,0,0x40);
  iVar18 = 0x10;
  if (len < 0x11) {
    iVar18 = len;
  }
  if (((((0 < iVar18) && (local_ec = (uint)*data, iVar18 != 1)) &&
       (local_e8 = (uint)data[1], iVar18 != 2)) &&
      (((local_e4 = (uint)data[2], iVar18 != 3 && (local_e0 = (uint)data[3], iVar18 != 4)) &&
       ((local_dc = (uint)data[4], iVar18 != 5 &&
        ((local_d8 = (uint)data[5], iVar18 != 6 && (local_d4 = (uint)data[6], iVar18 != 7)))))))) &&
     ((local_d0 = (uint)data[7], iVar18 != 8 &&
      (((((local_cc = (uint)data[8], iVar18 != 9 && (local_c8 = (uint)data[9], iVar18 != 10)) &&
         (local_c4 = (uint)data[10], iVar18 != 0xb)) &&
        ((local_c0 = (uint)data[0xb], iVar18 != 0xc && (local_bc = (uint)data[0xc], iVar18 != 0xd)))
        ) && ((local_b8 = (uint)data[0xd], iVar18 != 0xe &&
              (local_b4 = (uint)data[0xe], iVar18 == 0x10)))))))) {
    local_b0 = (uint)data[0xf];
  }
  uVar17 = *(uint *)(CAST_S_table6 + local_cc * 4);
  uVar4 = *(uint *)(CAST_S_table5 + local_c0 * 4);
  key->short_key = (uint)(iVar18 < 0xb);
  uVar8 = *(uint *)(CAST_S_table5 + local_b0 * 4);
  local_130 = local_ec << 0x18 | local_e8 << 0x10 | local_e0 | local_e4 << 8;
  local_12c = local_dc << 0x18 | local_d8 << 0x10 | local_d0 | local_d4 << 8;
  uVar3 = local_bc << 0x18 | local_b8 << 0x10 | local_b0 | local_b4 << 8;
  uVar29 = local_cc << 0x18 | local_c8 << 0x10 | local_c0 | local_c4 << 8;
  local_134 = local_c4 << 2;
  iVar18 = local_b8 << 2;
  iVar31 = local_bc << 2;
  local_13c = local_c8 << 2;
  iVar33 = local_b4 << 2;
  local_144 = &local_ac;
  do {
    uVar17 = *(uint *)(CAST_S_table4 + iVar18) ^ *(uint *)(CAST_S_table6 + iVar31) ^
             *(uint *)(CAST_S_table7 + iVar33) ^ local_130 ^ uVar8 ^ uVar17;
    iVar9 = (uVar17 >> 0x18) * 4;
    iVar33 = (uVar17 & 0xff) * 4;
    iVar18 = ((uVar17 << 0x10) >> 0x18) * 4;
    iVar34 = ((uVar17 << 8) >> 0x18) * 4;
    uVar8 = *(uint *)(CAST_S_table4 + iVar18);
    uVar19 = *(uint *)(CAST_S_table6 + iVar34);
    uVar5 = *(uint *)(CAST_S_table7 + iVar18);
    uVar29 = *(uint *)(CAST_S_table4 + iVar9) ^ *(uint *)(CAST_S_table7 + iVar33) ^
             *(uint *)(CAST_S_table7 + local_134) ^ *(uint *)(CAST_S_table5 + iVar18) ^ uVar19 ^
             uVar29;
    iVar10 = (uVar29 & 0xff) * 4;
    iVar18 = (uVar29 >> 0x18) * 4;
    iVar36 = ((uVar29 << 0x10) >> 0x18) * 4;
    iVar31 = ((uVar29 << 8) >> 0x18) * 4;
    uVar7 = *(uint *)(CAST_S_table6 + iVar10);
    uVar3 = *(uint *)(CAST_S_table7 + iVar18) ^ *(uint *)(CAST_S_table4 + iVar10) ^
            *(uint *)(CAST_S_table4 + local_13c) ^ *(uint *)(CAST_S_table5 + iVar36) ^
            *(uint *)(CAST_S_table6 + iVar31) ^ uVar3;
    uVar6 = *(uint *)(CAST_S_table6 + iVar33);
    iVar24 = ((uVar3 << 8) >> 0x18) * 4;
    iVar13 = (uVar3 & 0xff) * 4;
    iVar20 = (uVar3 >> 0x18) * 4;
    uVar23 = *(uint *)(CAST_S_table5 + iVar24);
    uVar25 = *(uint *)(CAST_S_table6 + iVar24);
    uVar37 = *(uint *)(CAST_S_table7 + iVar36);
    uVar26 = *(uint *)(CAST_S_table4 + iVar20);
    uVar4 = *(uint *)(CAST_S_table6 + iVar13) ^ *(uint *)(CAST_S_table7 + iVar20) ^
            *(uint *)(CAST_S_table4 + ((uVar3 << 0x10) >> 0x18) * 4) ^ uVar23 ^ local_12c ^ uVar4;
    iVar20 = (uVar4 >> 0x18) * 4;
    uVar27 = *(uint *)(CAST_S_table4 + iVar20);
    uVar21 = *(uint *)(CAST_S_table5 + ((uVar4 << 8) >> 0x18) * 4);
    uVar28 = *(uint *)(CAST_S_table5 + (uVar4 & 0xff) * 4);
    local_144[1] = *(uint *)(CAST_S_table5 + iVar36) ^ *(uint *)(CAST_S_table6 + iVar31) ^
                   *(uint *)(CAST_S_table7 + iVar18) ^ *(uint *)(CAST_S_table5 + iVar13) ^
                   *(uint *)(CAST_S_table4 + ((uVar3 << 0x10) >> 0x18) * 4);
    local_144[2] = uVar5 ^ uVar6 ^ uVar25 ^ uVar27 ^ uVar21;
    uVar27 = *(uint *)(CAST_S_table7 + iVar9);
    uVar6 = *(uint *)(CAST_S_table6 + iVar18);
    *local_144 = uVar7 ^ uVar8 ^ uVar37 ^ uVar26 ^ uVar23;
    uVar3 = *(uint *)(CAST_S_table5 + iVar10) ^ uVar6 ^ *(uint *)(CAST_S_table6 + iVar9) ^ uVar37 ^
            *(uint *)(CAST_S_table4 + iVar31) ^ uVar3;
    iVar13 = (uVar3 >> 0x18) * 4;
    iVar31 = (uVar3 & 0xff) * 4;
    iVar18 = ((uVar3 << 8) >> 0x18) * 4;
    uVar38 = *(uint *)(CAST_S_table5 + ((uVar3 << 0x10) >> 0x18) * 4);
    uVar5 = uVar17 ^ uVar5 ^ *(uint *)(CAST_S_table4 + iVar13) ^ *(uint *)(CAST_S_table7 + iVar31) ^
            uVar38 ^ *(uint *)(CAST_S_table6 + iVar18);
    iVar12 = (uVar5 & 0xff) * 4;
    iVar35 = (uVar5 >> 0x18) * 4;
    iVar9 = ((uVar5 << 8) >> 0x18) * 4;
    uVar39 = *(uint *)(CAST_S_table4 + iVar12);
    uVar21 = *(uint *)(CAST_S_table5 + ((uVar5 << 0x10) >> 0x18) * 4);
    uVar8 = uVar29 ^ *(uint *)(CAST_S_table4 + iVar34) ^ uVar39 ^ *(uint *)(CAST_S_table7 + iVar35)
            ^ uVar21 ^ *(uint *)(CAST_S_table6 + iVar9);
    uVar7 = *(uint *)(CAST_S_table4 + iVar18);
    iVar30 = (uVar8 & 0xff) * 4;
    iVar10 = ((uVar8 << 0x10) >> 0x18) * 4;
    iVar24 = (uVar8 >> 0x18) * 4;
    uVar6 = *(uint *)(CAST_S_table4 + iVar31);
    iVar14 = ((uVar8 << 8) >> 0x18) * 4;
    uVar17 = *(uint *)(CAST_S_table5 + iVar13);
    uVar29 = uVar4 ^ *(uint *)(CAST_S_table5 + iVar33) ^ *(uint *)(CAST_S_table6 + iVar30) ^
             *(uint *)(CAST_S_table7 + iVar24) ^ *(uint *)(CAST_S_table4 + iVar10) ^
             *(uint *)(CAST_S_table5 + iVar14);
    iVar13 = (uVar29 & 0xff) * 4;
    iVar33 = ((uVar29 << 0x10) >> 0x18) * 4;
    iVar18 = ((uVar29 << 8) >> 0x18) * 4;
    uVar25 = *(uint *)(CAST_S_table7 + iVar13);
    uVar23 = *(uint *)(CAST_S_table6 + iVar33);
    uVar26 = *(uint *)(CAST_S_table4 + iVar24);
    uVar37 = *(uint *)(CAST_S_table5 + iVar18);
    uVar40 = *(uint *)(CAST_S_table6 + (uVar29 >> 0x18) * 4);
    uVar32 = *(uint *)(CAST_S_table7 + iVar18);
    local_144[3] = uVar19 ^ uVar27 ^ uVar28 ^ *(uint *)(CAST_S_table7 + iVar20) ^
                   *(uint *)(CAST_S_table4 + ((uVar4 << 0x10) >> 0x18) * 4);
    local_144[4] = uVar38 ^ uVar6 ^ uVar26 ^ uVar40 ^ uVar32;
    local_144[5] = uVar7 ^ uVar17 ^ uVar25 ^ uVar23 ^ uVar37;
    uVar19 = *(uint *)(CAST_S_table6 + iVar24);
    uVar6 = *(uint *)(CAST_S_table6 + iVar31);
    uVar27 = uVar3 ^ uVar19 ^ uVar40 ^ *(uint *)(CAST_S_table5 + iVar13) ^
             *(uint *)(CAST_S_table4 + iVar18) ^ *(uint *)(CAST_S_table7 + iVar33);
    iVar13 = (uVar27 >> 0x18) * 4;
    iVar24 = (uVar27 & 0xff) * 4;
    iVar36 = ((uVar27 << 0x10) >> 0x18) * 4;
    iVar15 = ((uVar27 << 8) >> 0x18) * 4;
    uVar7 = uVar8 ^ *(uint *)(CAST_S_table7 + iVar10) ^ *(uint *)(CAST_S_table4 + iVar13) ^
            *(uint *)(CAST_S_table7 + iVar24) ^ *(uint *)(CAST_S_table5 + iVar36) ^
            *(uint *)(CAST_S_table6 + iVar15);
    iVar22 = (uVar7 & 0xff) * 4;
    iVar18 = (uVar7 >> 0x18) * 4;
    uVar17 = *(uint *)(CAST_S_table4 + iVar22);
    iVar11 = ((uVar7 << 0x10) >> 0x18) * 4;
    iVar16 = ((uVar7 << 8) >> 0x18) * 4;
    uVar26 = *(uint *)(CAST_S_table5 + iVar11);
    local_130 = uVar29 ^ *(uint *)(CAST_S_table4 + iVar14) ^ uVar17 ^
                *(uint *)(CAST_S_table7 + iVar18) ^ uVar26 ^ *(uint *)(CAST_S_table6 + iVar16);
    iVar31 = (local_130 & 0xff) * 4;
    iVar34 = (local_130 >> 0x18) * 4;
    iVar33 = ((local_130 << 0x10) >> 0x18) * 4;
    iVar20 = ((local_130 << 8) >> 0x18) * 4;
    uVar4 = uVar5 ^ *(uint *)(CAST_S_table5 + iVar30) ^ *(uint *)(CAST_S_table6 + iVar31) ^
            *(uint *)(CAST_S_table7 + iVar34) ^ *(uint *)(CAST_S_table4 + iVar33) ^
            *(uint *)(CAST_S_table5 + iVar20);
    uVar8 = *(uint *)(CAST_S_table5 + iVar35);
    iVar35 = (uVar4 >> 0x18) * 4;
    uVar23 = *(uint *)(CAST_S_table7 + iVar30);
    uVar3 = *(uint *)(CAST_S_table7 + iVar12);
    uVar29 = *(uint *)(CAST_S_table4 + iVar9);
    uVar5 = *(uint *)(CAST_S_table6 + iVar10);
    uVar25 = *(uint *)(CAST_S_table7 + iVar14);
    local_144[8] = *(uint *)(CAST_S_table5 + iVar36) ^ *(uint *)(CAST_S_table4 + iVar24) ^
                   *(uint *)(CAST_S_table4 + iVar20) ^ *(uint *)(CAST_S_table6 + iVar35) ^
                   *(uint *)(CAST_S_table7 + ((uVar4 << 8) >> 0x18) * 4);
    local_144[7] = uVar8 ^ uVar3 ^ uVar29 ^ uVar23 ^ uVar5;
    uVar29 = *(uint *)(CAST_S_table5 + iVar22);
    uVar5 = *(uint *)(CAST_S_table6 + iVar18);
    uVar8 = *(uint *)(CAST_S_table6 + iVar13);
    uVar32 = *(uint *)(CAST_S_table4 + iVar16);
    local_144[6] = uVar39 ^ uVar6 ^ uVar21 ^ uVar19 ^ uVar25;
    uVar3 = *(uint *)(CAST_S_table7 + iVar11);
    local_130 = uVar29 ^ uVar5 ^ uVar8 ^ uVar32 ^ uVar3 ^ local_130;
    iVar11 = (local_130 >> 0x18) * 4;
    iVar9 = (local_130 & 0xff) * 4;
    iVar12 = ((local_130 << 0x10) >> 0x18) * 4;
    uVar38 = *(uint *)(CAST_S_table6 + ((local_130 << 8) >> 0x18) * 4);
    local_12c = uVar27 ^ *(uint *)(CAST_S_table7 + iVar36) ^ *(uint *)(CAST_S_table4 + iVar11) ^
                *(uint *)(CAST_S_table7 + iVar9) ^ *(uint *)(CAST_S_table5 + iVar12) ^ uVar38;
    iVar14 = ((local_12c << 0x10) >> 0x18) * 4;
    iVar10 = (local_12c & 0xff) * 4;
    uVar40 = *(uint *)(CAST_S_table7 + (local_12c >> 0x18) * 4);
    uVar27 = *(uint *)(CAST_S_table6 + ((local_12c << 8) >> 0x18) * 4);
    uVar37 = *(uint *)(CAST_S_table6 + iVar36);
    uVar39 = *(uint *)(CAST_S_table5 + iVar18);
    uVar29 = uVar7 ^ *(uint *)(CAST_S_table4 + iVar15) ^ *(uint *)(CAST_S_table4 + iVar10) ^ uVar40
             ^ *(uint *)(CAST_S_table5 + iVar14) ^ uVar27;
    uVar23 = *(uint *)(CAST_S_table6 + iVar34);
    uVar19 = *(uint *)(CAST_S_table7 + iVar31);
    uVar6 = *(uint *)(CAST_S_table7 + iVar20);
    uVar5 = *(uint *)(CAST_S_table6 + iVar33);
    iVar18 = (uVar29 & 0xff) * 4;
    local_13c = ((uVar29 << 8) >> 0x18) * 4;
    iVar20 = (uVar29 >> 0x18) * 4;
    local_134 = ((uVar29 << 0x10) >> 0x18) * 4;
    uVar28 = *(uint *)(CAST_S_table5 + iVar24);
    uVar25 = *(uint *)(CAST_S_table6 + iVar18);
    uVar21 = *(uint *)(CAST_S_table5 + local_13c);
    uVar8 = *(uint *)(CAST_S_table7 + iVar20);
    uVar7 = *(uint *)(CAST_S_table4 + local_134);
    local_144[9] = *(uint *)(CAST_S_table4 + iVar15) ^ *(uint *)(CAST_S_table5 + iVar13) ^
                   *(uint *)(CAST_S_table7 + (uVar4 & 0xff) * 4) ^ *(uint *)(CAST_S_table5 + iVar35)
                   ^ *(uint *)(CAST_S_table6 + ((uVar4 << 0x10) >> 0x18) * 4);
    local_144[10] = uVar17 ^ uVar37 ^ uVar26 ^ uVar23 ^ uVar6;
    local_144[0xb] = uVar32 ^ uVar3 ^ uVar39 ^ uVar19 ^ uVar5;
    uVar3 = uVar4 ^ uVar28 ^ uVar25 ^ uVar8 ^ uVar7 ^ uVar21;
    uVar32 = *(uint *)(CAST_S_table6 + iVar10);
    uVar5 = *(uint *)(CAST_S_table4 + iVar9);
    uVar41 = *(uint *)(CAST_S_table7 + iVar11);
    uVar28 = *(uint *)(CAST_S_table6 + iVar9);
    iVar31 = (uVar3 >> 0x18) * 4;
    iVar33 = ((uVar3 << 0x10) >> 0x18) * 4;
    uVar17 = *(uint *)(CAST_S_table6 + iVar20);
    uVar39 = *(uint *)(CAST_S_table7 + iVar14);
    uVar8 = *(uint *)(CAST_S_table5 + (uVar3 & 0xff) * 4);
    uVar4 = *(uint *)(CAST_S_table5 + iVar18);
    uVar6 = *(uint *)(CAST_S_table7 + iVar12);
    uVar25 = *(uint *)(CAST_S_table4 + iVar20);
    uVar23 = *(uint *)(CAST_S_table4 + iVar31);
    uVar19 = *(uint *)(CAST_S_table4 + iVar33);
    iVar18 = ((uVar3 << 8) >> 0x18) * 4;
    uVar37 = *(uint *)(CAST_S_table5 + iVar18);
    uVar26 = *(uint *)(CAST_S_table7 + iVar18);
    local_144[0xd] = uVar40 ^ *(uint *)(CAST_S_table5 + iVar10) ^ uVar27 ^ uVar4 ^ uVar7;
    local_144[0xc] = uVar32 ^ uVar5 ^ uVar39 ^ uVar25 ^ uVar21;
    local_144[0xe] = uVar28 ^ uVar6 ^ uVar17 ^ uVar23 ^ uVar37;
    bVar1 = local_144 == &local_ac;
    local_144[0xf] = uVar38 ^ uVar41 ^ uVar8 ^ uVar19 ^ uVar26;
    local_144 = &local_6c;
  } while (bVar1);
  key->data[1] = local_6c + 0x10 & 0x1f;
  key->data[3] = local_68 + 0x10U & 0x1f;
  key->data[5] = local_64 + 0x10U & 0x1f;
  key->data[7] = local_60 + 0x10U & 0x1f;
  key->data[9] = local_5c + 0x10U & 0x1f;
  key->data[0xb] = local_58 + 0x10U & 0x1f;
  key->data[0xd] = local_54 + 0x10U & 0x1f;
  key->data[0] = local_ac;
  key->data[2] = local_a8;
  key->data[4] = local_a4;
  key->data[6] = local_a0;
  key->data[8] = local_9c;
  key->data[10] = local_98;
  key->data[0xc] = local_94;
  key->data[0xe] = local_90;
  key->data[0xf] = local_50 + 0x10U & 0x1f;
  key->data[0x11] = local_4c + 0x10U & 0x1f;
  key->data[0x13] = local_48 + 0x10U & 0x1f;
  key->data[0x15] = local_44 + 0x10U & 0x1f;
  key->data[0x17] = local_40 + 0x10U & 0x1f;
  key->data[0x19] = local_3c + 0x10U & 0x1f;
  key->data[0x1b] = local_38 + 0x10U & 0x1f;
  key->data[0x1d] = local_34 + 0x10U & 0x1f;
  key->data[0x10] = local_8c;
  key->data[0x1f] = local_30 + 0x10U & 0x1f;
  key->data[0x12] = local_88;
  key->data[0x14] = local_84;
  key->data[0x16] = local_80;
  key->data[0x18] = local_7c;
  key->data[0x1a] = (uint)local_78;
  key->data[0x1c] = (uint)local_74;
  key->data[0x1e] = local_70;
  if (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar4 = local_74[1] + *local_78;
    uVar4 = (uVar4 >> (-local_78[1] & 0x1fU)) + (uVar4 << 0x20 - (-local_78[1] & 0x1fU));
    uVar3 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar4 * 0x10000 >> 0x18) * 4) ^
            *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar4 & 0xff) * 4)) +
            (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar4 * 0x100 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar4 >> 0x18) * 4)) ^ *local_74;
    uVar4 = uVar3 ^ local_78[2];
    uVar4 = (uVar4 >> (-local_78[3] & 0x1fU)) + (uVar4 << 0x20 - (-local_78[3] & 0x1fU));
    uVar29 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar4 * 0x10000 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar4 & 0xff) * 4)) +
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar4 >> 0x18) * 4) ^
             local_74[1] ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar4 * 0x100 >> 0x18) * 4);
    uVar4 = local_78[4] - uVar29;
    uVar4 = (uVar4 >> (-local_78[5] & 0x1fU)) + (uVar4 << 0x20 - (-local_78[5] & 0x1fU));
    uVar3 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar4 * 0x10000 >> 0x18) * 4) +
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar4 & 0xff) * 4) ^
            *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar4 >> 0x18) * 4)) -
            *(int *)(PTR_CAST_S_table3_006a9614 + (uVar4 * 0x100 >> 0x18) * 4) ^ uVar3;
    uVar4 = uVar3 + local_78[6];
    uVar4 = (uVar4 >> (-local_78[7] & 0x1fU)) + (uVar4 << 0x20 - (-local_78[7] & 0x1fU));
    uVar29 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar4 * 0x10000 >> 0x18) * 4) ^
             *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar4 & 0xff) * 4)) +
             (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar4 * 0x100 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar4 >> 0x18) * 4)) ^ uVar29;
    uVar4 = uVar29 ^ local_78[8];
    uVar4 = (uVar4 >> (-local_78[9] & 0x1fU)) + (uVar4 << 0x20 - (-local_78[9] & 0x1fU));
    uVar4 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar4 * 0x10000 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table1_006a9620 + (uVar4 & 0xff) * 4)) +
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar4 >> 0x18) * 4) ^
            uVar3 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar4 * 0x100 >> 0x18) * 4);
    uVar3 = local_78[10] - uVar4;
    uVar3 = (uVar3 >> (-local_78[0xb] & 0x1fU)) + (uVar3 << 0x20 - (-local_78[0xb] & 0x1fU));
    uVar29 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar3 * 0x10000 >> 0x18) * 4) +
              *(int *)(PTR_CAST_S_table1_006a9620 + (uVar3 & 0xff) * 4) ^
             *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar3 >> 0x18) * 4)) -
             *(int *)(PTR_CAST_S_table3_006a9614 + (uVar3 * 0x100 >> 0x18) * 4) ^ uVar29;
    uVar3 = uVar29 + local_78[0xc];
    uVar3 = (uVar3 >> (-local_78[0xd] & 0x1fU)) + (uVar3 << 0x20 - (-local_78[0xd] & 0x1fU));
    uVar4 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar3 * 0x10000 >> 0x18) * 4) ^
            *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar3 & 0xff) * 4)) +
            (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar3 * 0x100 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar3 >> 0x18) * 4)) ^ uVar4;
    uVar3 = uVar4 ^ local_78[0xe];
    uVar3 = (uVar3 >> (-local_78[0xf] & 0x1fU)) + (uVar3 << 0x20 - (-local_78[0xf] & 0x1fU));
    uVar3 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar3 * 0x10000 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table1_006a9620 + (uVar3 & 0xff) * 4)) +
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar3 >> 0x18) * 4) ^
            uVar29 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar3 * 0x100 >> 0x18) * 4);
    uVar29 = local_78[0x10] - uVar3;
    uVar29 = (uVar29 >> (-local_78[0x11] & 0x1fU)) + (uVar29 << 0x20 - (-local_78[0x11] & 0x1fU));
    uVar4 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) +
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4) ^
            *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4)) -
            *(int *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4) ^ uVar4;
    uVar29 = uVar4 + local_78[0x12];
    uVar29 = (uVar29 >> (-local_78[0x13] & 0x1fU)) + (uVar29 << 0x20 - (-local_78[0x13] & 0x1fU));
    uVar3 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) ^
            *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4)) +
            (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4)) ^ uVar3;
    uVar29 = uVar3 ^ local_78[0x14];
    uVar29 = (uVar29 >> (-local_78[0x15] & 0x1fU)) + (uVar29 << 0x20 - (-local_78[0x15] & 0x1fU));
    uVar4 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4)) +
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4) ^
            uVar4 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4);
    uVar29 = (local_78[0x16] - uVar4 >> (-local_78[0x17] & 0x1fU)) +
             (local_78[0x16] - uVar4 << 0x20 - (-local_78[0x17] & 0x1fU));
    uVar3 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) +
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4) ^
            *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4)) -
            *(int *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4) ^ uVar3;
    if (local_78[0x20] == 0) {
      uVar29 = (uVar3 + local_78[0x18] >> (-local_78[0x19] & 0x1fU)) +
               (uVar3 + local_78[0x18] << 0x20 - (-local_78[0x19] & 0x1fU));
      uVar4 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) ^
              *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4)) +
              (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4) -
              *(int *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4)) ^ uVar4;
      uVar29 = uVar4 ^ local_78[0x1a];
      uVar29 = (uVar29 >> (-local_78[0x1b] & 0x1fU)) + (uVar29 << 0x20 - (-local_78[0x1b] & 0x1fU));
      uVar3 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) -
              *(int *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4)) +
              *(int *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4) ^
              uVar3 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4);
      uVar29 = local_78[0x1c] - uVar3;
      uVar29 = (uVar29 >> (-local_78[0x1d] & 0x1fU)) + (uVar29 << 0x20 - (-local_78[0x1d] & 0x1fU));
      uVar4 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) +
               *(int *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4) ^
              *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4)) -
              *(int *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4) ^ uVar4;
      uVar29 = (uVar4 + local_78[0x1e] >> (-local_78[0x1f] & 0x1fU)) +
               (uVar4 + local_78[0x1e] << 0x20 - (-local_78[0x1f] & 0x1fU));
      uVar3 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar29 * 0x10000 >> 0x18) * 4) ^
              *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar29 & 0xff) * 4)) +
              (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar29 * 0x100 >> 0x18) * 4) -
              *(int *)(PTR_CAST_S_table2_006a9618 + (uVar29 >> 0x18) * 4)) ^ uVar3;
    }
    local_74[1] = uVar4;
    *local_74 = uVar3;
    return;
  }
  return;
}

