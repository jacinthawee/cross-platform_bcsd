
void SHA1_Transform(SHA_CTX *c,uchar *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uchar *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint in_a3;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint in_t4;
  uint uVar14;
  uint in_t5;
  uint uVar15;
  uint in_t6;
  uint uVar16;
  uint in_t7;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uchar *puVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint in_t8;
  uint uVar28;
  uint in_t9;
  int iStackX_8;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  
  uStack_40 = c->h0;
  puVar20 = data + 0x40;
  uStack_3c = c->h1;
  uStack_38 = c->h2;
  uStack_34 = c->h3;
  iStackX_8 = 1;
  uStack_30 = c->h4;
  do {
    puVar6 = puVar20 + -0x40;
    if (((uint)data & 3) == 0) {
      uVar1 = *(uint *)(puVar20 + -0x40);
      uVar9 = *(uint *)(puVar20 + -0x3c);
      uVar25 = (uStack_3c >> 2) + uStack_3c * 0x40000000;
      uVar27 = *(uint *)(puVar20 + -0x38);
      uVar16 = *(uint *)(puVar20 + -0x34);
      uVar14 = *(uint *)(puVar20 + -0x30);
      uVar12 = *(uint *)(puVar20 + -0x2c);
      uVar17 = *(uint *)(puVar20 + -0x28);
      uVar8 = *(uint *)(puVar20 + -0x24);
      uVar15 = *(uint *)(puVar20 + -0x20);
      uVar23 = (uStack_40 >> 0x1b) + uStack_40 * 0x20 + uStack_30 + 0x5a827999 + uVar1 +
               ((uStack_38 ^ uStack_34) & uStack_3c ^ uStack_34);
      uVar13 = *(uint *)(puVar20 + -0x1c);
      uVar11 = *(uint *)(puVar20 + -0x18);
      uVar7 = *(uint *)(puVar20 + -0x10);
      uVar10 = *(uint *)(puVar20 + -0x14);
      uVar18 = (uStack_40 >> 2) + uStack_40 * 0x40000000;
      uVar5 = *(uint *)(puVar20 + -0xc);
      uVar28 = *(uint *)(puVar20 + -8);
      uVar3 = *(uint *)(puVar20 + -4);
      uVar19 = ((uStack_38 ^ uVar25) & uStack_40 ^ uStack_38) + uStack_34 + 0x5a827999 + uVar9 +
               (uVar23 >> 0x1b) + uVar23 * 0x20;
      uVar4 = (uVar23 >> 2) + uVar23 * 0x40000000;
      uVar23 = ((uVar25 ^ uVar18) & uVar23 ^ uVar25) + uStack_38 + 0x5a827999 + uVar27 +
               (uVar19 >> 0x1b) + uVar19 * 0x20;
      uVar22 = (uVar19 >> 2) + uVar19 * 0x40000000;
      uVar25 = ((uVar18 ^ uVar4) & uVar19 ^ uVar18) + uVar25 + 0x5a827999 + uVar16 +
               (uVar23 >> 0x1b) + uVar23 * 0x20;
      uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
      uVar23 = ((uVar4 ^ uVar22) & uVar23 ^ uVar4) + uVar18 + 0x5a827999 + uVar14 +
               (uVar25 >> 0x1b) + uVar25 * 0x20;
      uVar2 = (uVar25 >> 2) + uVar25 * 0x40000000;
      uVar4 = uVar12 + 0x5a827999 + uVar4;
      uVar18 = (uVar22 ^ uVar19) & uVar25 ^ uVar22;
    }
    else {
      uVar26 = (uStack_40 >> 2) + uStack_40 * 0x40000000;
      uVar1 = (uint)puVar6 & 3;
      uVar3 = (uint)(puVar20 + -0x3c) & 3;
      uVar5 = (uint)(puVar20 + -0x38) & 3;
      uVar7 = (uint)(puVar20 + -0x34) & 3;
      uVar24 = (uStack_3c >> 2) + uStack_3c * 0x40000000;
      uVar8 = (uint)(puVar20 + -0x3d) & 3;
      uVar1 = (*(int *)(puVar6 + -uVar1) << uVar1 * 8 |
              (uint)data & 3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar8 + 1) * 8 |
              *(uint *)(puVar20 + -0x3d + -uVar8) >> (3 - uVar8) * 8;
      uVar8 = (uint)(puVar20 + -0x39) & 3;
      uVar9 = (*(int *)(puVar20 + -0x3c + -uVar3) << uVar3 * 8 |
              in_a3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar8 + 1) * 8 |
              *(uint *)(puVar20 + -0x39 + -uVar8) >> (3 - uVar8) * 8;
      uVar3 = (uint)(puVar20 + -0x30) & 3;
      uVar8 = (uint)(puVar20 + -0x2c) & 3;
      uVar10 = (uint)(puVar20 + -0x35) & 3;
      uVar27 = (*(int *)(puVar20 + -0x38 + -uVar5) << uVar5 * 8 |
               in_t8 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)(puVar20 + -0x35 + -uVar10) >> (3 - uVar10) * 8;
      uVar17 = ((uStack_38 ^ uStack_34) & uStack_3c ^ uStack_34) +
               (uStack_40 >> 0x1b) + uStack_40 * 0x20 + uStack_30 + 0x5a827999 + uVar1;
      uVar5 = (uint)(puVar20 + -0x31) & 3;
      uVar16 = (*(int *)(puVar20 + -0x34 + -uVar7) << uVar7 * 8 |
               in_t7 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)(puVar20 + -0x31 + -uVar5) >> (3 - uVar5) * 8;
      uVar5 = (uint)(puVar20 + -0x28) & 3;
      uVar7 = (uint)(puVar20 + -0x24) & 3;
      uVar10 = (uint)(puVar20 + -0x2d) & 3;
      uVar14 = (*(int *)(puVar20 + -0x30 + -uVar3) << uVar3 * 8 |
               in_t5 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)(puVar20 + -0x2d + -uVar10) >> (3 - uVar10) * 8;
      uVar3 = (uint)(puVar20 + -0x29) & 3;
      uVar12 = (*(int *)(puVar20 + -0x2c + -uVar8) << uVar8 * 8 |
               uStack_3c & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar3 + 1) * 8 |
               *(uint *)(puVar20 + -0x29 + -uVar3) >> (3 - uVar3) * 8;
      uVar3 = (uint)(puVar20 + -0x20) & 3;
      uVar10 = (uint)(puVar20 + -0x1c) & 3;
      uVar21 = ((uStack_38 ^ uVar24) & uStack_40 ^ uStack_38) + uStack_34 + 0x5a827999 + uVar9 +
               (uVar17 >> 0x1b) + uVar17 * 0x20;
      uVar11 = (uint)(puVar20 + -0x18) & 3;
      uVar23 = (uint)(puVar20 + -0x10) & 3;
      uVar4 = (uVar24 ^ uVar26) & uVar17;
      uVar19 = (uint)(puVar20 + -0x14) & 3;
      uVar18 = (uVar17 >> 2) + uVar17 * 0x40000000;
      uVar25 = (uint)(puVar20 + -8) & 3;
      uVar22 = (uint)(puVar20 + -0xc) & 3;
      uVar8 = (uint)(puVar20 + -0x25) & 3;
      uVar17 = (*(int *)(puVar20 + -0x28 + -uVar5) << uVar5 * 8 |
               uStack_34 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)(puVar20 + -0x25 + -uVar8) >> (3 - uVar8) * 8;
      uVar5 = (uint)(puVar20 + -0x21) & 3;
      uVar8 = (*(int *)(puVar20 + -0x24 + -uVar7) << uVar7 * 8 |
              uStack_30 + 0x5a827999 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar5 + 1) * 8 |
              *(uint *)(puVar20 + -0x21 + -uVar5) >> (3 - uVar5) * 8;
      uVar2 = uStack_38 + 0x5a827999 + uVar27;
      uVar5 = (uint)(puVar20 + -0x1d) & 3;
      uVar15 = (*(int *)(puVar20 + -0x20 + -uVar3) << uVar3 * 8 |
               in_t6 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)(puVar20 + -0x1d + -uVar5) >> (3 - uVar5) * 8;
      uVar3 = (uint)(puVar20 + -0x19) & 3;
      uVar13 = (*(int *)(puVar20 + -0x1c + -uVar10) << uVar10 * 8 |
               in_t4 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar3 + 1) * 8 |
               *(uint *)(puVar20 + -0x19 + -uVar3) >> (3 - uVar3) * 8;
      uVar3 = (uint)(puVar20 + -0x15) & 3;
      uVar11 = (*(int *)(puVar20 + -0x18 + -uVar11) << uVar11 * 8 |
               uStack_40 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar3 + 1) * 8 |
               *(uint *)(puVar20 + -0x15 + -uVar3) >> (3 - uVar3) * 8;
      uVar3 = (uint)(puVar20 + -0x11) & 3;
      uVar10 = (*(int *)(puVar20 + -0x14 + -uVar19) << uVar19 * 8 |
               uStack_38 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar3 + 1) * 8 |
               *(uint *)(puVar20 + -0x11 + -uVar3) >> (3 - uVar3) * 8;
      uVar3 = (uint)(puVar20 + -0xd) & 3;
      uVar7 = (*(int *)(puVar20 + -0x10 + -uVar23) << uVar23 * 8 |
              (uint)puVar6 & 0xffffffffU >> (4 - uVar23) * 8) & -1 << (uVar3 + 1) * 8 |
              *(uint *)(puVar20 + -0xd + -uVar3) >> (3 - uVar3) * 8;
      uVar3 = (uint)(puVar20 + -4) & 3;
      uVar5 = (uint)(puVar20 + -9) & 3;
      uVar5 = (*(int *)(puVar20 + -0xc + -uVar22) << uVar22 * 8 |
              uVar4 & 0xffffffffU >> (4 - uVar22) * 8) & -1 << (uVar5 + 1) * 8 |
              *(uint *)(puVar20 + -9 + -uVar5) >> (3 - uVar5) * 8;
      uVar4 = (uVar4 ^ uVar24) + uVar2 + (uVar21 >> 0x1b) + uVar21 * 0x20;
      uVar22 = (uVar21 >> 2) + uVar21 * 0x40000000;
      uVar23 = (uint)(puVar20 + -5) & 3;
      uVar28 = (*(int *)(puVar20 + -8 + -uVar25) << uVar25 * 8 |
               in_t9 & 0xffffffffU >> (4 - uVar25) * 8) & -1 << (uVar23 + 1) * 8 |
               *(uint *)(puVar20 + -5 + -uVar23) >> (3 - uVar23) * 8;
      uVar23 = (uint)(puVar20 + -1) & 3;
      uVar3 = (*(int *)(puVar20 + -4 + -uVar3) << uVar3 * 8 | uVar2 & 0xffffffffU >> (4 - uVar3) * 8
              ) & -1 << (uVar23 + 1) * 8 | *(uint *)(puVar20 + -1 + -uVar23) >> (3 - uVar23) * 8;
      uVar25 = ((uVar26 ^ uVar18) & uVar21 ^ uVar26) + uVar24 + 0x5a827999 + uVar16 +
               (uVar4 >> 0x1b) + uVar4 * 0x20;
      uVar19 = (uVar4 >> 2) + uVar4 * 0x40000000;
      uVar23 = ((uVar18 ^ uVar22) & uVar4 ^ uVar18) + uVar26 + 0x5a827999 + uVar14 +
               (uVar25 >> 0x1b) + uVar25 * 0x20;
      uVar18 = uVar12 + 0x5a827999 + uVar18;
      uVar2 = (uVar25 >> 2) + uVar25 * 0x40000000;
      uVar4 = (uVar22 ^ uVar19) & uVar25 ^ uVar22;
    }
    uVar18 = uVar4 + uVar18 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar4 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar22 = ((uVar19 ^ uVar2) & uVar23 ^ uVar19) + uVar17 + 0x5a827999 + uVar22 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar2 ^ uVar4) & uVar18 ^ uVar2) + uVar8 + 0x5a827999 + uVar19 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar25 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar2 = ((uVar4 ^ uVar23) & uVar22 ^ uVar4) + uVar15 + 0x5a827999 + uVar2 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar19 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar23 ^ uVar25) & uVar18 ^ uVar23) + uVar13 + 0x5a827999 + uVar4 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar21 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar22 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar23 = ((uVar25 ^ uVar19) & uVar2 ^ uVar25) + uVar11 + 0x5a827999 + uVar23 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar4 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar18 = ((uVar19 ^ uVar21) & uVar18 ^ uVar19) + uVar10 + 0x5a827999 + uVar25 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar2 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar23 = ((uVar21 ^ uVar22) & uVar23 ^ uVar21) + uVar7 + 0x5a827999 + uVar19 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar18 = ((uVar22 ^ uVar4) & uVar18 ^ uVar22) + uVar5 + 0x5a827999 + uVar21 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar25 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar23 = ((uVar4 ^ uVar2) & uVar23 ^ uVar4) + uVar28 + 0x5a827999 + uVar22 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar22 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar2 ^ uVar25) & uVar18 ^ uVar2) + uVar3 + 0x5a827999 + uVar4 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar1 = uVar1 ^ uVar27 ^ uVar15 ^ uVar5;
    uVar9 = uVar9 ^ uVar16 ^ uVar13 ^ uVar28;
    uVar1 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar9 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar2 = ((uVar22 ^ uVar25) & uVar23 ^ uVar25) +
            (uVar18 >> 0x1b) + uVar18 * 0x20 + uVar2 + 0x5a827999 + uVar1;
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar4 = uVar27 ^ uVar14 ^ uVar11 ^ uVar3;
    uVar27 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar25 = ((uVar22 ^ uVar19) & uVar18 ^ uVar22) + uVar25 + 0x5a827999 + uVar9 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar4 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar16 = uVar16 ^ uVar12 ^ uVar10 ^ uVar1;
    uVar16 = uVar16 * 2 - ((int)uVar16 >> 0x1f);
    uVar18 = ((uVar19 ^ uVar23) & uVar2 ^ uVar19) + uVar22 + 0x5a827999 + uVar27 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar14 = uVar14 ^ uVar17 ^ uVar7 ^ uVar9;
    uVar14 = uVar14 * 2 - ((int)uVar14 >> 0x1f);
    uVar2 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar12 = uVar12 ^ uVar8 ^ uVar5 ^ uVar27;
    uVar12 = uVar12 * 2 - ((int)uVar12 >> 0x1f);
    uVar19 = ((uVar23 ^ uVar4) & uVar25 ^ uVar23) + uVar19 + 0x5a827999 + uVar16 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar21 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar17 = uVar17 ^ uVar15 ^ uVar28 ^ uVar16;
    uVar17 = uVar17 * 2 - ((int)uVar17 >> 0x1f);
    uVar18 = (uVar4 ^ uVar2 ^ uVar18) + uVar23 + 0x6ed9eba1 + uVar14 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar22 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar8 = uVar8 ^ uVar13 ^ uVar3 ^ uVar14;
    uVar8 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar25 = (uVar2 ^ uVar21 ^ uVar19) + uVar4 + uVar12 + 0x6ed9eba1 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = (uVar21 ^ uVar22 ^ uVar18) + uVar2 + uVar17 + 0x6ed9eba1 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar15 = uVar15 ^ uVar11 ^ uVar1 ^ uVar12;
    uVar15 = uVar15 * 2 - ((int)uVar15 >> 0x1f);
    uVar19 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar2 = (uVar22 ^ uVar23 ^ uVar25) + uVar8 + 0x6ed9eba1 + uVar21 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar13 = uVar13 ^ uVar10 ^ uVar9 ^ uVar17;
    uVar13 = uVar13 * 2 - ((int)uVar13 >> 0x1f);
    uVar25 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar11 = uVar11 ^ uVar7 ^ uVar27 ^ uVar8;
    uVar11 = uVar11 * 2 - ((int)uVar11 >> 0x1f);
    uVar22 = (uVar23 ^ uVar19 ^ uVar18) + uVar15 + 0x6ed9eba1 + uVar22 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar4 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar18 = (uVar19 ^ uVar25 ^ uVar2) + uVar13 + 0x6ed9eba1 + uVar23 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar10 = uVar10 ^ uVar5 ^ uVar16 ^ uVar15;
    uVar10 = uVar10 * 2 - ((int)uVar10 >> 0x1f);
    uVar2 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar7 = uVar7 ^ uVar28 ^ uVar14 ^ uVar13;
    uVar7 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar19 = (uVar25 ^ uVar4 ^ uVar22) + uVar11 + 0x6ed9eba1 + uVar19 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = (uVar4 ^ uVar2 ^ uVar18) + uVar10 + 0x6ed9eba1 + uVar25 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar5 = uVar5 ^ uVar3 ^ uVar12 ^ uVar11;
    uVar5 = uVar5 * 2 - ((int)uVar5 >> 0x1f);
    uVar22 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar4 = (uVar2 ^ uVar23 ^ uVar19) + uVar7 + 0x6ed9eba1 + uVar4 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar19 = uVar28 ^ uVar1 ^ uVar17 ^ uVar10;
    uVar21 = uVar19 * 2 - ((int)uVar19 >> 0x1f);
    uVar25 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar3 = uVar3 ^ uVar9 ^ uVar8 ^ uVar7;
    uVar3 = uVar3 * 2 - ((int)uVar3 >> 0x1f);
    uVar19 = (uVar23 ^ uVar22 ^ uVar18) + uVar5 + 0x6ed9eba1 + uVar2 +
             (uVar4 >> 0x1b) + uVar4 * 0x20;
    uVar24 = (uVar4 >> 2) + uVar4 * 0x40000000;
    uVar1 = uVar1 ^ uVar27 ^ uVar15 ^ uVar5;
    uVar1 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar18 = (uVar22 ^ uVar25 ^ uVar4) + uVar21 + 0x6ed9eba1 + uVar23 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar2 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar9 = uVar9 ^ uVar16 ^ uVar13 ^ uVar21;
    uVar9 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar19 = (uVar25 ^ uVar24 ^ uVar19) + uVar3 + 0x6ed9eba1 + uVar22 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar22 = (uVar24 ^ uVar2 ^ uVar18) + uVar1 + 0x6ed9eba1 + uVar25 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar18 = uVar27 ^ uVar14 ^ uVar11 ^ uVar3;
    uVar28 = uVar18 * 2 - ((int)uVar18 >> 0x1f);
    uVar18 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar4 = (uVar2 ^ uVar23 ^ uVar19) + uVar9 + 0x6ed9eba1 + uVar24 +
            (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar16 = uVar16 ^ uVar12 ^ uVar10 ^ uVar1;
    uVar16 = uVar16 * 2 - ((int)uVar16 >> 0x1f);
    uVar25 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar14 = uVar14 ^ uVar17 ^ uVar7 ^ uVar9;
    uVar14 = uVar14 * 2 - ((int)uVar14 >> 0x1f);
    uVar19 = (uVar23 ^ uVar18 ^ uVar22) + uVar28 + 0x6ed9eba1 + uVar2 +
             (uVar4 >> 0x1b) + uVar4 * 0x20;
    uVar27 = (uVar4 >> 2) + uVar4 * 0x40000000;
    uVar12 = uVar12 ^ uVar8 ^ uVar5 ^ uVar28;
    uVar12 = uVar12 * 2 - ((int)uVar12 >> 0x1f);
    uVar23 = (uVar18 ^ uVar25 ^ uVar4) + uVar16 + 0x6ed9eba1 + uVar23 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar22 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar18 = (uVar25 ^ uVar27 ^ uVar19) + uVar14 + 0x6ed9eba1 + uVar18 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar17 = uVar17 ^ uVar15 ^ uVar21 ^ uVar16;
    uVar17 = uVar17 * 2 - ((int)uVar17 >> 0x1f);
    uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar8 = uVar8 ^ uVar13 ^ uVar3 ^ uVar14;
    uVar8 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar2 = (uVar27 ^ uVar22 ^ uVar23) + uVar12 + 0x6ed9eba1 + uVar25 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = (uVar22 ^ uVar19 ^ uVar18) + uVar17 + 0x6ed9eba1 + uVar27 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar25 = (uVar19 ^ uVar23 ^ uVar2) + uVar8 + 0x6ed9eba1 + uVar22 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar15 = uVar15 ^ uVar11 ^ uVar1 ^ uVar12;
    uVar15 = uVar15 * 2 - ((int)uVar15 >> 0x1f);
    uVar2 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar13 = uVar13 ^ uVar10 ^ uVar9 ^ uVar17;
    uVar13 = uVar13 * 2 - ((int)uVar13 >> 0x1f);
    uVar22 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar2) & uVar23 | uVar18 & uVar2) +
             uVar15 + 0x8f1bbcdc + uVar19 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar11 = uVar11 ^ uVar7 ^ uVar28 ^ uVar8;
    uVar11 = uVar11 * 2 - ((int)uVar11 >> 0x1f);
    uVar19 = ((uVar25 | uVar22) & uVar2 | uVar25 & uVar22) + uVar13 + 0x8f1bbcdc + uVar23 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar25 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar10 = uVar10 ^ uVar5 ^ uVar16 ^ uVar15;
    uVar10 = uVar10 * 2 - ((int)uVar10 >> 0x1f);
    uVar4 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar25) & uVar22 | uVar18 & uVar25) +
             uVar11 + 0x8f1bbcdc + uVar2 + (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar7 = uVar7 ^ uVar21 ^ uVar14 ^ uVar13;
    uVar7 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar23 = ((uVar19 | uVar4) & uVar25 | uVar19 & uVar4) + uVar10 + 0x8f1bbcdc + uVar22 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar19 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar5 = uVar5 ^ uVar3 ^ uVar12 ^ uVar11;
    uVar5 = uVar5 * 2 - ((int)uVar5 >> 0x1f);
    uVar2 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar19) & uVar4 | uVar18 & uVar19) +
             uVar7 + 0x8f1bbcdc + uVar25 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar22 = uVar21 ^ uVar1 ^ uVar17 ^ uVar10;
    uVar21 = uVar22 * 2 - ((int)uVar22 >> 0x1f);
    uVar4 = ((uVar23 | uVar2) & uVar19 | uVar23 & uVar2) + uVar5 + 0x8f1bbcdc + uVar4 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar23 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar3 = uVar3 ^ uVar9 ^ uVar8 ^ uVar7;
    uVar3 = uVar3 * 2 - ((int)uVar3 >> 0x1f);
    uVar22 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar23) & uVar2 | uVar18 & uVar23) +
             uVar21 + 0x8f1bbcdc + uVar19 + (uVar4 >> 0x1b) + uVar4 * 0x20;
    uVar25 = ((uVar4 | uVar22) & uVar23 | uVar4 & uVar22) + uVar3 + 0x8f1bbcdc + uVar2 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar1 = uVar1 ^ uVar28 ^ uVar15 ^ uVar5;
    uVar1 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar2 = (uVar4 >> 2) + uVar4 * 0x40000000;
    uVar9 = uVar9 ^ uVar16 ^ uVar13 ^ uVar21;
    uVar9 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar19 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar2) & uVar22 | uVar18 & uVar2) +
             uVar1 + 0x8f1bbcdc + uVar23 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar23 = uVar28 ^ uVar14 ^ uVar11 ^ uVar3;
    uVar27 = uVar23 * 2 - ((int)uVar23 >> 0x1f);
    uVar22 = ((uVar25 | uVar19) & uVar2 | uVar25 & uVar19) + uVar9 + 0x8f1bbcdc + uVar22 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar25 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar16 = uVar16 ^ uVar12 ^ uVar10 ^ uVar1;
    uVar16 = uVar16 * 2 - ((int)uVar16 >> 0x1f);
    uVar4 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar25) & uVar19 | uVar18 & uVar25) +
             uVar27 + 0x8f1bbcdc + uVar2 + (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar23 = ((uVar22 | uVar4) & uVar25 | uVar22 & uVar4) + uVar16 + 0x8f1bbcdc + uVar19 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar14 = uVar14 ^ uVar17 ^ uVar7 ^ uVar9;
    uVar14 = uVar14 * 2 - ((int)uVar14 >> 0x1f);
    uVar22 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar12 = uVar12 ^ uVar8 ^ uVar5 ^ uVar27;
    uVar12 = uVar12 * 2 - ((int)uVar12 >> 0x1f);
    uVar2 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar22) & uVar4 | uVar18 & uVar22) +
             uVar14 + 0x8f1bbcdc + uVar25 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar25 = ((uVar23 | uVar2) & uVar22 | uVar23 & uVar2) + uVar12 + 0x8f1bbcdc + uVar4 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar17 = uVar17 ^ uVar15 ^ uVar21 ^ uVar16;
    uVar17 = uVar17 * 2 - ((int)uVar17 >> 0x1f);
    uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar8 = uVar8 ^ uVar13 ^ uVar3 ^ uVar14;
    uVar8 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar4 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = ((uVar18 | uVar19) & uVar2 | uVar18 & uVar19) +
             uVar17 + 0x8f1bbcdc + uVar22 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar22 = ((uVar25 | uVar4) & uVar19 | uVar25 & uVar4) + uVar8 + 0x8f1bbcdc + uVar2 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar15 = uVar15 ^ uVar11 ^ uVar1 ^ uVar12;
    uVar15 = uVar15 * 2 - ((int)uVar15 >> 0x1f);
    uVar25 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar13 = uVar13 ^ uVar10 ^ uVar9 ^ uVar17;
    uVar13 = uVar13 * 2 - ((int)uVar13 >> 0x1f);
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar19 = ((uVar18 | uVar25) & uVar4 | uVar18 & uVar25) +
             uVar15 + 0x8f1bbcdc + uVar19 + (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar2 = ((uVar22 | uVar23) & uVar25 | uVar22 & uVar23) + uVar13 + 0x8f1bbcdc + uVar4 +
            (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar11 = uVar11 ^ uVar7 ^ uVar27 ^ uVar8;
    uVar11 = uVar11 * 2 - ((int)uVar11 >> 0x1f);
    uVar22 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar10 = uVar10 ^ uVar5 ^ uVar16 ^ uVar15;
    uVar10 = uVar10 * 2 - ((int)uVar10 >> 0x1f);
    uVar18 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar19 = ((uVar19 | uVar22) & uVar23 | uVar19 & uVar22) +
             uVar11 + 0x8f1bbcdc + uVar25 + (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar4 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar7 = uVar7 ^ uVar21 ^ uVar14 ^ uVar13;
    uVar7 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar23 = ((uVar2 | uVar18) & uVar22 | uVar2 & uVar18) + uVar10 + 0x8f1bbcdc + uVar23 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar5 = uVar5 ^ uVar3 ^ uVar12 ^ uVar11;
    uVar5 = uVar5 * 2 - ((int)uVar5 >> 0x1f);
    uVar2 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar25 = uVar21 ^ uVar1 ^ uVar17 ^ uVar10;
    uVar28 = uVar25 * 2 - ((int)uVar25 >> 0x1f);
    uVar22 = (uVar18 ^ uVar4 ^ uVar19) + uVar7 + 0xca62c1d6 + uVar22 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar3 = uVar3 ^ uVar9 ^ uVar8 ^ uVar7;
    uVar3 = uVar3 * 2 - ((int)uVar3 >> 0x1f);
    uVar18 = (uVar4 ^ uVar2 ^ uVar23) + uVar5 + 0xca62c1d6 + uVar18 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar25 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar23 = (uVar2 ^ uVar19 ^ uVar22) + uVar28 + 0xca62c1d6 + uVar4 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar1 = uVar1 ^ uVar27 ^ uVar15 ^ uVar5;
    uVar1 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar22 = (uVar19 ^ uVar25 ^ uVar18) + uVar3 + 0xca62c1d6 + uVar2 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar9 = uVar9 ^ uVar16 ^ uVar13 ^ uVar28;
    in_a3 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar18 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar9 = uVar27 ^ uVar14 ^ uVar11 ^ uVar3;
    uVar4 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar27 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar23 = (uVar25 ^ uVar18 ^ uVar23) + uVar1 + 0xca62c1d6 + uVar19 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar9 = uVar16 ^ uVar12 ^ uVar10 ^ uVar1;
    uVar2 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar16 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar22 = (uVar18 ^ uVar27 ^ uVar22) + in_a3 + 0xca62c1d6 + uVar25 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar9 = uVar14 ^ uVar17 ^ uVar7 ^ in_a3;
    uVar14 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar25 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar18 = (uVar27 ^ uVar2 ^ uVar23) + uVar4 + 0xca62c1d6 + uVar18 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar9 = uVar12 ^ uVar8 ^ uVar5 ^ uVar4;
    uVar22 = (uVar2 ^ uVar19 ^ uVar22) + uVar16 + 0xca62c1d6 + uVar27 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar12 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar23 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar9 = uVar17 ^ uVar15 ^ uVar28 ^ uVar16;
    uVar9 = uVar9 * 2 - ((int)uVar9 >> 0x1f);
    uVar17 = (uVar19 ^ uVar25 ^ uVar18) + uVar14 + 0xca62c1d6 + uVar2 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar2 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar8 = uVar8 ^ uVar13 ^ uVar3 ^ uVar14;
    uVar18 = (uVar25 ^ uVar23 ^ uVar22) + uVar12 + 0xca62c1d6 + uVar19 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar8 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar22 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar19 = (uVar23 ^ uVar2 ^ uVar17) + uVar9 + 0xca62c1d6 + uVar25 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar17 = uVar15 ^ uVar11 ^ uVar1 ^ uVar12;
    in_t6 = uVar17 * 2 - ((int)uVar17 >> 0x1f);
    uVar15 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar17 = uVar13 ^ uVar10 ^ in_a3 ^ uVar9;
    in_t4 = 0xca62c1d6;
    uVar13 = (uVar2 ^ uVar22 ^ uVar18) + uVar8 + 0xca62c1d6 + uVar23 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar17 = uVar17 * 2 - ((int)uVar17 >> 0x1f);
    uVar18 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar11 = uVar11 ^ uVar7 ^ uVar4 ^ uVar8;
    uVar23 = (uVar22 ^ uVar15 ^ uVar19) + in_t6 + 0xca62c1d6 + uVar2 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    in_t8 = uVar11 * 2 - ((int)uVar11 >> 0x1f);
    uVar11 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar10 = uVar10 ^ uVar5 ^ uVar16 ^ in_t6;
    uVar16 = (uVar15 ^ uVar18 ^ uVar13) + uVar17 + 0xca62c1d6 + uVar22 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar10 = uVar10 * 2 - ((int)uVar10 >> 0x1f);
    uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar17 = uVar7 ^ uVar28 ^ uVar14 ^ uVar17;
    uVar13 = (uVar18 ^ uVar11 ^ uVar23) + in_t8 + 0xca62c1d6 + uVar15 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar7 = uVar17 * 2 - ((int)uVar17 >> 0x1f);
    uVar14 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar5 = uVar5 ^ uVar3 ^ uVar12 ^ in_t8;
    uVar12 = (uVar11 ^ uVar19 ^ uVar16) + uVar10 + 0xca62c1d6 + uVar18 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    in_t9 = uVar28 ^ uVar1;
    uVar17 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar10 = in_t9 ^ uVar9 ^ uVar10;
    uVar1 = (uVar19 ^ uVar14 ^ uVar13) + uVar7 + 0xca62c1d6 + uVar11 +
            (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar9 = (uVar12 >> 2) + uVar12 * 0x40000000;
    in_t7 = (uVar10 * 2 - ((int)uVar10 >> 0x1f)) + 0xca62c1d6;
    uVar7 = uVar3 ^ in_a3 ^ uVar8 ^ uVar7;
    uVar5 = (uVar1 >> 0x1b) + uVar1 * 0x20 +
            (uVar5 * 2 - ((int)uVar5 >> 0x1f)) + -0x359d3e2a + uVar19 + (uVar14 ^ uVar17 ^ uVar12);
    uVar3 = (uVar1 >> 2) + uVar1 * 0x40000000;
    in_t5 = (uVar7 * 2 - ((int)uVar7 >> 0x1f)) + 0xca62c1d6;
    uVar1 = (uVar5 >> 0x1b) + uVar5 * 0x20 + in_t7 + uVar14 + (uVar17 ^ uVar9 ^ uVar1);
    uStack_38 = (uVar5 >> 2) + uVar5 * 0x40000000 + uStack_38;
    uStack_40 = in_t5 + uVar17 + (uVar9 ^ uVar3 ^ uVar5) + (uVar1 >> 0x1b) + uVar1 * 0x20 +
                uStack_40;
    uStack_3c = uVar1 + uStack_3c;
    uStack_34 = uVar3 + uStack_34;
    c->h1 = uStack_3c;
    uStack_30 = uVar9 + uStack_30;
    c->h0 = uStack_40;
    c->h4 = uStack_30;
    c->h2 = uStack_38;
    iStackX_8 = iStackX_8 + -1;
    c->h3 = uStack_34;
    puVar20 = puVar20 + 0x40;
  } while (iStackX_8 != 0);
  return;
}

