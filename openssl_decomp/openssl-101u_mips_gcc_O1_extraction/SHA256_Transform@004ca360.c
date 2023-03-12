
void SHA256_Transform(SHA256_CTX *c,uchar *data)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
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
  uint uVar20;
  uint uVar21;
  uint in_t4;
  uint uVar22;
  uint in_t5;
  uint uVar23;
  uint uVar24;
  uint in_t6;
  undefined1 *puVar25;
  uint unaff_s3;
  uint unaff_s6;
  uint unaff_s7;
  uint uVar26;
  uint in_t8;
  uint uVar27;
  uint unaff_s8;
  uint uStack_e4;
  uint uStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  uchar *puStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  int iStack_ac;
  undefined1 *puStack_a0;
  uint auStack_6c [4];
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
  uint uStack_30;
  int iStack_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uVar8 = 1;
  iStack_ac = 0;
  iStack_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_b0 = c->h[7];
  uStack_d0 = c->h[0];
  uVar2 = (uint)data & 3;
  puStack_c4 = data + 0x40;
  uStack_cc = c->h[1];
  uStack_c8 = c->h[2];
  puStack_a0 = K256;
  uStack_c0 = c->h[3];
  uStack_bc = c->h[4];
  uStack_b8 = c->h[5];
  uStack_b4 = c->h[6];
  if (uVar2 != 0) goto LAB_004c8630;
  do {
    iVar3 = ((uStack_bc >> 6) + uStack_bc * 0x4000000 ^ (uStack_bc >> 0xb) + uStack_bc * 0x200000 ^
            (uStack_bc >> 0x19) + uStack_bc * 0x80) +
            uStack_b0 + 0x428a2f98 + *(uint *)(puStack_c4 + -0x40) +
            (~uStack_bc & uStack_b4 ^ uStack_bc & uStack_b8);
    auStack_6c[1] = *(uint *)(puStack_c4 + -0x3c);
    auStack_6c[0] = *(uint *)(puStack_c4 + -0x40);
    auStack_6c[2] = *(uint *)(puStack_c4 + -0x38);
    auStack_6c[3] = *(uint *)(puStack_c4 + -0x34);
    uStack_5c = *(uint *)(puStack_c4 + -0x30);
    uStack_54 = *(uint *)(puStack_c4 + -0x28);
    uVar15 = iVar3 + uStack_c0;
    uStack_4c = *(uint *)(puStack_c4 + -0x20);
    uStack_58 = *(uint *)(puStack_c4 + -0x2c);
    uStack_50 = *(uint *)(puStack_c4 + -0x24);
    uStack_48 = *(uint *)(puStack_c4 + -0x1c);
    uStack_34 = *(uint *)(puStack_c4 + -8);
    uStack_30 = *(uint *)(puStack_c4 + -4);
    uStack_38 = *(uint *)(puStack_c4 + -0xc);
    iVar10 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
             (uVar15 >> 0x19) + uVar15 * 0x80) +
             uStack_b4 + 0x71374491 + *(uint *)(puStack_c4 + -0x3c) +
             (~uVar15 & uStack_b8 ^ uVar15 & uStack_bc);
    uStack_3c = *(uint *)(puStack_c4 + -0x10);
    uStack_40 = *(uint *)(puStack_c4 + -0x14);
    uVar13 = iVar10 + uStack_c8;
    uStack_44 = *(uint *)(puStack_c4 + -0x18);
    iVar9 = ((uVar13 >> 6) + uVar13 * 0x4000000 ^ (uVar13 >> 0xb) + uVar13 * 0x200000 ^
            (uVar13 >> 0x19) + uVar13 * 0x80) +
            uStack_b8 + 0xb5c0fbcf + *(uint *)(puStack_c4 + -0x38) +
            (~uVar13 & uStack_bc ^ uVar15 & uVar13);
    uVar18 = iVar9 + uStack_cc;
    uVar8 = iVar3 + ((uStack_d0 >> 2) + uStack_d0 * 0x40000000 ^
                     (uStack_d0 >> 0xd) + uStack_d0 * 0x80000 ^
                    (uStack_d0 >> 0x16) + uStack_d0 * 0x400) +
                    (uStack_d0 & uStack_c8 ^ uStack_d0 & uStack_cc ^ uStack_cc & uStack_c8);
    iVar6 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
            (uVar18 >> 0x19) + uVar18 * 0x80) +
            uStack_bc + 0xe9b5dba5 + *(uint *)(puStack_c4 + -0x34) +
            (~uVar18 & uVar15 ^ uVar13 & uVar18);
    uVar19 = iVar6 + uStack_d0;
    uVar11 = iVar10 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                      (uVar8 >> 0x16) + uVar8 * 0x400) +
                      ((uStack_d0 ^ uStack_cc) & uVar8 ^ uStack_d0 & uStack_cc);
    iVar10 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
             (uVar19 >> 0x19) + uVar19 * 0x80) + *(uint *)(puStack_c4 + -0x30) + 0x3956c25b + uVar15
             + (~uVar19 & uVar13 ^ uVar18 & uVar19);
    uVar16 = uVar8 + iVar10;
    uVar23 = iVar9 + ((uVar11 >> 2) + uVar11 * 0x40000000 ^ (uVar11 >> 0xd) + uVar11 * 0x80000 ^
                     (uVar11 >> 0x16) + uVar11 * 0x400) +
                     ((uVar8 ^ uStack_d0) & uVar11 ^ uVar8 & uStack_d0);
    iVar3 = ((uVar16 >> 6) + uVar16 * 0x4000000 ^ (uVar16 >> 0xb) + uVar16 * 0x200000 ^
            (uVar16 >> 0x19) + uVar16 * 0x80) + *(uint *)(puStack_c4 + -0x2c) + 0x59f111f1 + uVar13
            + (~uVar16 & uVar18 ^ uVar19 & uVar16);
    uVar14 = uVar11 + iVar3;
    uVar8 = iVar6 + ((uVar23 >> 2) + uVar23 * 0x40000000 ^ (uVar23 >> 0xd) + uVar23 * 0x80000 ^
                    (uVar23 >> 0x16) + uVar23 * 0x400) +
                    ((uVar8 ^ uVar11) & uVar23 ^ uVar8 & uVar11);
    iVar9 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
            (uVar14 >> 0x19) + uVar14 * 0x80) + *(uint *)(puStack_c4 + -0x28) + 0x923f82a4 + uVar18
            + (~uVar14 & uVar19 ^ uVar16 & uVar14);
    uVar18 = uVar23 + iVar9;
    uVar11 = iVar10 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                      (uVar8 >> 0x16) + uVar8 * 0x400) +
                      ((uVar11 ^ uVar23) & uVar8 ^ uVar11 & uVar23);
    iVar6 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
            (uVar18 >> 0x19) + uVar18 * 0x80) + *(uint *)(puStack_c4 + -0x24) + 0xab1c5ed5 + uVar19
            + (~uVar18 & uVar16 ^ uVar14 & uVar18);
    uVar15 = uVar8 + iVar6;
    uVar13 = iVar3 + ((uVar11 >> 2) + uVar11 * 0x40000000 ^ (uVar11 >> 0xd) + uVar11 * 0x80000 ^
                     (uVar11 >> 0x16) + uVar11 * 0x400) +
                     ((uVar23 ^ uVar8) & uVar11 ^ uVar23 & uVar8);
    uVar8 = iVar9 + ((uVar13 >> 2) + uVar13 * 0x40000000 ^ (uVar13 >> 0xd) + uVar13 * 0x80000 ^
                    (uVar13 >> 0x16) + uVar13 * 0x400) +
                    ((uVar8 ^ uVar11) & uVar13 ^ uVar8 & uVar11);
    iVar3 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
            (uVar15 >> 0x19) + uVar15 * 0x80) + *(uint *)(puStack_c4 + -0x20) + 0xd807aa98 + uVar16
            + (~uVar15 & uVar14 ^ uVar18 & uVar15);
    uVar23 = uVar11 + iVar3;
    uVar11 = iVar6 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                     (uVar8 >> 0x16) + uVar8 * 0x400) +
                     ((uVar11 ^ uVar13) & uVar8 ^ uVar11 & uVar13);
    iVar6 = ((uVar23 >> 6) + uVar23 * 0x4000000 ^ (uVar23 >> 0xb) + uVar23 * 0x200000 ^
            (uVar23 >> 0x19) + uVar23 * 0x80) + *(uint *)(puStack_c4 + -0x1c) + 0x12835b01 + uVar14
            + (~uVar23 & uVar18 ^ uVar15 & uVar23);
    uVar19 = uVar13 + iVar6;
    uVar13 = iVar3 + ((uVar11 >> 2) + uVar11 * 0x40000000 ^ (uVar11 >> 0xd) + uVar11 * 0x80000 ^
                     (uVar11 >> 0x16) + uVar11 * 0x400) +
                     ((uVar13 ^ uVar8) & uVar11 ^ uVar13 & uVar8);
    iVar3 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
            (uVar19 >> 0x19) + uVar19 * 0x80) + *(uint *)(puStack_c4 + -0x18) + 0x243185be + uVar18
            + (~uVar19 & uVar15 ^ uVar23 & uVar19);
    uVar16 = uVar8 + iVar3;
    uVar8 = iVar6 + ((uVar13 >> 2) + uVar13 * 0x40000000 ^ (uVar13 >> 0xd) + uVar13 * 0x80000 ^
                    (uVar13 >> 0x16) + uVar13 * 0x400) +
                    ((uVar8 ^ uVar11) & uVar13 ^ uVar8 & uVar11);
    iVar6 = ((uVar16 >> 6) + uVar16 * 0x4000000 ^ (uVar16 >> 0xb) + uVar16 * 0x200000 ^
            (uVar16 >> 0x19) + uVar16 * 0x80) + *(uint *)(puStack_c4 + -0x14) + 0x550c7dc3 + uVar15
            + (~uVar16 & uVar23 ^ uVar19 & uVar16);
    uVar14 = iVar3 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                     (uVar8 >> 0x16) + uVar8 * 0x400) +
                     ((uVar11 ^ uVar13) & uVar8 ^ uVar11 & uVar13);
    uVar11 = uVar11 + iVar6;
    iVar3 = ((uVar11 >> 6) + uVar11 * 0x4000000 ^ (uVar11 >> 0xb) + uVar11 * 0x200000 ^
            (uVar11 >> 0x19) + uVar11 * 0x80) + *(uint *)(puStack_c4 + -0x10) + 0x72be5d74 + uVar23
            + (~uVar11 & uVar19 ^ uVar16 & uVar11);
    uVar15 = iVar6 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                     (uVar14 >> 0x16) + uVar14 * 0x400) +
                     ((uVar13 ^ uVar8) & uVar14 ^ uVar13 & uVar8);
    in_t8 = uVar13 + iVar3;
    uVar23 = iVar3 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                     (uVar15 >> 0x16) + uVar15 * 0x400) +
                     ((uVar8 ^ uVar14) & uVar15 ^ uVar8 & uVar14);
    iVar3 = ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
            (in_t8 >> 0x19) + in_t8 * 0x80) + *(uint *)(puStack_c4 + -0xc) + 0x80deb1fe + uVar19 +
            (~in_t8 & uVar16 ^ uVar11 & in_t8);
    uVar8 = uVar8 + iVar3;
    uVar18 = iVar3 + ((uVar23 >> 2) + uVar23 * 0x40000000 ^ (uVar23 >> 0xd) + uVar23 * 0x80000 ^
                     (uVar23 >> 0x16) + uVar23 * 0x400) +
                     ((uVar14 ^ uVar15) & uVar23 ^ uVar14 & uVar15);
    iVar3 = ((uVar8 >> 6) + uVar8 * 0x4000000 ^ (uVar8 >> 0xb) + uVar8 * 0x200000 ^
            (uVar8 >> 0x19) + uVar8 * 0x80) + *(uint *)(puStack_c4 + -8) + 0x9bdc06a7 + uVar16 +
            (~uVar8 & uVar11 ^ in_t8 & uVar8);
    uVar14 = uVar14 + iVar3;
    uVar13 = iVar3 + ((uVar18 >> 2) + uVar18 * 0x40000000 ^ (uVar18 >> 0xd) + uVar18 * 0x80000 ^
                     (uVar18 >> 0x16) + uVar18 * 0x400) +
                     ((uVar15 ^ uVar23) & uVar18 ^ uVar15 & uVar23);
    iVar3 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
            (uVar14 >> 0x19) + uVar14 * 0x80) + *(uint *)(puStack_c4 + -4) + 0xc19bf174 + uVar11 +
            (~uVar14 & in_t8 ^ uVar8 & uVar14);
    uVar15 = uVar15 + iVar3;
    unaff_s7 = iVar3 + ((uVar13 >> 2) + uVar13 * 0x40000000 ^ (uVar13 >> 0xd) + uVar13 * 0x80000 ^
                       (uVar13 >> 0x16) + uVar13 * 0x400) +
                       ((uVar23 ^ uVar18) & uVar13 ^ uVar23 & uVar18);
    while( true ) {
      uStack_e4 = 0x1d;
      uVar11 = 0;
      puVar25 = puStack_a0;
      uVar16 = 0x10;
      do {
        uVar19 = uVar16 + 1 & 0xf;
        uVar5 = uVar16 + 0xe & 0xf;
        uVar12 = auStack_6c[uVar19];
        uVar20 = auStack_6c[uVar5];
        uVar7 = uVar16 + 2 & 0xf;
        uVar17 = auStack_6c[uVar16 + 9 & 0xf] + auStack_6c[uVar11] +
                 ((uVar12 >> 7) + uVar12 * 0x2000000 ^ (uVar12 >> 0x12) + uVar12 * 0x4000 ^
                 uVar12 >> 3) +
                 ((uVar20 >> 0x11) + uVar20 * 0x8000 ^ (uVar20 >> 0x13) + uVar20 * 0x2000 ^
                 uVar20 >> 10);
        auStack_6c[uVar11] = uVar17;
        uVar12 = uVar16 + 0xf & 0xf;
        uVar24 = auStack_6c[uVar7];
        uVar20 = auStack_6c[uVar12];
        uVar21 = uVar16 + 3 & 0xf;
        uVar22 = auStack_6c[uVar16 + 10 & 0xf] + auStack_6c[uVar19] +
                 ((uVar24 >> 7) + uVar24 * 0x2000000 ^ (uVar24 >> 0x12) + uVar24 * 0x4000 ^
                 uVar24 >> 3) +
                 ((uVar20 >> 0x11) + uVar20 * 0x8000 ^ (uVar20 >> 0x13) + uVar20 * 0x2000 ^
                 uVar20 >> 10);
        auStack_6c[uVar19] = uVar22;
        uVar19 = auStack_6c[uVar11];
        uVar20 = auStack_6c[uVar21];
        uVar20 = auStack_6c[uVar16 + 0xb & 0xf] + auStack_6c[uVar7] +
                 ((uVar19 >> 0x11) + uVar19 * 0x8000 ^ (uVar19 >> 0x13) + uVar19 * 0x2000 ^
                 uVar19 >> 10) +
                 ((uVar20 >> 7) + uVar20 * 0x2000000 ^ (uVar20 >> 0x12) + uVar20 * 0x4000 ^
                 uVar20 >> 3);
        auStack_6c[uVar7] = uVar20;
        uVar24 = uVar16 + 4 & 0xf;
        uVar7 = auStack_6c[uVar24];
        uVar19 = auStack_6c[uVar16 + 0x11 & 0xf];
        iVar6 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
                (uVar15 >> 0x19) + uVar15 * 0x80) + (~uVar15 & uVar8 ^ uVar15 & uVar14) +
                *(int *)(puVar25 + 0x40) + uVar17 + in_t8;
        iVar3 = *(int *)(puVar25 + 0x44);
        uVar23 = iVar6 + uVar23;
        uVar19 = auStack_6c[uVar16 + 0xc & 0xf] + auStack_6c[uVar21] +
                 ((uVar7 >> 7) + uVar7 * 0x2000000 ^ (uVar7 >> 0x12) + uVar7 * 0x4000 ^ uVar7 >> 3)
                 + ((uVar19 >> 0x11) + uVar19 * 0x8000 ^ (uVar19 >> 0x13) + uVar19 * 0x2000 ^
                   uVar19 >> 10);
        auStack_6c[uVar21] = uVar19;
        uVar21 = uVar16 + 5 & 0xf;
        uVar17 = auStack_6c[uVar21];
        uVar27 = auStack_6c[uVar16 + 0x12 & 0xf];
        iVar3 = ((uVar23 >> 6) + uVar23 * 0x4000000 ^ (uVar23 >> 0xb) + uVar23 * 0x200000 ^
                (uVar23 >> 0x19) + uVar23 * 0x80) + uVar8 + iVar3 + uVar22 +
                (~uVar23 & uVar14 ^ uVar23 & uVar15);
        uVar22 = iVar3 + uVar18;
        uVar26 = iVar6 + ((unaff_s7 >> 2) + unaff_s7 * 0x40000000 ^
                          (unaff_s7 >> 0xd) + unaff_s7 * 0x80000 ^
                         (unaff_s7 >> 0x16) + unaff_s7 * 0x400) +
                         (unaff_s7 & uVar18 ^ unaff_s7 & uVar13 ^ uVar13 & uVar18);
        iVar6 = ((uVar22 >> 6) + uVar22 * 0x4000000 ^ (uVar22 >> 0xb) + uVar22 * 0x200000 ^
                (uVar22 >> 0x19) + uVar22 * 0x80) + uVar14 + *(int *)(puVar25 + 0x48) + uVar20 +
                (~uVar22 & uVar15 ^ uVar23 & uVar22);
        uVar8 = iVar3 + ((uVar26 >> 2) + uVar26 * 0x40000000 ^ (uVar26 >> 0xd) + uVar26 * 0x80000 ^
                        (uVar26 >> 0x16) + uVar26 * 0x400) +
                        ((unaff_s7 ^ uVar13) & uVar26 ^ unaff_s7 & uVar13);
        iVar3 = *(int *)(puVar25 + 0x4c);
        uVar7 = uVar16 + 6 & 0xf;
        uVar13 = iVar6 + uVar13;
        uVar20 = auStack_6c[uStack_e4 & 0xf] + auStack_6c[uVar24] +
                 ((uVar17 >> 7) + uVar17 * 0x2000000 ^ (uVar17 >> 0x12) + uVar17 * 0x4000 ^
                 uVar17 >> 3) +
                 ((uVar27 >> 0x11) + uVar27 * 0x8000 ^ (uVar27 >> 0x13) + uVar27 * 0x2000 ^
                 uVar27 >> 10);
        auStack_6c[uVar24] = uVar20;
        uVar14 = auStack_6c[uVar7];
        uVar18 = auStack_6c[uVar16 + 0x13 & 0xf];
        uVar18 = auStack_6c[uVar21] + auStack_6c[uVar5] +
                 ((uVar14 >> 7) + uVar14 * 0x2000000 ^ (uVar14 >> 0x12) + uVar14 * 0x4000 ^
                 uVar14 >> 3) +
                 ((uVar18 >> 0x11) + uVar18 * 0x8000 ^ (uVar18 >> 0x13) + uVar18 * 0x2000 ^
                 uVar18 >> 10);
        iVar9 = *(int *)(puVar25 + 0x50);
        iVar3 = ((uVar13 >> 6) + uVar13 * 0x4000000 ^ (uVar13 >> 0xb) + uVar13 * 0x200000 ^
                (uVar13 >> 0x19) + uVar13 * 0x80) + uVar15 + iVar3 + uVar19 +
                (~uVar13 & uVar23 ^ uVar22 & uVar13);
        auStack_6c[uVar21] = uVar18;
        uVar14 = iVar6 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                         (uVar8 >> 0x16) + uVar8 * 0x400) +
                         ((uVar26 ^ unaff_s7) & uVar8 ^ uVar26 & unaff_s7);
        uVar19 = uVar16 + 7 & 0xf;
        uVar17 = iVar3 + unaff_s7;
        uVar21 = auStack_6c[uVar19];
        uVar15 = iVar3 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                         (uVar14 >> 0x16) + uVar14 * 0x400) +
                         ((uVar26 ^ uVar8) & uVar14 ^ uVar26 & uVar8);
        uVar5 = auStack_6c[uVar16 + 0x14 & 0xf];
        iVar6 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
                (uVar17 >> 0x19) + uVar17 * 0x80) + uVar20 + iVar9 + uVar23 +
                (~uVar17 & uVar22 ^ uVar13 & uVar17);
        iVar3 = *(int *)(puVar25 + 0x54);
        in_t8 = uVar26 + iVar6;
        unaff_s6 = uVar16 + 8;
        uVar12 = auStack_6c[uVar7] + auStack_6c[uVar12] +
                 ((uVar21 >> 7) + uVar21 * 0x2000000 ^ (uVar21 >> 0x12) + uVar21 * 0x4000 ^
                 uVar21 >> 3) +
                 ((uVar5 >> 0x11) + uVar5 * 0x8000 ^ (uVar5 >> 0x13) + uVar5 * 0x2000 ^ uVar5 >> 10)
        ;
        auStack_6c[uVar7] = uVar12;
        uVar23 = iVar6 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                         (uVar15 >> 0x16) + uVar15 * 0x400) +
                         ((uVar8 ^ uVar14) & uVar15 ^ uVar8 & uVar14);
        uStack_e4 = uVar16 + 0x15;
        iVar3 = ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                (in_t8 >> 0x19) + in_t8 * 0x80) + uVar18 + iVar3 + uVar22 +
                (~in_t8 & uVar13 ^ uVar17 & in_t8);
        uVar5 = auStack_6c[unaff_s6 & 0xf];
        uVar8 = uVar8 + iVar3;
        uVar16 = auStack_6c[uStack_e4 & 0xf];
        uVar18 = iVar3 + ((uVar23 >> 2) + uVar23 * 0x40000000 ^ (uVar23 >> 0xd) + uVar23 * 0x80000 ^
                         (uVar23 >> 0x16) + uVar23 * 0x400) +
                         ((uVar14 ^ uVar15) & uVar23 ^ uVar14 & uVar15);
        in_t5 = ((uVar8 >> 6) + uVar8 * 0x4000000 ^ (uVar8 >> 0xb) + uVar8 * 0x200000 ^
                (uVar8 >> 0x19) + uVar8 * 0x80) + uVar12 + *(int *)(puVar25 + 0x58) + uVar13 +
                (~uVar8 & uVar17 ^ in_t8 & uVar8);
        uVar13 = in_t5 + ((uVar18 >> 2) + uVar18 * 0x40000000 ^ (uVar18 >> 0xd) + uVar18 * 0x80000 ^
                         (uVar18 >> 0x16) + uVar18 * 0x400) +
                         ((uVar15 ^ uVar23) & uVar18 ^ uVar15 & uVar23);
        iVar3 = *(int *)(puVar25 + 0x5c);
        uVar11 = ((uVar5 >> 7) + uVar5 * 0x2000000 ^ (uVar5 >> 0x12) + uVar5 * 0x4000 ^ uVar5 >> 3)
                 + auStack_6c[uVar19] + auStack_6c[uVar11] +
                 ((uVar16 >> 0x11) + uVar16 * 0x8000 ^ (uVar16 >> 0x13) + uVar16 * 0x2000 ^
                 uVar16 >> 10);
        uVar14 = uVar14 + in_t5;
        puVar25 = puVar25 + 0x20;
        auStack_6c[uVar19] = uVar11;
        in_t6 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
                (uVar14 >> 0x19) + uVar14 * 0x80) + uVar11 + iVar3 + uVar17 +
                (~uVar14 & in_t8 ^ uVar8 & uVar14);
        unaff_s7 = in_t6 + ((uVar13 >> 2) + uVar13 * 0x40000000 ^ (uVar13 >> 0xd) + uVar13 * 0x80000
                           ^ (uVar13 >> 0x16) + uVar13 * 0x400) +
                           ((uVar23 ^ uVar18) & uVar13 ^ uVar23 & uVar18);
        uVar15 = uVar15 + in_t6;
        uVar11 = unaff_s6 & 0xf;
        uVar16 = unaff_s6;
      } while (unaff_s6 != 0x40);
      uStack_d0 = unaff_s7 + uStack_d0;
      uStack_cc = uVar13 + uStack_cc;
      iStack_ac = iStack_ac + -1;
      unaff_s3 = uVar18 + uStack_c8;
      in_t4 = uVar15 + uStack_bc;
      unaff_s8 = uVar23 + uStack_c0;
      uStack_b8 = uVar14 + uStack_b8;
      c->h[0] = uStack_d0;
      c->h[1] = uStack_cc;
      uVar8 = uVar8 + uStack_b4;
      c->h[2] = unaff_s3;
      c->h[3] = unaff_s8;
      c->h[4] = in_t4;
      c->h[5] = uStack_b8;
      uStack_b0 = in_t8 + uStack_b0;
      c->h[6] = uVar8;
      c->h[7] = uStack_b0;
      puStack_c4 = puStack_c4 + 0x40;
      if (iStack_ac == -1) {
        puVar4 = (undefined4 *)0xffffffff;
        if (iStack_2c != *(int *)puVar1) {
          (*(code *)PTR___stack_chk_fail_006a9ab0)();
          (*(code *)PTR_memset_006a99f4)();
          puVar4[3] = 0xf70e5939;
          puVar4[6] = 0x64f98fa7;
          puVar4[0x1b] = 0x1c;
          puVar4[4] = 0xffc00b31;
          puVar4[5] = 0x68581511;
          puVar4[7] = 0xbefa4fa4;
          *puVar4 = 0xc1059ed8;
          puVar4[1] = 0x367cd507;
          puVar4[2] = 0x3070dd17;
          return;
        }
        return;
      }
      uStack_c8 = unaff_s3;
      uStack_c0 = unaff_s8;
      uStack_bc = in_t4;
      uStack_b4 = uVar8;
      if (uVar2 == 0) break;
LAB_004c8630:
      uVar11 = (uint)(puStack_c4 + -0x40) & 3;
      uVar13 = (uint)(puStack_c4 + -0x3c) & 3;
      uVar15 = (uint)(puStack_c4 + -0x39) & 3;
      auStack_6c[1] =
           (*(int *)(puStack_c4 + -0x3c + -uVar13) << uVar13 * 8 |
           uVar8 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar15 + 1) * 8 |
           *(uint *)(puStack_c4 + -0x39 + -uVar15) >> (3 - uVar15) * 8;
      uVar8 = (uint)(puStack_c4 + -0x34) & 3;
      uVar13 = (uint)(puStack_c4 + -0x3d) & 3;
      auStack_6c[0] =
           (*(int *)(puStack_c4 + -0x40 + -uVar11) << uVar11 * 8 |
           uVar2 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar13 + 1) * 8 |
           *(uint *)(puStack_c4 + -0x3d + -uVar13) >> (3 - uVar13) * 8;
      uVar11 = (uint)(puStack_c4 + -0x38) & 3;
      uVar13 = (uint)(puStack_c4 + -0x30) & 3;
      uVar15 = (uint)(puStack_c4 + -0x2c) & 3;
      uVar14 = (uint)(puStack_c4 + -0x28) & 3;
      uVar16 = (uint)(puStack_c4 + -0x35) & 3;
      auStack_6c[2] =
           (*(int *)(puStack_c4 + -0x38 + -uVar11) << uVar11 * 8 |
           in_t5 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar16 + 1) * 8 |
           *(uint *)(puStack_c4 + -0x35 + -uVar16) >> (3 - uVar16) * 8;
      uVar11 = (uint)(puStack_c4 + -0x2d) & 3;
      uStack_5c = (*(int *)(puStack_c4 + -0x30 + -uVar13) << uVar13 * 8 |
                  in_t8 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar11 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x2d + -uVar11) >> (3 - uVar11) * 8;
      iVar3 = ((uStack_bc >> 6) + uStack_bc * 0x4000000 ^ (uStack_bc >> 0xb) + uStack_bc * 0x200000
              ^ (uStack_bc >> 0x19) + uStack_bc * 0x80) + uStack_b0 + 0x428a2f98 +
              (~uStack_bc & uStack_b4 ^ uStack_bc & uStack_b8) + auStack_6c[0];
      uVar11 = (uint)(puStack_c4 + -0x31) & 3;
      auStack_6c[3] =
           (*(int *)(puStack_c4 + -0x34 + -uVar8) << uVar8 * 8 |
           unaff_s3 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar11 + 1) * 8 |
           *(uint *)(puStack_c4 + -0x31 + -uVar11) >> (3 - uVar11) * 8;
      uVar8 = (uint)(puStack_c4 + -0x29) & 3;
      uStack_58 = (*(int *)(puStack_c4 + -0x2c + -uVar15) << uVar15 * 8 |
                  in_t6 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x29 + -uVar8) >> (3 - uVar8) * 8;
      uVar8 = (uint)(puStack_c4 + -0x24) & 3;
      uVar11 = (uint)(puStack_c4 + -0x20) & 3;
      uVar23 = iVar3 + uStack_c0;
      uVar13 = (uint)(puStack_c4 + -0x18) & 3;
      uVar15 = (uint)(puStack_c4 + -0x21) & 3;
      uStack_50 = (*(int *)(puStack_c4 + -0x24 + -uVar8) << uVar8 * 8 |
                  uStack_b4 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar15 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x21 + -uVar15) >> (3 - uVar15) * 8;
      uVar8 = (uint)(puStack_c4 + -0x1d) & 3;
      uStack_4c = (*(int *)(puStack_c4 + -0x20 + -uVar11) << uVar11 * 8 |
                  auStack_6c[0] & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x1d + -uVar8) >> (3 - uVar8) * 8;
      uVar8 = (uint)(puStack_c4 + -0x25) & 3;
      uStack_54 = (*(int *)(puStack_c4 + -0x28 + -uVar14) << uVar14 * 8 |
                  in_t4 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x25 + -uVar8) >> (3 - uVar8) * 8;
      uVar8 = (uint)(puStack_c4 + -0x15) & 3;
      uStack_44 = (*(int *)(puStack_c4 + -0x18 + -uVar13) << uVar13 * 8 |
                  unaff_s6 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x15 + -uVar8) >> (3 - uVar8) * 8;
      uVar8 = (uint)(puStack_c4 + -0x14) & 3;
      uVar11 = (uint)(puStack_c4 + -0x1c) & 3;
      uVar14 = uStack_b8 + 0xb5c0fbcf + auStack_6c[2];
      iVar9 = ((uVar23 >> 6) + uVar23 * 0x4000000 ^ (uVar23 >> 0xb) + uVar23 * 0x200000 ^
              (uVar23 >> 0x19) + uVar23 * 0x80) + uStack_b4 + 0x71374491 + auStack_6c[1] +
              (~uVar23 & uStack_b8 ^ uVar23 & uStack_bc);
      uVar13 = (uint)(puStack_c4 + -0x19) & 3;
      uStack_48 = (*(int *)(puStack_c4 + -0x1c + -uVar11) << uVar11 * 8 |
                  auStack_6c[1] & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar13 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x19 + -uVar13) >> (3 - uVar13) * 8;
      uVar19 = iVar9 + uStack_c8;
      uVar11 = (uint)(puStack_c4 + -0x10) & 3;
      uVar13 = (uint)(puStack_c4 + -0x11) & 3;
      uStack_40 = (*(int *)(puStack_c4 + -0x14 + -uVar8) << uVar8 * 8 |
                  unaff_s7 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar13 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0x11 + -uVar13) >> (3 - uVar13) * 8;
      uVar8 = (uint)(puStack_c4 + -0xd) & 3;
      uStack_3c = (*(int *)(puStack_c4 + -0x10 + -uVar11) << uVar11 * 8 |
                  unaff_s8 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(puStack_c4 + -0xd + -uVar8) >> (3 - uVar8) * 8;
      uVar16 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
               (uVar19 >> 0x19) + uVar19 * 0x80) + uVar14;
      uVar8 = (uint)(puStack_c4 + -0xc) & 3;
      uVar11 = (uint)(puStack_c4 + -8) & 3;
      iVar6 = uVar16 + (~uVar19 & uStack_bc ^ uVar23 & uVar19);
      uVar13 = (uint)(puStack_c4 + -4) & 3;
      uVar15 = (uint)(puStack_c4 + -9) & 3;
      uStack_38 = (*(int *)(puStack_c4 + -0xc + -uVar8) << uVar8 * 8 |
                  uVar14 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar15 + 1) * 8 |
                  *(uint *)(puStack_c4 + -9 + -uVar15) >> (3 - uVar15) * 8;
      uVar18 = iVar6 + uStack_cc;
      uVar8 = (uint)(puStack_c4 + -5) & 3;
      uStack_34 = (*(int *)(puStack_c4 + -8 + -uVar11) << uVar11 * 8 |
                  ~uVar19 & uStack_bc & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(puStack_c4 + -5 + -uVar8) >> (3 - uVar8) * 8;
      uVar8 = (uint)(puStack_c4 + -1) & 3;
      uStack_30 = (*(int *)(puStack_c4 + -4 + -uVar13) << uVar13 * 8 |
                  uVar16 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(puStack_c4 + -1 + -uVar8) >> (3 - uVar8) * 8;
      uVar8 = iVar3 + ((uStack_d0 >> 2) + uStack_d0 * 0x40000000 ^
                       (uStack_d0 >> 0xd) + uStack_d0 * 0x80000 ^
                      (uStack_d0 >> 0x16) + uStack_d0 * 0x400) +
                      (uStack_d0 & uStack_c8 ^ uStack_d0 & uStack_cc ^ uStack_cc & uStack_c8);
      iVar3 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
              (uVar18 >> 0x19) + uVar18 * 0x80) + uStack_bc + 0xe9b5dba5 + auStack_6c[3] +
              (~uVar18 & uVar23 ^ uVar19 & uVar18);
      uVar14 = iVar3 + uStack_d0;
      uVar11 = iVar9 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                       (uVar8 >> 0x16) + uVar8 * 0x400) +
                       ((uStack_d0 ^ uStack_cc) & uVar8 ^ uStack_d0 & uStack_cc);
      iVar10 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
               (uVar14 >> 0x19) + uVar14 * 0x80) + uStack_5c + 0x3956c25b + uVar23 +
               (~uVar14 & uVar19 ^ uVar18 & uVar14);
      uVar23 = uVar8 + iVar10;
      uVar15 = iVar6 + ((uVar11 >> 2) + uVar11 * 0x40000000 ^ (uVar11 >> 0xd) + uVar11 * 0x80000 ^
                       (uVar11 >> 0x16) + uVar11 * 0x400) +
                       ((uVar8 ^ uStack_d0) & uVar11 ^ uVar8 & uStack_d0);
      iVar9 = ((uVar23 >> 6) + uVar23 * 0x4000000 ^ (uVar23 >> 0xb) + uVar23 * 0x200000 ^
              (uVar23 >> 0x19) + uVar23 * 0x80) + uStack_58 + 0x59f111f1 + uVar19 +
              (~uVar23 & uVar18 ^ uVar14 & uVar23);
      uVar5 = uVar11 + iVar9;
      uVar13 = iVar3 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                       (uVar15 >> 0x16) + uVar15 * 0x400) +
                       ((uVar8 ^ uVar11) & uVar15 ^ uVar8 & uVar11);
      iVar3 = ((uVar5 >> 6) + uVar5 * 0x4000000 ^ (uVar5 >> 0xb) + uVar5 * 0x200000 ^
              (uVar5 >> 0x19) + uVar5 * 0x80) + uStack_54 + 0x923f82a4 + uVar18 +
              (~uVar5 & uVar14 ^ uVar23 & uVar5);
      uVar16 = uVar15 + iVar3;
      uVar18 = iVar10 + ((uVar13 >> 2) + uVar13 * 0x40000000 ^ (uVar13 >> 0xd) + uVar13 * 0x80000 ^
                        (uVar13 >> 0x16) + uVar13 * 0x400) +
                        ((uVar11 ^ uVar15) & uVar13 ^ uVar11 & uVar15);
      iVar6 = ((uVar16 >> 6) + uVar16 * 0x4000000 ^ (uVar16 >> 0xb) + uVar16 * 0x200000 ^
              (uVar16 >> 0x19) + uVar16 * 0x80) + uStack_50 + 0xab1c5ed5 + uVar14 +
              (~uVar16 & uVar23 ^ uVar5 & uVar16);
      uVar11 = uVar13 + iVar6;
      uVar8 = iVar9 + ((uVar18 >> 2) + uVar18 * 0x40000000 ^ (uVar18 >> 0xd) + uVar18 * 0x80000 ^
                      (uVar18 >> 0x16) + uVar18 * 0x400) +
                      ((uVar15 ^ uVar13) & uVar18 ^ uVar15 & uVar13);
      uVar15 = iVar3 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                       (uVar8 >> 0x16) + uVar8 * 0x400) +
                       ((uVar13 ^ uVar18) & uVar8 ^ uVar13 & uVar18);
      iVar3 = ((uVar11 >> 6) + uVar11 * 0x4000000 ^ (uVar11 >> 0xb) + uVar11 * 0x200000 ^
              (uVar11 >> 0x19) + uVar11 * 0x80) + uStack_4c + 0xd807aa98 + uVar23 +
              (~uVar11 & uVar5 ^ uVar16 & uVar11);
      uVar23 = uVar18 + iVar3;
      uVar19 = iVar6 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                       (uVar15 >> 0x16) + uVar15 * 0x400) +
                       ((uVar18 ^ uVar8) & uVar15 ^ uVar18 & uVar8);
      iVar6 = ((uVar23 >> 6) + uVar23 * 0x4000000 ^ (uVar23 >> 0xb) + uVar23 * 0x200000 ^
              (uVar23 >> 0x19) + uVar23 * 0x80) + uStack_48 + 0x12835b01 + uVar5 +
              (~uVar23 & uVar16 ^ uVar11 & uVar23);
      uVar18 = uVar8 + iVar6;
      uVar13 = iVar3 + ((uVar19 >> 2) + uVar19 * 0x40000000 ^ (uVar19 >> 0xd) + uVar19 * 0x80000 ^
                       (uVar19 >> 0x16) + uVar19 * 0x400) +
                       ((uVar8 ^ uVar15) & uVar19 ^ uVar8 & uVar15);
      iVar9 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
              (uVar18 >> 0x19) + uVar18 * 0x80) + uStack_44 + 0x243185be + uVar16 +
              (~uVar18 & uVar11 ^ uVar23 & uVar18);
      uVar16 = uVar15 + iVar9;
      uVar8 = iVar6 + ((uVar13 >> 2) + uVar13 * 0x40000000 ^ (uVar13 >> 0xd) + uVar13 * 0x80000 ^
                      (uVar13 >> 0x16) + uVar13 * 0x400) +
                      ((uVar15 ^ uVar19) & uVar13 ^ uVar15 & uVar19);
      iVar3 = ((uVar16 >> 6) + uVar16 * 0x4000000 ^ (uVar16 >> 0xb) + uVar16 * 0x200000 ^
              (uVar16 >> 0x19) + uVar16 * 0x80) + uStack_40 + 0x550c7dc3 + uVar11 +
              (~uVar16 & uVar23 ^ uVar18 & uVar16);
      uVar14 = iVar9 + ((uVar8 >> 2) + uVar8 * 0x40000000 ^ (uVar8 >> 0xd) + uVar8 * 0x80000 ^
                       (uVar8 >> 0x16) + uVar8 * 0x400) +
                       ((uVar19 ^ uVar13) & uVar8 ^ uVar19 & uVar13);
      uVar19 = uVar19 + iVar3;
      uVar15 = iVar3 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                       (uVar14 >> 0x16) + uVar14 * 0x400) +
                       ((uVar13 ^ uVar8) & uVar14 ^ uVar13 & uVar8);
      iVar3 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
              (uVar19 >> 0x19) + uVar19 * 0x80) + uStack_3c + 0x72be5d74 + uVar23 +
              (~uVar19 & uVar18 ^ uVar16 & uVar19);
      in_t8 = uVar13 + iVar3;
      uVar23 = iVar3 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                       (uVar15 >> 0x16) + uVar15 * 0x400) +
                       ((uVar8 ^ uVar14) & uVar15 ^ uVar8 & uVar14);
      iVar3 = ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
              (in_t8 >> 0x19) + in_t8 * 0x80) + uStack_38 + 0x80deb1fe + uVar18 +
              (~in_t8 & uVar16 ^ uVar19 & in_t8);
      uVar8 = uVar8 + iVar3;
      uVar18 = iVar3 + ((uVar23 >> 2) + uVar23 * 0x40000000 ^ (uVar23 >> 0xd) + uVar23 * 0x80000 ^
                       (uVar23 >> 0x16) + uVar23 * 0x400) +
                       ((uVar14 ^ uVar15) & uVar23 ^ uVar14 & uVar15);
      iVar3 = ((uVar8 >> 6) + uVar8 * 0x4000000 ^ (uVar8 >> 0xb) + uVar8 * 0x200000 ^
              (uVar8 >> 0x19) + uVar8 * 0x80) + uStack_34 + 0x9bdc06a7 + uVar16 +
              (~uVar8 & uVar19 ^ in_t8 & uVar8);
      uVar14 = uVar14 + iVar3;
      uVar13 = iVar3 + ((uVar18 >> 2) + uVar18 * 0x40000000 ^ (uVar18 >> 0xd) + uVar18 * 0x80000 ^
                       (uVar18 >> 0x16) + uVar18 * 0x400) +
                       ((uVar15 ^ uVar23) & uVar18 ^ uVar15 & uVar23);
      iVar3 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
              (uVar14 >> 0x19) + uVar14 * 0x80) + uStack_30 + 0xc19bf174 + uVar19 +
              (~uVar14 & in_t8 ^ uVar8 & uVar14);
      uVar15 = uVar15 + iVar3;
      unaff_s7 = iVar3 + ((uVar13 >> 2) + uVar13 * 0x40000000 ^ (uVar13 >> 0xd) + uVar13 * 0x80000 ^
                         (uVar13 >> 0x16) + uVar13 * 0x400) +
                         ((uVar23 ^ uVar18) & uVar13 ^ uVar23 & uVar18);
    }
  } while( true );
}

