
void CAST_set_key(CAST_KEY *key,int len,uchar *data)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint *local_11c;
  uint local_118;
  uint local_114;
  uint local_10c;
  uint local_108;
  uint local_104;
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
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
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
  
  memset(&local_e8,0,0x40);
  iVar5 = 0x10;
  if (len < 0x11) {
    iVar5 = len;
  }
  if (((((0 < iVar5) && (local_e8 = (uint)*data, 1 < iVar5)) &&
       (local_e4 = (uint)data[1], 2 < iVar5)) &&
      (((local_e0 = (uint)data[2], 3 < iVar5 && (local_dc = (uint)data[3], 4 < iVar5)) &&
       ((local_d8 = (uint)data[4], 5 < iVar5 &&
        ((local_d4 = (uint)data[5], 6 < iVar5 && (local_d0 = (uint)data[6], 7 < iVar5)))))))) &&
     ((local_cc = (uint)data[7], 8 < iVar5 &&
      (((((local_c8 = (uint)data[8], 9 < iVar5 && (local_c4 = (uint)data[9], 10 < iVar5)) &&
         (local_c0 = (uint)data[10], 0xb < iVar5)) &&
        ((local_bc = (uint)data[0xb], 0xc < iVar5 && (local_b8 = (uint)data[0xc], 0xd < iVar5)))) &&
       ((local_b4 = (uint)data[0xd], 0xe < iVar5 && (local_b0 = (uint)data[0xe], 0xf < iVar5))))))))
  {
    local_ac = (uint)data[0xf];
  }
  iVar4 = iVar5;
  if (10 < iVar5) {
    iVar4 = 0;
  }
  local_104 = local_c4;
  if (iVar5 < 0xb) {
    iVar4 = 1;
  }
  key->short_key = iVar4;
  local_118 = local_e4 << 0x10 | local_e8 << 0x18 | local_dc | local_e0 << 8;
  iVar5 = local_b4 << 2;
  local_10c = local_d4 << 0x10 | local_d8 << 0x18 | local_cc | local_d0 << 8;
  iVar4 = local_b8 << 2;
  uVar20 = local_c4 << 0x10 | local_c8 << 0x18 | local_bc | local_c0 << 8;
  local_108 = *(uint *)(&CAST_S_table5 + local_bc * 4);
  iVar16 = local_c0 << 2;
  uVar12 = *(uint *)(CAST_S_table6 + local_c8 * 4);
  iVar22 = local_b0 << 2;
  uVar9 = *(uint *)(&CAST_S_table5 + local_ac * 4);
  local_11c = &local_a8;
  local_114 = local_b4 << 0x10 | local_b8 << 0x18 | local_ac | local_b0 << 8;
  while( true ) {
    uVar12 = uVar12 ^ uVar9 ^ *(uint *)(CAST_S_table6 + iVar4) ^ *(uint *)(CAST_S_table4 + iVar5) ^
                              *(uint *)(CAST_S_table7 + iVar22) ^ local_118;
    uVar9 = (uVar12 << 0x10) >> 0x18;
    iVar5 = ((uVar12 << 8) >> 0x18) * 4;
    iVar4 = (uVar12 >> 0x18) * 4;
    iVar22 = (uVar12 & 0xff) * 4;
    iVar1 = uVar9 * 4;
    uVar10 = *(uint *)(CAST_S_table6 + iVar5);
    uVar6 = *(uint *)(CAST_S_table6 + iVar22);
    uVar17 = *(uint *)(CAST_S_table4 + iVar1);
    uVar7 = *(uint *)(CAST_S_table7 + iVar1);
    uVar8 = *(uint *)(CAST_S_table7 + iVar4);
    uVar20 = *(uint *)(CAST_S_table4 + iVar4) ^ *(uint *)(CAST_S_table7 + iVar22) ^
             *(uint *)(CAST_S_table7 + iVar16) ^ *(uint *)(&CAST_S_table5 + uVar9 * 4) ^ uVar10 ^
             uVar20;
    iVar16 = ((uVar20 << 8) >> 0x18) * 4;
    iVar22 = (uVar20 >> 0x18) * 4;
    iVar1 = (uVar20 & 0xff) * 4;
    uVar25 = (uVar20 << 0x10) >> 0x18;
    uVar11 = *(uint *)(CAST_S_table6 + iVar1);
    uVar14 = *(uint *)(CAST_S_table7 + uVar25 * 4);
    local_114 = *(uint *)(CAST_S_table4 + iVar1) ^ *(uint *)(CAST_S_table7 + iVar22) ^
                *(uint *)(CAST_S_table4 + local_104 * 4) ^ *(uint *)(&CAST_S_table5 + uVar25 * 4) ^
                *(uint *)(CAST_S_table6 + iVar16) ^ local_114;
    uVar9 = (local_114 << 8) >> 0x18;
    iVar1 = (local_114 >> 0x18) * 4;
    uVar15 = *(uint *)(&CAST_S_table5 + uVar9 * 4);
    uVar24 = *(uint *)(CAST_S_table6 + uVar9 * 4);
    uVar18 = *(uint *)(CAST_S_table4 + iVar1);
    local_108 = *(uint *)(CAST_S_table7 + iVar1) ^ *(uint *)(CAST_S_table6 + (local_114 & 0xff) * 4)
                ^ *(uint *)(CAST_S_table4 + ((local_114 << 0x10) >> 0x18) * 4) ^ uVar15 ^ local_10c
                ^ local_108;
    iVar1 = (local_108 >> 0x18) * 4;
    uVar21 = *(uint *)(&CAST_S_table5 + (local_108 & 0xff) * 4);
    uVar26 = *(uint *)(&CAST_S_table5 + ((local_108 << 8) >> 0x18) * 4);
    uVar23 = *(uint *)(CAST_S_table4 + iVar1);
    uVar13 = *(uint *)(CAST_S_table7 + iVar1);
    uVar19 = *(uint *)(CAST_S_table4 + ((local_108 << 0x10) >> 0x18) * 4);
    uVar9 = *(uint *)(CAST_S_table6 + iVar4);
    local_11c[1] = *(uint *)(&CAST_S_table5 + uVar25 * 4) ^ *(uint *)(CAST_S_table6 + iVar16) ^
                   *(uint *)(CAST_S_table7 + iVar22) ^
                   *(uint *)(&CAST_S_table5 + (local_114 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table4 + ((local_114 << 0x10) >> 0x18) * 4);
    local_11c[2] = uVar7 ^ uVar6 ^ uVar24 ^ uVar23 ^ uVar26;
    local_11c[3] = uVar8 ^ uVar10 ^ uVar21 ^ uVar13 ^ uVar19;
    uVar6 = *(uint *)(CAST_S_table6 + iVar22);
    uVar8 = *(uint *)(&CAST_S_table5 + (uVar20 & 0xff) * 4);
    *local_11c = uVar11 ^ uVar17 ^ uVar14 ^ uVar18 ^ uVar15;
    local_114 = uVar8 ^ uVar6 ^ uVar9 ^ uVar14 ^ *(uint *)(CAST_S_table4 + iVar16) ^ local_114;
    iVar4 = ((local_114 << 8) >> 0x18) * 4;
    uVar15 = *(uint *)(&CAST_S_table5 + ((local_114 << 0x10) >> 0x18) * 4);
    iVar16 = (local_114 & 0xff) * 4;
    uVar26 = *(uint *)(CAST_S_table4 + iVar4);
    uVar9 = *(uint *)(&CAST_S_table5 + (local_114 >> 0x18) * 4);
    uVar7 = *(uint *)(CAST_S_table6 + iVar4) ^
            *(uint *)(CAST_S_table7 + iVar16) ^
            *(uint *)(CAST_S_table4 + (local_114 >> 0x18) * 4) ^ uVar7 ^ uVar12 ^ uVar15;
    uVar25 = *(uint *)(CAST_S_table4 + iVar16);
    iVar4 = ((uVar7 << 8) >> 0x18) * 4;
    iVar22 = (uVar7 & 0xff) * 4;
    uVar14 = *(uint *)(&CAST_S_table5 + (uVar7 >> 0x18) * 4);
    uVar13 = *(uint *)(CAST_S_table7 + iVar22);
    uVar10 = *(uint *)(CAST_S_table4 + iVar4);
    uVar8 = *(uint *)(CAST_S_table7 + (uVar7 >> 0x18) * 4) ^
            uVar20 ^ *(uint *)(CAST_S_table4 + iVar5) ^ *(uint *)(CAST_S_table4 + iVar22) ^
            *(uint *)(&CAST_S_table5 + ((uVar7 << 0x10) >> 0x18) * 4) ^
            *(uint *)(CAST_S_table6 + iVar4);
    uVar6 = (uVar8 << 8) >> 0x18;
    iVar5 = (uVar8 & 0xff) * 4;
    iVar4 = (uVar8 >> 0x18) * 4;
    iVar1 = uVar6 * 4;
    iVar2 = ((uVar8 << 0x10) >> 0x18) * 4;
    uVar19 = *(uint *)(CAST_S_table4 + iVar4);
    uVar20 = *(uint *)(CAST_S_table6 + iVar4);
    uVar11 = *(uint *)(&CAST_S_table5 + (uVar12 & 0xff) * 4) ^ local_108 ^
             *(uint *)(CAST_S_table6 + iVar5) ^ *(uint *)(CAST_S_table7 + iVar4) ^
             *(uint *)(CAST_S_table4 + iVar2) ^ *(uint *)(&CAST_S_table5 + uVar6 * 4);
    uVar17 = *(uint *)(CAST_S_table7 + iVar5);
    iVar5 = ((uVar11 << 0x10) >> 0x18) * 4;
    uVar6 = (uVar11 << 8) >> 0x18;
    iVar4 = uVar6 * 4;
    uVar24 = *(uint *)(CAST_S_table7 + (uVar11 & 0xff) * 4);
    uVar12 = *(uint *)(CAST_S_table6 + (uVar11 >> 0x18) * 4);
    uVar21 = *(uint *)(CAST_S_table6 + iVar5);
    uVar18 = *(uint *)(&CAST_S_table5 + uVar6 * 4);
    uVar6 = *(uint *)(CAST_S_table7 + iVar5);
    uVar23 = *(uint *)(CAST_S_table6 + iVar2);
    local_11c[6] = *(uint *)(CAST_S_table4 + iVar22) ^ *(uint *)(CAST_S_table6 + iVar16) ^
                   *(uint *)(&CAST_S_table5 + ((uVar7 << 0x10) >> 0x18) * 4) ^ uVar20 ^
                   *(uint *)(CAST_S_table7 + iVar1);
    local_11c[5] = uVar26 ^ uVar9 ^ uVar24 ^ uVar21 ^ uVar18;
    uVar18 = *(uint *)(CAST_S_table7 + iVar4);
    uVar9 = *(uint *)(CAST_S_table4 + iVar4);
    local_11c[7] = uVar13 ^ uVar14 ^ uVar10 ^ uVar17 ^ uVar23;
    local_11c[4] = uVar15 ^ uVar25 ^ uVar19 ^ uVar12 ^ uVar18;
    uVar6 = *(uint *)(&CAST_S_table5 + (uVar11 & 0xff) * 4) ^ uVar20 ^ local_114 ^ uVar12 ^ uVar9 ^
            uVar6;
    uVar20 = (uVar6 << 0x10) >> 0x18;
    iVar5 = (uVar6 >> 0x18) * 4;
    iVar4 = (uVar6 & 0xff) * 4;
    iVar16 = ((uVar6 << 8) >> 0x18) * 4;
    iVar22 = uVar20 * 4;
    uVar14 = *(uint *)(&CAST_S_table5 + (uVar6 >> 0x18) * 4);
    uVar9 = uVar8 ^ *(uint *)(CAST_S_table7 + iVar2) ^ *(uint *)(CAST_S_table4 + iVar5) ^
            *(uint *)(CAST_S_table7 + iVar4) ^ *(uint *)(&CAST_S_table5 + uVar20 * 4) ^
            *(uint *)(CAST_S_table6 + iVar16);
    uVar10 = (uVar9 << 0x10) >> 0x18;
    uVar15 = *(uint *)(&CAST_S_table5 + uVar10 * 4);
    iVar2 = ((uVar9 << 8) >> 0x18) * 4;
    iVar3 = (uVar9 >> 0x18) * 4;
    uVar24 = *(uint *)(CAST_S_table4 + (uVar9 & 0xff) * 4);
    uVar13 = *(uint *)(&CAST_S_table5 + (uVar9 >> 0x18) * 4);
    uVar12 = *(uint *)(CAST_S_table4 + iVar16);
    uVar10 = *(uint *)(CAST_S_table7 + uVar10 * 4);
    uVar21 = *(uint *)(CAST_S_table4 + iVar2);
    local_118 = uVar11 ^ *(uint *)(CAST_S_table4 + iVar1) ^ uVar24 ^
                *(uint *)(CAST_S_table7 + iVar3) ^ uVar15 ^ *(uint *)(CAST_S_table6 + iVar2);
    uVar18 = (local_118 << 8) >> 0x18;
    iVar16 = (local_118 & 0xff) * 4;
    iVar1 = (local_118 >> 0x18) * 4;
    iVar2 = ((local_118 << 0x10) >> 0x18) * 4;
    uVar17 = *(uint *)(CAST_S_table7 + iVar16);
    uVar11 = *(uint *)(&CAST_S_table5 + uVar18 * 4) ^
             uVar7 ^ *(uint *)(&CAST_S_table5 + (uVar8 & 0xff) * 4) ^
             *(uint *)(CAST_S_table6 + iVar16) ^ *(uint *)(CAST_S_table7 + iVar1) ^
             *(uint *)(CAST_S_table4 + iVar2);
    uVar23 = *(uint *)(CAST_S_table6 + iVar2);
    iVar16 = uVar18 * 4;
    uVar25 = *(uint *)(CAST_S_table6 + iVar1);
    uVar7 = *(uint *)(CAST_S_table6 + iVar22);
    uVar18 = *(uint *)(CAST_S_table7 + (uVar11 & 0xff) * 4);
    uVar8 = *(uint *)(&CAST_S_table5 + (uVar11 >> 0x18) * 4);
    uVar19 = *(uint *)(CAST_S_table7 + iVar16);
    uVar26 = *(uint *)(CAST_S_table6 + ((uVar11 << 0x10) >> 0x18) * 4);
    local_11c[8] = *(uint *)(CAST_S_table4 + iVar16) ^
                   *(uint *)(&CAST_S_table5 + uVar20 * 4) ^ *(uint *)(CAST_S_table4 + iVar4) ^
                   *(uint *)(CAST_S_table6 + (uVar11 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table7 + ((uVar11 << 8) >> 0x18) * 4);
    local_11c[9] = uVar12 ^ uVar14 ^ uVar18 ^ uVar8 ^ uVar26;
    local_11c[0xb] = uVar21 ^ uVar10 ^ uVar13 ^ uVar17 ^ uVar23;
    local_11c[10] = uVar24 ^ uVar7 ^ uVar15 ^ uVar25 ^ uVar19;
    local_118 = *(uint *)(CAST_S_table6 + iVar3) ^ *(uint *)(&CAST_S_table5 + (uVar9 & 0xff) * 4) ^
                *(uint *)(CAST_S_table6 + iVar5) ^ uVar21 ^ uVar10 ^ local_118;
    iVar5 = (local_118 >> 0x18) * 4;
    iVar4 = (local_118 & 0xff) * 4;
    uVar20 = (local_118 << 0x10) >> 0x18;
    uVar23 = *(uint *)(CAST_S_table7 + iVar5);
    uVar21 = *(uint *)(CAST_S_table7 + uVar20 * 4);
    uVar7 = *(uint *)(CAST_S_table4 + iVar4);
    uVar14 = *(uint *)(CAST_S_table6 + ((local_118 << 8) >> 0x18) * 4);
    local_10c = *(uint *)(&CAST_S_table5 + uVar20 * 4) ^
                *(uint *)(CAST_S_table7 + iVar4) ^
                uVar6 ^ *(uint *)(CAST_S_table7 + iVar22) ^ *(uint *)(CAST_S_table4 + iVar5) ^
                uVar14;
    uVar8 = *(uint *)(CAST_S_table6 + iVar4);
    uVar20 = (local_10c << 0x10) >> 0x18;
    iVar5 = (local_10c & 0xff) * 4;
    uVar10 = *(uint *)(CAST_S_table6 + iVar5);
    uVar15 = *(uint *)(CAST_S_table7 + uVar20 * 4);
    uVar20 = uVar12 ^ uVar9 ^ *(uint *)(CAST_S_table4 + iVar5) ^
             *(uint *)(CAST_S_table7 + (local_10c >> 0x18) * 4) ^
             *(uint *)(&CAST_S_table5 + uVar20 * 4) ^
             *(uint *)(CAST_S_table6 + ((local_10c << 8) >> 0x18) * 4);
    local_104 = (uVar20 << 8) >> 0x18;
    uVar13 = *(uint *)(&CAST_S_table5 + local_104 * 4);
    iVar16 = ((uVar20 << 0x10) >> 0x18) * 4;
    local_108 = *(uint *)(&CAST_S_table5 + (uVar20 & 0xff) * 4);
    iVar5 = (uVar20 >> 0x18) * 4;
    uVar12 = *(uint *)(CAST_S_table6 + iVar5);
    local_114 = uVar13 ^ *(uint *)(&CAST_S_table5 + (uVar6 & 0xff) * 4) ^ uVar11 ^
                         *(uint *)(CAST_S_table6 + (uVar20 & 0xff) * 4) ^
                         *(uint *)(CAST_S_table7 + iVar5) ^ *(uint *)(CAST_S_table4 + iVar16);
    uVar11 = *(uint *)(CAST_S_table4 + iVar5);
    uVar6 = (local_114 << 8) >> 0x18;
    iVar4 = (local_114 >> 0x18) * 4;
    iVar22 = ((local_114 << 0x10) >> 0x18) * 4;
    iVar5 = uVar6 * 4;
    uVar18 = *(uint *)(CAST_S_table4 + iVar4);
    uVar19 = *(uint *)(CAST_S_table4 + iVar22);
    uVar9 = *(uint *)(&CAST_S_table5 + (local_114 & 0xff) * 4);
    uVar17 = *(uint *)(&CAST_S_table5 + uVar6 * 4);
    uVar6 = *(uint *)(CAST_S_table7 + iVar5);
    local_11c[0xd] =
         *(uint *)(CAST_S_table4 + iVar16) ^
         *(uint *)(&CAST_S_table5 + (local_10c & 0xff) * 4) ^
         *(uint *)(CAST_S_table7 + (local_10c >> 0x18) * 4) ^
         *(uint *)(CAST_S_table6 + ((local_10c << 8) >> 0x18) * 4) ^ local_108;
    local_11c[0xf] = uVar14 ^ uVar23 ^ uVar9 ^ uVar19 ^ uVar6;
    local_11c[0xe] = uVar21 ^ uVar8 ^ uVar12 ^ uVar18 ^ uVar17;
    local_11c[0xc] = uVar10 ^ uVar7 ^ uVar15 ^ uVar11 ^ uVar13;
    if (local_11c != &local_a8) break;
    local_11c = &local_68;
  }
  key->data[1] = local_68 + 0x10 & 0x1f;
  key->data[3] = local_64 + 0x10U & 0x1f;
  key->data[5] = local_60 + 0x10U & 0x1f;
  key->data[7] = local_5c + 0x10U & 0x1f;
  key->data[9] = local_58 + 0x10U & 0x1f;
  key->data[0xb] = local_54 + 0x10U & 0x1f;
  key->data[0xd] = local_50 + 0x10U & 0x1f;
  key->data[0xf] = local_4c + 0x10U & 0x1f;
  key->data[0] = local_a8;
  key->data[2] = local_a4;
  key->data[4] = local_a0;
  key->data[6] = local_9c;
  key->data[8] = local_98;
  key->data[10] = local_94;
  key->data[0xc] = local_90;
  key->data[0xe] = local_8c;
  key->data[0x10] = local_88;
  key->data[0x11] = local_48 + 0x10U & 0x1f;
  key->data[0x13] = local_44 + 0x10U & 0x1f;
  key->data[0x15] = local_40 + 0x10U & 0x1f;
  key->data[0x17] = local_3c + 0x10U & 0x1f;
  key->data[0x1d] = local_30 + 0x10U & 0x1f;
  key->data[0x1f] = local_2c + 0x10U & 0x1f;
  key->data[0x12] = local_84;
  key->data[0x19] = local_38 + 0x10U & 0x1f;
  key->data[0x1b] = local_34 + 0x10U & 0x1f;
  key->data[0x14] = local_80;
  key->data[0x16] = local_7c;
  key->data[0x18] = local_78;
  key->data[0x1a] = local_74;
  key->data[0x1c] = local_70;
  key->data[0x1e] = local_6c;
  return;
}

