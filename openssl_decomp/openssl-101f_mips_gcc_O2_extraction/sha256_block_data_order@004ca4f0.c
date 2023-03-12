
int sha256_block_data_order(uint *param_1,uint param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint in_t4;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint in_t5;
  uint uVar22;
  uint in_t6;
  uint uVar23;
  undefined1 *puVar24;
  uint unaff_s3;
  uint unaff_s6;
  uint unaff_s7;
  uint in_t8;
  uint uVar25;
  uint uVar26;
  uint unaff_s8;
  uint local_e4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  int local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  int local_ac;
  undefined1 *local_a0;
  uint local_6c [4];
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
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_ac = param_3 - 1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar5 = param_1;
  if (param_3 != 0) {
    local_b0 = param_1[7];
    local_d0 = *param_1;
    uVar2 = param_2 & 3;
    local_c4 = param_2 + 0x40;
    local_cc = param_1[1];
    local_c8 = param_1[2];
    local_a0 = K256;
    local_c0 = param_1[3];
    local_bc = param_1[4];
    local_b8 = param_1[5];
    local_b4 = param_1[6];
    if (uVar2 != 0) goto LAB_004cb5e0;
    do {
      iVar4 = ((local_bc >> 6) + local_bc * 0x4000000 ^ (local_bc >> 0xb) + local_bc * 0x200000 ^
              (local_bc >> 0x19) + local_bc * 0x80) +
              local_b0 + 0x428a2f98 + *(uint *)(local_c4 + -0x40) +
              (~local_bc & local_b4 ^ local_bc & local_b8);
      local_6c[1] = *(uint *)(&DAT_ffffffc4 + local_c4);
      local_6c[0] = *(uint *)(local_c4 + -0x40);
      local_6c[2] = *(uint *)(&DAT_ffffffc8 + local_c4);
      local_6c[3] = *(uint *)(&DAT_ffffffcc + local_c4);
      local_5c = *(uint *)(local_c4 + -0x30);
      local_54 = *(uint *)(local_c4 + -0x28);
      uVar14 = iVar4 + local_c0;
      local_4c = *(uint *)(local_c4 + -0x20);
      local_58 = *(uint *)(local_c4 + -0x2c);
      local_50 = *(uint *)(local_c4 + -0x24);
      local_48 = *(uint *)(local_c4 + -0x1c);
      local_34 = *(uint *)(local_c4 + -8);
      local_30 = *(uint *)(local_c4 + -4);
      local_38 = *(uint *)(local_c4 + -0xc);
      iVar9 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
              (uVar14 >> 0x19) + uVar14 * 0x80) +
              local_b4 + 0x71374491 + *(uint *)(&DAT_ffffffc4 + local_c4) +
              (~uVar14 & local_b8 ^ uVar14 & local_bc);
      local_3c = *(uint *)(local_c4 + -0x10);
      local_40 = *(uint *)(local_c4 + -0x14);
      uVar12 = iVar9 + local_c8;
      local_44 = *(uint *)(local_c4 + -0x18);
      iVar8 = ((uVar12 >> 6) + uVar12 * 0x4000000 ^ (uVar12 >> 0xb) + uVar12 * 0x200000 ^
              (uVar12 >> 0x19) + uVar12 * 0x80) +
              local_b8 + 0xb5c0fbcf + *(uint *)(&DAT_ffffffc8 + local_c4) +
              (~uVar12 & local_bc ^ uVar14 & uVar12);
      uVar17 = iVar8 + local_cc;
      uVar3 = iVar4 + ((local_d0 >> 2) + local_d0 * 0x40000000 ^
                       (local_d0 >> 0xd) + local_d0 * 0x80000 ^
                      (local_d0 >> 0x16) + local_d0 * 0x400) +
                      (local_d0 & local_c8 ^ local_d0 & local_cc ^ local_cc & local_c8);
      iVar6 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
              (uVar17 >> 0x19) + uVar17 * 0x80) +
              local_bc + 0xe9b5dba5 + *(uint *)(&DAT_ffffffcc + local_c4) +
              (~uVar17 & uVar14 ^ uVar12 & uVar17);
      uVar19 = iVar6 + local_d0;
      uVar10 = iVar9 + ((uVar3 >> 2) + uVar3 * 0x40000000 ^ (uVar3 >> 0xd) + uVar3 * 0x80000 ^
                       (uVar3 >> 0x16) + uVar3 * 0x400) +
                       ((local_d0 ^ local_cc) & uVar3 ^ local_d0 & local_cc);
      iVar9 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
              (uVar19 >> 0x19) + uVar19 * 0x80) + *(uint *)(local_c4 + -0x30) + 0x3956c25b + uVar14
              + (~uVar19 & uVar12 ^ uVar17 & uVar19);
      uVar15 = uVar3 + iVar9;
      uVar14 = iVar8 + ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                       (uVar10 >> 0x16) + uVar10 * 0x400) +
                       ((uVar3 ^ local_d0) & uVar10 ^ uVar3 & local_d0);
      iVar4 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
              (uVar15 >> 0x19) + uVar15 * 0x80) + *(uint *)(local_c4 + -0x2c) + 0x59f111f1 + uVar12
              + (~uVar15 & uVar17 ^ uVar19 & uVar15);
      uVar13 = uVar10 + iVar4;
      uVar3 = iVar6 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                      (uVar14 >> 0x16) + uVar14 * 0x400) +
                      ((uVar3 ^ uVar10) & uVar14 ^ uVar3 & uVar10);
      iVar8 = ((uVar13 >> 6) + uVar13 * 0x4000000 ^ (uVar13 >> 0xb) + uVar13 * 0x200000 ^
              (uVar13 >> 0x19) + uVar13 * 0x80) + *(uint *)(local_c4 + -0x28) + 0x923f82a4 + uVar17
              + (~uVar13 & uVar19 ^ uVar15 & uVar13);
      uVar18 = uVar14 + iVar8;
      uVar12 = iVar9 + ((uVar3 >> 2) + uVar3 * 0x40000000 ^ (uVar3 >> 0xd) + uVar3 * 0x80000 ^
                       (uVar3 >> 0x16) + uVar3 * 0x400) +
                       ((uVar10 ^ uVar14) & uVar3 ^ uVar10 & uVar14);
      iVar6 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
              (uVar18 >> 0x19) + uVar18 * 0x80) + *(uint *)(local_c4 + -0x24) + 0xab1c5ed5 + uVar19
              + (~uVar18 & uVar15 ^ uVar13 & uVar18);
      uVar17 = uVar3 + iVar6;
      uVar10 = iVar4 + ((uVar12 >> 2) + uVar12 * 0x40000000 ^ (uVar12 >> 0xd) + uVar12 * 0x80000 ^
                       (uVar12 >> 0x16) + uVar12 * 0x400) +
                       ((uVar14 ^ uVar3) & uVar12 ^ uVar14 & uVar3);
      uVar14 = iVar8 + ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                       (uVar10 >> 0x16) + uVar10 * 0x400) +
                       ((uVar3 ^ uVar12) & uVar10 ^ uVar3 & uVar12);
      iVar4 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
              (uVar17 >> 0x19) + uVar17 * 0x80) + *(uint *)(local_c4 + -0x20) + 0xd807aa98 + uVar15
              + (~uVar17 & uVar13 ^ uVar18 & uVar17);
      uVar19 = uVar12 + iVar4;
      uVar3 = iVar6 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                      (uVar14 >> 0x16) + uVar14 * 0x400) +
                      ((uVar12 ^ uVar10) & uVar14 ^ uVar12 & uVar10);
      iVar6 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
              (uVar19 >> 0x19) + uVar19 * 0x80) + *(uint *)(local_c4 + -0x1c) + 0x12835b01 + uVar13
              + (~uVar19 & uVar18 ^ uVar17 & uVar19);
      uVar15 = uVar10 + iVar6;
      uVar10 = iVar4 + ((uVar3 >> 2) + uVar3 * 0x40000000 ^ (uVar3 >> 0xd) + uVar3 * 0x80000 ^
                       (uVar3 >> 0x16) + uVar3 * 0x400) +
                       ((uVar10 ^ uVar14) & uVar3 ^ uVar10 & uVar14);
      iVar4 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
              (uVar15 >> 0x19) + uVar15 * 0x80) + *(uint *)(local_c4 + -0x18) + 0x243185be + uVar18
              + (~uVar15 & uVar17 ^ uVar19 & uVar15);
      uVar13 = uVar14 + iVar4;
      param_3 = iVar6 + ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                        (uVar10 >> 0x16) + uVar10 * 0x400) +
                        ((uVar14 ^ uVar3) & uVar10 ^ uVar14 & uVar3);
      iVar6 = ((uVar13 >> 6) + uVar13 * 0x4000000 ^ (uVar13 >> 0xb) + uVar13 * 0x200000 ^
              (uVar13 >> 0x19) + uVar13 * 0x80) + *(uint *)(local_c4 + -0x14) + 0x550c7dc3 + uVar17
              + (~uVar13 & uVar19 ^ uVar15 & uVar13);
      uVar14 = iVar4 + ((param_3 >> 2) + param_3 * 0x40000000 ^ (param_3 >> 0xd) + param_3 * 0x80000
                       ^ (param_3 >> 0x16) + param_3 * 0x400) +
                       ((uVar3 ^ uVar10) & param_3 ^ uVar3 & uVar10);
      uVar3 = uVar3 + iVar6;
      iVar4 = ((uVar3 >> 6) + uVar3 * 0x4000000 ^ (uVar3 >> 0xb) + uVar3 * 0x200000 ^
              (uVar3 >> 0x19) + uVar3 * 0x80) + *(uint *)(local_c4 + -0x10) + 0x72be5d74 + uVar19 +
              (~uVar3 & uVar15 ^ uVar13 & uVar3);
      uVar12 = iVar6 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                       (uVar14 >> 0x16) + uVar14 * 0x400) +
                       ((uVar10 ^ param_3) & uVar14 ^ uVar10 & param_3);
      in_t8 = uVar10 + iVar4;
      uVar18 = iVar4 + ((uVar12 >> 2) + uVar12 * 0x40000000 ^ (uVar12 >> 0xd) + uVar12 * 0x80000 ^
                       (uVar12 >> 0x16) + uVar12 * 0x400) +
                       ((param_3 ^ uVar14) & uVar12 ^ param_3 & uVar14);
      iVar4 = ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
              (in_t8 >> 0x19) + in_t8 * 0x80) + *(uint *)(local_c4 + -0xc) + 0x80deb1fe + uVar15 +
              (~in_t8 & uVar13 ^ uVar3 & in_t8);
      param_3 = param_3 + iVar4;
      uVar17 = iVar4 + ((uVar18 >> 2) + uVar18 * 0x40000000 ^ (uVar18 >> 0xd) + uVar18 * 0x80000 ^
                       (uVar18 >> 0x16) + uVar18 * 0x400) +
                       ((uVar14 ^ uVar12) & uVar18 ^ uVar14 & uVar12);
      iVar4 = ((param_3 >> 6) + param_3 * 0x4000000 ^ (param_3 >> 0xb) + param_3 * 0x200000 ^
              (param_3 >> 0x19) + param_3 * 0x80) + *(uint *)(local_c4 + -8) + 0x9bdc06a7 + uVar13 +
              (~param_3 & uVar3 ^ in_t8 & param_3);
      uVar14 = uVar14 + iVar4;
      uVar10 = iVar4 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                       (uVar17 >> 0x16) + uVar17 * 0x400) +
                       ((uVar12 ^ uVar18) & uVar17 ^ uVar12 & uVar18);
      iVar4 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
              (uVar14 >> 0x19) + uVar14 * 0x80) + *(uint *)(local_c4 + -4) + 0xc19bf174 + uVar3 +
              (~uVar14 & in_t8 ^ param_3 & uVar14);
      uVar12 = uVar12 + iVar4;
      unaff_s7 = iVar4 + ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                         (uVar10 >> 0x16) + uVar10 * 0x400) +
                         ((uVar18 ^ uVar17) & uVar10 ^ uVar18 & uVar17);
      while( true ) {
        local_e4 = 0x1d;
        uVar3 = 0;
        puVar24 = local_a0;
        uVar13 = 0x10;
        do {
          uVar15 = uVar13 + 1 & 0xf;
          uVar19 = uVar13 + 0xe & 0xf;
          uVar11 = local_6c[uVar15];
          uVar20 = local_6c[uVar19];
          uVar7 = uVar13 + 2 & 0xf;
          uVar16 = local_6c[uVar13 + 9 & 0xf] + local_6c[uVar3] +
                   ((uVar11 >> 7) + uVar11 * 0x2000000 ^ (uVar11 >> 0x12) + uVar11 * 0x4000 ^
                   uVar11 >> 3) +
                   ((uVar20 >> 0x11) + uVar20 * 0x8000 ^ (uVar20 >> 0x13) + uVar20 * 0x2000 ^
                   uVar20 >> 10);
          local_6c[uVar3] = uVar16;
          uVar11 = uVar13 + 0xf & 0xf;
          uVar23 = local_6c[uVar7];
          uVar20 = local_6c[uVar11];
          uVar21 = uVar13 + 3 & 0xf;
          uVar22 = local_6c[uVar13 + 10 & 0xf] + local_6c[uVar15] +
                   ((uVar23 >> 7) + uVar23 * 0x2000000 ^ (uVar23 >> 0x12) + uVar23 * 0x4000 ^
                   uVar23 >> 3) +
                   ((uVar20 >> 0x11) + uVar20 * 0x8000 ^ (uVar20 >> 0x13) + uVar20 * 0x2000 ^
                   uVar20 >> 10);
          local_6c[uVar15] = uVar22;
          uVar15 = local_6c[uVar3];
          uVar20 = local_6c[uVar21];
          uVar20 = local_6c[uVar13 + 0xb & 0xf] + local_6c[uVar7] +
                   ((uVar15 >> 0x11) + uVar15 * 0x8000 ^ (uVar15 >> 0x13) + uVar15 * 0x2000 ^
                   uVar15 >> 10) +
                   ((uVar20 >> 7) + uVar20 * 0x2000000 ^ (uVar20 >> 0x12) + uVar20 * 0x4000 ^
                   uVar20 >> 3);
          local_6c[uVar7] = uVar20;
          uVar23 = uVar13 + 4 & 0xf;
          uVar7 = local_6c[uVar23];
          uVar15 = local_6c[uVar13 + 0x11 & 0xf];
          iVar6 = ((uVar12 >> 6) + uVar12 * 0x4000000 ^ (uVar12 >> 0xb) + uVar12 * 0x200000 ^
                  (uVar12 >> 0x19) + uVar12 * 0x80) + (~uVar12 & param_3 ^ uVar12 & uVar14) +
                  *(int *)(puVar24 + 0x40) + uVar16 + in_t8;
          iVar4 = *(int *)(puVar24 + 0x44);
          uVar18 = iVar6 + uVar18;
          uVar15 = local_6c[uVar13 + 0xc & 0xf] + local_6c[uVar21] +
                   ((uVar7 >> 7) + uVar7 * 0x2000000 ^ (uVar7 >> 0x12) + uVar7 * 0x4000 ^ uVar7 >> 3
                   ) + ((uVar15 >> 0x11) + uVar15 * 0x8000 ^ (uVar15 >> 0x13) + uVar15 * 0x2000 ^
                       uVar15 >> 10);
          local_6c[uVar21] = uVar15;
          uVar21 = uVar13 + 5 & 0xf;
          uVar16 = local_6c[uVar21];
          uVar26 = local_6c[uVar13 + 0x12 & 0xf];
          iVar4 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
                  (uVar18 >> 0x19) + uVar18 * 0x80) + param_3 + iVar4 + uVar22 +
                  (~uVar18 & uVar14 ^ uVar18 & uVar12);
          uVar22 = iVar4 + uVar17;
          uVar25 = iVar6 + ((unaff_s7 >> 2) + unaff_s7 * 0x40000000 ^
                            (unaff_s7 >> 0xd) + unaff_s7 * 0x80000 ^
                           (unaff_s7 >> 0x16) + unaff_s7 * 0x400) +
                           (unaff_s7 & uVar17 ^ unaff_s7 & uVar10 ^ uVar10 & uVar17);
          iVar6 = ((uVar22 >> 6) + uVar22 * 0x4000000 ^ (uVar22 >> 0xb) + uVar22 * 0x200000 ^
                  (uVar22 >> 0x19) + uVar22 * 0x80) + uVar14 + *(int *)(puVar24 + 0x48) + uVar20 +
                  (~uVar22 & uVar12 ^ uVar18 & uVar22);
          param_3 = iVar4 + ((uVar25 >> 2) + uVar25 * 0x40000000 ^
                             (uVar25 >> 0xd) + uVar25 * 0x80000 ^ (uVar25 >> 0x16) + uVar25 * 0x400)
                            + ((unaff_s7 ^ uVar10) & uVar25 ^ unaff_s7 & uVar10);
          iVar4 = *(int *)(puVar24 + 0x4c);
          uVar7 = uVar13 + 6 & 0xf;
          uVar10 = iVar6 + uVar10;
          uVar20 = local_6c[local_e4 & 0xf] + local_6c[uVar23] +
                   ((uVar16 >> 7) + uVar16 * 0x2000000 ^ (uVar16 >> 0x12) + uVar16 * 0x4000 ^
                   uVar16 >> 3) +
                   ((uVar26 >> 0x11) + uVar26 * 0x8000 ^ (uVar26 >> 0x13) + uVar26 * 0x2000 ^
                   uVar26 >> 10);
          local_6c[uVar23] = uVar20;
          uVar14 = local_6c[uVar7];
          uVar17 = local_6c[uVar13 + 0x13 & 0xf];
          uVar17 = local_6c[uVar21] + local_6c[uVar19] +
                   ((uVar14 >> 7) + uVar14 * 0x2000000 ^ (uVar14 >> 0x12) + uVar14 * 0x4000 ^
                   uVar14 >> 3) +
                   ((uVar17 >> 0x11) + uVar17 * 0x8000 ^ (uVar17 >> 0x13) + uVar17 * 0x2000 ^
                   uVar17 >> 10);
          iVar8 = *(int *)(puVar24 + 0x50);
          iVar4 = ((uVar10 >> 6) + uVar10 * 0x4000000 ^ (uVar10 >> 0xb) + uVar10 * 0x200000 ^
                  (uVar10 >> 0x19) + uVar10 * 0x80) + uVar12 + iVar4 + uVar15 +
                  (~uVar10 & uVar18 ^ uVar22 & uVar10);
          local_6c[uVar21] = uVar17;
          uVar14 = iVar6 + ((param_3 >> 2) + param_3 * 0x40000000 ^
                            (param_3 >> 0xd) + param_3 * 0x80000 ^
                           (param_3 >> 0x16) + param_3 * 0x400) +
                           ((uVar25 ^ unaff_s7) & param_3 ^ uVar25 & unaff_s7);
          uVar15 = uVar13 + 7 & 0xf;
          uVar16 = iVar4 + unaff_s7;
          uVar21 = local_6c[uVar15];
          uVar12 = iVar4 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000
                           ^ (uVar14 >> 0x16) + uVar14 * 0x400) +
                           ((uVar25 ^ param_3) & uVar14 ^ uVar25 & param_3);
          uVar19 = local_6c[uVar13 + 0x14 & 0xf];
          iVar6 = ((uVar16 >> 6) + uVar16 * 0x4000000 ^ (uVar16 >> 0xb) + uVar16 * 0x200000 ^
                  (uVar16 >> 0x19) + uVar16 * 0x80) + uVar20 + iVar8 + uVar18 +
                  (~uVar16 & uVar22 ^ uVar10 & uVar16);
          iVar4 = *(int *)(puVar24 + 0x54);
          in_t8 = uVar25 + iVar6;
          unaff_s6 = uVar13 + 8;
          uVar11 = local_6c[uVar7] + local_6c[uVar11] +
                   ((uVar21 >> 7) + uVar21 * 0x2000000 ^ (uVar21 >> 0x12) + uVar21 * 0x4000 ^
                   uVar21 >> 3) +
                   ((uVar19 >> 0x11) + uVar19 * 0x8000 ^ (uVar19 >> 0x13) + uVar19 * 0x2000 ^
                   uVar19 >> 10);
          local_6c[uVar7] = uVar11;
          uVar18 = iVar6 + ((uVar12 >> 2) + uVar12 * 0x40000000 ^ (uVar12 >> 0xd) + uVar12 * 0x80000
                           ^ (uVar12 >> 0x16) + uVar12 * 0x400) +
                           ((param_3 ^ uVar14) & uVar12 ^ param_3 & uVar14);
          local_e4 = uVar13 + 0x15;
          iVar4 = ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                  (in_t8 >> 0x19) + in_t8 * 0x80) + uVar17 + iVar4 + uVar22 +
                  (~in_t8 & uVar10 ^ uVar16 & in_t8);
          uVar19 = local_6c[unaff_s6 & 0xf];
          param_3 = param_3 + iVar4;
          uVar13 = local_6c[local_e4 & 0xf];
          uVar17 = iVar4 + ((uVar18 >> 2) + uVar18 * 0x40000000 ^ (uVar18 >> 0xd) + uVar18 * 0x80000
                           ^ (uVar18 >> 0x16) + uVar18 * 0x400) +
                           ((uVar14 ^ uVar12) & uVar18 ^ uVar14 & uVar12);
          in_t5 = ((param_3 >> 6) + param_3 * 0x4000000 ^ (param_3 >> 0xb) + param_3 * 0x200000 ^
                  (param_3 >> 0x19) + param_3 * 0x80) + uVar11 + *(int *)(puVar24 + 0x58) + uVar10 +
                  (~param_3 & uVar16 ^ in_t8 & param_3);
          uVar10 = in_t5 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000
                           ^ (uVar17 >> 0x16) + uVar17 * 0x400) +
                           ((uVar12 ^ uVar18) & uVar17 ^ uVar12 & uVar18);
          iVar4 = *(int *)(puVar24 + 0x5c);
          uVar3 = ((uVar19 >> 7) + uVar19 * 0x2000000 ^ (uVar19 >> 0x12) + uVar19 * 0x4000 ^
                  uVar19 >> 3) + local_6c[uVar15] + local_6c[uVar3] +
                  ((uVar13 >> 0x11) + uVar13 * 0x8000 ^ (uVar13 >> 0x13) + uVar13 * 0x2000 ^
                  uVar13 >> 10);
          uVar14 = uVar14 + in_t5;
          puVar24 = puVar24 + 0x20;
          local_6c[uVar15] = uVar3;
          in_t6 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
                  (uVar14 >> 0x19) + uVar14 * 0x80) + uVar3 + iVar4 + uVar16 +
                  (~uVar14 & in_t8 ^ param_3 & uVar14);
          unaff_s7 = in_t6 + ((uVar10 >> 2) + uVar10 * 0x40000000 ^
                              (uVar10 >> 0xd) + uVar10 * 0x80000 ^ (uVar10 >> 0x16) + uVar10 * 0x400
                             ) + ((uVar18 ^ uVar17) & uVar10 ^ uVar18 & uVar17);
          uVar12 = uVar12 + in_t6;
          uVar3 = unaff_s6 & 0xf;
          uVar13 = unaff_s6;
        } while (unaff_s6 != 0x40);
        local_d0 = unaff_s7 + local_d0;
        local_cc = uVar10 + local_cc;
        local_ac = local_ac + -1;
        unaff_s3 = uVar17 + local_c8;
        in_t4 = uVar12 + local_bc;
        unaff_s8 = uVar18 + local_c0;
        local_b8 = uVar14 + local_b8;
        *param_1 = local_d0;
        param_1[1] = local_cc;
        param_3 = param_3 + local_b4;
        param_1[2] = unaff_s3;
        param_1[3] = unaff_s8;
        param_1[4] = in_t4;
        param_1[5] = local_b8;
        puVar5 = (uint *)0xffffffff;
        local_b0 = in_t8 + local_b0;
        param_1[6] = param_3;
        param_1[7] = local_b0;
        local_c4 = local_c4 + 0x40;
        if (local_ac == -1) goto LAB_004cbdd8;
        local_c8 = unaff_s3;
        local_c0 = unaff_s8;
        local_bc = in_t4;
        local_b4 = param_3;
        if (uVar2 == 0) break;
LAB_004cb5e0:
        uVar3 = local_c4 - 0x40U & 3;
        uVar10 = (uint)(&DAT_ffffffc4 + local_c4) & 3;
        uVar12 = local_c4 - 0x39U & 3;
        local_6c[1] = (*(int *)(&DAT_ffffffc4 + local_c4 + -uVar10) << uVar10 * 8 |
                      param_3 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
                      *(uint *)((local_c4 - 0x39U) - uVar12) >> (3 - uVar12) * 8;
        uVar10 = (uint)(&DAT_ffffffcc + local_c4) & 3;
        uVar12 = local_c4 - 0x3dU & 3;
        local_6c[0] = (*(int *)((local_c4 - 0x40U) - uVar3) << uVar3 * 8 |
                      uVar2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar12 + 1) * 8 |
                      *(uint *)((local_c4 - 0x3dU) - uVar12) >> (3 - uVar12) * 8;
        uVar3 = (uint)(&DAT_ffffffc8 + local_c4) & 3;
        uVar12 = local_c4 - 0x30U & 3;
        uVar14 = local_c4 - 0x2cU & 3;
        uVar13 = local_c4 - 0x28U & 3;
        uVar17 = local_c4 - 0x35U & 3;
        local_6c[2] = (*(int *)(&DAT_ffffffc8 + local_c4 + -uVar3) << uVar3 * 8 |
                      in_t5 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar17 + 1) * 8 |
                      *(uint *)((local_c4 - 0x35U) - uVar17) >> (3 - uVar17) * 8;
        uVar3 = local_c4 - 0x2dU & 3;
        local_5c = (*(int *)((local_c4 - 0x30U) - uVar12) << uVar12 * 8 |
                   in_t8 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 0x2dU) - uVar3) >> (3 - uVar3) * 8;
        iVar4 = ((local_bc >> 6) + local_bc * 0x4000000 ^ (local_bc >> 0xb) + local_bc * 0x200000 ^
                (local_bc >> 0x19) + local_bc * 0x80) + local_b0 + 0x428a2f98 +
                (~local_bc & local_b4 ^ local_bc & local_b8) + local_6c[0];
        uVar3 = local_c4 - 0x31U & 3;
        local_6c[3] = (*(int *)(&DAT_ffffffcc + local_c4 + -uVar10) << uVar10 * 8 |
                      unaff_s3 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar3 + 1) * 8 |
                      *(uint *)((local_c4 - 0x31U) - uVar3) >> (3 - uVar3) * 8;
        uVar3 = local_c4 - 0x29U & 3;
        local_58 = (*(int *)((local_c4 - 0x2cU) - uVar14) << uVar14 * 8 |
                   in_t6 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 0x29U) - uVar3) >> (3 - uVar3) * 8;
        uVar3 = local_c4 - 0x24U & 3;
        uVar10 = local_c4 - 0x20U & 3;
        uVar19 = iVar4 + local_c0;
        uVar12 = local_c4 - 0x18U & 3;
        uVar14 = local_c4 - 0x21U & 3;
        local_50 = (*(int *)((local_c4 - 0x24U) - uVar3) << uVar3 * 8 |
                   local_b4 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar14 + 1) * 8 |
                   *(uint *)((local_c4 - 0x21U) - uVar14) >> (3 - uVar14) * 8;
        uVar3 = local_c4 - 0x1dU & 3;
        local_4c = (*(int *)((local_c4 - 0x20U) - uVar10) << uVar10 * 8 |
                   local_6c[0] & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 0x1dU) - uVar3) >> (3 - uVar3) * 8;
        uVar3 = local_c4 - 0x25U & 3;
        local_54 = (*(int *)((local_c4 - 0x28U) - uVar13) << uVar13 * 8 |
                   in_t4 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 0x25U) - uVar3) >> (3 - uVar3) * 8;
        uVar3 = local_c4 - 0x15U & 3;
        local_44 = (*(int *)((local_c4 - 0x18U) - uVar12) << uVar12 * 8 |
                   unaff_s6 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 0x15U) - uVar3) >> (3 - uVar3) * 8;
        uVar3 = local_c4 - 0x14U & 3;
        uVar10 = local_c4 - 0x1cU & 3;
        uVar13 = local_b8 + 0xb5c0fbcf + local_6c[2];
        iVar8 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
                (uVar19 >> 0x19) + uVar19 * 0x80) + local_b4 + 0x71374491 + local_6c[1] +
                (~uVar19 & local_b8 ^ uVar19 & local_bc);
        uVar12 = local_c4 - 0x19U & 3;
        local_48 = (*(int *)((local_c4 - 0x1cU) - uVar10) << uVar10 * 8 |
                   local_6c[1] & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
                   *(uint *)((local_c4 - 0x19U) - uVar12) >> (3 - uVar12) * 8;
        uVar18 = iVar8 + local_c8;
        uVar10 = local_c4 - 0x10U & 3;
        uVar12 = local_c4 - 0x11U & 3;
        local_40 = (*(int *)((local_c4 - 0x14U) - uVar3) << uVar3 * 8 |
                   unaff_s7 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar12 + 1) * 8 |
                   *(uint *)((local_c4 - 0x11U) - uVar12) >> (3 - uVar12) * 8;
        uVar3 = local_c4 - 0xdU & 3;
        local_3c = (*(int *)((local_c4 - 0x10U) - uVar10) << uVar10 * 8 |
                   unaff_s8 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 0xdU) - uVar3) >> (3 - uVar3) * 8;
        uVar17 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
                 (uVar18 >> 0x19) + uVar18 * 0x80) + uVar13;
        uVar3 = local_c4 - 0xcU & 3;
        uVar10 = local_c4 - 8U & 3;
        iVar6 = uVar17 + (~uVar18 & local_bc ^ uVar19 & uVar18);
        uVar12 = local_c4 - 4U & 3;
        uVar14 = local_c4 - 9U & 3;
        local_38 = (*(int *)((local_c4 - 0xcU) - uVar3) << uVar3 * 8 |
                   uVar13 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar14 + 1) * 8 |
                   *(uint *)((local_c4 - 9U) - uVar14) >> (3 - uVar14) * 8;
        uVar15 = iVar6 + local_cc;
        uVar3 = local_c4 - 5U & 3;
        local_34 = (*(int *)((local_c4 - 8U) - uVar10) << uVar10 * 8 |
                   ~uVar18 & local_bc & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 5U) - uVar3) >> (3 - uVar3) * 8;
        uVar3 = local_c4 - 1U & 3;
        local_30 = (*(int *)((local_c4 - 4U) - uVar12) << uVar12 * 8 |
                   uVar17 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)((local_c4 - 1U) - uVar3) >> (3 - uVar3) * 8;
        uVar3 = iVar4 + ((local_d0 >> 2) + local_d0 * 0x40000000 ^
                         (local_d0 >> 0xd) + local_d0 * 0x80000 ^
                        (local_d0 >> 0x16) + local_d0 * 0x400) +
                        (local_d0 & local_c8 ^ local_d0 & local_cc ^ local_cc & local_c8);
        iVar4 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
                (uVar15 >> 0x19) + uVar15 * 0x80) + local_bc + 0xe9b5dba5 + local_6c[3] +
                (~uVar15 & uVar19 ^ uVar18 & uVar15);
        uVar13 = iVar4 + local_d0;
        uVar10 = iVar8 + ((uVar3 >> 2) + uVar3 * 0x40000000 ^ (uVar3 >> 0xd) + uVar3 * 0x80000 ^
                         (uVar3 >> 0x16) + uVar3 * 0x400) +
                         ((local_d0 ^ local_cc) & uVar3 ^ local_d0 & local_cc);
        iVar9 = ((uVar13 >> 6) + uVar13 * 0x4000000 ^ (uVar13 >> 0xb) + uVar13 * 0x200000 ^
                (uVar13 >> 0x19) + uVar13 * 0x80) + local_5c + 0x3956c25b + uVar19 +
                (~uVar13 & uVar18 ^ uVar15 & uVar13);
        uVar19 = uVar3 + iVar9;
        uVar14 = iVar6 + ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                         (uVar10 >> 0x16) + uVar10 * 0x400) +
                         ((uVar3 ^ local_d0) & uVar10 ^ uVar3 & local_d0);
        iVar8 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
                (uVar19 >> 0x19) + uVar19 * 0x80) + local_58 + 0x59f111f1 + uVar18 +
                (~uVar19 & uVar15 ^ uVar13 & uVar19);
        uVar7 = uVar10 + iVar8;
        uVar12 = iVar4 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                         (uVar14 >> 0x16) + uVar14 * 0x400) +
                         ((uVar3 ^ uVar10) & uVar14 ^ uVar3 & uVar10);
        iVar4 = ((uVar7 >> 6) + uVar7 * 0x4000000 ^ (uVar7 >> 0xb) + uVar7 * 0x200000 ^
                (uVar7 >> 0x19) + uVar7 * 0x80) + local_54 + 0x923f82a4 + uVar15 +
                (~uVar7 & uVar13 ^ uVar19 & uVar7);
        uVar17 = uVar14 + iVar4;
        uVar15 = iVar9 + ((uVar12 >> 2) + uVar12 * 0x40000000 ^ (uVar12 >> 0xd) + uVar12 * 0x80000 ^
                         (uVar12 >> 0x16) + uVar12 * 0x400) +
                         ((uVar10 ^ uVar14) & uVar12 ^ uVar10 & uVar14);
        iVar6 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
                (uVar17 >> 0x19) + uVar17 * 0x80) + local_50 + 0xab1c5ed5 + uVar13 +
                (~uVar17 & uVar19 ^ uVar7 & uVar17);
        uVar10 = uVar12 + iVar6;
        uVar3 = iVar8 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                        (uVar15 >> 0x16) + uVar15 * 0x400) +
                        ((uVar14 ^ uVar12) & uVar15 ^ uVar14 & uVar12);
        uVar12 = iVar4 + ((uVar3 >> 2) + uVar3 * 0x40000000 ^ (uVar3 >> 0xd) + uVar3 * 0x80000 ^
                         (uVar3 >> 0x16) + uVar3 * 0x400) +
                         ((uVar12 ^ uVar15) & uVar3 ^ uVar12 & uVar15);
        iVar4 = ((uVar10 >> 6) + uVar10 * 0x4000000 ^ (uVar10 >> 0xb) + uVar10 * 0x200000 ^
                (uVar10 >> 0x19) + uVar10 * 0x80) + local_4c + 0xd807aa98 + uVar19 +
                (~uVar10 & uVar7 ^ uVar17 & uVar10);
        uVar18 = uVar15 + iVar4;
        uVar15 = iVar6 + ((uVar12 >> 2) + uVar12 * 0x40000000 ^ (uVar12 >> 0xd) + uVar12 * 0x80000 ^
                         (uVar12 >> 0x16) + uVar12 * 0x400) +
                         ((uVar15 ^ uVar3) & uVar12 ^ uVar15 & uVar3);
        iVar6 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
                (uVar18 >> 0x19) + uVar18 * 0x80) + local_48 + 0x12835b01 + uVar7 +
                (~uVar18 & uVar17 ^ uVar10 & uVar18);
        uVar19 = uVar3 + iVar6;
        uVar3 = iVar4 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                        (uVar15 >> 0x16) + uVar15 * 0x400) +
                        ((uVar3 ^ uVar12) & uVar15 ^ uVar3 & uVar12);
        iVar8 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
                (uVar19 >> 0x19) + uVar19 * 0x80) + local_44 + 0x243185be + uVar17 +
                (~uVar19 & uVar10 ^ uVar18 & uVar19);
        uVar13 = uVar12 + iVar8;
        param_3 = iVar6 + ((uVar3 >> 2) + uVar3 * 0x40000000 ^ (uVar3 >> 0xd) + uVar3 * 0x80000 ^
                          (uVar3 >> 0x16) + uVar3 * 0x400) +
                          ((uVar12 ^ uVar15) & uVar3 ^ uVar12 & uVar15);
        iVar4 = ((uVar13 >> 6) + uVar13 * 0x4000000 ^ (uVar13 >> 0xb) + uVar13 * 0x200000 ^
                (uVar13 >> 0x19) + uVar13 * 0x80) + local_40 + 0x550c7dc3 + uVar10 +
                (~uVar13 & uVar18 ^ uVar19 & uVar13);
        uVar14 = iVar8 + ((param_3 >> 2) + param_3 * 0x40000000 ^
                          (param_3 >> 0xd) + param_3 * 0x80000 ^ (param_3 >> 0x16) + param_3 * 0x400
                         ) + ((uVar15 ^ uVar3) & param_3 ^ uVar15 & uVar3);
        uVar15 = uVar15 + iVar4;
        uVar12 = iVar4 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                         (uVar14 >> 0x16) + uVar14 * 0x400) +
                         ((uVar3 ^ param_3) & uVar14 ^ uVar3 & param_3);
        iVar4 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
                (uVar15 >> 0x19) + uVar15 * 0x80) + local_3c + 0x72be5d74 + uVar18 +
                (~uVar15 & uVar19 ^ uVar13 & uVar15);
        in_t8 = uVar3 + iVar4;
        uVar18 = iVar4 + ((uVar12 >> 2) + uVar12 * 0x40000000 ^ (uVar12 >> 0xd) + uVar12 * 0x80000 ^
                         (uVar12 >> 0x16) + uVar12 * 0x400) +
                         ((param_3 ^ uVar14) & uVar12 ^ param_3 & uVar14);
        iVar4 = ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                (in_t8 >> 0x19) + in_t8 * 0x80) + local_38 + 0x80deb1fe + uVar19 +
                (~in_t8 & uVar13 ^ uVar15 & in_t8);
        param_3 = param_3 + iVar4;
        uVar17 = iVar4 + ((uVar18 >> 2) + uVar18 * 0x40000000 ^ (uVar18 >> 0xd) + uVar18 * 0x80000 ^
                         (uVar18 >> 0x16) + uVar18 * 0x400) +
                         ((uVar14 ^ uVar12) & uVar18 ^ uVar14 & uVar12);
        iVar4 = ((param_3 >> 6) + param_3 * 0x4000000 ^ (param_3 >> 0xb) + param_3 * 0x200000 ^
                (param_3 >> 0x19) + param_3 * 0x80) + local_34 + 0x9bdc06a7 + uVar13 +
                (~param_3 & uVar15 ^ in_t8 & param_3);
        uVar14 = uVar14 + iVar4;
        uVar10 = iVar4 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                         (uVar17 >> 0x16) + uVar17 * 0x400) +
                         ((uVar12 ^ uVar18) & uVar17 ^ uVar12 & uVar18);
        iVar4 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
                (uVar14 >> 0x19) + uVar14 * 0x80) + local_30 + 0xc19bf174 + uVar15 +
                (~uVar14 & in_t8 ^ param_3 & uVar14);
        uVar12 = uVar12 + iVar4;
        unaff_s7 = iVar4 + ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000
                           ^ (uVar10 >> 0x16) + uVar10 * 0x400) +
                           ((uVar18 ^ uVar17) & uVar10 ^ uVar18 & uVar17);
      }
    } while( true );
  }
LAB_004cbdd8:
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    (*(code *)PTR_memset_006aab00)();
    puVar5[3] = 0xf70e5939;
    puVar5[6] = 0x64f98fa7;
    puVar5[0x1b] = 0x1c;
    puVar5[4] = 0xffc00b31;
    puVar5[5] = 0x68581511;
    puVar5[7] = 0xbefa4fa4;
    *puVar5 = 0xc1059ed8;
    puVar5[1] = 0x367cd507;
    puVar5[2] = 0x3070dd17;
    return 1;
  }
  return *(int *)puVar1;
}

