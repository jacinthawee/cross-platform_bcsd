
void CAST_set_key(CAST_KEY *key,int len,uchar *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int in_GS_OFFSET;
  uint *local_13c;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_e0 [4];
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
  uint local_64;
  uint local_60;
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
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar15 = local_e0;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  iVar7 = 0x10;
  if (len < 0x11) {
    iVar7 = len;
  }
  if (((((0 < iVar7) && (local_e0[0] = (uint)*data, iVar7 != 1)) &&
       (local_e0[1] = (uint)data[1], iVar7 != 2)) &&
      (((local_e0[2] = (uint)data[2], iVar7 != 3 && (local_e0[3] = (uint)data[3], iVar7 != 4)) &&
       ((local_d0 = (uint)data[4], iVar7 != 5 &&
        ((local_cc = (uint)data[5], iVar7 != 6 && (local_c8 = (uint)data[6], iVar7 != 7)))))))) &&
     ((local_c4 = (uint)data[7], iVar7 != 8 &&
      (((((local_c0 = (uint)data[8], iVar7 != 9 && (local_bc = (uint)data[9], iVar7 != 10)) &&
         (local_b8 = (uint)data[10], iVar7 != 0xb)) &&
        ((local_b4 = (uint)data[0xb], iVar7 != 0xc && (local_b0 = (uint)data[0xc], iVar7 != 0xd))))
       && ((local_ac = (uint)data[0xd], iVar7 != 0xe && (local_a8 = (uint)data[0xe], iVar7 == 0x10))
          )))))) {
    local_a4 = (uint)data[0xf];
  }
  key->short_key = (uint)(iVar7 < 0xb);
  local_114 = local_b8;
  local_11c = local_e0[0] << 0x18 | local_e0[1] << 0x10 | local_e0[3] | local_e0[2] << 8;
  local_130 = local_bc;
  local_118 = local_d0 << 0x18 | local_cc << 0x10 | local_c4 | local_c8 << 8;
  uVar1 = local_bc << 0x10 | local_c0 << 0x18 | local_b4 | local_b8 << 8;
  local_12c = local_b0;
  local_134 = local_b0 << 0x18 | local_ac << 0x10 | local_a4 | local_a8 << 8;
  uVar9 = *(uint *)(CAST_S_table5 + local_a4 * 4);
  uVar10 = *(uint *)(CAST_S_table6 + local_c0 * 4);
  local_120 = *(uint *)(CAST_S_table5 + local_b4 * 4);
  local_13c = &local_a0;
  local_128 = local_a8;
  uVar12 = local_ac;
  while( true ) {
    uVar10 = uVar9 ^ *(uint *)(CAST_S_table4 + uVar12 * 4) ^
                     *(uint *)(CAST_S_table6 + local_12c * 4) ^
                     *(uint *)(CAST_S_table7 + local_128 * 4) ^ local_11c ^ uVar10;
    uVar14 = uVar10 & 0xff;
    uVar16 = uVar10 >> 8 & 0xff;
    uVar13 = uVar10 >> 0x18;
    uVar2 = uVar10 >> 0x10 & 0xff;
    uVar9 = *(uint *)(CAST_S_table6 + uVar2 * 4);
    uVar1 = *(uint *)(CAST_S_table4 + uVar13 * 4) ^ *(uint *)(CAST_S_table7 + uVar14 * 4) ^
            *(uint *)(CAST_S_table7 + local_114 * 4) ^ *(uint *)(CAST_S_table5 + uVar16 * 4) ^ uVar9
            ^ uVar1;
    uVar17 = uVar1 & 0xff;
    uVar3 = uVar1 >> 8 & 0xff;
    uVar11 = uVar1 >> 0x10 & 0xff;
    uVar12 = *(uint *)(CAST_S_table6 + uVar11 * 4);
    uVar4 = *(uint *)(CAST_S_table5 + uVar3 * 4);
    uVar5 = *(uint *)(CAST_S_table7 + (uVar1 >> 0x18) * 4);
    local_134 = uVar5 ^ *(uint *)(CAST_S_table4 + uVar17 * 4) ^
                *(uint *)(CAST_S_table4 + local_130 * 4) ^ uVar4 ^ uVar12 ^ local_134;
    uVar8 = local_134 >> 0x10 & 0xff;
    uVar6 = *(uint *)(CAST_S_table4 + (local_134 >> 8 & 0xff) * 4);
    uVar3 = *(uint *)(CAST_S_table7 + uVar3 * 4);
    local_120 = *(uint *)(CAST_S_table6 + (local_134 & 0xff) * 4) ^
                *(uint *)(CAST_S_table7 + (local_134 >> 0x18) * 4) ^ uVar6 ^
                *(uint *)(CAST_S_table5 + uVar8 * 4) ^ local_118 ^ local_120;
    *local_13c = *(uint *)(CAST_S_table6 + uVar17 * 4) ^ *(uint *)(CAST_S_table4 + uVar16 * 4) ^
                 uVar3 ^ *(uint *)(CAST_S_table4 + (local_134 >> 0x18) * 4) ^
                 *(uint *)(CAST_S_table5 + uVar8 * 4);
    local_13c[1] = uVar4 ^ uVar12 ^ uVar5 ^ *(uint *)(CAST_S_table5 + (local_134 & 0xff) * 4) ^
                   uVar6;
    uVar12 = *(uint *)(CAST_S_table7 + uVar16 * 4);
    uVar4 = *(uint *)(CAST_S_table5 + uVar17 * 4);
    local_13c[2] = *(uint *)(CAST_S_table6 + uVar14 * 4) ^ uVar12 ^
                   *(uint *)(CAST_S_table6 + uVar8 * 4) ^
                   *(uint *)(CAST_S_table4 + (local_120 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table5 + (local_120 >> 0x10 & 0xff) * 4);
    local_13c[3] = uVar9 ^ *(uint *)(CAST_S_table7 + uVar13 * 4) ^
                   *(uint *)(CAST_S_table5 + (local_120 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table7 + (local_120 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table4 + (local_120 >> 8 & 0xff) * 4);
    local_134 = local_134 ^
                uVar4 ^ *(uint *)(CAST_S_table6 + (uVar1 >> 0x18) * 4) ^
                *(uint *)(CAST_S_table6 + uVar13 * 4) ^ uVar3 ^
                *(uint *)(CAST_S_table4 + uVar11 * 4);
    uVar16 = local_134 & 0xff;
    uVar8 = local_134 >> 0x10 & 0xff;
    uVar11 = *(uint *)(CAST_S_table6 + uVar8 * 4) ^
             uVar10 ^ uVar12 ^ *(uint *)(CAST_S_table4 + (local_134 >> 0x18) * 4) ^
             *(uint *)(CAST_S_table7 + uVar16 * 4) ^
             *(uint *)(CAST_S_table5 + (local_134 >> 8 & 0xff) * 4);
    uVar17 = uVar11 >> 0x10 & 0xff;
    uVar9 = *(uint *)(CAST_S_table4 + (uVar11 & 0xff) * 4);
    uVar10 = *(uint *)(CAST_S_table5 + (uVar11 >> 8 & 0xff) * 4);
    uVar2 = uVar9 ^ uVar1 ^ *(uint *)(CAST_S_table4 + uVar2 * 4) ^
            *(uint *)(CAST_S_table7 + (uVar11 >> 0x18) * 4) ^ uVar10 ^
            *(uint *)(CAST_S_table6 + uVar17 * 4);
    uVar4 = uVar2 & 0xff;
    uVar5 = uVar2 >> 8 & 0xff;
    uVar18 = uVar2 >> 0x10 & 0xff;
    uVar3 = uVar2 >> 0x18;
    uVar6 = local_120 ^ *(uint *)(CAST_S_table5 + uVar14 * 4) ^ *(uint *)(CAST_S_table6 + uVar4 * 4)
            ^ *(uint *)(CAST_S_table7 + uVar3 * 4) ^ *(uint *)(CAST_S_table4 + uVar5 * 4) ^
            *(uint *)(CAST_S_table5 + uVar18 * 4);
    uVar13 = uVar6 >> 8 & 0xff;
    uVar14 = uVar6 >> 0x10 & 0xff;
    uVar12 = *(uint *)(CAST_S_table6 + (uVar6 >> 0x18) * 4);
    uVar1 = *(uint *)(CAST_S_table6 + uVar3 * 4);
    local_13c[4] = *(uint *)(CAST_S_table4 + uVar3 * 4) ^
                   *(uint *)(CAST_S_table5 + (local_134 >> 8 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table4 + uVar16 * 4) ^ uVar12 ^
                   *(uint *)(CAST_S_table7 + uVar14 * 4);
    local_13c[5] = *(uint *)(CAST_S_table4 + uVar8 * 4) ^
                   *(uint *)(CAST_S_table5 + (local_134 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table7 + (uVar6 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table6 + uVar13 * 4) ^ *(uint *)(CAST_S_table5 + uVar14 * 4);
    local_13c[6] = uVar10 ^ uVar9 ^ *(uint *)(CAST_S_table6 + uVar16 * 4) ^ uVar1 ^
                   *(uint *)(CAST_S_table7 + uVar18 * 4);
    local_13c[7] = *(uint *)(CAST_S_table5 + (uVar11 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table7 + (uVar11 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table4 + uVar17 * 4) ^ *(uint *)(CAST_S_table7 + uVar4 * 4) ^
                   *(uint *)(CAST_S_table6 + uVar5 * 4);
    uVar17 = uVar1 ^ local_134 ^ uVar12 ^ *(uint *)(CAST_S_table5 + (uVar6 & 0xff) * 4) ^
             *(uint *)(CAST_S_table4 + uVar14 * 4) ^ *(uint *)(CAST_S_table7 + uVar13 * 4);
    uVar13 = uVar17 & 0xff;
    uVar10 = uVar17 >> 0x10 & 0xff;
    uVar3 = uVar17 >> 0x18;
    uVar14 = uVar17 >> 8 & 0xff;
    uVar2 = uVar2 ^ *(uint *)(CAST_S_table7 + uVar5 * 4) ^ *(uint *)(CAST_S_table4 + uVar3 * 4) ^
            *(uint *)(CAST_S_table7 + uVar13 * 4) ^ *(uint *)(CAST_S_table5 + uVar14 * 4) ^
            *(uint *)(CAST_S_table6 + uVar10 * 4);
    uVar5 = uVar2 >> 8 & 0xff;
    uVar12 = uVar2 >> 0x10 & 0xff;
    uVar9 = *(uint *)(CAST_S_table4 + (uVar2 & 0xff) * 4);
    uVar8 = uVar2 >> 0x18;
    local_11c = uVar6 ^ *(uint *)(CAST_S_table4 + uVar18 * 4) ^ uVar9 ^
                *(uint *)(CAST_S_table7 + uVar8 * 4) ^ *(uint *)(CAST_S_table5 + uVar5 * 4) ^
                *(uint *)(CAST_S_table6 + uVar12 * 4);
    uVar6 = local_11c >> 0x10 & 0xff;
    uVar11 = *(uint *)(CAST_S_table5 + uVar6 * 4) ^
             uVar11 ^ *(uint *)(CAST_S_table5 + uVar4 * 4) ^
             *(uint *)(CAST_S_table6 + (local_11c & 0xff) * 4) ^
             *(uint *)(CAST_S_table7 + (local_11c >> 0x18) * 4) ^
             *(uint *)(CAST_S_table4 + (local_11c >> 8 & 0xff) * 4);
    local_13c[8] = *(uint *)(CAST_S_table4 + uVar6 * 4) ^
                   *(uint *)(CAST_S_table5 + uVar14 * 4) ^ *(uint *)(CAST_S_table4 + uVar13 * 4) ^
                   *(uint *)(CAST_S_table6 + (uVar11 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table7 + (uVar11 >> 0x10 & 0xff) * 4);
    uVar10 = *(uint *)(CAST_S_table4 + uVar10 * 4);
    local_13c[9] = uVar10 ^ *(uint *)(CAST_S_table5 + uVar3 * 4) ^
                   *(uint *)(CAST_S_table7 + (uVar11 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table5 + (uVar11 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table6 + (uVar11 >> 8 & 0xff) * 4);
    uVar12 = *(uint *)(CAST_S_table4 + uVar12 * 4);
    uVar1 = *(uint *)(CAST_S_table7 + uVar5 * 4);
    local_13c[10] =
         uVar9 ^ *(uint *)(CAST_S_table6 + uVar14 * 4) ^ *(uint *)(CAST_S_table5 + uVar5 * 4) ^
         *(uint *)(CAST_S_table6 + (local_11c >> 0x18) * 4) ^ *(uint *)(CAST_S_table7 + uVar6 * 4);
    local_13c[0xb] =
         uVar12 ^ uVar1 ^ *(uint *)(CAST_S_table5 + uVar8 * 4) ^
         *(uint *)(CAST_S_table7 + (local_11c & 0xff) * 4) ^
         *(uint *)(CAST_S_table6 + (local_11c >> 8 & 0xff) * 4);
    local_11c = *(uint *)(CAST_S_table5 + (uVar2 & 0xff) * 4) ^ *(uint *)(CAST_S_table6 + uVar8 * 4)
                ^ *(uint *)(CAST_S_table6 + uVar3 * 4) ^ uVar12 ^ uVar1 ^ local_11c;
    uVar3 = local_11c & 0xff;
    uVar16 = local_11c >> 8 & 0xff;
    uVar4 = *(uint *)(CAST_S_table6 + (local_11c >> 0x10 & 0xff) * 4);
    local_118 = uVar17 ^ *(uint *)(CAST_S_table7 + uVar14 * 4) ^
                *(uint *)(CAST_S_table4 + (local_11c >> 0x18) * 4) ^
                *(uint *)(CAST_S_table7 + uVar3 * 4) ^ *(uint *)(CAST_S_table5 + uVar16 * 4) ^ uVar4
    ;
    uVar14 = local_118 >> 8 & 0xff;
    uVar8 = local_118 & 0xff;
    uVar9 = *(uint *)(CAST_S_table6 + (local_118 >> 0x10 & 0xff) * 4);
    uVar5 = *(uint *)(CAST_S_table7 + (local_118 >> 0x18) * 4);
    uVar1 = uVar2 ^ uVar10 ^ *(uint *)(CAST_S_table4 + uVar8 * 4) ^ uVar5 ^
            *(uint *)(CAST_S_table5 + uVar14 * 4) ^ uVar9;
    local_114 = uVar1 >> 8 & 0xff;
    uVar10 = uVar1 >> 0x18;
    local_130 = uVar1 >> 0x10 & 0xff;
    uVar6 = *(uint *)(CAST_S_table4 + local_114 * 4);
    local_134 = *(uint *)(CAST_S_table5 + local_130 * 4) ^
                uVar11 ^ *(uint *)(CAST_S_table5 + uVar13 * 4) ^
                *(uint *)(CAST_S_table6 + (uVar1 & 0xff) * 4) ^
                *(uint *)(CAST_S_table7 + uVar10 * 4) ^ uVar6;
    local_128 = local_134 >> 8 & 0xff;
    uVar12 = local_134 >> 0x10 & 0xff;
    local_12c = local_134 >> 0x18;
    local_120 = *(uint *)(CAST_S_table5 + (uVar1 & 0xff) * 4);
    local_13c[0xc] =
         *(uint *)(CAST_S_table6 + uVar8 * 4) ^ *(uint *)(CAST_S_table4 + uVar3 * 4) ^
         *(uint *)(CAST_S_table7 + uVar14 * 4) ^ *(uint *)(CAST_S_table4 + uVar10 * 4) ^
         *(uint *)(CAST_S_table5 + local_130 * 4);
    uVar10 = *(uint *)(CAST_S_table6 + uVar10 * 4);
    uVar3 = *(uint *)(CAST_S_table6 + uVar3 * 4);
    uVar2 = *(uint *)(CAST_S_table7 + uVar16 * 4);
    local_13c[0xd] = uVar5 ^ *(uint *)(CAST_S_table5 + uVar8 * 4) ^ uVar9 ^ local_120 ^ uVar6;
    uVar5 = *(uint *)(CAST_S_table7 + (local_11c >> 0x18) * 4);
    local_13c[0xe] =
         uVar3 ^ uVar2 ^ uVar10 ^ *(uint *)(CAST_S_table4 + local_12c * 4) ^
         *(uint *)(CAST_S_table5 + uVar12 * 4);
    uVar9 = *(uint *)(CAST_S_table5 + (local_134 & 0xff) * 4);
    local_13c[0xf] =
         uVar4 ^ uVar5 ^ uVar9 ^ *(uint *)(CAST_S_table4 + local_128 * 4) ^
         *(uint *)(CAST_S_table7 + uVar12 * 4);
    if (local_13c != &local_a0) break;
    local_13c = &local_60;
  }
  key->data[0] = local_a0;
  key->data[1] = local_60 + 0x10 & 0x1f;
  key->data[2] = local_9c;
  key->data[3] = local_5c + 0x10U & 0x1f;
  key->data[4] = local_98;
  key->data[5] = local_58 + 0x10U & 0x1f;
  key->data[6] = local_94;
  key->data[7] = local_54 + 0x10U & 0x1f;
  key->data[8] = local_90;
  key->data[9] = local_50 + 0x10U & 0x1f;
  key->data[10] = local_8c;
  key->data[0xb] = local_4c + 0x10U & 0x1f;
  key->data[0xc] = local_88;
  key->data[0xd] = local_48 + 0x10U & 0x1f;
  key->data[0xe] = local_84;
  key->data[0xf] = local_44 + 0x10U & 0x1f;
  key->data[0x10] = local_80;
  key->data[0x11] = local_40 + 0x10U & 0x1f;
  key->data[0x12] = local_7c;
  key->data[0x13] = local_3c + 0x10U & 0x1f;
  key->data[0x14] = local_78;
  key->data[0x15] = local_38 + 0x10U & 0x1f;
  key->data[0x16] = local_74;
  key->data[0x17] = local_34 + 0x10U & 0x1f;
  key->data[0x18] = local_70;
  key->data[0x19] = local_30 + 0x10U & 0x1f;
  key->data[0x1a] = local_6c;
  key->data[0x1b] = local_2c + 0x10U & 0x1f;
  key->data[0x1c] = local_68;
  key->data[0x1d] = local_28 + 0x10U & 0x1f;
  key->data[0x1e] = local_64;
  key->data[0x1f] = local_24 + 0x10U & 0x1f;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

