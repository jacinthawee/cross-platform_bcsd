
void SHA512_Transform(SHA512_CTX *c,uchar *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
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
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  int in_GS_OFFSET;
  uint uStack_3f4;
  uint uStack_3f0;
  uint *puStack_3ec;
  uint uStack_3e8;
  uint uStack_3e4;
  uint uStack_3e0;
  uint uStack_3dc;
  uint uStack_3d8;
  uint uStack_3d4;
  uint uStack_3d0;
  uint uStack_3c8;
  uint uStack_3c4;
  uint uStack_3c0;
  uint uStack_3bc;
  uint uStack_3b4;
  uint uStack_3b0;
  uint uStack_3ac;
  uint *puStack_3a4;
  uint uStack_394;
  uint uStack_390;
  uint uStack_364;
  uint uStack_360;
  uint *puStack_35c;
  uint *puStack_34c;
  uint *puStack_348;
  uint uStack_340;
  uint uStack_2f4;
  uint auStack_2ec [2];
  uint uStack_2e4;
  int iStack_2e0;
  uint uStack_2dc;
  int iStack_2d8;
  uint uStack_2d4;
  int iStack_2d0;
  uint uStack_2c4;
  int iStack_2c0;
  uint uStack_2bc;
  int iStack_2b8;
  uint uStack_2b4;
  int iStack_2b0;
  uint auStack_ec [2];
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint auStack_6c [5];
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint auStack_4c [5];
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint auStack_2c [7];
  
  uVar1 = *(uint *)((int)c->h + 4);
  uVar2 = *(uint *)(c->h + 3);
  auStack_2c[3] = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = *(uint *)c->h;
  uVar4 = *(uint *)(c->h + 4);
  uVar5 = *(uint *)((int)c->h + 0xc);
  uVar6 = *(uint *)(c->h + 1);
  uVar7 = *(uint *)((int)c->h + 0x24);
  uVar8 = *(uint *)((int)c->h + 0x14);
  uVar9 = *(uint *)(c->h + 2);
  uVar10 = *(uint *)((int)c->h + 0x1c);
  uVar11 = *(uint *)(c->h + 5);
  uVar12 = *(uint *)((int)c->h + 0x2c);
  uVar13 = *(uint *)(c->h + 7);
  puStack_348 = (uint *)&K512;
  uVar14 = *(uint *)(c->h + 6);
  uVar15 = *(uint *)((int)c->h + 0x34);
  uVar16 = *(uint *)((int)c->h + 0x3c);
  puStack_3a4 = auStack_6c;
  puStack_34c = (uint *)data;
  uVar18 = uVar15;
  uVar17 = uVar14;
  uStack_3f4 = uVar3;
  uStack_3f0 = uVar1;
  puStack_3ec = (uint *)uVar4;
  uStack_3e8 = uVar7;
  uStack_3e4 = uVar13;
  uStack_3e0 = uVar16;
  uStack_3dc = uVar2;
  uStack_3d8 = uVar10;
  uStack_3d4 = uVar6;
  uStack_3c8 = uVar5;
  uStack_3b4 = uVar11;
  uStack_3b0 = uVar12;
  uStack_340 = uVar9;
  uStack_2f4 = uVar8;
  auStack_6c[2] = uVar6;
  auStack_4c[2] = uVar11;
  do {
    uVar27 = uVar17;
    uVar25 = uVar18;
    uVar18 = uStack_3b0;
    uVar17 = uStack_3b4;
    uVar19 = puStack_34c[1];
    uVar20 = *puStack_34c;
    uVar23 = uVar19 >> 0x18 | (uVar19 & 0xff0000) >> 8 | (uVar19 & 0xff00) << 8 | uVar19 << 0x18;
    uVar19 = uVar20 >> 0x18 | (uVar20 & 0xff0000) >> 8 | (uVar20 & 0xff00) << 8 | uVar20 << 0x18;
    *puStack_3a4 = uStack_3f4;
    puStack_3a4[1] = uStack_3f0;
    puStack_3a4[8] = (uint)puStack_3ec;
    puStack_3a4[9] = uStack_3e8;
    puStack_3a4[0x10] = uVar23;
    puStack_3a4[0x11] = uVar19;
    uVar26 = ((uint)puStack_3ec >> 0xe | uStack_3e8 << 0x12) ^
             ((uint)puStack_3ec >> 0x12 | uStack_3e8 << 0xe) ^
             ((int)puStack_3ec << 0x17 | uStack_3e8 >> 9);
    uVar20 = uStack_3e4 + *puStack_348 + uVar23;
    uVar21 = uVar20 + uVar26;
    uVar30 = uVar27 & ~(uint)puStack_3ec ^ (uint)puStack_3ec & uStack_3b4;
    uVar24 = uVar21 + uVar30;
    iVar22 = uStack_3e0 + puStack_348[1] + (uint)CARRY4(uStack_3e4,*puStack_348) + uVar19 +
             (uint)CARRY4(uStack_3e4 + *puStack_348,uVar23) +
             ((uStack_3e8 >> 0xe | (int)puStack_3ec << 0x12) ^
              (uStack_3e8 >> 0x12 | (int)puStack_3ec << 0xe) ^
             (uStack_3e8 << 0x17 | (uint)puStack_3ec >> 9)) + (uint)CARRY4(uVar20,uVar26) +
             (uVar25 & ~uStack_3e8 ^ uStack_3e8 & uStack_3b0) + (uint)CARRY4(uVar21,uVar30);
    uVar19 = uStack_3dc + uVar24;
    uVar20 = uStack_3d8 + iVar22 + (uint)CARRY4(uStack_3dc,uVar24);
    uVar30 = (uStack_3f4 >> 0x1c | uStack_3f0 << 4) ^ (uStack_3f4 << 0x1e | uStack_3f0 >> 2) ^
             (uStack_3f4 << 0x19 | uStack_3f0 >> 7);
    uVar26 = (uStack_3d4 ^ uStack_340) & uStack_3f4 ^ uStack_340 & uStack_3d4;
    uVar21 = uVar30 + uVar26;
    uVar23 = uVar21 + uVar24;
    uVar21 = ((uStack_3f0 >> 0x1c | uStack_3f4 << 4) ^ (uStack_3f0 << 0x1e | uStack_3f4 >> 2) ^
             (uStack_3f0 << 0x19 | uStack_3f4 >> 7)) +
             ((uStack_2f4 ^ uStack_3c8) & uStack_3f0 ^ uStack_2f4 & uStack_3c8) +
             (uint)CARRY4(uVar30,uVar26) + iVar22 + (uint)CARRY4(uVar21,uVar24);
    puStack_3a4 = puStack_3a4 + -2;
    puStack_34c = puStack_34c + 2;
    uStack_3dc = uStack_340;
    puStack_348 = puStack_348 + 2;
    uStack_3d8 = uStack_2f4;
    uStack_340 = uStack_3d4;
    uStack_2f4 = uStack_3c8;
    uStack_3d4 = uStack_3f4;
    uStack_3c8 = uStack_3f0;
    uStack_3b4 = (uint)puStack_3ec;
    uStack_3b0 = uStack_3e8;
    uStack_3f4 = uVar23;
    uStack_3f0 = uVar21;
    puStack_3ec = (uint *)uVar19;
    uStack_3e8 = uVar20;
    uStack_3e4 = uVar27;
    uStack_3e0 = uVar25;
  } while (puStack_3a4 != auStack_ec);
  uStack_3dc = uStack_d4;
  uStack_3d8 = uStack_d0;
  uStack_3c0 = uStack_dc;
  uStack_3e0 = uStack_b0;
  uStack_3bc = uStack_d8;
  uStack_3d0 = uStack_98;
  uStack_3c8 = uStack_e4;
  uStack_3c4 = uStack_e0;
  uStack_3e4 = uStack_b4;
  uStack_3b4 = uStack_bc;
  uStack_3b0 = uStack_b8;
  puStack_34c = (uint *)uStack_c4;
  uStack_3ac = uStack_c0;
  uStack_3d4 = uStack_9c;
  uStack_364 = uStack_a4;
  uStack_360 = uStack_a0;
  puStack_35c = (uint *)&DAT_08214580;
  uStack_394 = auStack_2c[0];
  uStack_390 = auStack_2c[1];
  puStack_3ec = puStack_3a4;
  auStack_6c[3] = uVar5;
  auStack_6c[4] = uVar9;
  uStack_58 = uVar8;
  uStack_54 = uVar2;
  uStack_50 = uVar10;
  auStack_4c[3] = uVar12;
  auStack_4c[4] = uVar14;
  uStack_38 = uVar15;
  uStack_34 = uVar13;
  uStack_30 = uVar16;
  do {
    uVar26 = uVar20;
    uVar21 = uVar19;
    uVar17 = puStack_3ec[0x2e];
    uVar18 = puStack_3ec[0x2f];
    uVar23 = (uVar17 >> 1 | uVar18 << 0x1f) ^ (uVar17 >> 8 | uVar18 << 0x18) ^
             (uVar17 >> 7 | uVar18 << 0x19);
    uVar24 = (uStack_3d4 >> 0x13 | uStack_3d0 << 0xd) ^ (uStack_3d4 << 3 | uStack_3d0 >> 0x1d) ^
             (uStack_3d4 >> 6 | uStack_3d0 << 0x1a);
    uVar20 = uStack_394 + uVar24;
    uVar19 = uVar20 + puStack_3ec[0x1e];
    uVar25 = uVar19 + uVar23;
    uVar28 = uStack_390 +
             ((uStack_3d0 >> 0x13 | uStack_3d4 << 0xd) ^ (uStack_3d0 << 3 | uStack_3d4 >> 0x1d) ^
             uStack_3d0 >> 6) + (uint)CARRY4(uStack_394,uVar24) + puStack_3ec[0x1f] +
             (uint)CARRY4(uVar20,puStack_3ec[0x1e]) +
             ((uVar18 >> 1 | uVar17 << 0x1f) ^ (uVar18 >> 8 | uVar17 << 0x18) ^ uVar18 >> 7) +
             (uint)CARRY4(uVar19,uVar23);
    puStack_3ec[8] = uVar21;
    puStack_3ec[9] = uVar26;
    *puStack_3ec = uStack_3f4;
    puStack_3ec[1] = uStack_3f0;
    puStack_3ec[0x10] = uVar25;
    puStack_3ec[0x11] = uVar28;
    uVar20 = (uVar21 >> 0xe | uVar26 << 0x12) ^ (uVar21 >> 0x12 | uVar26 << 0xe) ^
             (uVar21 << 0x17 | uVar26 >> 9);
    uVar23 = uStack_3e4 + *puStack_35c + uVar20;
    uVar19 = ~uVar21 & uStack_3b4 ^ (uint)puStack_34c & uVar21;
    uVar24 = uVar23 + uVar19;
    uVar29 = uVar24 + uVar25;
    iVar22 = uStack_3e0 + puStack_35c[1] + (uint)CARRY4(uStack_3e4,*puStack_35c) +
             ((uVar26 >> 0xe | uVar21 << 0x12) ^ (uVar26 >> 0x12 | uVar21 << 0xe) ^
             (uVar26 << 0x17 | uVar21 >> 9)) + (uint)CARRY4(uStack_3e4 + *puStack_35c,uVar20) +
             (~uVar26 & uStack_3b0 ^ uStack_3ac & uVar26) + (uint)CARRY4(uVar23,uVar19) + uVar28 +
             (uint)CARRY4(uVar24,uVar25);
    uVar19 = uStack_3dc + uVar29;
    uVar20 = uStack_3d8 + iVar22 + (uint)CARRY4(uStack_3dc,uVar29);
    uVar27 = (uStack_3f4 >> 0x1c | uStack_3f0 << 4) ^ (uStack_3f4 << 0x1e | uStack_3f0 >> 2) ^
             (uStack_3f4 << 0x19 | uStack_3f0 >> 7);
    uVar30 = (uStack_3c0 ^ uStack_3c8) & uStack_3f4 ^ uStack_3c0 & uStack_3c8;
    uVar23 = uVar27 + uVar30;
    uStack_3dc = uStack_3c0;
    uVar24 = uVar23 + uVar29;
    uVar23 = ((uStack_3f0 << 0x1e | uStack_3f4 >> 2) ^ (uStack_3f0 >> 0x1c | uStack_3f4 << 4) ^
             (uStack_3f0 << 0x19 | uStack_3f4 >> 7)) +
             ((uStack_3bc ^ uStack_3c4) & uStack_3f0 ^ uStack_3bc & uStack_3c4) +
             (uint)CARRY4(uVar27,uVar30) + iVar22 + (uint)CARRY4(uVar23,uVar29);
    uStack_3d8 = uStack_3bc;
    puStack_3ec = puStack_3ec + -2;
    puStack_35c = puStack_35c + 2;
    uStack_3c0 = uStack_3c8;
    uStack_3bc = uStack_3c4;
    uStack_3c8 = uStack_3f4;
    uStack_3c4 = uStack_3f0;
    uStack_3e4 = uStack_3b4;
    uStack_3e0 = uStack_3b0;
    uStack_3d0 = uStack_360;
    uStack_3b4 = (uint)puStack_34c;
    uStack_3d4 = uStack_364;
    uStack_3f4 = uVar24;
    uStack_3f0 = uVar23;
    uStack_3b0 = uStack_3ac;
    uStack_3ac = uVar26;
    uStack_394 = uVar17;
    uStack_390 = uVar18;
    uStack_364 = uVar25;
    uStack_360 = uVar28;
    puStack_34c = (uint *)uVar21;
  } while (puStack_3ec != auStack_2ec);
  *(uint *)(c->h + 1) = uVar6 + uStack_2e4;
  *(uint *)c->h = uVar24 + uVar3;
  *(uint *)((int)c->h + 0xc) = uVar5 + iStack_2e0 + (uint)CARRY4(uVar6,uStack_2e4);
  *(uint *)((int)c->h + 4) = uVar23 + uVar1 + (uint)CARRY4(uVar24,uVar3);
  *(uint *)(c->h + 2) = uVar9 + uStack_2dc;
  *(uint *)((int)c->h + 0x14) = uVar8 + iStack_2d8 + (uint)CARRY4(uVar9,uStack_2dc);
  *(uint *)(c->h + 3) = uVar2 + uStack_2d4;
  *(uint *)((int)c->h + 0x1c) = uVar10 + iStack_2d0 + (uint)CARRY4(uVar2,uStack_2d4);
  *(uint *)(c->h + 4) = uVar4 + uVar19;
  *(uint *)((int)c->h + 0x24) = uVar7 + uVar20 + (uint)CARRY4(uVar4,uVar19);
  *(uint *)(c->h + 5) = uVar11 + uStack_2c4;
  *(uint *)((int)c->h + 0x2c) = uVar12 + iStack_2c0 + (uint)CARRY4(uVar11,uStack_2c4);
  *(uint *)(c->h + 6) = uVar14 + uStack_2bc;
  *(uint *)((int)c->h + 0x34) = uVar15 + iStack_2b8 + (uint)CARRY4(uVar14,uStack_2bc);
  *(uint *)(c->h + 7) = uVar13 + uStack_2b4;
  iVar22 = *(int *)(in_GS_OFFSET + 0x14);
  *(uint *)((int)c->h + 0x3c) = uVar16 + iStack_2b0 + (uint)CARRY4(uVar13,uStack_2b4);
  if (auStack_2c[3] != iVar22) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

