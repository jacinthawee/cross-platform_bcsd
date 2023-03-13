
void whirlpool_block(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  int iVar33;
  int in_GS_OFFSET;
  uint *local_138;
  uint local_118;
  uint *local_f4;
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
  uint local_28;
  uint local_24;
  
  local_138 = (uint *)param_1[1];
  local_f4 = param_2;
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  local_ec = param_1[2];
  local_118 = *param_1;
  local_e8 = param_1[3];
  local_e4 = param_1[4];
  local_e0 = param_1[5];
  local_dc = param_1[6];
  local_d8 = param_1[7];
  local_d4 = param_1[8];
  local_d0 = param_1[9];
  local_cc = param_1[10];
  local_c8 = param_1[0xb];
  local_c4 = param_1[0xc];
  local_c0 = param_1[0xd];
  local_bc = param_1[0xe];
  local_b8 = param_1[0xf];
  do {
    local_60 = local_118;
    local_58 = local_ec;
    local_5c = (uint)local_138;
    uVar30 = (uint)local_138 ^ local_f4[1];
    local_54 = local_e8;
    local_4c = local_e0;
    local_50 = local_e4;
    local_44 = local_d8;
    local_48 = local_dc;
    local_3c = local_d0;
    local_40 = local_d4;
    local_7c = local_f4[9] ^ local_d0;
    local_34 = local_c8;
    local_38 = local_cc;
    local_74 = local_f4[0xb] ^ local_c8;
    local_2c = local_c0;
    local_30 = local_c4;
    local_70 = local_c4 ^ local_f4[0xc];
    local_6c = local_f4[0xd] ^ local_c0;
    local_24 = local_b8;
    local_28 = local_bc;
    local_68 = local_bc ^ local_f4[0xe];
    local_138 = (uint *)(Cx + 0x1000);
    local_64 = local_f4[0xf] ^ local_b8;
    local_a0 = local_118 ^ *local_f4;
    local_9c = uVar30;
    local_98 = local_ec ^ local_f4[2];
    local_94 = local_f4[3] ^ local_e8;
    local_90 = local_e4 ^ local_f4[4];
    local_8c = local_f4[5] ^ local_e0;
    local_88 = local_dc ^ local_f4[6];
    local_84 = local_f4[7] ^ local_d8;
    local_80 = local_d4 ^ local_f4[8];
    local_78 = local_cc ^ local_f4[10];
    do {
      iVar6 = (local_28 >> 8 & 0xff) * 0x10;
      iVar12 = (local_30 >> 0x10 & 0xff) * 0x10;
      iVar13 = (local_60 & 0xff) * 0x10;
      iVar7 = (local_60 >> 8 & 0xff) * 0x10;
      iVar14 = (local_38 >> 0x18) * 0x10;
      iVar15 = (local_3c & 0xff) * 0x10;
      iVar16 = (local_44 >> 8 & 0xff) * 0x10;
      iVar17 = (local_4c >> 0x10 & 0xff) * 0x10;
      iVar18 = (local_54 >> 0x18) * 0x10;
      uVar2 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar12 + 6) ^ *(uint *)(Cx + iVar13) ^
              *(uint *)(Cx + iVar14 + 5) ^ *(uint *)(Cx + iVar15 + 4) ^ *(uint *)(Cx + iVar16 + 3) ^
              *(uint *)(Cx + iVar17 + 2) ^ *(uint *)(Cx + iVar18 + 1) ^ *local_138;
      uVar31 = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar12 + 10) ^
               *(uint *)(Cx + iVar13 + 4) ^ *(uint *)(Cx + iVar14 + 9) ^ *(uint *)(Cx + iVar15 + 8)
               ^ *(uint *)(Cx + iVar16 + 7) ^ *(uint *)(Cx + iVar17 + 6) ^
               *(uint *)(Cx + iVar18 + 5) ^ local_138[1];
      iVar12 = (local_28 >> 0x10 & 0xff) * 0x10;
      iVar13 = (local_58 & 0xff) * 0x10;
      iVar14 = (local_30 >> 0x18) * 0x10;
      iVar6 = (local_60 >> 0x10 & 0xff) * 0x10;
      iVar15 = (local_34 & 0xff) * 0x10;
      iVar16 = (local_3c >> 8 & 0xff) * 0x10;
      iVar17 = (local_44 >> 0x10 & 0xff) * 0x10;
      iVar18 = (local_4c >> 0x18) * 0x10;
      uVar27 = *(uint *)(Cx + iVar7 + 7) ^ *(uint *)(Cx + iVar12 + 6) ^ *(uint *)(Cx + iVar13) ^
               *(uint *)(Cx + iVar14 + 5) ^ *(uint *)(Cx + iVar15 + 4) ^ *(uint *)(Cx + iVar16 + 3)
               ^ *(uint *)(Cx + iVar17 + 2) ^ *(uint *)(Cx + iVar18 + 1);
      uVar21 = *(uint *)(Cx + iVar7 + 0xb) ^ *(uint *)(Cx + iVar12 + 10) ^
               *(uint *)(Cx + iVar13 + 4) ^ *(uint *)(Cx + iVar14 + 9) ^ *(uint *)(Cx + iVar15 + 8)
               ^ *(uint *)(Cx + iVar16 + 7) ^ *(uint *)(Cx + iVar17 + 6) ^
               *(uint *)(Cx + iVar18 + 5);
      iVar17 = (local_58 >> 8 & 0xff) * 0x10;
      iVar7 = (local_50 & 0xff) * 0x10;
      iVar12 = (local_28 >> 0x18) * 0x10;
      iVar13 = (local_2c & 0xff) * 0x10;
      iVar14 = (local_34 >> 8 & 0xff) * 0x10;
      iVar15 = (local_3c >> 0x10 & 0xff) * 0x10;
      iVar16 = (local_44 >> 0x18) * 0x10;
      uVar25 = *(uint *)(Cx + iVar17 + 7) ^ *(uint *)(Cx + iVar6 + 6) ^ *(uint *)(Cx + iVar7) ^
               *(uint *)(Cx + iVar12 + 5) ^ *(uint *)(Cx + iVar13 + 4) ^ *(uint *)(Cx + iVar14 + 3)
               ^ *(uint *)(Cx + iVar15 + 2) ^ *(uint *)(Cx + iVar16 + 1);
      uVar19 = *(uint *)(Cx + iVar17 + 0xb) ^ *(uint *)(Cx + iVar6 + 10) ^ *(uint *)(Cx + iVar7 + 4)
               ^ *(uint *)(Cx + iVar12 + 9) ^ *(uint *)(Cx + iVar13 + 8) ^
               *(uint *)(Cx + iVar14 + 7) ^ *(uint *)(Cx + iVar15 + 6) ^ *(uint *)(Cx + iVar16 + 5);
      iVar7 = (local_58 >> 0x10 & 0xff) * 0x10;
      iVar6 = (local_50 >> 8 & 0xff) * 0x10;
      iVar12 = (local_48 & 0xff) * 0x10;
      iVar13 = (local_60 >> 0x18) * 0x10;
      iVar14 = (local_24 & 0xff) * 0x10;
      iVar15 = (local_2c >> 8 & 0xff) * 0x10;
      iVar16 = (local_34 >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_3c >> 0x18) * 0x10;
      uVar20 = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^ *(uint *)(Cx + iVar12 + 4)
               ^ *(uint *)(Cx + iVar13 + 9) ^ *(uint *)(Cx + iVar14 + 8) ^
               *(uint *)(Cx + iVar15 + 7) ^ *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5);
      uVar8 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^ *(uint *)(Cx + iVar12) ^
              *(uint *)(Cx + iVar13 + 5) ^ *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3) ^
              *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1);
      iVar7 = (local_50 >> 0x10 & 0xff) * 0x10;
      iVar6 = (local_48 >> 8 & 0xff) * 0x10;
      iVar12 = (local_40 & 0xff) * 0x10;
      iVar13 = (local_58 >> 0x18) * 0x10;
      iVar14 = (local_5c & 0xff) * 0x10;
      iVar15 = (local_24 >> 8 & 0xff) * 0x10;
      iVar16 = (local_2c >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_34 >> 0x18) * 0x10;
      uVar9 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^ *(uint *)(Cx + iVar12) ^
              *(uint *)(Cx + iVar13 + 5) ^ *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3) ^
              *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1);
      local_3c = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^
                 *(uint *)(Cx + iVar12 + 4) ^ *(uint *)(Cx + iVar13 + 9) ^
                 *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7) ^
                 *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5);
      iVar6 = (local_40 >> 8 & 0xff) * 0x10;
      iVar7 = (local_48 >> 0x10 & 0xff) * 0x10;
      iVar12 = (local_38 & 0xff) * 0x10;
      iVar13 = (local_50 >> 0x18) * 0x10;
      iVar14 = (local_54 & 0xff) * 0x10;
      iVar15 = (local_5c >> 8 & 0xff) * 0x10;
      iVar16 = (local_24 >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_2c >> 0x18) * 0x10;
      uVar10 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^ *(uint *)(Cx + iVar12) ^
               *(uint *)(Cx + iVar13 + 5) ^ *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3)
               ^ *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1);
      local_34 = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^
                 *(uint *)(Cx + iVar12 + 4) ^ *(uint *)(Cx + iVar13 + 9) ^
                 *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7) ^
                 *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5);
      iVar6 = (local_40 >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_38 >> 8 & 0xff) * 0x10;
      iVar7 = (local_30 & 0xff) * 0x10;
      iVar12 = (local_48 >> 0x18) * 0x10;
      iVar13 = (local_4c & 0xff) * 0x10;
      iVar14 = (local_54 >> 8 & 0xff) * 0x10;
      iVar15 = (local_5c >> 0x10 & 0xff) * 0x10;
      iVar16 = (local_24 >> 0x18) * 0x10;
      uVar26 = *(uint *)(Cx + iVar17 + 7) ^ *(uint *)(Cx + iVar6 + 6) ^ *(uint *)(Cx + iVar7) ^
               *(uint *)(Cx + iVar12 + 5) ^ *(uint *)(Cx + iVar13 + 4) ^ *(uint *)(Cx + iVar14 + 3)
               ^ *(uint *)(Cx + iVar15 + 2) ^ *(uint *)(Cx + iVar16 + 1);
      local_2c = *(uint *)(Cx + iVar16 + 5) ^
                 *(uint *)(Cx + iVar17 + 0xb) ^ *(uint *)(Cx + iVar6 + 10) ^
                 *(uint *)(Cx + iVar7 + 4) ^ *(uint *)(Cx + iVar12 + 9) ^ *(uint *)(Cx + iVar13 + 8)
                 ^ *(uint *)(Cx + iVar14 + 7) ^ *(uint *)(Cx + iVar15 + 6);
      iVar6 = (local_30 >> 8 & 0xff) * 0x10;
      iVar7 = (local_38 >> 0x10 & 0xff) * 0x10;
      iVar12 = (local_28 & 0xff) * 0x10;
      iVar13 = (local_40 >> 0x18) * 0x10;
      iVar14 = (local_44 & 0xff) * 0x10;
      iVar15 = (local_4c >> 8 & 0xff) * 0x10;
      iVar16 = (local_54 >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_5c >> 0x18) * 0x10;
      local_24 = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^
                 *(uint *)(Cx + iVar12 + 4) ^ *(uint *)(Cx + iVar13 + 9) ^
                 *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7) ^
                 *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5);
      local_28 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^ *(uint *)(Cx + iVar12) ^
                 *(uint *)(Cx + iVar13 + 5) ^ *(uint *)(Cx + iVar14 + 4) ^
                 *(uint *)(Cx + iVar15 + 3) ^ *(uint *)(Cx + iVar16 + 2) ^
                 *(uint *)(Cx + iVar17 + 1);
      iVar7 = (local_70 >> 0x10 & 0xff) * 0x10;
      iVar6 = (local_68 >> 8 & 0xff) * 0x10;
      iVar12 = (local_a0 & 0xff) * 0x10;
      iVar13 = (local_78 >> 0x18) * 0x10;
      iVar14 = (local_7c & 0xff) * 0x10;
      iVar15 = (local_84 >> 8 & 0xff) * 0x10;
      iVar16 = (local_8c >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_94 >> 0x18) * 0x10;
      uVar11 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^ *(uint *)(Cx + iVar12) ^
               *(uint *)(Cx + iVar13 + 5) ^ *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3)
               ^ *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1) ^ uVar2;
      uVar3 = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^ *(uint *)(Cx + iVar12 + 4)
              ^ *(uint *)(Cx + iVar13 + 9) ^ *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7)
              ^ *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5) ^ uVar31;
      iVar7 = (local_68 >> 0x10 & 0xff) * 0x10;
      iVar6 = (local_a0 >> 8 & 0xff) * 0x10;
      iVar12 = (local_98 & 0xff) * 0x10;
      iVar13 = (local_70 >> 0x18) * 0x10;
      iVar14 = (local_74 & 0xff) * 0x10;
      iVar15 = (local_7c >> 8 & 0xff) * 0x10;
      iVar16 = (local_84 >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_8c >> 0x18) * 0x10;
      uVar32 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^ *(uint *)(Cx + iVar12) ^
               *(uint *)(Cx + iVar13 + 5) ^ *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3)
               ^ *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1) ^ uVar27;
      uVar4 = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^ *(uint *)(Cx + iVar12 + 4)
              ^ *(uint *)(Cx + iVar13 + 9) ^ *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7)
              ^ *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5) ^ uVar21;
      iVar7 = (local_a0 >> 0x10 & 0xff) * 0x10;
      iVar6 = (local_98 >> 8 & 0xff) * 0x10;
      iVar12 = (local_90 & 0xff) * 0x10;
      iVar13 = (local_68 >> 0x18) * 0x10;
      iVar14 = (local_6c & 0xff) * 0x10;
      iVar15 = (local_74 >> 8 & 0xff) * 0x10;
      iVar16 = (local_7c >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_84 >> 0x18) * 0x10;
      uVar5 = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^ *(uint *)(Cx + iVar12 + 4)
              ^ *(uint *)(Cx + iVar13 + 9) ^ *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7)
              ^ *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5) ^ uVar19;
      uVar22 = uVar25 ^ *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^
                        *(uint *)(Cx + iVar12) ^ *(uint *)(Cx + iVar13 + 5) ^
                        *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3) ^
                        *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1);
      iVar7 = (local_98 >> 0x10 & 0xff) * 0x10;
      iVar6 = (local_90 >> 8 & 0xff) * 0x10;
      iVar12 = (local_88 & 0xff) * 0x10;
      iVar13 = (local_a0 >> 0x18) * 0x10;
      iVar14 = (local_64 & 0xff) * 0x10;
      iVar15 = (local_6c >> 8 & 0xff) * 0x10;
      iVar16 = (local_74 >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_7c >> 0x18) * 0x10;
      uVar28 = uVar8 ^ *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^
                       *(uint *)(Cx + iVar12) ^ *(uint *)(Cx + iVar13 + 5) ^
                       *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3) ^
                       *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1);
      uVar23 = uVar20 ^ *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^
                        *(uint *)(Cx + iVar12 + 4) ^ *(uint *)(Cx + iVar13 + 9) ^
                        *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7) ^
                        *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5);
      iVar7 = (local_90 >> 0x10 & 0xff) * 0x10;
      iVar6 = (local_88 >> 8 & 0xff) * 0x10;
      iVar12 = (local_80 & 0xff) * 0x10;
      iVar13 = (local_98 >> 0x18) * 0x10;
      iVar14 = (local_9c & 0xff) * 0x10;
      iVar15 = (local_64 >> 8 & 0xff) * 0x10;
      iVar16 = (local_6c >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_74 >> 0x18) * 0x10;
      local_7c = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar7 + 10) ^
                 *(uint *)(Cx + iVar12 + 4) ^ *(uint *)(Cx + iVar13 + 9) ^
                 *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7) ^
                 *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5) ^ local_3c;
      uVar24 = uVar9 ^ *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar7 + 6) ^
                       *(uint *)(Cx + iVar12) ^ *(uint *)(Cx + iVar13 + 5) ^
                       *(uint *)(Cx + iVar14 + 4) ^ *(uint *)(Cx + iVar15 + 3) ^
                       *(uint *)(Cx + iVar16 + 2) ^ *(uint *)(Cx + iVar17 + 1);
      iVar17 = (local_80 >> 8 & 0xff) * 0x10;
      iVar6 = (local_88 >> 0x10 & 0xff) * 0x10;
      iVar7 = (local_78 & 0xff) * 0x10;
      iVar12 = (local_90 >> 0x18) * 0x10;
      iVar13 = (local_94 & 0xff) * 0x10;
      iVar14 = (local_9c >> 8 & 0xff) * 0x10;
      iVar15 = (local_64 >> 0x10 & 0xff) * 0x10;
      iVar16 = (local_6c >> 0x18) * 0x10;
      uVar29 = *(uint *)(Cx + iVar17 + 7) ^ *(uint *)(Cx + iVar6 + 6) ^ *(uint *)(Cx + iVar7) ^
               *(uint *)(Cx + iVar12 + 5) ^ *(uint *)(Cx + iVar13 + 4) ^ *(uint *)(Cx + iVar14 + 3)
               ^ *(uint *)(Cx + iVar15 + 2) ^ *(uint *)(Cx + iVar16 + 1) ^ uVar10;
      iVar18 = (local_80 >> 0x10 & 0xff) * 0x10;
      local_74 = *(uint *)(Cx + iVar17 + 0xb) ^ *(uint *)(Cx + iVar6 + 10) ^
                 *(uint *)(Cx + iVar7 + 4) ^ *(uint *)(Cx + iVar12 + 9) ^ *(uint *)(Cx + iVar13 + 8)
                 ^ *(uint *)(Cx + iVar14 + 7) ^ *(uint *)(Cx + iVar15 + 6) ^
                 *(uint *)(Cx + iVar16 + 5) ^ local_34;
      iVar6 = (local_78 >> 8 & 0xff) * 0x10;
      iVar12 = (local_70 & 0xff) * 0x10;
      iVar13 = (local_88 >> 0x18) * 0x10;
      iVar14 = (local_8c & 0xff) * 0x10;
      iVar15 = (local_94 >> 8 & 0xff) * 0x10;
      iVar16 = (local_9c >> 0x10 & 0xff) * 0x10;
      iVar17 = (local_64 >> 0x18) * 0x10;
      iVar7 = (local_70 >> 8 & 0xff) * 0x10;
      iVar33 = (local_78 >> 0x10 & 0xff) * 0x10;
      local_6c = *(uint *)(Cx + iVar6 + 0xb) ^ *(uint *)(Cx + iVar18 + 10) ^
                 *(uint *)(Cx + iVar12 + 4) ^ *(uint *)(Cx + iVar13 + 9) ^
                 *(uint *)(Cx + iVar14 + 8) ^ *(uint *)(Cx + iVar15 + 7) ^
                 *(uint *)(Cx + iVar16 + 6) ^ *(uint *)(Cx + iVar17 + 5) ^ local_2c;
      local_70 = *(uint *)(Cx + iVar6 + 7) ^ *(uint *)(Cx + iVar18 + 6) ^ *(uint *)(Cx + iVar12) ^
                 *(uint *)(Cx + iVar13 + 5) ^ *(uint *)(Cx + iVar14 + 4) ^
                 *(uint *)(Cx + iVar15 + 3) ^ *(uint *)(Cx + iVar16 + 2) ^
                 *(uint *)(Cx + iVar17 + 1) ^ uVar26;
      iVar6 = (local_68 & 0xff) * 0x10;
      iVar12 = (local_80 >> 0x18) * 0x10;
      iVar13 = (local_84 & 0xff) * 0x10;
      iVar14 = (local_8c >> 8 & 0xff) * 0x10;
      iVar15 = (local_94 >> 0x10 & 0xff) * 0x10;
      iVar16 = (local_9c >> 0x18) * 0x10;
      local_68 = *(uint *)(Cx + iVar7 + 7) ^ *(uint *)(Cx + iVar33 + 6) ^ *(uint *)(Cx + iVar6) ^
                 *(uint *)(Cx + iVar12 + 5) ^ *(uint *)(Cx + iVar13 + 4) ^
                 *(uint *)(Cx + iVar14 + 3) ^ *(uint *)(Cx + iVar15 + 2) ^
                 *(uint *)(Cx + iVar16 + 1) ^ local_28;
      local_64 = *(uint *)(Cx + iVar7 + 0xb) ^ *(uint *)(Cx + iVar33 + 10) ^
                 *(uint *)(Cx + iVar6 + 4) ^ *(uint *)(Cx + iVar12 + 9) ^ *(uint *)(Cx + iVar13 + 8)
                 ^ *(uint *)(Cx + iVar14 + 7) ^ *(uint *)(Cx + iVar15 + 6) ^
                 *(uint *)(Cx + iVar16 + 5) ^ local_24;
      local_138 = local_138 + 2;
      local_a0 = uVar11;
      local_9c = uVar3;
      local_98 = uVar32;
      local_94 = uVar4;
      local_90 = uVar22;
      local_8c = uVar5;
      local_88 = uVar28;
      local_84 = uVar23;
      local_80 = uVar24;
      local_78 = uVar29;
      local_60 = uVar2;
      local_5c = uVar31;
      local_58 = uVar27;
      local_54 = uVar21;
      local_50 = uVar25;
      local_4c = uVar19;
      local_48 = uVar8;
      local_44 = uVar20;
      local_40 = uVar9;
      local_38 = uVar10;
      local_30 = uVar26;
    } while (local_138 != (uint *)&DAT_08215830);
    local_118 = local_118 ^ *local_f4 ^ uVar11;
    local_138 = (uint *)(uVar30 ^ uVar3);
    *param_1 = local_118;
    param_1[1] = (uint)local_138;
    local_ec = local_ec ^ uVar32 ^ local_f4[2];
    local_e8 = local_e8 ^ uVar4 ^ local_f4[3];
    param_1[2] = local_ec;
    param_1[3] = local_e8;
    local_e4 = local_e4 ^ uVar22 ^ local_f4[4];
    local_e0 = local_e0 ^ uVar5 ^ local_f4[5];
    param_1[5] = local_e0;
    param_1[4] = local_e4;
    local_dc = local_dc ^ uVar28 ^ local_f4[6];
    local_d8 = local_d8 ^ uVar23 ^ local_f4[7];
    param_1[7] = local_d8;
    param_1[6] = local_dc;
    local_d4 = local_d4 ^ uVar24 ^ local_f4[8];
    local_d0 = local_d0 ^ local_7c ^ local_f4[9];
    param_1[9] = local_d0;
    param_1[8] = local_d4;
    local_cc = local_cc ^ uVar29 ^ local_f4[10];
    local_c8 = local_c8 ^ local_74 ^ local_f4[0xb];
    param_1[10] = local_cc;
    param_1[0xb] = local_c8;
    local_c4 = local_c4 ^ local_70 ^ local_f4[0xc];
    local_c0 = local_c0 ^ local_6c ^ local_f4[0xd];
    param_1[0xc] = local_c4;
    param_1[0xd] = local_c0;
    local_bc = local_bc ^ local_68 ^ local_f4[0xe];
    local_b8 = local_b8 ^ local_64 ^ local_f4[0xf];
    param_3 = param_3 + -1;
    param_1[0xe] = local_bc;
    param_1[0xf] = local_b8;
    local_f4 = local_f4 + 0x10;
  } while (param_3 != 0);
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

