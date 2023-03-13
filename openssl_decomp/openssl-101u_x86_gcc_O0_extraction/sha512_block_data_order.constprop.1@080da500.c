
void __regparm3 sha512_block_data_order_constprop_1(uint *param_1,uint *param_2)

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
  uint local_3f4;
  uint local_3f0;
  uint *local_3ec;
  uint local_3e8;
  uint local_3e4;
  uint local_3e0;
  uint local_3dc;
  uint local_3d8;
  uint local_3d4;
  uint local_3d0;
  uint local_3c8;
  uint local_3c4;
  uint local_3c0;
  uint local_3bc;
  uint local_3b4;
  uint local_3b0;
  uint local_3ac;
  uint *local_3a4;
  uint local_394;
  uint local_390;
  uint local_364;
  uint local_360;
  uint *local_35c;
  uint *local_34c;
  uint *local_348;
  uint local_340;
  uint local_2f4;
  uint local_2ec [2];
  uint local_2e4;
  int local_2e0;
  uint local_2dc;
  int local_2d8;
  uint local_2d4;
  int local_2d0;
  uint local_2c4;
  int local_2c0;
  uint local_2bc;
  int local_2b8;
  uint local_2b4;
  int local_2b0;
  uint local_ec [2];
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_6c [5];
  uint local_58;
  uint local_54;
  uint local_50;
  uint auStack_4c [5];
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [7];
  
  uVar1 = param_1[1];
  uVar2 = param_1[6];
  local_2c[3] = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = *param_1;
  uVar4 = param_1[8];
  uVar5 = param_1[3];
  uVar6 = param_1[2];
  uVar7 = param_1[9];
  uVar8 = param_1[5];
  uVar9 = param_1[4];
  uVar10 = param_1[7];
  uVar11 = param_1[10];
  uVar12 = param_1[0xb];
  uVar13 = param_1[0xe];
  local_348 = (uint *)&K512;
  uVar14 = param_1[0xc];
  uVar15 = param_1[0xd];
  uVar16 = param_1[0xf];
  local_3a4 = local_6c;
  uVar18 = uVar15;
  uVar17 = uVar14;
  local_3f4 = uVar3;
  local_3f0 = uVar1;
  local_3ec = (uint *)uVar4;
  local_3e8 = uVar7;
  local_3e4 = uVar13;
  local_3e0 = uVar16;
  local_3dc = uVar2;
  local_3d8 = uVar10;
  local_3d4 = uVar6;
  local_3c8 = uVar5;
  local_3b4 = uVar11;
  local_3b0 = uVar12;
  local_34c = param_2;
  local_340 = uVar9;
  local_2f4 = uVar8;
  local_6c[2] = uVar6;
  auStack_4c[2] = uVar11;
  do {
    uVar27 = uVar17;
    uVar25 = uVar18;
    uVar18 = local_3b0;
    uVar17 = local_3b4;
    uVar19 = local_34c[1];
    uVar20 = *local_34c;
    uVar23 = uVar19 >> 0x18 | (uVar19 & 0xff0000) >> 8 | (uVar19 & 0xff00) << 8 | uVar19 << 0x18;
    uVar19 = uVar20 >> 0x18 | (uVar20 & 0xff0000) >> 8 | (uVar20 & 0xff00) << 8 | uVar20 << 0x18;
    *local_3a4 = local_3f4;
    local_3a4[1] = local_3f0;
    local_3a4[8] = (uint)local_3ec;
    local_3a4[9] = local_3e8;
    local_3a4[0x10] = uVar23;
    local_3a4[0x11] = uVar19;
    uVar26 = ((uint)local_3ec >> 0xe | local_3e8 << 0x12) ^
             ((uint)local_3ec >> 0x12 | local_3e8 << 0xe) ^
             ((int)local_3ec << 0x17 | local_3e8 >> 9);
    uVar20 = local_3e4 + *local_348 + uVar23;
    uVar21 = uVar20 + uVar26;
    uVar30 = uVar27 & ~(uint)local_3ec ^ (uint)local_3ec & local_3b4;
    uVar24 = uVar21 + uVar30;
    iVar22 = local_3e0 + local_348[1] + (uint)CARRY4(local_3e4,*local_348) + uVar19 +
             (uint)CARRY4(local_3e4 + *local_348,uVar23) +
             ((local_3e8 >> 0xe | (int)local_3ec << 0x12) ^
              (local_3e8 >> 0x12 | (int)local_3ec << 0xe) ^
             (local_3e8 << 0x17 | (uint)local_3ec >> 9)) + (uint)CARRY4(uVar20,uVar26) +
             (uVar25 & ~local_3e8 ^ local_3e8 & local_3b0) + (uint)CARRY4(uVar21,uVar30);
    uVar19 = local_3dc + uVar24;
    uVar20 = local_3d8 + iVar22 + (uint)CARRY4(local_3dc,uVar24);
    uVar30 = (local_3f4 >> 0x1c | local_3f0 << 4) ^ (local_3f4 << 0x1e | local_3f0 >> 2) ^
             (local_3f4 << 0x19 | local_3f0 >> 7);
    uVar26 = (local_3d4 ^ local_340) & local_3f4 ^ local_340 & local_3d4;
    uVar21 = uVar30 + uVar26;
    uVar23 = uVar21 + uVar24;
    uVar21 = ((local_3f0 >> 0x1c | local_3f4 << 4) ^ (local_3f0 << 0x1e | local_3f4 >> 2) ^
             (local_3f0 << 0x19 | local_3f4 >> 7)) +
             ((local_2f4 ^ local_3c8) & local_3f0 ^ local_2f4 & local_3c8) +
             (uint)CARRY4(uVar30,uVar26) + iVar22 + (uint)CARRY4(uVar21,uVar24);
    local_3a4 = local_3a4 + -2;
    local_34c = local_34c + 2;
    local_3dc = local_340;
    local_348 = local_348 + 2;
    local_3d8 = local_2f4;
    local_340 = local_3d4;
    local_2f4 = local_3c8;
    local_3d4 = local_3f4;
    local_3c8 = local_3f0;
    local_3b4 = (uint)local_3ec;
    local_3b0 = local_3e8;
    local_3f4 = uVar23;
    local_3f0 = uVar21;
    local_3ec = (uint *)uVar19;
    local_3e8 = uVar20;
    local_3e4 = uVar27;
    local_3e0 = uVar25;
  } while (local_3a4 != local_ec);
  local_3dc = local_d4;
  local_3d8 = local_d0;
  local_3c0 = local_dc;
  local_3e0 = local_b0;
  local_3bc = local_d8;
  local_3d0 = local_98;
  local_3c8 = local_e4;
  local_3c4 = local_e0;
  local_3e4 = local_b4;
  local_3b4 = local_bc;
  local_3b0 = local_b8;
  local_34c = (uint *)local_c4;
  local_3ac = local_c0;
  local_3d4 = local_9c;
  local_364 = local_a4;
  local_360 = local_a0;
  local_35c = (uint *)&DAT_08214580;
  local_394 = local_2c[0];
  local_390 = local_2c[1];
  local_3ec = local_3a4;
  local_6c[3] = uVar5;
  local_6c[4] = uVar9;
  local_58 = uVar8;
  local_54 = uVar2;
  local_50 = uVar10;
  auStack_4c[3] = uVar12;
  auStack_4c[4] = uVar14;
  local_38 = uVar15;
  local_34 = uVar13;
  local_30 = uVar16;
  do {
    uVar26 = uVar20;
    uVar21 = uVar19;
    uVar17 = local_3ec[0x2e];
    uVar18 = local_3ec[0x2f];
    uVar23 = (uVar17 >> 1 | uVar18 << 0x1f) ^ (uVar17 >> 8 | uVar18 << 0x18) ^
             (uVar17 >> 7 | uVar18 << 0x19);
    uVar24 = (local_3d4 >> 0x13 | local_3d0 << 0xd) ^ (local_3d4 << 3 | local_3d0 >> 0x1d) ^
             (local_3d4 >> 6 | local_3d0 << 0x1a);
    uVar20 = local_394 + uVar24;
    uVar19 = uVar20 + local_3ec[0x1e];
    uVar25 = uVar19 + uVar23;
    uVar28 = local_390 +
             ((local_3d0 >> 0x13 | local_3d4 << 0xd) ^ (local_3d0 << 3 | local_3d4 >> 0x1d) ^
             local_3d0 >> 6) + (uint)CARRY4(local_394,uVar24) + local_3ec[0x1f] +
             (uint)CARRY4(uVar20,local_3ec[0x1e]) +
             ((uVar18 >> 1 | uVar17 << 0x1f) ^ (uVar18 >> 8 | uVar17 << 0x18) ^ uVar18 >> 7) +
             (uint)CARRY4(uVar19,uVar23);
    local_3ec[8] = uVar21;
    local_3ec[9] = uVar26;
    *local_3ec = local_3f4;
    local_3ec[1] = local_3f0;
    local_3ec[0x10] = uVar25;
    local_3ec[0x11] = uVar28;
    uVar20 = (uVar21 >> 0xe | uVar26 << 0x12) ^ (uVar21 >> 0x12 | uVar26 << 0xe) ^
             (uVar21 << 0x17 | uVar26 >> 9);
    uVar23 = local_3e4 + *local_35c + uVar20;
    uVar19 = ~uVar21 & local_3b4 ^ (uint)local_34c & uVar21;
    uVar24 = uVar23 + uVar19;
    uVar29 = uVar24 + uVar25;
    iVar22 = local_3e0 + local_35c[1] + (uint)CARRY4(local_3e4,*local_35c) +
             ((uVar26 >> 0xe | uVar21 << 0x12) ^ (uVar26 >> 0x12 | uVar21 << 0xe) ^
             (uVar26 << 0x17 | uVar21 >> 9)) + (uint)CARRY4(local_3e4 + *local_35c,uVar20) +
             (~uVar26 & local_3b0 ^ local_3ac & uVar26) + (uint)CARRY4(uVar23,uVar19) + uVar28 +
             (uint)CARRY4(uVar24,uVar25);
    uVar19 = local_3dc + uVar29;
    uVar20 = local_3d8 + iVar22 + (uint)CARRY4(local_3dc,uVar29);
    uVar27 = (local_3f4 >> 0x1c | local_3f0 << 4) ^ (local_3f4 << 0x1e | local_3f0 >> 2) ^
             (local_3f4 << 0x19 | local_3f0 >> 7);
    uVar30 = (local_3c0 ^ local_3c8) & local_3f4 ^ local_3c0 & local_3c8;
    uVar23 = uVar27 + uVar30;
    local_3dc = local_3c0;
    uVar24 = uVar23 + uVar29;
    uVar23 = ((local_3f0 << 0x1e | local_3f4 >> 2) ^ (local_3f0 >> 0x1c | local_3f4 << 4) ^
             (local_3f0 << 0x19 | local_3f4 >> 7)) +
             ((local_3bc ^ local_3c4) & local_3f0 ^ local_3bc & local_3c4) +
             (uint)CARRY4(uVar27,uVar30) + iVar22 + (uint)CARRY4(uVar23,uVar29);
    local_3d8 = local_3bc;
    local_3ec = local_3ec + -2;
    local_35c = local_35c + 2;
    local_3c0 = local_3c8;
    local_3bc = local_3c4;
    local_3c8 = local_3f4;
    local_3c4 = local_3f0;
    local_3e4 = local_3b4;
    local_3e0 = local_3b0;
    local_3d0 = local_360;
    local_3b4 = (uint)local_34c;
    local_3d4 = local_364;
    local_3f4 = uVar24;
    local_3f0 = uVar23;
    local_3b0 = local_3ac;
    local_3ac = uVar26;
    local_394 = uVar17;
    local_390 = uVar18;
    local_364 = uVar25;
    local_360 = uVar28;
    local_34c = (uint *)uVar21;
  } while (local_3ec != local_2ec);
  param_1[2] = uVar6 + local_2e4;
  *param_1 = uVar24 + uVar3;
  param_1[3] = uVar5 + local_2e0 + (uint)CARRY4(uVar6,local_2e4);
  param_1[1] = uVar23 + uVar1 + (uint)CARRY4(uVar24,uVar3);
  param_1[4] = uVar9 + local_2dc;
  param_1[5] = uVar8 + local_2d8 + (uint)CARRY4(uVar9,local_2dc);
  param_1[6] = uVar2 + local_2d4;
  param_1[7] = uVar10 + local_2d0 + (uint)CARRY4(uVar2,local_2d4);
  param_1[8] = uVar4 + uVar19;
  param_1[9] = uVar7 + uVar20 + (uint)CARRY4(uVar4,uVar19);
  param_1[10] = uVar11 + local_2c4;
  param_1[0xb] = uVar12 + local_2c0 + (uint)CARRY4(uVar11,local_2c4);
  param_1[0xc] = uVar14 + local_2bc;
  param_1[0xd] = uVar15 + local_2b8 + (uint)CARRY4(uVar14,local_2bc);
  param_1[0xe] = uVar13 + local_2b4;
  iVar22 = *(int *)(in_GS_OFFSET + 0x14);
  param_1[0xf] = uVar16 + local_2b0 + (uint)CARRY4(uVar13,local_2b4);
  if (local_2c[3] != iVar22) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

