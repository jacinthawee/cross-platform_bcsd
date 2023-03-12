
void __sha256_block_data_order_from_thumb(uint *param_1,uint *param_2,int param_3)

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
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  
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
    uStack_70 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                uVar3 >> 0x18;
    iVar4 = uStack_70 +
            ((uVar12 >> 6 | uVar12 << 0x1a) ^ (uVar12 >> 0xb | uVar12 << 0x15) ^
            (uVar12 >> 0x19 | uVar12 << 7)) + uVar18 + ((uVar14 ^ uVar16) & uVar12 ^ uVar16) +
            *piVar20;
    uVar10 = uVar10 + iVar4;
    uVar19 = ((uVar5 >> 2 | uVar5 << 0x1e) ^ (uVar5 >> 0xd | uVar5 << 0x13) ^
             (uVar5 >> 0x16 | uVar5 << 10)) + iVar4 + ((uVar5 | uVar6) & uVar8 | uVar5 & uVar6);
    uVar18 = param_2[1];
    uStack_6c = uVar18 << 0x18 | (uVar18 >> 8 & 0xff) << 0x10 | (uVar18 >> 0x10 & 0xff) << 8 |
                uVar18 >> 0x18;
    iVar4 = uStack_6c +
            ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
            (uVar10 >> 0x19 | uVar10 * 0x80)) + uVar16 + ((uVar12 ^ uVar14) & uVar10 ^ uVar14) +
            piVar20[1];
    uVar8 = uVar8 + iVar4;
    uVar17 = ((uVar19 >> 2 | uVar19 * 0x40000000) ^ (uVar19 >> 0xd | uVar19 * 0x80000) ^
             (uVar19 >> 0x16 | uVar19 * 0x400)) + iVar4 +
             ((uVar19 | uVar5) & uVar6 | uVar19 & uVar5);
    uVar16 = param_2[2];
    uStack_68 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                uVar16 >> 0x18;
    iVar4 = uStack_68 +
            ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
            (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar14 + ((uVar10 ^ uVar12) & uVar8 ^ uVar12) +
            piVar20[2];
    uVar6 = uVar6 + iVar4;
    uVar15 = ((uVar17 >> 2 | uVar17 * 0x40000000) ^ (uVar17 >> 0xd | uVar17 * 0x80000) ^
             (uVar17 >> 0x16 | uVar17 * 0x400)) + iVar4 +
             ((uVar17 | uVar19) & uVar5 | uVar17 & uVar19);
    uVar14 = param_2[3];
    uStack_64 = uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
                uVar14 >> 0x18;
    iVar4 = uStack_64 +
            ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
            (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar12 + ((uVar8 ^ uVar10) & uVar6 ^ uVar10) +
            piVar20[3];
    uVar5 = uVar5 + iVar4;
    uVar13 = ((uVar15 >> 2 | uVar15 * 0x40000000) ^ (uVar15 >> 0xd | uVar15 * 0x80000) ^
             (uVar15 >> 0x16 | uVar15 * 0x400)) + iVar4 +
             ((uVar15 | uVar17) & uVar19 | uVar15 & uVar17);
    uVar12 = param_2[4];
    uStack_60 = uVar12 << 0x18 | (uVar12 >> 8 & 0xff) << 0x10 | (uVar12 >> 0x10 & 0xff) << 8 |
                uVar12 >> 0x18;
    iVar4 = uStack_60 +
            ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
            (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar10 + ((uVar6 ^ uVar8) & uVar5 ^ uVar8) +
            piVar20[4];
    uVar19 = uVar19 + iVar4;
    uVar11 = ((uVar13 >> 2 | uVar13 * 0x40000000) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
             (uVar13 >> 0x16 | uVar13 * 0x400)) + iVar4 +
             ((uVar13 | uVar15) & uVar17 | uVar13 & uVar15);
    uVar10 = param_2[5];
    uStack_5c = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                uVar10 >> 0x18;
    iVar4 = uStack_5c +
            ((uVar19 >> 6 | uVar19 * 0x4000000) ^ (uVar19 >> 0xb | uVar19 * 0x200000) ^
            (uVar19 >> 0x19 | uVar19 * 0x80)) + uVar8 + ((uVar5 ^ uVar6) & uVar19 ^ uVar6) +
            piVar20[5];
    uVar17 = uVar17 + iVar4;
    uVar9 = ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
            (uVar11 >> 0x16 | uVar11 * 0x400)) + iVar4 +
            ((uVar11 | uVar13) & uVar15 | uVar11 & uVar13);
    uVar8 = param_2[6];
    uStack_58 = uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
                uVar8 >> 0x18;
    iVar4 = uStack_58 +
            ((uVar17 >> 6 | uVar17 * 0x4000000) ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^
            (uVar17 >> 0x19 | uVar17 * 0x80)) + uVar6 + ((uVar19 ^ uVar5) & uVar17 ^ uVar5) +
            piVar20[6];
    uVar15 = uVar15 + iVar4;
    uVar7 = ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
            (uVar9 >> 0x16 | uVar9 * 0x400)) + iVar4 + ((uVar9 | uVar11) & uVar13 | uVar9 & uVar11);
    uVar6 = param_2[7];
    uStack_54 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
    iVar4 = uStack_54 +
            ((uVar15 >> 6 | uVar15 * 0x4000000) ^ (uVar15 >> 0xb | uVar15 * 0x200000) ^
            (uVar15 >> 0x19 | uVar15 * 0x80)) + uVar5 + ((uVar17 ^ uVar19) & uVar15 ^ uVar19) +
            piVar20[7];
    uVar13 = uVar13 + iVar4;
    uVar3 = ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
            (uVar7 >> 0x16 | uVar7 * 0x400)) + iVar4 + ((uVar7 | uVar9) & uVar11 | uVar7 & uVar9);
    uVar5 = param_2[8];
    uStack_50 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_50 +
            ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
            (uVar13 >> 0x19 | uVar13 * 0x80)) + uVar19 + ((uVar15 ^ uVar17) & uVar13 ^ uVar17) +
            piVar20[8];
    uVar11 = uVar11 + iVar4;
    uVar18 = ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
             (uVar3 >> 0x16 | uVar3 * 0x400)) + iVar4 + ((uVar3 | uVar7) & uVar9 | uVar3 & uVar7);
    uVar5 = param_2[9];
    uStack_4c = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_4c +
            ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
            (uVar11 >> 0x19 | uVar11 * 0x80)) + uVar17 + ((uVar13 ^ uVar15) & uVar11 ^ uVar15) +
            piVar20[9];
    uVar9 = uVar9 + iVar4;
    uVar16 = ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
             (uVar18 >> 0x16 | uVar18 * 0x400)) + iVar4 +
             ((uVar18 | uVar3) & uVar7 | uVar18 & uVar3);
    uVar5 = param_2[10];
    uStack_48 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_48 +
            ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
            (uVar9 >> 0x19 | uVar9 * 0x80)) + uVar15 + ((uVar11 ^ uVar13) & uVar9 ^ uVar13) +
            piVar20[10];
    uVar7 = uVar7 + iVar4;
    uVar14 = ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
             (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar4 +
             ((uVar16 | uVar18) & uVar3 | uVar16 & uVar18);
    uVar5 = param_2[0xb];
    uStack_44 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_44 +
            ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
            (uVar7 >> 0x19 | uVar7 * 0x80)) + uVar13 + ((uVar9 ^ uVar11) & uVar7 ^ uVar11) +
            piVar20[0xb];
    uVar3 = uVar3 + iVar4;
    uVar12 = ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
             (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar4 +
             ((uVar14 | uVar16) & uVar18 | uVar14 & uVar16);
    uVar5 = param_2[0xc];
    uStack_40 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_40 +
            ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
            (uVar3 >> 0x19 | uVar3 * 0x80)) + uVar11 + ((uVar7 ^ uVar9) & uVar3 ^ uVar9) +
            piVar20[0xc];
    uVar18 = uVar18 + iVar4;
    uVar10 = ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
             (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar4 +
             ((uVar12 | uVar14) & uVar16 | uVar12 & uVar14);
    uVar5 = param_2[0xd];
    uStack_3c = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_3c +
            ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
            (uVar18 >> 0x19 | uVar18 * 0x80)) + uVar9 + ((uVar3 ^ uVar7) & uVar18 ^ uVar7) +
            piVar20[0xd];
    uVar16 = uVar16 + iVar4;
    uVar8 = ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
            (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar4 +
            ((uVar10 | uVar12) & uVar14 | uVar10 & uVar12);
    puVar1 = param_2 + 0xf;
    uVar5 = param_2[0xe];
    uStack_38 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_38 +
            ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
            (uVar16 >> 0x19 | uVar16 * 0x80)) + uVar7 + ((uVar18 ^ uVar3) & uVar16 ^ uVar3) +
            piVar20[0xe];
    uVar14 = uVar14 + iVar4;
    uVar6 = ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
            (uVar8 >> 0x16 | uVar8 * 0x400)) + iVar4 + ((uVar8 | uVar10) & uVar12 | uVar8 & uVar10);
    param_2 = param_2 + 0x10;
    uVar5 = *puVar1;
    uStack_34 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    iVar4 = uStack_34 +
            ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
            (uVar14 >> 0x19 | uVar14 * 0x80)) + uVar3 + ((uVar16 ^ uVar18) & uVar14 ^ uVar18) +
            piVar20[0xf];
    uVar12 = uVar12 + iVar4;
    uVar5 = ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
            (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar4 + ((uVar6 | uVar8) & uVar10 | uVar6 & uVar8);
    do {
      piVar21 = piVar20;
      uStack_70 = uStack_70 +
                  ((uStack_6c >> 7 | uStack_6c << 0x19) ^ (uStack_6c >> 0x12 | uStack_6c << 0xe) ^
                  uStack_6c >> 3) + uStack_4c +
                  ((uStack_38 >> 0x11 | uStack_38 << 0xf) ^ (uStack_38 >> 0x13 | uStack_38 << 0xd) ^
                  uStack_38 >> 10);
      iVar4 = uStack_70 +
              ((uVar12 >> 6 | uVar12 << 0x1a) ^ (uVar12 >> 0xb | uVar12 << 0x15) ^
              (uVar12 >> 0x19 | uVar12 << 7)) + uVar18 + ((uVar14 ^ uVar16) & uVar12 ^ uVar16) +
              piVar21[0x10];
      uVar10 = uVar10 + iVar4;
      uVar18 = ((uVar5 >> 2 | uVar5 << 0x1e) ^ (uVar5 >> 0xd | uVar5 << 0x13) ^
               (uVar5 >> 0x16 | uVar5 << 10)) + iVar4 + ((uVar5 | uVar6) & uVar8 | uVar5 & uVar6);
      uStack_6c = uStack_6c +
                  ((uStack_68 >> 7 | uStack_68 << 0x19) ^ (uStack_68 >> 0x12 | uStack_68 << 0xe) ^
                  uStack_68 >> 3) + uStack_48 +
                  ((uStack_34 >> 0x11 | uStack_34 << 0xf) ^ (uStack_34 >> 0x13 | uStack_34 << 0xd) ^
                  uStack_34 >> 10);
      iVar4 = uStack_6c +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + uVar16 + ((uVar12 ^ uVar14) & uVar10 ^ uVar14) +
              piVar21[0x11];
      uVar8 = uVar8 + iVar4;
      uVar16 = ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
               (uVar18 >> 0x16 | uVar18 * 0x400)) + iVar4 +
               ((uVar18 | uVar5) & uVar6 | uVar18 & uVar5);
      uStack_68 = uStack_68 +
                  ((uStack_64 >> 7 | uStack_64 << 0x19) ^ (uStack_64 >> 0x12 | uStack_64 << 0xe) ^
                  uStack_64 >> 3) + uStack_44 +
                  ((uStack_70 >> 0x11 | uStack_70 * 0x8000) ^
                   (uStack_70 >> 0x13 | uStack_70 * 0x2000) ^ uStack_70 >> 10);
      iVar4 = uStack_68 +
              ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
              (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar14 + ((uVar10 ^ uVar12) & uVar8 ^ uVar12) +
              piVar21[0x12];
      uVar6 = uVar6 + iVar4;
      uVar14 = ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
               (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar4 +
               ((uVar16 | uVar18) & uVar5 | uVar16 & uVar18);
      uStack_64 = uStack_64 +
                  ((uStack_60 >> 7 | uStack_60 << 0x19) ^ (uStack_60 >> 0x12 | uStack_60 << 0xe) ^
                  uStack_60 >> 3) + uStack_40 +
                  ((uStack_6c >> 0x11 | uStack_6c * 0x8000) ^
                   (uStack_6c >> 0x13 | uStack_6c * 0x2000) ^ uStack_6c >> 10);
      iVar4 = uStack_64 +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar12 + ((uVar8 ^ uVar10) & uVar6 ^ uVar10) +
              piVar21[0x13];
      uVar5 = uVar5 + iVar4;
      uVar12 = ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
               (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar4 +
               ((uVar14 | uVar16) & uVar18 | uVar14 & uVar16);
      uStack_60 = uStack_60 +
                  ((uStack_5c >> 7 | uStack_5c << 0x19) ^ (uStack_5c >> 0x12 | uStack_5c << 0xe) ^
                  uStack_5c >> 3) + uStack_3c +
                  ((uStack_68 >> 0x11 | uStack_68 * 0x8000) ^
                   (uStack_68 >> 0x13 | uStack_68 * 0x2000) ^ uStack_68 >> 10);
      iVar4 = uStack_60 +
              ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar10 + ((uVar6 ^ uVar8) & uVar5 ^ uVar8) +
              piVar21[0x14];
      uVar18 = uVar18 + iVar4;
      uVar10 = ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar4 +
               ((uVar12 | uVar14) & uVar16 | uVar12 & uVar14);
      uStack_5c = uStack_5c +
                  ((uStack_58 >> 7 | uStack_58 << 0x19) ^ (uStack_58 >> 0x12 | uStack_58 << 0xe) ^
                  uStack_58 >> 3) + uStack_38 +
                  ((uStack_64 >> 0x11 | uStack_64 * 0x8000) ^
                   (uStack_64 >> 0x13 | uStack_64 * 0x2000) ^ uStack_64 >> 10);
      iVar4 = uStack_5c +
              ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
              (uVar18 >> 0x19 | uVar18 * 0x80)) + uVar8 + ((uVar5 ^ uVar6) & uVar18 ^ uVar6) +
              piVar21[0x15];
      uVar16 = uVar16 + iVar4;
      uVar8 = ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar4 +
              ((uVar10 | uVar12) & uVar14 | uVar10 & uVar12);
      uStack_58 = uStack_58 +
                  ((uStack_54 >> 7 | uStack_54 << 0x19) ^ (uStack_54 >> 0x12 | uStack_54 << 0xe) ^
                  uStack_54 >> 3) + uStack_34 +
                  ((uStack_60 >> 0x11 | uStack_60 * 0x8000) ^
                   (uStack_60 >> 0x13 | uStack_60 * 0x2000) ^ uStack_60 >> 10);
      iVar4 = uStack_58 +
              ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
              (uVar16 >> 0x19 | uVar16 * 0x80)) + uVar6 + ((uVar18 ^ uVar5) & uVar16 ^ uVar5) +
              piVar21[0x16];
      uVar14 = uVar14 + iVar4;
      uVar6 = ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
              (uVar8 >> 0x16 | uVar8 * 0x400)) + iVar4 +
              ((uVar8 | uVar10) & uVar12 | uVar8 & uVar10);
      uStack_54 = uStack_54 +
                  ((uStack_50 >> 7 | uStack_50 << 0x19) ^ (uStack_50 >> 0x12 | uStack_50 << 0xe) ^
                  uStack_50 >> 3) + uStack_70 +
                  ((uStack_5c >> 0x11 | uStack_5c * 0x8000) ^
                   (uStack_5c >> 0x13 | uStack_5c * 0x2000) ^ uStack_5c >> 10);
      iVar4 = uStack_54 +
              ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
              (uVar14 >> 0x19 | uVar14 * 0x80)) + uVar5 + ((uVar16 ^ uVar18) & uVar14 ^ uVar18) +
              piVar21[0x17];
      uVar12 = uVar12 + iVar4;
      uVar5 = ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
              (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar4 + ((uVar6 | uVar8) & uVar10 | uVar6 & uVar8);
      uStack_50 = uStack_50 +
                  ((uStack_4c >> 7 | uStack_4c << 0x19) ^ (uStack_4c >> 0x12 | uStack_4c << 0xe) ^
                  uStack_4c >> 3) + uStack_6c +
                  ((uStack_58 >> 0x11 | uStack_58 * 0x8000) ^
                   (uStack_58 >> 0x13 | uStack_58 * 0x2000) ^ uStack_58 >> 10);
      iVar4 = uStack_50 +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80)) + uVar18 + ((uVar14 ^ uVar16) & uVar12 ^ uVar16) +
              piVar21[0x18];
      uVar10 = uVar10 + iVar4;
      uVar18 = ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
               (uVar5 >> 0x16 | uVar5 * 0x400)) + iVar4 + ((uVar5 | uVar6) & uVar8 | uVar5 & uVar6);
      uStack_4c = uStack_4c +
                  ((uStack_48 >> 7 | uStack_48 << 0x19) ^ (uStack_48 >> 0x12 | uStack_48 << 0xe) ^
                  uStack_48 >> 3) + uStack_68 +
                  ((uStack_54 >> 0x11 | uStack_54 * 0x8000) ^
                   (uStack_54 >> 0x13 | uStack_54 * 0x2000) ^ uStack_54 >> 10);
      iVar4 = uStack_4c +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + uVar16 + ((uVar12 ^ uVar14) & uVar10 ^ uVar14) +
              piVar21[0x19];
      uVar8 = uVar8 + iVar4;
      uVar16 = ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
               (uVar18 >> 0x16 | uVar18 * 0x400)) + iVar4 +
               ((uVar18 | uVar5) & uVar6 | uVar18 & uVar5);
      uStack_48 = uStack_48 +
                  ((uStack_44 >> 7 | uStack_44 << 0x19) ^ (uStack_44 >> 0x12 | uStack_44 << 0xe) ^
                  uStack_44 >> 3) + uStack_64 +
                  ((uStack_50 >> 0x11 | uStack_50 * 0x8000) ^
                   (uStack_50 >> 0x13 | uStack_50 * 0x2000) ^ uStack_50 >> 10);
      iVar4 = uStack_48 +
              ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
              (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar14 + ((uVar10 ^ uVar12) & uVar8 ^ uVar12) +
              piVar21[0x1a];
      uVar6 = uVar6 + iVar4;
      uVar14 = ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
               (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar4 +
               ((uVar16 | uVar18) & uVar5 | uVar16 & uVar18);
      uStack_44 = uStack_44 +
                  ((uStack_40 >> 7 | uStack_40 << 0x19) ^ (uStack_40 >> 0x12 | uStack_40 << 0xe) ^
                  uStack_40 >> 3) + uStack_60 +
                  ((uStack_4c >> 0x11 | uStack_4c * 0x8000) ^
                   (uStack_4c >> 0x13 | uStack_4c * 0x2000) ^ uStack_4c >> 10);
      iVar4 = uStack_44 +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar12 + ((uVar8 ^ uVar10) & uVar6 ^ uVar10) +
              piVar21[0x1b];
      uVar5 = uVar5 + iVar4;
      uVar12 = ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
               (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar4 +
               ((uVar14 | uVar16) & uVar18 | uVar14 & uVar16);
      uStack_40 = uStack_40 +
                  ((uStack_3c >> 7 | uStack_3c << 0x19) ^ (uStack_3c >> 0x12 | uStack_3c << 0xe) ^
                  uStack_3c >> 3) + uStack_5c +
                  ((uStack_48 >> 0x11 | uStack_48 * 0x8000) ^
                   (uStack_48 >> 0x13 | uStack_48 * 0x2000) ^ uStack_48 >> 10);
      iVar4 = uStack_40 +
              ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar10 + ((uVar6 ^ uVar8) & uVar5 ^ uVar8) +
              piVar21[0x1c];
      uVar18 = uVar18 + iVar4;
      uVar10 = ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar4 +
               ((uVar12 | uVar14) & uVar16 | uVar12 & uVar14);
      uStack_3c = uStack_3c +
                  ((uStack_38 >> 7 | uStack_38 << 0x19) ^ (uStack_38 >> 0x12 | uStack_38 << 0xe) ^
                  uStack_38 >> 3) + uStack_58 +
                  ((uStack_44 >> 0x11 | uStack_44 * 0x8000) ^
                   (uStack_44 >> 0x13 | uStack_44 * 0x2000) ^ uStack_44 >> 10);
      iVar4 = uStack_3c +
              ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
              (uVar18 >> 0x19 | uVar18 * 0x80)) + uVar8 + ((uVar5 ^ uVar6) & uVar18 ^ uVar6) +
              piVar21[0x1d];
      uVar16 = uVar16 + iVar4;
      uVar8 = ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar4 +
              ((uVar10 | uVar12) & uVar14 | uVar10 & uVar12);
      uStack_38 = uStack_38 +
                  ((uStack_34 >> 7 | uStack_34 << 0x19) ^ (uStack_34 >> 0x12 | uStack_34 << 0xe) ^
                  uStack_34 >> 3) + uStack_54 +
                  ((uStack_40 >> 0x11 | uStack_40 * 0x8000) ^
                   (uStack_40 >> 0x13 | uStack_40 * 0x2000) ^ uStack_40 >> 10);
      iVar4 = uStack_38 +
              ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
              (uVar16 >> 0x19 | uVar16 * 0x80)) + uVar6 + ((uVar18 ^ uVar5) & uVar16 ^ uVar5) +
              piVar21[0x1e];
      uVar14 = uVar14 + iVar4;
      uVar6 = ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
              (uVar8 >> 0x16 | uVar8 * 0x400)) + iVar4 +
              ((uVar8 | uVar10) & uVar12 | uVar8 & uVar10);
      uStack_34 = uStack_34 +
                  ((uStack_70 >> 7 | uStack_70 * 0x2000000) ^
                   (uStack_70 >> 0x12 | uStack_70 * 0x4000) ^ uStack_70 >> 3) + uStack_50 +
                  ((uStack_3c >> 0x11 | uStack_3c * 0x8000) ^
                   (uStack_3c >> 0x13 | uStack_3c * 0x2000) ^ uStack_3c >> 10);
      iVar4 = uStack_34 +
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

