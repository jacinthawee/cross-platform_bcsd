
void sha256_block_data_order(uint *param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
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
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int *piVar20;
  int *piVar21;
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
  
  puVar2 = param_2 + param_3 * 0x10;
  uVar5 = *param_1;
  uVar6 = param_1[1];
  uVar8 = param_1[2];
  uVar10 = param_1[3];
  uVar12 = param_1[4];
  uVar14 = param_1[5];
  uVar16 = param_1[6];
  uVar18 = param_1[7];
  piVar20 = &K256;
  do {
    uVar3 = *param_2;
    local_70 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
    iVar4 = local_70 +
            ((uVar12 >> 6 | uVar12 << 0x1a) ^ (uVar12 >> 0xb | uVar12 << 0x15) ^
            (uVar12 >> 0x19 | uVar12 << 7)) + uVar18 + ((uVar14 ^ uVar16) & uVar12 ^ uVar16) +
            *piVar20;
    uVar10 = uVar10 + iVar4;
    uVar19 = ((uVar5 >> 2 | uVar5 << 0x1e) ^ (uVar5 >> 0xd | uVar5 << 0x13) ^
             (uVar5 >> 0x16 | uVar5 << 10)) + iVar4 + ((uVar5 | uVar6) & uVar8 | uVar5 & uVar6);
    uVar18 = param_2[1];
    local_6c = uVar18 << 0x18 | (uVar18 >> 8 & 0xff) << 0x10 | (uVar18 >> 0x10 & 0xff) << 8 |
               uVar18 >> 0x18;
    iVar4 = local_6c +
            ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
            (uVar10 >> 0x19 | uVar10 * 0x80)) + uVar16 + ((uVar12 ^ uVar14) & uVar10 ^ uVar14) +
            piVar20[1];
    uVar8 = uVar8 + iVar4;
    uVar17 = ((uVar19 >> 2 | uVar19 * 0x40000000) ^ (uVar19 >> 0xd | uVar19 * 0x80000) ^
             (uVar19 >> 0x16 | uVar19 * 0x400)) + iVar4 +
             ((uVar19 | uVar5) & uVar6 | uVar19 & uVar5);
    uVar16 = param_2[2];
    local_68 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
               uVar16 >> 0x18;
    iVar4 = local_68 +
            ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
            (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar14 + ((uVar10 ^ uVar12) & uVar8 ^ uVar12) +
            piVar20[2];
    uVar6 = uVar6 + iVar4;
    uVar15 = ((uVar17 >> 2 | uVar17 * 0x40000000) ^ (uVar17 >> 0xd | uVar17 * 0x80000) ^
             (uVar17 >> 0x16 | uVar17 * 0x400)) + iVar4 +
             ((uVar17 | uVar19) & uVar5 | uVar17 & uVar19);
    uVar14 = param_2[3];
    local_64 = uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
               uVar14 >> 0x18;
    iVar4 = local_64 +
            ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
            (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar12 + ((uVar8 ^ uVar10) & uVar6 ^ uVar10) +
            piVar20[3];
    uVar5 = uVar5 + iVar4;
    uVar13 = ((uVar15 >> 2 | uVar15 * 0x40000000) ^ (uVar15 >> 0xd | uVar15 * 0x80000) ^
             (uVar15 >> 0x16 | uVar15 * 0x400)) + iVar4 +
             ((uVar15 | uVar17) & uVar19 | uVar15 & uVar17);
    uVar12 = param_2[4];
    local_60 = uVar12 << 0x18 | (uVar12 >> 8 & 0xff) << 0x10 | (uVar12 >> 0x10 & 0xff) << 8 |
               uVar12 >> 0x18;
    iVar4 = local_60 +
            ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
            (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar10 + ((uVar6 ^ uVar8) & uVar5 ^ uVar8) +
            piVar20[4];
    uVar19 = uVar19 + iVar4;
    uVar11 = ((uVar13 >> 2 | uVar13 * 0x40000000) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
             (uVar13 >> 0x16 | uVar13 * 0x400)) + iVar4 +
             ((uVar13 | uVar15) & uVar17 | uVar13 & uVar15);
    uVar10 = param_2[5];
    local_5c = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
               uVar10 >> 0x18;
    iVar4 = local_5c +
            ((uVar19 >> 6 | uVar19 * 0x4000000) ^ (uVar19 >> 0xb | uVar19 * 0x200000) ^
            (uVar19 >> 0x19 | uVar19 * 0x80)) + uVar8 + ((uVar5 ^ uVar6) & uVar19 ^ uVar6) +
            piVar20[5];
    uVar17 = uVar17 + iVar4;
    uVar9 = ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
            (uVar11 >> 0x16 | uVar11 * 0x400)) + iVar4 +
            ((uVar11 | uVar13) & uVar15 | uVar11 & uVar13);
    uVar8 = param_2[6];
    local_58 = uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
               uVar8 >> 0x18;
    iVar4 = local_58 +
            ((uVar17 >> 6 | uVar17 * 0x4000000) ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^
            (uVar17 >> 0x19 | uVar17 * 0x80)) + uVar6 + ((uVar19 ^ uVar5) & uVar17 ^ uVar5) +
            piVar20[6];
    uVar15 = uVar15 + iVar4;
    uVar7 = ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
            (uVar9 >> 0x16 | uVar9 * 0x400)) + iVar4 + ((uVar9 | uVar11) & uVar13 | uVar9 & uVar11);
    uVar6 = param_2[7];
    local_54 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
               uVar6 >> 0x18;
    iVar4 = local_54 +
            ((uVar15 >> 6 | uVar15 * 0x4000000) ^ (uVar15 >> 0xb | uVar15 * 0x200000) ^
            (uVar15 >> 0x19 | uVar15 * 0x80)) + uVar5 + ((uVar17 ^ uVar19) & uVar15 ^ uVar19) +
            piVar20[7];
    uVar13 = uVar13 + iVar4;
    uVar3 = ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
            (uVar7 >> 0x16 | uVar7 * 0x400)) + iVar4 + ((uVar7 | uVar9) & uVar11 | uVar7 & uVar9);
    uVar5 = param_2[8];
    local_50 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_50 +
            ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
            (uVar13 >> 0x19 | uVar13 * 0x80)) + uVar19 + ((uVar15 ^ uVar17) & uVar13 ^ uVar17) +
            piVar20[8];
    uVar11 = uVar11 + iVar4;
    uVar18 = ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
             (uVar3 >> 0x16 | uVar3 * 0x400)) + iVar4 + ((uVar3 | uVar7) & uVar9 | uVar3 & uVar7);
    uVar5 = param_2[9];
    local_4c = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_4c +
            ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
            (uVar11 >> 0x19 | uVar11 * 0x80)) + uVar17 + ((uVar13 ^ uVar15) & uVar11 ^ uVar15) +
            piVar20[9];
    uVar9 = uVar9 + iVar4;
    uVar16 = ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
             (uVar18 >> 0x16 | uVar18 * 0x400)) + iVar4 +
             ((uVar18 | uVar3) & uVar7 | uVar18 & uVar3);
    uVar5 = param_2[10];
    local_48 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_48 +
            ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
            (uVar9 >> 0x19 | uVar9 * 0x80)) + uVar15 + ((uVar11 ^ uVar13) & uVar9 ^ uVar13) +
            piVar20[10];
    uVar7 = uVar7 + iVar4;
    uVar14 = ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
             (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar4 +
             ((uVar16 | uVar18) & uVar3 | uVar16 & uVar18);
    uVar5 = param_2[0xb];
    local_44 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_44 +
            ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
            (uVar7 >> 0x19 | uVar7 * 0x80)) + uVar13 + ((uVar9 ^ uVar11) & uVar7 ^ uVar11) +
            piVar20[0xb];
    uVar3 = uVar3 + iVar4;
    uVar12 = ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
             (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar4 +
             ((uVar14 | uVar16) & uVar18 | uVar14 & uVar16);
    uVar5 = param_2[0xc];
    local_40 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_40 +
            ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
            (uVar3 >> 0x19 | uVar3 * 0x80)) + uVar11 + ((uVar7 ^ uVar9) & uVar3 ^ uVar9) +
            piVar20[0xc];
    uVar18 = uVar18 + iVar4;
    uVar10 = ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
             (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar4 +
             ((uVar12 | uVar14) & uVar16 | uVar12 & uVar14);
    uVar5 = param_2[0xd];
    local_3c = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_3c +
            ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
            (uVar18 >> 0x19 | uVar18 * 0x80)) + uVar9 + ((uVar3 ^ uVar7) & uVar18 ^ uVar7) +
            piVar20[0xd];
    uVar16 = uVar16 + iVar4;
    uVar8 = ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
            (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar4 +
            ((uVar10 | uVar12) & uVar14 | uVar10 & uVar12);
    puVar1 = param_2 + 0xf;
    uVar5 = param_2[0xe];
    local_38 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_38 +
            ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
            (uVar16 >> 0x19 | uVar16 * 0x80)) + uVar7 + ((uVar18 ^ uVar3) & uVar16 ^ uVar3) +
            piVar20[0xe];
    uVar14 = uVar14 + iVar4;
    uVar6 = ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
            (uVar8 >> 0x16 | uVar8 * 0x400)) + iVar4 + ((uVar8 | uVar10) & uVar12 | uVar8 & uVar10);
    param_2 = param_2 + 0x10;
    uVar5 = *puVar1;
    local_34 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
    iVar4 = local_34 +
            ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
            (uVar14 >> 0x19 | uVar14 * 0x80)) + uVar3 + ((uVar16 ^ uVar18) & uVar14 ^ uVar18) +
            piVar20[0xf];
    uVar12 = uVar12 + iVar4;
    uVar5 = ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
            (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar4 + ((uVar6 | uVar8) & uVar10 | uVar6 & uVar8);
    do {
      piVar21 = piVar20;
      local_70 = local_70 +
                 ((local_6c >> 7 | local_6c << 0x19) ^ (local_6c >> 0x12 | local_6c << 0xe) ^
                 local_6c >> 3) + local_4c +
                 ((local_38 >> 0x11 | local_38 << 0xf) ^ (local_38 >> 0x13 | local_38 << 0xd) ^
                 local_38 >> 10);
      iVar4 = local_70 +
              ((uVar12 >> 6 | uVar12 << 0x1a) ^ (uVar12 >> 0xb | uVar12 << 0x15) ^
              (uVar12 >> 0x19 | uVar12 << 7)) + uVar18 + ((uVar14 ^ uVar16) & uVar12 ^ uVar16) +
              piVar21[0x10];
      uVar10 = uVar10 + iVar4;
      uVar18 = ((uVar5 >> 2 | uVar5 << 0x1e) ^ (uVar5 >> 0xd | uVar5 << 0x13) ^
               (uVar5 >> 0x16 | uVar5 << 10)) + iVar4 + ((uVar5 | uVar6) & uVar8 | uVar5 & uVar6);
      local_6c = local_6c +
                 ((local_68 >> 7 | local_68 << 0x19) ^ (local_68 >> 0x12 | local_68 << 0xe) ^
                 local_68 >> 3) + local_48 +
                 ((local_34 >> 0x11 | local_34 << 0xf) ^ (local_34 >> 0x13 | local_34 << 0xd) ^
                 local_34 >> 10);
      iVar4 = local_6c +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + uVar16 + ((uVar12 ^ uVar14) & uVar10 ^ uVar14) +
              piVar21[0x11];
      uVar8 = uVar8 + iVar4;
      uVar16 = ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
               (uVar18 >> 0x16 | uVar18 * 0x400)) + iVar4 +
               ((uVar18 | uVar5) & uVar6 | uVar18 & uVar5);
      local_68 = local_68 +
                 ((local_64 >> 7 | local_64 << 0x19) ^ (local_64 >> 0x12 | local_64 << 0xe) ^
                 local_64 >> 3) + local_44 +
                 ((local_70 >> 0x11 | local_70 * 0x8000) ^ (local_70 >> 0x13 | local_70 * 0x2000) ^
                 local_70 >> 10);
      iVar4 = local_68 +
              ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
              (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar14 + ((uVar10 ^ uVar12) & uVar8 ^ uVar12) +
              piVar21[0x12];
      uVar6 = uVar6 + iVar4;
      uVar14 = ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
               (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar4 +
               ((uVar16 | uVar18) & uVar5 | uVar16 & uVar18);
      local_64 = local_64 +
                 ((local_60 >> 7 | local_60 << 0x19) ^ (local_60 >> 0x12 | local_60 << 0xe) ^
                 local_60 >> 3) + local_40 +
                 ((local_6c >> 0x11 | local_6c * 0x8000) ^ (local_6c >> 0x13 | local_6c * 0x2000) ^
                 local_6c >> 10);
      iVar4 = local_64 +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar12 + ((uVar8 ^ uVar10) & uVar6 ^ uVar10) +
              piVar21[0x13];
      uVar5 = uVar5 + iVar4;
      uVar12 = ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
               (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar4 +
               ((uVar14 | uVar16) & uVar18 | uVar14 & uVar16);
      local_60 = local_60 +
                 ((local_5c >> 7 | local_5c << 0x19) ^ (local_5c >> 0x12 | local_5c << 0xe) ^
                 local_5c >> 3) + local_3c +
                 ((local_68 >> 0x11 | local_68 * 0x8000) ^ (local_68 >> 0x13 | local_68 * 0x2000) ^
                 local_68 >> 10);
      iVar4 = local_60 +
              ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar10 + ((uVar6 ^ uVar8) & uVar5 ^ uVar8) +
              piVar21[0x14];
      uVar18 = uVar18 + iVar4;
      uVar10 = ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar4 +
               ((uVar12 | uVar14) & uVar16 | uVar12 & uVar14);
      local_5c = local_5c +
                 ((local_58 >> 7 | local_58 << 0x19) ^ (local_58 >> 0x12 | local_58 << 0xe) ^
                 local_58 >> 3) + local_38 +
                 ((local_64 >> 0x11 | local_64 * 0x8000) ^ (local_64 >> 0x13 | local_64 * 0x2000) ^
                 local_64 >> 10);
      iVar4 = local_5c +
              ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
              (uVar18 >> 0x19 | uVar18 * 0x80)) + uVar8 + ((uVar5 ^ uVar6) & uVar18 ^ uVar6) +
              piVar21[0x15];
      uVar16 = uVar16 + iVar4;
      uVar8 = ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar4 +
              ((uVar10 | uVar12) & uVar14 | uVar10 & uVar12);
      local_58 = local_58 +
                 ((local_54 >> 7 | local_54 << 0x19) ^ (local_54 >> 0x12 | local_54 << 0xe) ^
                 local_54 >> 3) + local_34 +
                 ((local_60 >> 0x11 | local_60 * 0x8000) ^ (local_60 >> 0x13 | local_60 * 0x2000) ^
                 local_60 >> 10);
      iVar4 = local_58 +
              ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
              (uVar16 >> 0x19 | uVar16 * 0x80)) + uVar6 + ((uVar18 ^ uVar5) & uVar16 ^ uVar5) +
              piVar21[0x16];
      uVar14 = uVar14 + iVar4;
      uVar6 = ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
              (uVar8 >> 0x16 | uVar8 * 0x400)) + iVar4 +
              ((uVar8 | uVar10) & uVar12 | uVar8 & uVar10);
      local_54 = local_54 +
                 ((local_50 >> 7 | local_50 << 0x19) ^ (local_50 >> 0x12 | local_50 << 0xe) ^
                 local_50 >> 3) + local_70 +
                 ((local_5c >> 0x11 | local_5c * 0x8000) ^ (local_5c >> 0x13 | local_5c * 0x2000) ^
                 local_5c >> 10);
      iVar4 = local_54 +
              ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
              (uVar14 >> 0x19 | uVar14 * 0x80)) + uVar5 + ((uVar16 ^ uVar18) & uVar14 ^ uVar18) +
              piVar21[0x17];
      uVar12 = uVar12 + iVar4;
      uVar5 = ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
              (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar4 + ((uVar6 | uVar8) & uVar10 | uVar6 & uVar8);
      local_50 = local_50 +
                 ((local_4c >> 7 | local_4c << 0x19) ^ (local_4c >> 0x12 | local_4c << 0xe) ^
                 local_4c >> 3) + local_6c +
                 ((local_58 >> 0x11 | local_58 * 0x8000) ^ (local_58 >> 0x13 | local_58 * 0x2000) ^
                 local_58 >> 10);
      iVar4 = local_50 +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80)) + uVar18 + ((uVar14 ^ uVar16) & uVar12 ^ uVar16) +
              piVar21[0x18];
      uVar10 = uVar10 + iVar4;
      uVar18 = ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
               (uVar5 >> 0x16 | uVar5 * 0x400)) + iVar4 + ((uVar5 | uVar6) & uVar8 | uVar5 & uVar6);
      local_4c = local_4c +
                 ((local_48 >> 7 | local_48 << 0x19) ^ (local_48 >> 0x12 | local_48 << 0xe) ^
                 local_48 >> 3) + local_68 +
                 ((local_54 >> 0x11 | local_54 * 0x8000) ^ (local_54 >> 0x13 | local_54 * 0x2000) ^
                 local_54 >> 10);
      iVar4 = local_4c +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + uVar16 + ((uVar12 ^ uVar14) & uVar10 ^ uVar14) +
              piVar21[0x19];
      uVar8 = uVar8 + iVar4;
      uVar16 = ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
               (uVar18 >> 0x16 | uVar18 * 0x400)) + iVar4 +
               ((uVar18 | uVar5) & uVar6 | uVar18 & uVar5);
      local_48 = local_48 +
                 ((local_44 >> 7 | local_44 << 0x19) ^ (local_44 >> 0x12 | local_44 << 0xe) ^
                 local_44 >> 3) + local_64 +
                 ((local_50 >> 0x11 | local_50 * 0x8000) ^ (local_50 >> 0x13 | local_50 * 0x2000) ^
                 local_50 >> 10);
      iVar4 = local_48 +
              ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
              (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar14 + ((uVar10 ^ uVar12) & uVar8 ^ uVar12) +
              piVar21[0x1a];
      uVar6 = uVar6 + iVar4;
      uVar14 = ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
               (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar4 +
               ((uVar16 | uVar18) & uVar5 | uVar16 & uVar18);
      local_44 = local_44 +
                 ((local_40 >> 7 | local_40 << 0x19) ^ (local_40 >> 0x12 | local_40 << 0xe) ^
                 local_40 >> 3) + local_60 +
                 ((local_4c >> 0x11 | local_4c * 0x8000) ^ (local_4c >> 0x13 | local_4c * 0x2000) ^
                 local_4c >> 10);
      iVar4 = local_44 +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar12 + ((uVar8 ^ uVar10) & uVar6 ^ uVar10) +
              piVar21[0x1b];
      uVar5 = uVar5 + iVar4;
      uVar12 = ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
               (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar4 +
               ((uVar14 | uVar16) & uVar18 | uVar14 & uVar16);
      local_40 = local_40 +
                 ((local_3c >> 7 | local_3c << 0x19) ^ (local_3c >> 0x12 | local_3c << 0xe) ^
                 local_3c >> 3) + local_5c +
                 ((local_48 >> 0x11 | local_48 * 0x8000) ^ (local_48 >> 0x13 | local_48 * 0x2000) ^
                 local_48 >> 10);
      iVar4 = local_40 +
              ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar10 + ((uVar6 ^ uVar8) & uVar5 ^ uVar8) +
              piVar21[0x1c];
      uVar18 = uVar18 + iVar4;
      uVar10 = ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar4 +
               ((uVar12 | uVar14) & uVar16 | uVar12 & uVar14);
      local_3c = local_3c +
                 ((local_38 >> 7 | local_38 << 0x19) ^ (local_38 >> 0x12 | local_38 << 0xe) ^
                 local_38 >> 3) + local_58 +
                 ((local_44 >> 0x11 | local_44 * 0x8000) ^ (local_44 >> 0x13 | local_44 * 0x2000) ^
                 local_44 >> 10);
      iVar4 = local_3c +
              ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
              (uVar18 >> 0x19 | uVar18 * 0x80)) + uVar8 + ((uVar5 ^ uVar6) & uVar18 ^ uVar6) +
              piVar21[0x1d];
      uVar16 = uVar16 + iVar4;
      uVar8 = ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar4 +
              ((uVar10 | uVar12) & uVar14 | uVar10 & uVar12);
      local_38 = local_38 +
                 ((local_34 >> 7 | local_34 << 0x19) ^ (local_34 >> 0x12 | local_34 << 0xe) ^
                 local_34 >> 3) + local_54 +
                 ((local_40 >> 0x11 | local_40 * 0x8000) ^ (local_40 >> 0x13 | local_40 * 0x2000) ^
                 local_40 >> 10);
      iVar4 = local_38 +
              ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
              (uVar16 >> 0x19 | uVar16 * 0x80)) + uVar6 + ((uVar18 ^ uVar5) & uVar16 ^ uVar5) +
              piVar21[0x1e];
      uVar14 = uVar14 + iVar4;
      uVar6 = ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
              (uVar8 >> 0x16 | uVar8 * 0x400)) + iVar4 +
              ((uVar8 | uVar10) & uVar12 | uVar8 & uVar10);
      local_34 = local_34 +
                 ((local_70 >> 7 | local_70 * 0x2000000) ^ (local_70 >> 0x12 | local_70 * 0x4000) ^
                 local_70 >> 3) + local_50 +
                 ((local_3c >> 0x11 | local_3c * 0x8000) ^ (local_3c >> 0x13 | local_3c * 0x2000) ^
                 local_3c >> 10);
      iVar4 = local_34 +
              ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
              (uVar14 >> 0x19 | uVar14 * 0x80)) + uVar5 + ((uVar16 ^ uVar18) & uVar14 ^ uVar18) +
              piVar21[0x1f];
      uVar12 = uVar12 + iVar4;
      uVar5 = ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
              (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar4 + ((uVar6 | uVar8) & uVar10 | uVar6 & uVar8);
      piVar20 = piVar21 + 0x10;
    } while ((piVar21[0x1f] & 0xffU) != 0xf2);
    uVar5 = uVar5 + *param_1;
    uVar6 = uVar6 + param_1[1];
    uVar8 = uVar8 + param_1[2];
    uVar10 = uVar10 + param_1[3];
    uVar12 = uVar12 + param_1[4];
    uVar14 = uVar14 + param_1[5];
    uVar16 = uVar16 + param_1[6];
    uVar18 = uVar18 + param_1[7];
    *param_1 = uVar5;
    param_1[1] = uVar6;
    param_1[2] = uVar8;
    param_1[3] = uVar10;
    param_1[4] = uVar12;
    param_1[5] = uVar14;
    param_1[6] = uVar16;
    param_1[7] = uVar18;
    piVar20 = piVar21 + -0x20;
  } while (param_2 != puVar2);
  return;
}

