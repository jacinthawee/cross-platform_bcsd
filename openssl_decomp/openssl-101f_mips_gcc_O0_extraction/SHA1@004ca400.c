
uchar * SHA1(uchar *d,size_t n,uchar *md)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  size_t sVar7;
  int iVar8;
  uchar *puVar9;
  uint uVar10;
  uint uVar11;
  uchar *puVar12;
  uchar *puVar13;
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
  int iVar22;
  uint in_t6;
  uint uVar23;
  uint uVar24;
  undefined1 *puVar25;
  uint unaff_s6;
  uint unaff_s7;
  uint in_t8;
  uint uVar26;
  uint unaff_s8;
  uint uStack_17c;
  uint uStack_168;
  uint uStack_164;
  uchar *puStack_160;
  int iStack_15c;
  uint uStack_158;
  uint uStack_154;
  uint uStack_150;
  uchar *puStack_14c;
  uint uStack_148;
  uchar *puStack_144;
  undefined1 *puStack_138;
  uint auStack_104 [4];
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
  uint uStack_c8;
  uchar *puStack_c4;
  undefined1 *puStack_c0;
  SHA_CTX *pSStack_bc;
  undefined *puStack_b8;
  size_t sStack_b4;
  uchar *puStack_b0;
  SHA_CTX SStack_7c;
  uint *local_1c;
  
  puStack_b8 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(uint **)PTR___stack_chk_guard_006aabf0;
  puStack_c0 = md;
  if (md == (uchar *)0x0) {
    puStack_c0 = m_3938;
  }
  sVar7 = n;
  iVar2 = SHA1_Init(&SStack_7c);
  if (iVar2 == 0) {
    puVar9 = (uchar *)0x0;
  }
  else {
    md = (uchar *)n;
    SHA1_Update(&SStack_7c,d,n);
    SHA1_Final(puStack_c0,&SStack_7c);
    sVar7 = 0x60;
    OPENSSL_cleanse(&SStack_7c,0x60);
    puVar9 = puStack_c0;
  }
  if (local_1c == *(uint **)puStack_b8) {
    return puVar9;
  }
  puVar5 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puStack_144 = md + -1;
  puStack_b0 = d;
  sStack_b4 = n;
  pSStack_bc = &SStack_7c;
  puStack_c4 = *(uchar **)PTR___stack_chk_guard_006aabf0;
  puVar6 = puVar5;
  if (md == (uchar *)0x0) {
LAB_004cbdd8:
    if (puStack_c4 != *(uchar **)puVar1) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      (*(code *)PTR_memset_006aab00)();
      puVar6[3] = 0xf70e5939;
      puVar6[6] = 0x64f98fa7;
      puVar6[0x1b] = 0x1c;
      puVar6[4] = 0xffc00b31;
      puVar6[5] = 0x68581511;
      puVar6[7] = 0xbefa4fa4;
      *puVar6 = 0xc1059ed8;
      puVar6[1] = 0x367cd507;
      puVar6[2] = 0x3070dd17;
      return (uchar *)0x1;
    }
    return *(uchar **)puVar1;
  }
  uStack_148 = puVar5[7];
  uStack_168 = *puVar5;
  uVar3 = sVar7 & 3;
  iStack_15c = sVar7 + 0x40;
  uStack_164 = puVar5[1];
  puStack_160 = (uchar *)puVar5[2];
  puStack_138 = K256;
  uStack_158 = puVar5[3];
  uStack_154 = puVar5[4];
  uStack_150 = puVar5[5];
  puStack_14c = (uchar *)puVar5[6];
  if (uVar3 != 0) goto LAB_004cb5e0;
  do {
    iVar2 = ((uStack_154 >> 6) + uStack_154 * 0x4000000 ^
             (uStack_154 >> 0xb) + uStack_154 * 0x200000 ^ (uStack_154 >> 0x19) + uStack_154 * 0x80)
            + uStack_148 + 0x428a2f98 + *(uint *)(iStack_15c + -0x40) +
            (~uStack_154 & (uint)puStack_14c ^ uStack_154 & uStack_150);
    auStack_104[1] = *(uint *)(&DAT_ffffffc4 + iStack_15c);
    auStack_104[0] = *(uint *)(iStack_15c + -0x40);
    auStack_104[2] = *(uint *)(&DAT_ffffffc8 + iStack_15c);
    auStack_104[3] = *(uint *)(&DAT_ffffffcc + iStack_15c);
    uStack_f4 = *(uint *)(iStack_15c + -0x30);
    uStack_ec = *(uint *)(iStack_15c + -0x28);
    uVar14 = iVar2 + uStack_158;
    uStack_e4 = *(uint *)(iStack_15c + -0x20);
    uStack_f0 = *(uint *)(iStack_15c + -0x2c);
    uStack_e8 = *(uint *)(iStack_15c + -0x24);
    uStack_e0 = *(uint *)(iStack_15c + -0x1c);
    uStack_cc = *(uint *)(iStack_15c + -8);
    uStack_c8 = *(uint *)(iStack_15c + -4);
    uStack_d0 = *(uint *)(iStack_15c + -0xc);
    uStack_d4 = *(uint *)(iStack_15c + -0x10);
    uStack_d8 = *(uint *)(iStack_15c + -0x14);
    puVar12 = puStack_14c +
              (~uVar14 & uStack_150 ^ uVar14 & uStack_154) +
              ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
              (uVar14 >> 0x19) + uVar14 * 0x80) + *(uint *)(&DAT_ffffffc4 + iStack_15c) + 0x71374491
              + (int)puStack_160;
    uStack_dc = *(uint *)(iStack_15c + -0x18);
    iVar8 = (((uint)puVar12 >> 6) + (int)puVar12 * 0x4000000 ^
             ((uint)puVar12 >> 0xb) + (int)puVar12 * 0x200000 ^
            ((uint)puVar12 >> 0x19) + (int)puVar12 * 0x80) +
            uStack_150 + 0xb5c0fbcf + *(uint *)(&DAT_ffffffc8 + iStack_15c) +
            (~(uint)puVar12 & uStack_154 ^ uVar14 & (uint)puVar12);
    uVar17 = iVar8 + uStack_164;
    uVar4 = iVar2 + ((uStack_168 >> 2) + uStack_168 * 0x40000000 ^
                     (uStack_168 >> 0xd) + uStack_168 * 0x80000 ^
                    (uStack_168 >> 0x16) + uStack_168 * 0x400) +
                    (uStack_168 & (uint)puStack_160 ^ uStack_168 & uStack_164 ^
                    uStack_164 & (uint)puStack_160);
    iVar2 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
            (uVar17 >> 0x19) + uVar17 * 0x80) +
            uStack_154 + 0xe9b5dba5 + *(uint *)(&DAT_ffffffcc + iStack_15c) +
            (~uVar17 & uVar14 ^ (uint)puVar12 & uVar17);
    uVar19 = iVar2 + uStack_168;
    puVar9 = puStack_14c +
             (~uVar14 & uStack_150 ^ uVar14 & uStack_154) +
             ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
             (uVar14 >> 0x19) + uVar14 * 0x80) + *(uint *)(&DAT_ffffffc4 + iStack_15c) + 0x71374491
             + ((uVar4 >> 2) + uVar4 * 0x40000000 ^ (uVar4 >> 0xd) + uVar4 * 0x80000 ^
               (uVar4 >> 0x16) + uVar4 * 0x400) +
               ((uStack_168 ^ uStack_164) & uVar4 ^ uStack_168 & uStack_164);
    iVar22 = ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
             (uVar19 >> 0x19) + uVar19 * 0x80) + *(uint *)(iStack_15c + -0x30) + 0x3956c25b + uVar14
             + (~uVar19 & (uint)puVar12 ^ uVar17 & uVar19);
    uVar15 = uVar4 + iVar22;
    uVar23 = iVar8 + (((uint)puVar9 >> 2) + (int)puVar9 * 0x40000000 ^
                      ((uint)puVar9 >> 0xd) + (int)puVar9 * 0x80000 ^
                     ((uint)puVar9 >> 0x16) + (int)puVar9 * 0x400) +
                     ((uVar4 ^ uStack_168) & (uint)puVar9 ^ uVar4 & uStack_168);
    puVar13 = puVar9 + (int)(puVar12 +
                            (~uVar15 & uVar17 ^ uVar19 & uVar15) +
                            ((uVar15 >> 6) + uVar15 * 0x4000000 ^
                             (uVar15 >> 0xb) + uVar15 * 0x200000 ^ (uVar15 >> 0x19) + uVar15 * 0x80)
                            + *(uint *)(iStack_15c + -0x2c) + 0x59f111f1);
    uVar4 = iVar2 + ((uVar23 >> 2) + uVar23 * 0x40000000 ^ (uVar23 >> 0xd) + uVar23 * 0x80000 ^
                    (uVar23 >> 0x16) + uVar23 * 0x400) +
                    ((uVar4 ^ (uint)puVar9) & uVar23 ^ uVar4 & (uint)puVar9);
    iVar8 = (((uint)puVar13 >> 6) + (int)puVar13 * 0x4000000 ^
             ((uint)puVar13 >> 0xb) + (int)puVar13 * 0x200000 ^
            ((uint)puVar13 >> 0x19) + (int)puVar13 * 0x80) +
            *(uint *)(iStack_15c + -0x28) + 0x923f82a4 + uVar17 +
            (~(uint)puVar13 & uVar19 ^ uVar15 & (uint)puVar13);
    uVar18 = uVar23 + iVar8;
    uVar14 = iVar22 + ((uVar4 >> 2) + uVar4 * 0x40000000 ^ (uVar4 >> 0xd) + uVar4 * 0x80000 ^
                      (uVar4 >> 0x16) + uVar4 * 0x400) +
                      (((uint)puVar9 ^ uVar23) & uVar4 ^ (uint)puVar9 & uVar23);
    iVar2 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
            (uVar18 >> 0x19) + uVar18 * 0x80) + *(uint *)(iStack_15c + -0x24) + 0xab1c5ed5 + uVar19
            + (~uVar18 & uVar15 ^ (uint)puVar13 & uVar18);
    uVar10 = uVar4 + iVar2;
    puVar9 = puVar12 + (~uVar15 & uVar17 ^ uVar19 & uVar15) +
                       ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
                       (uVar15 >> 0x19) + uVar15 * 0x80) +
                       *(uint *)(iStack_15c + -0x2c) + 0x59f111f1 +
             ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
             (uVar14 >> 0x16) + uVar14 * 0x400) + ((uVar23 ^ uVar4) & uVar14 ^ uVar23 & uVar4);
    uVar17 = iVar8 + (((uint)puVar9 >> 2) + (int)puVar9 * 0x40000000 ^
                      ((uint)puVar9 >> 0xd) + (int)puVar9 * 0x80000 ^
                     ((uint)puVar9 >> 0x16) + (int)puVar9 * 0x400) +
                     ((uVar4 ^ uVar14) & (uint)puVar9 ^ uVar4 & uVar14);
    iVar8 = ((uVar10 >> 6) + uVar10 * 0x4000000 ^ (uVar10 >> 0xb) + uVar10 * 0x200000 ^
            (uVar10 >> 0x19) + uVar10 * 0x80) + *(uint *)(iStack_15c + -0x20) + 0xd807aa98 + uVar15
            + (~uVar10 & (uint)puVar13 ^ uVar18 & uVar10);
    uVar15 = uVar14 + iVar8;
    uVar4 = iVar2 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                    (uVar17 >> 0x16) + uVar17 * 0x400) +
                    ((uVar14 ^ (uint)puVar9) & uVar17 ^ uVar14 & (uint)puVar9);
    puVar12 = puVar9 + (int)(puVar13 +
                            (~uVar15 & uVar18 ^ uVar10 & uVar15) +
                            ((uVar15 >> 6) + uVar15 * 0x4000000 ^
                             (uVar15 >> 0xb) + uVar15 * 0x200000 ^ (uVar15 >> 0x19) + uVar15 * 0x80)
                            + *(uint *)(iStack_15c + -0x1c) + 0x12835b01);
    in_t8 = iVar8 + ((uVar4 >> 2) + uVar4 * 0x40000000 ^ (uVar4 >> 0xd) + uVar4 * 0x80000 ^
                    (uVar4 >> 0x16) + uVar4 * 0x400) +
                    (((uint)puVar9 ^ uVar17) & uVar4 ^ (uint)puVar9 & uVar17);
    iVar2 = (((uint)puVar12 >> 6) + (int)puVar12 * 0x4000000 ^
             ((uint)puVar12 >> 0xb) + (int)puVar12 * 0x200000 ^
            ((uint)puVar12 >> 0x19) + (int)puVar12 * 0x80) +
            *(uint *)(iStack_15c + -0x18) + 0x243185be + uVar18 +
            (~(uint)puVar12 & uVar10 ^ uVar15 & (uint)puVar12);
    uVar14 = uVar17 + iVar2;
    puVar9 = puVar13 + (~uVar15 & uVar18 ^ uVar10 & uVar15) +
                       ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
                       (uVar15 >> 0x19) + uVar15 * 0x80) +
                       *(uint *)(iStack_15c + -0x1c) + 0x12835b01 +
             ((in_t8 >> 2) + in_t8 * 0x40000000 ^ (in_t8 >> 0xd) + in_t8 * 0x80000 ^
             (in_t8 >> 0x16) + in_t8 * 0x400) + ((uVar17 ^ uVar4) & in_t8 ^ uVar17 & uVar4);
    iVar8 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
            (uVar14 >> 0x19) + uVar14 * 0x80) + *(uint *)(iStack_15c + -0x14) + 0x550c7dc3 + uVar10
            + (~uVar14 & uVar15 ^ (uint)puVar12 & uVar14);
    uVar17 = iVar2 + (((uint)puVar9 >> 2) + (int)puVar9 * 0x40000000 ^
                      ((uint)puVar9 >> 0xd) + (int)puVar9 * 0x80000 ^
                     ((uint)puVar9 >> 0x16) + (int)puVar9 * 0x400) +
                     ((uVar4 ^ in_t8) & (uint)puVar9 ^ uVar4 & in_t8);
    uVar4 = uVar4 + iVar8;
    iVar2 = ((uVar4 >> 6) + uVar4 * 0x4000000 ^ (uVar4 >> 0xb) + uVar4 * 0x200000 ^
            (uVar4 >> 0x19) + uVar4 * 0x80) + *(uint *)(iStack_15c + -0x10) + 0x72be5d74 + uVar15 +
            (~uVar4 & (uint)puVar12 ^ uVar14 & uVar4);
    in_t4 = iVar8 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                    (uVar17 >> 0x16) + uVar17 * 0x400) +
                    ((in_t8 ^ (uint)puVar9) & uVar17 ^ in_t8 & (uint)puVar9);
    in_t8 = in_t8 + iVar2;
    uVar10 = iVar2 + ((in_t4 >> 2) + in_t4 * 0x40000000 ^ (in_t4 >> 0xd) + in_t4 * 0x80000 ^
                     (in_t4 >> 0x16) + in_t4 * 0x400) +
                     (((uint)puVar9 ^ uVar17) & in_t4 ^ (uint)puVar9 & uVar17);
    puVar9 = puVar9 + (int)(puVar12 +
                           (~in_t8 & uVar14 ^ uVar4 & in_t8) +
                           ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                           (in_t8 >> 0x19) + in_t8 * 0x80) +
                           *(uint *)(iStack_15c + -0xc) + 0x80deb1fe);
    puVar12 = puVar12 + (~in_t8 & uVar14 ^ uVar4 & in_t8) +
                        ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                        (in_t8 >> 0x19) + in_t8 * 0x80) + *(uint *)(iStack_15c + -0xc) + 0x80deb1fe
              + ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                (uVar10 >> 0x16) + uVar10 * 0x400) + ((uVar17 ^ in_t4) & uVar10 ^ uVar17 & in_t4);
    iVar2 = (((uint)puVar9 >> 6) + (int)puVar9 * 0x4000000 ^
             ((uint)puVar9 >> 0xb) + (int)puVar9 * 0x200000 ^
            ((uint)puVar9 >> 0x19) + (int)puVar9 * 0x80) +
            *(uint *)(iStack_15c + -8) + 0x9bdc06a7 + uVar14 +
            (~(uint)puVar9 & uVar4 ^ in_t8 & (uint)puVar9);
    uVar17 = uVar17 + iVar2;
    uVar14 = iVar2 + (((uint)puVar12 >> 2) + (int)puVar12 * 0x40000000 ^
                      ((uint)puVar12 >> 0xd) + (int)puVar12 * 0x80000 ^
                     ((uint)puVar12 >> 0x16) + (int)puVar12 * 0x400) +
                     ((in_t4 ^ uVar10) & (uint)puVar12 ^ in_t4 & uVar10);
    iVar2 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
            (uVar17 >> 0x19) + uVar17 * 0x80) + *(uint *)(iStack_15c + -4) + 0xc19bf174 + uVar4 +
            (~uVar17 & in_t8 ^ (uint)puVar9 & uVar17);
    in_t4 = in_t4 + iVar2;
    unaff_s7 = iVar2 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                       (uVar14 >> 0x16) + uVar14 * 0x400) +
                       ((uVar10 ^ (uint)puVar12) & uVar14 ^ uVar10 & (uint)puVar12);
    while( true ) {
      uStack_17c = 0x1d;
      uVar4 = 0;
      puVar25 = puStack_138;
      uVar15 = 0x10;
      do {
        uVar18 = uVar15 + 1 & 0xf;
        uVar19 = uVar15 + 0xe & 0xf;
        uVar11 = auStack_104[uVar18];
        uVar20 = auStack_104[uVar19];
        uVar23 = uVar15 + 2 & 0xf;
        uVar16 = auStack_104[uVar15 + 9 & 0xf] + auStack_104[uVar4] +
                 ((uVar11 >> 7) + uVar11 * 0x2000000 ^ (uVar11 >> 0x12) + uVar11 * 0x4000 ^
                 uVar11 >> 3) +
                 ((uVar20 >> 0x11) + uVar20 * 0x8000 ^ (uVar20 >> 0x13) + uVar20 * 0x2000 ^
                 uVar20 >> 10);
        auStack_104[uVar4] = uVar16;
        uVar11 = uVar15 + 0xf & 0xf;
        uVar24 = auStack_104[uVar23];
        uVar20 = auStack_104[uVar11];
        uVar21 = uVar15 + 3 & 0xf;
        uVar20 = auStack_104[uVar15 + 10 & 0xf] + auStack_104[uVar18] +
                 ((uVar24 >> 7) + uVar24 * 0x2000000 ^ (uVar24 >> 0x12) + uVar24 * 0x4000 ^
                 uVar24 >> 3) +
                 ((uVar20 >> 0x11) + uVar20 * 0x8000 ^ (uVar20 >> 0x13) + uVar20 * 0x2000 ^
                 uVar20 >> 10);
        auStack_104[uVar18] = uVar20;
        uVar18 = auStack_104[uVar4];
        uVar24 = auStack_104[uVar21];
        uVar18 = auStack_104[uVar15 + 0xb & 0xf] + auStack_104[uVar23] +
                 ((uVar18 >> 0x11) + uVar18 * 0x8000 ^ (uVar18 >> 0x13) + uVar18 * 0x2000 ^
                 uVar18 >> 10) +
                 ((uVar24 >> 7) + uVar24 * 0x2000000 ^ (uVar24 >> 0x12) + uVar24 * 0x4000 ^
                 uVar24 >> 3);
        auStack_104[uVar23] = uVar18;
        uVar24 = uVar15 + 4 & 0xf;
        uVar26 = auStack_104[uVar24];
        uVar23 = auStack_104[uVar15 + 0x11 & 0xf];
        iVar8 = ((in_t4 >> 6) + in_t4 * 0x4000000 ^ (in_t4 >> 0xb) + in_t4 * 0x200000 ^
                (in_t4 >> 0x19) + in_t4 * 0x80) + (~in_t4 & (uint)puVar9 ^ in_t4 & uVar17) +
                *(int *)(puVar25 + 0x40) + uVar16 + in_t8;
        iVar2 = *(int *)(puVar25 + 0x44);
        uVar10 = iVar8 + uVar10;
        uVar23 = auStack_104[uVar15 + 0xc & 0xf] + auStack_104[uVar21] +
                 ((uVar26 >> 7) + uVar26 * 0x2000000 ^ (uVar26 >> 0x12) + uVar26 * 0x4000 ^
                 uVar26 >> 3) +
                 ((uVar23 >> 0x11) + uVar23 * 0x8000 ^ (uVar23 >> 0x13) + uVar23 * 0x2000 ^
                 uVar23 >> 10);
        auStack_104[uVar21] = uVar23;
        uVar21 = uVar15 + 5 & 0xf;
        uVar16 = auStack_104[uVar21];
        uVar26 = auStack_104[uVar15 + 0x12 & 0xf];
        puVar13 = puVar9 + (~uVar10 & uVar17 ^ uVar10 & in_t4) +
                           ((uVar10 >> 6) + uVar10 * 0x4000000 ^ (uVar10 >> 0xb) + uVar10 * 0x200000
                           ^ (uVar10 >> 0x19) + uVar10 * 0x80) + uVar20 + iVar2 + (int)puVar12;
        in_t8 = iVar8 + ((unaff_s7 >> 2) + unaff_s7 * 0x40000000 ^
                         (unaff_s7 >> 0xd) + unaff_s7 * 0x80000 ^
                        (unaff_s7 >> 0x16) + unaff_s7 * 0x400) +
                        (unaff_s7 & (uint)puVar12 ^ unaff_s7 & uVar14 ^ uVar14 & (uint)puVar12);
        iVar8 = (((uint)puVar13 >> 6) + (int)puVar13 * 0x4000000 ^
                 ((uint)puVar13 >> 0xb) + (int)puVar13 * 0x200000 ^
                ((uint)puVar13 >> 0x19) + (int)puVar13 * 0x80) +
                uVar17 + *(int *)(puVar25 + 0x48) + uVar18 +
                (~(uint)puVar13 & in_t4 ^ uVar10 & (uint)puVar13);
        puVar9 = puVar9 + (~uVar10 & uVar17 ^ uVar10 & in_t4) +
                          ((uVar10 >> 6) + uVar10 * 0x4000000 ^ (uVar10 >> 0xb) + uVar10 * 0x200000
                          ^ (uVar10 >> 0x19) + uVar10 * 0x80) + uVar20 + iVar2 +
                 ((in_t8 >> 2) + in_t8 * 0x40000000 ^ (in_t8 >> 0xd) + in_t8 * 0x80000 ^
                 (in_t8 >> 0x16) + in_t8 * 0x400) +
                 ((unaff_s7 ^ uVar14) & in_t8 ^ unaff_s7 & uVar14);
        iVar2 = *(int *)(puVar25 + 0x4c);
        uVar20 = uVar15 + 6 & 0xf;
        uVar14 = iVar8 + uVar14;
        uVar16 = auStack_104[uStack_17c & 0xf] + auStack_104[uVar24] +
                 ((uVar16 >> 7) + uVar16 * 0x2000000 ^ (uVar16 >> 0x12) + uVar16 * 0x4000 ^
                 uVar16 >> 3) +
                 ((uVar26 >> 0x11) + uVar26 * 0x8000 ^ (uVar26 >> 0x13) + uVar26 * 0x2000 ^
                 uVar26 >> 10);
        auStack_104[uVar24] = uVar16;
        uVar17 = auStack_104[uVar20];
        uVar18 = auStack_104[uVar15 + 0x13 & 0xf];
        uVar18 = auStack_104[uVar21] + auStack_104[uVar19] +
                 ((uVar17 >> 7) + uVar17 * 0x2000000 ^ (uVar17 >> 0x12) + uVar17 * 0x4000 ^
                 uVar17 >> 3) +
                 ((uVar18 >> 0x11) + uVar18 * 0x8000 ^ (uVar18 >> 0x13) + uVar18 * 0x2000 ^
                 uVar18 >> 10);
        iVar22 = *(int *)(puVar25 + 0x50);
        iVar2 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
                (uVar14 >> 0x19) + uVar14 * 0x80) + in_t4 + iVar2 + uVar23 +
                (~uVar14 & uVar10 ^ (uint)puVar13 & uVar14);
        auStack_104[uVar21] = uVar18;
        uVar17 = iVar8 + (((uint)puVar9 >> 2) + (int)puVar9 * 0x40000000 ^
                          ((uint)puVar9 >> 0xd) + (int)puVar9 * 0x80000 ^
                         ((uint)puVar9 >> 0x16) + (int)puVar9 * 0x400) +
                         ((in_t8 ^ unaff_s7) & (uint)puVar9 ^ in_t8 & unaff_s7);
        uVar19 = uVar15 + 7 & 0xf;
        uVar21 = iVar2 + unaff_s7;
        uVar24 = auStack_104[uVar19];
        in_t4 = iVar2 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                        (uVar17 >> 0x16) + uVar17 * 0x400) +
                        ((in_t8 ^ (uint)puVar9) & uVar17 ^ in_t8 & (uint)puVar9);
        uVar23 = auStack_104[uVar15 + 0x14 & 0xf];
        iVar8 = ((uVar21 >> 6) + uVar21 * 0x4000000 ^ (uVar21 >> 0xb) + uVar21 * 0x200000 ^
                (uVar21 >> 0x19) + uVar21 * 0x80) + uVar16 + iVar22 + uVar10 +
                (~uVar21 & (uint)puVar13 ^ uVar14 & uVar21);
        iVar2 = *(int *)(puVar25 + 0x54);
        in_t8 = in_t8 + iVar8;
        unaff_s6 = uVar15 + 8;
        uVar11 = auStack_104[uVar20] + auStack_104[uVar11] +
                 ((uVar24 >> 7) + uVar24 * 0x2000000 ^ (uVar24 >> 0x12) + uVar24 * 0x4000 ^
                 uVar24 >> 3) +
                 ((uVar23 >> 0x11) + uVar23 * 0x8000 ^ (uVar23 >> 0x13) + uVar23 * 0x2000 ^
                 uVar23 >> 10);
        auStack_104[uVar20] = uVar11;
        uVar10 = iVar8 + ((in_t4 >> 2) + in_t4 * 0x40000000 ^ (in_t4 >> 0xd) + in_t4 * 0x80000 ^
                         (in_t4 >> 0x16) + in_t4 * 0x400) +
                         (((uint)puVar9 ^ uVar17) & in_t4 ^ (uint)puVar9 & uVar17);
        uStack_17c = uVar15 + 0x15;
        uVar23 = auStack_104[unaff_s6 & 0xf];
        puVar9 = puVar9 + (int)(puVar13 +
                               (~in_t8 & uVar14 ^ uVar21 & in_t8) +
                               ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000
                               ^ (in_t8 >> 0x19) + in_t8 * 0x80) + uVar18 + iVar2);
        uVar15 = auStack_104[uStack_17c & 0xf];
        puVar12 = puVar13 + (~in_t8 & uVar14 ^ uVar21 & in_t8) +
                            ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                            (in_t8 >> 0x19) + in_t8 * 0x80) + uVar18 + iVar2 +
                  ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                  (uVar10 >> 0x16) + uVar10 * 0x400) + ((uVar17 ^ in_t4) & uVar10 ^ uVar17 & in_t4);
        in_t5 = (((uint)puVar9 >> 6) + (int)puVar9 * 0x4000000 ^
                 ((uint)puVar9 >> 0xb) + (int)puVar9 * 0x200000 ^
                ((uint)puVar9 >> 0x19) + (int)puVar9 * 0x80) +
                uVar11 + *(int *)(puVar25 + 0x58) + uVar14 +
                (~(uint)puVar9 & uVar21 ^ in_t8 & (uint)puVar9);
        uVar14 = in_t5 + (((uint)puVar12 >> 2) + (int)puVar12 * 0x40000000 ^
                          ((uint)puVar12 >> 0xd) + (int)puVar12 * 0x80000 ^
                         ((uint)puVar12 >> 0x16) + (int)puVar12 * 0x400) +
                         ((in_t4 ^ uVar10) & (uint)puVar12 ^ in_t4 & uVar10);
        iVar2 = *(int *)(puVar25 + 0x5c);
        uVar4 = ((uVar23 >> 7) + uVar23 * 0x2000000 ^ (uVar23 >> 0x12) + uVar23 * 0x4000 ^
                uVar23 >> 3) + auStack_104[uVar19] + auStack_104[uVar4] +
                ((uVar15 >> 0x11) + uVar15 * 0x8000 ^ (uVar15 >> 0x13) + uVar15 * 0x2000 ^
                uVar15 >> 10);
        uVar17 = uVar17 + in_t5;
        puVar25 = puVar25 + 0x20;
        auStack_104[uVar19] = uVar4;
        in_t6 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
                (uVar17 >> 0x19) + uVar17 * 0x80) + uVar4 + iVar2 + uVar21 +
                (~uVar17 & in_t8 ^ (uint)puVar9 & uVar17);
        unaff_s7 = in_t6 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000
                           ^ (uVar14 >> 0x16) + uVar14 * 0x400) +
                           ((uVar10 ^ (uint)puVar12) & uVar14 ^ uVar10 & (uint)puVar12);
        in_t4 = in_t4 + in_t6;
        uVar4 = unaff_s6 & 0xf;
        uVar15 = unaff_s6;
      } while (unaff_s6 != 0x40);
      uStack_168 = unaff_s7 + uStack_168;
      uStack_164 = uVar14 + uStack_164;
      puStack_144 = puStack_144 + -1;
      n = (size_t)(puVar12 + (int)puStack_160);
      in_t4 = in_t4 + uStack_154;
      unaff_s8 = uVar10 + uStack_158;
      uStack_150 = uVar17 + uStack_150;
      *puVar5 = uStack_168;
      puVar5[1] = uStack_164;
      md = puVar9 + (int)puStack_14c;
      puVar5[2] = n;
      puVar5[3] = unaff_s8;
      puVar5[4] = in_t4;
      puVar5[5] = uStack_150;
      puVar6 = (uint *)0xffffffff;
      uStack_148 = in_t8 + uStack_148;
      puVar5[6] = (uint)md;
      puVar5[7] = uStack_148;
      iStack_15c = iStack_15c + 0x40;
      if (puStack_144 == (uchar *)0xffffffff) goto LAB_004cbdd8;
      puStack_160 = (uchar *)n;
      uStack_158 = unaff_s8;
      uStack_154 = in_t4;
      puStack_14c = md;
      if (uVar3 == 0) break;
LAB_004cb5e0:
      uVar4 = iStack_15c - 0x40U & 3;
      uVar14 = (uint)(&DAT_ffffffc4 + iStack_15c) & 3;
      uVar17 = iStack_15c - 0x39U & 3;
      auStack_104[1] =
           (*(int *)(&DAT_ffffffc4 + iStack_15c + -uVar14) << uVar14 * 8 |
           (uint)md & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar17 + 1) * 8 |
           *(uint *)((iStack_15c - 0x39U) - uVar17) >> (3 - uVar17) * 8;
      uVar14 = (uint)(&DAT_ffffffcc + iStack_15c) & 3;
      uVar17 = iStack_15c - 0x3dU & 3;
      auStack_104[0] =
           (*(int *)((iStack_15c - 0x40U) - uVar4) << uVar4 * 8 |
           uVar3 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar17 + 1) * 8 |
           *(uint *)((iStack_15c - 0x3dU) - uVar17) >> (3 - uVar17) * 8;
      uVar4 = (uint)(&DAT_ffffffc8 + iStack_15c) & 3;
      uVar17 = iStack_15c - 0x30U & 3;
      uVar10 = iStack_15c - 0x2cU & 3;
      uVar15 = iStack_15c - 0x28U & 3;
      uVar18 = iStack_15c - 0x35U & 3;
      auStack_104[2] =
           (*(int *)(&DAT_ffffffc8 + iStack_15c + -uVar4) << uVar4 * 8 |
           in_t5 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar18 + 1) * 8 |
           *(uint *)((iStack_15c - 0x35U) - uVar18) >> (3 - uVar18) * 8;
      uVar4 = iStack_15c - 0x2dU & 3;
      uStack_f4 = (*(int *)((iStack_15c - 0x30U) - uVar17) << uVar17 * 8 |
                  in_t8 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x2dU) - uVar4) >> (3 - uVar4) * 8;
      iVar2 = ((uStack_154 >> 6) + uStack_154 * 0x4000000 ^
               (uStack_154 >> 0xb) + uStack_154 * 0x200000 ^
              (uStack_154 >> 0x19) + uStack_154 * 0x80) + uStack_148 + 0x428a2f98 +
              (~uStack_154 & (uint)puStack_14c ^ uStack_154 & uStack_150) + auStack_104[0];
      uVar4 = iStack_15c - 0x31U & 3;
      auStack_104[3] =
           (*(int *)(&DAT_ffffffcc + iStack_15c + -uVar14) << uVar14 * 8 |
           n & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar4 + 1) * 8 |
           *(uint *)((iStack_15c - 0x31U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iStack_15c - 0x29U & 3;
      uStack_f0 = (*(int *)((iStack_15c - 0x2cU) - uVar10) << uVar10 * 8 |
                  in_t6 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x29U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iStack_15c - 0x24U & 3;
      uVar14 = iStack_15c - 0x20U & 3;
      uVar19 = iVar2 + uStack_158;
      uVar17 = iStack_15c - 0x18U & 3;
      uVar10 = iStack_15c - 0x21U & 3;
      uStack_e8 = (*(int *)((iStack_15c - 0x24U) - uVar4) << uVar4 * 8 |
                  (uint)puStack_14c & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar10 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x21U) - uVar10) >> (3 - uVar10) * 8;
      uVar4 = iStack_15c - 0x1dU & 3;
      uStack_e4 = (*(int *)((iStack_15c - 0x20U) - uVar14) << uVar14 * 8 |
                  auStack_104[0] & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x1dU) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iStack_15c - 0x25U & 3;
      uStack_ec = (*(int *)((iStack_15c - 0x28U) - uVar15) << uVar15 * 8 |
                  in_t4 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x25U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iStack_15c - 0x15U & 3;
      uStack_dc = (*(int *)((iStack_15c - 0x18U) - uVar17) << uVar17 * 8 |
                  unaff_s6 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x15U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iStack_15c - 0x14U & 3;
      uVar14 = iStack_15c - 0x1cU & 3;
      uVar15 = uStack_150 + 0xb5c0fbcf + auStack_104[2];
      uVar17 = iStack_15c - 0x19U & 3;
      uStack_e0 = (*(int *)((iStack_15c - 0x1cU) - uVar14) << uVar14 * 8 |
                  auStack_104[1] & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar17 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x19U) - uVar17) >> (3 - uVar17) * 8;
      puVar12 = puStack_14c +
                (~uVar19 & uStack_150 ^ uVar19 & uStack_154) +
                ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
                (uVar19 >> 0x19) + uVar19 * 0x80) + auStack_104[1] + 0x71374491 + (int)puStack_160;
      uVar14 = iStack_15c - 0x10U & 3;
      uVar17 = iStack_15c - 0x11U & 3;
      uStack_d8 = (*(int *)((iStack_15c - 0x14U) - uVar4) << uVar4 * 8 |
                  unaff_s7 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar17 + 1) * 8 |
                  *(uint *)((iStack_15c - 0x11U) - uVar17) >> (3 - uVar17) * 8;
      uVar4 = iStack_15c - 0xdU & 3;
      uStack_d4 = (*(int *)((iStack_15c - 0x10U) - uVar14) << uVar14 * 8 |
                  unaff_s8 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((iStack_15c - 0xdU) - uVar4) >> (3 - uVar4) * 8;
      uVar18 = (((uint)puVar12 >> 6) + (int)puVar12 * 0x4000000 ^
                ((uint)puVar12 >> 0xb) + (int)puVar12 * 0x200000 ^
               ((uint)puVar12 >> 0x19) + (int)puVar12 * 0x80) + uVar15;
      uVar4 = iStack_15c - 0xcU & 3;
      uVar14 = iStack_15c - 8U & 3;
      iVar8 = uVar18 + (~(uint)puVar12 & uStack_154 ^ uVar19 & (uint)puVar12);
      uVar17 = iStack_15c - 4U & 3;
      uVar10 = iStack_15c - 9U & 3;
      uStack_d0 = (*(int *)((iStack_15c - 0xcU) - uVar4) << uVar4 * 8 |
                  uVar15 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar10 + 1) * 8 |
                  *(uint *)((iStack_15c - 9U) - uVar10) >> (3 - uVar10) * 8;
      uVar15 = iVar8 + uStack_164;
      uVar4 = iStack_15c - 5U & 3;
      uStack_cc = (*(int *)((iStack_15c - 8U) - uVar14) << uVar14 * 8 |
                  ~(uint)puVar12 & uStack_154 & 0xffffffffU >> (4 - uVar14) * 8) &
                  -1 << (uVar4 + 1) * 8 | *(uint *)((iStack_15c - 5U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iStack_15c - 1U & 3;
      uStack_c8 = (*(int *)((iStack_15c - 4U) - uVar17) << uVar17 * 8 |
                  uVar18 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((iStack_15c - 1U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iVar2 + ((uStack_168 >> 2) + uStack_168 * 0x40000000 ^
                       (uStack_168 >> 0xd) + uStack_168 * 0x80000 ^
                      (uStack_168 >> 0x16) + uStack_168 * 0x400) +
                      (uStack_168 & (uint)puStack_160 ^ uStack_168 & uStack_164 ^
                      uStack_164 & (uint)puStack_160);
      iVar2 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
              (uVar15 >> 0x19) + uVar15 * 0x80) + uStack_154 + 0xe9b5dba5 + auStack_104[3] +
              (~uVar15 & uVar19 ^ (uint)puVar12 & uVar15);
      uVar10 = iVar2 + uStack_168;
      puVar9 = puStack_14c +
               (~uVar19 & uStack_150 ^ uVar19 & uStack_154) +
               ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
               (uVar19 >> 0x19) + uVar19 * 0x80) + auStack_104[1] + 0x71374491 +
               ((uVar4 >> 2) + uVar4 * 0x40000000 ^ (uVar4 >> 0xd) + uVar4 * 0x80000 ^
               (uVar4 >> 0x16) + uVar4 * 0x400) +
               ((uStack_168 ^ uStack_164) & uVar4 ^ uStack_168 & uStack_164);
      iVar22 = ((uVar10 >> 6) + uVar10 * 0x4000000 ^ (uVar10 >> 0xb) + uVar10 * 0x200000 ^
               (uVar10 >> 0x19) + uVar10 * 0x80) + uStack_f4 + 0x3956c25b + uVar19 +
               (~uVar10 & (uint)puVar12 ^ uVar15 & uVar10);
      uVar19 = uVar4 + iVar22;
      uVar17 = iVar8 + (((uint)puVar9 >> 2) + (int)puVar9 * 0x40000000 ^
                        ((uint)puVar9 >> 0xd) + (int)puVar9 * 0x80000 ^
                       ((uint)puVar9 >> 0x16) + (int)puVar9 * 0x400) +
                       ((uVar4 ^ uStack_168) & (uint)puVar9 ^ uVar4 & uStack_168);
      puVar13 = puVar9 + (int)(puVar12 +
                              (~uVar19 & uVar15 ^ uVar10 & uVar19) +
                              ((uVar19 >> 6) + uVar19 * 0x4000000 ^
                               (uVar19 >> 0xb) + uVar19 * 0x200000 ^
                              (uVar19 >> 0x19) + uVar19 * 0x80) + uStack_f0 + 0x59f111f1);
      uVar14 = iVar2 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                       (uVar17 >> 0x16) + uVar17 * 0x400) +
                       ((uVar4 ^ (uint)puVar9) & uVar17 ^ uVar4 & (uint)puVar9);
      iVar2 = (((uint)puVar13 >> 6) + (int)puVar13 * 0x4000000 ^
               ((uint)puVar13 >> 0xb) + (int)puVar13 * 0x200000 ^
              ((uint)puVar13 >> 0x19) + (int)puVar13 * 0x80) + uStack_ec + 0x923f82a4 + uVar15 +
              (~(uint)puVar13 & uVar10 ^ uVar19 & (uint)puVar13);
      uVar18 = uVar17 + iVar2;
      uVar23 = iVar22 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                        (uVar14 >> 0x16) + uVar14 * 0x400) +
                        (((uint)puVar9 ^ uVar17) & uVar14 ^ (uint)puVar9 & uVar17);
      iVar8 = ((uVar18 >> 6) + uVar18 * 0x4000000 ^ (uVar18 >> 0xb) + uVar18 * 0x200000 ^
              (uVar18 >> 0x19) + uVar18 * 0x80) + uStack_e8 + 0xab1c5ed5 + uVar10 +
              (~uVar18 & uVar19 ^ (uint)puVar13 & uVar18);
      uVar4 = uVar14 + iVar8;
      puVar9 = puVar12 + (~uVar19 & uVar15 ^ uVar10 & uVar19) +
                         ((uVar19 >> 6) + uVar19 * 0x4000000 ^ (uVar19 >> 0xb) + uVar19 * 0x200000 ^
                         (uVar19 >> 0x19) + uVar19 * 0x80) + uStack_f0 + 0x59f111f1 +
               ((uVar23 >> 2) + uVar23 * 0x40000000 ^ (uVar23 >> 0xd) + uVar23 * 0x80000 ^
               (uVar23 >> 0x16) + uVar23 * 0x400) + ((uVar17 ^ uVar14) & uVar23 ^ uVar17 & uVar14);
      uVar17 = iVar2 + (((uint)puVar9 >> 2) + (int)puVar9 * 0x40000000 ^
                        ((uint)puVar9 >> 0xd) + (int)puVar9 * 0x80000 ^
                       ((uint)puVar9 >> 0x16) + (int)puVar9 * 0x400) +
                       ((uVar14 ^ uVar23) & (uint)puVar9 ^ uVar14 & uVar23);
      iVar2 = ((uVar4 >> 6) + uVar4 * 0x4000000 ^ (uVar4 >> 0xb) + uVar4 * 0x200000 ^
              (uVar4 >> 0x19) + uVar4 * 0x80) + uStack_e4 + 0xd807aa98 + uVar19 +
              (~uVar4 & (uint)puVar13 ^ uVar18 & uVar4);
      uVar10 = uVar23 + iVar2;
      uVar15 = iVar8 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                       (uVar17 >> 0x16) + uVar17 * 0x400) +
                       ((uVar23 ^ (uint)puVar9) & uVar17 ^ uVar23 & (uint)puVar9);
      puVar12 = puVar9 + (int)(puVar13 +
                              (~uVar10 & uVar18 ^ uVar4 & uVar10) +
                              ((uVar10 >> 6) + uVar10 * 0x4000000 ^
                               (uVar10 >> 0xb) + uVar10 * 0x200000 ^
                              (uVar10 >> 0x19) + uVar10 * 0x80) + uStack_e0 + 0x12835b01);
      in_t8 = iVar2 + ((uVar15 >> 2) + uVar15 * 0x40000000 ^ (uVar15 >> 0xd) + uVar15 * 0x80000 ^
                      (uVar15 >> 0x16) + uVar15 * 0x400) +
                      (((uint)puVar9 ^ uVar17) & uVar15 ^ (uint)puVar9 & uVar17);
      iVar8 = (((uint)puVar12 >> 6) + (int)puVar12 * 0x4000000 ^
               ((uint)puVar12 >> 0xb) + (int)puVar12 * 0x200000 ^
              ((uint)puVar12 >> 0x19) + (int)puVar12 * 0x80) + uStack_dc + 0x243185be + uVar18 +
              (~(uint)puVar12 & uVar4 ^ uVar10 & (uint)puVar12);
      uVar14 = uVar17 + iVar8;
      puVar9 = puVar13 + (~uVar10 & uVar18 ^ uVar4 & uVar10) +
                         ((uVar10 >> 6) + uVar10 * 0x4000000 ^ (uVar10 >> 0xb) + uVar10 * 0x200000 ^
                         (uVar10 >> 0x19) + uVar10 * 0x80) + uStack_e0 + 0x12835b01 +
               ((in_t8 >> 2) + in_t8 * 0x40000000 ^ (in_t8 >> 0xd) + in_t8 * 0x80000 ^
               (in_t8 >> 0x16) + in_t8 * 0x400) + ((uVar17 ^ uVar15) & in_t8 ^ uVar17 & uVar15);
      iVar2 = ((uVar14 >> 6) + uVar14 * 0x4000000 ^ (uVar14 >> 0xb) + uVar14 * 0x200000 ^
              (uVar14 >> 0x19) + uVar14 * 0x80) + uStack_d8 + 0x550c7dc3 + uVar4 +
              (~uVar14 & uVar10 ^ (uint)puVar12 & uVar14);
      uVar17 = iVar8 + (((uint)puVar9 >> 2) + (int)puVar9 * 0x40000000 ^
                        ((uint)puVar9 >> 0xd) + (int)puVar9 * 0x80000 ^
                       ((uint)puVar9 >> 0x16) + (int)puVar9 * 0x400) +
                       ((uVar15 ^ in_t8) & (uint)puVar9 ^ uVar15 & in_t8);
      uVar15 = uVar15 + iVar2;
      in_t4 = iVar2 + ((uVar17 >> 2) + uVar17 * 0x40000000 ^ (uVar17 >> 0xd) + uVar17 * 0x80000 ^
                      (uVar17 >> 0x16) + uVar17 * 0x400) +
                      ((in_t8 ^ (uint)puVar9) & uVar17 ^ in_t8 & (uint)puVar9);
      iVar2 = ((uVar15 >> 6) + uVar15 * 0x4000000 ^ (uVar15 >> 0xb) + uVar15 * 0x200000 ^
              (uVar15 >> 0x19) + uVar15 * 0x80) + uStack_d4 + 0x72be5d74 + uVar10 +
              (~uVar15 & (uint)puVar12 ^ uVar14 & uVar15);
      in_t8 = in_t8 + iVar2;
      uVar10 = iVar2 + ((in_t4 >> 2) + in_t4 * 0x40000000 ^ (in_t4 >> 0xd) + in_t4 * 0x80000 ^
                       (in_t4 >> 0x16) + in_t4 * 0x400) +
                       (((uint)puVar9 ^ uVar17) & in_t4 ^ (uint)puVar9 & uVar17);
      puVar9 = puVar9 + (int)(puVar12 +
                             (~in_t8 & uVar14 ^ uVar15 & in_t8) +
                             ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                             (in_t8 >> 0x19) + in_t8 * 0x80) + uStack_d0 + 0x80deb1fe);
      puVar12 = puVar12 + (~in_t8 & uVar14 ^ uVar15 & in_t8) +
                          ((in_t8 >> 6) + in_t8 * 0x4000000 ^ (in_t8 >> 0xb) + in_t8 * 0x200000 ^
                          (in_t8 >> 0x19) + in_t8 * 0x80) + uStack_d0 + 0x80deb1fe +
                ((uVar10 >> 2) + uVar10 * 0x40000000 ^ (uVar10 >> 0xd) + uVar10 * 0x80000 ^
                (uVar10 >> 0x16) + uVar10 * 0x400) + ((uVar17 ^ in_t4) & uVar10 ^ uVar17 & in_t4);
      iVar2 = (((uint)puVar9 >> 6) + (int)puVar9 * 0x4000000 ^
               ((uint)puVar9 >> 0xb) + (int)puVar9 * 0x200000 ^
              ((uint)puVar9 >> 0x19) + (int)puVar9 * 0x80) + uStack_cc + 0x9bdc06a7 + uVar14 +
              (~(uint)puVar9 & uVar15 ^ in_t8 & (uint)puVar9);
      uVar17 = uVar17 + iVar2;
      uVar14 = iVar2 + (((uint)puVar12 >> 2) + (int)puVar12 * 0x40000000 ^
                        ((uint)puVar12 >> 0xd) + (int)puVar12 * 0x80000 ^
                       ((uint)puVar12 >> 0x16) + (int)puVar12 * 0x400) +
                       ((in_t4 ^ uVar10) & (uint)puVar12 ^ in_t4 & uVar10);
      iVar2 = ((uVar17 >> 6) + uVar17 * 0x4000000 ^ (uVar17 >> 0xb) + uVar17 * 0x200000 ^
              (uVar17 >> 0x19) + uVar17 * 0x80) + uStack_c8 + 0xc19bf174 + uVar15 +
              (~uVar17 & in_t8 ^ (uint)puVar9 & uVar17);
      in_t4 = in_t4 + iVar2;
      unaff_s7 = iVar2 + ((uVar14 >> 2) + uVar14 * 0x40000000 ^ (uVar14 >> 0xd) + uVar14 * 0x80000 ^
                         (uVar14 >> 0x16) + uVar14 * 0x400) +
                         ((uVar10 ^ (uint)puVar12) & uVar14 ^ uVar10 & (uint)puVar12);
    }
  } while( true );
}

