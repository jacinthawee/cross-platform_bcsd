
void SHA_Transform(SHA_CTX *c,uchar *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint in_a3;
  uint uVar14;
  uint in_t0;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint in_t3;
  uint uVar18;
  uint in_t4;
  uint uVar19;
  uint in_t5;
  uint uVar20;
  uchar *puVar21;
  uint uVar22;
  uint unaff_s0;
  uint uVar23;
  uint unaff_s1;
  uint uVar24;
  uint unaff_s2;
  uint uVar25;
  uint unaff_s3;
  uint uVar26;
  uint unaff_s4;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  int iStackX_8;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  
  uStack_40 = c->h0;
  puVar21 = data + 0x40;
  uStack_3c = c->h1;
  uStack_38 = c->h2;
  uStack_34 = c->h3;
  iStackX_8 = 1;
  uStack_30 = c->h4;
  do {
    if (((uint)data & 3) == 0) {
      uVar13 = *(uint *)(puVar21 + -0x40);
      uVar14 = *(uint *)(puVar21 + -0x3c);
      uVar7 = (uStack_3c >> 2) + uStack_3c * 0x40000000;
      uVar19 = *(uint *)(puVar21 + -0x38);
      uVar18 = *(uint *)(puVar21 + -0x34);
      uVar17 = *(uint *)(puVar21 + -0x30);
      uVar16 = *(uint *)(puVar21 + -0x2c);
      uVar15 = *(uint *)(puVar21 + -0x28);
      uVar26 = *(uint *)(puVar21 + -0x24);
      uVar25 = *(uint *)(puVar21 + -0x20);
      uVar5 = (uStack_40 >> 0x1b) + uStack_40 * 0x20 + uStack_30 + 0x5a827999 + uVar13 +
              ((uStack_38 ^ uStack_34) & uStack_3c ^ uStack_34);
      uVar22 = *(uint *)(puVar21 + -0x1c);
      uVar20 = *(uint *)(puVar21 + -0x18);
      uVar24 = *(uint *)(puVar21 + -0x14);
      uVar23 = *(uint *)(puVar21 + -0x10);
      uVar28 = (uStack_40 >> 2) + uStack_40 * 0x40000000;
      uVar30 = *(uint *)(puVar21 + -8);
      uVar2 = *(uint *)(puVar21 + -0xc);
      uVar29 = *(uint *)(puVar21 + -4);
      uVar11 = ((uStack_38 ^ uVar7) & uStack_40 ^ uStack_38) + uStack_34 + 0x5a827999 + uVar14 +
               (uVar5 >> 0x1b) + uVar5 * 0x20;
      uVar10 = (uVar5 >> 2) + uVar5 * 0x40000000;
      uVar1 = ((uVar7 ^ uVar28) & uVar5 ^ uVar7) + uStack_38 + 0x5a827999 + uVar19 +
              (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar7 = ((uVar28 ^ uVar10) & uVar11 ^ uVar28) + uVar7 + 0x5a827999 + uVar18 +
              (uVar1 >> 0x1b) + uVar1 * 0x20;
      uVar3 = (uVar1 >> 2) + uVar1 * 0x40000000;
      uVar12 = (uVar7 >> 2) + uVar7 * 0x40000000;
      uVar11 = ((uVar10 ^ uVar5) & uVar1 ^ uVar10) + uVar28 + 0x5a827999 + uVar17 +
               (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar28 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar5 ^ uVar3) & uVar7 ^ uVar5) + uVar16 + 0x5a827999 + uVar10 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar7 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar3 ^ uVar12) & uVar11 ^ uVar3) + uVar15 + 0x5a827999 + uVar5 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar12 ^ uVar28) & uVar10 ^ uVar12) + uVar26 + 0x5a827999 + uVar3 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar1 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar28 ^ uVar7) & uVar11 ^ uVar28) + uVar25 + 0x5a827999 + uVar12 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar12 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar7 ^ uVar5) & uVar10 ^ uVar7) + uVar22 + 0x5a827999 + uVar28 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar11 = ((uVar5 ^ uVar1) & uVar11 ^ uVar5) + uVar20 + 0x5a827999 + uVar7 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar7 = (uVar10 >> 2) + uVar10 * 0x40000000;
      iVar8 = ((uVar1 ^ uVar12) & uVar10 ^ uVar1) + uVar24 + 0x5a827999 + uVar5;
    }
    else {
      uVar27 = (uStack_40 >> 2) + uStack_40 * 0x40000000;
      uVar2 = (uint)(puVar21 + -0x40) & 3;
      uVar11 = (uint)(puVar21 + -0x3c) & 3;
      uVar5 = (uint)(puVar21 + -0x38) & 3;
      uVar10 = (uint)(puVar21 + -0x34) & 3;
      uVar7 = (uint)(puVar21 + -0x3d) & 3;
      uVar13 = (*(int *)(puVar21 + -0x40 + -uVar2) << uVar2 * 8 |
               in_a3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar7 + 1) * 8 |
               *(uint *)(puVar21 + -0x3d + -uVar7) >> (3 - uVar7) * 8;
      uVar9 = (uStack_3c >> 2) + uStack_3c * 0x40000000;
      uVar2 = (uint)(puVar21 + -0x39) & 3;
      uVar14 = (*(int *)(puVar21 + -0x3c + -uVar11) << uVar11 * 8 |
               in_t0 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)(puVar21 + -0x39 + -uVar2) >> (3 - uVar2) * 8;
      uVar2 = (uint)(puVar21 + -0x35) & 3;
      uVar19 = (*(int *)(puVar21 + -0x38 + -uVar5) << uVar5 * 8 |
               in_t5 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)(puVar21 + -0x35 + -uVar2) >> (3 - uVar2) * 8;
      uVar2 = (uint)(puVar21 + -0x30) & 3;
      uVar11 = (uint)(puVar21 + -0x2c) & 3;
      uVar3 = ((uStack_38 ^ uStack_34) & uStack_3c ^ uStack_34) +
              (uStack_40 >> 0x1b) + uStack_40 * 0x20 + uStack_30 + 0x5a827999 + uVar13;
      uVar5 = (uint)(puVar21 + -0x31) & 3;
      uVar18 = (*(int *)(puVar21 + -0x34 + -uVar10) << uVar10 * 8 |
               in_t4 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)(puVar21 + -0x31 + -uVar5) >> (3 - uVar5) * 8;
      uVar5 = (uint)(puVar21 + -0x28) & 3;
      uVar10 = (uint)(puVar21 + -0x24) & 3;
      uVar7 = (uint)(puVar21 + -0x2d) & 3;
      uVar17 = (*(int *)(puVar21 + -0x30 + -uVar2) << uVar2 * 8 |
               in_t3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar7 + 1) * 8 |
               *(uint *)(puVar21 + -0x2d + -uVar7) >> (3 - uVar7) * 8;
      uVar2 = (uint)(puVar21 + -0x29) & 3;
      uVar16 = (*(int *)(puVar21 + -0x2c + -uVar11) << uVar11 * 8 |
               uStack_3c & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)(puVar21 + -0x29 + -uVar2) >> (3 - uVar2) * 8;
      uVar2 = (uint)(puVar21 + -0x20) & 3;
      uVar11 = (uint)(puVar21 + -0x1c) & 3;
      uVar7 = (uint)(puVar21 + -0x18) & 3;
      uVar6 = ((uStack_38 ^ uVar9) & uStack_40 ^ uStack_38) + uStack_34 + 0x5a827999 + uVar14 +
              (uVar3 >> 0x1b) + uVar3 * 0x20;
      uVar28 = (uint)(puVar21 + -0x14) & 3;
      uVar12 = (uint)(puVar21 + -0x10) & 3;
      uVar1 = uStack_38 + 0x5a827999 + uVar19;
      uVar15 = (uint)(puVar21 + -0x25) & 3;
      uVar15 = (*(int *)(puVar21 + -0x28 + -uVar5) << uVar5 * 8 |
               uStack_34 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar15 + 1) * 8 |
               *(uint *)(puVar21 + -0x25 + -uVar15) >> (3 - uVar15) * 8;
      uVar4 = (uVar3 >> 2) + uVar3 * 0x40000000;
      uVar5 = (uint)(puVar21 + -0x21) & 3;
      uVar26 = (*(int *)(puVar21 + -0x24 + -uVar10) << uVar10 * 8 |
               unaff_s4 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)(puVar21 + -0x21 + -uVar5) >> (3 - uVar5) * 8;
      uVar5 = (uint)(puVar21 + -0x1d) & 3;
      uVar25 = (*(int *)(puVar21 + -0x20 + -uVar2) << uVar2 * 8 |
               unaff_s3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)(puVar21 + -0x1d + -uVar5) >> (3 - uVar5) * 8;
      uVar2 = (uint)(puVar21 + -0xc) & 3;
      uVar5 = (uint)(puVar21 + -0x19) & 3;
      uVar22 = (*(int *)(puVar21 + -0x1c + -uVar11) << uVar11 * 8 |
               unaff_s0 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)(puVar21 + -0x19 + -uVar5) >> (3 - uVar5) * 8;
      uVar11 = (uint)(puVar21 + -0x15) & 3;
      uVar20 = (*(int *)(puVar21 + -0x18 + -uVar7) << uVar7 * 8 |
               uStack_38 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar11 + 1) * 8 |
               *(uint *)(puVar21 + -0x15 + -uVar11) >> (3 - uVar11) * 8;
      uVar11 = (uint)(puVar21 + -0x11) & 3;
      uVar24 = (*(int *)(puVar21 + -0x14 + -uVar28) << uVar28 * 8 |
               unaff_s2 & 0xffffffffU >> (4 - uVar28) * 8) & -1 << (uVar11 + 1) * 8 |
               *(uint *)(puVar21 + -0x11 + -uVar11) >> (3 - uVar11) * 8;
      uVar11 = (uint)(puVar21 + -8) & 3;
      uVar5 = (uint)(puVar21 + -4) & 3;
      uVar10 = (uint)(puVar21 + -0xd) & 3;
      uVar23 = (*(int *)(puVar21 + -0x10 + -uVar12) << uVar12 * 8 |
               unaff_s1 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)(puVar21 + -0xd + -uVar10) >> (3 - uVar10) * 8;
      uVar10 = (uint)(puVar21 + -9) & 3;
      uVar2 = (*(int *)(puVar21 + -0xc + -uVar2) << uVar2 * 8 |
              uVar1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar10 + 1) * 8 |
              *(uint *)(puVar21 + -9 + -uVar10) >> (3 - uVar10) * 8;
      uVar28 = ((uVar9 ^ uVar27) & uVar3 ^ uVar9) + uVar1 + (uVar6 >> 0x1b) + uVar6 * 0x20;
      uVar7 = (uVar6 >> 2) + uVar6 * 0x40000000;
      uVar10 = (uint)(puVar21 + -5) & 3;
      uVar30 = (*(int *)(puVar21 + -8 + -uVar11) << uVar11 * 8 |
               uStack_40 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)(puVar21 + -5 + -uVar10) >> (3 - uVar10) * 8;
      uVar11 = (uint)(puVar21 + -1) & 3;
      uVar29 = (*(int *)(puVar21 + -4 + -uVar5) << uVar5 * 8 |
               0xffffffffU >> (4 - uVar5) * 8 & 0x5a827999) & -1 << (uVar11 + 1) * 8 |
               *(uint *)(puVar21 + -1 + -uVar11) >> (3 - uVar11) * 8;
      uVar11 = ((uVar27 ^ uVar4) & uVar6 ^ uVar27) + uVar9 + 0x5a827999 + uVar18 +
               (uVar28 >> 0x1b) + uVar28 * 0x20;
      uVar1 = (uVar28 >> 2) + uVar28 * 0x40000000;
      uVar12 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar4 ^ uVar7) & uVar28 ^ uVar4) + uVar27 + 0x5a827999 + uVar17 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar3 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar7 ^ uVar1) & uVar11 ^ uVar7) + uVar16 + 0x5a827999 + uVar4 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar1 ^ uVar12) & uVar10 ^ uVar1) + uVar15 + 0x5a827999 + uVar7 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar28 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar12 ^ uVar3) & uVar11 ^ uVar12) + uVar26 + 0x5a827999 + uVar1 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar1 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar7 = ((uVar3 ^ uVar5) & uVar10 ^ uVar3) + uVar25 + 0x5a827999 + uVar12 +
              (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar12 = (uVar7 >> 2) + uVar7 * 0x40000000;
      uVar10 = ((uVar5 ^ uVar28) & uVar11 ^ uVar5) + uVar22 + 0x5a827999 + uVar3 +
               (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar11 = ((uVar28 ^ uVar1) & uVar7 ^ uVar28) + uVar20 + 0x5a827999 + uVar5 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar7 = (uVar10 >> 2) + uVar10 * 0x40000000;
      iVar8 = ((uVar1 ^ uVar12) & uVar10 ^ uVar1) + uVar24 + 0x5a827999 + uVar28;
    }
    uVar5 = iVar8 + (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar10 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar28 = (uVar5 >> 2) + uVar5 * 0x40000000;
    uVar11 = ((uVar12 ^ uVar7) & uVar11 ^ uVar12) + uVar23 + 0x5a827999 + uVar1 +
             (uVar5 >> 0x1b) + uVar5 * 0x20;
    uVar5 = ((uVar7 ^ uVar10) & uVar5 ^ uVar7) + uVar2 + 0x5a827999 + uVar12 +
            (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar1 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar12 = ((uVar10 ^ uVar28) & uVar11 ^ uVar10) + uVar30 + 0x5a827999 + uVar7 +
             (uVar5 >> 0x1b) + uVar5 * 0x20;
    uVar11 = ((uVar28 ^ uVar1) & uVar5 ^ uVar28) + uVar29 + 0x5a827999 + uVar10 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar13 = uVar2 ^ uVar13 ^ uVar19 ^ uVar25;
    uVar10 = (uVar5 >> 2) + uVar5 * 0x40000000;
    uVar7 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar14 = uVar30 ^ uVar14 ^ uVar18 ^ uVar22;
    uVar12 = (uVar11 >> 0x1b) + uVar11 * 0x20 + uVar28 + 0x5a827999 + uVar13 +
             ((uVar10 ^ uVar1) & uVar12 ^ uVar1);
    uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar19 = uVar29 ^ uVar19 ^ uVar17 ^ uVar20;
    uVar28 = ((uVar10 ^ uVar7) & uVar11 ^ uVar10) + uVar1 + 0x5a827999 + uVar14 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar1 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar18 = uVar13 ^ uVar18 ^ uVar16 ^ uVar24;
    uVar11 = ((uVar7 ^ uVar5) & uVar12 ^ uVar7) + uVar10 + 0x5a827999 + uVar19 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar12 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar17 = uVar14 ^ uVar17 ^ uVar15 ^ uVar23;
    uVar7 = ((uVar5 ^ uVar1) & uVar28 ^ uVar5) + uVar7 + 0x5a827999 + uVar18 +
            (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar16 = uVar19 ^ uVar16 ^ uVar26 ^ uVar2;
    uVar10 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar5 = (uVar1 ^ uVar12 ^ uVar11) + uVar5 + 0x6ed9eba1 + uVar17 + (uVar7 >> 0x1b) + uVar7 * 0x20
    ;
    uVar15 = uVar18 ^ uVar15 ^ uVar25 ^ uVar30;
    uVar28 = (uVar7 >> 2) + uVar7 * 0x40000000;
    uVar7 = (uVar12 ^ uVar10 ^ uVar7) + uVar16 + 0x6ed9eba1 + uVar1 + (uVar5 >> 0x1b) + uVar5 * 0x20
    ;
    uVar11 = uVar17 ^ uVar26 ^ uVar22 ^ uVar29;
    uVar3 = (uVar5 >> 2) + uVar5 * 0x40000000;
    uVar26 = (uVar10 ^ uVar28 ^ uVar5) + uVar15 + 0x6ed9eba1 + uVar12 +
             (uVar7 >> 0x1b) + uVar7 * 0x20;
    uVar5 = uVar16 ^ uVar25 ^ uVar20 ^ uVar13;
    uVar12 = (uVar7 >> 2) + uVar7 * 0x40000000;
    uVar10 = (uVar28 ^ uVar3 ^ uVar7) + uVar11 + 0x6ed9eba1 + uVar10 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar22 = uVar15 ^ uVar22 ^ uVar24 ^ uVar14;
    uVar25 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar7 = (uVar3 ^ uVar12 ^ uVar26) + uVar5 + 0x6ed9eba1 + uVar28 +
            (uVar10 >> 0x1b) + uVar10 * 0x20;
    uVar20 = uVar11 ^ uVar20 ^ uVar23 ^ uVar19;
    uVar1 = (uVar10 >> 2) + uVar10 * 0x40000000;
    uVar28 = (uVar12 ^ uVar25 ^ uVar10) + uVar22 + 0x6ed9eba1 + uVar3 +
             (uVar7 >> 0x1b) + uVar7 * 0x20;
    uVar10 = uVar5 ^ uVar24 ^ uVar2 ^ uVar18;
    uVar26 = (uVar7 >> 2) + uVar7 * 0x40000000;
    uVar12 = (uVar25 ^ uVar1 ^ uVar7) + uVar20 + 0x6ed9eba1 + uVar12 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar7 = uVar22 ^ uVar23 ^ uVar30 ^ uVar17;
    uVar23 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar28 = (uVar1 ^ uVar26 ^ uVar28) + uVar10 + 0x6ed9eba1 + uVar25 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar2 = uVar20 ^ uVar2 ^ uVar29 ^ uVar16;
    uVar25 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar12 = (uVar26 ^ uVar23 ^ uVar12) + uVar7 + 0x6ed9eba1 + uVar1 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar30 = uVar10 ^ uVar30 ^ uVar13 ^ uVar15;
    uVar24 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar26 = (uVar23 ^ uVar25 ^ uVar28) + uVar2 + 0x6ed9eba1 + uVar26 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar29 = uVar7 ^ uVar29 ^ uVar14 ^ uVar11;
    uVar1 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar23 = (uVar25 ^ uVar24 ^ uVar12) + uVar30 + 0x6ed9eba1 + uVar23 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar28 = uVar2 ^ uVar13 ^ uVar19 ^ uVar5;
    uVar3 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar25 = (uVar24 ^ uVar1 ^ uVar26) + uVar29 + 0x6ed9eba1 + uVar25 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar12 = uVar30 ^ uVar14 ^ uVar18 ^ uVar22;
    uVar13 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar14 = (uVar1 ^ uVar3 ^ uVar23) + uVar28 + 0x6ed9eba1 + uVar24 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar19 = uVar29 ^ uVar19 ^ uVar17 ^ uVar20;
    uVar26 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar18 = uVar28 ^ uVar18 ^ uVar16 ^ uVar10;
    uVar24 = (uVar3 ^ uVar13 ^ uVar25) + uVar12 + 0x6ed9eba1 + uVar1 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar1 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar17 = uVar12 ^ uVar17 ^ uVar15 ^ uVar7;
    uVar23 = (uVar13 ^ uVar26 ^ uVar14) + uVar19 + 0x6ed9eba1 + uVar3 +
             (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar25 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar14 = uVar19 ^ uVar16 ^ uVar11 ^ uVar2;
    uVar16 = (uVar26 ^ uVar1 ^ uVar24) + uVar18 + 0x6ed9eba1 + uVar13 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar24 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar23 = (uVar1 ^ uVar25 ^ uVar23) + uVar17 + 0x6ed9eba1 + uVar26 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar13 = uVar18 ^ uVar15 ^ uVar5 ^ uVar30;
    uVar3 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar11 = uVar17 ^ uVar11 ^ uVar22 ^ uVar29;
    uVar26 = (uVar25 ^ uVar24 ^ uVar16) + uVar14 + 0x6ed9eba1 + uVar1 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar15 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar16 = (uVar24 ^ uVar3 ^ uVar23) + uVar13 + 0x6ed9eba1 + uVar25 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar5 = uVar14 ^ uVar5 ^ uVar20 ^ uVar28;
    uVar23 = (uVar3 ^ uVar15 ^ uVar26) + uVar11 + 0x6ed9eba1 + uVar24 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar25 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar22 = uVar13 ^ uVar22 ^ uVar10 ^ uVar12;
    uVar1 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = ((uVar16 | uVar25) & uVar15 | uVar16 & uVar25) +
             uVar5 + 0x8f1bbcdc + uVar3 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar20 = uVar11 ^ uVar20 ^ uVar7 ^ uVar19;
    uVar24 = ((uVar23 | uVar1) & uVar25 | uVar23 & uVar1) + uVar22 + 0x8f1bbcdc + uVar15 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar26 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar10 = uVar5 ^ uVar10 ^ uVar2 ^ uVar18;
    uVar3 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar15 = ((uVar16 | uVar26) & uVar1 | uVar16 & uVar26) +
             uVar20 + 0x8f1bbcdc + uVar25 + (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar7 = uVar22 ^ uVar7 ^ uVar30 ^ uVar17;
    uVar23 = ((uVar24 | uVar3) & uVar26 | uVar24 & uVar3) + uVar10 + 0x8f1bbcdc + uVar1 +
             (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar25 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar2 = uVar20 ^ uVar2 ^ uVar29 ^ uVar14;
    uVar1 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar16 = ((uVar15 | uVar25) & uVar3 | uVar15 & uVar25) +
             uVar7 + 0x8f1bbcdc + uVar26 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar30 = uVar10 ^ uVar30 ^ uVar28 ^ uVar13;
    uVar15 = ((uVar23 | uVar1) & uVar25 | uVar23 & uVar1) + uVar2 + 0x8f1bbcdc + uVar3 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar24 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar29 = uVar7 ^ uVar29 ^ uVar12 ^ uVar11;
    uVar26 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar23 = ((uVar16 | uVar24) & uVar1 | uVar16 & uVar24) +
             uVar30 + 0x8f1bbcdc + uVar25 + (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar28 = uVar2 ^ uVar28 ^ uVar19 ^ uVar5;
    uVar16 = ((uVar15 | uVar26) & uVar24 | uVar15 & uVar26) + uVar29 + 0x8f1bbcdc + uVar1 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar15 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar12 = uVar30 ^ uVar12 ^ uVar18 ^ uVar22;
    uVar1 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar25 = ((uVar23 | uVar15) & uVar26 | uVar23 & uVar15) +
             uVar28 + 0x8f1bbcdc + uVar24 + (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar19 = uVar29 ^ uVar19 ^ uVar17 ^ uVar20;
    uVar24 = ((uVar16 | uVar1) & uVar15 | uVar16 & uVar1) + uVar12 + 0x8f1bbcdc + uVar26 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar23 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = uVar28 ^ uVar18 ^ uVar14 ^ uVar10;
    uVar3 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar18 = ((uVar25 | uVar23) & uVar1 | uVar25 & uVar23) +
             uVar19 + 0x8f1bbcdc + uVar15 + (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar25 = ((uVar24 | uVar3) & uVar23 | uVar24 & uVar3) + uVar16 + 0x8f1bbcdc + uVar1 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar15 = uVar12 ^ uVar17 ^ uVar13 ^ uVar7;
    uVar24 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar14 = uVar19 ^ uVar14 ^ uVar11 ^ uVar2;
    uVar26 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar17 = ((uVar18 | uVar24) & uVar3 | uVar18 & uVar24) +
             uVar15 + 0x8f1bbcdc + uVar23 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar13 = uVar16 ^ uVar13 ^ uVar5 ^ uVar30;
    uVar1 = ((uVar25 | uVar26) & uVar24 | uVar25 & uVar26) + uVar14 + 0x8f1bbcdc + uVar3 +
            (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar18 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar11 = uVar15 ^ uVar11 ^ uVar22 ^ uVar29;
    uVar25 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar17 | uVar18) & uVar26 | uVar17 & uVar18) +
             uVar13 + 0x8f1bbcdc + uVar24 + (uVar1 >> 0x1b) + uVar1 * 0x20;
    uVar5 = uVar14 ^ uVar5 ^ uVar20 ^ uVar28;
    uVar23 = ((uVar1 | uVar25) & uVar18 | uVar1 & uVar25) + uVar11 + 0x8f1bbcdc + uVar26 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar24 = (uVar1 >> 2) + uVar1 * 0x40000000;
    uVar22 = uVar13 ^ uVar22 ^ uVar10 ^ uVar12;
    uVar26 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar17 | uVar24) & uVar25 | uVar17 & uVar24) +
             uVar5 + 0x8f1bbcdc + uVar18 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar18 = uVar11 ^ uVar20 ^ uVar7 ^ uVar19;
    uVar20 = ((uVar23 | uVar26) & uVar24 | uVar23 & uVar26) + uVar22 + 0x8f1bbcdc + uVar25 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar23 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar10 = uVar5 ^ uVar10 ^ uVar2 ^ uVar16;
    uVar25 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar17 | uVar23) & uVar26 | uVar17 & uVar23) +
             uVar18 + 0x8f1bbcdc + uVar24 + (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar7 = uVar22 ^ uVar7 ^ uVar30 ^ uVar15;
    uVar24 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar26 = ((uVar20 | uVar25) & uVar23 | uVar20 & uVar25) + uVar10 + 0x8f1bbcdc + uVar26 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar2 = uVar18 ^ uVar2 ^ uVar29 ^ uVar14;
    uVar20 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar30 = uVar10 ^ uVar30 ^ uVar28 ^ uVar13;
    uVar17 = (uVar25 ^ uVar24 ^ uVar17) + uVar7 + 0xca62c1d6 + uVar23 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar1 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar3 = uVar7 ^ uVar29 ^ uVar12 ^ uVar11;
    uVar25 = (uVar24 ^ uVar20 ^ uVar26) + uVar2 + 0xca62c1d6 + uVar25 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar23 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = (uVar20 ^ uVar1 ^ uVar17) + uVar30 + 0xca62c1d6 + uVar24 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    in_a3 = uVar2 ^ uVar28 ^ uVar19 ^ uVar5;
    uVar24 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar28 = (uVar1 ^ uVar23 ^ uVar25) + uVar3 + 0xca62c1d6 + uVar20 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    in_t0 = uVar30 ^ uVar12 ^ uVar16 ^ uVar22;
    uVar12 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar20 = (uVar23 ^ uVar24 ^ uVar17) + in_a3 + 0xca62c1d6 + uVar1 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar17 = uVar3 ^ uVar19 ^ uVar15 ^ uVar18;
    uVar19 = (uVar28 >> 2) + uVar28 * 0x40000000;
    in_t4 = in_a3 ^ uVar16 ^ uVar14 ^ uVar10;
    uVar25 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar28 = (uVar24 ^ uVar12 ^ uVar28) + in_t0 + 0xca62c1d6 + uVar23 +
             (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar23 = (uVar12 ^ uVar19 ^ uVar20) + uVar17 + 0xca62c1d6 + uVar24 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar15 = in_t0 ^ uVar15 ^ uVar13 ^ uVar7;
    uVar16 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar20 = (uVar19 ^ uVar25 ^ uVar28) + in_t4 + 0xca62c1d6 + uVar12 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar12 = uVar17 ^ uVar14 ^ uVar11 ^ uVar2;
    uVar24 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar14 = (uVar25 ^ uVar16 ^ uVar23) + uVar15 + 0xca62c1d6 + uVar19 +
             (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar28 = in_t4 ^ uVar13 ^ uVar5 ^ uVar30;
    uVar19 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar13 = (uVar16 ^ uVar24 ^ uVar20) + uVar12 + 0xca62c1d6 + uVar25 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar11 = uVar15 ^ uVar11 ^ uVar22 ^ uVar3;
    uVar23 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = (uVar24 ^ uVar19 ^ uVar14) + uVar28 + 0xca62c1d6 + uVar16 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar5 = uVar12 ^ uVar5 ^ uVar18 ^ in_a3;
    uVar20 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar16 = (uVar19 ^ uVar23 ^ uVar13) + uVar11 + 0xca62c1d6 + uVar24 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar13 = uVar28 ^ uVar22 ^ uVar10 ^ in_t0;
    uVar22 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = (uVar23 ^ uVar20 ^ uVar14) + uVar5 + 0xca62c1d6 + uVar19 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    unaff_s1 = 0xca62c1d6;
    in_t5 = uVar11 ^ uVar18 ^ uVar7 ^ uVar17;
    uVar17 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = (uVar20 ^ uVar22 ^ uVar16) + uVar13 + 0xca62c1d6 + uVar23 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar5 = uVar5 ^ uVar10 ^ uVar2 ^ in_t4;
    uVar10 = (uVar14 >> 2) + uVar14 * 0x40000000;
    unaff_s2 = uVar5 + 0xca62c1d6;
    uVar14 = (uVar22 ^ uVar17 ^ uVar14) + in_t5 + 0xca62c1d6 + uVar20 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar13 = uVar13 ^ uVar7 ^ uVar30 ^ uVar15;
    uVar18 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar15 = (uVar17 ^ uVar10 ^ uVar16) + unaff_s2 + uVar22 + (uVar14 >> 0x1b) + uVar14 * 0x20;
    in_t3 = uVar10 ^ uVar18 ^ uVar14;
    uVar14 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar7 = in_t3 + uVar13 + 0xca62c1d6 + uVar17 + (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar16 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar2 = (in_t5 ^ uVar2 ^ uVar3 ^ uVar12) + 0xca62c1d6 + uVar10 + (uVar18 ^ uVar14 ^ uVar15) +
            (uVar7 >> 0x1b) + uVar7 * 0x20;
    unaff_s4 = (uVar7 >> 2) + uVar7 * 0x40000000;
    unaff_s0 = (uVar13 ^ uVar3 ^ in_t0 ^ uVar11) + 0xca62c1d6;
    uVar11 = (uVar5 ^ uVar30 ^ in_a3 ^ uVar28) + 0xca62c1d6 + uVar18 + (uVar14 ^ uVar16 ^ uVar7) +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    unaff_s3 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uStack_38 = unaff_s3 + uStack_38;
    uStack_40 = unaff_s0 + uVar14 + (uVar16 ^ unaff_s4 ^ uVar2) + (uVar11 >> 0x1b) + uVar11 * 0x20 +
                uStack_40;
    uStack_3c = uVar11 + uStack_3c;
    uStack_34 = unaff_s4 + uStack_34;
    c->h1 = uStack_3c;
    c->h0 = uStack_40;
    uStack_30 = uVar16 + uStack_30;
    iStackX_8 = iStackX_8 + -1;
    c->h4 = uStack_30;
    c->h2 = uStack_38;
    c->h3 = uStack_34;
    puVar21 = puVar21 + 0x40;
  } while (iStackX_8 != 0);
  return;
}

