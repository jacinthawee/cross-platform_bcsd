
void __regparm3 sha512_block_data_order(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
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
  int in_GS_OFFSET;
  bool bVar19;
  uint local_404;
  uint local_400;
  uint local_3fc;
  uint local_3f8;
  uint local_3f4;
  uint local_3f0;
  uint local_3ec;
  uint local_3e8;
  uint local_3e4;
  uint local_3e0;
  uint local_3d8;
  uint local_3d4;
  uint local_3d0;
  uint local_3cc;
  uint local_3c8;
  uint *local_3c4;
  uint *local_3c0;
  uint local_3bc;
  uint local_3ac;
  uint local_3a8;
  uint local_37c;
  uint local_378;
  uint *local_374;
  uint local_33c;
  uint local_338;
  uint local_334;
  uint local_330;
  uint local_32c;
  uint local_328;
  uint local_324;
  uint local_320;
  uint local_31c;
  uint local_318;
  uint local_314;
  int local_310;
  uint local_30c;
  uint local_308;
  uint local_304;
  uint local_300;
  uint local_2fc;
  uint local_2f8;
  uint *local_2f4;
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
  uint local_ec [5];
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint auStack_cc [5];
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint auStack_ac [5];
  uint local_98;
  uint auStack_74 [5];
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_310 = param_3 + -1;
  if (param_3 != 0) {
    local_330 = param_1[3];
    local_334 = param_1[2];
    local_328 = param_1[5];
    local_32c = param_1[4];
    local_320 = param_1[7];
    local_324 = param_1[6];
    local_300 = param_1[0xb];
    local_304 = param_1[10];
    local_338 = param_1[0xd];
    local_33c = param_1[0xc];
    local_318 = param_1[0xf];
    local_31c = param_1[0xe];
    local_2f8 = param_1[9];
    local_2fc = param_1[8];
    local_308 = param_1[1];
    local_30c = *param_1;
    local_2f4 = param_2;
    do {
      local_60 = local_330;
      local_50 = local_320;
      auStack_74[4] = local_334;
      local_58 = local_328;
      local_44 = local_304;
      local_40 = local_300;
      local_3cc = local_304;
      local_54 = local_324;
      local_3c8 = local_300;
      local_34 = local_31c;
      local_5c = local_32c;
      local_38 = local_338;
      local_3c = local_33c;
      local_30 = local_318;
      local_3c0 = (uint *)&K512;
      local_3f4 = local_31c;
      local_3f0 = local_318;
      local_3c4 = local_2f4;
      local_3bc = local_328;
      local_3ec = local_324;
      local_3e4 = local_334;
      local_3d8 = local_330;
      local_3fc = local_2fc;
      local_3f8 = local_2f8;
      local_3e8 = local_320;
      local_404 = local_30c;
      puVar4 = auStack_74 + 2;
      local_314 = local_32c;
      local_400 = local_308;
      uVar1 = local_338;
      uVar2 = local_33c;
      do {
        uVar7 = uVar2;
        uVar6 = uVar1;
        uVar1 = local_3c4[1];
        uVar2 = *local_3c4;
        uVar8 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        uVar1 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
        *puVar4 = local_404;
        puVar4[1] = local_400;
        puVar4[8] = local_3fc;
        puVar4[9] = local_3f8;
        puVar4[0x10] = uVar8;
        puVar4[0x11] = uVar1;
        uVar13 = (local_3fc >> 0xe | local_3f8 << 0x12) ^ (local_3fc >> 0x12 | local_3f8 << 0xe) ^
                 (local_3fc << 0x17 | local_3f8 >> 9);
        uVar2 = local_3f4 + *local_3c0 + uVar8;
        uVar3 = uVar2 + uVar13;
        uVar17 = uVar7 & ~local_3fc ^ local_3fc & local_3cc;
        uVar9 = uVar3 + uVar17;
        iVar5 = local_3f0 + local_3c0[1] + (uint)CARRY4(local_3f4,*local_3c0) + uVar1 +
                (uint)CARRY4(local_3f4 + *local_3c0,uVar8) +
                ((local_3f8 >> 0xe | local_3fc << 0x12) ^ (local_3f8 >> 0x12 | local_3fc << 0xe) ^
                (local_3f8 << 0x17 | local_3fc >> 9)) + (uint)CARRY4(uVar2,uVar13) +
                (uVar6 & ~local_3f8 ^ local_3f8 & local_3c8) + (uint)CARRY4(uVar3,uVar17);
        uVar17 = local_3ec + uVar9;
        uVar18 = local_3e8 + iVar5 + (uint)CARRY4(local_3ec,uVar9);
        uVar3 = (local_404 >> 0x1c | local_400 << 4) ^ (local_404 << 0x1e | local_400 >> 2) ^
                (local_404 << 0x19 | local_400 >> 7);
        uVar2 = (local_3e4 ^ local_314) & local_404 ^ local_314 & local_3e4;
        uVar1 = uVar3 + uVar2;
        uVar13 = uVar1 + uVar9;
        local_3ec = local_314;
        uVar9 = ((local_400 >> 0x1c | local_404 << 4) ^ (local_400 << 0x1e | local_404 >> 2) ^
                (local_400 << 0x19 | local_404 >> 7)) +
                ((local_3d8 ^ local_3bc) & local_400 ^ local_3d8 & local_3bc) +
                (uint)CARRY4(uVar3,uVar2) + iVar5 + (uint)CARRY4(uVar1,uVar9);
        puVar4 = puVar4 + -2;
        local_3c4 = local_3c4 + 2;
        local_3e8 = local_3bc;
        local_3c0 = local_3c0 + 2;
        local_314 = local_3e4;
        local_3bc = local_3d8;
        local_3e4 = local_404;
        local_3d8 = local_400;
        uVar3 = local_3fc;
        uVar8 = local_3f8;
        uVar1 = local_3c8;
        uVar2 = local_3cc;
        local_404 = uVar13;
        local_400 = uVar9;
        local_3fc = uVar17;
        local_3f8 = uVar18;
        local_3f4 = uVar7;
        local_3f0 = uVar6;
        local_3cc = uVar3;
        local_3c8 = uVar8;
      } while (puVar4 != local_ec);
      local_3f4 = local_d4;
      local_3f0 = local_d0;
      local_3d8 = local_ec[4];
      local_3e8 = local_b0;
      local_3cc = local_d8;
      local_3e0 = local_98;
      local_3d4 = local_ec[2];
      local_3d0 = local_ec[3];
      local_3ec = local_b4;
      local_3c0 = (uint *)auStack_cc[4];
      local_314 = local_b8;
      local_3c8 = auStack_cc[2];
      local_3c4 = (uint *)auStack_cc[3];
      local_3e4 = auStack_ac[4];
      local_37c = auStack_ac[2];
      local_378 = auStack_ac[3];
      local_374 = (uint *)&DAT_082141e0;
      local_3ac = local_2c;
      puVar4 = local_ec;
      local_3a8 = local_28;
      do {
        uVar1 = puVar4[0x2e];
        uVar2 = puVar4[0x2f];
        uVar3 = (uVar1 >> 1 | uVar2 << 0x1f) ^ (uVar1 >> 8 | uVar2 << 0x18) ^
                (uVar1 >> 7 | uVar2 << 0x19);
        uVar8 = (local_3e4 >> 0x13 | local_3e0 << 0xd) ^ (local_3e4 << 3 | local_3e0 >> 0x1d) ^
                (local_3e4 >> 6 | local_3e0 << 0x1a);
        uVar9 = local_3ac + uVar8;
        uVar13 = uVar9 + puVar4[0x1e];
        uVar11 = uVar13 + uVar3;
        uVar15 = local_3a8 +
                 ((local_3e0 >> 0x13 | local_3e4 << 0xd) ^ (local_3e0 << 3 | local_3e4 >> 0x1d) ^
                 local_3e0 >> 6) + (uint)CARRY4(local_3ac,uVar8) + puVar4[0x1f] +
                 (uint)CARRY4(uVar9,puVar4[0x1e]) +
                 ((uVar2 >> 1 | uVar1 << 0x1f) ^ (uVar2 >> 8 | uVar1 << 0x18) ^ uVar2 >> 7) +
                 (uint)CARRY4(uVar13,uVar3);
        *puVar4 = local_404;
        puVar4[1] = local_400;
        puVar4[8] = local_3fc;
        puVar4[9] = local_3f8;
        puVar4[0x10] = uVar11;
        puVar4[0x11] = uVar15;
        uVar3 = (local_3fc >> 0xe | local_3f8 << 0x12) ^ (local_3fc >> 0x12 | local_3f8 << 0xe) ^
                (local_3fc << 0x17 | local_3f8 >> 9);
        uVar13 = local_3ec + *local_374 + uVar3;
        uVar8 = ~local_3fc & (uint)local_3c0 ^ local_3c8 & local_3fc;
        uVar9 = uVar13 + uVar8;
        uVar16 = uVar9 + uVar11;
        iVar5 = local_3e8 + local_374[1] + (uint)CARRY4(local_3ec,*local_374) +
                ((local_3f8 >> 0xe | local_3fc << 0x12) ^ (local_3f8 >> 0x12 | local_3fc << 0xe) ^
                (local_3f8 << 0x17 | local_3fc >> 9)) + (uint)CARRY4(local_3ec + *local_374,uVar3) +
                (~local_3f8 & local_314 ^ (uint)local_3c4 & local_3f8) + (uint)CARRY4(uVar13,uVar8)
                + uVar15 + (uint)CARRY4(uVar9,uVar11);
        uVar18 = local_3f4 + uVar16;
        uVar6 = local_3f0 + iVar5 + (uint)CARRY4(local_3f4,uVar16);
        uVar14 = (local_404 >> 0x1c | local_400 << 4) ^ (local_404 << 0x1e | local_400 >> 2) ^
                 (local_404 << 0x19 | local_400 >> 7);
        uVar9 = local_3d0 ^ local_3cc;
        local_3f0 = local_3cc;
        uVar12 = (local_3d8 ^ local_3d4) & local_404 ^ local_3d4 & local_3d8;
        uVar10 = local_3d0 & local_3cc;
        uVar17 = uVar14 + uVar12;
        local_3cc = local_3d0;
        uVar3 = local_3d4;
        uVar8 = local_3fc;
        uVar13 = (uint)local_3c4;
        uVar7 = uVar17 + uVar16;
        local_3d4 = local_404;
        uVar17 = ((local_400 << 0x19 | local_404 >> 7) ^
                 (local_400 >> 0x1c | local_404 << 4) ^ (local_400 << 0x1e | local_404 >> 2)) +
                 (uVar9 & local_400 ^ uVar10) + (uint)CARRY4(uVar14,uVar12) + iVar5 +
                 (uint)CARRY4(uVar17,uVar16);
        local_3f4 = local_3d8;
        uVar9 = local_3c8;
        puVar4 = puVar4 + -2;
        local_374 = local_374 + 2;
        local_3d0 = local_400;
        local_3ec = (uint)local_3c0;
        local_3e8 = local_314;
        local_3c4 = (uint *)local_3f8;
        local_3e4 = local_37c;
        local_3e0 = local_378;
        local_404 = uVar7;
        local_400 = uVar17;
        local_3fc = uVar18;
        local_3f8 = uVar6;
        local_3d8 = uVar3;
        local_3c8 = uVar8;
        local_3c0 = (uint *)uVar9;
        local_3ac = uVar1;
        local_3a8 = uVar2;
        local_37c = uVar11;
        local_378 = uVar15;
        local_314 = uVar13;
      } while (puVar4 != local_2ec);
      bVar19 = CARRY4(local_30c,uVar7);
      local_30c = local_30c + uVar7;
      local_308 = local_308 + uVar17 + (uint)bVar19;
      bVar19 = CARRY4(local_334,local_2e4);
      local_334 = local_334 + local_2e4;
      local_330 = local_330 + local_2e0 + (uint)bVar19;
      param_1[2] = local_334;
      bVar19 = CARRY4(local_32c,local_2dc);
      local_32c = local_32c + local_2dc;
      param_1[3] = local_330;
      local_328 = local_328 + local_2d8 + (uint)bVar19;
      *param_1 = local_30c;
      param_1[1] = local_308;
      param_1[4] = local_32c;
      bVar19 = CARRY4(local_324,local_2d4);
      local_324 = local_324 + local_2d4;
      param_1[5] = local_328;
      local_320 = local_320 + local_2d0 + (uint)bVar19;
      param_1[6] = local_324;
      bVar19 = CARRY4(uVar18,local_2fc);
      local_2fc = uVar18 + local_2fc;
      param_1[7] = local_320;
      local_2f8 = uVar6 + local_2f8 + (uint)bVar19;
      bVar19 = CARRY4(local_304,local_2c4);
      local_304 = local_304 + local_2c4;
      local_300 = local_300 + local_2c0 + (uint)bVar19;
      param_1[8] = local_2fc;
      param_1[9] = local_2f8;
      param_1[10] = local_304;
      bVar19 = CARRY4(local_33c,local_2bc);
      local_33c = local_33c + local_2bc;
      param_1[0xb] = local_300;
      local_338 = local_338 + local_2b8 + (uint)bVar19;
      param_1[0xc] = local_33c;
      bVar19 = CARRY4(local_31c,local_2b4);
      local_31c = local_31c + local_2b4;
      param_1[0xd] = local_338;
      local_318 = local_318 + local_2b0 + (uint)bVar19;
      local_310 = local_310 + -1;
      param_1[0xf] = local_318;
      local_2f4 = local_2f4 + 0x20;
      param_1[0xe] = local_31c;
    } while (local_310 != -1);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

